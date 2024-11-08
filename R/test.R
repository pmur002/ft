
test <- function(font, index) {
    result <- .Call("C_test", as.character(font)[1], as.integer(index)[1])
    names(result) <- c("unitsPerEm", "width", "left", "right", "top", "bottom")
    result
}
