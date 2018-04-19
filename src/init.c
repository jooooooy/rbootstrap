#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP _rbootstrap_lse(SEXP, SEXP);
extern SEXP _rbootstrap_model_predict(SEXP, SEXP, SEXP);
extern SEXP _rbootstrap_rcppeigen_bothproducts(SEXP);
extern SEXP _rbootstrap_rcppeigen_hello_world();
extern SEXP _rbootstrap_rcppeigen_innerproduct(SEXP);
extern SEXP _rbootstrap_rcppeigen_outerproduct(SEXP);
extern SEXP _rbootstrap_VecInnerProd(SEXP, SEXP);
extern SEXP _rbootstrap_VecSum(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_rbootstrap_lse",                    (DL_FUNC) &_rbootstrap_lse,                    2},
    {"_rbootstrap_model_predict",          (DL_FUNC) &_rbootstrap_model_predict,          3},
    {"_rbootstrap_rcppeigen_bothproducts", (DL_FUNC) &_rbootstrap_rcppeigen_bothproducts, 1},
    {"_rbootstrap_rcppeigen_hello_world",  (DL_FUNC) &_rbootstrap_rcppeigen_hello_world,  0},
    {"_rbootstrap_rcppeigen_innerproduct", (DL_FUNC) &_rbootstrap_rcppeigen_innerproduct, 1},
    {"_rbootstrap_rcppeigen_outerproduct", (DL_FUNC) &_rbootstrap_rcppeigen_outerproduct, 1},
    {"_rbootstrap_VecInnerProd",           (DL_FUNC) &_rbootstrap_VecInnerProd,           2},
    {"_rbootstrap_VecSum",                 (DL_FUNC) &_rbootstrap_VecSum,                 2},
    {NULL, NULL, 0}
};

void R_init_rbootstrap(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}