/*
 * Code generation for system system '<S3>/Transmitter'
 *
 * Model                      : PhysicalLayerModelUSRP
 * Model version              : 1.272
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Sun Sep 07 13:05:56 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModelU_Transmitter.h"

/* Include model header file for global data */
#include "PhysicalLayerModelUSRP.h"
#include "PhysicalLayerModelUSRP_private.h"

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

  /* S-Function (sdspupfir2): '<S24>/FIR Interpolation' */
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

  /* End of S-Function (sdspupfir2): '<S24>/FIR Interpolation' */
}

/*
 * Initial conditions for atomic system:
 *    '<S3>/Transmitter'
 *    '<S4>/Transmitter'
 */
void PhysicalLayerM_Transmitter_Init(DW_Transmitter_PhysicalLayerM_T *localDW)
{
  int32_T buffIdx;
  int32_T i;

  /* InitializeConditions for S-Function (sdspupfir2): '<S24>/FIR Interpolation' */
  localDW->FIRInterpolation_TapDelayIndex = 0;
  for (i = 0; i < 9; i++) {
    localDW->FIRInterpolation_TapDelayBuff[i].re = 0.0;
    localDW->FIRInterpolation_TapDelayBuff[i].im = 0.0;
  }

  /* End of InitializeConditions for S-Function (sdspupfir2): '<S24>/FIR Interpolation' */

  /* InitializeConditions for S-Function (sdspvdly2): '<S8>/Variable Fractional Delay' */
  localDW->VariableFractionalDelay_BUFF_OF = 4;
  buffIdx = 0;
  for (i = 0; i < 5; i++) {
    localDW->VariableFractionalDelay_BUFF[buffIdx].re = 0.0;
    localDW->VariableFractionalDelay_BUFF[buffIdx].im = 0.0;
    buffIdx++;
  }

  /* End of InitializeConditions for S-Function (sdspvdly2): '<S8>/Variable Fractional Delay' */
}

/*
 * Start for atomic system:
 *    '<S3>/Transmitter'
 *    '<S4>/Transmitter'
 */
void PhysicalLayer_Transmitter_Start(DW_Transmitter_PhysicalLayerM_T *localDW)
{
  /* S-Function (usrp_uhd_sfuntx): <S25>/usrp_uhd_sfuntx */
  {
    char newip[1024];
    size_t dhnlen;
    strncpy((char *)&localDW->usrp_uhd_sfuntx_work1[0],
            "PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter/usrp_uhd_sfuntx",
            1024);
    dhnlen = strlen("EngDev:192.168.10.2");
    strncpy(newip, "EngDev:192.168.10.2", 1024);
    *&localDW->usrp_uhd_sfuntx_work5 = 2112;
    *&localDW->usrp_uhd_sfuntx_work6 = (1==1) ? DPortDTypeCDouble :
      DPortDTypeDouble;
    openDataConnection_c( newip, (BoardIdCapiEnumT)
                         PhysicalLayerModelUSRP_ConstP.pooled12, (char *)
                         &localDW->usrp_uhd_sfuntx_work1[0], (uint32_T)
                         PhysicalLayerModelUSRP_ConstP.pooled10,
                         (DataPortDataTypeCapiEnumT)
                         PhysicalLayerModelUSRP_ConstP.pooled14, (boolean_T)
                         PhysicalLayerModelUSRP_ConstP.pooled16, (uint32_T)
                         PhysicalLayerModelUSRP_ConstP.pooled9,
                         &localDW->usrp_uhd_sfuntx_work4,
                         &localDW->usrp_uhd_sfuntx_work2, (char *)
                         &localDW->usrp_uhd_sfuntx_work3[0]);
    if (*&localDW->usrp_uhd_sfuntx_work2 != UsrpDriverSuccess) {
      fprintf(stderr, "%s\n", (char *) &localDW->usrp_uhd_sfuntx_work3[0]);
      exit(-1);
    }
  }

  /* end of code for  S-Function (usrp_uhd_sfuntx): <S25>/usrp_uhd_sfuntx */
}

/*
 * Output and update for atomic system:
 *    '<S3>/Transmitter'
 *    '<S4>/Transmitter'
 */
