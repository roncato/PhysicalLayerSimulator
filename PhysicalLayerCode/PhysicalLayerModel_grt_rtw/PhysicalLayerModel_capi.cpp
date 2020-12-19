/*
 * PhysicalLayerModel_capi.cpp
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "PhysicalLayerModel_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "PhysicalLayerModel.h"
#include "PhysicalLayerModel_private.h"
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
  { 0, 1, TARGET_STRING("PhysicalLayerModel/Channel1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 2, TARGET_STRING("PhysicalLayerModel/Channel2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 1, TARGET_STRING("PhysicalLayerModel/Channel1/Add1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 2, TARGET_STRING("PhysicalLayerModel/Channel2/Add1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("PhysicalLayerModel/Data Source 1/From Workspace"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 5, 0, TARGET_STRING("PhysicalLayerModel/Data Source 2/From Workspace"),
    TARGET_STRING(""), 0, 1, 1, 0, 1 },

  { 6, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 7, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver"),
    TARGET_STRING(""), 1, 2, 1, 0, 0 },

  { 8, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver"),
    TARGET_STRING(""), 2, 0, 1, 0, 0 },

  { 9, 7, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 11, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver"),
    TARGET_STRING(""), 1, 2, 1, 0, 0 },

  { 12, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver"),
    TARGET_STRING(""), 2, 0, 1, 0, 0 },

  { 13, 12, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 13, TARGET_STRING(
    "PhysicalLayerModel/Statistics1/Error Rate Calculation"),
    TARGET_STRING(""), 0, 0, 2, 0, 1 },

  { 15, 14, TARGET_STRING(
    "PhysicalLayerModel/Statistics2/Error Rate Calculation"),
    TARGET_STRING(""), 0, 0, 2, 0, 1 },

  { 16, 1, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 1, TARGET_STRING(
    "PhysicalLayerModel/Channel1/AWGN Channel/Random Source"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 1, TARGET_STRING(
    "PhysicalLayerModel/Channel1/Interferer/Complex to Real-Imag"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 1, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 1, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 21, 1, TARGET_STRING(
    "PhysicalLayerModel/Channel1/Interferer/Interferer Tone "),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 22, 1, TARGET_STRING(
    "PhysicalLayerModel/Channel1/Upconverted Spectra/Matrix Concatenation"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 23, 2, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 24, 2, TARGET_STRING(
    "PhysicalLayerModel/Channel2/AWGN Channel/Random Source"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 25, 2, TARGET_STRING(
    "PhysicalLayerModel/Channel2/Interferer/Complex to Real-Imag"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 2, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 27, 2, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 28, 2, TARGET_STRING(
    "PhysicalLayerModel/Channel2/Interferer/Interferer Tone "),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 29, 2, TARGET_STRING(
    "PhysicalLayerModel/Channel2/Upconverted Spectra/Matrix Concatenation"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 30, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/PSK Gain"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 31, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Multiport Switch"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 32, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/M-PSK Demodulator Baseband"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 33, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Rectangular QAM Demodulator Baseband"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 34, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/PSK On"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 35, 5, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/QAM On"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 36, 6, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/PSK Gain"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 37, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Multiport Switch"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 38, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/M-PSK Modulator Baseband"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 39, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Rectangular QAM Modulator Baseband"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 40, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Variable Fractional Delay"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 41, 7, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/PSK On"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 42, 7, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/QAM On"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 43, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/PSK Gain"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 44, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Multiport Switch"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 45, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/M-PSK Demodulator Baseband"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 46, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Rectangular QAM Demodulator Baseband"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 47, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/PSK On"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 48, 10, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/QAM On"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 49, 11, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/PSK Gain"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 50, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Multiport Switch"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 51, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/M-PSK Modulator Baseband"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 52, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Rectangular QAM Modulator Baseband"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 53, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Variable Fractional Delay"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 54, 12, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/PSK On"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 55, 12, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/QAM On"),
    TARGET_STRING(""), 0, 1, 1, 0, 0 },

  { 56, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Downconverter/Conjugate"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 57, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Downconverter/Product1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 58, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 59, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 60, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 61, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Raised Cosine Receive Filter/FIR Decimation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 62, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 63, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 64, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 65, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 66, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Upconverter/Complex to Real-Imag"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 67, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Upconverter/Product"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 68, 7, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 69, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Downconverter/Conjugate"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 70, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Downconverter/Product1"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 71, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 72, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 73, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 74, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Raised Cosine Receive Filter/FIR Decimation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 75, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 76, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/PSK Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 77, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/QAM Modulation Type/Compare"),
    TARGET_STRING(""), 0, 1, 4, 0, 1 },

  { 78, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 79, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Upconverter/Complex to Real-Imag"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 80, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Upconverter/Product"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 81, 12, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 82, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 83, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Sum"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 84, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Sum1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 85, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Complex to Magnitude-Angle"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 86, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 87, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 88, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 89, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sum"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 90, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 91, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 92, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Symbol Sampling/Real-Imag to Complex"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 93, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Symbol Sampling/Interpolation"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 94, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Symbol Sampling/Interpolation1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 95, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 96, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 97, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/Abs"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 98, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/Fcn"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 99, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/Merge"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 100, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/Sum2"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 101, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 102, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Sum"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 103, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Sum1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 104, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Complex to Magnitude-Angle"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 105, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 106, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING(""), 0, 2, 0, 0, 0 },

  { 107, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Math Function"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 108, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sum"),
    TARGET_STRING(""), 0, 2, 4, 0, 0 },

  { 109, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 110, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Symbol Sampling/Complex to Real-Imag2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 111, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Symbol Sampling/Real-Imag to Complex"),
    TARGET_STRING(""), 0, 2, 1, 0, 0 },

  { 112, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Symbol Sampling/Interpolation"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 113, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Symbol Sampling/Interpolation1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 114, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 115, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 116, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/Abs"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 117, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/Fcn"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 118, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/Merge"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 119, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/Sum2"),
    TARGET_STRING(""), 0, 0, 4, 0, 0 },

  { 120, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 121, 5, TARGET_STRING(
    "PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1/In1"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 122, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  { 123, 10, TARGET_STRING(
    "PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem1/In1"),
    TARGET_STRING(""), 0, 0, 4, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 124, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING("Seed"), 3, 4, 0 },

  { 125, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING("SNR"), 0, 4, 0 },

  { 126, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING("SPOW"), 0, 4, 0 },

  { 127, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Random Source"),
    TARGET_STRING("MeanRTP"), 0, 4, 0 },

  { 128, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Random Source"),
    TARGET_STRING("VarianceRTP"), 0, 4, 0 },

  { 129, TARGET_STRING("PhysicalLayerModel/Channel1/AWGN Channel/Random Source"),
    TARGET_STRING("InitSeed"), 3, 4, 0 },

  { 130, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Constant"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 131, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 132, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Interferer Tone "),
    TARGET_STRING("Amplitude"), 0, 4, 0 },

  { 133, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Interferer Tone "),
    TARGET_STRING("Frequency"), 0, 4, 0 },

  { 134, TARGET_STRING("PhysicalLayerModel/Channel1/Interferer/Interferer Tone "),
    TARGET_STRING("Phase"), 0, 4, 0 },

  { 135, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING("Seed"), 3, 4, 0 },

  { 136, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING("SNR"), 0, 4, 0 },

  { 137, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Dynamic AWGN"),
    TARGET_STRING("SPOW"), 0, 4, 0 },

  { 138, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Random Source"),
    TARGET_STRING("MeanRTP"), 0, 4, 0 },

  { 139, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Random Source"),
    TARGET_STRING("VarianceRTP"), 0, 4, 0 },

  { 140, TARGET_STRING("PhysicalLayerModel/Channel2/AWGN Channel/Random Source"),
    TARGET_STRING("InitSeed"), 3, 4, 0 },

  { 141, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Constant"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 142, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 143, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Interferer Tone "),
    TARGET_STRING("Amplitude"), 0, 4, 0 },

  { 144, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Interferer Tone "),
    TARGET_STRING("Frequency"), 0, 4, 0 },

  { 145, TARGET_STRING("PhysicalLayerModel/Channel2/Interferer/Interferer Tone "),
    TARGET_STRING("Phase"), 0, 4, 0 },

  { 146, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Modulation Type"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 147, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/PSK Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 148, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/PSK On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 149, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/QAM On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 150, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/Delay Factor"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 151, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/Modulation Type"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 152, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/PSK Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 153, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/PSK On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 154, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/QAM On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 155, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Modulation Type"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 156, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/PSK Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 157, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/PSK On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 158, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/QAM On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 159, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/Delay Factor"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 160, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/Modulation Type"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 161, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/PSK Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 162, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/PSK On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 163, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/QAM On"),
    TARGET_STRING("Threshold"), 1, 4, 0 },

  { 164, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING("Amplitude"), 0, 4, 0 },

  { 165, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING("Frequency"), 0, 4, 0 },

  { 166, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING("Phase"), 0, 4, 0 },

  { 167, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 168, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 169, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING("Gain"), 0, 5, 0 },

  { 170, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 171, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 172, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING("FILTER_COEFF"), 0, 6, 0 },

  { 173, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING("Amplitude"), 0, 4, 0 },

  { 174, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING("Frequency"), 0, 4, 0 },

  { 175, TARGET_STRING("PhysicalLayerModel/Radio1/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING("Phase"), 0, 4, 0 },

  { 176, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING("Amplitude"), 0, 4, 0 },

  { 177, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING("Frequency"), 0, 4, 0 },

  { 178, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Downconverter/Downfrequency Oscillator"),
    TARGET_STRING("Phase"), 0, 4, 0 },

  { 179, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 180, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 181, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Vector in terms of Samples"),
    TARGET_STRING("Gain"), 0, 5, 0 },

  { 182, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/PSK Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 183, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/QAM Modulation Type/Constant"),
    TARGET_STRING("Value"), 4, 4, 0 },

  { 184, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/Raised Cosine Transmit Filter/FIR Interpolation"),
    TARGET_STRING("FILTER_COEFF"), 0, 6, 0 },

  { 185, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING("Amplitude"), 0, 4, 0 },

  { 186, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING("Frequency"), 0, 4, 0 },

  { 187, TARGET_STRING("PhysicalLayerModel/Radio2/Transmitter/Upconverter/Upfrequency Oscillator"),
    TARGET_STRING("Phase"), 0, 4, 0 },

  { 188, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Constant"),
    TARGET_STRING("Value"), 0, 5, 0 },

  { 189, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Constant1"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 190, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 191, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 192, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING("Gain"), 2, 7, 0 },

  { 193, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Constant"),
    TARGET_STRING("Value"), 0, 5, 0 },

  { 194, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Constant1"),
    TARGET_STRING("Value"), 0, 4, 0 },

  { 195, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Generate Sampling Instants/Gain"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 196, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity1"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 197, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Squaring Timing Phase Estimator/Sensitivity3"),
    TARGET_STRING("Gain"), 2, 7, 0 },

  { 198, TARGET_STRING("PhysicalLayerModel/Radio1/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING("Gain"), 0, 4, 0 },

  { 199, TARGET_STRING("PhysicalLayerModel/Radio2/Receiver/Squaring Timing Recovery/Within [0 T]/If Action Subsystem/Set to zero"),
    TARGET_STRING("Gain"), 0, 4, 0 },

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
static void PhysicalLayerModel_InitializeDataAddr(RT_MODEL_PhysicalLayerModel_T *
  const PhysicalLayerModel_M, void* dataAddr[], B_PhysicalLayerModel_T
  *PhysicalLayerModel_B, P_PhysicalLayerModel_T *PhysicalLayerModel_P)
{
  void* *rtDataAddrMap;
  rt_FREE( rtwCAPI_GetDataAddressMap( &(PhysicalLayerModel_M->DataMapInfo.mmi) )
          );
  rtDataAddrMap = (void* *) malloc(200 * sizeof(void* ));
  dataAddr[0] = (void*) (&PhysicalLayerModel_B->Channel1.DynamicAWGN[0]);
  dataAddr[1] = (void*) (&PhysicalLayerModel_B->Channel2.DynamicAWGN[0]);
  dataAddr[2] = (void*) (&PhysicalLayerModel_B->Channel1.Add1[0]);
  dataAddr[3] = (void*) (&PhysicalLayerModel_B->Channel2.Add1[0]);
  dataAddr[4] = (void*) (&PhysicalLayerModel_B->FromWorkspace[0]);
  dataAddr[5] = (void*) (&PhysicalLayerModel_B->FromWorkspace_lddws[0]);
  dataAddr[6] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.MultiportSwitch[0]);
  dataAddr[7] = (void*) (&PhysicalLayerModel_B->
    Receiver_ewxak.RealImagtoComplex[0].re);
  dataAddr[8] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.VectorintermsofSamples[0]);
  dataAddr[9] = (void*) (&PhysicalLayerModel_B->Transmitter.ComplextoRealImag[0]);
  dataAddr[10] = (void*) (&PhysicalLayerModel_B->Receiver.MultiportSwitch[0]);
  dataAddr[11] = (void*) (&PhysicalLayerModel_B->Receiver.RealImagtoComplex[0].
    re);
  dataAddr[12] = (void*) (&PhysicalLayerModel_B->
    Receiver.VectorintermsofSamples[0]);
  dataAddr[13] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.ComplextoRealImag[0]);
  dataAddr[14] = (void*)
    (&PhysicalLayerModel_B->Statistics1.ErrorRateCalculation[0]);
  dataAddr[15] = (void*)
    (&PhysicalLayerModel_B->Statistics2.ErrorRateCalculation[0]);
  dataAddr[16] = (void*) (&PhysicalLayerModel_B->Channel1.DynamicAWGN[0]);
  dataAddr[17] = (void*) (&PhysicalLayerModel_B->Channel1.RandomSource[0]);
  dataAddr[18] = (void*) (&PhysicalLayerModel_B->Channel1.ComplextoRealImag[0]);
  dataAddr[19] = (void*) (&PhysicalLayerModel_B->Channel1.Gain[0]);
  dataAddr[20] = (void*) (&PhysicalLayerModel_B->Channel1.MathFunction[0]);
  dataAddr[21] = (void*) (&PhysicalLayerModel_B->Channel1.InterfererTone[0].re);
  dataAddr[22] = (void*) (&PhysicalLayerModel_B->Channel1.MatrixConcatenation[0]);
  dataAddr[23] = (void*) (&PhysicalLayerModel_B->Channel2.DynamicAWGN[0]);
  dataAddr[24] = (void*) (&PhysicalLayerModel_B->Channel2.RandomSource[0]);
  dataAddr[25] = (void*) (&PhysicalLayerModel_B->Channel2.ComplextoRealImag[0]);
  dataAddr[26] = (void*) (&PhysicalLayerModel_B->Channel2.Gain[0]);
  dataAddr[27] = (void*) (&PhysicalLayerModel_B->Channel2.MathFunction[0]);
  dataAddr[28] = (void*) (&PhysicalLayerModel_B->Channel2.InterfererTone[0].re);
  dataAddr[29] = (void*) (&PhysicalLayerModel_B->Channel2.MatrixConcatenation[0]);
  dataAddr[30] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.PSKGain[0].re);
  dataAddr[31] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.MultiportSwitch
    [0]);
  dataAddr[32] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.MPSKDemodulatorBaseband[0]);
  dataAddr[33] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.RectangularQAMDemodulatorBaseba[0]);
  dataAddr[34] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.PSKOn[0].re);
  dataAddr[35] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.QAMOn[0].re);
  dataAddr[36] = (void*) (&PhysicalLayerModel_B->Transmitter.PSKGain[0].re);
  dataAddr[37] = (void*) (&PhysicalLayerModel_B->Transmitter.MultiportSwitch[0].
    re);
  dataAddr[38] = (void*)
    (&PhysicalLayerModel_B->Transmitter.MPSKModulatorBaseband[0].re);
  dataAddr[39] = (void*)
    (&PhysicalLayerModel_B->Transmitter.RectangularQAMModulatorBaseband[0].re);
  dataAddr[40] = (void*)
    (&PhysicalLayerModel_B->Transmitter.VariableFractionalDelay[0].re);
  dataAddr[41] = (void*) (&PhysicalLayerModel_B->Transmitter.PSKOn[0]);
  dataAddr[42] = (void*) (&PhysicalLayerModel_B->Transmitter.QAMOn[0]);
  dataAddr[43] = (void*) (&PhysicalLayerModel_B->Receiver.PSKGain[0].re);
  dataAddr[44] = (void*) (&PhysicalLayerModel_B->Receiver.MultiportSwitch[0]);
  dataAddr[45] = (void*)
    (&PhysicalLayerModel_B->Receiver.MPSKDemodulatorBaseband[0]);
  dataAddr[46] = (void*)
    (&PhysicalLayerModel_B->Receiver.RectangularQAMDemodulatorBaseba[0]);
  dataAddr[47] = (void*) (&PhysicalLayerModel_B->Receiver.PSKOn[0].re);
  dataAddr[48] = (void*) (&PhysicalLayerModel_B->Receiver.QAMOn[0].re);
  dataAddr[49] = (void*) (&PhysicalLayerModel_B->Transmitter_fe4q0.PSKGain[0].re);
  dataAddr[50] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.MultiportSwitch[0].re);
  dataAddr[51] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.MPSKModulatorBaseband[0].re);
  dataAddr[52] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.RectangularQAMModulatorBaseband[0]
     .re);
  dataAddr[53] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.VariableFractionalDelay[0].re);
  dataAddr[54] = (void*) (&PhysicalLayerModel_B->Transmitter_fe4q0.PSKOn[0]);
  dataAddr[55] = (void*) (&PhysicalLayerModel_B->Transmitter_fe4q0.QAMOn[0]);
  dataAddr[56] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Conjugate[0].re);
  dataAddr[57] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Product1[0].re);
  dataAddr[58] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.DownfrequencyOscillator[0].re);
  dataAddr[59] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Compare);
  dataAddr[60] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Compare_puagn);
  dataAddr[61] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.FIRDecimation[0]
    .re);
  dataAddr[62] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.VectorintermsofSamples[0]);
  dataAddr[63] = (void*) (&PhysicalLayerModel_B->Transmitter.Compare);
  dataAddr[64] = (void*) (&PhysicalLayerModel_B->Transmitter.Compare_hirmf);
  dataAddr[65] = (void*) (&PhysicalLayerModel_B->Transmitter.FIRInterpolation[0]
    .re);
  dataAddr[66] = (void*) (&PhysicalLayerModel_B->Transmitter.ComplextoRealImag[0]);
  dataAddr[67] = (void*) (&PhysicalLayerModel_B->Transmitter.Product[0].re);
  dataAddr[68] = (void*)
    (&PhysicalLayerModel_B->Transmitter.UpfrequencyOscillator[0].re);
  dataAddr[69] = (void*) (&PhysicalLayerModel_B->Receiver.Conjugate[0].re);
  dataAddr[70] = (void*) (&PhysicalLayerModel_B->Receiver.Product1[0].re);
  dataAddr[71] = (void*)
    (&PhysicalLayerModel_B->Receiver.DownfrequencyOscillator[0].re);
  dataAddr[72] = (void*) (&PhysicalLayerModel_B->Receiver.Compare);
  dataAddr[73] = (void*) (&PhysicalLayerModel_B->Receiver.Compare_puagn);
  dataAddr[74] = (void*) (&PhysicalLayerModel_B->Receiver.FIRDecimation[0].re);
  dataAddr[75] = (void*) (&PhysicalLayerModel_B->
    Receiver.VectorintermsofSamples[0]);
  dataAddr[76] = (void*) (&PhysicalLayerModel_B->Transmitter_fe4q0.Compare);
  dataAddr[77] = (void*) (&PhysicalLayerModel_B->Transmitter_fe4q0.Compare_hirmf);
  dataAddr[78] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.FIRInterpolation[0].re);
  dataAddr[79] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.ComplextoRealImag[0]);
  dataAddr[80] = (void*) (&PhysicalLayerModel_B->Transmitter_fe4q0.Product[0].re);
  dataAddr[81] = (void*)
    (&PhysicalLayerModel_B->Transmitter_fe4q0.UpfrequencyOscillator[0].re);
  dataAddr[82] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Gain[0]);
  dataAddr[83] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Sum_hqxki[0]);
  dataAddr[84] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Sum1[0]);
  dataAddr[85] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.ComplextoMagnitudeAngle);
  dataAddr[86] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Sensitivity1);
  dataAddr[87] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Sensitivity3[0].
    re);
  dataAddr[88] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.MathFunction[0]);
  dataAddr[89] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Sum.re);
  dataAddr[90] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.ComplextoRealImag2_o1[0]);
  dataAddr[91] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.ComplextoRealImag2_o2[0]);
  dataAddr[92] = (void*)
    (&PhysicalLayerModel_B->Receiver_ewxak.RealImagtoComplex[0].re);
  dataAddr[93] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Interpolation[0]);
  dataAddr[94] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Interpolation1[0]);
  dataAddr[95] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Merge);
  dataAddr[96] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Merge);
  dataAddr[97] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Abs);
  dataAddr[98] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Fcn);
  dataAddr[99] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Merge);
  dataAddr[100] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Sum2);
  dataAddr[101] = (void*) (&PhysicalLayerModel_B->Receiver.Gain[0]);
  dataAddr[102] = (void*) (&PhysicalLayerModel_B->Receiver.Sum_hqxki[0]);
  dataAddr[103] = (void*) (&PhysicalLayerModel_B->Receiver.Sum1[0]);
  dataAddr[104] = (void*)
    (&PhysicalLayerModel_B->Receiver.ComplextoMagnitudeAngle);
  dataAddr[105] = (void*) (&PhysicalLayerModel_B->Receiver.Sensitivity1);
  dataAddr[106] = (void*) (&PhysicalLayerModel_B->Receiver.Sensitivity3[0].re);
  dataAddr[107] = (void*) (&PhysicalLayerModel_B->Receiver.MathFunction[0]);
  dataAddr[108] = (void*) (&PhysicalLayerModel_B->Receiver.Sum.re);
  dataAddr[109] = (void*) (&PhysicalLayerModel_B->
    Receiver.ComplextoRealImag2_o1[0]);
  dataAddr[110] = (void*) (&PhysicalLayerModel_B->
    Receiver.ComplextoRealImag2_o2[0]);
  dataAddr[111] = (void*) (&PhysicalLayerModel_B->Receiver.RealImagtoComplex[0].
    re);
  dataAddr[112] = (void*) (&PhysicalLayerModel_B->Receiver.Interpolation[0]);
  dataAddr[113] = (void*) (&PhysicalLayerModel_B->Receiver.Interpolation1[0]);
  dataAddr[114] = (void*) (&PhysicalLayerModel_B->Receiver.Merge);
  dataAddr[115] = (void*) (&PhysicalLayerModel_B->Receiver.Merge);
  dataAddr[116] = (void*) (&PhysicalLayerModel_B->Receiver.Abs);
  dataAddr[117] = (void*) (&PhysicalLayerModel_B->Receiver.Fcn);
  dataAddr[118] = (void*) (&PhysicalLayerModel_B->Receiver.Merge);
  dataAddr[119] = (void*) (&PhysicalLayerModel_B->Receiver.Sum2);
  dataAddr[120] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Merge);
  dataAddr[121] = (void*) (&PhysicalLayerModel_B->Receiver_ewxak.Merge);
  dataAddr[122] = (void*) (&PhysicalLayerModel_B->Receiver.Merge);
  dataAddr[123] = (void*) (&PhysicalLayerModel_B->Receiver.Merge);
  dataAddr[124] = (void*) (&PhysicalLayerModel_P->Channel1.DynamicAWGN_Seed);
  dataAddr[125] = (void*) (&PhysicalLayerModel_P->Channel1.DynamicAWGN_SNR);
  dataAddr[126] = (void*) (&PhysicalLayerModel_P->Channel1.DynamicAWGN_SPOW);
  dataAddr[127] = (void*) (&PhysicalLayerModel_P->Channel1.RandomSource_MeanRTP);
  dataAddr[128] = (void*)
    (&PhysicalLayerModel_P->Channel1.RandomSource_VarianceRTP);
  dataAddr[129] = (void*) (&PhysicalLayerModel_P->Channel1.RandomSource_InitSeed);
  dataAddr[130] = (void*) (&PhysicalLayerModel_P->Channel1.Constant_Value);
  dataAddr[131] = (void*) (&PhysicalLayerModel_P->Channel1.Gain_Gain);
  dataAddr[132] = (void*)
    (&PhysicalLayerModel_P->Channel1.InterfererTone_Amplitude);
  dataAddr[133] = (void*)
    (&PhysicalLayerModel_P->Channel1.InterfererTone_Frequency);
  dataAddr[134] = (void*) (&PhysicalLayerModel_P->Channel1.InterfererTone_Phase);
  dataAddr[135] = (void*) (&PhysicalLayerModel_P->Channel2.DynamicAWGN_Seed);
  dataAddr[136] = (void*) (&PhysicalLayerModel_P->Channel2.DynamicAWGN_SNR);
  dataAddr[137] = (void*) (&PhysicalLayerModel_P->Channel2.DynamicAWGN_SPOW);
  dataAddr[138] = (void*) (&PhysicalLayerModel_P->Channel2.RandomSource_MeanRTP);
  dataAddr[139] = (void*)
    (&PhysicalLayerModel_P->Channel2.RandomSource_VarianceRTP);
  dataAddr[140] = (void*) (&PhysicalLayerModel_P->Channel2.RandomSource_InitSeed);
  dataAddr[141] = (void*) (&PhysicalLayerModel_P->Channel2.Constant_Value);
  dataAddr[142] = (void*) (&PhysicalLayerModel_P->Channel2.Gain_Gain);
  dataAddr[143] = (void*)
    (&PhysicalLayerModel_P->Channel2.InterfererTone_Amplitude);
  dataAddr[144] = (void*)
    (&PhysicalLayerModel_P->Channel2.InterfererTone_Frequency);
  dataAddr[145] = (void*) (&PhysicalLayerModel_P->Channel2.InterfererTone_Phase);
  dataAddr[146] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.ModulationType_Value);
  dataAddr[147] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.PSKGain_Gain);
  dataAddr[148] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.PSKOn_Threshold);
  dataAddr[149] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.QAMOn_Threshold);
  dataAddr[150] = (void*) (&PhysicalLayerModel_P->Transmitter.DelayFactor_Value);
  dataAddr[151] = (void*)
    (&PhysicalLayerModel_P->Transmitter.ModulationType_Value);
  dataAddr[152] = (void*) (&PhysicalLayerModel_P->Transmitter.PSKGain_Gain);
  dataAddr[153] = (void*) (&PhysicalLayerModel_P->Transmitter.PSKOn_Threshold);
  dataAddr[154] = (void*) (&PhysicalLayerModel_P->Transmitter.QAMOn_Threshold);
  dataAddr[155] = (void*) (&PhysicalLayerModel_P->Receiver.ModulationType_Value);
  dataAddr[156] = (void*) (&PhysicalLayerModel_P->Receiver.PSKGain_Gain);
  dataAddr[157] = (void*) (&PhysicalLayerModel_P->Receiver.PSKOn_Threshold);
  dataAddr[158] = (void*) (&PhysicalLayerModel_P->Receiver.QAMOn_Threshold);
  dataAddr[159] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.DelayFactor_Value);
  dataAddr[160] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.ModulationType_Value);
  dataAddr[161] = (void*) (&PhysicalLayerModel_P->Transmitter_fe4q0.PSKGain_Gain);
  dataAddr[162] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.PSKOn_Threshold);
  dataAddr[163] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.QAMOn_Threshold);
  dataAddr[164] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.DownfrequencyOscillator_Amplitu);
  dataAddr[165] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.DownfrequencyOscillator_Frequen);
  dataAddr[166] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.DownfrequencyOscillator_Phase);
  dataAddr[167] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.Constant_Value_iyrus);
  dataAddr[168] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.Constant_Value_ch0td);
  dataAddr[169] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.VectorintermsofSamples_Gain[0]);
  dataAddr[170] = (void*) (&PhysicalLayerModel_P->Transmitter.Constant_Value);
  dataAddr[171] = (void*)
    (&PhysicalLayerModel_P->Transmitter.Constant_Value_b4tax);
  dataAddr[172] = (void*)
    (&PhysicalLayerModel_P->Transmitter.FIRInterpolation_FILTER_COEFF[0]);
  dataAddr[173] = (void*)
    (&PhysicalLayerModel_P->Transmitter.UpfrequencyOscillator_Amplitude);
  dataAddr[174] = (void*)
    (&PhysicalLayerModel_P->Transmitter.UpfrequencyOscillator_Frequency);
  dataAddr[175] = (void*)
    (&PhysicalLayerModel_P->Transmitter.UpfrequencyOscillator_Phase);
  dataAddr[176] = (void*)
    (&PhysicalLayerModel_P->Receiver.DownfrequencyOscillator_Amplitu);
  dataAddr[177] = (void*)
    (&PhysicalLayerModel_P->Receiver.DownfrequencyOscillator_Frequen);
  dataAddr[178] = (void*)
    (&PhysicalLayerModel_P->Receiver.DownfrequencyOscillator_Phase);
  dataAddr[179] = (void*) (&PhysicalLayerModel_P->Receiver.Constant_Value_iyrus);
  dataAddr[180] = (void*) (&PhysicalLayerModel_P->Receiver.Constant_Value_ch0td);
  dataAddr[181] = (void*)
    (&PhysicalLayerModel_P->Receiver.VectorintermsofSamples_Gain[0]);
  dataAddr[182] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.Constant_Value);
  dataAddr[183] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.Constant_Value_b4tax);
  dataAddr[184] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.FIRInterpolation_FILTER_COEFF[0]);
  dataAddr[185] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.UpfrequencyOscillator_Amplitude);
  dataAddr[186] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.UpfrequencyOscillator_Frequency);
  dataAddr[187] = (void*)
    (&PhysicalLayerModel_P->Transmitter_fe4q0.UpfrequencyOscillator_Phase);
  dataAddr[188] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.Constant_Value
    [0]);
  dataAddr[189] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.Constant1_Value);
  dataAddr[190] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.Gain_Gain);
  dataAddr[191] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.Sensitivity1_Gain);
  dataAddr[192] = (void*)
    (&PhysicalLayerModel_P->Receiver_ewxak.Sensitivity3_Gain[0].re);
  dataAddr[193] = (void*) (&PhysicalLayerModel_P->Receiver.Constant_Value[0]);
  dataAddr[194] = (void*) (&PhysicalLayerModel_P->Receiver.Constant1_Value);
  dataAddr[195] = (void*) (&PhysicalLayerModel_P->Receiver.Gain_Gain);
  dataAddr[196] = (void*) (&PhysicalLayerModel_P->Receiver.Sensitivity1_Gain);
  dataAddr[197] = (void*) (&PhysicalLayerModel_P->Receiver.Sensitivity3_Gain[0].
    re);
  dataAddr[198] = (void*) (&PhysicalLayerModel_P->Receiver_ewxak.Settozero_Gain);
  dataAddr[199] = (void*) (&PhysicalLayerModel_P->Receiver.Settozero_Gain);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void PhysicalLayerModel_InitializeVarDimsAddr
  (RT_MODEL_PhysicalLayerModel_T *const PhysicalLayerModel_M, int32_T
   * vardimsAddr[])
{
  int32_T* *rtVarDimsAddrMap;
  rt_FREE( rtwCAPI_GetVarDimsAddressMap( &(PhysicalLayerModel_M->DataMapInfo.mmi)
           ) );
  rtVarDimsAddrMap = (int32_T* *) malloc(1 * sizeof(int32_T* ));
  vardimsAddr[0] = (NULL);
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "struct", "creal_T", 0, 0, sizeof(creal_T), SS_DOUBLE, 1, 0 },

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

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_SCALAR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  2112,                                /* 0 */
  1,                                   /* 1 */
  264,                                 /* 2 */
  1,                                   /* 3 */
  3,                                   /* 4 */
  1,                                   /* 5 */
  2112,                                /* 6 */
  2,                                   /* 7 */
  1,                                   /* 8 */
  1,                                   /* 9 */
  9,                                   /* 10 */
  8                                    /* 11 */
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
    0, 1 },

  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
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
  { rtBlockSignals, 124,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 76,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", (NULL), 0,
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  PhysicalLayerModel_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void PhysicalLayerModel_InitializeDataMapInfo(RT_MODEL_PhysicalLayerModel_T *
  const PhysicalLayerModel_M, B_PhysicalLayerModel_T *PhysicalLayerModel_B,
  P_PhysicalLayerModel_T *PhysicalLayerModel_P)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(PhysicalLayerModel_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(PhysicalLayerModel_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(PhysicalLayerModel_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  PhysicalLayerModel_InitializeDataAddr(PhysicalLayerModel_M,
    PhysicalLayerModel_M->DataMapInfo.dataAddress,
    PhysicalLayerModel_M->ModelData.blockIO,
    PhysicalLayerModel_M->ModelData.defaultParam);
  rtwCAPI_SetDataAddressMap(PhysicalLayerModel_M->DataMapInfo.mmi,
    PhysicalLayerModel_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  PhysicalLayerModel_InitializeVarDimsAddr(PhysicalLayerModel_M,
    PhysicalLayerModel_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(PhysicalLayerModel_M->DataMapInfo.mmi,
    PhysicalLayerModel_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(PhysicalLayerModel_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(PhysicalLayerModel_M->DataMapInfo.mmi, (NULL));

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(PhysicalLayerModel_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(PhysicalLayerModel_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(PhysicalLayerModel_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void PhysicalLayerModel_host_InitializeDataMapInfo
    (PhysicalLayerModel_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: PhysicalLayerModel_capi.cpp */
