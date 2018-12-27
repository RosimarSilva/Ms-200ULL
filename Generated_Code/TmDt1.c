/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : TmDt1.c
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Component   : TimeDate
**     Version     : Component 02.111, Driver 01.00, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-11-12, 20:36, # CodeGen: 216
**     Abstract    :
**         This component "TimeDate" implements real time and date.
**         The component requires a periodic interrupt generator: timer
**         compare or reload register or timer-overflow interrupt
**         (of free running counter). User can select precision of
**         selected timer.
**         The component supports also alarm with event OnAlarm.
**     Settings    :
**          Component name                                 : TmDt1
**          Periodic interrupt source                      : LPTMR0_CMR
**          Counter                                        : LPTMR0_CNR
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_LPTimer
**            Interrupt priority                           : medium priority
**          Resolution                                     : 1 sec
**          Component uses entire timer                    : no
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Time                                         : 23:45:00
**            Date                                         : 2018-11-10
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component enabled
**            Slow speed mode                              : This component enabled
**          Referenced components                          : 
**            TimeDate_LDD                                 : TimeDate_LDD
**     Contents    :
**         Enable  - byte TmDt1_Enable(void);
**         Disable - byte TmDt1_Disable(void);
**         SetTime - byte TmDt1_SetTime(byte Hour, byte Min, byte Sec, byte Sec100);
**         GetTime - byte TmDt1_GetTime(TIMEREC *Time);
**         SetDate - byte TmDt1_SetDate(word Year, byte Month, byte Day);
**         GetDate - byte TmDt1_GetDate(DATEREC *Date);
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
** @file TmDt1.c
** @version 01.00
** @brief
**         This component "TimeDate" implements real time and date.
**         The component requires a periodic interrupt generator: timer
**         compare or reload register or timer-overflow interrupt
**         (of free running counter). User can select precision of
**         selected timer.
**         The component supports also alarm with event OnAlarm.
*/         
/*!
**  @addtogroup TmDt1_module TmDt1 module documentation
**  @{
*/         

/* MODULE TmDt1. */

#include "TmDt1.h"

/*
** ===================================================================
**     Method      :  TmDt1_Enable (component TimeDate)
**     Description :
**         This method enables the component - it starts the time/date
**         timer. Events may be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte TmDt1_Enable(void)
**  This method is implemented as a macro. See TmDt1.h file.  **
*/

/*
** ===================================================================
**     Method      :  TmDt1_Disable (component TimeDate)
**     Description :
**         This method disables the component - it stops the time/date
**         timer. No events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte TmDt1_Disable(void)
**  This method is implemented as a macro. See TmDt1.h file.  **
*/

/*
** ===================================================================
**     Method      :  TmDt1_SetTime (component TimeDate)
**     Description :
**         This method sets a new actual time.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Hour            - Hours (0 - 23)
**         Min             - Minutes (0 - 59)
**         Sec             - Seconds (0 - 59)
**         Sec100          - Hundredths of seconds (0 - 99)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte TmDt1_SetTime(byte Hour,byte Min,byte Sec,byte Sec100)
{
  LDD_TimeDate_TTimeRec InhrTime;

  InhrTime.Hour = (uint16_t)Hour;
  InhrTime.Min = (uint16_t)Min;
  InhrTime.Sec = (uint16_t)Sec;
  InhrTime.Sec100 = (uint16_t)Sec100;
  return TimeDateLdd1_SetTime(TimeDateLdd1_DeviceData, &InhrTime);
}

/*
** ===================================================================
**     Method      :  TmDt1_GetTime (component TimeDate)
**     Description :
**         This method returns current time.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - Pointer to the structure TIMEREC. It
**                           contains actual number of hours, minutes,
**                           seconds and hundredths of seconds.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte TmDt1_GetTime(TIMEREC *Time)
{
  LDD_TimeDate_TTimeRec InhrTime;
  LDD_TError Error;

  Error = TimeDateLdd1_GetTime(TimeDateLdd1_DeviceData, &InhrTime);
  if (Error != ERR_OK) {
    return (byte)Error;
  }
  Time->Hour = (byte)InhrTime.Hour;
  Time->Min = (byte)InhrTime.Min;
  Time->Sec = (byte)InhrTime.Sec;
  Time->Sec100 = (byte)InhrTime.Sec100;
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TmDt1_SetDate (component TimeDate)
**     Description :
**         This method sets a new actual date. See limitations at the
**         page <General Info>.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Year            - Years (16-bit unsigned integer)
**         Month           - Months (8-bit unsigned integer)
**         Day             - Days (8-bit unsigned integer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte TmDt1_SetDate(word Year,byte Month,byte Day)
{
  LDD_TimeDate_TDateRec InhrDate;

  InhrDate.Year = (uint16_t)Year;
  InhrDate.Month = (uint16_t)Month;
  InhrDate.Day = (uint16_t)Day;
  InhrDate.DayOfWeek = (uint16_t)UINT_MAX; /* Correct day of week will be calculated */
  return TimeDateLdd1_SetDate(TimeDateLdd1_DeviceData, &InhrDate);
}

/*
** ===================================================================
**     Method      :  TmDt1_GetDate (component TimeDate)
**     Description :
**         This method returns current date.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Date            - Pointer to the structure DATEREC. It
**                           contains actual year, month, and day
**                           description.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte TmDt1_GetDate(DATEREC *Date)
{
  LDD_TimeDate_TDateRec InhrDate;
  LDD_TError Error;

  Error = TimeDateLdd1_GetDate(TimeDateLdd1_DeviceData, &InhrDate);
  if (Error != ERR_OK) {
    return (byte)Error;
  }
  Date->Year = (word)InhrDate.Year;
  Date->Month = (byte)InhrDate.Month;
  Date->Day = (byte)InhrDate.Day;
  return ERR_OK;                       /* OK */
}

/* END TmDt1. */

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
