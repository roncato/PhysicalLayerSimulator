/*
 * PhysicalLayerModelUSRP_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "PhysicalLayerModelUSRP_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "PhysicalLayerModelUSRP.h"
#include "PhysicalLayerModelUSRP_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("PhysicalLayerModelUSRP/Data Source 1/From Workspace"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("PhysicalLayerModelUSRP/Data Source 2/From Workspace"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 3, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver"),
    TARGET_STRING(""), 1, 1, 0, 0, 1 },

  { 4, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver"),
    TARGET_STRING(""), 2, 2, 0, 0, 1 },

  { 5, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver"),
    TARGET_STRING(""), 1, 1, 0, 0, 1 },

  { 7, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver"),
    TARGET_STRING(""), 2, 2, 0, 0, 1 },

  { 8, 13, TARGET_STRING(
    "PhysicalLayerModelUSRP/Statistics1/Error Rate Calculation"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 9, 14, TARGET_STRING(
    "PhysicalLayerModelUSRP/Statistics2/Error Rate Calculation"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 10, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 11, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder"),
    TARGET_STRING(""), 1, 1, 0, 0, 1 },

  { 12, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder"),
    TARGET_STRING(""), 2, 2, 0, 0, 1 },

  { 13, 5, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/PSK Gain"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 14, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/Multiport Switch"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 15, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/M-PSK Modulator Baseband"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 16, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/Rectangular QAM Modulator Baseband"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 17, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/Variable Fractional Delay"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 18, 6, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/PSK On"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 19, 6, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/QAM On"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 20, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 21, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder"),
    TARGET_STRING(""), 1, 1, 0, 0, 1 },

  { 22, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder"),
    TARGET_STRING(""), 2, 2, 0, 0, 1 },

  { 23, 11, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/PSK Gain"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 24, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/Multiport Switch"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 25, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/M-PSK Modulator Baseband"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 26, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/Rectangular QAM Modulator Baseband"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 27, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/Variable Fractional Delay"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 28, 12, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/PSK On"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 29, 12, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/QAM On"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 30, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK Gain"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 31, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Multiport Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 32, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/M-PSK Demodulator Baseband"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 33, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Rectangular QAM Demodulator Baseband"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 34, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK On"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 35, 3, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/QAM On"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 36, 4, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/Gain"),
    TARGET_STRING(""), 0, 1, 3, 0, 0 },

  { 37, 4, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/usrp_uhd_sfunrx"),
    TARGET_STRING(""), 0, 3, 3, 0, 0 },

  { 38, 4, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/usrp_uhd_sfunrx"),
    TARGET_STRING(""), 1, 4, 4, 0, 0 },

  { 39, 4, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/usrp_uhd_sfunrx"),
    TARGET_STRING(""), 2, 4, 4, 0, 0 },

  { 40, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 41, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 42, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 43, 6, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter/usrp_uhd_sfuntx"),
    TARGET_STRING(""), 0, 4, 4, 0, 0 },

  { 44, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK Gain"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 45, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Multiport Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 46, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/M-PSK Demodulator Baseband"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 47, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Rectangular QAM Demodulator Baseband"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 48, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK On"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 49, 9, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/QAM On"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 50, 10, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/Gain"),
    TARGET_STRING(""), 0, 1, 3, 0, 0 },

  { 51, 10, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/usrp_uhd_sfunrx"),
    TARGET_STRING(""), 0, 3, 3, 0, 0 },

  { 52, 10, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/usrp_uhd_sfunrx"),
    TARGET_STRING(""), 1, 4, 4, 0, 0 },

  { 53, 10, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/usrp_uhd_sfunrx"),
    TARGET_STRING(""), 2, 4, 4, 0, 0 },

  { 54, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 55, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 56, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 57, 12, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Transmitter/SDRu Transmitter/usrp_uhd_sfuntx"),
    TARGET_STRING(""), 0, 4, 4, 0, 0 },

  { 58, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 59, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 60, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Raised Cosine Receive Filter/FIR Decimation"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 61, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 62, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 63, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 64, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Raised Cosine Receive Filter/FIR Decimation"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 65, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 66, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 67, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Sum"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 68, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Sum1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 69, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Complex to Magnitude-Angle"),
    TARGET_STRING(""), 0, 2, 4, 0, 1 },

  { 70, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING(""), 0, 2, 4, 0, 1 },

  { 71, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 72, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Math Function"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 73, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sum"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 74, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 75, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 1, 2, 2, 0, 1 },

  { 76, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Real-Imag to Complex"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 77, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Interpolation"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 78, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Interpolation1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 79, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 80, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 81, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Abs"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 82, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Fcn"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 83, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Merge"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 84, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Sum2"),
    TARGET_STRING(""), 0, 2, 4, 0, 1 },

  { 85, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 86, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Sum"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 87, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Sum1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 88, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Complex to Magnitude-Angle"),
    TARGET_STRING(""), 0, 2, 4, 0, 1 },

  { 89, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING(""), 0, 2, 4, 0, 1 },

  { 90, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING(""), 0, 1, 2, 0, 1 },

  { 91, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Math Function"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 92, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sum"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 93, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 0, 2, 2, 0, 1 },

  { 94, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 1, 2, 2, 0, 1 },

  { 95, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Real-Imag to Complex"),
    TARGET_STRING(""), 0, 1, 0, 0, 1 },

  { 96, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Interpolation"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 97, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Symbol Sampling/Interpolation1"),
    TARGET_STRING(""), 0, 2, 0, 0, 1 },

  { 98, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 99, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 100, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Abs"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 101, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Fcn"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 102, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Merge"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 103, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/Sum2"),
    TARGET_STRING(""), 0, 2, 4, 0, 1 },

  { 104, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 105, 3, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1/In1"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 106, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 107, 9, TARGET_STRING(
    "PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1/In1"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 108, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/Delay Factor"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 109, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/Modulation Type"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 110, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/PSK Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 111, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/PSK On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 112, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/QAM On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 113, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/Delay Factor"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 114, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/Modulation Type"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 115, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/PSK Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 116, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/PSK On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 117, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/QAM On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 118, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Modulation Type"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 119, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 120, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 121, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/QAM On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 122, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/port_1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 123, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/port_2"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 124, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/port_3"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 125, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/port_4"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 126, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/SDRu Receiver/Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 127, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 128, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 129, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING("FILTER_COEFF"), 2, 5, 0 },

  { 130, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter/port_1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 131, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter/port_2"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 132, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter/port_3"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 133, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Transmitter/SDRu Transmitter/port_4"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 134, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Modulation Type"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 135, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 136, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 137, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/QAM On"),
    TARGET_STRING("Threshold"), 0, 4, 0 },

  { 138, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/port_1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 139, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/port_2"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 140, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/port_3"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 141, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/port_4"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 142, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/SDRu Receiver/Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 143, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 144, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 145, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING("FILTER_COEFF"), 2, 5, 0 },

  { 146, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/SDRu Transmitter/port_1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 147, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/SDRu Transmitter/port_2"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 148, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/SDRu Transmitter/port_3"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 149, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Transmitter/SDRu Transmitter/port_4"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 150, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 151, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 152, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING("Gain"), 2, 6, 0 },

  { 153, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 154, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 5, 4, 0 },

  { 155, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING("Gain"), 2, 6, 0 },

  { 156, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Constant"),
    TARGET_STRING("Value"), 2, 6, 0 },

  { 157, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Constant1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 158, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 159, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 160, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING("Gain"), 1, 3, 0 },

  { 161, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Constant"),
    TARGET_STRING("Value"), 2, 6, 0 },

  { 162, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Constant1"),
    TARGET_STRING("Value"), 2, 4, 0 },

  { 163, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 164, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 165, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING("Gain"), 1, 3, 0 },

  { 166, TARGET_STRING("PhysicalLayerModelUSRP/Radio1/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  { 167, TARGET_STRING("PhysicalLayerModelUSRP/Radio2/Receiver/Decoder/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING("Gain"), 2, 4, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void PhysicalLayerModelUSRP_InitializeDataAddr
  (RT_MODEL_PhysicalLayerModelUS_T *const PhysicalLayerModelUSRP_M, void
   * dataAddr[], B_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_B,
   P_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_P)
{
  void* *rtDataAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap
          ( &(PhysicalLayerModelUSRP_M->DataMapInfo.mmi) ) );
  rtDataAddrMap = (void* *) malloc(168 * sizeof(void* ));
  dataAddr[0] = (void*) (&PhysicalLayerModelUSRP_B->FromWorkspace[0]);
  dataAddr[1] = (void*) (&PhysicalLayerModelUSRP_B->FromWorkspace_lddws[0]);
  dataAddr[2] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.MultiportSwitch[0]);
  dataAddr[3] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.RealImagtoComplex[0].re);
  dataAddr[4] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.VectorintermsofSamples[0]);
  dataAddr[5] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.MultiportSwitch[0]);
  dataAddr[6] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.RealImagtoComplex[0]
    .re);
  dataAddr[7] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.VectorintermsofSamples[0]);
  dataAddr[8] = (void*)
    (&PhysicalLayerModelUSRP_B->Statistics1.ErrorRateCalculation[0]);
  dataAddr[9] = (void*)
    (&PhysicalLayerModelUSRP_B->Statistics2.ErrorRateCalculation[0]);
  dataAddr[10] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.MultiportSwitch[0]);
  dataAddr[11] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.RealImagtoComplex[0].re);
  dataAddr[12] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.VectorintermsofSamples[0]);
  dataAddr[13] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter.PSKGain[0].re);
  dataAddr[14] = (void*) (&PhysicalLayerModelUSRP_B->
    Transmitter.MultiportSwitch[0].re);
  dataAddr[15] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter.MPSKModulatorBaseband[0].re);
  dataAddr[16] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter.RectangularQAMModulatorBaseband[0].
     re);
  dataAddr[17] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter.VariableFractionalDelay[0].re);
  dataAddr[18] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter.PSKOn[0]);
  dataAddr[19] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter.QAMOn[0]);
  dataAddr[20] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.MultiportSwitch[0]);
  dataAddr[21] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.RealImagtoComplex
    [0].re);
  dataAddr[22] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.VectorintermsofSamples[0]);
  dataAddr[23] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.PSKGain[0]
    .re);
  dataAddr[24] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.MultiportSwitch[0].re);
  dataAddr[25] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.MPSKModulatorBaseband[0].re);
  dataAddr[26] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.RectangularQAMModulatorBaseband
     [0].re);
  dataAddr[27] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.VariableFractionalDelay[0].re);
  dataAddr[28] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.PSKOn[0]);
  dataAddr[29] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.QAMOn[0]);
  dataAddr[30] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.PSKGain[0].
    re);
  dataAddr[31] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.MultiportSwitch[0]);
  dataAddr[32] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.MPSKDemodulatorBaseband[0]);
  dataAddr[33] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.RectangularQAMDemodulatorBaseba[0]);
  dataAddr[34] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.PSKOn[0].re);
  dataAddr[35] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.QAMOn[0].re);
  dataAddr[36] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Gain[0].re);
  dataAddr[37] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.usrp_uhd_sfunrx_o1[0].re);
  dataAddr[38] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.usrp_uhd_sfunrx_o2);
  dataAddr[39] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.usrp_uhd_sfunrx_o3);
  dataAddr[40] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter.Compare_fxhmg);
  dataAddr[41] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter.Compare);
  dataAddr[42] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter.FIRInterpolation[0].re);
  dataAddr[43] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter.usrp_uhd_sfuntx);
  dataAddr[44] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.PSKGain[0].re);
  dataAddr[45] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.MultiportSwitch[0]);
  dataAddr[46] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.MPSKDemodulatorBaseband[0]);
  dataAddr[47] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.RectangularQAMDemodulatorBaseba[0]);
  dataAddr[48] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.PSKOn[0].re);
  dataAddr[49] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.QAMOn[0].re);
  dataAddr[50] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Gain[0].re);
  dataAddr[51] = (void*) (&PhysicalLayerModelUSRP_B->
    Receiver.usrp_uhd_sfunrx_o1[0].re);
  dataAddr[52] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.usrp_uhd_sfunrx_o2);
  dataAddr[53] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.usrp_uhd_sfunrx_o3);
  dataAddr[54] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.Compare_fxhmg);
  dataAddr[55] = (void*) (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.Compare);
  dataAddr[56] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.FIRInterpolation[0].re);
  dataAddr[57] = (void*)
    (&PhysicalLayerModelUSRP_B->Transmitter_k4fhb.usrp_uhd_sfuntx);
  dataAddr[58] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Compare);
  dataAddr[59] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Compare_fjcnv);
  dataAddr[60] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.FIRDecimation[0].re);
  dataAddr[61] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.VectorintermsofSamples[0]);
  dataAddr[62] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Compare);
  dataAddr[63] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Compare_fjcnv);
  dataAddr[64] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.FIRDecimation[0].
    re);
  dataAddr[65] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.VectorintermsofSamples[0]);
  dataAddr[66] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Gain_nyex1[0]);
  dataAddr[67] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum_hha5s[0]);
  dataAddr[68] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum1[0]);
  dataAddr[69] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.ComplextoMagnitudeAngle);
  dataAddr[70] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Sensitivity1);
  dataAddr[71] = (void*) (&PhysicalLayerModelUSRP_B->
    Receiver_ewxak.Sensitivity3[0].re);
  dataAddr[72] = (void*) (&PhysicalLayerModelUSRP_B->
    Receiver_ewxak.MathFunction[0]);
  dataAddr[73] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum.re);
  dataAddr[74] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.ComplextoRealImag2_o1[0]);
  dataAddr[75] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.ComplextoRealImag2_o2[0]);
  dataAddr[76] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.RealImagtoComplex[0].re);
  dataAddr[77] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Interpolation[0]);
  dataAddr[78] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Interpolation1[0]);
  dataAddr[79] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Merge);
  dataAddr[80] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Merge);
  dataAddr[81] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Abs);
  dataAddr[82] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Fcn);
  dataAddr[83] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Merge);
  dataAddr[84] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Sum2);
  dataAddr[85] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Gain_nyex1[0]);
  dataAddr[86] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Sum_hha5s[0]);
  dataAddr[87] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Sum1[0]);
  dataAddr[88] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.ComplextoMagnitudeAngle);
  dataAddr[89] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Sensitivity1);
  dataAddr[90] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Sensitivity3[0].re);
  dataAddr[91] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.MathFunction[0]);
  dataAddr[92] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Sum.re);
  dataAddr[93] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.ComplextoRealImag2_o1[0]);
  dataAddr[94] = (void*)
    (&PhysicalLayerModelUSRP_B->Receiver.ComplextoRealImag2_o2[0]);
  dataAddr[95] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.RealImagtoComplex
    [0].re);
  dataAddr[96] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Interpolation[0]);
  dataAddr[97] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Interpolation1[0]);
  dataAddr[98] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Merge);
  dataAddr[99] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Merge);
  dataAddr[100] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Abs);
  dataAddr[101] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Fcn);
  dataAddr[102] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Merge);
  dataAddr[103] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Sum2);
  dataAddr[104] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Merge);
  dataAddr[105] = (void*) (&PhysicalLayerModelUSRP_B->Receiver_ewxak.Merge);
  dataAddr[106] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Merge);
  dataAddr[107] = (void*) (&PhysicalLayerModelUSRP_B->Receiver.Merge);
  dataAddr[108] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter.DelayFactor_Value);
  dataAddr[109] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter.ModulationType_Value);
  dataAddr[110] = (void*) (&PhysicalLayerModelUSRP_P->Transmitter.PSKGain_Gain);
  dataAddr[111] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter.PSKOn_Threshold);
  dataAddr[112] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter.QAMOn_Threshold);
  dataAddr[113] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.DelayFactor_Value);
  dataAddr[114] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.ModulationType_Value);
  dataAddr[115] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.PSKGain_Gain);
  dataAddr[116] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.PSKOn_Threshold);
  dataAddr[117] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.QAMOn_Threshold);
  dataAddr[118] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.ModulationType_Value);
  dataAddr[119] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.PSKGain_Gain);
  dataAddr[120] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.PSKOn_Threshold);
  dataAddr[121] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.QAMOn_Threshold);
  dataAddr[122] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.port_1_Value);
  dataAddr[123] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.port_2_Value);
  dataAddr[124] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.port_3_Value);
  dataAddr[125] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.port_4_Value);
  dataAddr[126] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Gain_Gain_ima5v);
  dataAddr[127] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter.Constant_Value_lrtfa);
  dataAddr[128] = (void*) (&PhysicalLayerModelUSRP_P->Transmitter.Constant_Value);
  dataAddr[129] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter.FIRInterpolation_FILTER_COEFF[0]);
  dataAddr[130] = (void*) (&PhysicalLayerModelUSRP_P->Transmitter.port_1_Value);
  dataAddr[131] = (void*) (&PhysicalLayerModelUSRP_P->Transmitter.port_2_Value);
  dataAddr[132] = (void*) (&PhysicalLayerModelUSRP_P->Transmitter.port_3_Value);
  dataAddr[133] = (void*) (&PhysicalLayerModelUSRP_P->Transmitter.port_4_Value);
  dataAddr[134] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver.ModulationType_Value);
  dataAddr[135] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.PSKGain_Gain);
  dataAddr[136] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.PSKOn_Threshold);
  dataAddr[137] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.QAMOn_Threshold);
  dataAddr[138] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.port_1_Value);
  dataAddr[139] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.port_2_Value);
  dataAddr[140] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.port_3_Value);
  dataAddr[141] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.port_4_Value);
  dataAddr[142] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.Gain_Gain_ima5v);
  dataAddr[143] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.Constant_Value_lrtfa);
  dataAddr[144] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.Constant_Value);
  dataAddr[145] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.FIRInterpolation_FILTER_COEFF
     [0]);
  dataAddr[146] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.port_1_Value);
  dataAddr[147] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.port_2_Value);
  dataAddr[148] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.port_3_Value);
  dataAddr[149] = (void*)
    (&PhysicalLayerModelUSRP_P->Transmitter_k4fhb.port_4_Value);
  dataAddr[150] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Constant_Value_jhhlt);
  dataAddr[151] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Constant_Value_puofi);
  dataAddr[152] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.VectorintermsofSamples_Gain[0]);
  dataAddr[153] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver.Constant_Value_jhhlt);
  dataAddr[154] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver.Constant_Value_puofi);
  dataAddr[155] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver.VectorintermsofSamples_Gain[0]);
  dataAddr[156] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Constant_Value[0]);
  dataAddr[157] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Constant1_Value);
  dataAddr[158] = (void*) (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Gain_Gain);
  dataAddr[159] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Sensitivity1_Gain);
  dataAddr[160] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Sensitivity3_Gain[0].re);
  dataAddr[161] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.Constant_Value[0]);
  dataAddr[162] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.Constant1_Value);
  dataAddr[163] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.Gain_Gain);
  dataAddr[164] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.Sensitivity1_Gain);
  dataAddr[165] = (void*) (&PhysicalLayerModelUSRP_P->
    Receiver.Sensitivity3_Gain[0].re);
  dataAddr[166] = (void*)
    (&PhysicalLayerModelUSRP_P->Receiver_ewxak.Settozero_Gain);
  dataAddr[167] = (void*) (&PhysicalLayerModelUSRP_P->Receiver.Settozero_Gain);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void PhysicalLayerModelUSRP_InitializeVarDimsAddr
  (RT_MODEL_PhysicalLayerModelUS_T *const PhysicalLayerModelUSRP_M, int32_T
   * vardimsAddr[])
{
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetVarDimsAddressMap
          ( &(PhysicalLayerModelUSRP_M->DataMapInfo.mmi) ) );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  vardimsAddr[0] = (NULL);
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "struct", "creal_T", 0, 0, sizeof(creal_T), SS_DOUBLE, 1, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "struct", "cint16_T", 0, 0, sizeof(cint16_T), SS_INT16, 1, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_SCALAR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  264,                                 /* 0 */
  1,                                   /* 1 */
  3,                                   /* 2 */
  1,                                   /* 3 */
  2112,                                /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  1,                                   /* 7 */
  9,                                   /* 8 */
  8                                    /* 9 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.00026399999999999997, 0.0
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 1 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Root Inputs: {rootInputs, numRootInputs}
   * Root Outputs: {rootOutputs, numRootOutputs}
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 108,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 60,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", (NULL), 0,
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  PhysicalLayerModelUSRP_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void PhysicalLayerModelUSRP_InitializeDataMapInfo
  (RT_MODEL_PhysicalLayerModelUS_T *const PhysicalLayerModelUSRP_M,
   B_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_B,
   P_PhysicalLayerModelUSRP_T *PhysicalLayerModelUSRP_P)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  PhysicalLayerModelUSRP_InitializeDataAddr(PhysicalLayerModelUSRP_M,
    PhysicalLayerModelUSRP_M->DataMapInfo.dataAddress,
    PhysicalLayerModelUSRP_M->ModelData.blockIO,
    PhysicalLayerModelUSRP_M->ModelData.defaultParam);
  rtwCAPI_SetDataAddressMap(PhysicalLayerModelUSRP_M->DataMapInfo.mmi,
    PhysicalLayerModelUSRP_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  PhysicalLayerModelUSRP_InitializeVarDimsAddr(PhysicalLayerModelUSRP_M,
    PhysicalLayerModelUSRP_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(PhysicalLayerModelUSRP_M->DataMapInfo.mmi,
    PhysicalLayerModelUSRP_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, (NULL));

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(PhysicalLayerModelUSRP_M->DataMapInfo.mmi,
    (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(PhysicalLayerModelUSRP_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void PhysicalLayerModelUSRP_host_InitializeDataMapInfo
    (PhysicalLayerModelUSRP_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: PhysicalLayerModelUSRP_capi.c */
