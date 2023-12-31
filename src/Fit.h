#ifndef FIT_H
#define FIT_H

// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>


// [[Rcpp::export(fit_rbf_regression_gp_cpp)]]
Rcpp::List fit_rbf_regression_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                     int s,
                                     double sigma, std::string approach, std::string noise,
                                     std::string sample,
                                     bool output_cov,
                                     int nstart);

/*
//' Fit Gaussian process regression with local anchor embedding kernels
//'
//' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
//' @param Y A numeric vector with length(m), count of the positive class.
//' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
//' @param s An integer indicating the number of the subsampling.
//' @param r An integer, the number of the nearest neighbor points.
//' @param K An integer, the number of used eigenpairs to construct heat kernel,
//' the defaulting value is `NULL`, that is, `K=min(n,s)`.
//' @param sigma A non-negative number, the weight coefficient of ridge penalty on H,
//' the defaulting value is 1e-3.
//' @param approach A character vector, taking value in c("posterior", "marginal"),
//' decides which objective function to be optimized, defaulting value is `posterior`.
//' @param models A list with four components
//' \describe{
//' \item{subsample}{the method of subsampling, the defaulting value is `kmeans`.}
//' \item{kernel}{the type of kernel to compute cross similarity matrix W, the
//' defaulting value is `lae`.}
//' \item{gl}{the kind of graph Laplacian L, the defaulting value is `rw`.}
//' \item{root}{whether to square root eigenvalues of the two steps similarity matrix W,
//' the defaulting value is `FALSE`.}
//' }
//' @param output_cov Bool, whether to output covariance, defaulting value is `FALSE`.
//' @param n_start Int, the number of random sets should be chosen in k-means.
//'
//' @return `Y_pred` A numeric vector with length(m_new), each element indicates
//' the label in the corresponding new sample point.
//' @export
//'
//' @examples
//' X0 <- matrix(rnorm(3*3), 3, 3)
//' X1 <- matrix(rnorm(3*3, 5), 3, 3)
//' Y <- runif(6)
//' X <- rbind(X0,X1)
//' X0_new <- matrix(rnorm(10*3),10,3)
//' X1_new <- matrix(rnorm(10*3, 5),10,3)
//' X_new <- rbind(X0_new, X1_new)
//' Y_new <- runif(20)
//' s <- 6; r <- 3
//' K <- 5
//' Y_pred <- fit_lae_regression_gp_cpp(X, Y, X_new, s, r, K)
*/
// [[Rcpp::export(fit_lae_regression_gp_cpp)]]
Rcpp::List fit_lae_regression_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                     int s, int r, int K,
                                     double sigma, std::string approach, std::string noise,
                                     Rcpp::List models,
                                     bool output_cov,
                                     int nstart);

// Fit Gaussian process regression with the square exponential kernels
// [[Rcpp::export(fit_se_regression_gp_cpp)]]
Rcpp::List fit_se_regression_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                    int s, int r, int K,
                                    double sigma, std::vector<double> a2s, std::string approach,
                                    std::string noise,
                                    Rcpp::List models,
                                    bool output_cov,
                                    int nstart);

// Fit Gaussian process regression with the nystrom extension
// [[Rcpp::export(fit_nystrom_regression_gp_cpp)]]
Rcpp::List fit_nystrom_regression_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                         int s, int K,
                                         double sigma, std::vector<double> a2s, std::string approach,
                                         std::string noise,
                                         Rcpp::List models,
                                         bool output_cov,
                                         int nstart);

// Fit Gaussian process regression with the graph Laplacian
// [[Rcpp::export(fit_gl_regression_gp_cpp)]]
Rcpp::List fit_gl_regression_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                    int K,
                                    double sigma, std::vector<double> a2s,
                                    double threshold, bool sparse,
                                    std::string approach, std::string noise,
                                    Rcpp::List models,
                                    bool output_cov);

