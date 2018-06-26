/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: NormCorrVer0.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "NormCorrVer0.h"
#include "sqrt.h"
#include "sum.h"
#include "power.h"
#include "abs.h"
#include "ifft.h"
#include "fft.h"
#include "fliplr.h"
#include "MainRx_RT_rtwutil.h"

/* Function Definitions */

/*
 * function[Corr] = NormCorrVer0(Data,Ref, FftFlag, NormFlag ,StartIndx, StopIndx)
 *
 *   Description: This function perform normalized correlation between ...
 *                a refference signal and data signal. It can calculate the ...
 *                correlation output in time domain or frequency domain.
 *                It also can return normalized correlation.
 *
 *  Input parameters:
 *              Data - The data signal.
 *              Ref - The refference signal.
 *              FftFlag -  A flag determines whether to use time domain
 *                         implementation  or frequency domain implementation.
 *              NormFlag - A flag determines whether to normalize the correlation output
 *              StartIndx - Start index of the result relative to the case where
 *                          the result is of length = length(Data)+RefL - 1
 *              StopIndx - Stop index of the result relative to the case where
 *                          the result is of length = length(Data)+RefL - 1
 *
 *   Output parameters:
 *             Corr - The correlation result.
 * Arguments    : const creal_T Data[33750]
 *                const creal_T Ref[6750]
 *                creal_T Corr[33750]
 * Return Type  : void
 */
void NormCorrVer0(const creal_T Data[33750], const creal_T Ref[6750], creal_T
                  Corr[33750])
{
  double re;
  double im;
  int ind;
  creal_T K;
  static creal_T dcv2[65536];
  static creal_T dcv3[6750];
  static creal_T dcv4[6750];
  static creal_T dcv5[65536];
  static creal_T dcv6[65536];
  static creal_T b_Data[47249];
  double dv1[6750];
  double dv2[6750];
  double SumX2;
  double Corr_re;

  /*    Set default values to StartIndx and StopIndx */
  /*  Assure row vectors */
  re = 0.0;
  im = 0.0;
  for (ind = 0; ind < 6750; ind++) {
    re += Ref[ind].re * Ref[ind].re - Ref[ind].im * -Ref[ind].im;
    im += Ref[ind].re * -Ref[ind].im + Ref[ind].im * Ref[ind].re;
  }

  K.re = re;
  K.im = im;
  b_sqrt(&K);

  /*  power of the reference; */
  /*  The length of the reference */
  /*  The length of the data */
  /*  method 1 - fft implementation */
  /*  Padding to a power of 2 for the fft function */
  /*  Correlation in frequency domain */
  /*  figure;plot(abs(Corr)) */
  fft(Data, dcv2);
  memcpy(&dcv3[0], &Ref[0], 6750U * sizeof(creal_T));
  fliplr(dcv3);
  for (ind = 0; ind < 6750; ind++) {
    dcv4[ind].re = dcv3[ind].re;
    dcv4[ind].im = -dcv3[ind].im;
  }

  b_fft(dcv4, dcv5);
  for (ind = 0; ind < 65536; ind++) {
    dcv6[ind].re = dcv2[ind].re * dcv5[ind].re - dcv2[ind].im * dcv5[ind].im;
    dcv6[ind].im = dcv2[ind].re * dcv5[ind].im + dcv2[ind].im * dcv5[ind].re;
  }

  ifft(dcv6, dcv2);
  memcpy(&Corr[0], &dcv2[6749], 33750U * sizeof(creal_T));

  /*  cutting the fft implementation to the supposed length. */
  /*  Normalize the correlation */
  memset(&b_Data[0], 0, 6749U * sizeof(creal_T));
  memcpy(&b_Data[6749], &Data[0], 33750U * sizeof(creal_T));
  memset(&b_Data[40499], 0, 6750U * sizeof(creal_T));

  /*  zero padding to perform normalization */
  b_abs(*(creal_T (*)[6750])&b_Data[6749], dv1);
  power(dv1, dv2);
  SumX2 = sum(dv2);

  /*  the energy of each point */
  for (ind = 0; ind < 33750; ind++) {
    re = SumX2;
    c_sqrt(&re);
    if (Corr[ind].im == 0.0) {
      Corr[ind].re /= re;
      Corr[ind].im = 0.0;
    } else if (Corr[ind].re == 0.0) {
      Corr[ind].re = 0.0;
      Corr[ind].im /= re;
    } else {
      Corr[ind].re /= re;
      Corr[ind].im /= re;
    }

    re = rt_hypotd_snf(b_Data[ind + 13499].re, b_Data[ind + 13499].im);
    im = rt_hypotd_snf(b_Data[ind + 6749].re, b_Data[ind + 6749].im);
    SumX2 = (SumX2 + re * re) - im * im;
  }

  /*  Normalize the correlation */
  for (ind = 0; ind < 33750; ind++) {
    Corr_re = Corr[ind].re;
    if (K.im == 0.0) {
      if (Corr[ind].im == 0.0) {
        Corr[ind].re /= K.re;
        Corr[ind].im = 0.0;
      } else if (Corr[ind].re == 0.0) {
        Corr[ind].re = 0.0;
        Corr[ind].im /= K.re;
      } else {
        Corr[ind].re /= K.re;
        Corr[ind].im /= K.re;
      }
    } else if (K.re == 0.0) {
      if (Corr[ind].re == 0.0) {
        Corr[ind].re = Corr[ind].im / K.im;
        Corr[ind].im = 0.0;
      } else if (Corr[ind].im == 0.0) {
        Corr[ind].re = 0.0;
        Corr[ind].im = -(Corr_re / K.im);
      } else {
        Corr[ind].re = Corr[ind].im / K.im;
        Corr[ind].im = -(Corr_re / K.im);
      }
    } else {
      SumX2 = fabs(K.re);
      re = fabs(K.im);
      if (SumX2 > re) {
        re = K.im / K.re;
        im = K.re + re * K.im;
        Corr[ind].re = (Corr[ind].re + re * Corr[ind].im) / im;
        Corr[ind].im = (Corr[ind].im - re * Corr_re) / im;
      } else if (re == SumX2) {
        if (K.re > 0.0) {
          re = 0.5;
        } else {
          re = -0.5;
        }

        if (K.im > 0.0) {
          im = 0.5;
        } else {
          im = -0.5;
        }

        Corr[ind].re = (Corr[ind].re * re + Corr[ind].im * im) / SumX2;
        Corr[ind].im = (Corr[ind].im * re - Corr_re * im) / SumX2;
      } else {
        re = K.re / K.im;
        im = K.im + re * K.re;
        Corr[ind].re = (re * Corr[ind].re + Corr[ind].im) / im;
        Corr[ind].im = (re * Corr[ind].im - Corr_re) / im;
      }
    }
  }
}

/*
 * File trailer for NormCorrVer0.c
 *
 * [EOF]
 */
