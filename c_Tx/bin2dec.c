/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bin2dec.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Jun-2018 15:47:02
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "bin2dec.h"

/* Function Definitions */

/*
 * Arguments    : const char s_data[]
 *                const int s_size[2]
 * Return Type  : double
 */
double bin2dec(const char s_data[], const int s_size[2])
{
  double x;
  double p2;
  int i4;
  int j;
  int b_j;
  x = 0.0;
  p2 = 1.0;
  i4 = (int)((1.0 + (-1.0 - (double)s_size[1])) / -1.0);
  for (j = 1; j - 1 < i4; j++) {
    b_j = s_size[1] - j;
    if (s_data[s_size[0] * b_j] != ' ') {
      if (s_data[s_size[0] * b_j] == '1') {
        x += p2;
      }

      p2 += p2;
    }
  }

  return x;
}

/*
 * File trailer for bin2dec.c
 *
 * [EOF]
 */
