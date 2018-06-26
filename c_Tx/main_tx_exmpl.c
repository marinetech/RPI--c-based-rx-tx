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

/* Function Declarations */
static void main_MainTx_RT(void);

/* Function Definitions */
 #include "stdio.h"

static void main_MainTx_RT(void)
{
//  char cv0[27]="10110001";
  char cv0[27]="101100111000111100001110001";
//  char cv0[27]="101010101010101010101010101";
  static double Sig[46384];

  MainTx_RT(cv0, Sig);

//      int sz=sizeof(Sig)/sizeof(Sig[0]);
//      int kk;
//      for(kk=0;kk<sz;kk++){
//        printf("%f ,",Sig[kk]);
////        printf("%d ,",kk);
//      }
//      printf("\n");


    FILE *fp;
    fp = fopen("OutputLs.txt", "w");// "w" means that we are going to write on this file
      for(kk=0;kk<sz;kk++){
        fprintf(fp, "%f ",Sig[kk]);
      }
    fclose(fp);

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

   main_MainTx_RT();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
