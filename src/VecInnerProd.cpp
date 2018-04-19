#include <Rcpp.h>
#include <RcppEigen.h>


// [[Rcpp::depends(RcppEigen)]]
//' VecInnerProd
//' The function returns the inner product of two vector z = x.T*y. 
//'
//' @author Jingyi Lin
//' @param X is a vector
//' @param Y is a vector
//' @return \code{z}
//' @export
// [[Rcpp::export]]

Eigen::VectorXd VecInnerProd(const Eigen::VectorXd x, const Eigen::VectorXd y){
  
  Eigen::VectorXd z=x.transpose()*y;
  
  return(z);
}



