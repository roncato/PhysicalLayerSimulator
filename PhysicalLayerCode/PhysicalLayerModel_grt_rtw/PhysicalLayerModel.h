/*
 * PhysicalLayerModel.h
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
#ifndef RTW_HEADER_PhysicalLayerModel_h_
#define RTW_HEADER_PhysicalLayerModel_h_
#include "rtw_modelmap.h"
#ifndef PhysicalLayerModel_COMMON_INCLUDES_
# define PhysicalLayerModel_COMMON_INCLUDES_
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
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* PhysicalLayerModel_COMMON_INCLUDES_ */

#include "PhysicalLayerModel_types.h"

/* Child system includes */
#include "PhysicalLayerModel_Channel.h"
#include "PhysicalLayerModel_Receiver.h"
#include "PhysicalLayerModel_Statistics.h"
#include "PhysicalLayerModel_Transmitter.h"

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

#define PhysicalLayerModel_M_TYPE      RT_MODEL_PhysicalLayerModel_T

/* Block signals (auto storage) */
typedef struct {
  uint8_T FromWorkspace[264];          /* '<S3>/From Workspace' */
  uint8_T FromWorkspace_lddws[264];    /* '<S4>/From Workspace' */
  B_Statistics_PhysicalLayerMo_T Statistics2;/* '<Root>/Statistics2' */
  B_Statistics_PhysicalLayerMo_T Statistics1;/* '<Root>/Statistics1' */
  B_Transmitter_PhysicalLayerMo_T Transmitter_fe4q0;/* '<S6>/Transmitter' */
  B_Receiver_PhysicalLayerModel_T Receiver;/* '<S6>/Receiver' */
  B_Transmitter_PhysicalLayerMo_T Transmitter;/* '<S5>/Transmitter' */
  B_Receiver_PhysicalLayerModel_T Receiver_ewxak;/* '<S5>/Receiver' */
  B_Channel_PhysicalLayerModel_T Channel2;/* '<Root>/Channel2' */
  B_Channel_PhysicalLayerModel_T Channel1;/* '<Root>/Channel1' */
} B_PhysicalLayerModel_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S3>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK_opoi0;         /* '<S4>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S3>/From Workspace' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK_j1ku0;         /* '<S4>/From Workspace' */

  DW_Statistics_PhysicalLayerM_T Statistics2;/* '<Root>/Statistics2' */
  DW_Statistics_PhysicalLayerM_T Statistics1;/* '<Root>/Statistics1' */
  DW_Transmitter_PhysicalLayerM_T Transmitter_fe4q0;/* '<S6>/Transmitter' */
  DW_Receiver_PhysicalLayerMode_T Receiver;/* '<S6>/Receiver' */
  DW_Transmitter_PhysicalLayerM_T Transmitter;/* '<S5>/Transmitter' */
  DW_Receiver_PhysicalLayerMode_T Receiver_ewxak;/* '<S5>/Receiver' */
  DW_Channel_PhysicalLayerMode_T Channel2;/* '<Root>/Channel2' */
  DW_Channel_PhysicalLayerMode_T Channel1;/* '<Root>/Channel1' */
} DW_PhysicalLayerModel_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: a.h)
   * Referenced by:
   *   '<S20>/FIR Decimation'
   *   '<S38>/FIR Decimation'
   */
  real_T pooled1[65];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/M-PSK Modulator Baseband'
   *   '<S34>/M-PSK Modulator Baseband'
   */
  real_T pooled5[32];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S16>/Rectangular QAM Modulator Baseband'
   *   '<S34>/Rectangular QAM Modulator Baseband'
   */
  real_T pooled6[32];
} ConstP_PhysicalLayerModel_T;

