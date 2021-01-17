
#' print some values
#'
#' @param x single value to be printed
#'
#' @return NULL (invisible)
#'
#' @export
print_values <- function(x){
  if(missing(x))
    stop("missing x")
  .Call("_test_package_print_values", x)
  invisible()
}

#' Print hello world
#'
#' @return NULL (invisible)
#'
#' @export
hello_world <- function(){
  .Call("_test_package_rcpp_hello_world")
}

#' create class
#' @description creates a class
#'
#' @param bool1 x1
#' @param bool2 x2
#'
#' @return pointer
#'
#' @export
createClass <- function(s1, s2, s3, s4, bool1, bool2)
  .Call("_createClass", s1, s2, s3, s4, bool1, bool2)

#' extract bools
#'
#' @returns vector of bools from pointer.
getbools <- function(ptr)
  .Call("_getbools", ptr)
