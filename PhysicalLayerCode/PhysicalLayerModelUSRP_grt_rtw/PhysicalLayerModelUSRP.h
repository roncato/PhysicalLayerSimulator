/*
 * PhysicalLayerModelUSRP.h
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
#ifndef RTW_HEADER_PhysicalLayerModelUSRP_h_
#define RTW_HEADER_PhysicalLayerModelUSRP_h_
#include "rtw_modelmap.h"
#ifndef PhysicalLayerModelUSRP_COMMON_INCLUDES_
# define PhysicalLayerModelUSRP_COMMON_INCLUDES_
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
#include "usrp_uhd_capi.hpp"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* PhysicalLayerModelUSRP_COMMON_INCLUDES_ */
#include <stdio.h>
#include "PhysicalLayerModelUSRP_types.h"

/* Child system includes */
#include "PhysicalLayerModelUSRP_Receiver.h"
#include "PhysicalLayerModelU_Statistics1.h"
#include "PhysicalLayerModelU_Statistics2.h"
#include "PhysicalLayerModelU_Transmitter.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#define PhysicalLayerModelUSRP_M_TYPE  RT_MODEL_PhysicalLayerModelUS_T

/* Block signals (auto storage) */
typedef struct {
  uint8_T FromWorkspace[264];          /* '<S1>/From Workspace' */
  uint8_T FromWorkspace_lddws[264];    /* '<S2>/From Workspace' */
  B_Statistics2_PhysicalLayerMo_T Statistics2;/* '<Root>/Statistics2' */
  B_Statistics1_PhysicalLayerMo_T Statistics1;/* '<Root>/Statistics1' */
  B_Transmitter_PhysicalLayerMo_T Transmitter_k4fhb;/* '<S4>/Transmitter' */
  B_Receiver_PhysicalLayerModel_T Receiver;/* '<S4>/Receiver' */
  B_Transmitter_PhysicalLayerMo_T Transmitter;/* '<S3>/Transmitter' */
  B_Receiver_PhysicalLayerModel_T Receiver_ewxak;/* '<S3>/Receiver' */
} B_PhysicalLayerModelUSRP_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S1>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK_opoi0;         /* '<S2>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S1>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK_j1ku0;         /* '<S2>/From Workspace' */

  DW_Statistics2_PhysicalLayerM_T Statistics2;/* '<Root>/Statistics2' */
  DW_Statistics1_PhysicalLayerM_T Statistics1;/* '<Root>/Statistics1' */
  DW_Transmitter_PhysicalLayerM_T Transmitter_k4fhb;/* '<S4>/Transmitter' */
  DW_Receiver_PhysicalLayerMode_T Receiver;/* '<S4>/Receiver' */
  DW_Transmitter_PhysicalLayerM_T Transmitter;/* '<S3>/Transmitter' */
  DW_Receiver_PhysicalLayerMode_T Receiver_ewxak;/* '<S3>/Receiver' */
} DW_PhysicalLayerModelUSRP_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: a.h)
   * Referenced by:
   *   '<S13>/FIR Decimation'
   *   '<S32>/FIR Decimation'
   */
  real_T pooled1[65];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/Rectangular QAM Modulator Baseband'
   *   '<S27>/Rectangular QAM Modulator Baseband'
   */
  real_T pooled5[32];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S8>/M-PSK Modulator Baseband'
   *   '<S27>/M-PSK Modulator Baseband'
   */
  real_T pooled6[32];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/usrp_uhd_sfunrx'
   *   '<S29>/usrp_uhd_sfunrx'
   */
  uint32_T pooled8;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/usrp_uhd_sfunrx'
   *   '<S25>/usrp_uhd_sfuntx'
   *   '<S29>/usrp_uhd_sfunrx'
   *   '<S44>/usrp_uhd_sfuntx'
   */
  uint32_T pooled9;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S25>/usrp_uhd_sfuntx'
   *   '<S44>/usrp_uhd_sfuntx'
   */
  uint32_T pooled10;

  /* Pooled Parameter (Expression: BoardId)
   * Referenced by:
   *   '<S10>/usrp_uhd_sfunrx'
   *   '<S29>/usrp_uhd_sfunrx'
   */
  BoardIdSLCapiEnumT pooled11;

  /* Pooled Parameter (Expression: BoardId)
   * Referenced by:
   *   '<S25>/usrp_uhd_sfuntx'
   *   '<S44>/usrp_uhd_sfuntx'
   */
  BoardIdSLCapiEnumT pooled12;

  /* Pooled Parameter (Expression: DportDtype)
   * Referenced by:
   *   '<S10>/usrp_uhd_sfunrx'
   *   '<S29>/usrp_uhd_sfunrx'
   */
  DataPortDataTypeSLCapiEnumT pooled13;

  /* Pooled Parameter (Expression: DportDtype)
   * Referenced by:
   *   '<S25>/usrp_uhd_sfuntx'
   *   '<S44>/usrp_uhd_sfuntx'
   */
  DataPortDataTypeSLCapiEnumT pooled14;

  /* Pooled Parameter (Expression: IPAddrAsInt8Array)
   * Referenced by:
   *   '<S10>/usrp_uhd_sfunrx'
   *   '<S25>/usrp_uhd_sfuntx'
   *   '<S29>/usrp_uhd_sfunrx'
   *   '<S44>/usrp_uhd_sfuntx'
   */
  int8_T pooled15[13];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/usrp_uhd_sfunrx'
   *   '<S25>/usrp_uhd_sfuntx'
   *   '<S29>/usrp_uhd_sfunrx'
   *   '<S44>/usrp_uhd_sfuntx'
   */
  boolean_T pooled16;
} ConstP_PhysicalLayerModelUSRP_T;

