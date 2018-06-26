/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[6750]
 * Return Type  : double
 */
double sum(const double x[6750])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 6749; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
