
test <- function(font, index) {
    .Call("C_test", as.character(font)[1], as.integer(index)[1])
}
