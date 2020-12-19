/*
 * Code generation for system system '<S3>/Receiver'
 * For more details, see corresponding source file PhysicalLayerModelUSRP_Receiver.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModelUSRP_Receiver_h_
#define RTW_HEADER_PhysicalLayerModelUSRP_Receiver_h_
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

/* Block signals for system '<S3>/Receiver' */
typedef struct {
  creal_T Gain[2112];                  /* '<S10>/Gain' */
  creal_T FIRDecimation[2112];         /* '<S13>/FIR Decimation' */
  creal_T Sensitivity3[2112];          /* '<S17>/Sensitivity3' */
  creal_T Sum;                         /* '<S17>/Sum' */
  creal_T RealImagtoComplex[264];      /* '<S18>/Real-Imag to Complex' */
  creal_T PSKOn[264];                  /* '<S9>/PSK On' */
  creal_T PSKGain[264];                /* '<S9>/PSK Gain' */
  creal_T QAMOn[264];                  /* '<S9>/QAM On' */
  real_T ComplextoRealImag2_o1[2112];  /* '<S18>/Complex to Real-Imag2' */
  real_T ComplextoRealImag2_o2[2112];  /* '<S18>/Complex to Real-Imag2' */
  real_T MathFunction[2112];           /* '<S17>/Math Function' */
  real_T ComplextoMagnitudeAngle;      /* '<S17>/Complex to Magnitude-Angle' */
  real_T Sensitivity1;                 /* '<S17>/Sensitivity1' */
  real_T Abs;                          /* '<S19>/Abs' */
  real_T Merge;                        /* '<S19>/Merge' */
  real_T Fcn;                          /* '<S19>/Fcn' */
  real_T Sum2;                         /* '<S19>/Sum2' */
  real_T Sum_hha5s[264];               /* '<S16>/Sum' */
  real_T Gain_nyex1[264];              /* '<S16>/Gain' */
  real_T Sum1[264];                    /* '<S16>/Sum1' */
  real_T Interpolation[264];           /* '<S18>/Interpolation' */
  real_T Interpolation1[264];          /* '<S18>/Interpolation1' */
  real_T VectorintermsofSamples[264];  /* '<S14>/Vector in terms of Samples' */
  uint32_T usrp_uhd_sfunrx_o2;         /* '<S10>/usrp_uhd_sfunrx' */
  uint32_T usrp_uhd_sfunrx_o3;         /* '<S10>/usrp_uhd_sfunrx' */
  cint16_T usrp_uhd_sfunrx_o1[2112];   /* '<S10>/usrp_uhd_sfunrx' */
  uint8_T Compare;                     /* '<S11>/Compare' */
  uint8_T MPSKDemodulatorBaseband[264];/* '<S9>/M-PSK Demodulator Baseband' */
  uint8_T Compare_fjcnv;               /* '<S12>/Compare' */
  uint8_T RectangularQAMDemodulatorBaseba[264];/* '<S9>/Rectangular QAM Demodulator Baseband' */
  uint8_T MultiportSwitch[264];        /* '<S9>/Multiport Switch' */
} B_Receiver_PhysicalLayerModel_T;

