# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

fit_rbf_regression_gp_cpp <- function(X_train, Y_train, X_test, s, sigma, approach, noise, sample, output_cov, nstart) {
    .Call(`_FLAG_fit_rbf_regression_gp_cpp`, X_train, Y_train, X_test, s, sigma, approach, noise, sample, output_cov, nstart)
}

fit_lae_regression_gp_cpp <- function(X_train, Y_train, X_test, s, r, K, sigma, approach, noise, models, output_cov, nstart) {
    .Call(`_FLAG_fit_lae_regression_gp_cpp`, X_train, Y_train, X_test, s, r, K, sigma, approach, noise, models, output_cov, nstart)
}

fit_se_regression_gp_cpp <- function(X_train, Y_train, X_test, s, r, K, sigma, a2s, approach, noise, models, output_cov, nstart) {
    .Call(`_FLAG_fit_se_regression_gp_cpp`, X_train, Y_train, X_test, s, r, K, sigma, a2s, approach, noise, models, output_cov, nstart)
}

fit_nystrom_regression_gp_cpp <- function(X_train, Y_train, X_test, s, K, sigma, a2s, approach, noise, models, output_cov, nstart) {
    .Call(`_FLAG_fit_nystrom_regression_gp_cpp`, X_train, Y_train, X_test, s, K, sigma, a2s, approach, noise, models, output_cov, nstart)
}

fit_gl_regression_gp_cpp <- function(X_train, Y_train, X_test, K, sigma, a2s, threshold, sparse, approach, noise, models, output_cov) {
    .Call(`_FLAG_fit_gl_regression_gp_cpp`, X_train, Y_train, X_test, K, sigma, a2s, threshold, sparse, approach, noise, models, output_cov)
}

fit_lae_logit_gp_cpp <- function(X_train, Y_train, X_test, s, r, K, N_train, sigma, approach, models, output_cov, nstart) {
    .Call(`_FLAG_fit_lae_logit_gp_cpp`, X_train, Y_train, X_test, s, r, K, N_train, sigma, approach, models, output_cov, nstart)
}

fit_lae_logit_mult_gp_cpp <- function(X_train, Y_train, X_test, s, r, K, sigma, approach, models, nstart) {
    .Call(`_FLAG_fit_lae_logit_mult_gp_cpp`, X_train, Y_train, X_test, s, r, K, sigma, approach, models, nstart)
}

fit_se_logit_gp_cpp <- function(X_train, Y_train, X_test, s, r, K, N_train, sigma, a2s, approach, models, output_cov, nstart) {
    .Call(`_FLAG_fit_se_logit_gp_cpp`, X_train, Y_train, X_test, s, r, K, N_train, sigma, a2s, approach, models, output_cov, nstart)
}

fit_se_logit_mult_gp_cpp <- function(X_train, Y_train, X_test, s, r, K, sigma, a2s, approach, models, nstart) {
    .Call(`_FLAG_fit_se_logit_mult_gp_cpp`, X_train, Y_train, X_test, s, r, K, sigma, a2s, approach, models, nstart)
}

fit_nystrom_logit_gp_cpp <- function(X_train, Y_train, X_test, s, K, N_train, sigma, a2s, approach, models, output_cov, nstart) {
    .Call(`_FLAG_fit_nystrom_logit_gp_cpp`, X_train, Y_train, X_test, s, K, N_train, sigma, a2s, approach, models, output_cov, nstart)
}

fit_nystrom_logit_mult_gp_cpp <- function(X_train, Y_train, X_test, s, K, sigma, a2s, approach, models, nstart) {
    .Call(`_FLAG_fit_nystrom_logit_mult_gp_cpp`, X_train, Y_train, X_test, s, K, sigma, a2s, approach, models, nstart)
}

fit_gl_logit_gp_cpp <- function(X_train, Y_train, X_test, K, N_train, sigma, a2s, threshold, sparse, approach, models, output_cov) {
    .Call(`_FLAG_fit_gl_logit_gp_cpp`, X_train, Y_train, X_test, K, N_train, sigma, a2s, threshold, sparse, approach, models, output_cov)
}

fit_gl_logit_mult_gp_cpp <- function(X_train, Y_train, X_test, K, sigma, a2s, threshold, sparse, approach, models) {
    .Call(`_FLAG_fit_gl_logit_mult_gp_cpp`, X_train, Y_train, X_test, K, sigma, a2s, threshold, sparse, approach, models)
}

