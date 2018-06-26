/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "abs.h"
#include "MainRx_RT_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : const creal_T x[6750]
 *                double y[6750]
 * Return Type  : void
 */
void b_abs(const creal_T x[6750], double y[6750])
{
  int k;
  for (k = 0; k < 6750; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

/*
 * Arguments    : const creal_T x[33750]
 *                double y[33750]
 * Return Type  : void
 */
void c_abs(const creal_T x[33750], double y[33750])
{
  int k;
  for (k = 0; k < 33750; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
