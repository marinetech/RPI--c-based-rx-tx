/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 05-Jun-2018 15:47:02
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "main.h"
#include "MainTx_RT_terminate.h"
#include "MainTx_RT_initialize.h"

/* Function Declarations */
static void argInit_1x27_char_T(char result[27]);
static char argInit_char_T(void);
static void main_MainTx_RT(void);

/* Function Definitions */

/*
 * Arguments    : char result[27]
 * Return Type  : void
 */
static void argInit_1x27_char_T(char result[27])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 27; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : char
 */
static char argInit_char_T(void)
{
  return '?';
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_MainTx_RT(void)
{
  char cv0[27]='101100111000111100001';
  static double Sig[46384];

  /* Initialize function 'MainTx_RT' input arguments. */
  /* Initialize function input argument 'DataBits'. */
  /* Call the entry-point 'MainTx_RT'. */
  argInit_1x27_char_T(cv0);
  MainTx_RT(cv0, Sig);
  print(Sig);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  MainTx_RT_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_MainTx_RT();

  /* Terminate the application.
     You do not need to do this more than one time. */
  MainTx_RT_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
