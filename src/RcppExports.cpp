// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// fit_lae_logit_gp_cpp
Rcpp::List fit_lae_logit_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int s, int r, int K, Eigen::VectorXd N, double sigma, std::string approach, Rcpp::List models, bool output_cov);
RcppExport SEXP _FLAG_fit_lae_logit_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP sSEXP, SEXP rSEXP, SEXP KSEXP, SEXP NSEXP, SEXP sigmaSEXP, SEXP approachSEXP, SEXP modelsSEXP, SEXP output_covSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type N(NSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    Rcpp::traits::input_parameter< bool >::type output_cov(output_covSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_lae_logit_gp_cpp(X, Y, X_new, s, r, K, N, sigma, approach, models, output_cov));
    return rcpp_result_gen;
END_RCPP
}
// fit_lae_logit_mult_gp_cpp
Rcpp::List fit_lae_logit_mult_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int s, int r, int K, double sigma, std::string approach, Rcpp::List models);
RcppExport SEXP _FLAG_fit_lae_logit_mult_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP sSEXP, SEXP rSEXP, SEXP KSEXP, SEXP sigmaSEXP, SEXP approachSEXP, SEXP modelsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_lae_logit_mult_gp_cpp(X, Y, X_new, s, r, K, sigma, approach, models));
    return rcpp_result_gen;
END_RCPP
}
// fit_se_logit_gp_cpp
Rcpp::List fit_se_logit_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int s, int r, int K, Eigen::VectorXd N, double sigma, std::vector<double> a2s, std::string approach, Rcpp::List models, bool output_cov);
RcppExport SEXP _FLAG_fit_se_logit_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP sSEXP, SEXP rSEXP, SEXP KSEXP, SEXP NSEXP, SEXP sigmaSEXP, SEXP a2sSEXP, SEXP approachSEXP, SEXP modelsSEXP, SEXP output_covSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type N(NSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a2s(a2sSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    Rcpp::traits::input_parameter< bool >::type output_cov(output_covSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_se_logit_gp_cpp(X, Y, X_new, s, r, K, N, sigma, a2s, approach, models, output_cov));
    return rcpp_result_gen;
END_RCPP
}
// fit_se_logit_mult_gp_cpp
Rcpp::List fit_se_logit_mult_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int s, int r, int K, double sigma, std::vector<double> a2s, std::string approach, Rcpp::List models);
RcppExport SEXP _FLAG_fit_se_logit_mult_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP sSEXP, SEXP rSEXP, SEXP KSEXP, SEXP sigmaSEXP, SEXP a2sSEXP, SEXP approachSEXP, SEXP modelsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a2s(a2sSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_se_logit_mult_gp_cpp(X, Y, X_new, s, r, K, sigma, a2s, approach, models));
    return rcpp_result_gen;
END_RCPP
}
// fit_nystrom_logit_gp_cpp
Rcpp::List fit_nystrom_logit_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int s, int K, Eigen::VectorXd N, double sigma, std::vector<double> a2s, std::string approach, Rcpp::List models, bool output_cov);
RcppExport SEXP _FLAG_fit_nystrom_logit_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP sSEXP, SEXP KSEXP, SEXP NSEXP, SEXP sigmaSEXP, SEXP a2sSEXP, SEXP approachSEXP, SEXP modelsSEXP, SEXP output_covSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type N(NSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a2s(a2sSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    Rcpp::traits::input_parameter< bool >::type output_cov(output_covSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_nystrom_logit_gp_cpp(X, Y, X_new, s, K, N, sigma, a2s, approach, models, output_cov));
    return rcpp_result_gen;
END_RCPP
}
// fit_nystrom_logit_mult_gp_cpp
Rcpp::List fit_nystrom_logit_mult_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int s, int K, double sigma, std::vector<double> a2s, std::string approach, Rcpp::List models);
RcppExport SEXP _FLAG_fit_nystrom_logit_mult_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP sSEXP, SEXP KSEXP, SEXP sigmaSEXP, SEXP a2sSEXP, SEXP approachSEXP, SEXP modelsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a2s(a2sSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_nystrom_logit_mult_gp_cpp(X, Y, X_new, s, K, sigma, a2s, approach, models));
    return rcpp_result_gen;
