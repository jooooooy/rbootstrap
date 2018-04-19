#include <Rcpp.h>
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]
//' lse
//' The function returns the lease square estimate of model Y = X*beta + epsilon. 
//'
//' @author Jingyi Lin
//' @param X is the design matrix including the intercept
//' @param Y is the response variable
//' @return \code{lse}
//' @export
// [[Rcpp::export]]

Eigen::VectorXd lse(const Eigen::MatrixXd X, const Eigen::VectorXd Y){
  
  Eigen::VectorXd lse = (X.transpose() * X).inverse() * X.transpose() * Y;
  
  return(lse);
}



