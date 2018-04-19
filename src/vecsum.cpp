#include <Rcpp.h>
#include <RcppEigen.h>


// [[Rcpp::depends(RcppEigen)]]
//' VecSum
//' The function returns the sum of two vector z = x+y. 
//'
//' @author Jingyi Lin
//' @param X is a vector
//' @param Y is a vector
//' @return \code{z}
//' @export
// [[Rcpp::export]]

Eigen::VectorXd VecSum(const Eigen::VectorXd x, const Eigen::VectorXd y){
  
  Eigen::VectorXd z=x+y;
  
  return(z);
}



