/*
 * Code generation for system system '<Root>/Channel1'
 *
 * Model                      : PhysicalLayerModel
 * Model version              : 1.254
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C++ source code generated on : Fri Jul 25 20:13:46 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModel_Channel1.h"

/* Include model header file for global data */
#include "PhysicalLayerModel.h"
#include "PhysicalLayerModel_private.h"

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S9>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    state[i << 1] = 362436069U;
    state[(i << 1) + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S9>/Random Source' */
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

void RandSrc_GZ_D(real_T y[], const real_T mean[], int32_T meanLen, const real_T
                  xstd[], int32_T xstdLen, uint32_T state[], int32_T nChans,
                  int32_T nSamps)
{
  int32_T i;
  int32_T j;
  real_T r;
  real_T x;
  real_T s;
  real_T y_0;
  int32_T chan;
  real_T std;
  uint32_T icng;
  uint32_T jsr;
  int32_T samp;
  real_T mean_0;
  static const real_T vt[65] = { 0.340945, 0.4573146, 0.5397793, 0.6062427,
    0.6631691, 0.7136975, 0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948,
    0.9490791, 0.9820005, 1.0138492, 1.044781, 1.0749254, 1.1043917, 1.1332738,
    1.161653, 1.189601, 1.2171815, 1.2444516, 1.2714635, 1.298265, 1.3249008,
    1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915, 1.4834527, 1.5100122,
    1.5367061, 1.5635712, 1.5906454, 1.617968, 1.6455802, 1.6735255, 1.7018503,
    1.7306045, 1.7598422, 1.7896223, 1.8200099, 1.851077, 1.8829044, 1.9155831,
    1.9492166, 1.9839239, 2.0198431, 2.0571356, 2.095993, 2.136645, 2.1793713,
    2.2245175, 2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658,
    2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942 };

  /* S-Function (sdsprandsrc2): '<S9>/Random Source' */
  /* RandSrc_GZ_D */
  for (chan = 0; chan < nChans; chan++) {
    mean_0 = mean[meanLen > 1 ? chan : 0];
    std = xstd[xstdLen > 1 ? chan : 0];
    icng = state[chan << 1];
    jsr = state[(chan << 1) + 1];
    for (samp = 0; samp < nSamps; samp++) {
      icng = 69069U * icng + 1234567U;
      jsr ^= jsr << 13;
      jsr ^= jsr >> 17;
      jsr ^= jsr << 5;
      i = (int32_T)(icng + jsr);
      j = (i & 63) + 1;
      r = (real_T)i * 4.6566128730773926E-10 * vt[j];
      if (!(fabs(r) <= vt[j - 1])) {
        x = (fabs(r) - vt[j - 1]) / (vt[j] - vt[j - 1]);
        icng = 69069U * icng + 1234567U;
        jsr ^= jsr << 13;
        jsr ^= jsr >> 17;
        jsr ^= jsr << 5;
        i = (int32_T)(icng + jsr);
        y_0 = (real_T)i * 2.328306436538696E-10 + 0.5;
        s = x + y_0;
        if (s > 1.301198) {
          r = r < 0.0 ? 0.4878992 * x - 0.4878992 : 0.4878992 - 0.4878992 * x;
        } else {
          if (!(s <= 0.9689279)) {
            x = 0.4878992 - 0.4878992 * x;
            if (y_0 > 12.67706 - exp(-0.5 * x * x) * 12.37586) {
              r = r < 0.0 ? -x : x;
            } else {
              if (!(exp(-0.5 * vt[j] * vt[j]) + y_0 * 0.01958303 / vt[j] <= exp(
                    -0.5 * r * r))) {
                do {
                  icng = 69069U * icng + 1234567U;
                  jsr ^= jsr << 13;
                  jsr ^= jsr >> 17;
                  jsr ^= jsr << 5;
                  i = (int32_T)(icng + jsr);
                  y_0 = (real_T)i * 2.328306436538696E-10 + 0.5;
                  x = log(y_0) / 2.776994;
                  icng = 69069U * icng + 1234567U;
                  jsr ^= jsr << 13;
                  jsr ^= jsr >> 17;
                  jsr ^= jsr << 5;
                  i = (int32_T)(icng + jsr);
                  y_0 = (real_T)i * 2.328306436538696E-10 + 0.5;
                } while (-2.0 * log(y_0) <= x * x);

                r = r < 0.0 ? x - 2.776994 : 2.776994 - x;
              }
            }
          }
        }
      }

      y[chan * nSamps + samp] = std * r + mean_0;
    }

    state[chan << 1] = icng;
    state[(chan << 1) + 1] = jsr;
  }

  /* End of S-Function (sdsprandsrc2): '<S9>/Random Source' */
}

/* Initial conditions for atomic system: '<Root>/Channel1' */
void PhysicalLayerMode_Channel1_Init(DW_Channel1_PhysicalLayerMode_T *localDW,
  P_Channel1_PhysicalLayerModel_T *localP)
{
  real_T ten;

  /* InitializeConditions for S-Function (sdspsine2): '<S10>/Interferer Tone ' */
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

  /* End of InitializeConditions for S-Function (sdspsine2): '<S10>/Interferer Tone ' */

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S9>/Random Source' */
  localDW->RandomSource_SEED_DWORK = localP->RandomSource_InitSeed;
  RandSrcInitState_GZ(&localDW->RandomSource_SEED_DWORK,
                      localDW->RandomSource_STATE_DWORK, 1);

  /* InitializeConditions for S-Function (scomawgnchan2): '<S9>/Dynamic AWGN' */
  ten = localP->DynamicAWGN_SNR / 10.0;
  ten = rt_powd_snf(10.0, ten);
  ten = localP->DynamicAWGN_SPOW / ten;
  localDW->STDDEV = sqrt(ten);
}

/* Start for atomic system: '<Root>/Channel1' */
void PhysicalLayerMod_Channel1_Start(DW_Channel1_PhysicalLayerMode_T *localDW,
  P_Channel1_PhysicalLayerModel_T *localP)
{
  real_T arg;

  /* Start for S-Function (sdspsine2): '<S10>/Interferer Tone ' */
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

  /* End of Start for S-Function (sdspsine2): '<S10>/Interferer Tone ' */
}

/* Output and update for atomic system: '<Root>/Channel1' */
void PhysicalLayerModel_Channel1(const real_T rtu_ChannelIn[2112],
  B_Channel1_PhysicalLayerModel_T *localB, DW_Channel1_PhysicalLayerMode_T
  *localDW, P_Channel1_PhysicalLayerModel_T *localP)
{
  real_T updateVal;
  int32_T k;
  int32_T i;
  real_T u;

  /* SignalConversion: '<S11>/ConcatBufferAtMatrix ConcatenationIn1' */
  memcpy(&localB->MatrixConcatenation[0], &rtu_ChannelIn[0], 2112U * sizeof
         (real_T));

  /* S-Function (sdspsine2): '<S10>/Interferer Tone ' */
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
    /* ComplexToRealImag: '<S10>/Complex to Real-Imag' */
    localB->ComplextoRealImag[i] = localB->InterfererTone[i].re;

    /* Math: '<S10>/Math Function' incorporates:
     *  Constant: '<S10>/Constant'
     */
    updateVal = localB->ComplextoRealImag[i];
    u = localP->Constant_Value;
    if ((updateVal < 0.0) && (u > floor(u))) {
      updateVal = -rt_powd_snf(-updateVal, u);
    } else {
      updateVal = rt_powd_snf(updateVal, u);
    }

    localB->MathFunction[i] = updateVal;

    /* End of Math: '<S10>/Math Function' */

    /* Gain: '<S10>/Gain' */
    localB->Gain[i] = localP->Gain_Gain * localB->MathFunction[i];

    /* SignalConversion: '<S11>/ConcatBufferAtMatrix ConcatenationIn2' */
    localB->MatrixConcatenation[i + 2112] = localB->Gain[i];

    /* Sum: '<S1>/Add1' */
    localB->Add1[i] = rtu_ChannelIn[i] + localB->Gain[i];
  }

  /* End of S-Function (sdspsine2): '<S10>/Interferer Tone ' */

  /* S-Function (sdsprandsrc2): '<S9>/Random Source' */
  RandSrc_GZ_D(localB->RandomSource, &localP->RandomSource_MeanRTP, 1,
               &localP->RandomSource_VarianceRTP, 1,
               localDW->RandomSource_STATE_DWORK, 1, 2112);

  /* S-Function (scomawgnchan2): '<S9>/Dynamic AWGN' */
  for (i = 0; i < 2112; i++) {
    localB->DynamicAWGN[k] = localDW->STDDEV * localB->RandomSource[k];
    localB->DynamicAWGN[k] += localB->Add1[k];
    k++;
  }

  /* End of S-Function (scomawgnchan2): '<S9>/Dynamic AWGN' */
}

/* Termination for atomic system: '<Root>/Channel1' */
void PhysicalLayerMode_Channel1_Term(void)
{
}
