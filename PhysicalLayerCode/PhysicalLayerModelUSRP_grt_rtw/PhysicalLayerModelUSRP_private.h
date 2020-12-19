/*
 * PhysicalLayerModelUSRP_private.h
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
#ifndef RTW_HEADER_PhysicalLayerModelUSRP_private_h_
#define RTW_HEADER_PhysicalLayerModelUSRP_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 rtmSetErrorStatus(PhysicalLayerModelUSRP_M, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

#include "dsp_rt.h"                    /* DSP System Toolbox general run time support functions */

/* Used by FromWorkspace Block: '<S1>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void interpBilinear_MultiChan_real_T(real_T out[], const real_T src[],
  const real_T pts[], const int32_T nSamps, const int32_T nChans, const int32_T
  nSampsI);
extern void UpFIR_DF_Z_D(const creal_T inArray[], const real_T coefArra[],
  creal_T tap0Array[], creal_T outArray[], int32_T tapIdx[], int32_T outIdx,
  int32_T numChans, int32_T inFrameSize, int32_T iFactor, int32_T
  polyphaseFiltLen);

#endif                                 /* RTW_HEADER_PhysicalLayerModelUSRP_private_h_ */
