
# What is this branch about?
This branch (function_result_lifetime) is concerned about SEXP lifetime.
As part of the [cmdline.arguments](https://github.com/Bijaelo/cmdline.arguments) package the result of an R function call (performed from a C++ class) is to stored until the user requires the result. This is a simple procedure, performed by a call to [`do_docall`](https://github.com/wch/r-source/blob/b74babdd236b9c626f387d59ae5f5d1c965d9e68/src/main/coerce.c#L2659) in the internal API, to build and evaluate the function call. While it is commonly described that SEXP expessions needs to be protected (performed automatically by **Rcpp/protection/Shield.h** and subtypes in Rcpp) the result from [eval](https://github.com/wch/r-source/blob/b74babdd236b9c626f387d59ae5f5d1c965d9e68/src/main/eval.c#L641) is by itself not protected when returned. Common sense lets us expect that we have to "protect" the result, but one has to be certain this is true. One option would be to store the SEXP as a class similar to **Rcpp/protection/Shield.h**, but this requires a quick redefinition of the class to not have constant protection. The question is whether this would be accepted by the R-stack of an error about difference in protection level would occur.

This repository seeks to uncover these mysteries and find and answer as to how one should "correctly" store the result from a function call as SEXP. One important note is that this search is somewhat defunct, as we could simply cast the result to an `Rcpp::RObject` and store it as such. But this would come at the cost of some minor performance loss. So here I am trying to learn how to avoid this.


A quick few tests came to the following conclusions:

1. Storing the result of `do_docall` will not ensure it's safety. When the garbage collector is called it will be destroyed, but extracting using `Rcpp::wrap` is still safe. The result is meaningless however, as it is just a list of length 4 with all values equal to `NULL`. The 4 fields are named after the fields of an `SEXP`.
2. The result can safely e stored in an `Rcpp::RObject`, and will not be collected by the garbage collector
3. Using `PROTECT` even with a destructor will result in the warning **Warning: stack imbalance in '<-', 2 then 3** (numbers are irrelevant), but the object is safely stored. However the warning is quite clear, that it is not "that simple".

So for now I will use `Rcpp::RObject` and `Rcpp::wrap` while I would prefer to just store the result as a plain `SEXP`, this is going to take a bit more research than I am willing to do right now.

