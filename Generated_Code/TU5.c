/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TU5.c
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Component   : TimerUnit_LDD
**     Version     : Component 01.164, Driver 01.11, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-12-13, 01:28, # CodeGen: 354
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU5
**          Module name                                    : FTM2
**          Counter                                        : FTM2_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Input clock source                             : Internal
**            Counter frequency                            : 35.995648 MHz
**          Counter restart                                : On-overrun
**            Overrun period                               : Auto select
**            Interrupt                                    : Disabled
**          Channel list                                   : 1
**            Channel 0                                    : 
**              Mode                                       : Compare
**                Compare                                  : FTM2_C0V
**                Offset                                   : 0.05 ms
**                Output on compare                        : Disconnect
**                Interrupt                                : Enabled
**                  Interrupt                              : INT_FTM2
**                  Interrupt priority                     : high priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Disabled
**              OnChannel0                                 : Enabled
**              OnChannel1                                 : Disabled
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
**         Init            - LDD_TDeviceData* TU5_Init(LDD_TUserData *UserDataPtr);
**         SetEventMask    - LDD_TError TU5_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask...
**         GetEventMask    - LDD_TEventMask TU5_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue - TU5_TValueType TU5_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
**         SetOffsetTicks  - LDD_TError TU5_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         GetOffsetTicks  - LDD_TError TU5_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
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
** @file TU5.c
** @version 01.11
** @brief
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
*/         
/*!
**  @addtogroup TU5_module TU5 module documentation
**  @{
*/         

/* MODULE TU5. */

#include "RealTimeLdd2.h"
#include "TU5.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* List of channels used by component */
static const uint8_t ChannelDevice[TU5_NUMBER_OF_CHANNELS] = {0x00U};

/* Table of channels mode / 0 - compare mode, 1 - capture mode */
static const uint8_t ChannelMode[TU5_NUMBER_OF_CHANNELS] = {0x00U};


typedef struct {
  bool EnUser;                         /* Enable/Disable device */
  bool EnMode;                         /* Enable/Disable device in clock configuration */
  LDD_TEventMask EnEvents;             /* Enable/Disable events mask */
  uint32_t Source;                     /* Current source clock */
  uint8_t InitCntr;                    /* Number of initialization */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} TU5_TDeviceData;

typedef TU5_TDeviceData *TU5_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static TU5_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static TU5_TDeviceDataPtr INT_FTM2__DEFAULT_RTOS_ISRPARAM;

#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERUNIT_ON_CHANNEL_0)
#define LAST_CHANNEL 0x00U

