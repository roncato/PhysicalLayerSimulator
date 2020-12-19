/*
 * Code generation for system system '<S3>/Transmitter'
 * For more details, see corresponding source file PhysicalLayerModelU_Transmitter.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModelU_Transmitter_h_
#define RTW_HEADER_PhysicalLayerModelU_Transmitter_h_
#ifndef PhysicalLayerModelUSRP_COMMON_INCLUDES_
# define PhysicalLayerModelUSRP_COMMON_INCLUDES_
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
#include "usrp_uhd_capi.hpp"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* PhysicalLayerModelUSRP_COMMON_INCLUDES_ */

#include "PhysicalLayerModelUSRP_types.h"

/* Block signals for system '<S3>/Transmitter' */
typedef struct {
  creal_T RectangularQAMModulatorBaseband[264];/* '<S8>/Rectangular QAM Modulator Baseband' */
  creal_T MPSKModulatorBaseband[264];  /* '<S8>/M-PSK Modulator Baseband' */
  creal_T MultiportSwitch[264];        /* '<S8>/Multiport Switch' */
  creal_T FIRInterpolation[2112];      /* '<S24>/FIR Interpolation' */
  creal_T VariableFractionalDelay[2112];/* '<S8>/Variable Fractional Delay' */
  creal_T PSKGain[264];                /* '<S8>/PSK Gain' */
  uint32_T usrp_uhd_sfuntx;            /* '<S25>/usrp_uhd_sfuntx' */
  uint8_T Compare;                     /* '<S23>/Compare' */
  uint8_T QAMOn[264];                  /* '<S8>/QAM On' */
  uint8_T Compare_fxhmg;               /* '<S22>/Compare' */
  uint8_T PSKOn[264];                  /* '<S8>/PSK On' */
} B_Transmitter_PhysicalLayerMo_T;

/* Block states (auto storage) for system '<S3>/Transmitter' */
typedef struct {
  creal_T FIRInterpolation_TapDelayBuff[9];/* '<S24>/FIR Interpolation' */
  creal_T VariableFractionalDelay_BUFF[5];/* '<S8>/Variable Fractional Delay' */
  int32_T FIRInterpolation_TapDelayIndex;/* '<S24>/FIR Interpolation' */
  int32_T VariableFractionalDelay_BUFF_OF;/* '<S8>/Variable Fractional Delay' */
  int32_T usrp_uhd_sfuntx_work4;       /* '<S25>/usrp_uhd_sfuntx' */
  uint32_T usrp_uhd_sfuntx_work5;      /* '<S25>/usrp_uhd_sfuntx' */
  DataPortDataTypeSLCapiEnumT usrp_uhd_sfuntx_work6;/* '<S25>/usrp_uhd_sfuntx' */
  UsrpErrorSLCapiEnumT usrp_uhd_sfuntx_work2;/* '<S25>/usrp_uhd_sfuntx' */
  int8_T usrp_uhd_sfuntx_work1[1024];  /* '<S25>/usrp_uhd_sfuntx' */
  int8_T usrp_uhd_sfuntx_work3[1024];  /* '<S25>/usrp_uhd_sfuntx' */
} DW_Transmitter_PhysicalLayerM_T;

/* Parameters for system: '<S3>/Transmitter' */
struct P_Transmitter_PhysicalLayerMo_T_ {
  real_T PSKGain_Gain;                 /* Expression: SignalPower
                                        * Referenced by: '<S8>/PSK Gain'
                                        */
  real_T port_1_Value;                 /* Expression: centerFrequency
                                        * Referenced by: '<S25>/port_1'
                                        */
  real_T port_2_Value;                 /* Expression: loOffset
                                        * Referenced by: '<S25>/port_2'
                                        */
  real_T port_3_Value;                 /* Expression: gain
                                        * Referenced by: '<S25>/port_3'
                                        */
  real_T port_4_Value;                 /* Expression: decimInterp
                                        * Referenced by: '<S25>/port_4'
                                        */
  real_T FIRInterpolation_FILTER_COEFF[72];/* Expression: a.h
                                            * Referenced by: '<S24>/FIR Interpolation'
                                            */
  real_T DelayFactor_Value;            /* Expression: DelayParam
                                        * Referenced by: '<S8>/Delay Factor'
                                        */
  int8_T ModulationType_Value;         /* Expression: ModulationType
                                        * Referenced by: '<S8>/Modulation Type'
                                        */
  int8_T Constant_Value;               /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S23>/Constant'
                                        */
  int8_T Constant_Value_lrtfa;         /* Computed Parameter: Constant_Value_lrtfa
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint8_T QAMOn_Threshold;             /* Computed Parameter: QAMOn_Threshold
                                        * Referenced by: '<S8>/QAM On'
                                        */
  uint8_T PSKOn_Threshold;             /* Computed Parameter: PSKOn_Threshold
                                        * Referenced by: '<S8>/PSK On'
                                        */
};

void PhysicalLayerM_Transmitter_Init(DW_Transmitter_PhysicalLayerM_T *localDW);
void PhysicalLayer_Transmitter_Start(DW_Transmitter_PhysicalLayerM_T *localDW);
void PhysicalLayerModelU_Transmitter(const uint8_T rtu_TransmitterIn[264],
  B_Transmitter_PhysicalLayerMo_T *localB, DW_Transmitter_PhysicalLayerM_T
  *localDW, P_Transmitter_PhysicalLayerMo_T *localP);
void PhysicalLayerM_Transmitter_Term(DW_Transmitter_PhysicalLayerM_T *localDW);

#endif                                 /* RTW_HEADER_PhysicalLayerModelU_Transmitter_h_ */
