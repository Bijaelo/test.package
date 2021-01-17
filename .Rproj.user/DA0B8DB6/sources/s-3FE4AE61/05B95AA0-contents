#include <Rcpp.h>
#include "utils/cmd_coerce.h"
#include "test_class.h"
using namespace Rcpp;


List rcpp_hello_world();
//void print_values(std::string& x);
//void print_values_2(std::string x);
List rcpp_hello_world_2();

typedef Rcpp::traits::input_parameter< std::string& >::type r_string;

extern "C" {

  SEXP _test_package_rcpp_hello_world() {
    BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpp_hello_world());
    return rcpp_result_gen;
    END_RCPP
  }

  // works as expected... why is the other version not working as expected!?
  SEXP createPtr(SEXP func = R_NilValue,
                 SEXP args = R_NilValue,
                 SEXP env = R_NilValue){
    Rcpp::XPtr<test_class> ptr(new test_class(func, args, env));
    return Rcpp::wrap(ptr);
  }
  SEXP getres(SEXP ptr){
    Rcpp::XPtr<test_class> _ptr(ptr);
    return _ptr -> getres();
  }

}
#include <R_ext/Rdynload.h>

#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}

// Create a list of pointers to be exported to R
static const R_CallMethodDef CallEntries[] = {
  {"_test_package_rcpp_hello_world", (DL_FUNC) &_test_package_rcpp_hello_world, 0},
  {"_createClass", (DL_FUNC) &createPtr, 3},
  {"_getres", (DL_FUNC) &getres, 1},
  /*
  {"_test_package_rcpp_hello_world_2", (DL_FUNC) &_test_package_rcpp_hello_world_2, 0},
  {"_test_package_print_values_2", (DL_FUNC) &_test_package_print_values_2, 1},
   */
  {NULL, NULL, 0}
};

// Register the pointers as Dynamic Symbols for R.
extern "C" void R_init_test_package(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, (Rboolean)FALSE);
};
