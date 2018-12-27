/* ###################################################################
**     Filename    : main.c
**     Project     : Ms_200
**     Processor   : MK20DX256VLL7
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-08-03, 20:21, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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


/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include "main.h"
#include "display.h"
#include "auxiliar.h"
#include "analogicas.h"
#include "aux_telas.h"
#include "velocimetro.h"
#include "telaPrincipal.h"
#include "dadosFlash.h"
#include "nivel_tanque.h"
#include "Bluethoot.h"

#include <stdarg.h>

#include <stdlib.h>
#include <string.h>

byte  p_cursor;



/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{

  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

 PE_low_level_init();

flashdataadr = 0x3F000;       // endereco para salvar dados de calibracao

pulsos = 0;
Cpu_EnableInt();
display_init();


inicializa();


 while(dadosSalvos ==0)//
  {
	  WDog1_Clear();
	 writeflash(flashdataadr,0,0);       // escreve dados na flash
	 readflash();
	 comandosBluethoot(LED);
	 delay(100);
	 comandosBluethoot(NAME);
	 delay(100);

	 comandosBluethoot(RESET);

	 delay(100);
  }

  p_cursor = 2;


while(1)
  {
	screen();

	WDog1_Clear();
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
/****************************************************************************************/
void delay(int t)
{
	conttempo = t;
	while(conttempo > 0)
	{
		WDog1_Clear();
	}
}
/******************************************************************************************/
void screen(void)
{
	switch(tela)
	{
		case 1: odometro();break;
		case 2: config_velocimetro(); break;
		case 3: tela_principal(); break;
		case 4: menu(); break;
		case 5:  tanque_config(); break;
		case 6:config_rpm(); break;
		case 7:sensor_pressao();break;
		case 8:sens_temperatura(); break;
		//case 9:sonda_lambda();break;
		case 10: setDate();break;
		case 11:AuxSenha(); break;//cadastro
		case 22:sensors(); break;
		case 90: tela99(); break;
		case 99: telaPrincipalCont(); break;
		case 100:telaPrincipal();break;
		case 101: telaPrincipal101(); break;
	}

}
/****************************************************************************************/
void tela99(void)
{
	uint16_t chave = 100;
	byte brab=0;

	 limpa_disp(); // limpa o display
	 comandosBluethoot(CLEAR);
	 comandosBluethoot(SLEEP);


	 deligaDAdosDSP();

	// Back_light_PutVal(0);


	  PowerOnOff_PutVal(0);

	   Cpu_SetClockConfiguration(1);  // derruba o clock do micro



	  while((tela == 90)&&(chave < 350))
	{
		chave = analogicasmed(ADC1,CHAVE_POS);

		brab=Cpu_GetClockConfiguration();
		WDog1_Clear();
	}

	Cpu_SetClockConfiguration(0);



	Cpu_EnableInt();
	chave = analogicasmed(ADC1,CHAVE_POS);
	if(chave < 350) {tela = 90;}  // aumenta o clock do micro}

	else
	{
		Cpu_SetClockConfiguration(0);  // aumenta o clock do micro
		PowerOnOff_PutVal(1);
		//Back_light_PutVal(1);

		display_init();
		Bluethoot_Enable();

		tela_0();

	}


}
/****************************************************************************************/
void tela_0(void)
{
	byte brab=0;
	 linha(1);
	 L(' '); L(' '); L(' '); L('M'); L(' ');   L('S'); L(' ');  L('-');  L(' '); L(1);   L(' '); L(0);   L(' ');  L(' ');  L(' ');  L(' ');

	   L('V'); L('e'); L('r'); L(':');   L(1); L('.');  L(2);L(' '); L(1); L(6); L('/'); L(1); L(0); L('/'); L(1); L(8);

	   linha(2);
	   L(' ');  L(' ');L(' '); L(' '); L('W'); L('A');   L('R'); L('M');  L('-');  L('U'); L('P');

	   inicializa();

	   comandosBluethoot(RESET);

	   brab=Cpu_GetClockConfiguration();

	   tela =100;
	   delay(4000);

	   tecla = 0;
	   medTanque(boia);
	   aux_nivel = nivel;

}
/************************************************************************************************/
void tela_principal(void)
{
	uint16_t pressur =0, speed = 0,pcomb = 0, rpm = 0;
	 byte p_oleo = 0, t_agua = 0;
	 limpa_disp(); // limpa o display
	 linha(1);
	  L(2);   L(9); L(9);  L('K');  L('m'); L('/');   L('h');  L(' ');  L(4); L(8); L(3); L(5);  L('r'); L('p');   L('m');

	  move_character(2,1);
	  L('P');   L('.'); L('C');  L('O');  L('M'); L('B');   L('.');    L(3); L(','); L(0); L(2); L('b'); L('a'); L('r');

	 move_character(3,1);
	  L('P');   L('.'); L('O');  L('L');  L('E'); L('O');   L('.');    L(2); L(','); L(5); L(4); L('b'); L('a'); L('r');

	  move_character(4,1);
	  L('T');   L('.'); L('A');  L('G');  L('U'); L('A');   L('.');    L(1); L(9); L(9);L('°'); L('C');

	while(tela == 3)
	{
		WDog1_Clear();
	}
}
/**********************************************************************************************/
void menu(void)
{
	byte  c = 16;
	Buzzer_PutVal(0);
	limpa_disp();
	move_character(1,3);
	 L('M'); L('E'); L('N');  L('U'); L(' '); L('C'); L('O');   L('N'); L('F');  L('I');  L('G');   L('.');

	// show_cursor(1);
	 scrool_menu(p_cursor);// posição do cursor
	 moveSeta(p_cursor,c);
	while(tela == 4)
	{

		if(tecla == DOWN)
		{
			p_cursor ++; tecla = 0;
			if(p_cursor > 9) p_cursor =9;


			if((p_cursor ==5)||(p_cursor ==8))
			{
				//show_cursor(0);
				scrool_menu(p_cursor);// posição do cursor
				//show_cursor(1);
			}

		//move_character(p_cursor,c);
			 moveSeta(p_cursor,c);
		}
		if(tecla == UP)
		{
			p_cursor--; tecla =0;

			if(p_cursor < 2) p_cursor =2;

			if((p_cursor ==4) ||(p_cursor ==7))
			{
				//show_cursor(0);
				scrool_menu(p_cursor);// posição do cursor
				//show_cursor(1);

			}

			//move_character(p_cursor,c);
				 moveSeta(p_cursor,c);
		}

		if(tecla == ENTER)
		{
			tecla = 0;
			switch(p_cursor)
			{
			case 2: tela = 1;break;
			case 3: tela = 2;break;
			case 4: tela = 5;break;
			case 5: tela = 6;break;
			case 6: tela = 7;break;
			case 7: tela = 8;break;
			case 8: tela = 10;break;
			case 9: tela = 11;break;
			//case 10: tela = 11;break;

			}
		}

		if(tecla == MENU) {tecla = 0; tela = 100;}
		WDog1_Clear();
	}
	 show_cursor(0);
}
/********************************************************************************************************/
void inicializa(void)
{
uint16_t chave = 0;
chupa = 0;

almAgua=0;almOleo=0;
almTempA=0;almTempB=0;
aguaTemp=0;oleoTemp=0;
TempA=0;TempB=0;

	histerezeAgua=1;
	histerezeOleo=1;
	histerezeA=1;
	histerezeB=1;

	velocidadeAnt = 60;
	flag.configVelocidade =0;

	mede = 1600;

	temperatura[0] = 0;
	temperatura[1] = 10;
	temperatura[2] = 20;
	temperatura[3] = 30;
	temperatura[4] = 40;
	temperatura[5] = 50;
	temperatura[6] = 60;
	temperatura[7] = 70;
	temperatura[8] = 80;
	temperatura[9] = 90;
	temperatura[10] = 100;
	temperatura[11] = 110;
	temperatura[12] = 120;
	temperatura[13] = 130;
	temperatura[14] = 140;
	temperatura[15] = 150;
	temperatura[16] = 160;

	medida_ana[0] = 3710;
	medida_ana[1] = 3421;
	medida_ana[2] = 3120;
	medida_ana[3] = 2750;
	medida_ana[4] = 2345;
	medida_ana[5] = 1933;
	medida_ana[6] = 1546;
	medida_ana[7] = 1229;
	medida_ana[8] = 942;
	medida_ana[9] = 745;
	medida_ana[10] = 585;
	medida_ana[11] = 447;
	medida_ana[12] = 352;
	medida_ana[13] = 280;
	medida_ana[14] = 217;
	medida_ana[15] = 176;
	medida_ana[16] = 138;

	 pressao[0] = 00;
	 pressao[1] = 10;
	 pressao[2] = 20;
	 pressao[3] = 30;
	 pressao[4] = 40;
	 pressao[5] = 50;
	 pressao[6] = 60;
	 pressao[7] = 70;
	 pressao[8] = 80;
	 pressao[9] = 90;
	 pressao[10] = 100;



	 medida_ana_press[0] = 172;
	 medida_ana_press[1] = 494;
	 medida_ana_press[2] = 761;
	 medida_ana_press[3] = 970;
	 medida_ana_press[4] = 1148;
	 medida_ana_press[5] = 1290;
	 medida_ana_press[6] = 1418;
	 medida_ana_press[7] = 1525;
	 medida_ana_press[8] = 1623;
	 medida_ana_press[9] = 1702;
	 medida_ana_press[10] = 1775;

	 anaBoia1[0] = 571;
	 anaBoia1[1] = 203;
	 anaBoia1[2] = 95;

	 anaBoia2[0] = 614;
	 anaBoia2[1] = 353;
	 anaBoia2[2] = 95;

	 anaBoia3[0] = 4;
	 anaBoia3[1] = 108;
	 anaBoia3[2] = 217;

	 readflash();

	 referVelocidade = (pulsosHora_*60)*60;

	 anaBoia4[0] = nivelTanqMin;
	 anaBoia4[1] =nivelTanqMeio;
	 anaBoia4[2] = nivelTanqMax;


	 percent[0] = 0;  percent[1] = 50;  percent[2] = 100;


	 if(!engAgua){maxTempAgua = maxTempAgua *18; maxTempAgua += 320;}
	 if(!engOleo){ maxTempOleo = maxTempOleo *18; maxTempOleo += 320;}
	 if(!engOleoA){ maxTempA = maxTempA *18; maxTempA += 320;}
	 if(!engOleoB){ maxTempB = maxTempB *18; maxTempB += 320;}
	 contDesliga = 3000;

	 aux_nivel = 255;
	 back = 1;

	 chave = analogicasmed(ADC1,CHAVE_POS);
	 if(chave < 350) {tela = 90;}  // aumenta o clock do micro}

	 else
	 {
		 tela = 100;
		// Back_light_PutVal(1);
	 }

	 duty = 1000;
	 BackLight_SetDutyUS(duty);
	 delay(50);
}
/********************************************************/
void deligaDAdosDSP(void)
{
	uint16_t en;

	Lcd_RS_PutVal(0);
	Lcd_RW_PutVal(0);
	Lcd_E_PutVal(0);
	LCD_0_PutVal(0);
	LCD_1_PutVal(0);
	LCD_2_PutVal(0);
	LCD_3_PutVal(0);
	LCD_4_PutVal(0);
	LCD_5_PutVal(0);
	LCD_6_PutVal(0);
	LCD_7_PutVal(0);


	//TU2_Disable(&en);

	//TU1_Disable(&en);
	//TU5_Disable(&en);
	//TU4_Disable(&en);
	//TU6_Disable(&en);
	//TU7_Disable(&en);
}
/**********************************************************/

