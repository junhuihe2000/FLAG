#' Fit Gaussian process logistic regression with Nystrom extension
#'
#' @param X Training sample, a (m, d) matrix, each row indicates one point in R^d.
#' @param Y A numeric vector with length(m), count of the positive class.
#' @param X_new Testing sample, a (n-m, d) matrix, each row indicates one point in R^d.
#' @param s An integer indicating the number of the subsampling.
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
#' s <- 6
#' K <- 5
#' Y_pred <- fit_nystrom_logit_gp_r(X, Y, X_new, s, K)
fit_nystrom_logit_gp_r <- function(X, Y, X_new, s, K=NULL, N=NULL, sigma=1e-3, a2s=NULL,
                                 approach ="posterior", cl=NULL,
                                 models=list(subsample="kmeans",
                                             kernel="se",
                                             gl="rw",
                                             root=FALSE),
                                 output_cov=FALSE) {
  cat("Nystrom extension:\n")

  m = nrow(X); m_new = nrow(X_new); n = m + m_new;
  X_all = rbind(X,X_new)

  if(is.null(K)) {
    K = s
  }

  if(is.null(a2s)) {
    a2s = exp(seq(log(0.1),log(10),length.out=10))
  }

  d = ncol(X)
  U = subsample(X_all, s, models$subsample)[,1:d,drop=FALSE]
  distances_U = rowSums(U^2)-2*U%*%t(U) + matrix(rowSums(U^2), s, nrow(U), byrow = TRUE)
  distances_XU = rowSums(X^2)-2*X%*%t(U) + matrix(rowSums(U^2), m, nrow(U), byrow = TRUE)
  distances_allU = rowSums(X_all^2)-2*X_all%*%t(U) + matrix(rowSums(U^2), n, nrow(U), byrow = TRUE)
  distances_mean = mean(distances_U)

  # initialize model
  best_model = list(a2=NA,t=NA, obj=-Inf, eigenpair=NULL, Z=NULL)

  # Train model
  cat("Training...\n")
  for(a2 in a2s) {
    Z = exp(-distances_U/(a2*distances_mean))

    A = Matrix::dimScale(Z, 1/(Matrix::rowSums(Z)+1e-5))
    D = Matrix::rowSums(A)
    W = Matrix::dimScale(A, 1/sqrt(D+1e-5))
    eigenpair_U = RSpectra::eigs_sym(W,K)
    eigenpair_U$vectors = sqrt(s)*Matrix::rowScale(eigenpair_U$vectors, 1/sqrt(D+1e-5))

    # Nystrom extension formula
    Z_XU = exp(-distances_XU/(a2*distances_mean))
    A_XU = Matrix::rowScale(Z_XU, 1/(Matrix::rowSums(Z_XU)+1e-5))
    A_XU = Matrix::colScale(A_XU, 1/(Matrix::colSums(Z)+1e-5))
    W_XU = Matrix::rowScale(A_XU, 1/Matrix::rowSums(A_XU+1e-5))
    eigenpair = eigenpair_U
    eigenpair$vectors = W_XU%*%Matrix::colScale(eigenpair$vectors, 1/eigenpair$values)

    # empirical Bayes to optimize t
    cat("When epsilon =", sqrt(a2),": ")
    opt = train_lae_logit_gp(eigenpair, Y, c(1:m), K, sigma, N, approach)
    # update model parameters
    if(opt$obj>best_model$obj) {
      best_model$a2 = a2; best_model$t = opt$t; best_model$obj = opt$obj
      best_model$eigenpair = eigenpair_U; best_model$Z = Z
    }
  }


  cat("\nTraining over \n\n")
  cat("The optimal epsilon =",sqrt(best_model$a2),", t =", best_model$t,
      ", log", approach, "=",best_model$obj,".\n")

  # Test model
  cat("Testing...\n")
  # Nystrom extension
  Z_allU = exp(-distances_allU/(best_model$a2*distances_mean))
  A_allU = Matrix::rowScale(Z_allU, 1/Matrix::rowSums(Z_allU))
  A_allU = Matrix::colScale(A_allU, 1/Matrix::colSums(best_model$Z))
  W_allU = Matrix::rowScale(A_allU, 1/Matrix::rowSums(A_allU))
  best_model$eigenpair$vectors = W_allU%*%Matrix::colScale(best_model$eigenpair$vectors, 1/best_model$eigenpair$values)
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
