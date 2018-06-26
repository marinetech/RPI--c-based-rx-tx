/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainTx_RT_initialize.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Jun-2018 15:47:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "MainTx_RT_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void MainTx_RT_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for MainTx_RT_initialize.c
 *
 * [EOF]
 */
