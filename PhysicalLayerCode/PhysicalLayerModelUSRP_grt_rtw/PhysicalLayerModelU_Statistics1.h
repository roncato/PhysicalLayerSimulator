/*
 * Code generation for system system '<Root>/Statistics1'
 * For more details, see corresponding source file PhysicalLayerModelU_Statistics1.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModelU_Statistics1_h_
#define RTW_HEADER_PhysicalLayerModelU_Statistics1_h_
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

/* Block signals for system '<Root>/Statistics1' */
typedef struct {
  real_T ErrorRateCalculation[3];      /* '<S5>/Error Rate Calculation' */
} B_Statistics1_PhysicalLayerMo_T;

/* Block states (auto storage) for system '<Root>/Statistics1' */
typedef struct {
  real_T errors;                       /* '<S5>/Error Rate Calculation' */
  real_T symbols;                      /* '<S5>/Error Rate Calculation' */
  struct {
    void *LoggedData;
  } ErrorVars_PWORK;                   /* '<S5>/Error Vars' */

  struct {
    void *LoggedData;
  } Rx1_PWORK;                         /* '<S5>/Rx1' */

  struct {
    void *LoggedData;
  } Tx1_PWORK;                         /* '<S5>/Tx1' */

  int32_T STDelay;                     /* '<S5>/Error Rate Calculation' */
  int32_T curTx;                       /* '<S5>/Error Rate Calculation' */
  uint8_T txBuff[9];                   /* '<S5>/Error Rate Calculation' */
  boolean_T useFrame[264];             /* '<S5>/Error Rate Calculation' */
} DW_Statistics1_PhysicalLayerM_T;

void PhysicalLayerM_Statistics1_Init(DW_Statistics1_PhysicalLayerM_T *localDW);
void PhysicalLayer_Statistics1_Start(RT_MODEL_PhysicalLayerModelUS_T * const
  PhysicalLayerModelUSRP_M, DW_Statistics1_PhysicalLayerM_T *localDW);
void PhysicalLayerModelU_Statistics1(const uint8_T rtu_Tx[264], const uint8_T
  rtu_Rx[264], B_Statistics1_PhysicalLayerMo_T *localB,
  DW_Statistics1_PhysicalLayerM_T *localDW);

#endif                                 /* RTW_HEADER_PhysicalLayerModelU_Statistics1_h_ */
