/*
 * Code generation for system system '<Root>/Statistics2'
 *
 * Model                      : PhysicalLayerModelUSRP
 * Model version              : 1.272
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Sun Sep 07 13:05:56 2014
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "PhysicalLayerModelU_Statistics2.h"

/* Include model header file for global data */
#include "PhysicalLayerModelUSRP.h"
#include "PhysicalLayerModelUSRP_private.h"

/* Initial conditions for atomic system: '<Root>/Statistics2' */
void PhysicalLayerM_Statistics2_Init(DW_Statistics2_PhysicalLayerM_T *localDW)
{
  int32_T i;

  /* InitializeConditions for S-Function (scomerrrate2): '<S6>/Error Rate Calculation' */
  localDW->errors = 0.0;
  localDW->symbols = 0.0;
  localDW->STDelay = 0;
  localDW->curTx = 0;
  for (i = 0; i < 264; i++) {
    localDW->useFrame[i] = TRUE;
  }

  /* End of InitializeConditions for S-Function (scomerrrate2): '<S6>/Error Rate Calculation' */
}

/* Start for atomic system: '<Root>/Statistics2' */
void PhysicalLayer_Statistics2_Start(RT_MODEL_PhysicalLayerModelUS_T * const
  PhysicalLayerModelUSRP_M, DW_Statistics2_PhysicalLayerM_T *localDW)
{
  /* Start for SignalToWorkspace: '<S6>/Error Vars' */
  {
    int_T dimensions[1] = { 3 };

    localDW->ErrorVars_PWORK.LoggedData = rt_CreateLogVar(
      PhysicalLayerModelUSRP_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(PhysicalLayerModelUSRP_M),
      PhysicalLayerModelUSRP_M->Timing.stepSize0,
      (&rtmGetErrorStatus(PhysicalLayerModelUSRP_M)),
      "ErrorVars2",
      SS_DOUBLE,
      0,
      0,
      0,
      3,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.00026399999999999997,
      1);
    if (localDW->ErrorVars_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for SignalToWorkspace: '<S6>/Rx2' */
  {
    int_T dimensions[2] = { 264, 1 };

    localDW->Rx2_PWORK.LoggedData = rt_CreateLogVar(
      PhysicalLayerModelUSRP_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(PhysicalLayerModelUSRP_M),
      PhysicalLayerModelUSRP_M->Timing.stepSize0,
      (&rtmGetErrorStatus(PhysicalLayerModelUSRP_M)),
      "Rx2",
      SS_UINT8,
      0,
      0,
      1,
      264,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.00026399999999999997,
      1);
    if (localDW->Rx2_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for SignalToWorkspace: '<S6>/Tx2' */
  {
    int_T dimensions[2] = { 264, 1 };

    localDW->Tx2_PWORK.LoggedData = rt_CreateLogVar(
      PhysicalLayerModelUSRP_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(PhysicalLayerModelUSRP_M),
      PhysicalLayerModelUSRP_M->Timing.stepSize0,
      (&rtmGetErrorStatus(PhysicalLayerModelUSRP_M)),
      "Tx2",
      SS_UINT8,
      0,
      0,
      1,
      264,
      2,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.00026399999999999997,
      1);
    if (localDW->Tx2_PWORK.LoggedData == (NULL))
      return;
  }
}

/* Output and update for atomic system: '<Root>/Statistics2' */
void PhysicalLayerModelU_Statistics2(const uint8_T rtu_Tx[264], const uint8_T
  rtu_Rx[264], B_Statistics2_PhysicalLayerMo_T *localB,
  DW_Statistics2_PhysicalLayerM_T *localDW)
{
  real_T err;
  real_T sym;
  real_T ratio;
  int32_T idx;
  boolean_T cur_fr;
  int32_T txIdx;
  uint8_T ru;

  /* S-Function (scomerrrate2): '<S6>/Error Rate Calculation' */
  err = 0.0;
  sym = 0.0;
  ratio = 0.0;
  for (idx = 0; idx < 264; idx++) {
    txIdx = localDW->curTx;
    localDW->txBuff[txIdx] = rtu_Tx[idx];
    cur_fr = localDW->useFrame[idx];
    if (localDW->curTx == 8) {
      localDW->curTx = 0;
    } else {
      localDW->curTx++;
    }

    if (localDW->STDelay < 8) {
      localDW->STDelay++;
    } else {
      if (cur_fr) {
        ru = rtu_Rx[idx];
        sym++;
        if (localDW->txBuff[localDW->curTx] != ru) {
          err++;
        }
      }
    }
  }

  localDW->symbols += sym;
  localDW->errors += err;
  if (localDW->symbols > 0.0) {
    ratio = localDW->errors / localDW->symbols;
  }

  localB->ErrorRateCalculation[0U] = ratio;
  localB->ErrorRateCalculation[1U] = localDW->errors;
  localB->ErrorRateCalculation[2U] = localDW->symbols;

  /* End of S-Function (scomerrrate2): '<S6>/Error Rate Calculation' */

  /* SignalToWorkspace: '<S6>/Error Vars' */
  rt_UpdateLogVar((LogVar *)(LogVar*) (localDW->ErrorVars_PWORK.LoggedData),
                  &localB->ErrorRateCalculation[0], 0);

  /* SignalToWorkspace: '<S6>/Rx2' */
  rt_UpdateLogVar((LogVar *)(LogVar*) (localDW->Rx2_PWORK.LoggedData), &rtu_Rx[0],
                  0);

  /* SignalToWorkspace: '<S6>/Tx2' */
  rt_UpdateLogVar((LogVar *)(LogVar*) (localDW->Tx2_PWORK.LoggedData), &rtu_Tx[0],
                  0);
}

/* Termination for atomic system: '<Root>/Statistics2' */
void PhysicalLayerM_Statistics2_Term(void)
{
}