/* Parameters (auto storage) */
struct P_PhysicalLayerModel_T_ {
  P_Transmitter_PhysicalLayerMo_T Transmitter_fe4q0;/* '<S6>/Transmitter' */
  P_Receiver_PhysicalLayerModel_T Receiver;/* '<S6>/Receiver' */
  P_Transmitter_PhysicalLayerMo_T Transmitter;/* '<S5>/Transmitter' */
  P_Receiver_PhysicalLayerModel_T Receiver_ewxak;/* '<S5>/Receiver' */
  P_Channel_PhysicalLayerModel_T Channel2;/* '<Root>/Channel2' */
  P_Channel_PhysicalLayerModel_T Channel1;/* '<Root>/Channel1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_PhysicalLayerModel_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[200];
    int32_T* vardimsAddress[200];
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    B_PhysicalLayerModel_T *blockIO;
    P_PhysicalLayerModel_T *defaultParam;
    boolean_T paramIsMalloced;
    DW_PhysicalLayerModel_T *dwork;
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

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

extern P_PhysicalLayerModel_T PhysicalLayerModel_P;/* parameters */

/* Constant parameters (auto storage) */
extern const ConstP_PhysicalLayerModel_T PhysicalLayerModel_ConstP;

/* External data declarations for dependent source files */
extern const creal_T PhysicalLayerModel_RGND_Complex;/* real_T complex ground */

#ifdef __cplusplus

extern "C" {

#endif

  extern const char *RT_MEMORY_ALLOCATION_ERROR;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern RT_MODEL_PhysicalLayerModel_T *PhysicalLayerModel(void);
  extern void PhysicalLayerModel_initialize(RT_MODEL_PhysicalLayerModel_T *const
    PhysicalLayerModel_M);
  extern void PhysicalLayerModel_step(RT_MODEL_PhysicalLayerModel_T *const
    PhysicalLayerModel_M);
  extern void PhysicalLayerModel_terminate(RT_MODEL_PhysicalLayerModel_T
    * PhysicalLayerModel_M);

#ifdef __cplusplus

}
#endif

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  PhysicalLayerModel_GetCAPIStaticMap(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Delay Estimate' : Unused code path elimination
 * Block '<S22>/Check Signal Attributes' : Unused code path elimination
 * Block '<S6>/Delay Estimate' : Unused code path elimination
 * Block '<S40>/Check Signal Attributes' : Unused code path elimination
 * Block '<S7>/SER Display' : Unused code path elimination
 * Block '<S8>/SER Display' : Unused code path elimination
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
 * '<Root>' : 'PhysicalLayerModel'
 * '<S1>'   : 'PhysicalLayerModel/Channel1'
 * '<S2>'   : 'PhysicalLayerModel/Channel2'
 * '<S3>'   : 'PhysicalLayerModel/Data Source 1'
 * '<S4>'   : 'PhysicalLayerModel/Data Source 2'
 * '<S5>'   : 'PhysicalLayerModel/Radio1'
 * '<S6>'   : 'PhysicalLayerModel/Radio2'
 * '<S7>'   : 'PhysicalLayerModel/Statistics1'
 * '<S8>'   : 'PhysicalLayerModel/Statistics2'
 * '<S9>'   : 'PhysicalLayerModel/Channel1/AWGN Channel'
 * '<S10>'  : 'PhysicalLayerModel/Channel1/Interferer'
 * '<S11>'  : 'PhysicalLayerModel/Channel1/Upconverted Spectra'
 * '<S12>'  : 'PhysicalLayerModel/Channel2/AWGN Channel'
 * '<S13>'  : 'PhysicalLayerModel/Channel2/Interferer'
 * '<S14>'  : 'PhysicalLayerModel/Channel2/Upconverted Spectra'
 * '<S15>'  : 'PhysicalLayerModel/Radio1/Receiver'
 * '<S16>'  : 'PhysicalLayerModel/Radio1/Transmitter'
 * '<S17>'  : 'PhysicalLayerModel/Radio1/Receiver/Downconverter'
 * '<S18>'  : 'PhysicalLayerModel/Radio1/Receiver/PSK Modulation Type'
 * '<S19>'  : 'PhysicalLayerModel/Radio1/Receiver/QAM Modulation Type'
 * '<S20>'  : 'PhysicalLayerModel/Radio1/Receiver/Raised Cosine Receive Filter'
 * '<S21>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery'
 * '<S22>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Check Signal Attributes'
 * '<S23>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants'
 * '<S24>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator'
 * '<S25>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Symbol Sampling'
 * '<S26>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]'
 * '<S27>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem'
 * '<S28>'  : 'PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1'
 * '<S29>'  : 'PhysicalLayerModel/Radio1/Transmitter/PSK Modulation Type'
 * '<S30>'  : 'PhysicalLayerModel/Radio1/Transmitter/QAM Modulation Type'
 * '<S31>'  : 'PhysicalLayerModel/Radio1/Transmitter/Raised Cosine Transmit Filter'
 * '<S32>'  : 'PhysicalLayerModel/Radio1/Transmitter/Upconverter'
 * '<S33>'  : 'PhysicalLayerModel/Radio2/Receiver'
 * '<S34>'  : 'PhysicalLayerModel/Radio2/Transmitter'
 * '<S35>'  : 'PhysicalLayerModel/Radio2/Receiver/Downconverter'
 * '<S36>'  : 'PhysicalLayerModel/Radio2/Receiver/PSK Modulation Type'
 * '<S37>'  : 'PhysicalLayerModel/Radio2/Receiver/QAM Modulation Type'
 * '<S38>'  : 'PhysicalLayerModel/Radio2/Receiver/Raised Cosine Receive Filter'
 * '<S39>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery'
 * '<S40>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Check Signal Attributes'
 * '<S41>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants'
 * '<S42>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator'
 * '<S43>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Symbol Sampling'
 * '<S44>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]'
 * '<S45>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem'
 * '<S46>'  : 'PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1'
 * '<S47>'  : 'PhysicalLayerModel/Radio2/Transmitter/PSK Modulation Type'
 * '<S48>'  : 'PhysicalLayerModel/Radio2/Transmitter/QAM Modulation Type'
 * '<S49>'  : 'PhysicalLayerModel/Radio2/Transmitter/Raised Cosine Transmit Filter'
 * '<S50>'  : 'PhysicalLayerModel/Radio2/Transmitter/Upconverter'
 */
#endif                                 /* RTW_HEADER_PhysicalLayerModel_h_ */
