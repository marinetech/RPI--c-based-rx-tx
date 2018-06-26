/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: std.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Jun-2018 15:47:02
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "std.h"
#include "xnrm2.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 * Arguments    : const double x[31590]
 * Return Type  : double
 */
double b_std(const double x[31590])
{
  double xbar;
  int k;
  static double absdiff[31590];
  xbar = combineVectorElements(x) / 31590.0;
  for (k = 0; k < 31590; k++) {
    absdiff[k] = fabs(x[k] - xbar);
  }

  return xnrm2(absdiff) / 177.73294573601149;
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
