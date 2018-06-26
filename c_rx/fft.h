/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fft.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

#ifndef FFT_H
#define FFT_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "MainRx_RT_types.h"

/* Function Declarations */
extern void b_fft(const creal_T x[6750], creal_T y[65536]);
extern void fft(const creal_T x[33750], creal_T y[65536]);

#endif

/*
 * File trailer for fft.h
 *
 * [EOF]
 */
