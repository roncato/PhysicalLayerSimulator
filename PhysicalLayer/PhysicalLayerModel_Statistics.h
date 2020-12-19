/*
 * Code generation for system system '<Root>/Statistics'
 * For more details, see corresponding source file PhysicalLayerModel_Statistics1.c
 *
 */
#ifndef RTW_HEADER_PhysicalLayerModel_Statistics1_h_
#define RTW_HEADER_PhysicalLayerModel_Statistics1_h_
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

/* Block signals for system '<Root>/Statistics' */
typedef struct {
	real_T ErrorRateCalculation[3];      /* '<S7>/Error Rate Calculation' */
} B_Statistics_PhysicalLayerMo_T;

/* Block states (auto storage) for system '<Root>/Statistics' */
typedef struct {
  real_T errors;                       /* '<S7>/Error Rate Calculation' */
  real_T symbols;                      /* '<S7>/Error Rate Calculation' */
  struct {
    void *LoggedData;
  } ErrorVars_PWORK;                   /* '<S7>/Error Vars' */

  struct {
    void *LoggedData;
  } Rx_PWORK;                         /* '<S7>/Rx1' */

  struct {
    void *LoggedData;
  } Tx_PWORK;                         /* '<S7>/Tx1' */

  int32_T STDelay;                     /* '<S7>/Error Rate Calculation' */
  int32_T curTx;                       /* '<S7>/Error Rate Calculation' */
  uint8_T txBuff[9];                   /* '<S7>/Error Rate Calculation' */
  boolean_T useFrame[264];             /* '<S7>/Error Rate Calculation' */
} DW_Statistics_PhysicalLayerM_T;

void PhysicalLayerM_Statistics_Init(DW_Statistics_PhysicalLayerM_T *localDW);
void PhysicalLayer_Statistics_Start(RT_MODEL_PhysicalLayerModel_T * const
  PhysicalLayerModel_M, DW_Statistics_PhysicalLayerM_T *localDW);
void PhysicalLayerModel_Statistics(const uint8_T rtu_Tx[264], const uint8_T
  rtu_Rx[264], B_Statistics_PhysicalLayerMo_T *localB,
  DW_Statistics_PhysicalLayerM_T *localDW);
void PhysicalLayerM_Statistics_Term(void);
#endif                                 /* RTW_HEADER_PhysicalLayerModel_Statistics1_h_ */
