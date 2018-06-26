/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "filter.h"

/* Function Definitions */

/*
 * Arguments    : const double b[129]
 *                const creal_T x[67500]
 *                creal_T y[67500]
 *                creal_T zf[128]
 * Return Type  : void
 */
void filter(const double b[129], const creal_T x[67500], creal_T y[67500],
            creal_T zf[128])
{
  int k;
  int j;
  for (k = 0; k < 128; k++) {
    zf[k].re = 0.0;
    zf[k].im = 0.0;
    y[k].re = 0.0;
    y[k].im = 0.0;
  }

  for (k = 0; k < 67372; k++) {
    y[k + 128].re = 0.0;
    y[k + 128].im = 0.0;
  }


  for (k = 0; k < 129; k++) {
    for (j = k; j + 1 < 67501; j++) {
      y[j].re += b[k] * x[j - k].re;
      y[j].im += b[k] * x[j - k].im;
    }
  }

  for (k = 0; k < 128; k++) {
    for (j = 0; j < k + 1; j++) {
      zf[j].re += x[k + 67372].re * b[(j - k) + 128];
      zf[j].im += x[k + 67372].im * b[(j - k) + 128];
    }
  }
}

/*
 * File trailer for filter.c
 *
 * [EOF]
 */
