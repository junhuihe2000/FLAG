#' Fit Gaussian process logistic regression with square exponential kernels
#'
#' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
#' @param Y A numeric vector with length(m), count of the positive class.
#' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
#' @param s An integer indicating the number of the subsampling.
#' @param r An integer, the number of the nearest neighbor points.
#' @param K An integer, the number of used eigenpairs to construct heat kernel,
#' the defaulting value is `NULL`, that is, `K=min(n,s)`.
#' @param N A numeric vector with length(m), total count.
#' @param sigma A non-negative number, the weight coefficient of ridge penalty on H,
#' the defaulting value is 1e-3.
#' @param a2s A numeric vector, the searching range for bandwidth.
#' @param approach A character vector, taking value in c("posterior", "marginal"),
#' decides which objective function to be optimized, defaulting value is `posterior`.
#' @param cl The cluster to make parallel computing,
#' typically generated by `parallel::makeCluster(num_workers)`.
#' The defaulting value of cl is NULL, that is, sequential computing.
#' @param models A list with four components
#' \describe{
#' \item{subsample}{the method of subsampling, the defaulting value is `kmeans`.}
#' \item{kernel}{the type of kernel to compute cross similarity matrix W, the
#' defaulting value is `lae`.}
#' \item{gl}{the kind of graph Laplacian L, the defaulting value is `rw`.}
#' \item{root}{whether to square root eigenvalues of the two steps similarity matrix W,
#' the defaulting value is `FALSE`.}
#' }
#' @param output_cov Bool, whether to output covariance, defaulting value is `FALSE`.
#'
#' @return `Y_pred` A numeric vector with length(m_new), each element indicates
#' the label in the corresponding new sample point.
#' @export
#'
#' @examples
#' X0 <- matrix(rnorm(3*3), 3, 3)
#' X1 <- matrix(rnorm(3*3, 5), 3, 3)
#' Y <- c(1,1,1,0,0,0)
#' X <- rbind(X0,X1)
#' X0_new <- matrix(rnorm(10*3),10,3)
#' X1_new <- matrix(rnorm(10*3, 5),10,3)
#' X_new <- rbind(X0_new, X1_new)
#' Y_new <- c(rep(1,10),rep(0,10))
#' s <- 6; r <- 3
#' K <- 5
#' Y_pred <- fit_se_logit_gp_r(X, Y, X_new, s, r, K)
fit_se_logit_gp_r <- function(X, Y, X_new, s, r, K=NULL, N=NULL, sigma=1e-3, a2s=NULL,
                             approach ="posterior", cl=NULL,
                             models=list(subsample="kmeans",
                                         kernel="se",
                                         gl="rw",
                                         root=FALSE),
                             output_cov=FALSE) {
  cat("Square exponential kernel:\n")

  m = nrow(X)
  n = m + nrow(X_new)

  if(is.null(K)) {
    K = s
  }

  if(is.null(a2s)) {
    a2s = exp(seq(log(0.1),log(10),length.out=10))
  }


  d = ncol(X)
  U = subsample(rbind(X,X_new), s, models$subsample)
  res_knn = KNN(rbind(X,X_new), U[,1:d,drop=FALSE], r, output=TRUE, cl=cl)
  ind_knn = res_knn[[1]]
  distances_sp = res_knn[[2]]
  distance_mean = sum(distances_sp) / (n*r)
  i = rep(c(1:n),each=r); j = unlist(ind_knn)
  Z = distances_sp

  # initialize model
  best_model = list(a2=NA,t=NA, obj=-Inf, eigenpair=NULL)

  # Train model
  cat("Training...\n")
  for(a2 in a2s) {
    Z[cbind(i,j)] = exp(-distances_sp[cbind(i,j)]/(a2*distance_mean))
    if(models$gl=="cluster-normalized") {
      Z = graphLaplacian(Z, models$gl, U[,d+1])
    } else {
      Z = graphLaplacian(Z, models$gl)
    }
    eigenpair = spectrum_from_Z(Z, K, models$root)
    # empirical Bayes to optimize t
    cat("When epsilon =", sqrt(a2),": ")
    opt = train_lae_logit_gp(eigenpair, Y, c(1:m), K, sigma, N, approach)
    # update model parameters
    if(opt$obj>best_model$obj) {
      best_model$a2 = a2; best_model$t = opt$t; best_model$obj = opt$obj
      best_model$eigenpair = eigenpair
    }
  }

  cat("\nTraining over \n\n")
  cat("The optimal epsilon =",sqrt(best_model$a2),", t =", best_model$t,
      ", log", approach, "=",best_model$obj,".\n")

  # Test model
  cat("Testing...\n")
  # construct covariance matrix
  C = HK_from_spectrum(best_model$eigenpair, K, best_model$t, NULL, c(1:m))
  C[cbind(rep(1:m),rep(1:m))] = C[cbind(rep(1:m),rep(1:m))] + sigma
  Cvv = C[1:m,]
  Cnv = C[(m+1):n,]

  # predict labels on new samples
  Y_pred = test_pgbinary(as.matrix(Cvv), Y, as.matrix(Cnv), N)

  if(output_cov) {
    return(list(Y_pred=Y_pred, C=C))
  }
  cat("Testing over\n")

  return(Y_pred)
}
