/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ConvertToBBVer0.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "ConvertToBBVer0.h"
#include "filter.h"
#include "exp.h"

/* Function Definitions */

/*
 * function[ SignalBB, FiltMem, NextPhase, FiltMemDec ] = ConvertToBBVer0( ...
 *                                             Signal, Fcarrier, Fs, Factor,...
 *                                             FiltCoeff, FiltMem, Phase)
 *
 *  Description:
 *            This function convert a crossband signal to a baseband signal.
 *
 *  inputs:
 *            Signal      - The signal to be converted.
 *            Fcarrier    - carrier frequency of the sent signal.
 *            Fs          - sampling frequency.
 *            Factor      - Decimation Factor.
 *            FiltMem     - Filter memory vector of length(FiltCoeff)-1...
 *                          if zero - there is no memory from the last time.
 *            Phase       - carrier phase from the last call of the function.
 *            FiltCoeff   - The LPF coefficients.
 *
 *  Output:
 *            SignalBB    - The signal in base band. In the first call of the
 *                          function, it has a delay of length(FiltCoeff)/2 samples
 *            FiltMem     - Filter memory for the next call.
 *            NextPhase   - Carrier phase to the next call of the function.
 *            FiltMemDec  - Filter memory after decimation - Concatenate it to ...
 *                                 'SignalBB' in the last call of the function.
 * Arguments    : const double Signal[67500]
 *                const double FiltCoeff[129]
 *                creal_T SignalBB[33750]
 * Return Type  : void
 */
void ConvertToBBVer0(const double Signal[67500], const double FiltCoeff[129],
                     creal_T SignalBB[33750])
{
  static double time[67500];
  int k;
  double kd;
  static creal_T b_SignalBB[67500];
  static creal_T b_Signal[67500];
  creal_T FiltMem[128];

  /*  Set default values. */
  /*  The signal length. */
  /*  Warning message. */
  time[0] = 0.0;
  time[67499] = 0.9999851851851852;
  for (k = 0; k < 33748; k++) {
    kd = ((double)k + 1.0) * 1.4814814814814815E-5;
    time[k + 1] = kd;
    time[67498 - k] = 0.9999851851851852 - kd;
  }

  time[33749] = 0.4999851851851852;
  time[33750] = 0.5;

  /*  Time vector. */
  /*  Calculate the NextPhase. */
  /*  Shift the signal to BaseBand. */
  /*  Filtering and resampling the baseband signal. */
  for (k = 0; k < 67500; k++) {
    b_SignalBB[k].re = 0.0;
    b_SignalBB[k].im = -(75398.223686155034 * time[k]);
  }

  b_exp(b_SignalBB);
  for (k = 0; k < 67500; k++) {
    b_Signal[k].re = Signal[k] * b_SignalBB[k].re;
    b_Signal[k].im = Signal[k] * b_SignalBB[k].im;
  }
//    FILE *fp;
//    int kk;
//    int sz;
//  sz=sizeof(b_SignalBB)/sizeof(b_SignalBB[1]);
//  fp = fopen("b_SignalBB_re.csv", "w");// "w" means that we are going to write on this file
//  for(kk=0;kk<sz;kk++){
//    fprintf(fp, "%f,",b_SignalBB[kk].re);
//  }
//  fclose(fp);
//  fp = fopen("b_SignalBB_im.csv", "w");// "w" means that we are going to write on this file
//  for(kk=0;kk<sz;kk++){
//    fprintf(fp, "%f,",b_SignalBB[kk].im);
//  }
//  fclose(fp);

  filter(FiltCoeff, b_Signal, b_SignalBB, FiltMem);
  for (k = 0; k < 33750; k++) {
    SignalBB[k] = b_SignalBB[k << 1];
  }


//  sz=sizeof(b_SignalBB)/sizeof(b_SignalBB[1]);
//  fp = fopen("after_filter_b_SignalBB_re.csv", "w");// "w" means that we are going to write on this file
//  for(kk=0;kk<sz;kk++){
//    fprintf(fp, "%f,",b_SignalBB[kk].re);
//  }
//  fclose(fp);
//  fp = fopen("after_filter_b_SignalBB_im.csv", "w");// "w" means that we are going to write on this file
//  for(kk=0;kk<sz;kk++){
//    fprintf(fp, "%f,",b_SignalBB[kk].im);
//  }
//  fclose(fp);

  /*  Decimation. */
  /*  Decimation. */
  /*  Convert to row vector. */
  /*  Convert to row vector. */
}

/*
 * File trailer for ConvertToBBVer0.c
 *
 * [EOF]
 */