END_RCPP
}
// fit_gl_logit_gp_cpp
Rcpp::List fit_gl_logit_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int K, Eigen::VectorXd N, double sigma, std::vector<double> a2s, double threshold, bool sparse, std::string approach, Rcpp::List models, bool output_cov);
RcppExport SEXP _FLAG_fit_gl_logit_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP KSEXP, SEXP NSEXP, SEXP sigmaSEXP, SEXP a2sSEXP, SEXP thresholdSEXP, SEXP sparseSEXP, SEXP approachSEXP, SEXP modelsSEXP, SEXP output_covSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type N(NSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a2s(a2sSEXP);
    Rcpp::traits::input_parameter< double >::type threshold(thresholdSEXP);
    Rcpp::traits::input_parameter< bool >::type sparse(sparseSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    Rcpp::traits::input_parameter< bool >::type output_cov(output_covSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_gl_logit_gp_cpp(X, Y, X_new, K, N, sigma, a2s, threshold, sparse, approach, models, output_cov));
    return rcpp_result_gen;
END_RCPP
}
// fit_gl_logit_mult_gp_cpp
Rcpp::List fit_gl_logit_mult_gp_cpp(Eigen::MatrixXd X, Eigen::VectorXd Y, Eigen::MatrixXd X_new, int K, double sigma, std::vector<double> a2s, double threshold, bool sparse, std::string approach, Rcpp::List models);
RcppExport SEXP _FLAG_fit_gl_logit_mult_gp_cpp(SEXP XSEXP, SEXP YSEXP, SEXP X_newSEXP, SEXP KSEXP, SEXP sigmaSEXP, SEXP a2sSEXP, SEXP thresholdSEXP, SEXP sparseSEXP, SEXP approachSEXP, SEXP modelsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X(XSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type Y(YSEXP);
    Rcpp::traits::input_parameter< Eigen::MatrixXd >::type X_new(X_newSEXP);
    Rcpp::traits::input_parameter< int >::type K(KSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< std::vector<double> >::type a2s(a2sSEXP);
    Rcpp::traits::input_parameter< double >::type threshold(thresholdSEXP);
    Rcpp::traits::input_parameter< bool >::type sparse(sparseSEXP);
    Rcpp::traits::input_parameter< std::string >::type approach(approachSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type models(modelsSEXP);
    rcpp_result_gen = Rcpp::wrap(fit_gl_logit_mult_gp_cpp(X, Y, X_new, K, sigma, a2s, threshold, sparse, approach, models));
    return rcpp_result_gen;
END_RCPP
}
// test_pgbinary_cpp
Rcpp::List test_pgbinary_cpp(const Eigen::MatrixXd& C, const Eigen::VectorXd& Y, const Eigen::MatrixXd& Cnv, int N_sample, bool output_pi);
RcppExport SEXP _FLAG_test_pgbinary_cpp(SEXP CSEXP, SEXP YSEXP, SEXP CnvSEXP, SEXP N_sampleSEXP, SEXP output_piSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type C(CSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type Cnv(CnvSEXP);
    Rcpp::traits::input_parameter< int >::type N_sample(N_sampleSEXP);
    Rcpp::traits::input_parameter< bool >::type output_pi(output_piSEXP);
    rcpp_result_gen = Rcpp::wrap(test_pgbinary_cpp(C, Y, Cnv, N_sample, output_pi));
    return rcpp_result_gen;
END_RCPP
}
// cross_similarity_lae_cpp
Eigen::SparseMatrix<double,Eigen::RowMajor> cross_similarity_lae_cpp(const Eigen::MatrixXd& X, const Eigen::MatrixXd& U, int r, Rcpp::String gl);
RcppExport SEXP _FLAG_cross_similarity_lae_cpp(SEXP XSEXP, SEXP USEXP, SEXP rSEXP, SEXP glSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type U(USEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type gl(glSEXP);
    rcpp_result_gen = Rcpp::wrap(cross_similarity_lae_cpp(X, U, r, gl));
    return rcpp_result_gen;
END_RCPP
}
// subsample_cpp
Eigen::MatrixXd subsample_cpp(const Eigen::MatrixXd& X, int s, std::string method);
RcppExport SEXP _FLAG_subsample_cpp(SEXP XSEXP, SEXP sSEXP, SEXP methodSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type X(XSEXP);
    Rcpp::traits::input_parameter< int >::type s(sSEXP);
    Rcpp::traits::input_parameter< std::string >::type method(methodSEXP);
    rcpp_result_gen = Rcpp::wrap(subsample_cpp(X, s, method));
    return rcpp_result_gen;
END_RCPP
}
// KNN_cpp
Rcpp::List KNN_cpp(const Eigen::MatrixXd& X, const Eigen::MatrixXd& U, int r, std::string distance, bool output);
RcppExport SEXP _FLAG_KNN_cpp(SEXP XSEXP, SEXP USEXP, SEXP rSEXP, SEXP distanceSEXP, SEXP outputSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type U(USEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    Rcpp::traits::input_parameter< std::string >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< bool >::type output(outputSEXP);
    rcpp_result_gen = Rcpp::wrap(KNN_cpp(X, U, r, distance, output));
    return rcpp_result_gen;
END_RCPP
}
// LAE_cpp
Eigen::SparseMatrix<double, Eigen::RowMajor> LAE_cpp(const Eigen::MatrixXd& X, const Eigen::MatrixXd& U, int r);
RcppExport SEXP _FLAG_LAE_cpp(SEXP XSEXP, SEXP USEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type X(XSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type U(USEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(LAE_cpp(X, U, r));
    return rcpp_result_gen;
END_RCPP
}
// local_anchor_embedding_cpp
Eigen::RowVectorXd local_anchor_embedding_cpp(const Eigen::RowVectorXd& x, const Eigen::MatrixXd& U);
RcppExport SEXP _FLAG_local_anchor_embedding_cpp(SEXP xSEXP, SEXP USEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::RowVectorXd& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type U(USEXP);
    rcpp_result_gen = Rcpp::wrap(local_anchor_embedding_cpp(x, U));
    return rcpp_result_gen;
END_RCPP
}
// v_to_z_cpp
Eigen::RowVectorXd v_to_z_cpp(const Eigen::RowVectorXd& v);
RcppExport SEXP _FLAG_v_to_z_cpp(SEXP vSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::RowVectorXd& >::type v(vSEXP);
    rcpp_result_gen = Rcpp::wrap(v_to_z_cpp(v));
    return rcpp_result_gen;
END_RCPP
}
// marginal_log_likelihood_logit_la_cpp
double marginal_log_likelihood_logit_la_cpp(const Eigen::MatrixXd& C, const Eigen::VectorXd& Y, const Eigen::VectorXd& N, double tol, int max_iter);
RcppExport SEXP _FLAG_marginal_log_likelihood_logit_la_cpp(SEXP CSEXP, SEXP YSEXP, SEXP NSEXP, SEXP tolSEXP, SEXP max_iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type C(CSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type Y(YSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type N(NSEXP);
    Rcpp::traits::input_parameter< double >::type tol(tolSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    rcpp_result_gen = Rcpp::wrap(marginal_log_likelihood_logit_la_cpp(C, Y, N, tol, max_iter));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_FLAG_fit_lae_logit_gp_cpp", (DL_FUNC) &_FLAG_fit_lae_logit_gp_cpp, 11},
    {"_FLAG_fit_lae_logit_mult_gp_cpp", (DL_FUNC) &_FLAG_fit_lae_logit_mult_gp_cpp, 9},
    {"_FLAG_fit_se_logit_gp_cpp", (DL_FUNC) &_FLAG_fit_se_logit_gp_cpp, 12},
    {"_FLAG_fit_se_logit_mult_gp_cpp", (DL_FUNC) &_FLAG_fit_se_logit_mult_gp_cpp, 10},
    {"_FLAG_fit_nystrom_logit_gp_cpp", (DL_FUNC) &_FLAG_fit_nystrom_logit_gp_cpp, 11},
    {"_FLAG_fit_nystrom_logit_mult_gp_cpp", (DL_FUNC) &_FLAG_fit_nystrom_logit_mult_gp_cpp, 9},
    {"_FLAG_fit_gl_logit_gp_cpp", (DL_FUNC) &_FLAG_fit_gl_logit_gp_cpp, 12},
    {"_FLAG_fit_gl_logit_mult_gp_cpp", (DL_FUNC) &_FLAG_fit_gl_logit_mult_gp_cpp, 10},
    {"_FLAG_test_pgbinary_cpp", (DL_FUNC) &_FLAG_test_pgbinary_cpp, 5},
    {"_FLAG_cross_similarity_lae_cpp", (DL_FUNC) &_FLAG_cross_similarity_lae_cpp, 4},
    {"_FLAG_subsample_cpp", (DL_FUNC) &_FLAG_subsample_cpp, 3},
    {"_FLAG_KNN_cpp", (DL_FUNC) &_FLAG_KNN_cpp, 5},
    {"_FLAG_LAE_cpp", (DL_FUNC) &_FLAG_LAE_cpp, 3},
    {"_FLAG_local_anchor_embedding_cpp", (DL_FUNC) &_FLAG_local_anchor_embedding_cpp, 2},
    {"_FLAG_v_to_z_cpp", (DL_FUNC) &_FLAG_v_to_z_cpp, 1},
    {"_FLAG_marginal_log_likelihood_logit_la_cpp", (DL_FUNC) &_FLAG_marginal_log_likelihood_logit_la_cpp, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_FLAG(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
