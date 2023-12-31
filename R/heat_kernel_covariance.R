#' Construct heat kernel covariance matrix by FLAG
#'
#' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
#' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
#' @param s An integer indicating the number of the subsampling.
#' @param r An integer, the number of the nearest neighbor points.
#' @param t A non-negative number, the heat diffusion time.
#' @param K An integer, the number of used eigenpairs to construct heat kernel,
#' the defaulting value is `NULL`, that is, `K=s`.
#' @param sigma A non-negative number, the weight coefficient of ridge penalty on H,
#' the defaulting value is 1e-3.
#' @param cl The cluster to make parallel computing,
#' typically generated by `parallel::makeCluster(num_workers)`.
#' The defaulting value of cl is NULL, that is, sequential computing.
#' @param models A list, including
#' * `subsample` the method of subsampling, the defaulting value is `kmeans`.
#' * `kernel` the type of kernel to compute cross similarity matrix W, the
#' defaulting value is `lae`.
#' * `gl` the kind of graph Laplacian L, the defaulting value is `rw`.
#' * `root` whether to square root eigenvalues of the two steps similarity matrix W,
#' the defaulting value is `FALSE`.
#'
#' @return A numeric matrix with dim (n,m), the covariance matrix of heat kernel
#' Gaussian processes with ridge penalty.
#' @export
#'
#' @examples
#' X <- matrix(rnorm(2*2), 2, 2)
#' X_new <- matrix(rnorm(3*2),3,2)
#' s <- 2; r <- 2; t <- 1
#' heat_kernel_covariance(X, X_new, s, r, t)
heat_kernel_covariance <- function(X, X_new, s, r, t, K=NULL, sigma=1e-3, cl=NULL,
                                   models=list(subsample="kmeans",
                                               kernel="lae",
                                               gl="rw",
                                               root=FALSE)) {
  m = nrow(X)

  eigenpairs = heat_kernel_spectrum(X, X_new, s, r, K, cl, models)
  H = HK_from_spectrum(eigenpairs, K, t, NULL, c(1:m))
  H[cbind(c(1:m),c(1:m))] = H[cbind(c(1:m),c(1:m))] + sigma # ridge penalty
  return(H)
}



#' Compute spectrum of graph Laplacian by FLAG
#'
#' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
#' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
#' @param s An integer indicating the number of the subsampling.
#' @param r An integer, the number of the nearest neighbor points.
#' @param K An integer, the number of used eigenpairs to construct heat kernel,
#' the defaulting value is `NULL`, that is, `K=s`.
#' @param cl The cluster to make parallel computing,
#' typically generated by `parallel::makeCluster(num_workers)`.
#' The defaulting value of cl is NULL, that is, sequential computing.
#' @param models A list, including
#' * `subsample` the method of subsampling, the defaulting value is `kmeans`.
#' * `kernel` the type of kernel to compute cross similarity matrix W, the
#' defaulting value is `lae`.
#' * `gl` the kind of graph Laplacian L, the defaulting value is `rw`.
#' * `root` whether to square root eigenvalues of the two steps similarity matrix W,
#' the defaulting value is `FALSE`.
#'
#' @return A list of converged eigenvalues and eigenvectors of W.
#' \describe{
#' \item{values}{eigenvalues, descending order.}
#' \item{vectors}{eigenvectors.}
#' }
#' @export
#'
#' @examples
#' X <- matrix(rnorm(2*2), 2, 2)
#' X_new <- matrix(rnorm(3*2),3,2)
#' s <- 2; r <- 2
#' heat_kernel_spectrum(X, X_new, s, r)
heat_kernel_spectrum <- function(X, X_new, s, r, K=NULL, cl=NULL,
                                 models=list(subsample="kmeans",
                                             kernel="lae",
                                             gl="rw",
                                             root=FALSE)) {
  X = rbind(X, X_new)
  U = subsample(X, s, models$subsample)
  Z = cross_similarity(X, U, r, models$kernel, models$gl, cl)
  if(is.null(K)) {
    K = s
  }
  eigenpairs = spectrum_from_Z(Z, K, models$root)
  return(eigenpairs)
}
