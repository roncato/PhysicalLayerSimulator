/*
 * Code generation for system system '<Root>/Channel1'
 * For more details, see corresponding source file PhysicalLayerModel_Channel1.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModel_Channel1_h_
#define RTW_HEADER_PhysicalLayerModel_Channel1_h_
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

/* Block signals for system '<Root>/Channel1' */
typedef struct {
  creal_T InterfererTone[2112];        /* '<S10>/Interferer Tone ' */
  real_T ComplextoRealImag[2112];      /* '<S10>/Complex to Real-Imag' */
  real_T MathFunction[2112];           /* '<S10>/Math Function' */
  real_T Gain[2112];                   /* '<S10>/Gain' */
  real_T MatrixConcatenation[4224];    /* '<S11>/Matrix Concatenation' */
  real_T Add1[2112];                   /* '<S1>/Add1' */
  real_T RandomSource[2112];           /* '<S9>/Random Source' */
  real_T DynamicAWGN[2112];            /* '<S9>/Dynamic AWGN' */
} B_Channel_PhysicalLayerModel_T;

/* Block states (auto storage) for system '<Root>/Channel1' */
typedef struct {
  real_T InterfererTone_AccFreqNorm;   /* '<S10>/Interferer Tone ' */
  real_T STDDEV;                       /* '<S9>/Dynamic AWGN' */
  uint32_T RandomSource_SEED_DWORK;    /* '<S9>/Random Source' */
  uint32_T RandomSource_STATE_DWORK[2];/* '<S9>/Random Source' */
} DW_Channel_PhysicalLayerMode_T;

/* Parameters for system: '<Root>/Channel1' */
struct P_Channel_PhysicalLayerModel_T_ {
  real_T InterfererTone_Amplitude;     /* Expression: Amplitude
                                        * Referenced by: '<S10>/Interferer Tone '
                                        */
  real_T InterfererTone_Frequency;     /* Expression: Frequency
                                        * Referenced by: '<S10>/Interferer Tone '
                                        */
  real_T InterfererTone_Phase;         /* Expression: Phase
                                        * Referenced by: '<S10>/Interferer Tone '
                                        */
  real_T Constant_Value;               /* Expression: 3
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: .25
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T RandomSource_MeanRTP;         /* Expression: MeanVal
                                        * Referenced by: '<S9>/Random Source'
                                        */
  real_T RandomSource_VarianceRTP;     /* Computed Parameter: RandomSource_VarianceRTP
                                        * Referenced by: '<S9>/Random Source'
                                        */
  real_T DynamicAWGN_SNR;              /* Expression: SNRdB
                                        * Referenced by: '<S9>/Dynamic AWGN'
                                        */
  real_T DynamicAWGN_SPOW;             /* Expression: Ps
                                        * Referenced by: '<S9>/Dynamic AWGN'
                                        */
  uint32_T RandomSource_InitSeed;      /* Computed Parameter: RandomSource_InitSeed
                                        * Referenced by: '<S9>/Random Source'
                                        */
  uint32_T DynamicAWGN_Seed;           /* Computed Parameter: DynamicAWGN_Seed
                                        * Referenced by: '<S9>/Dynamic AWGN'
                                        */
  real_T Bandwidth;
};

void PhysicalLayerMode_Channel_Init(DW_Channel_PhysicalLayerMode_T *localDW,
  P_Channel_PhysicalLayerModel_T *localP);
void PhysicalLayerMod_Channel_Start(DW_Channel_PhysicalLayerMode_T *localDW,
  P_Channel_PhysicalLayerModel_T *localP);
void PhysicalLayerModel_Channel(const real_T rtu_ChannelIn[2112],
  B_Channel_PhysicalLayerModel_T *localB, DW_Channel_PhysicalLayerMode_T
  *localDW, P_Channel_PhysicalLayerModel_T *localP);
real_T rt_powd_snf(real_T u0, real_T u1);
#endif                                 /* RTW_HEADER_PhysicalLayerModel_Channel1_h_ */
