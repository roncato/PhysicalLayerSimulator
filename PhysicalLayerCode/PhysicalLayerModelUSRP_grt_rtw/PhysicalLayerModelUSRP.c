/*
 * PhysicalLayerModelUSRP.c
 *
 * Code generation for model "PhysicalLayerModelUSRP".
 *
 * Model version              : 1.272
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Sun Sep 07 13:05:56 2014
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
#include "PhysicalLayerModelUSRP_capi.h"
#include "PhysicalLayerModelUSRP.h"
#include "PhysicalLayerModelUSRP_private.h"

const creal_T PhysicalLayerModelUSRP_RGND_Complex = { 0.0, 0.0 };/* real_T complex ground */

/* Model step function */
void PhysicalLayerModelUSRP_step(RT_MODEL_PhysicalLayerModelUS_T *const
  PhysicalLayerModelUSRP_M)
{
  P_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_P =
    ((P_PhysicalLayerModelUSRP_T *)
     PhysicalLayerModelUSRP_M->ModelData.defaultParam);
  B_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_B =
    ((B_PhysicalLayerModelUSRP_T *) PhysicalLayerModelUSRP_M->ModelData.blockIO);
  DW_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_DW =
    ((DW_PhysicalLayerModelUSRP_T *) PhysicalLayerModelUSRP_M->ModelData.dwork);

  /* FromWorkspace: '<S1>/From Workspace' */
  {
    int_T currIndex = PhysicalLayerModelUSRP_DW->FromWorkspace_IWORK.PrevIndex+1;
    uint8_T *pDataValues = (uint8_T *)
      PhysicalLayerModelUSRP_DW->FromWorkspace_PWORK.DataPtr;
    if (currIndex >= 1) {
      currIndex = 0;
    }

    if (currIndex < 1) {
      pDataValues += currIndex;

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModelUSRP_B->FromWorkspace[0])[elIdx] = *pDataValues;
          pDataValues += 1;
        }
      }
    } else {
      pDataValues += (0);

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModelUSRP_B->FromWorkspace[0])[elIdx] = *pDataValues;
          pDataValues += 1;
        }
      }
    }

    PhysicalLayerModelUSRP_DW->FromWorkspace_IWORK.PrevIndex = currIndex;
  }

  /* Outputs for Atomic SubSystem: '<S4>/Receiver' */
  PhysicalLayerModelUSRP_Receiver(&PhysicalLayerModelUSRP_B->Receiver,
    &PhysicalLayerModelUSRP_DW->Receiver, (P_Receiver_PhysicalLayerModel_T *)
    &PhysicalLayerModelUSRP_P->Receiver);

  /* End of Outputs for SubSystem: '<S4>/Receiver' */

  /* Outputs for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayerModelU_Statistics1(PhysicalLayerModelUSRP_B->FromWorkspace,
    PhysicalLayerModelUSRP_B->Receiver.MultiportSwitch,
    &PhysicalLayerModelUSRP_B->Statistics1,
    &PhysicalLayerModelUSRP_DW->Statistics1);

  /* End of Outputs for SubSystem: '<Root>/Statistics1' */

  /* FromWorkspace: '<S2>/From Workspace' */
  {
    int_T currIndex =
      PhysicalLayerModelUSRP_DW->FromWorkspace_IWORK_j1ku0.PrevIndex+1;
    uint8_T *pDataValues = (uint8_T *)
      PhysicalLayerModelUSRP_DW->FromWorkspace_PWORK_opoi0.DataPtr;
    if (currIndex >= 1) {
      currIndex = 0;
    }

    if (currIndex < 1) {
      pDataValues += currIndex;

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModelUSRP_B->FromWorkspace_lddws[0])[elIdx] =
            *pDataValues;
          pDataValues += 1;
        }
      }
    } else {
      pDataValues += (0);

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 264; ++elIdx) {
          (&PhysicalLayerModelUSRP_B->FromWorkspace_lddws[0])[elIdx] =
            *pDataValues;
          pDataValues += 1;
        }
      }
    }

    PhysicalLayerModelUSRP_DW->FromWorkspace_IWORK_j1ku0.PrevIndex = currIndex;
  }

  /* Outputs for Atomic SubSystem: '<S3>/Receiver' */
  PhysicalLayerModelUSRP_Receiver(&PhysicalLayerModelUSRP_B->Receiver_ewxak,
    &PhysicalLayerModelUSRP_DW->Receiver_ewxak, (P_Receiver_PhysicalLayerModel_T
    *)&PhysicalLayerModelUSRP_P->Receiver_ewxak);

  /* End of Outputs for SubSystem: '<S3>/Receiver' */

  /* Outputs for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayerModelU_Statistics2(PhysicalLayerModelUSRP_B->FromWorkspace_lddws,
    PhysicalLayerModelUSRP_B->Receiver_ewxak.MultiportSwitch,
    &PhysicalLayerModelUSRP_B->Statistics2,
    &PhysicalLayerModelUSRP_DW->Statistics2);

  /* End of Outputs for SubSystem: '<Root>/Statistics2' */

  /* Outputs for Atomic SubSystem: '<S3>/Transmitter' */
  PhysicalLayerModelU_Transmitter(PhysicalLayerModelUSRP_B->FromWorkspace,
    &PhysicalLayerModelUSRP_B->Transmitter,
    &PhysicalLayerModelUSRP_DW->Transmitter, (P_Transmitter_PhysicalLayerMo_T *)
    &PhysicalLayerModelUSRP_P->Transmitter);

  /* End of Outputs for SubSystem: '<S3>/Transmitter' */

  /* Outputs for Atomic SubSystem: '<S4>/Transmitter' */
  PhysicalLayerModelU_Transmitter(PhysicalLayerModelUSRP_B->FromWorkspace_lddws,
    &PhysicalLayerModelUSRP_B->Transmitter_k4fhb,
    &PhysicalLayerModelUSRP_DW->Transmitter_k4fhb,
    (P_Transmitter_PhysicalLayerMo_T *)
    &PhysicalLayerModelUSRP_P->Transmitter_k4fhb);

  /* End of Outputs for SubSystem: '<S4>/Transmitter' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(PhysicalLayerModelUSRP_M->rtwLogInfo,
                      (&PhysicalLayerModelUSRP_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.00026399999999999997s, 0.0s] */
    if ((rtmGetTFinal(PhysicalLayerModelUSRP_M)!=-1) &&
        !((rtmGetTFinal(PhysicalLayerModelUSRP_M)-
           PhysicalLayerModelUSRP_M->Timing.taskTime0) >
          PhysicalLayerModelUSRP_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PhysicalLayerModelUSRP_M, "Simulation finished");
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
  if (!(++PhysicalLayerModelUSRP_M->Timing.clockTick0)) {
    ++PhysicalLayerModelUSRP_M->Timing.clockTickH0;
  }

  PhysicalLayerModelUSRP_M->Timing.taskTime0 =
    PhysicalLayerModelUSRP_M->Timing.clockTick0 *
    PhysicalLayerModelUSRP_M->Timing.stepSize0 +
    PhysicalLayerModelUSRP_M->Timing.clockTickH0 *
    PhysicalLayerModelUSRP_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void PhysicalLayerModelUSRP_initialize(RT_MODEL_PhysicalLayerModelUS_T *const
  PhysicalLayerModelUSRP_M)
{
  DW_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_DW =
    ((DW_PhysicalLayerModelUSRP_T *) PhysicalLayerModelUSRP_M->ModelData.dwork);

  /* Start for FromWorkspace: '<S1>/From Workspace' */
  {
    static uint8_T pDataValues0[] = { 13U, 14U, 2U, 14U, 10U, 1U, 4U, 8U, 15U,
      15U, 2U, 15U, 15U, 7U, 12U, 2U, 6U, 14U, 12U, 15U, 10U, 0U, 13U, 14U, 10U,
      12U, 11U, 6U, 10U, 2U, 11U, 0U, 4U, 0U, 1U, 13U, 11U, 5U, 15U, 0U, 7U, 6U,
      12U, 12U, 2U, 7U, 7U, 10U, 11U, 12U, 4U, 10U, 10U, 2U, 1U, 7U, 15U, 5U, 9U,
      3U, 12U, 4U, 8U, 11U, 14U, 15U, 8U, 2U, 2U, 4U, 13U, 4U, 13U, 3U, 14U, 5U,
      3U, 4U, 9U, 7U, 5U, 13U, 9U, 8U, 14U, 4U, 12U, 12U, 6U, 9U, 1U, 0U, 8U,
      12U, 14U, 2U, 9U, 7U, 0U, 5U, 2U, 12U, 4U, 8U, 2U, 9U, 4U, 10U, 11U, 11U,
      7U, 1U, 3U, 14U, 2U, 13U, 8U, 15U, 1U, 7U, 1U, 15U, 0U, 12U, 13U, 13U, 1U,
      6U, 4U, 12U, 6U, 14U, 2U, 4U, 2U, 2U, 13U, 9U, 8U, 2U, 13U, 9U, 5U, 8U, 6U,
      1U, 3U, 1U, 2U, 3U, 6U, 0U, 14U, 15U, 7U, 7U, 5U, 14U, 5U, 1U, 12U, 6U, 3U,
      6U, 1U, 2U, 15U, 15U, 9U, 0U, 3U, 5U, 13U, 0U, 0U, 2U, 10U, 11U, 10U, 7U,
      8U, 4U, 11U, 3U, 10U, 2U, 5U, 10U, 12U, 1U, 14U, 12U, 7U, 6U, 7U, 4U, 8U,
      8U, 13U, 12U, 10U, 6U, 12U, 8U, 5U, 15U, 14U, 8U, 9U, 9U, 3U, 4U, 7U, 3U,
      13U, 3U, 3U, 2U, 3U, 6U, 4U, 14U, 6U, 2U, 14U, 15U, 7U, 1U, 4U, 6U, 9U, 4U,
      9U, 11U, 3U, 1U, 4U, 5U, 6U, 8U, 1U, 4U, 12U, 0U, 14U, 11U, 7U, 9U, 3U, 7U,
      15U, 8U, 8U, 3U, 7U, 9U, 10U, 6U, 5U, 15U, 0U, 14U, 14U, 12U } ;

    PhysicalLayerModelUSRP_DW->FromWorkspace_PWORK.TimePtr = (void *) 0;
    PhysicalLayerModelUSRP_DW->FromWorkspace_PWORK.DataPtr = (void *)
      pDataValues0;
    PhysicalLayerModelUSRP_DW->FromWorkspace_IWORK.PrevIndex = -1;
  }

  /* Start for Atomic SubSystem: '<S4>/Receiver' */
  PhysicalLayerMod_Receiver_Start(&PhysicalLayerModelUSRP_DW->Receiver);

  /* End of Start for SubSystem: '<S4>/Receiver' */

  /* Start for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayer_Statistics1_Start(PhysicalLayerModelUSRP_M,
    &PhysicalLayerModelUSRP_DW->Statistics1);

  /* End of Start for SubSystem: '<Root>/Statistics1' */

  /* Start for FromWorkspace: '<S2>/From Workspace' */
  {
    static uint8_T pDataValues0[] = { 1U, 4U, 5U, 10U, 2U, 11U, 1U, 10U, 7U, 12U,
      11U, 14U, 14U, 5U, 11U, 3U, 0U, 11U, 8U, 7U, 14U, 9U, 9U, 13U, 12U, 9U, 2U,
      3U, 14U, 0U, 7U, 2U, 15U, 11U, 8U, 7U, 0U, 10U, 0U, 1U, 8U, 1U, 13U, 13U,
      11U, 2U, 10U, 8U, 15U, 10U, 12U, 7U, 6U, 13U, 1U, 2U, 2U, 6U, 13U, 12U, 0U,
      6U, 8U, 6U, 10U, 10U, 4U, 6U, 0U, 15U, 2U, 1U, 5U, 3U, 7U, 5U, 15U, 14U,
      0U, 11U, 4U, 6U, 8U, 15U, 6U, 15U, 4U, 11U, 10U, 8U, 11U, 10U, 2U, 2U, 15U,
      2U, 0U, 8U, 14U, 10U, 3U, 5U, 7U, 15U, 2U, 13U, 10U, 6U, 3U, 6U, 7U, 1U,
      9U, 3U, 6U, 9U, 4U, 4U, 9U, 4U, 13U, 15U, 11U, 5U, 9U, 1U, 14U, 14U, 13U,
      4U, 9U, 0U, 6U, 5U, 2U, 2U, 6U, 1U, 9U, 7U, 11U, 11U, 10U, 0U, 1U, 5U, 8U,
      10U, 6U, 13U, 11U, 15U, 8U, 5U, 1U, 9U, 12U, 6U, 1U, 4U, 2U, 4U, 7U, 8U,
      7U, 14U, 8U, 15U, 10U, 15U, 3U, 10U, 4U, 10U, 11U, 1U, 4U, 3U, 10U, 13U,
      5U, 12U, 10U, 0U, 9U, 6U, 14U, 0U, 7U, 6U, 7U, 12U, 5U, 12U, 7U, 0U, 2U,
      11U, 7U, 2U, 5U, 9U, 3U, 11U, 3U, 14U, 4U, 12U, 3U, 4U, 1U, 9U, 10U, 8U,
      6U, 10U, 10U, 10U, 10U, 15U, 3U, 11U, 3U, 1U, 9U, 7U, 7U, 10U, 12U, 5U,
      10U, 6U, 13U, 13U, 4U, 9U, 9U, 8U, 13U, 4U, 5U, 1U, 15U, 10U, 7U, 10U, 8U,
      10U, 8U, 11U, 8U, 15U, 3U, 1U, 1U, 1U, 6U, 7U, 5U, 12U, 10U, 12U, 14U, 15U
    } ;

    PhysicalLayerModelUSRP_DW->FromWorkspace_PWORK_opoi0.TimePtr = (void *) 0;
    PhysicalLayerModelUSRP_DW->FromWorkspace_PWORK_opoi0.DataPtr = (void *)
      pDataValues0;
    PhysicalLayerModelUSRP_DW->FromWorkspace_IWORK_j1ku0.PrevIndex = -1;
  }

  /* Start for Atomic SubSystem: '<S3>/Receiver' */
  PhysicalLayerMod_Receiver_Start(&PhysicalLayerModelUSRP_DW->Receiver_ewxak);

  /* End of Start for SubSystem: '<S3>/Receiver' */

  /* Start for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayer_Statistics2_Start(PhysicalLayerModelUSRP_M,
    &PhysicalLayerModelUSRP_DW->Statistics2);

  /* End of Start for SubSystem: '<Root>/Statistics2' */

  /* Start for Atomic SubSystem: '<S3>/Transmitter' */
  PhysicalLayer_Transmitter_Start(&PhysicalLayerModelUSRP_DW->Transmitter);

  /* End of Start for SubSystem: '<S3>/Transmitter' */

  /* Start for Atomic SubSystem: '<S4>/Transmitter' */
  PhysicalLayer_Transmitter_Start(&PhysicalLayerModelUSRP_DW->Transmitter_k4fhb);

  /* End of Start for SubSystem: '<S4>/Transmitter' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayerM_Statistics1_Init(&PhysicalLayerModelUSRP_DW->Statistics1);

  /* End of InitializeConditions for SubSystem: '<Root>/Statistics1' */

  /* InitializeConditions for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayerM_Statistics2_Init(&PhysicalLayerModelUSRP_DW->Statistics2);

  /* End of InitializeConditions for SubSystem: '<Root>/Statistics2' */

  /* InitializeConditions for Atomic SubSystem: '<S3>/Transmitter' */
  PhysicalLayerM_Transmitter_Init(&PhysicalLayerModelUSRP_DW->Transmitter);

  /* End of InitializeConditions for SubSystem: '<S3>/Transmitter' */

  /* InitializeConditions for Atomic SubSystem: '<S4>/Transmitter' */
  PhysicalLayerM_Transmitter_Init(&PhysicalLayerModelUSRP_DW->Transmitter_k4fhb);

  /* End of InitializeConditions for SubSystem: '<S4>/Transmitter' */
}

/* Model terminate function */
void PhysicalLayerModelUSRP_terminate(RT_MODEL_PhysicalLayerModelUS_T
  * PhysicalLayerModelUSRP_M)
{
  DW_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_DW =
    ((DW_PhysicalLayerModelUSRP_T *) PhysicalLayerModelUSRP_M->ModelData.dwork);

  /* Terminate for Atomic SubSystem: '<S4>/Receiver' */
  PhysicalLayerMode_Receiver_Term(&PhysicalLayerModelUSRP_DW->Receiver);

  /* End of Terminate for SubSystem: '<S4>/Receiver' */

  /* Terminate for Atomic SubSystem: '<Root>/Statistics1' */
  PhysicalLayerM_Statistics1_Term();

  /* End of Terminate for SubSystem: '<Root>/Statistics1' */

  /* Terminate for Atomic SubSystem: '<S3>/Receiver' */
  PhysicalLayerMode_Receiver_Term(&PhysicalLayerModelUSRP_DW->Receiver_ewxak);

  /* End of Terminate for SubSystem: '<S3>/Receiver' */

  /* Terminate for Atomic SubSystem: '<Root>/Statistics2' */
  PhysicalLayerM_Statistics2_Term();

  /* End of Terminate for SubSystem: '<Root>/Statistics2' */

  /* Terminate for Atomic SubSystem: '<S3>/Transmitter' */
  PhysicalLayerM_Transmitter_Term(&PhysicalLayerModelUSRP_DW->Transmitter);

  /* End of Terminate for SubSystem: '<S3>/Transmitter' */

  /* Terminate for Atomic SubSystem: '<S4>/Transmitter' */
  PhysicalLayerM_Transmitter_Term(&PhysicalLayerModelUSRP_DW->Transmitter_k4fhb);

  /* End of Terminate for SubSystem: '<S4>/Transmitter' */

  /* model code */
  {
    void *ptr = PhysicalLayerModelUSRP_M->ModelData.blockIO;
    rt_FREE(ptr);
  }

  if (PhysicalLayerModelUSRP_M->ModelData.paramIsMalloced) {
    rt_FREE(PhysicalLayerModelUSRP_M->ModelData.defaultParam);
  }

  rt_FREE(PhysicalLayerModelUSRP_M->ModelData.dwork);

  {
    void *xptr = (void *) rtliGetLogXSignalPtrs
      (PhysicalLayerModelUSRP_M->rtwLogInfo);
    void *yptr = (void *) rtliGetLogYSignalPtrs
      (PhysicalLayerModelUSRP_M->rtwLogInfo);
    rt_FREE(xptr);
    rt_FREE(yptr);
  }

  rt_FREE(PhysicalLayerModelUSRP_M->rtwLogInfo);
  rt_FREE(PhysicalLayerModelUSRP_M);
}

/* Model data allocation function */
RT_MODEL_PhysicalLayerModelUS_T *PhysicalLayerModelUSRP(void)
{
  RT_MODEL_PhysicalLayerModelUS_T *PhysicalLayerModelUSRP_M;
  PhysicalLayerModelUSRP_M = (RT_MODEL_PhysicalLayerModelUS_T *) malloc(sizeof
    (RT_MODEL_PhysicalLayerModelUS_T));
  if (PhysicalLayerModelUSRP_M == NULL) {
    return NULL;
  }

  (void) memset((char *)PhysicalLayerModelUSRP_M, 0,
                sizeof(RT_MODEL_PhysicalLayerModelUS_T));

  /* Setup for data logging */
  {
    RTWLogInfo *rt_DataLoggingInfo = (RTWLogInfo *) malloc(sizeof(RTWLogInfo));
    rt_VALIDATE_MEMORY(PhysicalLayerModelUSRP_M,rt_DataLoggingInfo);
    PhysicalLayerModelUSRP_M->rtwLogInfo = rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PhysicalLayerModelUSRP_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PhysicalLayerModelUSRP_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalInfo(PhysicalLayerModelUSRP_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PhysicalLayerModelUSRP_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  {
    B_PhysicalLayerModelUSRP_T *b = (B_PhysicalLayerModelUSRP_T *) malloc(sizeof
      (B_PhysicalLayerModelUSRP_T));
    rt_VALIDATE_MEMORY(PhysicalLayerModelUSRP_M,b);
    PhysicalLayerModelUSRP_M->ModelData.blockIO = (b);
  }

  /* parameters */
  {
    P_PhysicalLayerModelUSRP_T *p;
    static int_T pSeen = FALSE;

    /* only malloc on multiple model instantiation */
    if (pSeen == TRUE ) {
      p = (P_PhysicalLayerModelUSRP_T *) malloc(sizeof
        (P_PhysicalLayerModelUSRP_T));
      rt_VALIDATE_MEMORY(PhysicalLayerModelUSRP_M,p);
      (void) memcpy(p, &PhysicalLayerModelUSRP_P,
                    sizeof(P_PhysicalLayerModelUSRP_T));
      PhysicalLayerModelUSRP_M->ModelData.paramIsMalloced = (TRUE);
    } else {
      p = &PhysicalLayerModelUSRP_P;
      PhysicalLayerModelUSRP_M->ModelData.paramIsMalloced = (FALSE);
      pSeen = TRUE;
    }

    PhysicalLayerModelUSRP_M->ModelData.defaultParam = (p);
  }

  /* states (dwork) */
  {
    DW_PhysicalLayerModelUSRP_T *dwork = (DW_PhysicalLayerModelUSRP_T *) malloc
      (sizeof(DW_PhysicalLayerModelUSRP_T));
    DW_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_DW =
      (DW_PhysicalLayerModelUSRP_T *) dwork;
    rt_VALIDATE_MEMORY(PhysicalLayerModelUSRP_M,dwork);
    PhysicalLayerModelUSRP_M->ModelData.dwork = (dwork);
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  PhysicalLayerModelUSRP_InitializeDataMapInfo(PhysicalLayerModelUSRP_M,
    PhysicalLayerModelUSRP_M->ModelData.blockIO,
    PhysicalLayerModelUSRP_M->ModelData.defaultParam);

  {
    P_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_P =
      ((P_PhysicalLayerModelUSRP_T *)
       PhysicalLayerModelUSRP_M->ModelData.defaultParam);
    B_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_B =
      ((B_PhysicalLayerModelUSRP_T *)
       PhysicalLayerModelUSRP_M->ModelData.blockIO);
    DW_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_DW =
      ((DW_PhysicalLayerModelUSRP_T *) PhysicalLayerModelUSRP_M->ModelData.dwork);

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));
    rtmSetTFinal(PhysicalLayerModelUSRP_M, -1);
    PhysicalLayerModelUSRP_M->Timing.stepSize0 = 0.00026399999999999997;

    /* Setup for data logging */
    {
      rtliSetLogT(PhysicalLayerModelUSRP_M->rtwLogInfo, "");
      rtliSetLogX(PhysicalLayerModelUSRP_M->rtwLogInfo, "");
      rtliSetLogXFinal(PhysicalLayerModelUSRP_M->rtwLogInfo, "");
      rtliSetSigLog(PhysicalLayerModelUSRP_M->rtwLogInfo, "");
      rtliSetLogVarNameModifier(PhysicalLayerModelUSRP_M->rtwLogInfo, "rt_");
      rtliSetLogFormat(PhysicalLayerModelUSRP_M->rtwLogInfo, 0);
      rtliSetLogMaxRows(PhysicalLayerModelUSRP_M->rtwLogInfo, 1000);
      rtliSetLogDecimation(PhysicalLayerModelUSRP_M->rtwLogInfo, 1);
      rtliSetLogY(PhysicalLayerModelUSRP_M->rtwLogInfo, "");
    }

    PhysicalLayerModelUSRP_M->Timing.stepSize = (0.00026399999999999997);

    /* block I/O */
    (void) memset(((void *) PhysicalLayerModelUSRP_B), 0,
                  sizeof(B_PhysicalLayerModelUSRP_T));

    {
      int_T i;
      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.RectangularQAMModulatorBaseband
          [i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.RectangularQAMModulatorBaseband
          [i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.MPSKModulatorBaseband[i].re =
          0.0;
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.MPSKModulatorBaseband[i].im =
          0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.MultiportSwitch[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.MultiportSwitch[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.FIRInterpolation[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.FIRInterpolation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.VariableFractionalDelay[i].
          re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.VariableFractionalDelay[i].
          im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.PSKGain[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter_k4fhb.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Gain[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.Gain[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver.FIRDecimation[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.FIRDecimation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Sensitivity3[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.Sensitivity3[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.RealImagtoComplex[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.RealImagtoComplex[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.PSKOn[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.PSKOn[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.PSKGain[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.QAMOn[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver.QAMOn[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver.ComplextoRealImag2_o1[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver.ComplextoRealImag2_o2[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver.MathFunction[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Sum_hha5s[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Gain_nyex1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Sum1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Interpolation[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.Interpolation1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver.VectorintermsofSamples[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter.RectangularQAMModulatorBaseband[i]
          .re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter.RectangularQAMModulatorBaseband[i]
          .im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter.MPSKModulatorBaseband[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter.MPSKModulatorBaseband[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter.MultiportSwitch[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter.MultiportSwitch[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Transmitter.FIRInterpolation[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter.FIRInterpolation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Transmitter.VariableFractionalDelay[i].re =
          0.0;
        PhysicalLayerModelUSRP_B->Transmitter.VariableFractionalDelay[i].im =
          0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Transmitter.PSKGain[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Transmitter.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Gain[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Gain[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.FIRDecimation[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.FIRDecimation[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Sensitivity3[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Sensitivity3[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.RealImagtoComplex[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.RealImagtoComplex[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.PSKOn[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.PSKOn[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.PSKGain[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.PSKGain[i].im = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.QAMOn[i].re = 0.0;
        PhysicalLayerModelUSRP_B->Receiver_ewxak.QAMOn[i].im = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.ComplextoRealImag2_o1[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.ComplextoRealImag2_o2[i] = 0.0;
      }

      for (i = 0; i < 2112; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.MathFunction[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum_hha5s[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Gain_nyex1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Interpolation[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.Interpolation1[i] = 0.0;
      }

      for (i = 0; i < 264; i++) {
        PhysicalLayerModelUSRP_B->Receiver_ewxak.VectorintermsofSamples[i] = 0.0;
      }

      PhysicalLayerModelUSRP_B->Statistics2.ErrorRateCalculation[0] = 0.0;
      PhysicalLayerModelUSRP_B->Statistics2.ErrorRateCalculation[1] = 0.0;
      PhysicalLayerModelUSRP_B->Statistics2.ErrorRateCalculation[2] = 0.0;
      PhysicalLayerModelUSRP_B->Statistics1.ErrorRateCalculation[0] = 0.0;
      PhysicalLayerModelUSRP_B->Statistics1.ErrorRateCalculation[1] = 0.0;
      PhysicalLayerModelUSRP_B->Statistics1.ErrorRateCalculation[2] = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Sum.re = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Sum.im = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.ComplextoMagnitudeAngle = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Sensitivity1 = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Abs = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Merge = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Fcn = 0.0;
      PhysicalLayerModelUSRP_B->Receiver.Sum2 = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum.re = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum.im = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.ComplextoMagnitudeAngle = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Sensitivity1 = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Abs = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Merge = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Fcn = 0.0;
      PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum2 = 0.0;
    }

    /* states (dwork) */
    (void) memset((void *)PhysicalLayerModelUSRP_DW, 0,
                  sizeof(DW_PhysicalLayerModelUSRP_T));
    PhysicalLayerModelUSRP_DW->Statistics2.errors = 0.0;
    PhysicalLayerModelUSRP_DW->Statistics2.symbols = 0.0;
    PhysicalLayerModelUSRP_DW->Statistics1.errors = 0.0;
    PhysicalLayerModelUSRP_DW->Statistics1.symbols = 0.0;

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        PhysicalLayerModelUSRP_DW->Transmitter_k4fhb.FIRInterpolation_TapDelayBuff
          [i].re = 0.0;
        PhysicalLayerModelUSRP_DW->Transmitter_k4fhb.FIRInterpolation_TapDelayBuff
          [i].im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        PhysicalLayerModelUSRP_DW->Transmitter_k4fhb.VariableFractionalDelay_BUFF
          [i].re = 0.0;
        PhysicalLayerModelUSRP_DW->Transmitter_k4fhb.VariableFractionalDelay_BUFF
          [i].im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 4224; i++) {
        PhysicalLayerModelUSRP_DW->Receiver.FIRDecimation_OutBuff[i].re = 0.0;
        PhysicalLayerModelUSRP_DW->Receiver.FIRDecimation_OutBuff[i].im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 65; i++) {
        PhysicalLayerModelUSRP_DW->Receiver.FIRDecimation_StatesBuff[i].re = 0.0;
        PhysicalLayerModelUSRP_DW->Receiver.FIRDecimation_StatesBuff[i].im = 0.0;
      }
    }

    PhysicalLayerModelUSRP_DW->Receiver.FIRDecimation_Sums.re = 0.0;
    PhysicalLayerModelUSRP_DW->Receiver.FIRDecimation_Sums.im = 0.0;

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        PhysicalLayerModelUSRP_DW->Transmitter.FIRInterpolation_TapDelayBuff[i].
          re = 0.0;
        PhysicalLayerModelUSRP_DW->Transmitter.FIRInterpolation_TapDelayBuff[i].
          im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 5; i++) {
        PhysicalLayerModelUSRP_DW->Transmitter.VariableFractionalDelay_BUFF[i].
          re = 0.0;
        PhysicalLayerModelUSRP_DW->Transmitter.VariableFractionalDelay_BUFF[i].
          im = 0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 4224; i++) {
        PhysicalLayerModelUSRP_DW->Receiver_ewxak.FIRDecimation_OutBuff[i].re =
          0.0;
        PhysicalLayerModelUSRP_DW->Receiver_ewxak.FIRDecimation_OutBuff[i].im =
          0.0;
      }
    }

    {
      int_T i;
      for (i = 0; i < 65; i++) {
        PhysicalLayerModelUSRP_DW->Receiver_ewxak.FIRDecimation_StatesBuff[i].re
          = 0.0;
        PhysicalLayerModelUSRP_DW->Receiver_ewxak.FIRDecimation_StatesBuff[i].im
          = 0.0;
      }
    }

    PhysicalLayerModelUSRP_DW->Receiver_ewxak.FIRDecimation_Sums.re = 0.0;
    PhysicalLayerModelUSRP_DW->Receiver_ewxak.FIRDecimation_Sums.im = 0.0;
  }

  return PhysicalLayerModelUSRP_M;
}
