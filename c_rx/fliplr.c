/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fliplr.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "fliplr.h"

/* Function Definitions */

/*
 * Arguments    : creal_T x[6750]
 * Return Type  : void
 */
void fliplr(creal_T x[6750])
{
  int b_j1;
  double xtmp_re;
  double xtmp_im;
  for (b_j1 = 0; b_j1 < 3375; b_j1++) {
    xtmp_re = x[b_j1].re;
    xtmp_im = x[b_j1].im;
    x[b_j1] = x[6749 - b_j1];
    x[6749 - b_j1].re = xtmp_re;
    x[6749 - b_j1].im = xtmp_im;
  }
}

/*
 * File trailer for fliplr.c
 *
 * [EOF]
 */
