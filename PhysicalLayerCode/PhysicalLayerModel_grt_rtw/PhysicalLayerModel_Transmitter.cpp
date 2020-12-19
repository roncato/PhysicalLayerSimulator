/*
 * Code generation for system system '<S5>/Transmitter'
 *
 * Model                      : PhysicalLayerModel
 * Model version              : 1.254
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C++ source code generated on : Fri Jul 25 20:13:46 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModel_Transmitter.h"

/* Include model header file for global data */
#include "PhysicalLayerModel.h"
#include "PhysicalLayerModel_private.h"

void UpFIR_DF_Z_D(const creal_T inArray[], const real_T coefArra[], creal_T
                  tap0Array[], creal_T outArray[], int32_T tapIdx[], int32_T
                  outIdx, int32_T numChans, int32_T inFrameSize, int32_T iFactor,
                  int32_T polyphaseFiltLen)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T m;
  int32_T curTapIdx;
  int32_T inputIdx;
  int32_T tap0Idx;
  int32_T cffIdx;
  int32_T memIdx;
  real_T sumsArray_re;
  real_T sumsArray_im;

  /* S-Function (sdspupfir2): '<S31>/FIR Interpolation' */
  curTapIdx = 0;
  inputIdx = 0;
  tap0Idx = 0;
  sumsArray_re = 0.0;
  sumsArray_im = 0.0;
  for (k = 0; k < numChans; k++) {
    curTapIdx = tapIdx[0U];
    for (i = 0; i < inFrameSize; i++) {
      cffIdx = 0;
      memIdx = tap0Idx + curTapIdx;
      tap0Array[memIdx] = inArray[inputIdx];
      for (m = 0; m < iFactor; m++) {
        for (j = 0; j <= curTapIdx; j++) {
          sumsArray_re += tap0Array[memIdx].re * coefArra[cffIdx];
          sumsArray_im += tap0Array[memIdx].im * coefArra[cffIdx];
          memIdx--;
          cffIdx++;
        }

        memIdx += polyphaseFiltLen;
        while (j < polyphaseFiltLen) {
          sumsArray_re += tap0Array[memIdx].re * coefArra[cffIdx];
          sumsArray_im += tap0Array[memIdx].im * coefArra[cffIdx];
          memIdx--;
          cffIdx++;
          j++;
        }

        outArray[outIdx].re = sumsArray_re;
        outArray[outIdx].im = sumsArray_im;
        outIdx++;
        sumsArray_re = 0.0;
        sumsArray_im = 0.0;
      }

      inputIdx++;
      curTapIdx++;
      if (curTapIdx >= polyphaseFiltLen) {
        curTapIdx = 0;
      }
    }

    tap0Idx += polyphaseFiltLen;
  }

  tapIdx[0U] = curTapIdx;

  /* End of S-Function (sdspupfir2): '<S31>/FIR Interpolation' */
}

/*
 * Initial conditions for atomic system:
 *    '<S5>/Transmitter'
 *    '<S6>/Transmitter'
 */
void PhysicalLayerM_Transmitter_Init(DW_Transmitter_PhysicalLayerM_T *localDW,
  P_Transmitter_PhysicalLayerMo_T *localP)
{
  int32_T buffIdx;
  real_T arg;
  int32_T i;

  /* InitializeConditions for S-Function (sdspupfir2): '<S31>/FIR Interpolation' */
  localDW->FIRInterpolation_TapDelayIndex = 0;
  for (i = 0; i < 9; i++) {
    localDW->FIRInterpolation_TapDelayBuff[i].re = 0.0;
    localDW->FIRInterpolation_TapDelayBuff[i].im = 0.0;
  }

  /* End of InitializeConditions for S-Function (sdspupfir2): '<S31>/FIR Interpolation' */

  /* InitializeConditions for S-Function (sdspvdly2): '<S16>/Variable Fractional Delay' */
  localDW->VariableFractionalDelay_BUFF_OF = 4;
  buffIdx = 0;
  for (i = 0; i < 5; i++) {
    localDW->VariableFractionalDelay_BUFF[buffIdx].re = 0.0;
    localDW->VariableFractionalDelay_BUFF[buffIdx].im = 0.0;
    buffIdx++;
  }

  /* End of InitializeConditions for S-Function (sdspvdly2): '<S16>/Variable Fractional Delay' */

  /* InitializeConditions for S-Function (sdspsine2): '<S32>/Upfrequency Oscillator' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  for (arg = localP->UpfrequencyOscillator_Phase; arg >= 6.2831853071795862; arg
       -= 6.2831853071795862) {
  }

  while (arg < 0.0) {
    arg += 6.2831853071795862;
  }

  localDW->UpfrequencyOscillator_AccFreqNo = arg;

  /* End of InitializeConditions for S-Function (sdspsine2): '<S32>/Upfrequency Oscillator' */

  // Transmission Power
  localP->TransmissionPower = 1;

  // Bandwitdth
  localP->Bandwidth = 1e6;

}

