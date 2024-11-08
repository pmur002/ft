\name{test}
\alias{test}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Test Function
}
\description{
Function to test calling FreeType C code.
}
\usage{
test(font, index)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{font}{
    Name of a font file.
  }
  \item{index}{
    Integer index of glyph.
  }
}
\value{
  Currently called just for printed side effect.
}
\references{
https://freetype.org/
}
\author{
Paul Murrell
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\examples{
test(system.file("fonts", "Montserrat-Medium.ttf", package="ft"), 0)
}
\keyword{ dplot }
