/*
 * main.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_MAIN_H_
#define SOURCES_MAIN_H_
/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
//#include "Back_light.h"
//#include "BitIoLdd1.h"
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
#include "TU2.h"
#include "ADC1_chanells.h"
#include "AdcLdd1.h"
#include "ADC0_chanells.h"
#include "AdcLdd2.h"
#include "RPM.h"
#include "CaptureLdd1.h"
//#include "TU3.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void delay(int t);
void screen(void);
void tela99(void);
void tela_0(void);
void tela_principal(void);
void menu(void);
void scrool_menu(byte  indice);
void inicializa(void);
void setDate(void);
void deligaDAdosDSP(void);


int conttempo,teta;
uint16_t time;
uint64_t time_;

uint32_t timeVel;
uint16_t anaBoia1[3];
uint16_t anaBoia2[3];
uint16_t anaBoia3[3];
uint16_t anaBoia4[3];


byte percent[3];
int contDesliga;

byte tela;
word data[20];



#endif /* SOURCES_MAIN_H_ */