#' Predict labels on new samples with Polya-Gamma
#'
#' @param C A numeric matrix with dim(m,m), the self covariance matrix
#' in the training samples.
#' @param Y A numeric vector with length(m), count of the positive class.
#' @param Cnv A numeric matrix with dim(m_new,m), cross covariance matrix
#' between new sample and training sample.
#' @param N_sample An integer, the length of the Gibbs sampler chain.
#' @param output_pi Bool, whether or not to output pi_new, defaulting value is `FALSE`.
#'
#' @return `list(Y_pred)` if `output_pi=FALSE`, otherwise `list(Y_pred,pi_pred)`.
#' @export
#'
#' @examples
#' Z <- matrix(rnorm(3*3),3,3)
#' C <- Z%*%t(Z)
#' Y <- sample(c(0,1),3, replace=TRUE)
#' Cnv <- matrix(rnorm(5*3),5,3)
#' test_pgbinary_cpp(C, Y, Cnv)
test_pgbinary_cpp <- function(C, Y, Cnv, N_sample = 100L, output_pi = FALSE) {
    .Call(`_FLAG_test_pgbinary_cpp`, C, Y, Cnv, N_sample, output_pi)
}

#' Predict labels on new samples in the regression
#'
#' @param C A numeric matrix with dim(m,m), the self covariance matrix of noisy targets Y.
#' in the training samples.
#' @param Y A numeric vector with length(m), the training labels.
#' @param Cnv A numeric matrix with dim(m_new,m), cross covariance matrix
#' between new sample and training sample.
#'
#' @return `Y_pred`, A numeric vector with length(m_new), the prediction labels.
#' @export
#'
#' @examples
#' Z <- matrix(rnorm(3*3),3,3)
#' C <- Z%*%t(Z)
#' Y <- runif(3)
#' Cnv <- matrix(rnorm(5*3),5,3)
#' test_regression_cpp(C, Y, Cnv)
test_regression_cpp <- function(C, Y, Cnv) {
    .Call(`_FLAG_test_regression_cpp`, C, Y, Cnv)
}

#' Compute cross similarity matrix Z between X and U
#'
#' @param X A numeric matrix with dim (n,d), original sample,
#' each row indicates one original point in R^d.
#' @param U A numeric matrix with dim (s,d) or (s,d+1), sub-sample,
#' each row indicates one representative point in R^d,
#' where the d+1 column indicates the number of points in each cluster if it exists.
#' @param r An integer, the number of the nearest neighbor points.
#' @param gl A character vector in c("rw", "normalized", "cluster-normalized"),
#' indicates how to construct the stochastic transition matrix. "rw" means random walk,
#' "normalized" means normalized random walk, "cluster-normalized" means
#' normalized random walk with cluster membership re-balance. The defaulting gl
#' is "rw".
#'
#' @return `Z` A numeric sparse dgr matrix with dim (n,s),
#' the stochastic transition matrix from X to U.
#' @export
#'
#' @examples
#' X <- matrix(rnorm(5*2), 5, 2)
#' U <- subsample(X, 2, "random")
#' r <- 2
#' cross_similarity_lae_cpp(X, U, r)
cross_similarity_lae_cpp <- function(X, U, r = 3L, gl = "rw") {
    .Call(`_FLAG_cross_similarity_lae_cpp`, X, U, r, gl)
}

#' Subsample in the domain
#'
#' @param X Original sample, a (n, d) matrix, each row indicates one point in R^d.
#' @param s An integer indicating the number of the subsampling.
#' @param method How to subsample, characters in c("kmeans", "random"),
#' including kmeans and random selection, the
#' defaulting subsampling method is kmeans.
#'
#' @return A subsampling, a (s, d) or (s, d+1) matrix, each row indicates one point in R^d,
#' where the d+1 column indicates the number of points in each cluster if it exists.
#' @export
#'
#' @examples
#' X <- matrix(rnorm(10*3), nrow=10, ncol=3)
#' s <- 3
#' U = subsample_cpp(X, s, method = "kmeans")
subsample_cpp <- function(X, s, method = "kmeans", nstart = 1L) {
    .Call(`_FLAG_subsample_cpp`, X, s, method, nstart)
}

