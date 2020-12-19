/*
 * Code generation for system system '<S3>/Receiver'
 *
 * Model                      : PhysicalLayerModelUSRP
 * Model version              : 1.272
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Sun Sep 07 13:05:56 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModelUSRP_Receiver.h"

/* Include model header file for global data */
#include "PhysicalLayerModelUSRP.h"
#include "PhysicalLayerModelUSRP_private.h"

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

    y = atan2(tmp_0, tmp);
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

  /* S-Function (sdspinterp): '<S18>/Interpolation' */
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

  /* End of S-Function (sdspinterp): '<S18>/Interpolation' */
}

/*
 * Start for atomic system:
 *    '<S3>/Receiver'
 *    '<S4>/Receiver'
 */
void PhysicalLayerMod_Receiver_Start(DW_Receiver_PhysicalLayerMode_T *localDW)
{
  int32_T i;

  /* start of code for: S-Function (usrp_uhd_sfunrx): <S10>/usrp_uhd_sfunrx */
  {
    char newip[1024];
    size_t dhnlen;
    strncpy((char *)&localDW->usrp_uhd_sfunrx_work1[0],
            "PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/usrp_uhd_sfunrx",
            1024);
    dhnlen = strlen("EngDev:192.168.10.2");
    strncpy(newip, "EngDev:192.168.10.2", 1024);
    openDataConnection_c( newip, (BoardIdCapiEnumT)
                         PhysicalLayerModelUSRP_ConstP.pooled11, (char *)
                         &localDW->usrp_uhd_sfunrx_work1[0], (uint32_T)
                         PhysicalLayerModelUSRP_ConstP.pooled8,
                         (DataPortDataTypeCapiEnumT)
                         PhysicalLayerModelUSRP_ConstP.pooled13, (boolean_T)
                         PhysicalLayerModelUSRP_ConstP.pooled16, (uint32_T)
                         PhysicalLayerModelUSRP_ConstP.pooled9,
                         &localDW->usrp_uhd_sfunrx_work4,
                         &localDW->usrp_uhd_sfunrx_work2, (char *)
                         &localDW->usrp_uhd_sfunrx_work3[0]);
    if (*&localDW->usrp_uhd_sfunrx_work2 != UsrpDriverSuccess) {
      fprintf(stderr, "%s\n", (char *) &localDW->usrp_uhd_sfunrx_work3[0]);
      exit(-1);
    }
  }                                    /* end of code for: S-Function (usrp_uhd_sfunrx): <S10>/usrp_uhd_sfunrx */

  /* InitializeConditions for Enabled SubSystem: '<S7>/Decoder' */
  /* InitializeConditions for S-Function (sdspfirdn2): '<S13>/FIR Decimation' */
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

  /* End of InitializeConditions for S-Function (sdspfirdn2): '<S13>/FIR Decimation' */
  /* End of InitializeConditions for SubSystem: '<S7>/Decoder' */
}

/*
 * Output and update for atomic system:
 *    '<S3>/Receiver'
 *    '<S4>/Receiver'
 */