/* Parameters (auto storage) */
struct P_PhysicalLayerModelUSRP_T_ {
  P_Transmitter_PhysicalLayerMo_T Transmitter_k4fhb;/* '<S4>/Transmitter' */
  P_Receiver_PhysicalLayerModel_T Receiver;/* '<S4>/Receiver' */
  P_Transmitter_PhysicalLayerMo_T Transmitter;/* '<S3>/Transmitter' */
  P_Receiver_PhysicalLayerModel_T Receiver_ewxak;/* '<S3>/Receiver' */
};

/* Real-time Model Data Structure */
struct tag_RTM_PhysicalLayerModelUSR_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[168];
    int32_T* vardimsAddress[168];
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    B_PhysicalLayerModelUSRP_T *blockIO;
    P_PhysicalLayerModelUSRP_T *defaultParam;
    boolean_T paramIsMalloced;
    DW_PhysicalLayerModelUSRP_T *dwork;
  } ModelData;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

extern P_PhysicalLayerModelUSRP_T PhysicalLayerModelUSRP_P;/* parameters */

/* Constant parameters (auto storage) */
extern const ConstP_PhysicalLayerModelUSRP_T PhysicalLayerModelUSRP_ConstP;

/* External data declarations for dependent source files */
extern const creal_T PhysicalLayerModelUSRP_RGND_Complex;/* real_T complex ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern RT_MODEL_PhysicalLayerModelUS_T *PhysicalLayerModelUSRP(void);
extern void PhysicalLayerModelUSRP_initialize(RT_MODEL_PhysicalLayerModelUS_T *
  const PhysicalLayerModelUSRP_M);
extern void PhysicalLayerModelUSRP_step(RT_MODEL_PhysicalLayerModelUS_T *const
  PhysicalLayerModelUSRP_M);
extern void PhysicalLayerModelUSRP_terminate(RT_MODEL_PhysicalLayerModelUS_T
  * PhysicalLayerModelUSRP_M);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  PhysicalLayerModelUSRP_GetCAPIStaticMap(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Delay Estimate' : Unused code path elimination
 * Block '<S15>/Check Signal Attributes' : Unused code path elimination
 * Block '<S4>/Delay Estimate' : Unused code path elimination
 * Block '<S34>/Check Signal Attributes' : Unused code path elimination
 * Block '<S5>/SER Display' : Unused code path elimination
 * Block '<S6>/SER Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PhysicalLayerModelUSRP'
 * '<S1>'   : 'PhysicalLayerModelUSRP/Data Source 1'
 * '<S2>'   : 'PhysicalLayerModelUSRP/Data Source 2'
 * '<S3>'   : 'PhysicalLayerModelUSRP/Radio1'
 * '<S4>'   : 'PhysicalLayerModelUSRP/Radio2'
 * '<S5>'   : 'PhysicalLayerModelUSRP/Statistics1'
 * '<S6>'   : 'PhysicalLayerModelUSRP/Statistics2'
 * '<S7>'   : 'PhysicalLayerModelUSRP/Radio1/Receiver'
 * '<S8>'   : 'PhysicalLayerModelUSRP/Radio1/Transmitter'
 * '<S9>'   : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder'
 * '<S10>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver'
 * '<S11>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK Modulation Type'
 * '<S12>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/QAM Modulation Type'
 * '<S13>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Raised Cosine Receive Filter'
 * '<S14>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery'
 * '<S15>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Check Signal Attributes'
 * '<S16>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants'
 * '<S17>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator'
 * '<S18>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling'
 * '<S19>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]'
 * '<S20>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem'
 * '<S21>'  : 'PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1'
 * '<S22>'  : 'PhysicalLayerModelUSRP/Radio1/Transmitter/PSK Modulation Type'
 * '<S23>'  : 'PhysicalLayerModelUSRP/Radio1/Transmitter/QAM Modulation Type'
 * '<S24>'  : 'PhysicalLayerModelUSRP/Radio1/Transmitter/Raised Cosine Transmit Filter'
 * '<S25>'  : 'PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter'
 * '<S26>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver'
 * '<S27>'  : 'PhysicalLayerModelUSRP/Radio2/Transmitter'
 * '<S28>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder'
 * '<S29>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver'
 * '<S30>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK Modulation Type'
 * '<S31>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/QAM Modulation Type'
 * '<S32>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Raised Cosine Receive Filter'
 * '<S33>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery'
 * '<S34>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Check Signal Attributes'
 * '<S35>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants'
 * '<S36>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator'
 * '<S37>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling'
 * '<S38>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]'
 * '<S39>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem'
 * '<S40>'  : 'PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1'
 * '<S41>'  : 'PhysicalLayerModelUSRP/Radio2/Transmitter/PSK Modulation Type'
 * '<S42>'  : 'PhysicalLayerModelUSRP/Radio2/Transmitter/QAM Modulation Type'
 * '<S43>'  : 'PhysicalLayerModelUSRP/Radio2/Transmitter/Raised Cosine Transmit Filter'
 * '<S44>'  : 'PhysicalLayerModelUSRP/Radio2/Transmitter/SDRu Transmitter'
 */
#endif                                 /* RTW_HEADER_PhysicalLayerModelUSRP_h_ */
