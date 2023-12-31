% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{subsample_cpp}
\alias{subsample_cpp}
\title{Subsample in the domain}
\usage{
subsample_cpp(X, s, method = "kmeans", nstart = 1L)
}
\arguments{
\item{X}{Original sample, a (n, d) matrix, each row indicates one point in R^d.}

\item{s}{An integer indicating the number of the subsampling.}

\item{method}{How to subsample, characters in c("kmeans", "random"),
including kmeans and random selection, the
defaulting subsampling method is kmeans.}
}
\value{
A subsampling, a (s, d) or (s, d+1) matrix, each row indicates one point in R^d,
where the d+1 column indicates the number of points in each cluster if it exists.
}
\description{
Subsample in the domain
}
\examples{
X <- matrix(rnorm(10*3), nrow=10, ncol=3)
s <- 3
U = subsample_cpp(X, s, method = "kmeans")
}