#' k-nearest neighbor reference points
#'
#' @param X Original points, a (n,d) matrix, each row indicates one original point.
#' @param U Reference points, a (s,d) or (s,d+1) matrix, each row indicates one reference point.
#' @param r The number of k-nearest neighbor points, an integer.
#' @param distance The distance method to compute k-nearest neighbor points, characters in c("Euclidean", "geodesic"),
#'  including Euclidean distance and geodesic distance, the defaulting distance
#'  is Euclidean distance.
#' @param output Bool, whether to output the distance matrix, defaulting value is `FALSE`.
#' @param batch Int, the batch size, defaulting value is `100`.
#'
#' @return If `output=FALSE`, `list(ind_knn)`, the indexes of KNN, a list with length n, each component of the list is a vector of length r,
#'  indicating the indexes of KNN for the corresponding original point based on the chosen distance.
#'  Otherwise `output=TRUE`, `list(ind_knn,distances_sp)`, a list with two components, the one is the indexes of KNN,
#'  the other is the sparse distance matrix with dim(n,s).
#' @export
#'
#' @examples
#' X <- matrix(rnorm(300), nrow=100, ncol=3)
#' U <- matrix(rnorm(30), nrow=10, ncol=3)
#' r <- 3
#' distance <- "Euclidean"
#' KNN_cpp(X, U, r, distance)
KNN_cpp <- function(X, U, r = 3L, distance = "Euclidean", output = FALSE, batch = 100L) {
    .Call(`_FLAG_KNN_cpp`, X, U, r, distance, output, batch)
}

#' Local anchor embedding
#'
#' @param X A numeric matrix with dim (n,d), original sample,
#' each row indicates one original point in R^d.
#' @param U A numeric matrix with dim (s,d) or (s,d+1), sub-sample,
#' each row indicates one representative point in R^d,
#' where the d+1 column indicates the number of points in each cluster if it exists.
#' @param r An integer, the number of the nearest neighbor points.
#' @param cl The cluster to make parallel computing,
#' typically generated by `parallel::makeCluster(num_workers)`.
#' The defaulting value of cl is NULL, that is, sequential computing.
#'
#' @return A numeric 'sparse' matrix with dim (n,s) and n*r non-zero entries, r << s,
#' the stochastic transition matrix from X to U.
#' @export
#'
#' @examples
#' X <- matrix(rnorm(10*3),10,3)
#' r <- 3
#' U <- matrix(rnorm(5*3),5,3)
#' LAE_cpp(X, U, r)
LAE_cpp <- function(X, U, r = 3L) {
    .Call(`_FLAG_LAE_cpp`, X, U, r)
}

#' Local anchor embedding of one single point by
#' gradient descent projection with Nesterov's methods
#'
#' @param x A numeric row vector with length(d), indicates the single point to be embedded.
#' @param U A numeric matrix with dimension (r, d), the columns of U
#' are equal to the length of x, including KNN reference points.
#'
#' @return A numeric vector with the length r, convex combination coefficients.
#' @export
#'
#' @examples
#' x <- rnorm(3)
#' U <- matrix(rnorm(3*3),3,3)
#' local_anchor_embedding_cpp(x,U)
local_anchor_embedding_cpp <- function(x, U) {
    .Call(`_FLAG_local_anchor_embedding_cpp`, x, U)
}

#' Simplex projection into convex combination coefficients
#'
#' @param v A numeric vector to be projected.
#'
#' @return A numeric vector of convex combination coefficients with
#' the same length of v.
#' @export
#'
#' @examples
#' v <- rnorm(3)
#' v_to_z_cpp(v)
v_to_z_cpp <- function(v) {
    .Call(`_FLAG_v_to_z_cpp`, v)
}

#' Mode-finding for binary Laplace GPC with logit link function
#'
#' @param C A numeric matrix with dim(m,m), covariance matrix.
#' @param Y A numeric vector with length(m), count of the positive class.
#' @param N A numeric vector with length(m), total count.
#' @param tol A double, convergence criterion, the defaulting value is `1e-5`.
#' @param max_iter An integer, the maximum iteration number, defaulting value `100`.
#'
#' @return `amll` A double, the Laplace approximation of the marginal log likelihood.
#' @export
#'
#' @examples
#' A <- matrix(rnorm(3*3),3,3)
#' C <- A%*%t(A)
#' Y <- sample(c(0,1), 3,replace=TRUE)
#' N <- rep(1,3)
#' marginal_log_likelihood_logit_la_cpp(C, Y, N)
marginal_log_likelihood_logit_la_cpp <- function(C, Y, N, tol = 1e-5, max_iter = 100L) {
    .Call(`_FLAG_marginal_log_likelihood_logit_la_cpp`, C, Y, N, tol, max_iter)
}

