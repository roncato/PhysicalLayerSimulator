/*
 * Code generation for system system '<Root>/Statistics2'
 * For more details, see corresponding source file PhysicalLayerModelU_Statistics2.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModelU_Statistics2_h_
#define RTW_HEADER_PhysicalLayerModelU_Statistics2_h_
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

#include "PhysicalLayerModelUSRP_types.h"

/* Block signals for system '<Root>/Statistics2' */
typedef struct {
  real_T ErrorRateCalculation[3];      /* '<S6>/Error Rate Calculation' */
} B_Statistics2_PhysicalLayerMo_T;

/* Block states (auto storage) for system '<Root>/Statistics2' */
typedef struct {
  real_T errors;                       /* '<S6>/Error Rate Calculation' */
  real_T symbols;                      /* '<S6>/Error Rate Calculation' */
  struct {
    void *LoggedData;
  } ErrorVars_PWORK;                   /* '<S6>/Error Vars' */

  struct {
    void *LoggedData;
  } Rx2_PWORK;                         /* '<S6>/Rx2' */

  struct {
    void *LoggedData;
  } Tx2_PWORK;                         /* '<S6>/Tx2' */

  int32_T STDelay;                     /* '<S6>/Error Rate Calculation' */
  int32_T curTx;                       /* '<S6>/Error Rate Calculation' */
  uint8_T txBuff[9];                   /* '<S6>/Error Rate Calculation' */
  boolean_T useFrame[264];             /* '<S6>/Error Rate Calculation' */
} DW_Statistics2_PhysicalLayerM_T;

void PhysicalLayerM_Statistics2_Init(DW_Statistics2_PhysicalLayerM_T *localDW);
void PhysicalLayer_Statistics2_Start(RT_MODEL_PhysicalLayerModelUS_T * const
  PhysicalLayerModelUSRP_M, DW_Statistics2_PhysicalLayerM_T *localDW);
void PhysicalLayerModelU_Statistics2(const uint8_T rtu_Tx[264], const uint8_T
  rtu_Rx[264], B_Statistics2_PhysicalLayerMo_T *localB,
  DW_Statistics2_PhysicalLayerM_T *localDW);

#endif                                 /* RTW_HEADER_PhysicalLayerModelU_Statistics2_h_ */
