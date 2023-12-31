% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/test_pgmult.R
\name{test_pgmult}
\alias{test_pgmult}
\title{Predict multinomial probabilities on new samples}
\usage{
test_pgmult(C, Y, Cnv, N_sample = 100)
}
\arguments{
\item{C}{A numeric matrix with dim(m,m), the self covariance matrix
in the training samples.}

\item{Y}{A numeric matrix with dim(m,J), each row is a one hot vector indicating
the label.}

\item{Cnv}{A numeric matrix with dim(m_new,m), cross covariance matrix
between new sample and training sample.}

\item{N_sample}{An integer, the length of the Gibbs sampler chain.}
}
\value{
\code{pis_new} A numeric matrix with dim(m_new,J), each row indicates
the predictive multinomial probability in the corresponding new sample point.
}
\description{
Predict multinomial probabilities on new samples
}
\examples{
A <- matrix(rnorm(3*3),3,3)
C <- A\%*\%t(A)
Y <- matrix(sample.int(3*3 ,replace=TRUE),3,3)
Cnv <- matrix(rnorm(5*3),5,3)
test_pgmult(C, Y, Cnv, 100)
}
