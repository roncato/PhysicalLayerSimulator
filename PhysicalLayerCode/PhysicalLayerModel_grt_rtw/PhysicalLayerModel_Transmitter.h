/*
 * Code generation for system system '<S5>/Transmitter'
 * For more details, see corresponding source file PhysicalLayerModel_Transmitter.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModel_Transmitter_h_
#define RTW_HEADER_PhysicalLayerModel_Transmitter_h_
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

/* Block signals for system '<S5>/Transmitter' */
typedef struct {
  creal_T MPSKModulatorBaseband[264];  /* '<S16>/M-PSK Modulator Baseband' */
  creal_T RectangularQAMModulatorBaseband[264];/* '<S16>/Rectangular QAM Modulator Baseband' */
  creal_T MultiportSwitch[264];        /* '<S16>/Multiport Switch' */
  creal_T FIRInterpolation[2112];      /* '<S31>/FIR Interpolation' */
  creal_T VariableFractionalDelay[2112];/* '<S16>/Variable Fractional Delay' */
  creal_T UpfrequencyOscillator[2112]; /* '<S32>/Upfrequency Oscillator' */
  creal_T Product[2112];               /* '<S32>/Product' */
  creal_T PSKGain[264];                /* '<S16>/PSK Gain' */
  real_T ComplextoRealImag[2112];      /* '<S32>/Complex to Real-Imag' */
  uint8_T Compare;                     /* '<S29>/Compare' */
  uint8_T PSKOn[264];                  /* '<S16>/PSK On' */
  uint8_T Compare_hirmf;               /* '<S30>/Compare' */
  uint8_T QAMOn[264];                  /* '<S16>/QAM On' */
} B_Transmitter_PhysicalLayerMo_T;

/* Block states (auto storage) for system '<S5>/Transmitter' */
typedef struct {
  creal_T FIRInterpolation_TapDelayBuff[9];/* '<S31>/FIR Interpolation' */
  creal_T VariableFractionalDelay_BUFF[5];/* '<S16>/Variable Fractional Delay' */
  real_T UpfrequencyOscillator_AccFreqNo;/* '<S32>/Upfrequency Oscillator' */
  int32_T FIRInterpolation_TapDelayIndex;/* '<S31>/FIR Interpolation' */
  int32_T VariableFractionalDelay_BUFF_OF;/* '<S16>/Variable Fractional Delay' */
} DW_Transmitter_PhysicalLayerM_T;

/* Parameters for system: '<S5>/Transmitter' */
struct P_Transmitter_PhysicalLayerMo_T_ {
  real_T PSKGain_Gain;                 /* Expression: SignalPower
                                        * Referenced by: '<S16>/PSK Gain'
                                        */
  real_T DelayFactor_Value;            /* Expression: DelayParam
                                        * Referenced by: '<S16>/Delay Factor'
                                        */
  real_T FIRInterpolation_FILTER_COEFF[72];/* Expression: a.h
                                            * Referenced by: '<S31>/FIR Interpolation'
                                            */
  real_T UpfrequencyOscillator_Amplitude;/* Expression: Amplitude
                                          * Referenced by: '<S32>/Upfrequency Oscillator'
                                          */
  real_T UpfrequencyOscillator_Frequency;/* Expression: Frequency
                                          * Referenced by: '<S32>/Upfrequency Oscillator'
                                          */
  real_T UpfrequencyOscillator_Phase;  /* Expression: Phase
                                        * Referenced by: '<S32>/Upfrequency Oscillator'
                                        */
  int8_T ModulationType_Value;         /* Expression: ModulationType
                                        * Referenced by: '<S16>/Modulation Type'
                                        */
  int8_T Constant_Value;               /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S29>/Constant'
                                        */
  int8_T Constant_Value_b4tax;         /* Computed Parameter: Constant_Value_b4tax
                                        * Referenced by: '<S30>/Constant'
                                        */
  uint8_T PSKOn_Threshold;             /* Computed Parameter: PSKOn_Threshold
                                        * Referenced by: '<S16>/PSK On'
                                        */
  uint8_T QAMOn_Threshold;             /* Computed Parameter: QAMOn_Threshold
                                        * Referenced by: '<S16>/QAM On'
                                        */
  real_T TransmissionPower;

  real_T Bandwidth;
};

void PhysicalLayerM_Transmitter_Init(DW_Transmitter_PhysicalLayerM_T *localDW,
  P_Transmitter_PhysicalLayerMo_T *localP);
void PhysicalLayer_Transmitter_Start(DW_Transmitter_PhysicalLayerM_T *localDW,
  P_Transmitter_PhysicalLayerMo_T *localP);
void PhysicalLayerModel_Transmitter(const uint8_T rtu_TransmitterIn[264],
  B_Transmitter_PhysicalLayerMo_T *localB, DW_Transmitter_PhysicalLayerM_T
  *localDW, P_Transmitter_PhysicalLayerMo_T *localP);

#endif                                 /* RTW_HEADER_PhysicalLayerModel_Transmitter_h_ */
