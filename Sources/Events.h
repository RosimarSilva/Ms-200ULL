/* ###################################################################
**     Filename    : Events.h
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-08-03, 20:21, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "WDog1.h"
#include "WatchDogLdd1.h"
#include "TU1.h"
#include "Lcd_RS.h"
#include "BitIoLdd2.h"
#include "Lcd_RW.h"
#include "BitIoLdd3.h"
#include "Lcd_E.h"
#include "BitIoLdd4.h"
#include "LCD_0.h"
#include "BitIoLdd5.h"
#include "LCD_1.h"
#include "BitIoLdd6.h"
#include "LCD_2.h"
#include "BitIoLdd7.h"
#include "LCD_3.h"
#include "BitIoLdd8.h"
#include "LCD_4.h"
#include "BitIoLdd9.h"
#include "LCD_5.h"
#include "BitIoLdd10.h"
#include "LCD_6.h"
#include "BitIoLdd11.h"
#include "LCD_7.h"
#include "BitIoLdd12.h"
#include "MENU0.h"
#include "BitIoLdd13.h"
#include "UP.h"
#include "BitIoLdd14.h"
#include "DOWN.h"
#include "BitIoLdd15.h"
#include "ENTER.h"
#include "BitIoLdd16.h"
#include "Teclado.h"
#include "TimerIntLdd2.h"
#include "TU4.h"
#include "Sens_vel.h"
#include "CaptureLdd2.h"
#include "FC322.h"
#include "RealTimeLdd2.h"
#include "TU5.h"
#include "TmDt1.h"
#include "TimeDateLdd1.h"
#include "TU6.h"
#include "IFsh1.h"
#include "IntFlashLdd1.h"
#include "TU7.h"
#include "Bluethoot.h"
#include "ASerialLdd1.h"
#include "Buzzer.h"
#include "BitIoLdd17.h"
#include "PowerOnOff.h"
#include "BitIoLdd18.h"
#include "pta5.h"
#include "BitIoLdd19.h"
#include "Bit1.h"
#include "BitIoLdd21.h"
#include "pta19.h"
#include "BitIoLdd20.h"
#include "PTB.h"
#include "BitsIoLdd1.h"
#include "PTB9.h"
#include "BitIoLdd22.h"
#include "PTC.h"
#include "BitsIoLdd2.h"
#include "BIT_PTC.h"
#include "BitIoLdd23.h"
#include "PTC13_14_15.h"
#include "BitsIoLdd3.h"
#include "PTC18.h"
#include "BitIoLdd24.h"
#include "PTES.h"
#include "BitsIoLdd4.h"
#include "PTE1.h"
#include "BitIoLdd25.h"
#include "PTE24.h"
#include "BitsIoLdd5.h"
#include "BackLight.h"
#include "PwmLdd1.h"
#include "TU3.h"
#include "RTC1.h"
#include "TU2.h"
#include "FC321.h"
#include "RealTimeLdd1.h"
#include "ADC1_chanells.h"
#include "AdcLdd1.h"
#include "ADC0_chanells.h"
#include "AdcLdd2.h"
#include "RPM.h"
#include "CaptureLdd1.h"

uint16_t mediaRpm[12];
uint64_t RpmNewVet;

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  Teclado_OnInterrupt (module Events)
**
**     Component   :  Teclado [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Teclado_OnInterrupt(void);

/*
** ===================================================================
**     Event       :  RPM_OnCapture (module Events)
**
**     Component   :  RPM [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void RPM_OnCapture(void);

/*
** ===================================================================
**     Event       :  RPM_OnOverflow (module Events)
**
**     Component   :  RPM [Capture]
**     Description :
**         This event is called if counter overflows (only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>.This event is available only if a <interrupt
**         service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void RPM_OnOverflow(void);

/*
** ===================================================================
**     Event       :  Cap1_OnCapture (module Events)
**
**     Component   :  RPM [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cap1_OnCapture(void);

/*
** ===================================================================
**     Event       :  Sens_vel_OnCapture (module Events)
**
**     Component   :  Sens_vel [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Sens_vel_OnCapture(void);

/*
** ===================================================================
**     Event       :  Sens_vel_OnOverflow (module Events)
**
**     Component   :  Sens_vel [Capture]
**     Description :
**         This event is called if counter overflows (only when the
**         component is enabled - <Enable> and the events are enabled -
**         <EnableEvent>.This event is available only if a <interrupt
**         service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Sens_vel_OnOverflow(void);

/*
** ===================================================================
**     Event       :  Bluethoot_OnRxChar (module Events)
**
**     Component   :  Bluethoot [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Bluethoot_OnRxChar(void);

/*
** ===================================================================
**     Event       :  Bluethoot_OnTxChar (module Events)
**
**     Component   :  Bluethoot [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Bluethoot_OnTxChar(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
