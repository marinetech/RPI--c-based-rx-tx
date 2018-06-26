/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: MainRx_RT_types.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 12-Jun-2018 15:22:04
 */

#ifndef MAINRX_RT_TYPES_H
#define MAINRX_RT_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x1000
#define struct_emxArray_char_T_1x1000

struct emxArray_char_T_1x1000
{
  char data[1000];
  int size[2];
};

#endif                                 /*struct_emxArray_char_T_1x1000*/

#ifndef typedef_emxArray_char_T_1x1000
#define typedef_emxArray_char_T_1x1000

typedef struct emxArray_char_T_1x1000 emxArray_char_T_1x1000;

#endif                                 /*typedef_emxArray_char_T_1x1000*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T

struct emxArray_int8_T
{
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int8_T*/

#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T

typedef struct emxArray_int8_T emxArray_int8_T;

#endif                                 /*typedef_emxArray_int8_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_s9uEdhYwwSbx2BBD5TbfoCG_tag
#define struct_s9uEdhYwwSbx2BBD5TbfoCG_tag

struct s9uEdhYwwSbx2BBD5TbfoCG_tag
{
  emxArray_char_T_1x1000 Value;
};

#endif                                 /*struct_s9uEdhYwwSbx2BBD5TbfoCG_tag*/

#ifndef typedef_rtString
#define typedef_rtString

typedef struct s9uEdhYwwSbx2BBD5TbfoCG_tag rtString;

#endif                                 /*typedef_rtString*/
#endif

/*
 * File trailer for MainRx_RT_types.h
 *
 * [EOF]
 */
