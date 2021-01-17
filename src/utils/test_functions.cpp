#include "utils/test_function.h"

using namespace Rcpp;
namespace test_func{
namespace utils{
void print_values(std::string& x){
  Rcpp::Rcout << x << std::endl;
  return;
}

void print_values_2(std::string x){
  Rcpp::Rcout << x << std::endl;
  return;
}
}
}
