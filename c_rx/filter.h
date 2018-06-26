/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: filter.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

#ifndef FILTER_H
#define FILTER_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "MainRx_RT_types.h"

/* Function Declarations */
extern void filter(const double b[129], const creal_T x[67500], creal_T y[67500],
                   creal_T zf[128]);

#endif

/*
 * File trailer for filter.h
 *
 * [EOF]
 */
