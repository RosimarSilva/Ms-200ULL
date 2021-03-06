/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RPM.h
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Component   : Capture
**     Version     : Component 02.223, Driver 01.01, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-12-13, 00:02, # CodeGen: 347
**     Abstract    :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings    :
**          Component name                                 : RPM
**          Capture device                                 : FTM0_C1V
**          Counter                                        : FTM0_CNT
**          Capture input pin                              : ADC0_SE4b/CMP1_IN0/TSI0_CH15/PTC2/SPI0_PCS2/UART1_CTS_b/FTM0_CH1/FB_AD12/I2S0_TX_FS
**          Capture input signal                           : 
**          Edge                                           : rising edge
**          Interrupt service/event                        : Enabled
**            Capture interrupt                            : INT_FTM0
**            Capture priority                             : maximal priority
**          Maximum time of event                          : 0.02 ms
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          Referenced components                          : 
**            Capture_LDD                                  : Capture_LDD
**     Contents    :
**         Enable          - byte RPM_Enable(void);
**         Disable         - byte RPM_Disable(void);
**         Reset           - byte RPM_Reset(void);
**         GetCaptureValue - byte RPM_GetCaptureValue(RPM_TCapturedValue *Value);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file RPM.h
** @version 01.01
** @brief
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
*/         
/*!
**  @addtogroup RPM_module RPM module documentation
**  @{
*/         

#ifndef __RPM_H
#define __RPM_H

/* MODULE RPM. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "CaptureLdd1.h"

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 

#ifndef __BWUserType_RPM_TCapturedValue
#define __BWUserType_RPM_TCapturedValue
  typedef uint16_t RPM_TCapturedValue; /* Captured value, unsigned integer value. Bit-width of the type depends on the width of selected timer. */
#endif

#define RPM_PRESCALER_VALUE 0x01UL     /* Initial prescaler value of the timer. It is available only if the component is enabled in high speed mode. */
#define RPM_PRESCALER_VALUE_HIGH 0x01UL /* Prescaler value of the timer in high speed mode. It is available only if the component is enabled in high speed mode. */
#define RPM_COUNTER_INPUT_CLOCK_HZ CaptureLdd1_CNT_INP_FREQ_U /* Initial counter input clock frequency [Hz] (integer number). It is available only if the component is enabled in high speed mode. */
#define RPM_COUNTER_INPUT_CLOCK_HZ_HIGH CaptureLdd1_CNT_INP_FREQ_U_CFG_0 /* Counter input clock frequency in high speed mode [Hz] (integer number). It is available only if the component is enabled in high speed mode. */


/*
** ===================================================================
**     Method      :  RPM_Enable (component Capture)
**     Description :
**         This method enables the component - it starts the capture.
**         Events may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define RPM_Enable() (CaptureLdd1_Enable(CaptureLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  RPM_Disable (component Capture)
**     Description :
**         This method disables the component - it stops the capture.
**         No events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define RPM_Disable() (CaptureLdd1_Disable(CaptureLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  RPM_Reset (component Capture)
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define RPM_Reset() (CaptureLdd1_Reset(CaptureLdd1_DeviceData))

/*
** ===================================================================
**     Method      :  RPM_GetCaptureValue (component Capture)
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
#define RPM_GetCaptureValue(Value) (CaptureLdd1_GetCaptureValue(CaptureLdd1_DeviceData, Value))

/*
** ===================================================================
**     Method      :  RPM_OnCapture (component Capture)
**
**     Description :
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CaptureLdd1_OnCapture(LDD_TUserData *UserDataPtr);

/* END RPM. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __RPM_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