/*
//' Fit Gaussian process logistic regression with local anchor embedding kernels
//'
//' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
//' @param Y A numeric vector with length(m), count of the positive class.
//' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
//' @param s An integer indicating the number of the subsampling.
//' @param r An integer, the number of the nearest neighbor points.
//' @param K An integer, the number of used eigenpairs to construct heat kernel,
//' the defaulting value is `NULL`, that is, `K=min(n,s)`.
//' @param N A numeric vector with length(m), total count.
//' @param sigma A non-negative number, the weight coefficient of ridge penalty on H,
//' the defaulting value is 1e-3.
//' @param approach A character vector, taking value in c("posterior", "marginal"),
//' decides which objective function to be optimized, defaulting value is `posterior`.
//' @param cl The cluster to make parallel computing,
//' typically generated by `parallel::makeCluster(num_workers)`.
//' The defaulting value of cl is NULL, that is, sequential computing.
//' @param models A list with four components
//' \describe{
//' \item{subsample}{the method of subsampling, the defaulting value is `kmeans`.}
//' \item{kernel}{the type of kernel to compute cross similarity matrix W, the
//' defaulting value is `lae`.}
//' \item{gl}{the kind of graph Laplacian L, the defaulting value is `rw`.}
//' \item{root}{whether to square root eigenvalues of the two steps similarity matrix W,
//' the defaulting value is `FALSE`.}
//' }
//' @param output_cov Bool, whether to output covariance, defaulting value is `FALSE`.
//'
//' @return `Y_pred` A numeric vector with length(m_new), each element indicates
//' the label in the corresponding new sample point.
//' @export
//'
//' @examples
//' X0 <- matrix(rnorm(3*3), 3, 3)
//' X1 <- matrix(rnorm(3*3, 5), 3, 3)
//' Y <- c(1,1,1,0,0,0)
//' X <- rbind(X0,X1)
//' X0_new <- matrix(rnorm(10*3),10,3)
//' X1_new <- matrix(rnorm(10*3, 5),10,3)
//' X_new <- rbind(X0_new, X1_new)
//' Y_new <- c(rep(1,10),rep(0,10))
//' s <- 6; r <- 3
//' K <- 5
//' Y_pred <- fit_lae_logit_gp_cpp(X, Y, X_new, s, r, K)
*/
// [[Rcpp::export(fit_lae_logit_gp_cpp)]]
Rcpp::List fit_lae_logit_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                int s, int r, int K, Rcpp::NumericVector N_train,
                                double sigma, std::string approach,
                                Rcpp::List models,
                                bool output_cov,
                                int nstart);


