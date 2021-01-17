
#ifndef test_h
#define test_h

#include <string>
#include <Rcpp.h>
#include <Rinternals.h>
#include "utils/cmd_coerce.h"

class test_class{
private:
  SEXP func;
  //Rcpp::RObject res; <- works
  SEXP res; // Didn't work without PROTECT.
public:
  test_class(SEXP, SEXP, SEXP);
  SEXP getres();
  SEXP getfunc();
};

#endif
