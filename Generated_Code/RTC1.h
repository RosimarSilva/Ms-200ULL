/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RTC1.h
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Component   : RTC_LDD
**     Version     : Component 01.165, Driver 01.08, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-12-27, 18:50, # CodeGen: 358
**     Abstract    :
**         This component implements a real time clock (RTC). Actual date may also be
**         obtained and an alarm function is included.
**     Settings    :
**          Component name                                 : RTC1
**          Device                                         : RTC
**          Input clock frequency [s]                      : 1 sec
**          Clock frequency [kHz]                          : 
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_RTC
**            Interrupt priority                           : medium priority
**            Interrupt                                    : INT_RTC_Seconds
**            Interrupt priority                           : medium priority
**          Min year                                       : 2000
**          Max year                                       : 2099
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto Initialization                          : yes
**              Auto init. mode                            : Soft init
**            Event mask                                   : 
**              OnAlarm                                    : Disabled
**              OnSecond                                   : Disabled
**              OnTimeOverflow                             : Disabled
**              OnTimeInvalid                              : Disabled
**            Time and date settings                       : 
**              Time                                       : 00:00:01
**              Date                                       : 2000-01-01
**            Alarm settings                               : Enabled
**              Alarm time                                 : 00:00:00
**              Alarm date                                 : 2000-01-01
**            Compensation settings                        : 
**              Compensation period [s]                    : 0
**              Compensation value [clock cycles]          : 0
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component enabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init    - LDD_TDeviceData * RTC1_Init(LDD_TUserData *UserDataPtr, bool SoftInit);
**         Enable  - LDD_TError RTC1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         GetTime - void RTC1_GetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr);
**         SetTime - LDD_TError RTC1_SetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr);
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
** @file RTC1.h
** @version 01.08
** @brief
**         This component implements a real time clock (RTC). Actual date may also be
**         obtained and an alarm function is included.
*/         
/*!
**  @addtogroup RTC1_module RTC1 module documentation
**  @{
*/         

#ifndef __RTC1_H
#define __RTC1_H

/* MODULE RTC1. */

#include "Cpu.h"


#ifdef __cplusplus
extern "C" {
#endif

/* Driver mode */
#define RTC1_INTERRUPT_MODE

/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define RTC1_PRPH_BASE_ADDRESS  0x4003D000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define RTC1_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_RTC1_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define RTC1_Init_METHOD_ENABLED       /*!< Init method of the component RTC1 is enabled (generated) */
#define RTC1_Enable_METHOD_ENABLED     /*!< Enable method of the component RTC1 is enabled (generated) */
#define RTC1_GetTime_METHOD_ENABLED    /*!< GetTime method of the component RTC1 is enabled (generated) */
#define RTC1_SetTime_METHOD_ENABLED    /*!< SetTime method of the component RTC1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */

/*
** ===================================================================
**     Method      :  RTC1_Init (component RTC_LDD)
*/
/*!
**     @brief
**         Initializes the device. There are two modes of
**         initialization.
**         1) RTC device is NOT battery backed up. (SoftInit = FALSE)
**         All registers (interrupts, counters, clock routing �) that
**         influence RTC behavior are initialized. 
**         Note: This initialization mode doesn't preserve time and
**         date settings.
**         2) RTC device IS battery backed up.
**         (SoftInit = TRUE). Only registers that are not backed up are
**         initialized (Interrupt priority �). RTC device is running,
**         time and date a preserved, RTC interrupts (events) are
**         preserved too.
**         Allocates memory for the device data structure.
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @param
**         SoftInit        - If set to "[true]" only
**                           registers that are not battery backup are
**                           initialized (E.g. Interrupt priority in
**                           interrupt controller � )
**                           If set to "[false]" all registers are
**                           initialized.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData * RTC1_Init(LDD_TUserData *UserDataPtr, bool SoftInit);

/*
** ===================================================================
**     Method      :  RTC1_Enable (component RTC_LDD)
*/
/*!
**     @brief
**         Enables the real-time clock module (Typically sets the
**         module enable bit). All other HW settings are preserved. RTC
**         module can be disabled by the [Disable] method and
**         reinitialized by the [Init] method.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
*/
/* ===================================================================*/
LDD_TError RTC1_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  RTC1_GetTime (component RTC_LDD)
*/
/*!
**     @brief
**         Returns actual time and date. 
**         Note: Fields not supported by HW are calculated in software.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @param
**         TimePtr         - Pointer to the time structure to
**                           fill with current time.
*/
/* ===================================================================*/
void RTC1_GetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr);

/*
** ===================================================================
**     Method      :  RTC1_SetTime (component RTC_LDD)
*/
/*!
**     @brief
**         Sets new time and date.
**         Note: All LDD_RTC_TTime structure members must be correctly
**         filled in.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by [Init] method.
**     @param
**         TimePtr         - Pointer to the time structure with
**                           new time to set.
**     @return
**                         - Error code, possible codes: 
**                           - ERR_OK - OK. 
**                           - ERR_DISABLED - Component is disabled. 
**                           - ERR_SPEED - Component does not work in
**                           the active clock configuration. 
**                           - ERR_RANGE - Parameter out of range.
*/
/* ===================================================================*/
LDD_TError RTC1_SetTime(LDD_TDeviceData *DeviceDataPtr, LDD_RTC_TTime *TimePtr);

/*
** ===================================================================
**     Method      :  RTC1_Interrupt (component RTC_LDD)
**
**     Description :
**         RTC interrupt handler
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(RTC1_Interrupt);

/*
** ===================================================================
**     Method      :  RTC1_SetClockConfiguration (component RTC_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void RTC1_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);

/* END RTC1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif
/* ifndef __RTC1_H */
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
