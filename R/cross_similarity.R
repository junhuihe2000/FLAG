#' Compute cross similarity matrix Z between X and U
#'
#' @param X A numeric matrix with dim (n,d), original sample,
#' each row indicates one original point in R^d.
#' @param U A numeric matrix with dim (s,d) or (s,d+1), sub-sample,
#' each row indicates one representative point in R^d,
#' where the d+1 column indicates the number of points in each cluster if it exists.
#' @param r An integer, the number of the nearest neighbor points.
#' @param kernel A character vectors in c("lae"), the type of kernel in computing
#' the cross similarity matrix Z, the defaulting value is "lae".
#' @param gl A character vector in c("rw", "normalized", "cluster-normalized"),
#' indicates how to construct the stochastic transition matrix. "rw" means random walk,
#' "normalized" means normalized random walk, "cluster-normalized" means
#' normalized random walk with cluster membership re-balance. The defaulting gl
#' is "rw".
#' @param cl he cluster to make parallel computing,
#' typically generated by parallel::makeCluster(num_workers).
#' The defaulting value of cl is NULL, that is, sequential computing.
#'
#' @return `Z` A numeric matrix with dim (n,s),
#' the stochastic transition matrix from X to U.
#' @export
#'
#' @examples
#' X <- matrix(rnorm(5*2), 5, 2)
#' U <- subsample(X, 2, "random")
#' cross_similarity(X, U, 2)
cross_similarity <- function(X, U, r=3L, kernel="lae", gl="rw", cl=NULL) {
  stopifnot(ncol(U)-ncol(X)==0||ncol(U)-ncol(X)==1, r<=nrow(U))
  d = ncol(X)

  if(kernel=="lae") {
    Z = LAE(X, U[,1:d, drop=FALSE], r, cl=cl)
  } else {
    stop("Error: the kernel is not supported!")
  }

  num_class = NULL
  if(gl=="cluster-normalized") {
    num_class = U[,d+1]
  }

  Z = graphLaplacian(Z, gl, num_class)

  return(Z)
}