/*
//' Fit Gaussian process logistic multinomial regression with local anchor embedding kernels
//'
//' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
//' @param Y A numeric vector with length(m), indicating the labels of multi-classes,
//' `Y` should be continuous integers, such as 0,1,2,...,9.
//' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
//' @param s An integer indicating the number of the subsampling.
//' @param r An integer, the number of the nearest neighbor points.
//' @param K An integer, the number of used eigenpairs to construct heat kernel,
//' the defaulting value is `NULL`, that is, `K=min(n,s)`.
//' @param N A numeric vector with length(m), total count.
//' @param sigma A non-negative number, the weight coefficient of ridge penalty on H,
//' the defaulting value is 1e-3.
//' @param approach A character vector, taking value in c("posterior", "marginal"),
//' decides which objective function to be optimized, defaulting value is `posterior`.
//' @param cl The cluster to make parallel computing,
//' typically generated by `parallel::makeCluster(num_workers)`.
//' The defaulting value of cl is NULL, that is, sequential computing.
//' @param models A list with four components
//' \describe{
//' \item{subsample}{the method of subsampling, the defaulting value is `kmeans`.}
//' \item{kernel}{the type of kernel to compute cross similarity matrix W, the
//' defaulting value is `lae`.}
//' \item{gl}{the kind of graph Laplacian L, the defaulting value is `rw`.}
//' \item{root}{whether to square root eigenvalues of the two steps similarity matrix W,
//' the defaulting value is `FALSE`.}
//' }
//' @param output_cov Bool, whether to output covariance, defaulting value is `FALSE`.
//'
//' @return `Y_pred` A numeric vector with length(m_new), each element indicates
//' the label in the corresponding new sample point.
//' @export
//'
//' @examples
//' X0 <- matrix(rnorm(3*3), 3, 3)
//' X1 <- matrix(rnorm(3*3, 5), 3, 3)
//' X2 <- matrix(rnorm(3*3, -5), 3, 3)
//' Y <- c(0,0,0,1,1,1,2,2,2)
//' X <- rbind(X0,X1,X2)
//' X0_new <- matrix(rnorm(10*3),10,3)
//' X1_new <- matrix(rnorm(10*3, 5),10,3)
//' X2_new <- matrix(rnorm(10*3, -5),10,3)
//' X_new <- rbind(X0_new, X1_new, X2_new)
//' Y_new <- c(rep(0,10),rep(1,10),rep(2,10))
//' s <- 6; r <- 3
//' K <- 5
//' Y_pred <- fit_lae_logit_mult_gp_cpp(X, Y, X_new, s, r, K)
*/
// [[Rcpp::export(fit_lae_logit_mult_gp_cpp)]]
Rcpp::List fit_lae_logit_mult_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                     int s, int r, int K,
                                     double sigma, std::string approach,
                                     Rcpp::List models,
                                     int nstart);



// Fit Gaussian process logistic regression with square exponential kernels
// [[Rcpp::export(fit_se_logit_gp_cpp)]]
Rcpp::List fit_se_logit_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                               int s, int r, int K, Rcpp::NumericVector N_train,
                               double sigma, std::vector<double> a2s, std::string approach,
                               Rcpp::List models,
                               bool output_cov,
                               int nstart);


// Fit Gaussian process logistic multinomial regression with square exponential kernels
// [[Rcpp::export(fit_se_logit_mult_gp_cpp)]]
Rcpp::List fit_se_logit_mult_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                    int s, int r, int K,
                                    double sigma, std::vector<double> a2s, std::string approach,
                                    Rcpp::List models,
                                    int nstart);

// Fit Gaussian process logistic regression with Nystrom extension
// [[Rcpp::export(fit_nystrom_logit_gp_cpp)]]
Rcpp::List fit_nystrom_logit_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                    int s, int K, Rcpp::NumericVector N_train,
                                    double sigma, std::vector<double> a2s, std::string approach,
                                    Rcpp::List models,
                                    bool output_cov,
                                    int nstart);

// Fit Gaussian process logistic multinomial regression with Nystrom extension
// [[Rcpp::export(fit_nystrom_logit_mult_gp_cpp)]]
Rcpp::List fit_nystrom_logit_mult_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                         int s, int K,
                                         double sigma, std::vector<double> a2s, std::string approach,
                                         Rcpp::List models,
                                         int nstart);

// Fit logistic regression with GLGP
// [[Rcpp::export(fit_gl_logit_gp_cpp)]]
Rcpp::List fit_gl_logit_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                               int K, Rcpp::NumericVector N_train,
                               double sigma, std::vector<double> a2s,
                               double threshold, bool sparse,
                               std::string approach,
                               Rcpp::List models,
                               bool output_cov);

// Fit logistic multinomial regression with GLGP
// [[Rcpp::export(fit_gl_logit_mult_gp_cpp)]]
Rcpp::List fit_gl_logit_mult_gp_cpp(Rcpp::NumericMatrix X_train, Rcpp::NumericVector Y_train, Rcpp::NumericMatrix X_test,
                                    int K,
                                    double sigma, std::vector<double> a2s,
                                    double threshold, bool sparse,
                                    std::string approach,
                                    Rcpp::List models);

#endif
