#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


/* Include Files */
#include "rt_nonfinite.h"
#include "MainRx_RT.h"
#include "main.h"
#include "MainRx_RT_terminate.h"
#include "MainRx_RT_initialize.h"

/* Function Declarations */
static void argInit_1x67500_real_T(double result[67500]);
static double argInit_real_T(void);
static void main_MainRx_RT(void);

/* Function Definitions */

/*
 * Arguments    : double result[67500]
 * Return Type  : void
 */
static void argInit_1x67500_real_T(double result[67500])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 67500; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_MainRx_RT(void)
{
  static double dv3[67500];
  rtString DataBitsVec;
  static double BitNumVec=27;

  argInit_1x67500_real_T(dv3);

    FILE *fp;
    int kk;
    int sz;

    int i=0;
    int c;
    int n = 0;
    char str[30];
    int dv_index=0;
//    string filename="OutputLs.txt";
//    char *filename="RxSig.csv";
    char *filename="rSig2.csv";
//    char delimiter=' ';
    char delimiter=',';
    fp = fopen(filename, "r");
    if(!fp){
        printf("bad file opnenig");
    }
    double tmp_val;
     while(  !feof(fp) ){
        c = (char)fgetc(fp);
        if(c==delimiter){
            str[n]=0;
            tmp_val=strtod(str,NULL);
            dv3[dv_index]=tmp_val;
            dv_index++;
            i++;
            n=0;
            str[0]=0;
        }
        else {
            str[n]=c;
            n++;
        }
    }
    fclose(fp);

//sz=sizeof(dv3)/sizeof(dv3[1]);
//printf("sz= %d \n\n",sz);

//    double zr[67500]={0,0};
//    double RxSig[202500]={0,0};
//    for(kk=67500;kk<135000;kk++){
//        RxSig[kk]=dv3[kk-67500];
//    }
//    //[zeros(1, Tnoise*Fs), Sig + randn(1, length(Sig))*NoiseStd, zeros(1, Tnoise*Fs)];

  MainRx_RT(dv3, BitNumVec, &DataBitsVec);
    //MainRx_RT(RxSig, DataBitsVec_data, DataBitsVec_size);
//    MainRx_RT(dv3, DataBitsVec_data, DataBitsVec_size);

  printf( "%s \n\n",DataBitsVec.Value.data);


}
#include <time.h>

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
  MainRx_RT_initialize();

   time_t seconds1;
   time_t seconds2;

clock_t clk1=clock();

    seconds1 = time(NULL);
 /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_MainRx_RT();

   seconds2 = time(NULL);

   int secdiff;
   secdiff=seconds2-seconds1;
   printf("runtime= %d \n",secdiff);
   printf("runtime (clock)= %d \n",clock()-clk1);

  /* Terminate the application.
     You do not need to do this more than one time. */
  MainRx_RT_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
