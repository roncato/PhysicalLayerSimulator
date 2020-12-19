/*
 * PhysicalLayerModel.cpp
 *
 * Code generation for model "PhysicalLayerModel".
 *
 * Model version              : 1.254
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C++ source code generated on : Fri Jul 25 20:13:46 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Specified
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objective: Debugging
 * Validation result: All passed
 */
#include "rt_logging_mmi.h"
#include "PhysicalLayerModel_capi.h"
#include "PhysicalLayerModel.h"
#include "PhysicalLayerModel_private.h"

const creal_T PhysicalLayerModel_RGND_Complex = { 0.0, 0.0 };/* real_T complex ground */

/* Model step function */
void PhysicalLayerModel_step(RT_MODEL_PhysicalLayerModel_T *const
  PhysicalLayerModel_M)
{
  P_PhysicalLayerModel_T *PhysicalLayerModel_P = ((P_PhysicalLayerModel_T *)
    PhysicalLayerModel_M->ModelData.defaultParam);
  B_PhysicalLayerModel_T *PhysicalLayerModel_B = ((B_PhysicalLayerModel_T *)
    PhysicalLayerModel_M->ModelData.blockIO);
  DW_PhysicalLayerModel_T *PhysicalLayerModel_DW = ((DW_PhysicalLayerModel_T *)
    PhysicalLayerModel_M->ModelData.dwork);

  /* FromWorkspace: '<S3>/From Workspace' */
  {
    int_T currIndex = PhysicalLayerModel_DW->FromWorkspace_IWORK.PrevIndex+1;
    uint8_T *pDataValues = (uint8_T *)
      PhysicalLayerModel_DW->FromWorkspace_PWORK.DataPtr;
    if (currIndex >= 1) {
      currIndex = 0;
    }

    if (currIndex < 1) {
      pDataValues += currIndex;

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModel_B->FromWorkspace[0])[elIdx] = *pDataValues;
          pDataValues += 1;
        }
      }
    } else {
      pDataValues += (0);

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModel_B->FromWorkspace[0])[elIdx] = *pDataValues;
          pDataValues += 1;
        }
      }
    }

    PhysicalLayerModel_DW->FromWorkspace_IWORK.PrevIndex = currIndex;
  }

  /* Outputs for Atomic SubSystem: '<S5>/Transmitter' */
  PhysicalLayerModel_Transmitter(PhysicalLayerModel_B->FromWorkspace,
    &PhysicalLayerModel_B->Transmitter, &PhysicalLayerModel_DW->Transmitter,
    (P_Transmitter_PhysicalLayerMo_T *)&PhysicalLayerModel_P->Transmitter);

  /* End of Outputs for SubSystem: '<S5>/Transmitter' */

  /* Outputs for Atomic SubSystem: '<Root>/Channel1' */
  PhysicalLayerModel_Channel
    (PhysicalLayerModel_B->Transmitter.ComplextoRealImag,
     &PhysicalLayerModel_B->Channel1, &PhysicalLayerModel_DW->Channel1,
     (P_Channel_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Channel1);

  /* End of Outputs for SubSystem: '<Root>/Channel1' */

  /* Outputs for Atomic SubSystem: '<S6>/Receiver' */
  PhysicalLayerModel_Receiver(PhysicalLayerModel_B->Channel1.DynamicAWGN,
    &PhysicalLayerModel_B->Receiver, &PhysicalLayerModel_DW->Receiver,
    (P_Receiver_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Receiver);

  /* End of Outputs for SubSystem: '<S6>/Receiver' */

  /* Outputs for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayerModel_Statistics(PhysicalLayerModel_B->FromWorkspace,
    PhysicalLayerModel_B->Receiver.RectangularQAMDemodulatorBaseba,
    &PhysicalLayerModel_B->Statistics1, &PhysicalLayerModel_DW->Statistics1);

  /* End of Outputs for SubSystem: '<Root>/Statistics1' */

  /* FromWorkspace: '<S4>/From Workspace' */
  {
    int_T currIndex = PhysicalLayerModel_DW->FromWorkspace_IWORK_j1ku0.PrevIndex
      +1;
    uint8_T *pDataValues = (uint8_T *)
      PhysicalLayerModel_DW->FromWorkspace_PWORK_opoi0.DataPtr;
    if (currIndex >= 1) {
      currIndex = 0;
    }

    if (currIndex < 1) {
      pDataValues += currIndex;

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModel_B->FromWorkspace_lddws[0])[elIdx] = *pDataValues;
          pDataValues += 1;
        }
      }
    } else {
      pDataValues += (0);

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModel_B->FromWorkspace_lddws[0])[elIdx] = *pDataValues;
          pDataValues += 1;
        }
      }
    }

    PhysicalLayerModel_DW->FromWorkspace_IWORK_j1ku0.PrevIndex = currIndex;
  }

  /* Outputs for Atomic SubSystem: '<S6>/Transmitter' */
  PhysicalLayerModel_Transmitter(PhysicalLayerModel_B->FromWorkspace_lddws,
    &PhysicalLayerModel_B->Transmitter_fe4q0,
    &PhysicalLayerModel_DW->Transmitter_fe4q0, (P_Transmitter_PhysicalLayerMo_T *)
    &PhysicalLayerModel_P->Transmitter_fe4q0);

  /* End of Outputs for SubSystem: '<S6>/Transmitter' */

  /* Outputs for Atomic SubSystem: '<Root>/Channel2' */
  PhysicalLayerModel_Channel
    (PhysicalLayerModel_B->Transmitter_fe4q0.ComplextoRealImag,
     &PhysicalLayerModel_B->Channel2, &PhysicalLayerModel_DW->Channel2,
     (P_Channel_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Channel2);

  /* End of Outputs for SubSystem: '<Root>/Channel2' */

  /* Outputs for Atomic SubSystem: '<S5>/Receiver' */
  PhysicalLayerModel_Receiver(PhysicalLayerModel_B->Channel2.DynamicAWGN,
    &PhysicalLayerModel_B->Receiver_ewxak,
    &PhysicalLayerModel_DW->Receiver_ewxak, (P_Receiver_PhysicalLayerModel_T *)
    &PhysicalLayerModel_P->Receiver_ewxak);

  /* End of Outputs for SubSystem: '<S5>/Receiver' */

  /* Outputs for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayerModel_Statistics(PhysicalLayerModel_B->FromWorkspace_lddws,
    PhysicalLayerModel_B->Receiver_ewxak.RectangularQAMDemodulatorBaseba,
    &PhysicalLayerModel_B->Statistics2, &PhysicalLayerModel_DW->Statistics2);

  /* End of Outputs for SubSystem: '<Root>/Statistics2' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(PhysicalLayerModel_M->rtwLogInfo,
                      (&PhysicalLayerModel_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.00026399999999999997s, 0.0s] */
    if ((rtmGetTFinal(PhysicalLayerModel_M)!=-1) &&
        !((rtmGetTFinal(PhysicalLayerModel_M)-
           PhysicalLayerModel_M->Timing.taskTime0) >
          PhysicalLayerModel_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PhysicalLayerModel_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PhysicalLayerModel_M->Timing.clockTick0)) {
    ++PhysicalLayerModel_M->Timing.clockTickH0;
  }

  PhysicalLayerModel_M->Timing.taskTime0 =
    PhysicalLayerModel_M->Timing.clockTick0 *
    PhysicalLayerModel_M->Timing.stepSize0 +
    PhysicalLayerModel_M->Timing.clockTickH0 *
    PhysicalLayerModel_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void PhysicalLayerModel_initialize(RT_MODEL_PhysicalLayerModel_T *const
  PhysicalLayerModel_M)
{
  P_PhysicalLayerModel_T *PhysicalLayerModel_P = ((P_PhysicalLayerModel_T *)
    PhysicalLayerModel_M->ModelData.defaultParam);
  DW_PhysicalLayerModel_T *PhysicalLayerModel_DW = ((DW_PhysicalLayerModel_T *)
    PhysicalLayerModel_M->ModelData.dwork);

  /* Start for FromWorkspace: '<S3>/From Workspace' */
  {
    static uint8_T pDataValues0[] = { 13U, 9U, 5U, 3U, 10U, 4U, 15U, 2U, 12U,
      14U, 7U, 9U, 6U, 15U, 10U, 12U, 6U, 2U, 7U, 13U, 10U, 7U, 7U, 2U, 11U, 3U,
      10U, 1U, 9U, 12U, 9U, 10U, 6U, 4U, 15U, 15U, 11U, 11U, 10U, 1U, 8U, 13U,
      3U, 13U, 3U, 7U, 4U, 5U, 14U, 0U, 11U, 6U, 9U, 5U, 13U, 13U, 8U, 0U, 8U,
      13U, 9U, 3U, 5U, 1U, 5U, 4U, 4U, 7U, 1U, 1U, 13U, 1U, 4U, 12U, 7U, 14U, 8U,
      6U, 6U, 1U, 11U, 11U, 11U, 11U, 4U, 0U, 5U, 14U, 11U, 4U, 2U, 2U, 1U, 6U,
      4U, 3U, 2U, 7U, 11U, 6U, 2U, 2U, 14U, 5U, 2U, 13U, 12U, 11U, 7U, 6U, 13U,
      2U, 14U, 13U, 10U, 7U, 14U, 15U, 0U, 13U, 10U, 7U, 9U, 12U, 10U, 12U, 0U,
      6U, 6U, 10U, 10U, 14U, 9U, 9U, 14U, 12U, 12U, 1U, 3U, 1U, 13U, 6U, 7U, 1U,
      0U, 15U, 2U, 14U, 3U, 1U, 10U, 1U, 0U, 11U, 0U, 2U, 4U, 5U, 11U, 9U, 8U,
      9U, 0U, 5U, 8U, 1U, 4U, 9U, 0U, 0U, 6U, 2U, 4U, 4U, 4U, 9U, 8U, 12U, 5U,
      12U, 10U, 8U, 13U, 6U, 9U, 12U, 8U, 15U, 1U, 4U, 6U, 7U, 3U, 5U, 3U, 0U,
      0U, 12U, 0U, 14U, 3U, 9U, 8U, 11U, 5U, 12U, 8U, 12U, 5U, 14U, 14U, 8U, 8U,
      2U, 9U, 11U, 14U, 7U, 12U, 2U, 0U, 2U, 13U, 12U, 3U, 2U, 10U, 6U, 14U, 7U,
      6U, 3U, 5U, 7U, 2U, 15U, 7U, 12U, 13U, 3U, 10U, 4U, 1U, 6U, 1U, 1U, 8U, 3U,
      0U, 15U, 11U, 15U, 15U, 7U, 15U, 13U, 4U, 15U, 1U, 1U, 0U, 4U, 5U, 1U } ;

    PhysicalLayerModel_DW->FromWorkspace_PWORK.TimePtr = (void *) 0;
    PhysicalLayerModel_DW->FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    PhysicalLayerModel_DW->FromWorkspace_IWORK.PrevIndex = -1;
  }

  /* Start for Atomic SubSystem: '<S5>/Transmitter' */
  PhysicalLayer_Transmitter_Start(&PhysicalLayerModel_DW->Transmitter,
    (P_Transmitter_PhysicalLayerMo_T *)&PhysicalLayerModel_P->Transmitter);

  /* End of Start for SubSystem: '<S5>/Transmitter' */

  /* Start for Atomic SubSystem: '<Root>/Channel1' */
  PhysicalLayerMod_Channel_Start(&PhysicalLayerModel_DW->Channel1,
    (P_Channel_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Channel1);

  /* End of Start for SubSystem: '<Root>/Channel1' */

  /* Start for Atomic SubSystem: '<S6>/Receiver' */
  PhysicalLayerMod_Receiver_Start(&PhysicalLayerModel_DW->Receiver,
    (P_Receiver_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Receiver);

  /* End of Start for SubSystem: '<S6>/Receiver' */

  /* Start for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayer_Statistics_Start(PhysicalLayerModel_M,
    &PhysicalLayerModel_DW->Statistics1);

  /* End of Start for SubSystem: '<Root>/Statistics1' */

  /* Start for FromWorkspace: '<S4>/From Workspace' */
  {
    static uint8_T pDataValues0[] = { 11U, 15U, 5U, 12U, 10U, 1U, 11U, 14U, 0U,
      1U, 5U, 14U, 15U, 2U, 2U, 1U, 9U, 6U, 4U, 3U, 3U, 14U, 10U, 9U, 10U, 2U,
      10U, 14U, 2U, 10U, 14U, 4U, 9U, 7U, 13U, 0U, 11U, 8U, 6U, 12U, 6U, 5U, 10U,
      6U, 2U, 0U, 3U, 14U, 15U, 7U, 2U, 8U, 15U, 12U, 15U, 14U, 3U, 1U, 6U, 2U,
      12U, 5U, 7U, 3U, 11U, 3U, 12U, 3U, 9U, 5U, 11U, 1U, 2U, 3U, 5U, 6U, 3U,
      10U, 15U, 6U, 12U, 12U, 15U, 3U, 5U, 12U, 12U, 15U, 9U, 9U, 5U, 5U, 9U, 8U,
      7U, 10U, 0U, 3U, 14U, 9U, 0U, 4U, 0U, 12U, 11U, 8U, 9U, 3U, 6U, 8U, 13U,
      10U, 7U, 13U, 7U, 4U, 11U, 15U, 6U, 3U, 3U, 0U, 15U, 12U, 9U, 6U, 10U, 15U,
      11U, 1U, 7U, 11U, 5U, 14U, 10U, 14U, 6U, 4U, 14U, 0U, 2U, 15U, 11U, 4U,
      13U, 12U, 14U, 10U, 10U, 1U, 14U, 9U, 4U, 15U, 0U, 0U, 1U, 8U, 14U, 6U, 8U,
      9U, 1U, 6U, 5U, 3U, 1U, 1U, 4U, 4U, 14U, 2U, 8U, 2U, 14U, 14U, 2U, 13U, 0U,
      11U, 14U, 6U, 3U, 1U, 13U, 10U, 12U, 5U, 2U, 0U, 1U, 5U, 4U, 8U, 6U, 14U,
      2U, 12U, 2U, 12U, 8U, 7U, 5U, 5U, 6U, 4U, 15U, 10U, 8U, 3U, 1U, 14U, 5U,
      7U, 1U, 13U, 4U, 14U, 0U, 9U, 9U, 10U, 5U, 0U, 4U, 14U, 12U, 5U, 11U, 9U,
      0U, 6U, 0U, 12U, 15U, 11U, 12U, 9U, 4U, 11U, 11U, 7U, 6U, 2U, 8U, 3U, 11U,
      11U, 11U, 11U, 10U, 14U, 7U, 5U, 15U, 1U, 3U, 2U, 12U, 1U, 7U, 9U, 5U, 11U
    } ;

    PhysicalLayerModel_DW->FromWorkspace_PWORK_opoi0.TimePtr = (void *) 0;
    PhysicalLayerModel_DW->FromWorkspace_PWORK_opoi0.DataPtr = (void *)
      pDataValues0;
    PhysicalLayerModel_DW->FromWorkspace_IWORK_j1ku0.PrevIndex = -1;
  }

  /* Start for Atomic SubSystem: '<S6>/Transmitter' */
  PhysicalLayer_Transmitter_Start(&PhysicalLayerModel_DW->Transmitter_fe4q0,
    (P_Transmitter_PhysicalLayerMo_T *)&PhysicalLayerModel_P->Transmitter_fe4q0);

  /* End of Start for SubSystem: '<S6>/Transmitter' */

  /* Start for Atomic SubSystem: '<Root>/Channel2' */
  PhysicalLayerMod_Channel_Start(&PhysicalLayerModel_DW->Channel2,
    (P_Channel_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Channel2);

  /* End of Start for SubSystem: '<Root>/Channel2' */

  /* Start for Atomic SubSystem: '<S5>/Receiver' */
  PhysicalLayerMod_Receiver_Start(&PhysicalLayerModel_DW->Receiver_ewxak,
    (P_Receiver_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Receiver_ewxak);

  /* End of Start for SubSystem: '<S5>/Receiver' */

  /* Start for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayer_Statistics_Start(PhysicalLayerModel_M,
    &PhysicalLayerModel_DW->Statistics2);

  /* End of Start for SubSystem: '<Root>/Statistics2' */

  /* InitializeConditions for Atomic SubSystem: '<S5>/Transmitter' */
  PhysicalLayerM_Transmitter_Init(&PhysicalLayerModel_DW->Transmitter,
    (P_Transmitter_PhysicalLayerMo_T *)&PhysicalLayerModel_P->Transmitter);

  /* End of InitializeConditions for SubSystem: '<S5>/Transmitter' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/Channel1' */
  PhysicalLayerMode_Channel_Init(&PhysicalLayerModel_DW->Channel1,
    (P_Channel_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Channel1);

  /* End of InitializeConditions for SubSystem: '<Root>/Channel1' */

  /* InitializeConditions for Atomic SubSystem: '<S6>/Receiver' */
  PhysicalLayerMode_Receiver_Init(&PhysicalLayerModel_DW->Receiver,
    (P_Receiver_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Receiver);

  /* End of InitializeConditions for SubSystem: '<S6>/Receiver' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayerM_Statistics_Init(&PhysicalLayerModel_DW->Statistics1);

  /* End of InitializeConditions for SubSystem: '<Root>/Statistics1' */

  /* InitializeConditions for Atomic SubSystem: '<S6>/Transmitter' */
  PhysicalLayerM_Transmitter_Init(&PhysicalLayerModel_DW->Transmitter_fe4q0,
    (P_Transmitter_PhysicalLayerMo_T *)&PhysicalLayerModel_P->Transmitter_fe4q0);

  /* End of InitializeConditions for SubSystem: '<S6>/Transmitter' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/Channel2' */
  PhysicalLayerMode_Channel_Init(&PhysicalLayerModel_DW->Channel2,
    (P_Channel_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Channel2);

  /* End of InitializeConditions for SubSystem: '<Root>/Channel2' */

  /* InitializeConditions for Atomic SubSystem: '<S5>/Receiver' */
  PhysicalLayerMode_Receiver_Init(&PhysicalLayerModel_DW->Receiver_ewxak,
    (P_Receiver_PhysicalLayerModel_T *)&PhysicalLayerModel_P->Receiver_ewxak);

  /* End of InitializeConditions for SubSystem: '<S5>/Receiver' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayerM_Statistics_Init(&PhysicalLayerModel_DW->Statistics2);

  /* End of InitializeConditions for SubSystem: '<Root>/Statistics2' */
}

/* Model terminate function */
void PhysicalLayerModel_terminate(RT_MODEL_PhysicalLayerModel_T
  * PhysicalLayerModel_M)
{
  /* Terminate for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayerM_Statistics_Term();

  /* End of Terminate for SubSystem: '<Root>/Statistics1' */

   /* model code */
  {
    void *ptr = PhysicalLayerModel_M->ModelData.blockIO;
    rt_FREE(ptr);
  }

  if (PhysicalLayerModel_M->ModelData.paramIsMalloced) {
    rt_FREE(PhysicalLayerModel_M->ModelData.defaultParam);
  }

  rt_FREE(PhysicalLayerModel_M->ModelData.dwork);

  {
    void *xptr = (void *) rtliGetLogXSignalPtrs(PhysicalLayerModel_M->rtwLogInfo);
    void *yptr = (void *) rtliGetLogYSignalPtrs(PhysicalLayerModel_M->rtwLogInfo);
    rt_FREE(xptr);
    rt_FREE(yptr);
  }

  rt_FREE(PhysicalLayerModel_M->rtwLogInfo);
  rt_FREE(PhysicalLayerModel_M);
}

/* Model data allocation function */
RT_MODEL_PhysicalLayerModel_T *PhysicalLayerModel(void)
{
  RT_MODEL_PhysicalLayerModel_T *PhysicalLayerModel_M;
  PhysicalLayerModel_M = (RT_MODEL_PhysicalLayerModel_T *) malloc(sizeof
    (RT_MODEL_PhysicalLayerModel_T));
  if (PhysicalLayerModel_M == NULL) {
    return NULL;
  }

  (void) memset((char *)PhysicalLayerModel_M, 0,
                sizeof(RT_MODEL_PhysicalLayerModel_T));

  /* Setup for data logging */
  {
    RTWLogInfo *rt_DataLoggingInfo = (RTWLogInfo *) malloc(sizeof(RTWLogInfo));
    rt_VALIDATE_MEMORY(PhysicalLayerModel_M,rt_DataLoggingInfo);
    PhysicalLayerModel_M->rtwLogInfo = rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PhysicalLayerModel_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PhysicalLayerModel_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalInfo(PhysicalLayerModel_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PhysicalLayerModel_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  {
    B_PhysicalLayerModel_T *b = (B_PhysicalLayerModel_T *) malloc(sizeof
      (B_PhysicalLayerModel_T));
    rt_VALIDATE_MEMORY(PhysicalLayerModel_M,b);
    PhysicalLayerModel_M->ModelData.blockIO = (b);
  }

  /* parameters */
  {
    P_PhysicalLayerModel_T *p;
    static int_T pSeen = FALSE;

    /* only malloc on multiple model instantiation */
    if (pSeen == TRUE ) {
      p = (P_PhysicalLayerModel_T *) malloc(sizeof(P_PhysicalLayerModel_T));
      rt_VALIDATE_MEMORY(PhysicalLayerModel_M,p);
      (void) memcpy(p, &PhysicalLayerModel_P,
                    sizeof(P_PhysicalLayerModel_T));
      PhysicalLayerModel_M->ModelData.paramIsMalloced = (TRUE);
    } else {
      p = &PhysicalLayerModel_P;
      PhysicalLayerModel_M->ModelData.paramIsMalloced = (FALSE);
      pSeen = TRUE;
    }

    PhysicalLayerModel_M->ModelData.defaultParam = (p);
  }

  /* states (dwork) */
  {
    DW_PhysicalLayerModel_T *dwork = (DW_PhysicalLayerModel_T *) malloc(sizeof
      (DW_PhysicalLayerModel_T));
    DW_PhysicalLayerModel_T *PhysicalLayerModel_DW = (DW_PhysicalLayerModel_T *)
      dwork;
    rt_VALIDATE_MEMORY(PhysicalLayerModel_M,dwork);
    PhysicalLayerModel_M->ModelData.dwork = (dwork);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  PhysicalLayerModel_InitializeDataMapInfo(PhysicalLayerModel_M,
    PhysicalLayerModel_M->ModelData.blockIO,
    PhysicalLayerModel_M->ModelData.defaultParam);

  {
    P_PhysicalLayerModel_T *PhysicalLayerModel_P = ((P_PhysicalLayerModel_T *)
      PhysicalLayerModel_M->ModelData.defaultParam);
    B_PhysicalLayerModel_T *PhysicalLayerModel_B = ((B_PhysicalLayerModel_T *)
      PhysicalLayerModel_M->ModelData.blockIO);
    DW_PhysicalLayerModel_T *PhysicalLayerModel_DW = ((DW_PhysicalLayerModel_T *)
      PhysicalLayerModel_M->ModelData.dwork);

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtmSetTFinal(PhysicalLayerModel_M, -1);
    PhysicalLayerModel_M->Timing.stepSize0 = 0.00026399999999999997;

    /* Setup for data logging */
    {
      rtliSetLogT(PhysicalLayerModel_M->rtwLogInfo, "");
      rtliSetLogX(PhysicalLayerModel_M->rtwLogInfo, "");
      rtliSetLogXFinal(PhysicalLayerModel_M->rtwLogInfo, "");
      rtliSetSigLog(PhysicalLayerModel_M->rtwLogInfo, "");
      rtliSetLogVarNameModifier(PhysicalLayerModel_M->rtwLogInfo, "rt_");
      rtliSetLogFormat(PhysicalLayerModel_M->rtwLogInfo, 0);
      rtliSetLogMaxRows(PhysicalLayerModel_M->rtwLogInfo, 1000);
      rtliSetLogDecimation(PhysicalLayerModel_M->rtwLogInfo, 1);
      rtliSetLogY(PhysicalLayerModel_M->rtwLogInfo, "");
    }

    PhysicalLayerModel_M->Timing.stepSize = (0.00026399999999999997);

    /* block I/O */
    (void) memset(((void *) PhysicalLayerModel_B), 0,
                  sizeof(B_PhysicalLayerModel_T));

    {
      int_T i;
      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.MPSKModulatorBaseband[i].re =
          0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.MPSKModulatorBaseband[i].im =
          0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->
          Transmitter_fe4q0.RectangularQAMModulatorBaseband[i].re = 0.0;
        PhysicalLayerModel_B->
          Transmitter_fe4q0.RectangularQAMModulatorBaseband[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.MultiportSwitch[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.MultiportSwitch[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.FIRInterpolation[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.FIRInterpolation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.VariableFractionalDelay[i].re =
          0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.VariableFractionalDelay[i].im =
          0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.UpfrequencyOscillator[i].re =
          0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.UpfrequencyOscillator[i].im =
          0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.Product[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.Product[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.PSKGain[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter_fe4q0.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter_fe4q0.ComplextoRealImag[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.DownfrequencyOscillator[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.DownfrequencyOscillator[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.Conjugate[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.Conjugate[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.Product1[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.Product1[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.FIRDecimation[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.FIRDecimation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.Sensitivity3[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.Sensitivity3[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.RealImagtoComplex[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.RealImagtoComplex[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.PSKOn[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.PSKOn[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.PSKGain[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.QAMOn[i].re = 0.0;
        PhysicalLayerModel_B->Receiver.QAMOn[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.ComplextoRealImag2_o1[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.ComplextoRealImag2_o2[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver.MathFunction[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.Sum_hqxki[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.Gain[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.Sum1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.Interpolation[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.Interpolation1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver.VectorintermsofSamples[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter.MPSKModulatorBaseband[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.MPSKModulatorBaseband[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter.RectangularQAMModulatorBaseband[i].re =
          0.0;
        PhysicalLayerModel_B->Transmitter.RectangularQAMModulatorBaseband[i].im =
          0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter.MultiportSwitch[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.MultiportSwitch[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter.FIRInterpolation[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.FIRInterpolation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter.VariableFractionalDelay[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.VariableFractionalDelay[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter.UpfrequencyOscillator[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.UpfrequencyOscillator[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter.Product[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.Product[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Transmitter.PSKGain[i].re = 0.0;
        PhysicalLayerModel_B->Transmitter.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Transmitter.ComplextoRealImag[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.DownfrequencyOscillator[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.DownfrequencyOscillator[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Conjugate[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.Conjugate[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Product1[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.Product1[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.FIRDecimation[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.FIRDecimation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Sensitivity3[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.Sensitivity3[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.RealImagtoComplex[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.RealImagtoComplex[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.PSKOn[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.PSKOn[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.PSKGain[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.QAMOn[i].re = 0.0;
        PhysicalLayerModel_B->Receiver_ewxak.QAMOn[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.ComplextoRealImag2_o1[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.ComplextoRealImag2_o2[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.MathFunction[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Sum_hqxki[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Gain[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Sum1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Interpolation[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.Interpolation1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModel_B->Receiver_ewxak.VectorintermsofSamples[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.InterfererTone[i].re = 0.0;
        PhysicalLayerModel_B->Channel2.InterfererTone[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.ComplextoRealImag[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.MathFunction[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.Gain[i] = 0.0;
      }

      for (i = 0; i < 4224; i++) {
        PhysicalLayerModel_B->Channel2.MatrixConcatenation[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.Add1[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.RandomSource[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel2.DynamicAWGN[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.InterfererTone[i].re = 0.0;
        PhysicalLayerModel_B->Channel1.InterfererTone[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.ComplextoRealImag[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.MathFunction[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.Gain[i] = 0.0;
      }

      for (i = 0; i < 4224; i++) {
        PhysicalLayerModel_B->Channel1.MatrixConcatenation[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.Add1[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.RandomSource[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModel_B->Channel1.DynamicAWGN[i] = 0.0;
      }

      PhysicalLayerModel_B->Statistics2.ErrorRateCalculation[0] = 0.0;
      PhysicalLayerModel_B->Statistics2.ErrorRateCalculation[1] = 0.0;
      PhysicalLayerModel_B->Statistics2.ErrorRateCalculation[2] = 0.0;
      PhysicalLayerModel_B->Statistics1.ErrorRateCalculation[0] = 0.0;
      PhysicalLayerModel_B->Statistics1.ErrorRateCalculation[1] = 0.0;
      PhysicalLayerModel_B->Statistics1.ErrorRateCalculation[2] = 0.0;
      PhysicalLayerModel_B->Receiver.Sum.re = 0.0;
      PhysicalLayerModel_B->Receiver.Sum.im = 0.0;
      PhysicalLayerModel_B->Receiver.ComplextoMagnitudeAngle = 0.0;
      PhysicalLayerModel_B->Receiver.Sensitivity1 = 0.0;
      PhysicalLayerModel_B->Receiver.Abs = 0.0;
      PhysicalLayerModel_B->Receiver.Merge = 0.0;
      PhysicalLayerModel_B->Receiver.Fcn = 0.0;
      PhysicalLayerModel_B->Receiver.Sum2 = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Sum.re = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Sum.im = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.ComplextoMagnitudeAngle = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Sensitivity1 = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Abs = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Merge = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Fcn = 0.0;
      PhysicalLayerModel_B->Receiver_ewxak.Sum2 = 0.0;
    }

    /* states (dwork) */
    (void) memset((void *)PhysicalLayerModel_DW, 0,
                  sizeof(DW_PhysicalLayerModel_T));
    PhysicalLayerModel_DW->Statistics2.errors = 0.0;
    PhysicalLayerModel_DW->Statistics2.symbols = 0.0;
    PhysicalLayerModel_DW->Statistics1.errors = 0.0;
    PhysicalLayerModel_DW->Statistics1.symbols = 0.0;

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        PhysicalLayerModel_DW->Transmitter_fe4q0.FIRInterpolation_TapDelayBuff[i]
          .re = 0.0;
        PhysicalLayerModel_DW->Transmitter_fe4q0.FIRInterpolation_TapDelayBuff[i]
          .im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        PhysicalLayerModel_DW->Transmitter_fe4q0.VariableFractionalDelay_BUFF[i]
          .re = 0.0;
        PhysicalLayerModel_DW->Transmitter_fe4q0.VariableFractionalDelay_BUFF[i]
          .im = 0.0;
      }
    }

    PhysicalLayerModel_DW->Transmitter_fe4q0.UpfrequencyOscillator_AccFreqNo =
      0.0;

    {
      int_T i;
      for (i = 0; i < 4224; i++) {
        PhysicalLayerModel_DW->Receiver.FIRDecimation_OutBuff[i].re = 0.0;
        PhysicalLayerModel_DW->Receiver.FIRDecimation_OutBuff[i].im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 65; i++) {
        PhysicalLayerModel_DW->Receiver.FIRDecimation_StatesBuff[i].re = 0.0;
        PhysicalLayerModel_DW->Receiver.FIRDecimation_StatesBuff[i].im = 0.0;
      }
    }

    PhysicalLayerModel_DW->Receiver.DownfrequencyOscillator_AccFreq = 0.0;
    PhysicalLayerModel_DW->Receiver.FIRDecimation_Sums.re = 0.0;
    PhysicalLayerModel_DW->Receiver.FIRDecimation_Sums.im = 0.0;

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        PhysicalLayerModel_DW->Transmitter.FIRInterpolation_TapDelayBuff[i].re =
          0.0;
        PhysicalLayerModel_DW->Transmitter.FIRInterpolation_TapDelayBuff[i].im =
          0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        PhysicalLayerModel_DW->Transmitter.VariableFractionalDelay_BUFF[i].re =
          0.0;
        PhysicalLayerModel_DW->Transmitter.VariableFractionalDelay_BUFF[i].im =
          0.0;
      }
    }

    PhysicalLayerModel_DW->Transmitter.UpfrequencyOscillator_AccFreqNo = 0.0;

    {
      int_T i;
      for (i = 0; i < 4224; i++) {
        PhysicalLayerModel_DW->Receiver_ewxak.FIRDecimation_OutBuff[i].re = 0.0;
        PhysicalLayerModel_DW->Receiver_ewxak.FIRDecimation_OutBuff[i].im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 65; i++) {
        PhysicalLayerModel_DW->Receiver_ewxak.FIRDecimation_StatesBuff[i].re =
          0.0;
        PhysicalLayerModel_DW->Receiver_ewxak.FIRDecimation_StatesBuff[i].im =
          0.0;
      }
    }

    PhysicalLayerModel_DW->Receiver_ewxak.DownfrequencyOscillator_AccFreq = 0.0;
    PhysicalLayerModel_DW->Receiver_ewxak.FIRDecimation_Sums.re = 0.0;
    PhysicalLayerModel_DW->Receiver_ewxak.FIRDecimation_Sums.im = 0.0;
    PhysicalLayerModel_DW->Channel2.InterfererTone_AccFreqNorm = 0.0;
    PhysicalLayerModel_DW->Channel2.STDDEV = 0.0;
    PhysicalLayerModel_DW->Channel1.InterfererTone_AccFreqNorm = 0.0;
    PhysicalLayerModel_DW->Channel1.STDDEV = 0.0;
  }

  return PhysicalLayerModel_M;
}
