/*
 * Code generation for system system '<Root>/Channel2'
 * For more details, see corresponding source file PhysicalLayerModel_Channel2.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModel_Channel2_h_
#define RTW_HEADER_PhysicalLayerModel_Channel2_h_
#ifndef PhysicalLayerModel_COMMON_INCLUDES_
# define PhysicalLayerModel_COMMON_INCLUDES_
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* PhysicalLayerModel_COMMON_INCLUDES_ */

#include "PhysicalLayerModel_types.h"

/* Block signals for system '<Root>/Channel2' */
typedef struct {
  creal_T InterfererTone[2112];        /* '<S13>/Interferer Tone ' */
  real_T ComplextoRealImag[2112];      /* '<S13>/Complex to Real-Imag' */
  real_T MathFunction[2112];           /* '<S13>/Math Function' */
  real_T Gain[2112];                   /* '<S13>/Gain' */
  real_T MatrixConcatenation[4224];    /* '<S14>/Matrix Concatenation' */
  real_T Add1[2112];                   /* '<S2>/Add1' */
  real_T RandomSource[2112];           /* '<S12>/Random Source' */
  real_T DynamicAWGN[2112];            /* '<S12>/Dynamic AWGN' */
} B_Channel2_PhysicalLayerModel_T;

/* Block states (auto storage) for system '<Root>/Channel2' */
typedef struct {
  real_T InterfererTone_AccFreqNorm;   /* '<S13>/Interferer Tone ' */
  real_T STDDEV;                       /* '<S12>/Dynamic AWGN' */
  uint32_T RandomSource_SEED_DWORK;    /* '<S12>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[2];/* '<S12>/Random Source' */
} DW_Channel2_PhysicalLayerMode_T;

/* Parameters for system: '<Root>/Channel2' */
struct P_Channel2_PhysicalLayerModel_T_ {
  real_T InterfererTone_Amplitude;     /* Expression: Amplitude
                                        * Referenced by: '<S13>/Interferer Tone '
                                        */
  real_T InterfererTone_Frequency;     /* Expression: Frequency
                                        * Referenced by: '<S13>/Interferer Tone '
                                        */
  real_T InterfererTone_Phase;         /* Expression: Phase
                                        * Referenced by: '<S13>/Interferer Tone '
                                        */
  real_T Constant_Value;               /* Expression: 3
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: .25
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T RandomSource_MeanRTP;         /* Expression: MeanVal
                                        * Referenced by: '<S12>/Random Source'
                                        */
  real_T RandomSource_VarianceRTP;     /* Computed Parameter: RandomSource_VarianceRTP
                                        * Referenced by: '<S12>/Random Source'
                                        */
  real_T DynamicAWGN_SNR;              /* Expression: SNRdB
                                        * Referenced by: '<S12>/Dynamic AWGN'
                                        */
  real_T DynamicAWGN_SPOW;             /* Expression: Ps
                                        * Referenced by: '<S12>/Dynamic AWGN'
                                        */
  uint32_T RandomSource_InitSeed;      /* Computed Parameter: RandomSource_InitSeed
                                        * Referenced by: '<S12>/Random Source'
                                        */
  uint32_T DynamicAWGN_Seed;           /* Computed Parameter: DynamicAWGN_Seed
                                        * Referenced by: '<S12>/Dynamic AWGN'
                                        */
};

void PhysicalLayerMode_Channel2_Init(DW_Channel2_PhysicalLayerMode_T *localDW,
  P_Channel2_PhysicalLayerModel_T *localP);
void PhysicalLayerMod_Channel2_Start(DW_Channel2_PhysicalLayerMode_T *localDW,
  P_Channel2_PhysicalLayerModel_T *localP);
void PhysicalLayerModel_Channel2(const real_T rtu_ChannelIn[2112],
  B_Channel2_PhysicalLayerModel_T *localB, DW_Channel2_PhysicalLayerMode_T
  *localDW, P_Channel2_PhysicalLayerModel_T *localP);

#endif                                 /* RTW_HEADER_PhysicalLayerModel_Channel2_h_ */
