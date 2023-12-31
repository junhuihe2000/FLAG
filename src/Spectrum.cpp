// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
/*
// [[Rcpp::depends(RSpectra)]]
#include <Spectra/SymEigsSolver.h>
#include <Spectra/MatOp/SparseSymMatProd.h>
*/

#include "Utils.h"
#include "lae.h"
#include "Spectrum.h"

/*
using namespace Rcpp;
using namespace Eigen;
*/

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/




EigenPair heat_kernel_spectrum_cpp(const Eigen::MatrixXd & X, const Eigen::MatrixXd & X_new,
                                   int s, int r, int K, const Rcpp::List & models, int nstart) {
  int m = X.rows(); int m_new = X_new.rows();
  Eigen::MatrixXd X_all(m+m_new, X.cols());
  X_all.topRows(m) = X;
  X_all.bottomRows(m_new) = X_new;

  Eigen::MatrixXd U = subsample_cpp(X_all, s, Rcpp::as<std::string>(models["subsample"]), nstart);
  Eigen::SparseMatrix<double, Eigen::RowMajor> Z = cross_similarity_lae_cpp(X_all, U, r, Rcpp::as<std::string>(models["gl"]));

  if(K<0) {
    K = s;
  }

  EigenPair eigenpair = spectrum_from_Z_cpp(Z, K, models["root"]);

  return eigenpair;
}






Eigen::MatrixXd HK_from_spectrum_cpp(const EigenPair & eigenpair, int K, double t,
                                     const Eigen::VectorXi & idx0,
                                     const Eigen::VectorXi & idx1) {
  Eigen::VectorXd eigenvalues = 1 - eigenpair.values.head(K).array();
  const Eigen::MatrixXd & eigenvectors = eigenpair.vectors;
  Eigen::VectorXi cols = Eigen::VectorXi::LinSpaced(K,0,K-1);

  Eigen::MatrixXd H = mat_indexing(eigenvectors, idx0, cols)*Eigen::exp(-t*eigenvalues.array()).matrix().asDiagonal()\
    *mat_indexing(eigenvectors, idx1, cols).transpose();

  return H;
}






Eigen::SparseMatrix<double,Eigen::RowMajor> cross_similarity_lae_cpp(
    const Eigen::MatrixXd & X,
    const Eigen::MatrixXd & U,
    int r,
    Rcpp::String gl) {
  int d = X.cols();
  Eigen::SparseMatrix<double,Eigen::RowMajor> Z = LAE_cpp(X, U.leftCols(d), r);

  Eigen::VectorXd num_class;
  if(gl=="cluster-normalized") {
    num_class = U.col(d);
  }

  graphLaplacian_cpp(Z, gl, num_class);

  return Z;
}



EigenPair truncated_SVD_cpp(const Eigen::SparseMatrix<double,Eigen::RowMajor> & Z,
                             int K) {
  if(K<0) {
    K = Z.cols();
  }

  Eigen::MatrixXd vectors;
  Eigen::VectorXd values;
  if(K==Z.cols()) {
    Eigen::BDCSVD<Eigen::MatrixXd> svd(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(Z), Eigen::ComputeThinU|Eigen::ComputeThinV);
    vectors = svd.matrixU();
    values = svd.singularValues().array().square();
  } else {
    /*
    Rcpp::Environment irlba_pkg = Rcpp::Environment::namespace_env("irlba");
    Rcpp::Function irlba = irlba_pkg["irlba"];
    Rcpp::List pairs = irlba(Rcpp::Named("A")=Rcpp::wrap(Eigen::SparseMatrix<double>(Z)),
                             Rcpp::Named("nv")=K,
                             Rcpp::Named("work")=2*K);
    values = Rcpp::as<Eigen::VectorXd>(pairs["d"]).array().square();
    vectors = Rcpp::as<Eigen::MatrixXd>(pairs["u"]);
    */

    Rcpp::Environment RSpectra = Rcpp::Environment::namespace_env("RSpectra");
    Rcpp::Function svds = RSpectra["svds"];
    Rcpp::List pairs = svds(Rcpp::Named("A")=Rcpp::wrap(Eigen::SparseMatrix<double>(Z)),
                            Rcpp::Named("k")=K,
                            Rcpp::Named("nu")=K,
                            Rcpp::Named("nv")=0);
    values = Rcpp::as<Eigen::Map<Eigen::VectorXd>>(pairs["d"]).array().square();
    vectors = Rcpp::as<Eigen::Map<Eigen::MatrixXd>>(pairs["u"]);

    /*
    Spectra::SparseSymMatProd<double> op(Z.transpose()*Z);
    Spectra::SymEigsSolver<double, Spectra::LARGEST_ALGE, Spectra::SparseSymMatProd<double>> eigs_sym(&op, K, 2*K);
    eigs_sym.init();
    eigs_sym.compute();
    values = eigs_sym.eigenvalues();
    vectors = eigs_sym.eigenvectors();
    vectors = Z * (vectors * (1.0/(values.array()+1e-5).sqrt()).matrix().asDiagonal());
    */
  }

  return EigenPair(values, vectors);
}




EigenPair spectrum_from_Z_cpp(const Eigen::SparseMatrix<double,Eigen::RowMajor> & Z,
                               int K,
                               bool root) {
  Eigen::VectorXd Z_colsum = Eigen::RowVectorXd::Ones(Z.rows()) * Z;
  Eigen::SparseMatrix<double,Eigen::RowMajor> A = Z*(1.0/(Z_colsum.array().abs()+1e-5).sqrt()).matrix().asDiagonal();
  EigenPair pairs = truncated_SVD_cpp(A, K);

  if(root) {
    pairs.values = pairs.values.array().sqrt().matrix();
  }

  double n = Z.rows();
  pairs.vectors *= std::sqrt(n);

  return pairs;
}