/* Internal method prototypes */
static void HWEnDi(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TU5_Init (component TimerUnit_LDD)
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
LDD_TDeviceData* TU5_Init(LDD_TUserData *UserDataPtr)
{
  TU5_TDeviceData *DeviceDataPrv;

  if (PE_LDD_DeviceDataList[PE_LDD_COMPONENT_TU5_ID] == NULL) {
    /* Allocate device structure */
    /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
    DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
    DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
    DeviceDataPrv->InitCntr = 1U;      /* First initialization */
  }
  else {
    /* Memory is already allocated */
    DeviceDataPrv = (TU5_TDeviceDataPtr) PE_LDD_DeviceDataList[PE_LDD_COMPONENT_TU5_ID];
    DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
    DeviceDataPrv->InitCntr++;         /* Increment counter of initialization */
    return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
  }
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_FTM2__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* SIM_SCGC3: FTM2=1 */
  SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK;
  /* FTM2_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,CAPTEST=0,PWMSYNC=0,WPDIS=1,INIT=0,FTMEN=0 */
  FTM2_MODE = (FTM_MODE_FAULTM(0x00) | FTM_MODE_WPDIS_MASK); /* Set up mode register */
  /* FTM2_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=0,PS=0 */
  FTM2_SC = (FTM_SC_CLKS(0x00) | FTM_SC_PS(0x00)); /* Clear status and control register */
  /* FTM2_CNTIN: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,INIT=0 */
  FTM2_CNTIN = FTM_CNTIN_INIT(0x00);   /* Clear counter initial register */
  /* FTM2_CNT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNT=0 */
  FTM2_CNT = FTM_CNT_COUNT(0x00);      /* Reset counter register */
  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM2_C0SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM2_C1SC = 0x00U;                   /* Clear channel status and control register */
  /* FTM2_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0xFFFF */
  FTM2_MOD = FTM_MOD_MOD(0xFFFF);      /* Set up modulo register */
  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=1,MSB=0,MSA=1,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM2_C0SC = (FTM_CnSC_CHIE_MASK | FTM_CnSC_MSA_MASK); /* Set up channel status and control register */
  /* FTM2_C0V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0x0708 */
  FTM2_C0V = FTM_CnV_VAL(0x0708);      /* Set up channel value register */
  DeviceDataPrv->EnEvents = 0x01U;     /* Enable selected events */
  DeviceDataPrv->Source = FTM_PDD_SYSTEM; /* Store clock source */
  /* NVICIP64: PRI64=0x50 */
  NVICIP64 = NVIC_IP_PRI64(0x50);
  /* NVICISER2: SETENA|=1 */
  NVICISER2 |= NVIC_ISER_SETENA(0x01);
  DeviceDataPrv->EnUser = TRUE;        /* Set the flag "device enabled" */
  TU5_SetClockConfiguration(DeviceDataPrv, Cpu_GetClockConfiguration()); /* Set Initial according clock configuration */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_TU5_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  TU5_SetEventMask (component TimerUnit_LDD)
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
LDD_TError TU5_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask)
{
  TU5_TDeviceData *DeviceDataPrv = (TU5_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  /* Event mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((EventMask & ((LDD_TEventMask)~AVAILABLE_EVENTS_MASK)) != 0U) {
    return ERR_PARAM_MASK;
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  if ((EventMask & LDD_TIMERUNIT_ON_CHANNEL_0) != 0U) { /* Is the event enabled? */
    FTM_PDD_ClearChannelInterruptFlag(FTM2_BASE_PTR, ChannelDevice[0]); /* If yes then clear flag */
    FTM_PDD_EnableChannelInterrupt(FTM2_BASE_PTR, ChannelDevice[0]); /* and enable interrupt */
  }
  else {
    FTM_PDD_DisableChannelInterrupt(FTM2_BASE_PTR, ChannelDevice[0]); /* Disable channel 0 interrupt */
  }
  DeviceDataPrv->EnEvents = EventMask;
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TU5_GetEventMask (component TimerUnit_LDD)
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
LDD_TEventMask TU5_GetEventMask(LDD_TDeviceData *DeviceDataPtr)
{
  TU5_TDeviceData *DeviceDataPrv = (TU5_TDeviceData *)DeviceDataPtr;

  return DeviceDataPrv->EnEvents;
}

/*
** ===================================================================
**     Method      :  TU5_GetCounterValue (component TimerUnit_LDD)
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
TU5_TValueType TU5_GetCounterValue(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return (TU5_TValueType)FTM_PDD_ReadCounterReg(FTM2_BASE_PTR);
}

/*
** ===================================================================
**     Method      :  TU5_SetOffsetTicks (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Sets the new offset value to channel specified by the
**         parameter ChannelIdx. It is user responsibility to use value
**         below selected period. This method is available when at
**         least one channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         Ticks           - Number of counter ticks to compare
**                           match.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU5_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU5_TValueType Ticks)
{
  TU5_TDeviceData *DeviceDataPrv = (TU5_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (ChannelIdx > LAST_CHANNEL) {     /* Is the channel index out of range? */
    return ERR_PARAM_INDEX;            /* If yes then error */
  }
  if ((ChannelMode[ChannelIdx]) != 0U) { /* Is the channel in compare mode? */
    return ERR_NOTAVAIL;               /* If not then error */
  }
  FTM_PDD_WriteChannelValueReg(FTM2_BASE_PTR, ChannelDevice[ChannelIdx], (uint16_t)Ticks);
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TU5_GetOffsetTicks (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the number of counter ticks to compare match channel
**         specified by the parameter ChannelIdx. See also method
**         [SetOffsetTicks]. This method is available when at least one
**         channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         TicksPtr        - Pointer to return value of the
**                           number of counter ticks to compare match.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU5_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU5_TValueType *TicksPtr)
{
  TU5_TDeviceData *DeviceDataPrv = (TU5_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (ChannelIdx > LAST_CHANNEL) {     /* Is the channel index out of range? */
    return ERR_PARAM_INDEX;            /* If yes then error */
  }
  if ((ChannelMode[ChannelIdx]) != 0U) { /* Is the channel in compare mode? */
    return ERR_NOTAVAIL;               /* If not then error */
  }
  *TicksPtr = (TU5_TValueType)(FTM_PDD_ReadChannelValueReg(FTM2_BASE_PTR, ChannelDevice[ChannelIdx]));
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TU5_SetClockConfiguration (component TimerUnit_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU5_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration)
{
  TU5_TDeviceData *DeviceDataPrv = (TU5_TDeviceData *)DeviceDataPtr;

  FTM_PDD_SelectPrescalerSource(FTM2_BASE_PTR, FTM_PDD_DISABLED);
  switch (ClockConfiguration) {
    case CPU_CLOCK_CONFIG_0:
      DeviceDataPrv->EnMode = TRUE;    /* Set the flag "device enabled" in the actual clock configuration */
      DeviceDataPrv->Source = FTM_PDD_SYSTEM; /* Select clock source */
      FTM_PDD_SetPrescaler(FTM2_BASE_PTR, FTM_PDD_DIVIDE_1); /* Set prescaler register */
      break;
    default:
      DeviceDataPrv->EnMode = FALSE;   /* Set the flag "device disabled" in the actual clock configuration */
      break;
  }
  HWEnDi(DeviceDataPtr);               /* Enable/disable device according to status flags */
}

/*
** ===================================================================
**     Method      :  TU5_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(TU5_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  TU5_TDeviceDataPtr DeviceDataPrv = INT_FTM2__DEFAULT_RTOS_ISRPARAM;

  LDD_TEventMask State = 0U;

  if ((FTM_PDD_GetChannelInterruptFlag(FTM2_BASE_PTR, ChannelDevice[0])) != 0U) { /* Is the channel interrupt flag pending? */
    State |= LDD_TIMERUNIT_ON_CHANNEL_0; /* and set mask */
  }
  State &= DeviceDataPrv->EnEvents;    /* Handle only enabled interrupts */
  if (State & LDD_TIMERUNIT_ON_CHANNEL_0) { /* Is the channel 0 interrupt flag pending? */
    FTM_PDD_ClearChannelInterruptFlag(FTM2_BASE_PTR, ChannelDevice[0]); /* Clear flag */
    TU5_OnChannel0(DeviceDataPrv->UserDataPtr); /* Invoke OnChannel0 event */
  }
}

/*
** ===================================================================
**     Method      :  HWEnDi (component TimerUnit_LDD)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(LDD_TDeviceData *DeviceDataPtr)
{
  TU5_TDeviceDataPtr DeviceDataPrv = (TU5_TDeviceDataPtr)DeviceDataPtr;

  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  if (DeviceDataPrv->EnMode && DeviceDataPrv->EnUser) { /* Enable device? */
    FTM_PDD_SelectPrescalerSource(FTM2_BASE_PTR, DeviceDataPrv->Source);
  }
  else {
    FTM_PDD_SelectPrescalerSource(FTM2_BASE_PTR, FTM_PDD_DISABLED);
  }
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
}
/* END TU5. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
