% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/predict.R
\name{collapsed_predict}
\alias{collapsed_predict}
\title{Predict multinomial probability given omega}
\usage{
collapsed_predict(aug_data = AugmentedData(), Cnv)
}
\arguments{
\item{aug_data}{An augmented data for polya-gamma sampling.}

\item{Cnv}{A numeric matrix with dim(m_new,m), cross covariance matrix
between new sample and training sample.}
}
\value{
\code{pis_new} a numeric matrix with dim(m_new, J), each row indicates
the predictive multinomial probability in the corresponding new sample point.
}
\description{
Predict the multinomial probability vector at Cnv
by first integrating out the value of f, given
omega and the kernel parameters.
}
\examples{
A <- matrix(rnorm(3*3),3,3)
C <- A\%*\%t(A)
Y <- matrix(sample.int(3*3 ,replace=TRUE),3,3)
aug_data <- AugmentedData(C,Y)
Cnv <- matrix(rnorm(5*3),5,3)
collapsed_predict(aug_data, Cnv)
}
