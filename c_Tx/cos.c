/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cos.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Jun-2018 15:47:02
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "cos.h"

/* Function Definitions */

/*
 * Arguments    : double x[3375]
 * Return Type  : void
 */
void b_cos(double x[3375])
{
  int k;
  for (k = 0; k < 3375; k++) {
    x[k] = cos(x[k]);
  }
}

/*
 * File trailer for cos.c
 *
 * [EOF]
 */
