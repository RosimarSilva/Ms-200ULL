/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TU2.h
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Component   : TimerUnit_LDD
**     Version     : Component 01.164, Driver 01.11, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-12-13, 00:02, # CodeGen: 347
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU2
**          Module name                                    : FTM0
**          Counter                                        : FTM0_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Input clock source                             : Internal
**            Counter frequency                            : 35.995648 MHz
**          Counter restart                                : On-overrun
**            Overrun period                               : 0.02 ms
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_FTM0
**              Interrupt priority                         : maximal priority
**          Channel list                                   : 2
**            Channel 0                                    : 
**              Mode                                       : Capture
**                Capture                                  : FTM0_C1V
**                Capture input pin                        : ADC0_SE4b/CMP1_IN0/TSI0_CH15/PTC2/SPI0_PCS2/UART1_CTS_b/FTM0_CH1/FB_AD12/I2S0_TX_FS
**                Capture input signal                     : 
**                Edge                                     : rising edge
**                Maximum time of event                    : 1.820655616 ms
**                Interrupt                                : Enabled
**                  Interrupt                              : INT_FTM0
**                  Interrupt priority                     : maximal priority
**            Channel 1                                    : 
**              Mode                                       : Capture
**                Capture                                  : FTM0_C0V
**                Capture input pin                        : ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/FB_AD13/I2S0_TXD0
**                Capture input signal                     : 
**                Edge                                     : falling edge
**                Maximum time of event                    : 1.820655616 ms
**                Interrupt                                : Enabled
**                  Interrupt                              : INT_FTM0
**                  Interrupt priority                     : maximal priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Enabled
**              OnChannel1                                 : Enabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init              - LDD_TDeviceData* TU2_Init(LDD_TUserData *UserDataPtr);
**         Enable            - LDD_TError TU2_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable           - LDD_TError TU2_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask      - LDD_TError TU2_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask...
**         GetEventMask      - LDD_TEventMask TU2_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue   - TU2_TValueType TU2_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
**         GetCaptureValue   - LDD_TError TU2_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         SelectCaptureEdge - LDD_TError TU2_SelectCaptureEdge(LDD_TDeviceData *DeviceDataPtr, uint8_t...
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
** @file TU2.h
** @version 01.11
** @brief
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
*/         
/*!
**  @addtogroup TU2_module TU2 module documentation
**  @{
*/         

#ifndef __TU2_H
#define __TU2_H

/* MODULE TU2. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "FTM_PDD.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef __BWUserType_TU2_TValueType
#define __BWUserType_TU2_TValueType
  typedef uint16_t TU2_TValueType ;    /* Type for data parameters of methods */
#endif
#define TU2_CNT_INP_FREQ_U_0 0x02254000UL /* Counter input frequency in Hz */
#define TU2_CNT_INP_FREQ_U_0_CFG_0 0x02254000UL /* Counter input frequency in Hz for Clock configuration 0 */
#define TU2_CNT_INP_FREQ_R_0 35995824.484359816F /* Counter input frequency in Hz */
#define TU2_CNT_INP_FREQ_R_0_CFG_0 35995824.484359816F /* Counter input frequency in Hz for Clock configuration 0 */
#define TU2_CNT_INP_FREQ_COUNT 0U      /* Count of predefined counter input frequencies */
#define TU2_PERIOD_TICKS   0x00010000UL /* Initialization value of period in 'counter ticks' */
#define TU2_NUMBER_OF_CHANNELS 0x02U   /* Count of predefined channels */
#define TU2_COUNTER_WIDTH  0x10U       /* Counter width in bits  */
#define TU2_COUNTER_DIR    DIR_UP      /* Direction of counting */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TU2_PRPH_BASE_ADDRESS  0x40038000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TU2_Init_METHOD_ENABLED        /*!< Init method of the component TU2 is enabled (generated) */
#define TU2_Enable_METHOD_ENABLED      /*!< Enable method of the component TU2 is enabled (generated) */
#define TU2_Disable_METHOD_ENABLED     /*!< Disable method of the component TU2 is enabled (generated) */
#define TU2_SetEventMask_METHOD_ENABLED /*!< SetEventMask method of the component TU2 is enabled (generated) */
#define TU2_GetEventMask_METHOD_ENABLED /*!< GetEventMask method of the component TU2 is enabled (generated) */
#define TU2_GetCounterValue_METHOD_ENABLED /*!< GetCounterValue method of the component TU2 is enabled (generated) */
#define TU2_GetCaptureValue_METHOD_ENABLED /*!< GetCaptureValue method of the component TU2 is enabled (generated) */
#define TU2_SelectCaptureEdge_METHOD_ENABLED /*!< SelectCaptureEdge method of the component TU2 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define TU2_OnCounterRestart_EVENT_ENABLED /*!< OnCounterRestart event of the component TU2 is enabled (generated) */
#define TU2_OnChannel0_EVENT_ENABLED   /*!< OnChannel0 event of the component TU2 is enabled (generated) */
#define TU2_OnChannel1_EVENT_ENABLED   /*!< OnChannel1 event of the component TU2 is enabled (generated) */



/*
** ===================================================================
**     Method      :  TU2_Init (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* TU2_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  TU2_Enable (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask). The method is
**         not available if the counter can't be disabled/enabled by HW.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU2_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  TU2_Disable (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Disables the component - it stops signal generation and
**         events calling. The method is not available if the counter
**         can't be disabled/enabled by HW.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU2_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  TU2_SetEventMask (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Enables/disables event(s). The events contained within the
**         mask are enabled. Events not contained within the mask are
**         disabled. The component event masks are defined in the
**         PE_Types.h file. Note: Event that are not generated (See the
**         "Events" tab in the Component inspector) are not handled by
**         this method. In this case the method returns ERR_PARAM_MASK
**         error code. See also method [GetEventMask].
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         EventMask       - Event mask
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_PARAM_MASK - Event mask is not valid
*/
/* ===================================================================*/
LDD_TError TU2_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask);

/*
** ===================================================================
**     Method      :  TU2_GetEventMask (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns current events mask. Note: Event that are not
**         generated (See the "Events" tab in the Component inspector)
**         are not handled by this method. See also method
**         [SetEventMask].
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Current EventMask.
**                           The component event masks are defined in
**                           the PE_Types.h file.
*/
/* ===================================================================*/
LDD_TEventMask TU2_GetEventMask(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  TU2_GetCounterValue (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Counter value (number of counted ticks).
*/
/* ===================================================================*/
TU2_TValueType TU2_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  TU2_GetCaptureValue (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the content of capture register specified by the
**         parameter ChannelIdx. This method is available when at least
**         one channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         ValuePtr        - Pointer to return value of the
**                           capture register.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range
**                           ERR_NOTAVAIL -  The capture mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU2_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU2_TValueType *ValuePtr);

/*
** ===================================================================
**     Method      :  TU2_SelectCaptureEdge (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Sets the type of edge for input capture on selected channel
**         input. This method is available when at least one channel is
**         configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         Edge            - Select type of edge for input capture
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range
**                           ERR_NOTAVAIL -  Action is not possible on
**                           selected channel..
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU2_SelectCaptureEdge(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, LDD_TimerUnit_TEdge Edge);

/*
** ===================================================================
**     Method      :  TU2_SetClockConfiguration (component TimerUnit_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU2_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);

/*
** ===================================================================
**     Method      :  TU2_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(TU2_Interrupt);

/* END TU2. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __TU2_H */
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
