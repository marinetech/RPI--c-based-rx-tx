
/* Include Files */
#include "rt_nonfinite.h"
#include "MainTx_RT.h"
#include "main_smrt.h"

/* Function Declarations */
static void main_MainTx_RT(char cv0[27],char *filename);

/* Function Definitions */
 #include "stdio.h"
#include <string.h>

static void main_MainTx_RT(char cv0[27],char filename[50])
{
////  char cv0[27]="10110001";
//  char cv0[27]="101100111000111100001110001";
////  char cv0[27]="101010101010101010101010101";
  static double Sig[46384];

  MainTx_RT(cv0, Sig);

      int sz=sizeof(Sig)/sizeof(Sig[0]);
      int kk;
    FILE *fp;
//    fp = fopen("rSig2.csv", "w");
    fp = fopen(filename, "w");
      for(kk=0;kk<sz;kk++){
        fprintf(fp, "%f,",Sig[kk]);
      }
    fclose(fp);

}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, char * argv[])
{
//  (void)argc;
//  (void)argv;

if(argc < 2){
    printf("needed parameters:  tx_string  output_filename \n");
    return 0;
}
char msg[27]="";
   strcpy(msg, argv[1]);
printf("%s \n",msg);
char filename[50]="";
   strcpy(filename, argv[2]);
printf("%s \n",filename);
   main_MainTx_RT(msg,filename);
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