void PhysicalLayerModelUSRP_Receiver(B_Receiver_PhysicalLayerModel_T *localB,
  DW_Receiver_PhysicalLayerMode_T *localDW, P_Receiver_PhysicalLayerModel_T
  *localP)
{
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

  /* S-Function (usrp_uhd_sfunrx): '<S10>/usrp_uhd_sfunrx' */
  receiveData_c( localDW->usrp_uhd_sfunrx_work4, (real_T)localP->port_1_Value,
                (real_T)localP->port_2_Value,
                (real_T)localP->port_3_Value, (real_T)localP->port_4_Value,
                &localB->usrp_uhd_sfunrx_o1[0], &localB->usrp_uhd_sfunrx_o2,
                &localB->usrp_uhd_sfunrx_o3, &localDW->usrp_uhd_sfunrx_work2,
                (char *) &localDW->usrp_uhd_sfunrx_work3[0]);
  if (*&localDW->usrp_uhd_sfunrx_work2 != UsrpDriverSuccess) {
    fprintf(stderr, "%s\n", (char *) &localDW->usrp_uhd_sfunrx_work3[0]);
    exit(-1);
  }

  /* Gain: '<S10>/Gain' */
  for (i = 0; i < 2112; i++) {
    localB->Gain[i].re = localP->Gain_Gain_ima5v * (real_T)
      localB->usrp_uhd_sfunrx_o1[i].re;
    localB->Gain[i].im = localP->Gain_Gain_ima5v * (real_T)
      localB->usrp_uhd_sfunrx_o1[i].im;
  }

  /* End of Gain: '<S10>/Gain' */

  /* Outputs for Enabled SubSystem: '<S7>/Decoder' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (localB->usrp_uhd_sfunrx_o2 > 0U) {
    /* S-Function (sdspfirdn2): '<S13>/FIR Decimation' */
    inputIdx = 0;
    curBuf = localDW->FIRDecimation_wrtBufIdx;
    phaseIdx = localDW->FIRDecimation_PhaseIdx;
    curTapIdx = localDW->FIRDecimation_TapDelayIndex;
    outIdx = localDW->FIRDecimation_OutIdx;
    cffIdx = localDW->FIRDecimation_CoeffIdx;
    for (i = 0; i < 2112; i++) {
      tapIdx = curTapIdx;
      localDW->FIRDecimation_StatesBuff[tapIdx] = localB->Gain[inputIdx];
      inputIdx++;
      for (j = 0; j < 65; j++) {
        localDW->FIRDecimation_Sums.re += localDW->
          FIRDecimation_StatesBuff[tapIdx].re *
          PhysicalLayerModelUSRP_ConstP.pooled1[cffIdx];
        localDW->FIRDecimation_Sums.im += localDW->
          FIRDecimation_StatesBuff[tapIdx].im *
          PhysicalLayerModelUSRP_ConstP.pooled1[cffIdx];
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
      memcpy(&localB->FIRDecimation[0], &localDW->FIRDecimation_OutBuff[0],
             2112U * sizeof(creal_T));
    }

    localDW->FIRDecimation_readBufIdx = !localDW->FIRDecimation_readBufIdx;
    for (i = 0; i < 2112; i++) {
      /* ComplexToRealImag: '<S18>/Complex to Real-Imag2' */
      localB->ComplextoRealImag2_o1[i] = localB->FIRDecimation[i].re;
      localB->ComplextoRealImag2_o2[i] = localB->FIRDecimation[i].im;

      /* Math: '<S17>/Math Function'
       *
       * About '<S17>/Math Function':
       *  Operator: magnitude^2
       */
      u = localB->FIRDecimation[i];
      re = u.re * u.re + u.im * u.im;
      localB->MathFunction[i] = re;

      /* Gain: '<S17>/Sensitivity3' */
      localB->Sensitivity3[i].re = localP->Sensitivity3_Gain[i].re *
        localB->MathFunction[i];
      localB->Sensitivity3[i].im = localP->Sensitivity3_Gain[i].im *
        localB->MathFunction[i];
    }

    /* End of S-Function (sdspfirdn2): '<S13>/FIR Decimation' */

    /* Sum: '<S17>/Sum' */
    re = localB->Sensitivity3[0].re;
    im = localB->Sensitivity3[0].im;
    for (j = 0; j < 2111; j++) {
      inputIdx = j + 1;
      re += localB->Sensitivity3[inputIdx].re;
      im += localB->Sensitivity3[inputIdx].im;
    }

    localB->Sum.re = re;
    localB->Sum.im = im;

    /* End of Sum: '<S17>/Sum' */

    /* ComplexToMagnitudeAngle: '<S17>/Complex to Magnitude-Angle' */
    localB->ComplextoMagnitudeAngle = rt_atan2d_snf(localB->Sum.im,
      localB->Sum.re);

    /* Gain: '<S17>/Sensitivity1' */
    localB->Sensitivity1 = localP->Sensitivity1_Gain *
      localB->ComplextoMagnitudeAngle;

    /* Abs: '<S19>/Abs' */
    localB->Abs = fabs(localB->Sensitivity1);

    /* If: '<S19>/If' incorporates:
     *  Inport: '<S21>/In1'
     */
    if (localB->Abs < 0.0625) {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* Gain: '<S20>/Set to zero' */
      localB->Merge = localP->Settozero_Gain * localB->Sensitivity1;

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S19>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      localB->Merge = localB->Sensitivity1;

      /* End of Outputs for SubSystem: '<S19>/If Action Subsystem1' */
    }

    /* End of If: '<S19>/If' */

    /* Fcn: '<S19>/Fcn' */
    localB->Fcn = (localB->Merge < 0.0);

    /* Sum: '<S19>/Sum2' */
    localB->Sum2 = localB->Merge + localB->Fcn;
    for (i = 0; i < 264; i++) {
      /* Sum: '<S16>/Sum' incorporates:
       *  Constant: '<S16>/Constant'
       */
      localB->Sum_hha5s[i] = localB->Sum2 + localP->Constant_Value[i];

      /* Gain: '<S16>/Gain' */
      localB->Gain_nyex1[i] = localP->Gain_Gain * localB->Sum_hha5s[i];

      /* Sum: '<S16>/Sum1' incorporates:
       *  Constant: '<S16>/Constant1'
       */
      localB->Sum1[i] = localB->Gain_nyex1[i] + localP->Constant1_Value;
    }

    /* S-Function (sdspinterp): '<S18>/Interpolation' */
    interpBilinear_MultiChan_real_T(&localB->Interpolation[0U],
      &localB->ComplextoRealImag2_o1[0U], &localB->Sum1[0U], 2112, 1, 264);

    /* S-Function (sdspinterp): '<S18>/Interpolation1' */
    interpBilinear_MultiChan_real_T(&localB->Interpolation1[0U],
      &localB->ComplextoRealImag2_o2[0U], &localB->Sum1[0U], 2112, 1, 264);

    /* RelationalOperator: '<S11>/Compare' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S9>/Modulation Type'
     */
    localB->Compare = (uint8_T)(localP->ModulationType_Value ==
      localP->Constant_Value_jhhlt);
    for (i = 0; i < 264; i++) {
      /* RealImagToComplex: '<S18>/Real-Imag to Complex' */
      localB->RealImagtoComplex[i].re = localB->Interpolation[i];
      localB->RealImagtoComplex[i].im = localB->Interpolation1[i];

      /* Switch: '<S9>/PSK On' */
      if (localB->Compare > localP->PSKOn_Threshold) {
        localB->PSKOn[i] = localB->RealImagtoComplex[i];
      } else {
        localB->PSKOn[i] = PhysicalLayerModelUSRP_RGND_Complex;
      }

      /* End of Switch: '<S9>/PSK On' */

      /* Gain: '<S9>/PSK Gain' */
      localB->PSKGain[i].re = localP->PSKGain_Gain * localB->PSKOn[i].re;
      localB->PSKGain[i].im = localP->PSKGain_Gain * localB->PSKOn[i].im;
    }

    /* S-Function (scompskdemod): '<S9>/M-PSK Demodulator Baseband' */
    for (j = 0; j < 264; j++) {
      re = localB->PSKGain[j].re * 0.98078530365980221 - localB->PSKGain[j].im *
        -0.1950902050974104;
      im = localB->PSKGain[j].re * -0.1950902050974104 + localB->PSKGain[j].im *
        0.98078530365980221;
      re = rt_atan2d_snf(im, re);
      re = re * 16.0 / 6.2831853071795862;
      if (re < 0.0) {
        cffIdx = (int32_T)ceil(re - 0.5);
      } else {
        cffIdx = (int32_T)floor(re + 0.5);
      }

      if (cffIdx < 0) {
        cffIdx += 16;
      }

      phaseIdx = cffIdx >> 1;
      phaseIdx ^= cffIdx;
      localB->MPSKDemodulatorBaseband[j] = (uint8_T)phaseIdx;
    }

    /* End of S-Function (scompskdemod): '<S9>/M-PSK Demodulator Baseband' */

    /* RelationalOperator: '<S12>/Compare' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S9>/Modulation Type'
     */
    localB->Compare_fjcnv = (uint8_T)(localP->ModulationType_Value ==
      localP->Constant_Value_puofi);

    /* Switch: '<S9>/QAM On' */
    for (i = 0; i < 264; i++) {
      if (localB->Compare_fjcnv > localP->QAMOn_Threshold) {
        localB->QAMOn[i] = localB->RealImagtoComplex[i];
      } else {
        localB->QAMOn[i] = PhysicalLayerModelUSRP_RGND_Complex;
      }
    }

    /* End of Switch: '<S9>/QAM On' */

    /* S-Function (scomqamdemod): '<S9>/Rectangular QAM Demodulator Baseband' */
    for (i = 0; i < 264; i++) {
      re = localB->QAMOn[i].re;
      im = localB->QAMOn[i].im;
      re *= 2.0;
      im *= 2.0;
      re += 3.0;
      im += 3.0;
      re /= 2.0;
      im /= 2.0;
      if (re < 0.0) {
        re = ceil(re - 0.5);
      } else {
        re = floor(re + 0.5);
      }

      if ((int32_T)re >= 3) {
        phaseIdx = 3;
      } else if (re <= 0.0) {
        phaseIdx = 0;
      } else {
        phaseIdx = (int32_T)re;
      }

      if (im < 0.0) {
        re = ceil(im - 0.5);
      } else {
        re = floor(im + 0.5);
      }

      if ((int32_T)re >= 3) {
        tapIdx = 3;
      } else if (re <= 0.0) {
        tapIdx = 0;
      } else {
        tapIdx = (int32_T)re;
      }

      j = ((phaseIdx << 2) - tapIdx) + 3;
      localB->RectangularQAMDemodulatorBaseba[i] = (uint8_T)j;
    }

    /* End of S-Function (scomqamdemod): '<S9>/Rectangular QAM Demodulator Baseband' */

    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/Modulation Type'
     */
    if (localP->ModulationType_Value == 0) {
      memcpy(&localB->MultiportSwitch[0],
             &localB->RectangularQAMDemodulatorBaseba[0], 264U * sizeof(uint8_T));
    } else {
      memcpy(&localB->MultiportSwitch[0], &localB->MPSKDemodulatorBaseband[0],
             264U * sizeof(uint8_T));
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

    /* Gain: '<S14>/Vector in terms of Samples' */
    for (i = 0; i < 264; i++) {
      localB->VectorintermsofSamples[i] = localP->VectorintermsofSamples_Gain[i]
        * localB->Sum2;
    }

    /* End of Gain: '<S14>/Vector in terms of Samples' */
  }

  /* End of Outputs for SubSystem: '<S7>/Decoder' */
}

/*
 * Termination for atomic system:
 *    '<S3>/Receiver'
 *    '<S4>/Receiver'
 */
void PhysicalLayerMode_Receiver_Term(DW_Receiver_PhysicalLayerMode_T *localDW)
{
  /* S-Function (usrp_uhd_sfunrx): <S10>/usrp_uhd_sfunrx */
  closeDataConnection_c( localDW->usrp_uhd_sfunrx_work4,
                        &localDW->usrp_uhd_sfunrx_work2, (char *)
                        &localDW->usrp_uhd_sfunrx_work3[0]);
  if (*&localDW->usrp_uhd_sfunrx_work2 != UsrpDriverSuccess) {
    fprintf(stderr, "%s\n", (char *) &localDW->usrp_uhd_sfunrx_work3[0]);
    exit(-1);
  }
}
