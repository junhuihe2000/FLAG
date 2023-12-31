% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/lae.R
\name{LAE}
\alias{LAE}
\title{Local anchor embedding}
\usage{
LAE(X, U, r = 3L, cl = NULL)
}
\arguments{
\item{X}{A numeric matrix with dim (n,d), original sample,
each row indicates one original point in R^d.}

\item{U}{A numeric matrix with dim (s,d) or (s,d+1), sub-sample,
each row indicates one representative point in R^d,
where the d+1 column indicates the number of points in each cluster if it exists.}

\item{r}{An integer, the number of the nearest neighbor points.}

\item{cl}{The cluster to make parallel computing,
typically generated by \code{parallel::makeCluster(num_workers)}.
The defaulting value of cl is NULL, that is, sequential computing.}
}
\value{
A numeric 'sparse' matrix with dim (n,s) and n*r non-zero entries, r << s,
the stochastic transition matrix from X to U.
}
\description{
Local anchor embedding
}
\examples{
X <- matrix(rnorm(10*3),10,3)
r <- 3
U <- matrix(rnorm(5*3),5,3)
LAE(X, U, r)
}
