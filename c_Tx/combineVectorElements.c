/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: combineVectorElements.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Jun-2018 15:47:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 * Arguments    : const double x[31590]
 * Return Type  : double
 */
double combineVectorElements(const double x[31590])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 31589; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * File trailer for combineVectorElements.c
 *
 * [EOF]
 */
