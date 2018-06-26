/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: fft1.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

#ifndef FFT1_H
#define FFT1_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "MainRx_RT_types.h"

/* Function Declarations */
extern void b_generate_twiddle_tables(double costab[32769], double sintab[32769]);
extern void c_fft(const emxArray_creal_T *x, int n, emxArray_creal_T *y);
extern void generate_twiddle_tables(double costab[32769], double sintab[32769]);

#endif

/*
 * File trailer for fft1.h
 *
 * [EOF]
 */