void PhysicalLayerModelU_Transmitter(const uint8_T rtu_TransmitterIn[264],
  B_Transmitter_PhysicalLayerMo_T *localB, DW_Transmitter_PhysicalLayerM_T
  *localDW, P_Transmitter_PhysicalLayerMo_T *localP)
{
  int32_T inIdx;
  int32_T outIdx;
  uint8_T u;
  int32_T ti;
  real_T accum;
  int32_T buffstart;
  int32_T samp;
  int32_T i;
  real_T accumIn_re;
  real_T accumIn_im;

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S23>/Constant'
   *  Constant: '<S8>/Modulation Type'
   */
  localB->Compare = (uint8_T)(localP->ModulationType_Value ==
    localP->Constant_Value);

  /* Switch: '<S8>/QAM On' */
  for (i = 0; i < 264; i++) {
    if (localB->Compare > localP->QAMOn_Threshold) {
      localB->QAMOn[i] = rtu_TransmitterIn[i];
    } else {
      localB->QAMOn[i] = ((uint8_T)0U);
    }
  }

  /* End of Switch: '<S8>/QAM On' */

  /* S-Function (scomapskmod4): '<S8>/Rectangular QAM Modulator Baseband' */
  inIdx = 0;
  outIdx = 0;
  for (i = 0; i < 264; i++) {
    u = localB->QAMOn[inIdx];
    inIdx++;
    ti = u;
    localB->RectangularQAMModulatorBaseband[outIdx].re =
      PhysicalLayerModelUSRP_ConstP.pooled5[ti << 1];
    localB->RectangularQAMModulatorBaseband[outIdx].im =
      PhysicalLayerModelUSRP_ConstP.pooled5[(ti << 1) + 1];
    outIdx++;
  }

  /* End of S-Function (scomapskmod4): '<S8>/Rectangular QAM Modulator Baseband' */

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S8>/Modulation Type'
   */
  localB->Compare_fxhmg = (uint8_T)(localP->ModulationType_Value ==
    localP->Constant_Value_lrtfa);

  /* Switch: '<S8>/PSK On' */
  for (i = 0; i < 264; i++) {
    if (localB->Compare_fxhmg > localP->PSKOn_Threshold) {
      localB->PSKOn[i] = rtu_TransmitterIn[i];
    } else {
      localB->PSKOn[i] = ((uint8_T)0U);
    }
  }

  /* End of Switch: '<S8>/PSK On' */

  /* S-Function (scomapskmod4): '<S8>/M-PSK Modulator Baseband' */
  inIdx = 0;
  outIdx = 0;
  for (i = 0; i < 264; i++) {
    u = localB->PSKOn[inIdx];
    inIdx++;
    ti = u;
    for (buffstart = 1; buffstart < 4; buffstart += buffstart) {
      samp = ti >> buffstart;
      ti ^= samp;
    }

    localB->MPSKModulatorBaseband[outIdx].re =
      PhysicalLayerModelUSRP_ConstP.pooled6[ti << 1];
    localB->MPSKModulatorBaseband[outIdx].im =
      PhysicalLayerModelUSRP_ConstP.pooled6[(ti << 1) + 1];
    outIdx++;
  }

  /* End of S-Function (scomapskmod4): '<S8>/M-PSK Modulator Baseband' */

  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Constant: '<S8>/Modulation Type'
   */
  if (localP->ModulationType_Value == 0) {
    memcpy(&localB->MultiportSwitch[0], &localB->
           RectangularQAMModulatorBaseband[0], 264U * sizeof(creal_T));
  } else {
    /* Gain: '<S8>/PSK Gain' */
    for (i = 0; i < 264; i++) {
      localB->PSKGain[i].re = localP->PSKGain_Gain *
        localB->MPSKModulatorBaseband[i].re;
      localB->PSKGain[i].im = localP->PSKGain_Gain *
        localB->MPSKModulatorBaseband[i].im;
      localB->MultiportSwitch[i] = localB->PSKGain[i];
    }

    /* End of Gain: '<S8>/PSK Gain' */
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* S-Function (sdspupfir2): '<S24>/FIR Interpolation' */
  UpFIR_DF_Z_D(localB->MultiportSwitch, localP->FIRInterpolation_FILTER_COEFF,
               localDW->FIRInterpolation_TapDelayBuff, localB->FIRInterpolation,
               &localDW->FIRInterpolation_TapDelayIndex, 0, 1, 264, 8, 9);

  /* S-Function (sdspvdly2): '<S8>/Variable Fractional Delay' incorporates:
   *  Constant: '<S8>/Delay Factor'
   */
  i = (int32_T)floor(localP->DelayFactor_Value);
  if (i < 0) {
    i = 0;
    accum = 0.0;
  } else if (i >= 4) {
    i = 4;
    accum = 0.0;
  } else {
    accum = localP->DelayFactor_Value;
    accum -= (real_T)i;
  }

  inIdx = 0;
  outIdx = 0;
  buffstart = localDW->VariableFractionalDelay_BUFF_OF;
  for (samp = 0; samp < 2112; samp++) {
    if (buffstart == 5) {
      buffstart = 0;
    }

    localDW->VariableFractionalDelay_BUFF[buffstart] = localB->
      FIRInterpolation[inIdx];
    inIdx++;
    ti = i;
    ti = buffstart - ti;
    if (ti < 0) {
      ti += 5;
    }

    if (ti > 0) {
      accumIn_re = localDW->VariableFractionalDelay_BUFF[ti - 1].re;
      accumIn_im = localDW->VariableFractionalDelay_BUFF[ti - 1].im;
    } else {
      accumIn_re = localDW->VariableFractionalDelay_BUFF[ti + 4].re;
      accumIn_im = localDW->VariableFractionalDelay_BUFF[ti + 4].im;
    }

    accumIn_re -= localDW->VariableFractionalDelay_BUFF[ti].re;
    accumIn_im -= localDW->VariableFractionalDelay_BUFF[ti].im;
    accumIn_re *= accum;
    accumIn_im *= accum;
    accumIn_re += localDW->VariableFractionalDelay_BUFF[ti].re;
    accumIn_im += localDW->VariableFractionalDelay_BUFF[ti].im;
    localB->VariableFractionalDelay[outIdx].re = accumIn_re;
    localB->VariableFractionalDelay[outIdx].im = accumIn_im;
    outIdx++;
    buffstart++;
  }

  localDW->VariableFractionalDelay_BUFF_OF += 2112;
  while (localDW->VariableFractionalDelay_BUFF_OF >= 5) {
    localDW->VariableFractionalDelay_BUFF_OF -= 5;
  }

  /* End of S-Function (sdspvdly2): '<S8>/Variable Fractional Delay' */

  /* S-Function (usrp_uhd_sfuntx): '<S25>/usrp_uhd_sfuntx' */
  sendData_c( localDW->usrp_uhd_sfuntx_work4, (void*)
             &localB->VariableFractionalDelay[0], (real_T)localP->port_1_Value,
             (real_T)localP->port_2_Value, (real_T)localP->port_3_Value, (real_T)
             localP->port_4_Value, &localB->usrp_uhd_sfuntx,
             &localDW->usrp_uhd_sfuntx_work2, (char *)
             &localDW->usrp_uhd_sfuntx_work3[0]);
  if (*&localDW->usrp_uhd_sfuntx_work2 != UsrpDriverSuccess) {
    fprintf(stderr, "%s\n", (char *) &localDW->usrp_uhd_sfuntx_work3[0]);
    exit(-1);
  }
}

/*
 * Termination for atomic system:
 *    '<S3>/Transmitter'
 *    '<S4>/Transmitter'
 */
void PhysicalLayerM_Transmitter_Term(DW_Transmitter_PhysicalLayerM_T *localDW)
{
  /* S-Function (usrp_uhd_sfuntx): <S25>/usrp_uhd_sfuntx */
  closeDataConnection_c( localDW->usrp_uhd_sfuntx_work4,
                        &localDW->usrp_uhd_sfuntx_work2, (char *)
                        &localDW->usrp_uhd_sfuntx_work3[0]);
  if (*&localDW->usrp_uhd_sfuntx_work2 != UsrpDriverSuccess) {
    fprintf(stderr, "%s\n", (char *) &localDW->usrp_uhd_sfuntx_work3[0]);
    exit(-1);
  }
}
