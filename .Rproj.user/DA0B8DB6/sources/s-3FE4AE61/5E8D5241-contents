#include <Rcpp.h>
#include <Rinternals.h>
#include "test_class.h"
using namespace Rcpp;
using std::string;

test_class::test_class(const string& s1,
                       const string& s2,
                       const string& s3,
                       const string& s4,
                         const bool _bool1, const bool _bool2) :
  s1(s1),
  s2(s2),
  s3(s3),
  s4(s4),
  bool1(_bool1), bool2(_bool2) {};
SEXP test_class::getbools(){
    LogicalVector v = {this -> bool1 ? TRUE : FALSE,
                       this -> bool2 ? TRUE : FALSE};
    return Rcpp::wrap(v);
  }
