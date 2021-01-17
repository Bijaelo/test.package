
#include "test_class.h"
using namespace Rcpp;
using std::string;
using cmdline_arguments::utils::coerce::cmd_do_docall;
/*test_class::test_class(SEXP _func, SEXP args, SEXP env) : func(_func){
  PROTECT(this -> res = cmd_do_docall(_func, args, as<Environment>(env), "no name"));
};*/
/*
test_class::test_class(SEXP _func, SEXP args, SEXP env) : func(_func){
  this -> res = cmd_do_docall(_func, args, as<Environment>(env), "no name");
};*/
/*
test_class::test_class(SEXP _func, SEXP args, SEXP env) : func(Rf_shallow_duplicate(_func)){
  this -> res = cmd_do_docall(_func, args, as<Environment>(env), "no name");
};*/
test_class::test_class(SEXP _func, SEXP args, SEXP env) : func(Rf_duplicate(_func)){
  this -> res = cmd_do_docall(_func, args, as<Environment>(env), "no name");
};
/*test_class::~test_class(){
  UNPROTECT(1);
}*/
SEXP test_class::getres(){
  return wrap(this -> res);
}
SEXP test_class::getfunc(){
  return wrap(this -> func);
}
