#include <Rcpp.h>
#include "utils/test_function.h"
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

  SEXP _test_package_print_values(SEXP xSEXP) {
    BEGIN_RCPP
    //Rcpp::traits::input_parameter< std::string& >::type x(xSEXP);
    test_func::utils::print_values(Rcpp::as<r_string>(xSEXP));
    return R_NilValue;
    END_RCPP
  }
  // works as expected... why is the other version not working as expected!?
  SEXP createPtr(SEXP s1 = R_NilValue,
                 SEXP s2 = R_NilValue,
                 SEXP s3 = R_NilValue,
                 SEXP s4 = R_NilValue,
                 SEXP _bool1 = R_NilValue,
                 SEXP _bool2 = R_NilValue){
    Rcpp::XPtr<test_class> ptr(new test_class(as<std::string>(s1),
                                              as<std::string>(s2),
                                              as<std::string>(s3),
                                              as<std::string>(s4),
                                              Rf_asLogical(_bool1) != 0,
                                              Rf_asLogical(_bool2) != 0));
    return Rcpp::wrap(ptr);
  }
  SEXP getbools(SEXP ptr){
    Rcpp::XPtr<test_class> _ptr(ptr);
    return _ptr -> getbools();
  }

}
#include <R_ext/Rdynload.h>

#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}

// Create a list of pointers to be exported to R
static const R_CallMethodDef CallEntries[] = {
  {"_test_package_rcpp_hello_world", (DL_FUNC) &_test_package_rcpp_hello_world, 0},
  {"_test_package_print_values", (DL_FUNC) &_test_package_print_values, 1},
  {"_createClass", (DL_FUNC) &createPtr, 6},
  {"_getbools", (DL_FUNC) &getbools, 1},
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
