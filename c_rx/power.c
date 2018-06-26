/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: power.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a[6750]
 *                double y[6750]
 * Return Type  : void
 */
void power(const double a[6750], double y[6750])
{
  int k;
  for (k = 0; k < 6750; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
