/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: exp.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "exp.h"

/* Function Definitions */

/*
 * Arguments    : creal_T x[67500]
 * Return Type  : void
 */
void b_exp(creal_T x[67500])
{
  int k;
  double x_re;
  double r;
  for (k = 0; k < 67500; k++) {
    if (x[k].im == 0.0) {
      x_re = exp(x[k].re);
      r = 0.0;
    } else if (rtIsInf(x[k].im) && rtIsInf(x[k].re) && (x[k].re < 0.0)) {
      x_re = 0.0;
      r = 0.0;
    } else {
      r = exp(x[k].re / 2.0);
      x_re = r * (r * cos(x[k].im));
      r *= r * sin(x[k].im);
    }

    x[k].re = x_re;
    x[k].im = r;
  }
}

/*
 * File trailer for exp.c
 *
 * [EOF]
 */
