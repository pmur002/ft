
#include <R_ext/Visibility.h>
#include <R_ext/Rdynload.h>
#include "test.h"

static const R_CallMethodDef callMethods[] = {
    {"test", (DL_FUNC) &test, 2},
    { NULL, NULL, 0 }
};

void R_init_ft(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
}
