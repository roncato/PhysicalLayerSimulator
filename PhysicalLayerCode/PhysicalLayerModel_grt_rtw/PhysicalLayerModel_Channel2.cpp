/*
 * Code generation for system system '<Root>/Channel2'
 *
 * Model                      : PhysicalLayerModel
 * Model version              : 1.254
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C++ source code generated on : Fri Jul 25 20:13:46 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModel_Channel2.h"

/* Include model header file for global data */
#include "PhysicalLayerModel.h"
#include "PhysicalLayerModel_private.h"

/* Initial conditions for atomic system: '<Root>/Channel2' */
void PhysicalLayerMode_Channel2_Init(DW_Channel2_PhysicalLayerMode_T *localDW,
  P_Channel2_PhysicalLayerModel_T *localP)
{
  real_T ten;

  /* InitializeConditions for S-Function (sdspsine2): '<S13>/Interferer Tone ' */
  /* This code only executes when block is re-enabled in an
     enabled subsystem when the enabled subsystem states on
     re-enabling are set to 'Reset' */
  /* Reset to time zero on re-enable */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  for (ten = localP->InterfererTone_Phase; ten >= 6.2831853071795862; ten -=
       6.2831853071795862) {
  }

  while (ten < 0.0) {
    ten += 6.2831853071795862;
  }

  localDW->InterfererTone_AccFreqNorm = ten;

  /* End of InitializeConditions for S-Function (sdspsine2): '<S13>/Interferer Tone ' */

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S12>/Random Source' */
  localDW->RandomSource_SEED_DWORK = localP->RandomSource_InitSeed;
  RandSrcInitState_GZ(&localDW->RandomSource_SEED_DWORK,
                      localDW->RandomSource_STATE_DWORK, 1);

  /* InitializeConditions for S-Function (scomawgnchan2): '<S12>/Dynamic AWGN' */
  ten = localP->DynamicAWGN_SNR / 10.0;
  ten = rt_powd_snf(10.0, ten);
  ten = localP->DynamicAWGN_SPOW / ten;
  localDW->STDDEV = sqrt(ten);
}

/* Start for atomic system: '<Root>/Channel2' */
void PhysicalLayerMod_Channel2_Start(DW_Channel2_PhysicalLayerMode_T *localDW,
  P_Channel2_PhysicalLayerModel_T *localP)
{
  real_T arg;

  /* Start for S-Function (sdspsine2): '<S13>/Interferer Tone ' */
  /* Trigonometric mode: compute accumulated
     normalized trig fcn argument for each channel */
  /* Keep normalized value in range [0 2*pi) */
  for (arg = localP->InterfererTone_Phase; arg >= 6.2831853071795862; arg -=
       6.2831853071795862) {
  }

  while (arg < 0.0) {
    arg += 6.2831853071795862;
  }

  localDW->InterfererTone_AccFreqNorm = arg;

  /* End of Start for S-Function (sdspsine2): '<S13>/Interferer Tone ' */
}

/* Output and update for atomic system: '<Root>/Channel2' */
void PhysicalLayerModel_Channel2(const real_T rtu_ChannelIn[2112],
  B_Channel2_PhysicalLayerModel_T *localB, DW_Channel2_PhysicalLayerMode_T
  *localDW, P_Channel2_PhysicalLayerModel_T *localP)
{
  real_T updateVal;
  int32_T k;
  int32_T i;
  real_T u;

  /* SignalConversion: '<S14>/ConcatBufferAtMatrix ConcatenationIn1' */
  memcpy(&localB->MatrixConcatenation[0], &rtu_ChannelIn[0], 2112U * sizeof
         (real_T));

  /* S-Function (sdspsine2): '<S13>/Interferer Tone ' */
  updateVal = localP->InterfererTone_Frequency * 7.8539816339744812E-7;
  k = 0;
  for (i = 0; i < 2112; i++) {
    u = localDW->InterfererTone_AccFreqNorm;
    localB->InterfererTone[i].re = localP->InterfererTone_Amplitude * cos(u);
    localB->InterfererTone[i].im = localP->InterfererTone_Amplitude * sin(u);

    /* Update accumulated normalized freq value
       for next sample.  Keep in range [0 2*pi) */
    localDW->InterfererTone_AccFreqNorm += updateVal;
    if (localDW->InterfererTone_AccFreqNorm >= 6.2831853071795862) {
      localDW->InterfererTone_AccFreqNorm -= 6.2831853071795862;
    } else {
      if (localDW->InterfererTone_AccFreqNorm < 0.0) {
        localDW->InterfererTone_AccFreqNorm += 6.2831853071795862;
      }
    }
  }

  for (i = 0; i < 2112; i++) {
    /* ComplexToRealImag: '<S13>/Complex to Real-Imag' */
    localB->ComplextoRealImag[i] = localB->InterfererTone[i].re;

    /* Math: '<S13>/Math Function' incorporates:
     *  Constant: '<S13>/Constant'
     */
    updateVal = localB->ComplextoRealImag[i];
    u = localP->Constant_Value;
    if ((updateVal < 0.0) && (u > floor(u))) {
      updateVal = -rt_powd_snf(-updateVal, u);
    } else {
      updateVal = rt_powd_snf(updateVal, u);
    }

    localB->MathFunction[i] = updateVal;

    /* End of Math: '<S13>/Math Function' */

    /* Gain: '<S13>/Gain' */
    localB->Gain[i] = localP->Gain_Gain * localB->MathFunction[i];

    /* SignalConversion: '<S14>/ConcatBufferAtMatrix ConcatenationIn2' */
    localB->MatrixConcatenation[i + 2112] = localB->Gain[i];

    /* Sum: '<S2>/Add1' */
    localB->Add1[i] = rtu_ChannelIn[i] + localB->Gain[i];
  }

  /* End of S-Function (sdspsine2): '<S13>/Interferer Tone ' */

  /* S-Function (sdsprandsrc2): '<S12>/Random Source' */
  RandSrc_GZ_D(localB->RandomSource, &localP->RandomSource_MeanRTP, 1,
               &localP->RandomSource_VarianceRTP, 1,
               localDW->RandomSource_STATE_DWORK, 1, 2112);

  /* S-Function (scomawgnchan2): '<S12>/Dynamic AWGN' */
  for (i = 0; i < 2112; i++) {
    localB->DynamicAWGN[k] = localDW->STDDEV * localB->RandomSource[k];
    localB->DynamicAWGN[k] += localB->Add1[k];
    k++;
  }

  /* End of S-Function (scomawgnchan2): '<S12>/Dynamic AWGN' */
}

/* Termination for atomic system: '<Root>/Channel2' */
void PhysicalLayerMode_Channel2_Term(void)
{
}
