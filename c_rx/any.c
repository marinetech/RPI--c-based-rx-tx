/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: any.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "any.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : boolean_T
 */
boolean_T any(const emxArray_real_T *x)
{
  boolean_T y;
  int ix;
  boolean_T exitg1;
  y = false;
  ix = 0;
  exitg1 = false;
  while ((!exitg1) && (ix + 1 <= x->size[1])) {
    if ((x->data[ix] == 0.0) || rtIsNaN(x->data[ix])) {
      ix++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  return y;
}

/*
 * File trailer for any.c
 *
 * [EOF]
 */