/* Block states (auto storage) for system '<S3>/Receiver' */
typedef struct {
  creal_T FIRDecimation_OutBuff[4224]; /* '<S13>/FIR Decimation' */
  creal_T FIRDecimation_StatesBuff[65];/* '<S13>/FIR Decimation' */
  creal_T FIRDecimation_Sums;          /* '<S13>/FIR Decimation' */
  int32_T FIRDecimation_PhaseIdx;      /* '<S13>/FIR Decimation' */
  int32_T FIRDecimation_OutIdx;        /* '<S13>/FIR Decimation' */
  int32_T FIRDecimation_CoeffIdx;      /* '<S13>/FIR Decimation' */
  int32_T FIRDecimation_TapDelayIndex; /* '<S13>/FIR Decimation' */
  int32_T usrp_uhd_sfunrx_work4;       /* '<S10>/usrp_uhd_sfunrx' */
  UsrpErrorSLCapiEnumT usrp_uhd_sfunrx_work2;/* '<S10>/usrp_uhd_sfunrx' */
  boolean_T FIRDecimation_wrtBufIdx;   /* '<S13>/FIR Decimation' */
  boolean_T FIRDecimation_readBufIdx;  /* '<S13>/FIR Decimation' */
  int8_T usrp_uhd_sfunrx_work1[1024];  /* '<S10>/usrp_uhd_sfunrx' */
  int8_T usrp_uhd_sfunrx_work3[1024];  /* '<S10>/usrp_uhd_sfunrx' */
} DW_Receiver_PhysicalLayerMode_T;

/* Parameters for system: '<S3>/Receiver' */
struct P_Receiver_PhysicalLayerModel_T_ {
  real_T Settozero_Gain;               /* Expression: 0
                                        * Referenced by: '<S20>/Set to zero'
                                        */
  real_T Sensitivity1_Gain;            /* Expression: -1/(2*pi)
                                        * Referenced by: '<S17>/Sensitivity1'
                                        */
  real_T Constant_Value[264];          /* Expression: [0:numSymb-1]'
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: sampPerSymb
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T PSKGain_Gain;                 /* Expression: 1/SignalPower
                                        * Referenced by: '<S9>/PSK Gain'
                                        */
  real_T VectorintermsofSamples_Gain[264];/* Expression: sampPerSymb.*ones(numSymb,1)
                                           * Referenced by: '<S14>/Vector in terms of Samples'
                                           */
  real_T port_1_Value;                 /* Expression: centerFrequency
                                        * Referenced by: '<S10>/port_1'
                                        */
  real_T port_2_Value;                 /* Expression: loOffset
                                        * Referenced by: '<S10>/port_2'
                                        */
  real_T port_3_Value;                 /* Expression: gain
                                        * Referenced by: '<S10>/port_3'
                                        */
  real_T port_4_Value;                 /* Expression: decimInterp
                                        * Referenced by: '<S10>/port_4'
                                        */
  real_T Gain_Gain_ima5v;              /* Expression: double(1/(2^15-1))
                                        * Referenced by: '<S10>/Gain'
                                        */
  creal_T Sensitivity3_Gain[2112];     /* Expression: exp(-i*2*pi*(0:L*obsInt-1)'/L)
                                        * Referenced by: '<S17>/Sensitivity3'
                                        */
  int8_T ModulationType_Value;         /* Expression: ModulationType
                                        * Referenced by: '<S9>/Modulation Type'
                                        */
  int8_T Constant_Value_jhhlt;         /* Computed Parameter: Constant_Value_jhhlt
                                        * Referenced by: '<S11>/Constant'
                                        */
  int8_T Constant_Value_puofi;         /* Computed Parameter: Constant_Value_puofi
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T PSKOn_Threshold;             /* Computed Parameter: PSKOn_Threshold
                                        * Referenced by: '<S9>/PSK On'
                                        */
  uint8_T QAMOn_Threshold;             /* Computed Parameter: QAMOn_Threshold
                                        * Referenced by: '<S9>/QAM On'
                                        */
};

void PhysicalLayerMod_Receiver_Start(DW_Receiver_PhysicalLayerMode_T *localDW);
void PhysicalLayerModelUSRP_Receiver(B_Receiver_PhysicalLayerModel_T *localB,
  DW_Receiver_PhysicalLayerMode_T *localDW, P_Receiver_PhysicalLayerModel_T
  *localP);
void PhysicalLayerMode_Receiver_Term(DW_Receiver_PhysicalLayerMode_T *localDW);

#endif                                 /* RTW_HEADER_PhysicalLayerModelUSRP_Receiver_h_ */
