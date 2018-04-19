#include <Rcpp.h>
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
Rcpp::List model_predict(const Eigen::VectorXd Y, const Eigen::MatrixXd X, 
                     const Eigen::VectorXd x_new) {
  
  /* Getting ready for boostrap resampling */
  int n = X.rows();
  
  Eigen::VectorXd beta_hat = (X.transpose() * X).inverse() * X.transpose() * Y;
  Eigen::VectorXd Y_hat    = X * beta_hat;
  Eigen::VectorXd y_new_hat= beta_hat.transpose() * x_new ;
  Eigen::MatrixXd mat_hat  = X * (X.transpose() * X).inverse() * X.transpose();
  
  Eigen::VectorXd h        = mat_hat.diagonal();
  Eigen::VectorXd raw_err  = Y - Y_hat;
  Eigen::VectorXd mod_err(n);
  for (int i = 0; i < n; i++){
    mod_err[i] = raw_err[i]/std::sqrt(1-h[i]);
    }
  Eigen::VectorXd onevec(n);
  onevec.fill(1);
  Eigen::MatrixXd mean = mod_err.transpose() * onevec ;
  Eigen::VectorXd cen_err = mod_err - onevec * mean/n;
  
  
  return Rcpp::List::create(Rcpp::Named("beta_hat") = beta_hat,
                            Rcpp::Named("Y_hat") = Y_hat,
                            Rcpp::Named("y_new_hat") = y_new_hat,
                            Rcpp::Named("cen_err") = cen_err);
}



 
