

#' create class
#' @description creates a class
#'
#' @param bool1 x1
#' @param bool2 x2
#'
#' @return pointer
#'
#' @export
createClass <- function(func, args = list(), env = new.env())
  .Call("_createClass", func, args, env)

#' extract bools
#'
#' @returns vector of bools from pointer.
getres <- function(ptr)
  .Call("_getres", ptr)
