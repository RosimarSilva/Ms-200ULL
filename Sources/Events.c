/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#include "main.h"
#include "auxiliar.h"
#include "Velocimetro.h"
#include "display.h"
#include "aux_telas.h"
#include "nivel_tanque.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

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
** uint16_t contOverflow;
*/
uint16_t contOverflow;
byte over,over_;
word vai,mili,opa;
uint32_t brasil,brasil_;
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */

	if(conttempo)
	{
		conttempo --;
		if(conttempo <= 0) conttempo = 0;
	}

	if(atualiza_med)
	{
		atualiza_med --;
		if(atualiza_med <= 0) atualiza_med = 0;
	}

	 if(contMedRpm)
	 {
		 contMedRpm --;
		 if(contMedRpm <= 0) contMedRpm = 0;
	 }

	 if(cont_vel >0){
		 cont_vel --;
		 if(cont_vel <= 0)cont_vel =0;
		 if(cont_vel  > 300) cont_vel = 300;
	 }

	if(contSetHora)
	{
		contSetHora --;
		 if(contSetHora <= 0)contSetHora =0;

	}

	if(cont_piScAgua)
	{
		cont_piScAgua --;
		 if(cont_piScAgua <= 0)cont_piScAgua =0;

	}

	if(cont_piScOleo)
	{
		cont_piScOleo --;
		 if(cont_piScOleo <= 0)cont_piScOleo =0;

	}

	if(cont_piScA)
	{
		cont_piScA --;
		 if(cont_piScA <= 0)cont_piScA =0;

	}

	if(cont_piScB)
	{
		cont_piScB --;
		 if(cont_piScB <= 0)cont_piScB =0;

	}


	if(contShowAlarme)
	{
		contShowAlarme --;
		 if(contShowAlarme <= 0)contShowAlarme =0;

	}

	if(teta)
	{
		teta --;
		 if(teta <= 0)teta =0;

	}



	if(contVelocimetro)
	{
		contVelocimetro --;
		 if(contVelocimetro <= 0)contVelocimetro =0;

	}

	if(contVerAlarme)
	{
		contVerAlarme --;
		 if(contVerAlarme <= 0)contVerAlarme =0;
	}


	if(contDesliga)
	{
		contDesliga --;
		 if(contDesliga <= 0)
		 {
			 contDesliga =0;
			 tela = 90;
			 conttempo = 0;
		 }
	}


	if(mede!= 1050)
	{
		mede ++;
		 if(mede >= 1050)mede =1050;

	}


	if(contNivel)
	{
		contNivel --;
		 if(contNivel <= 0)
		 {
			 contNivel =0;
		 }
	}

	if(ContBotao < 100)
	{
		ContBotao ++;
		 if(ContBotao >= 100)
		 {
			 ContBotao =100;
		 }
	}

	brasil ++;
	brasil_ ++;

}

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
void Teclado_OnInterrupt(void)
{
  /* Write your code here ... */
	tecla = teclado();
}

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
 uint8_t media;
 uint64_t timeles;
 uint8_t vetorMedia =1;
void RPM_OnCapture(void)
{
  /* Write your code here ... */
	  /* Write your code here ... */


	pulsos++;
	if(pulsos == 1)
	{
		FC321_Reset();
		time =0;
		brasil_=0;

	}
	if(pulsos == 2)
	{
		over_ = FC321_GetTimeUS(&time);


		if(over_ >= ERR_OVERFLOW  )  // se estourou a o contador
		{
			FC321_Reset();
			time_= 0;
			time_ = (brasil_*1000);
			brasil_ = 0;
		}

		else
		{
			time =0;
			FC321_GetTimeUS(&time);
			FC321_Reset();
		/*	media ++;
			if(media <= 5)
			{
				 timeles += time;
			}

			else
			{
				mediaRpm[vetorMedia] = timeles/5;;
				vetorMedia++;
				media =1;
				if(vetorMedia >10)
				{
					vetorMedia = 1;
					for(int i = 1;i<=10;i++)
					{
						RpmNewVet += mediaRpm[i];
						 mediaRpm[i] =0;
					}
					time_ = RpmNewVet/10;
					RpmNewVet = 0;
				}
				media =1;
			//	time_ = timeles/5;
				timeles = 0;
				media =1;
			}*/

			time_ = time;
			teta = 1;

			FC321_Reset();
			brasil_ = 0;
			//FC321_Reset();
		}

		 pulsos = 0;

		 teta = 1200;

	}


}

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

void Sens_vel_OnCapture(void)
{
  /* Write your code here ... */


	pulsos_odo ++;
	pulsos_vel ++;
	if(pulsos_vel == 1)
	{
		FC322_Reset();  // reseta o timer do contador de periodo do velocimetro

		brasil = 0;
	}
	if(pulsos_vel == 2)
	{
		over = FC322_GetTimeUS(&vai);

		if(over >= ERR_OVERFLOW  )
		{
			timeVel = (brasil*1000);
			brasil = 0;
		}

	/*	if(over != 5)
		{
			//if(!dspRpm)
			//{
				media ++;
				if(media <= 5)
				{
					timeVel = 0;
					FC322_GetTimeUS(&timeVel);
					FC322_Reset();  // reseta o timer do contador de periodo do velocimetro

					timeles+=timeVel;
				}


			else
			{
				timeVel = 0;
				timeVel = timeles/5;
				timeles = 0;
				media =1;
				FC322_Reset();  // reseta o timer do contador de periodo do velocimetro
			}
		}*/


		if(over != 5)
		{
			timeVel = 0;
			FC322_GetTimeUS(&timeVel);
			FC322_Reset();  // reseta o timer do contador de periodo do velocimetro

			brasil =0;

			FC322_Reset();


		}
		contVelocimetro = 1500;

		pulsos_vel =0;
	}



}

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

void Sens_vel_OnOverflow(void)
{
  /* Write your code here ... */

	contOverflow ++;
	//Sens_vel_Reset();


	//FC321_Reset();

}

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
byte pont=0;
void Bluethoot_OnRxChar(void)
{
  /* Write your code here ... */
	char Data;
	 Bluethoot_RecvChar(&Data);//Bluethoot_GetCharsInRxBuf();
	 blueRec[pont] = Data;
	 pont++;

   //  if(pont == s)
	//if(pont == 12)
	//{
		//pont =0;
	//}
	 switch(Data)
	 {
	 case 'u': tecla = UP; break;
	 case 'm': tecla = MENU; break;
	 case 'd': tecla = DOWN; break;
	 case 'e': tecla = ENTER; break;
	 }
}

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
void Bluethoot_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TI2_OnInterrupt (module Events)
**
**     Component   :  TI2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


/* END Events */

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
