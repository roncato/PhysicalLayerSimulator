/*
 * Code generation for system system '<S5>/Receiver'
 *
 * Model                      : PhysicalLayerModel
 * Model version              : 1.254
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C++ source code generated on : Fri Jul 25 20:13:46 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModel_Receiver.h"

/* Include model header file for global data */
#include "PhysicalLayerModel.h"
#include "PhysicalLayerModel_private.h"

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2((real_T)tmp_0, (real_T)tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void interpBilinear_MultiChan_real_T(real_T out[], const real_T src[], const
  real_T pts[], const int32_T nSamps, const int32_T nChans, const int32_T
  nSampsI)
{
  int32_T offset;
  int32_T outIdx;
  int32_T pointIndx;
  int32_T chan;
  int32_T samp;
  real_T point;
  int32_T ti;
  real_T mfrac;

  /* S-Function (sdspinterp): '<S25>/Interpolation' */
  /* Bilinear interpolation */
  offset = -1;
  outIdx = 0;
  pointIndx = 0;
  for (chan = 0; chan < nChans; chan++) {
    for (samp = 0; samp < nSampsI; samp++) {
      point = pts[pointIndx];
      pointIndx++;
      if (rtIsNaN(point)) {
        out[outIdx] = (rtNaN);
      } else {
        if (point < 1.0) {
          point = 1.0;
        } else {
          if (point > nSamps) {
            point = nSamps;
          }
        }

        ti = (int32_T)floor(point);
        if (ti == nSamps) {
          out[outIdx] = src[offset + ti];
        } else {
          point -= (real_T)ti;
          mfrac = 1.0 - point;
          out[outIdx] = src[(offset + ti) + 1] * point + src[offset + ti] *
            mfrac;
        }
      }

      outIdx++;
    }

    pointIndx = 0;
    offset += nSamps;
  }

  /* End of S-Function (sdspinterp): '<S25>/Interpolation' */
}

/*
 * Initial conditions for atomic system:
 *    '<S5>/Receiver'
 *    '<S6>/Receiver'
 */
void PhysicalLayerMode_Receiver_Init(DW_Receiver_PhysicalLayerMode_T *localDW,
  P_Receiver_PhysicalLayerModel_T *localP)
{
  real_T arg;
  int32_T i;

  /* InitializeConditions for S-Function (sdspsine2): '<S17>/Downfrequency Oscillator' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  for (arg = localP->DownfrequencyOscillator_Phase; arg >= 6.2831853071795862;
       arg -= 6.2831853071795862) {
  }

  while (arg < 0.0) {
    arg += 6.2831853071795862;
  }

  localDW->DownfrequencyOscillator_AccFreq = arg;

  /* End of InitializeConditions for S-Function (sdspsine2): '<S17>/Downfrequency Oscillator' */

  /* InitializeConditions for S-Function (sdspfirdn2): '<S20>/FIR Decimation' */
  localDW->FIRDecimation_TapDelayIndex = 0;
  localDW->FIRDecimation_PhaseIdx = 0;
  localDW->FIRDecimation_CoeffIdx = 0;
  localDW->FIRDecimation_OutIdx = 0;
  for (i = 0; i < 4224; i++) {
    localDW->FIRDecimation_OutBuff[i].re = 0.0;
    localDW->FIRDecimation_OutBuff[i].im = 0.0;
  }

  localDW->FIRDecimation_Sums.re = 0.0;
  localDW->FIRDecimation_Sums.im = 0.0;
  for (i = 0; i < 65; i++) {
    localDW->FIRDecimation_StatesBuff[i].re = 0.0;
    localDW->FIRDecimation_StatesBuff[i].im = 0.0;
  }

  localDW->FIRDecimation_readBufIdx = TRUE;
  localDW->FIRDecimation_wrtBufIdx = TRUE;
  for (i = 0; i < 2112; i++) {
    localDW->FIRDecimation_OutBuff[i + 2112].re = 0.0;
    localDW->FIRDecimation_OutBuff[i + 2112].im = 0.0;
  }

  /* End of InitializeConditions for S-Function (sdspfirdn2): '<S18>/FIR Decimation' */

  // Receiver Power
  localP->ReceiverPower = 1;

  // Bandwith
  localP->Bandwidth = 1e6;

}

/*
 * Start for atomic system:
 *    '<S5>/Receiver'
 *    '<S6>/Receiver'
 */
void PhysicalLayerMod_Receiver_Start(DW_Receiver_PhysicalLayerMode_T *localDW,
  P_Receiver_PhysicalLayerModel_T *localP)
{
  real_T arg;

  /* Start for S-Function (sdspsine2): '<S17>/Downfrequency Oscillator' */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  for (arg = localP->DownfrequencyOscillator_Phase; arg >= 6.2831853071795862;
       arg -= 6.2831853071795862) {
  }

  while (arg < 0.0) {
    arg += 6.2831853071795862;
  }

  localDW->DownfrequencyOscillator_AccFreq = arg;

  /* End of Start for S-Function (sdspsine2): '<S17>/Downfrequency Oscillator' */
}

/*
 * Output and update for atomic system:
 *    '<S5>/Receiver'
 *    '<S6>/Receiver'
 */
void PhysicalLayerModel_Receiver(const real_T rtu_ReceiverIn[2112],
  B_Receiver_PhysicalLayerModel_T *localB, DW_Receiver_PhysicalLayerMode_T
  *localDW, P_Receiver_PhysicalLayerModel_T *localP)
{
  real_T roundedNearest;
  int32_T inputIdx;
  int32_T curBuf;
  int32_T phaseIdx;
  int32_T curTapIdx;
  int32_T outIdx;
  int32_T cffIdx;
  int32_T tapIdx;
  int32_T j;
  int32_T i;
  real_T re;
  real_T im;
  creal_T u;

  /* S-Function (sdspsine2): '<S17>/Downfrequency Oscillator' */
  roundedNearest = localP->DownfrequencyOscillator_Frequen * (1 / localP->Bandwidth) / 1.27323954489;
  for (j = 0; j < 2112; j++) {
    re = localDW->DownfrequencyOscillator_AccFreq;
    localB->DownfrequencyOscillator[j].re =
      localP->DownfrequencyOscillator_Amplitu * cos(re);
    localB->DownfrequencyOscillator[j].im =
      localP->DownfrequencyOscillator_Amplitu * sin(re);

    /* Update accumulated normalized freq value
       for next sample.  Keep in range [0 2*pi) */
    localDW->DownfrequencyOscillator_AccFreq += roundedNearest;
    if (localDW->DownfrequencyOscillator_AccFreq >= 6.2831853071795862) {
      localDW->DownfrequencyOscillator_AccFreq -= 6.2831853071795862;
    } else {
      if (localDW->DownfrequencyOscillator_AccFreq < 0.0) {
        localDW->DownfrequencyOscillator_AccFreq += 6.2831853071795862;
      }
    }
  }

  for (i = 0; i < 2112; i++) {
    /* Math: '<S17>/Conjugate' */
    localB->Conjugate[i].re = localB->DownfrequencyOscillator[i].re;
    localB->Conjugate[i].im = -localB->DownfrequencyOscillator[i].im;

    /* Product: '<S17>/Product1' */
    localB->Product1[i].re = localB->Conjugate[i].re * rtu_ReceiverIn[i];
    localB->Product1[i].im = localB->Conjugate[i].im * rtu_ReceiverIn[i];
  }

  /* End of S-Function (sdspsine2): '<S17>/Downfrequency Oscillator' */

  /* S-Function (sdspfirdn2): '<S20>/FIR Decimation' */
  inputIdx = 0;
  curBuf = localDW->FIRDecimation_wrtBufIdx;
  phaseIdx = localDW->FIRDecimation_PhaseIdx;
  curTapIdx = localDW->FIRDecimation_TapDelayIndex;
  outIdx = localDW->FIRDecimation_OutIdx;
  cffIdx = localDW->FIRDecimation_CoeffIdx;
  for (i = 0; i < 2112; i++) {
    tapIdx = curTapIdx;
    localDW->FIRDecimation_StatesBuff[tapIdx] = localB->Product1[inputIdx];
    inputIdx++;
    for (j = 0; j < 65; j++) {
      localDW->FIRDecimation_Sums.re += localDW->FIRDecimation_StatesBuff[tapIdx]
        .re * PhysicalLayerModel_ConstP.pooled1[cffIdx];
      localDW->FIRDecimation_Sums.im += localDW->FIRDecimation_StatesBuff[tapIdx]
        .im * PhysicalLayerModel_ConstP.pooled1[cffIdx];
      cffIdx++;
      tapIdx--;
      if (tapIdx < 0) {
        tapIdx += 65;
      }
    }

    curTapIdx++;
    if (curTapIdx >= 65) {
      curTapIdx = 0;
    }

    phaseIdx++;
    if (phaseIdx >= 1) {
      j = outIdx;
      if (curBuf > 0) {
        j += 2112;
      }

      localDW->FIRDecimation_OutBuff[j] = localDW->FIRDecimation_Sums;
      localDW->FIRDecimation_Sums.re = 0.0;
      localDW->FIRDecimation_Sums.im = 0.0;
      outIdx++;
      if (outIdx >= 2112) {
        outIdx = 0;
        curBuf = !(curBuf != 0);
      }

      phaseIdx = 0;
      cffIdx = 0;
    }
  }

  localDW->FIRDecimation_CoeffIdx = cffIdx;
  localDW->FIRDecimation_PhaseIdx = phaseIdx;
  localDW->FIRDecimation_TapDelayIndex = curTapIdx;
  localDW->FIRDecimation_OutIdx = outIdx;
  localDW->FIRDecimation_wrtBufIdx = (curBuf != 0);
  if (localDW->FIRDecimation_readBufIdx == 1) {
    memcpy(&localB->FIRDecimation[0], &localDW->FIRDecimation_OutBuff[2112],
           2112U * sizeof(creal_T));
  } else {
    memcpy(&localB->FIRDecimation[0], &localDW->FIRDecimation_OutBuff[0], 2112U *
           sizeof(creal_T));
  }

  localDW->FIRDecimation_readBufIdx = !localDW->FIRDecimation_readBufIdx;
  for (i = 0; i < 2112; i++) {
    /* ComplexToRealImag: '<S25>/Complex to Real-Imag2' */
    localB->ComplextoRealImag2_o1[i] = localB->FIRDecimation[i].re;
    localB->ComplextoRealImag2_o2[i] = localB->FIRDecimation[i].im;

    /* Math: '<S24>/Math Function'
     *
     * About '<S24>/Math Function':
     *  Operator: magnitude^2
     */
    u = localB->FIRDecimation[i];
    re = u.re * u.re + u.im * u.im;
    localB->MathFunction[i] = re;

    /* Gain: '<S24>/Sensitivity3' */
    localB->Sensitivity3[i].re = localP->Sensitivity3_Gain[i].re *
      localB->MathFunction[i];
    localB->Sensitivity3[i].im = localP->Sensitivity3_Gain[i].im *
      localB->MathFunction[i];
  }

  /* End of S-Function (sdspfirdn2): '<S20>/FIR Decimation' */

  /* Sum: '<S24>/Sum' */
  re = localB->Sensitivity3[0].re;
  im = localB->Sensitivity3[0].im;
  for (cffIdx = 0; cffIdx < 2111; cffIdx++) {
    phaseIdx = cffIdx + 1;
    re += localB->Sensitivity3[phaseIdx].re;
    im += localB->Sensitivity3[phaseIdx].im;
  }

  localB->Sum.re = re;
  localB->Sum.im = im;

  /* End of Sum: '<S24>/Sum' */

  /* ComplexToMagnitudeAngle: '<S24>/Complex to Magnitude-Angle' */
  localB->ComplextoMagnitudeAngle = rt_atan2d_snf(localB->Sum.im, localB->Sum.re);

  /* Gain: '<S24>/Sensitivity1' */
  localB->Sensitivity1 = localP->Sensitivity1_Gain *
    localB->ComplextoMagnitudeAngle;

  /* Abs: '<S26>/Abs' */
  localB->Abs = fabs(localB->Sensitivity1);

  /* If: '<S26>/If' incorporates:
   *  Inport: '<S28>/In1'
   */
  if (localB->Abs < 0.0625) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Gain: '<S27>/Set to zero' */
    localB->Merge = localP->Settozero_Gain * localB->Sensitivity1;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    localB->Merge = localB->Sensitivity1;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem1' */
  }

  /* End of If: '<S26>/If' */

  /* Fcn: '<S26>/Fcn' */
  localB->Fcn = (localB->Merge < 0.0);

  /* Sum: '<S26>/Sum2' */
  localB->Sum2 = localB->Merge + localB->Fcn;
  for (i = 0; i < 264; i++) {
    /* Sum: '<S23>/Sum' incorporates:
     *  Constant: '<S23>/Constant'
     */
    localB->Sum_hqxki[i] = localB->Sum2 + localP->Constant_Value[i];

    /* Gain: '<S23>/Gain' */
    localB->Gain[i] = localP->Gain_Gain * localB->Sum_hqxki[i];

    /* Sum: '<S23>/Sum1' incorporates:
     *  Constant: '<S23>/Constant1'
     */
    localB->Sum1[i] = localB->Gain[i] + localP->Constant1_Value;
  }

  /* S-Function (sdspinterp): '<S25>/Interpolation' */
  interpBilinear_MultiChan_real_T(&localB->Interpolation[0U],
    &localB->ComplextoRealImag2_o1[0U], &localB->Sum1[0U], 2112, 1, 264);

  /* S-Function (sdspinterp): '<S25>/Interpolation1' */
  interpBilinear_MultiChan_real_T(&localB->Interpolation1[0U],
    &localB->ComplextoRealImag2_o2[0U], &localB->Sum1[0U], 2112, 1, 264);

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S15>/Modulation Type'
   *  Constant: '<S18>/Constant'
   */
  localB->Compare = (localP->ModulationType_Value ==
                     localP->Constant_Value_iyrus);
  for (i = 0; i < 264; i++) {
    /* RealImagToComplex: '<S25>/Real-Imag to Complex' */
    localB->RealImagtoComplex[i].re = localB->Interpolation[i];
    localB->RealImagtoComplex[i].im = localB->Interpolation1[i];

    /* Switch: '<S15>/PSK On' */
    if (localB->Compare > localP->PSKOn_Threshold) {
      localB->PSKOn[i] = localB->RealImagtoComplex[i];
    } else {
      localB->PSKOn[i] = PhysicalLayerModel_RGND_Complex;
    }

    /* End of Switch: '<S15>/PSK On' */

    /* Gain: '<S15>/PSK Gain' */
	localB->PSKGain[i].re = 1 / localP->ReceiverPower * localB->PSKOn[i].re;
	localB->PSKGain[i].im = 1 / localP->ReceiverPower * localB->PSKOn[i].im;
  }

  /* S-Function (scompskdemod): '<S15>/M-PSK Demodulator Baseband' */
  for (j = 0; j < 264; j++) {
    re = localB->PSKGain[j].re * 0.98078530365980221 - localB->PSKGain[j].im *
      -0.1950902050974104;
    im = localB->PSKGain[j].re * -0.1950902050974104 + localB->PSKGain[j].im *
      0.98078530365980221;
    re = rt_atan2d_snf(im, re);
    re = re * 16.0 / 6.2831853071795862;
    if (re < 0.0) {
      tapIdx = (int32_T)ceil(re - 0.5);
    } else {
      tapIdx = (int32_T)floor(re + 0.5);
    }

    if (tapIdx < 0) {
      tapIdx += 16;
    }

    inputIdx = tapIdx >> 1;
    inputIdx ^= tapIdx;
    localB->MPSKDemodulatorBaseband[j] = (uint8_T)inputIdx;
  }

  /* End of S-Function (scompskdemod): '<S15>/M-PSK Demodulator Baseband' */

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S15>/Modulation Type'
   *  Constant: '<S19>/Constant'
   */
  localB->Compare_puagn = (localP->ModulationType_Value ==
    localP->Constant_Value_ch0td);

  /* Switch: '<S15>/QAM On' */
  for (i = 0; i < 264; i++) {
    if (localB->Compare_puagn > localP->QAMOn_Threshold) {
      localB->QAMOn[i] = localB->RealImagtoComplex[i];
    } else {
      localB->QAMOn[i] = PhysicalLayerModel_RGND_Complex;
    }
  }

  /* End of Switch: '<S15>/QAM On' */

  /* S-Function (scomqamdemod): '<S15>/Rectangular QAM Demodulator Baseband' */
  for (i = 0; i < 264; i++) {
    re = localB->QAMOn[i].re;
    im = localB->QAMOn[i].im;
    re *= (2.0 / localP->ReceiverPower);
	im *= (2.0 / localP->ReceiverPower);
    re += 3.0;
    im += 3.0;
    re /= 2.0;
    im /= 2.0;
    if (re < 0.0) {
      roundedNearest = ceil(re - 0.5);
    } else {
      roundedNearest = floor(re + 0.5);
    }

    if ((int32_T)roundedNearest >= 3) {
      inputIdx = 3;
    } else if (roundedNearest <= 0.0) {
      inputIdx = 0;
    } else {
      inputIdx = (int32_T)roundedNearest;
    }

    if (im < 0.0) {
      roundedNearest = ceil(im - 0.5);
    } else {
      roundedNearest = floor(im + 0.5);
    }

    if ((int32_T)roundedNearest >= 3) {
      j = 3;
    } else if (roundedNearest <= 0.0) {
      j = 0;
    } else {
      j = (int32_T)roundedNearest;
    }

    j = ((inputIdx << 2) - j) + 3;
    localB->RectangularQAMDemodulatorBaseba[i] = (uint8_T)j;
  }

  /* End of S-Function (scomqamdemod): '<S15>/Rectangular QAM Demodulator Baseband' */

  /* MultiPortSwitch: '<S15>/Multiport Switch' incorporates:
   *  Constant: '<S15>/Modulation Type'
   */
  if (localP->ModulationType_Value == 0) {
    memcpy(&localB->MultiportSwitch[0], &localB->
           RectangularQAMDemodulatorBaseba[0], 264U * sizeof(uint8_T));
  } else {
    memcpy(&localB->MultiportSwitch[0], &localB->MPSKDemodulatorBaseband[0],
           264U * sizeof(uint8_T));
  }

  /* End of MultiPortSwitch: '<S15>/Multiport Switch' */

  /* Gain: '<S21>/Vector in terms of Samples' */
  for (i = 0; i < 264; i++) {
    localB->VectorintermsofSamples[i] = localP->VectorintermsofSamples_Gain[i] *
      localB->Sum2;
  }

  /* End of Gain: '<S21>/Vector in terms of Samples' */
}

/*
 * Termination for atomic system:
 *    '<S5>/Receiver'
 *    '<S6>/Receiver'
 */
void PhysicalLayerMode_Receiver_Term(void)
{
}
