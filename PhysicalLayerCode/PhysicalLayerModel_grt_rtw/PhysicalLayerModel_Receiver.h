/*
 * Code generation for system system '<S5>/Receiver'
 * For more details, see corresponding source file PhysicalLayerModel_Receiver.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModel_Receiver_h_
#define RTW_HEADER_PhysicalLayerModel_Receiver_h_
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

/* Block signals for system '<S5>/Receiver' */
typedef struct {
  creal_T DownfrequencyOscillator[2112];/* '<S17>/Downfrequency Oscillator' */
  creal_T Conjugate[2112];             /* '<S17>/Conjugate' */
  creal_T Product1[2112];              /* '<S17>/Product1' */
  creal_T FIRDecimation[2112];         /* '<S20>/FIR Decimation' */
  creal_T Sensitivity3[2112];          /* '<S24>/Sensitivity3' */
  creal_T Sum;                         /* '<S24>/Sum' */
  creal_T RealImagtoComplex[264];      /* '<S25>/Real-Imag to Complex' */
  creal_T PSKOn[264];                  /* '<S15>/PSK On' */
  creal_T PSKGain[264];                /* '<S15>/PSK Gain' */
  creal_T QAMOn[264];                  /* '<S15>/QAM On' */
  real_T ComplextoRealImag2_o1[2112];  /* '<S25>/Complex to Real-Imag2' */
  real_T ComplextoRealImag2_o2[2112];  /* '<S25>/Complex to Real-Imag2' */
  real_T MathFunction[2112];           /* '<S24>/Math Function' */
  real_T ComplextoMagnitudeAngle;      /* '<S24>/Complex to Magnitude-Angle' */
  real_T Sensitivity1;                 /* '<S24>/Sensitivity1' */
  real_T Abs;                          /* '<S26>/Abs' */
  real_T Merge;                        /* '<S26>/Merge' */
  real_T Fcn;                          /* '<S26>/Fcn' */
  real_T Sum2;                         /* '<S26>/Sum2' */
  real_T Sum_hqxki[264];               /* '<S23>/Sum' */
  real_T Gain[264];                    /* '<S23>/Gain' */
  real_T Sum1[264];                    /* '<S23>/Sum1' */
  real_T Interpolation[264];           /* '<S25>/Interpolation' */
  real_T Interpolation1[264];          /* '<S25>/Interpolation1' */
  real_T VectorintermsofSamples[264];  /* '<S21>/Vector in terms of Samples' */
  uint8_T Compare;                     /* '<S18>/Compare' */
  uint8_T MPSKDemodulatorBaseband[264];/* '<S15>/M-PSK Demodulator Baseband' */
  uint8_T Compare_puagn;               /* '<S19>/Compare' */
  uint8_T RectangularQAMDemodulatorBaseba[264];/* '<S15>/Rectangular QAM Demodulator Baseband' */
  uint8_T MultiportSwitch[264];        /* '<S15>/Multiport Switch' */
} B_Receiver_PhysicalLayerModel_T;

/* Block states (auto storage) for system '<S5>/Receiver' */
typedef struct {
  creal_T FIRDecimation_OutBuff[4224]; /* '<S20>/FIR Decimation' */
  creal_T FIRDecimation_StatesBuff[65];/* '<S20>/FIR Decimation' */
  real_T DownfrequencyOscillator_AccFreq;/* '<S17>/Downfrequency Oscillator' */
  creal_T FIRDecimation_Sums;          /* '<S20>/FIR Decimation' */
  int32_T FIRDecimation_PhaseIdx;      /* '<S20>/FIR Decimation' */
  int32_T FIRDecimation_OutIdx;        /* '<S20>/FIR Decimation' */
  int32_T FIRDecimation_CoeffIdx;      /* '<S20>/FIR Decimation' */
  int32_T FIRDecimation_TapDelayIndex; /* '<S20>/FIR Decimation' */
  boolean_T FIRDecimation_wrtBufIdx;   /* '<S20>/FIR Decimation' */
  boolean_T FIRDecimation_readBufIdx;  /* '<S20>/FIR Decimation' */
} DW_Receiver_PhysicalLayerMode_T;

/* Parameters for system: '<S5>/Receiver' */
struct P_Receiver_PhysicalLayerModel_T_ {
  real_T Settozero_Gain;               /* Expression: 0
                                        * Referenced by: '<S27>/Set to zero'
                                        */
  real_T DownfrequencyOscillator_Amplitu;/* Expression: Amplitude
                                          * Referenced by: '<S17>/Downfrequency Oscillator'
                                          */
  real_T DownfrequencyOscillator_Frequen;/* Expression: Frequency
                                          * Referenced by: '<S17>/Downfrequency Oscillator'
                                          */
  real_T DownfrequencyOscillator_Phase;/* Expression: Phase
                                        * Referenced by: '<S17>/Downfrequency Oscillator'
                                        */
  real_T Sensitivity1_Gain;            /* Expression: -1/(2*pi)
                                        * Referenced by: '<S24>/Sensitivity1'
                                        */
  real_T Constant_Value[264];          /* Expression: [0:numSymb-1]'
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: sampPerSymb
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T PSKGain_Gain;                 /* Expression: 1/SignalPower
                                        * Referenced by: '<S15>/PSK Gain'
                                        */
  real_T VectorintermsofSamples_Gain[264];/* Expression: sampPerSymb.*ones(numSymb,1)
                                           * Referenced by: '<S21>/Vector in terms of Samples'
                                           */
  creal_T Sensitivity3_Gain[2112];     /* Expression: exp(-i*2*pi*(0:L*obsInt-1)'/L)
                                        * Referenced by: '<S24>/Sensitivity3'
                                        */
  int8_T ModulationType_Value;         /* Expression: ModulationType
                                        * Referenced by: '<S15>/Modulation Type'
                                        */
  int8_T Constant_Value_iyrus;         /* Computed Parameter: Constant_Value_iyrus
                                        * Referenced by: '<S18>/Constant'
                                        */
  int8_T Constant_Value_ch0td;         /* Computed Parameter: Constant_Value_ch0td
                                        * Referenced by: '<S19>/Constant'
                                        */
  uint8_T PSKOn_Threshold;             /* Computed Parameter: PSKOn_Threshold
                                        * Referenced by: '<S15>/PSK On'
                                        */
  uint8_T QAMOn_Threshold;             /* Computed Parameter: QAMOn_Threshold
                                        * Referenced by: '<S15>/QAM On'
                                        */
  real_T ReceiverPower;

  real_T Bandwidth;

};

void PhysicalLayerMode_Receiver_Init(DW_Receiver_PhysicalLayerMode_T *localDW,
  P_Receiver_PhysicalLayerModel_T *localP);
void PhysicalLayerMod_Receiver_Start(DW_Receiver_PhysicalLayerMode_T *localDW,
  P_Receiver_PhysicalLayerModel_T *localP);
void PhysicalLayerModel_Receiver(const real_T rtu_ReceiverIn[2112],
  B_Receiver_PhysicalLayerModel_T *localB, DW_Receiver_PhysicalLayerMode_T
  *localDW, P_Receiver_PhysicalLayerModel_T *localP);

#endif                                 /* RTW_HEADER_PhysicalLayerModel_Receiver_h_ */
