
# func as function
x <- createClass(rnorm, list(n = 3))
getrfunc(x)
gc()
getrfunc(x)
for(i in seq_len(1e6)){
  rnorm(100)
  stopifnot(identical(getrfunc(x),rnorm))
}

#func as string
x <- createClass("rnorm", list(n = 3))
getrfunc(x)
gc()
getrfunc(x)
for(i in seq_len(1e6)){
  rnorm(100)
  stopifnot(getrfunc(x) == 'rnorm')
}
rm(x)
gc()