/*
 * Start for atomic system:
 *    '<S5>/Transmitter'
 *    '<S6>/Transmitter'
 */
void PhysicalLayer_Transmitter_Start(DW_Transmitter_PhysicalLayerM_T *localDW,
  P_Transmitter_PhysicalLayerMo_T *localP)
{
  real_T arg;

  /* Start for S-Function (sdspsine2): '<S32>/Upfrequency Oscillator' */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  for (arg = localP->UpfrequencyOscillator_Phase; arg >= 6.2831853071795862; arg
       -= 6.2831853071795862) {
  }

  while (arg < 0.0) {
    arg += 6.2831853071795862;
  }

  localDW->UpfrequencyOscillator_AccFreqNo = arg;

  /* End of Start for S-Function (sdspsine2): '<S28>/Upfrequency Oscillator' */
}

/*
 * Output and update for atomic system:
 *    '<S5>/Transmitter'
 *    '<S6>/Transmitter'
 */
void PhysicalLayerModel_Transmitter(const uint8_T rtu_TransmitterIn[264],
  B_Transmitter_PhysicalLayerMo_T *localB, DW_Transmitter_PhysicalLayerM_T
  *localDW, P_Transmitter_PhysicalLayerMo_T *localP)
{
  int32_T inIdx;
  int32_T outIdx;
  uint8_T u;
  int32_T ti;
  int32_T ti_0;
  real_T accum;
  real_T accum_0;
  int32_T buffstart;
  int32_T i;
  real_T im;

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S16>/Modulation Type'
   *  Constant: '<S29>/Constant'
   */
  localB->Compare = (localP->ModulationType_Value == localP->Constant_Value);

  /* Switch: '<S16>/PSK On' */
  for (i = 0; i < 264; i++) {
    if (localB->Compare > localP->PSKOn_Threshold) {
      localB->PSKOn[i] = rtu_TransmitterIn[i];
    } else {
      localB->PSKOn[i] = ((uint8_T)0U);
    }
  }

  /* End of Switch: '<S16>/PSK On' */

  /* S-Function (scomapskmod4): '<S16>/M-PSK Modulator Baseband' */
  inIdx = 0;
  outIdx = 0;
  for (i = 0; i < 264; i++) {
    u = localB->PSKOn[inIdx];
    inIdx++;
    ti_0 = u;
    for (ti = 1; ti < 4; ti += ti) {
      buffstart = ti_0 >> ti;
      ti_0 ^= buffstart;
    }

    localB->MPSKModulatorBaseband[outIdx].re =
      PhysicalLayerModel_ConstP.pooled5[ti_0 << 1];
    localB->MPSKModulatorBaseband[outIdx].im =
      PhysicalLayerModel_ConstP.pooled5[(ti_0 << 1) + 1];
    outIdx++;
  }

  /* End of S-Function (scomapskmod4): '<S16>/M-PSK Modulator Baseband' */

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S16>/Modulation Type'
   *  Constant: '<S30>/Constant'
   */
  localB->Compare_hirmf = (localP->ModulationType_Value ==
    localP->Constant_Value_b4tax);

  /* Switch: '<S16>/QAM On' */
  for (i = 0; i < 264; i++) {
    if (localB->Compare_hirmf > localP->QAMOn_Threshold) {
      localB->QAMOn[i] = rtu_TransmitterIn[i];
    } else {
      localB->QAMOn[i] = ((uint8_T)0U);
    }
  }

  /* End of Switch: '<S16>/QAM On' */

  /* S-Function (scomapskmod4): '<S16>/Rectangular QAM Modulator Baseband' */
  inIdx = 0;
  outIdx = 0;
  for (i = 0; i < 264; i++) {
    u = localB->QAMOn[inIdx];
    inIdx++;
    ti_0 = u;
    localB->RectangularQAMModulatorBaseband[outIdx].re =
      PhysicalLayerModel_ConstP.pooled6[ti_0 << 1] * localP->TransmissionPower;
    localB->RectangularQAMModulatorBaseband[outIdx].im =
      PhysicalLayerModel_ConstP.pooled6[(ti_0 << 1) + 1] * localP->TransmissionPower;
    outIdx++;
  }

  /* End of S-Function (scomapskmod4): '<S16>/Rectangular QAM Modulator Baseband' */

  /* MultiPortSwitch: '<S16>/Multiport Switch' incorporates:
   *  Constant: '<S16>/Modulation Type'
   */
  if (localP->ModulationType_Value == 0) {
    memcpy(&localB->MultiportSwitch[0], &localB->
           RectangularQAMModulatorBaseband[0], 264U * sizeof(creal_T));
  } else {
    /* Gain: '<S16>/PSK Gain' */
    for (i = 0; i < 264; i++) {
		localB->PSKGain[i].re = localP->TransmissionPower *
        localB->MPSKModulatorBaseband[i].re;
		localB->PSKGain[i].im = localP->TransmissionPower *
        localB->MPSKModulatorBaseband[i].im;
      localB->MultiportSwitch[i] = localB->PSKGain[i];
    }

    /* End of Gain: '<S16>/PSK Gain' */
  }

  /* End of MultiPortSwitch: '<S16>/Multiport Switch' */

  /* S-Function (sdspupfir2): '<S31>/FIR Interpolation' */
  UpFIR_DF_Z_D(localB->MultiportSwitch, localP->FIRInterpolation_FILTER_COEFF,
               localDW->FIRInterpolation_TapDelayBuff, localB->FIRInterpolation,
               &localDW->FIRInterpolation_TapDelayIndex, 0, 1, 264, 8, 9);

  /* S-Function (sdspvdly2): '<S16>/Variable Fractional Delay' incorporates:
   *  Constant: '<S16>/Delay Factor'
   */
  ti_0 = (int32_T)floor(localP->DelayFactor_Value);
  if (ti_0 < 0) {
    ti_0 = 0;
    accum_0 = 0.0;
  } else if (ti_0 >= 4) {
    ti_0 = 4;
    accum_0 = 0.0;
  } else {
    accum = ti_0;
    accum_0 = localP->DelayFactor_Value;
    accum_0 -= accum;
  }

  inIdx = 0;
  outIdx = 0;
  buffstart = localDW->VariableFractionalDelay_BUFF_OF;
  for (i = 0; i < 2112; i++) {
    if (buffstart == 5) {
      buffstart = 0;
    }

    localDW->VariableFractionalDelay_BUFF[buffstart] = localB->
      FIRInterpolation[inIdx];
    inIdx++;
    ti = ti_0;
    ti = buffstart - ti;
    if (ti < 0) {
      ti += 5;
    }

    if (ti > 0) {
      accum = localDW->VariableFractionalDelay_BUFF[ti - 1].re;
      im = localDW->VariableFractionalDelay_BUFF[ti - 1].im;
    } else {
      accum = localDW->VariableFractionalDelay_BUFF[ti + 4].re;
      im = localDW->VariableFractionalDelay_BUFF[ti + 4].im;
    }

    accum -= localDW->VariableFractionalDelay_BUFF[ti].re;
    im -= localDW->VariableFractionalDelay_BUFF[ti].im;
    accum *= accum_0;
    im *= accum_0;
    accum += localDW->VariableFractionalDelay_BUFF[ti].re;
    im += localDW->VariableFractionalDelay_BUFF[ti].im;
    localB->VariableFractionalDelay[outIdx].re = accum;
    localB->VariableFractionalDelay[outIdx].im = im;
    outIdx++;
    buffstart++;
  }

  localDW->VariableFractionalDelay_BUFF_OF += 2112;
  while (localDW->VariableFractionalDelay_BUFF_OF >= 5) {
    localDW->VariableFractionalDelay_BUFF_OF -= 5;
  }

  /* End of S-Function (sdspvdly2): '<S16>/Variable Fractional Delay' */

  /* S-Function (sdspsine2): '<S32>/Upfrequency Oscillator' */
  accum = localP->UpfrequencyOscillator_Frequency * (1 / localP->Bandwidth) / 1.27323954489;
  for (ti_0 = 0; ti_0 < 2112; ti_0++) {
    accum_0 = localDW->UpfrequencyOscillator_AccFreqNo;
    localB->UpfrequencyOscillator[ti_0].re =
      localP->UpfrequencyOscillator_Amplitude * cos(accum_0);
    localB->UpfrequencyOscillator[ti_0].im =
      localP->UpfrequencyOscillator_Amplitude * sin(accum_0);

    /* Update accumulated normalized freq value
       for next sample.  Keep in range [0 2*pi) */
    localDW->UpfrequencyOscillator_AccFreqNo += accum;
    if (localDW->UpfrequencyOscillator_AccFreqNo >= 6.2831853071795862) {
      localDW->UpfrequencyOscillator_AccFreqNo -= 6.2831853071795862;
    } else {
      if (localDW->UpfrequencyOscillator_AccFreqNo < 0.0) {
        localDW->UpfrequencyOscillator_AccFreqNo += 6.2831853071795862;
      }
    }
  }

  for (i = 0; i < 2112; i++) {
    /* Product: '<S32>/Product' */
    accum = localB->VariableFractionalDelay[i].re *
      localB->UpfrequencyOscillator[i].re - localB->VariableFractionalDelay[i].
      im * localB->UpfrequencyOscillator[i].im;
    im = localB->VariableFractionalDelay[i].re * localB->UpfrequencyOscillator[i]
      .im + localB->VariableFractionalDelay[i].im *
      localB->UpfrequencyOscillator[i].re;
    localB->Product[i].re = accum;
    localB->Product[i].im = im;

    /* ComplexToRealImag: '<S32>/Complex to Real-Imag' */
    localB->ComplextoRealImag[i] = localB->Product[i].re;
  }

  /* End of S-Function (sdspsine2): '<S32>/Upfrequency Oscillator' */
}

/*
 * Termination for atomic system:
 *    '<S5>/Transmitter'
 *    '<S6>/Transmitter'
 */
void PhysicalLayerM_Transmitter_Term(void)
{
}
