/*
 * dadosFlash.c
 *
 *  Created on: 12/09/2018
 *      Author: Rosimar
 */

#include "main.h"
#include "velocimetro.h"
#include "nivel_tanque.h"
#include "dadosFlash.h"
#include "aux_telas.h"
#include "display.h"
#include "nivel_tanque.h"
#include "auxiliar.h"
#include "analogicas.h"


//extern uint16_t a,b,c,d,e,f,g,h;

/*******************************************************************/
// p é a posicao do vetor dadosalvo qdo se quer salvar apenas um valor
void writeflash(unsigned long addrflash, int p, unsigned int v)
{
  unsigned int aux;
  unsigned long pont;
  unsigned int dado;



  	if(dadosalvo[0] != 0xAA)
  	{
  		calibracaoPadrao();
  		 WDog1_Clear();
  	}

    if(p == 0)
    {
    	 WDog1_Clear();
    	dadosalvo[1] = auxPulsos_odo;  // define quantos pulsos tem em 100 metros
    	dadosalvo[2] = odometroMetro;
    	dadosalvo[3] = odometroTotal;
    	dadosalvo[4] = pulsosPorVolta;
    	dadosalvo[5] = nivelTanqMin;
		dadosalvo[6] = nivelTanqMeio;
		dadosalvo[7] = nivelTanqMax;

		dadosalvo[8] = voltsOleomin;
		dadosalvo[9] = voltsCombMin;

		dadosalvo[10] = voltsOleoMax;
		dadosalvo[11] = pressOleoMax;

		dadosalvo[12] =	voltsCombMax;   // volts do combustível máximo
		dadosalvo[13] = pressCombMax;// pressão máxima do combustível

		dadosalvo[14] = oleoPress; // modo em que vai ser medido a pressão do òleo / = 0 vai ser em volts / =1 conforme tabela fornecido pelo fabricante do sensor
		dadosalvo[15] = combPress;   // modo em que vai ser medido a pressão do combustível / = 0 vai ser em volts / =1 conforme tabela fornecido pelo fabricante do sensor

		dadosalvo[16] =	tensaoLambdaMax;

		dadosalvo[17] = unityLambMin;
		dadosalvo[18] = unityLambMax;

		dadosalvo[19] = engAgua;// variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith
		dadosalvo[20] = engOleo;// variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith

		dadosalvo[21] = engOleoA;// variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith
		dadosalvo[22] = engOleoB;// variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith

		dadosalvo[23] = tensaoLambdaMin;

		dadosalvo[24] = lamb;

		  dadosalvo[25] = a;
		  dadosalvo[26] = b;
		 dadosalvo[27] = c;
		dadosalvo[28] = d;
		 dadosalvo[29] = e;
		  dadosalvo[30] = f;
		 dadosalvo[31] = g;
		 dadosalvo[32] = h;

		 dadosalvo[33] =  maxTempOleo;
		  dadosalvo[34] = maxTempAgua;
		 dadosalvo[35] = maxTempA;
		 dadosalvo[36] = maxTempB;

		 dadosalvo[37] = engMap;

		 dadosalvo[38] =  minTempAgua ;
		  dadosalvo[39] = minTempOleo  ;
		  dadosalvo[40] = minTempA ;
		  dadosalvo[41] = minTempB;

		  dadosalvo[42] = pOleomin;
		  dadosalvo[43] = pOleomax;
		  dadosalvo[44] = pCombmin ;
		  dadosalvo[45] = pCombmax ;
		  dadosalvo[46] =  pMapmin ;
		  dadosalvo[47] =  pMapmax ;
		  dadosalvo[48] =  boia ;
		  dadosalvo[49] =  pulsosHora_ ;

		  dadosalvo[50] = kmRest;
		  dadosalvo[51] = nivel_alarme;
		  dadosalvo[52] =  contKmfuel;

		  dadosalvo[53] = kmRest;
		  dadosalvo[54] = kmRest_;
		  dadosalvo[55] =  percentConfig;
		  dadosalvo[56] =   flag.histereze;
		  dadosalvo[57] = odometroParcial;
		  dadosalvo[58] = senha;
		  dadosalvo[59] = rangeSensor;

		  WDog1_Clear();

		  Cpu_DisableInt();

    	aux = 0;
    	pont =  0x3F000;
    	while (aux <= 59 )          // lê (iex, iey, sdx, sdy, tempmin, tempmax, Pemin, Pemax, Psmin, Psmax, dp0, dp5, dp20, dp45, valvula)
    	{                                    // total de 24 dados
    		dado = dadosalvo[aux];
    		IFsh1_SetWordFlash(pont, dado);
    		//IFsh1_SetWordFlash(pont, dado);

    		aux++;
    		pont = pont + 0x02;       // incrementa o endereco que pula de 0x02 em 0x02 (16 bits)
    	}
    } // if (p == 0)

    else
    {
    	  Cpu_DisableInt();
    	if (p != 0)
    	{
    		dadosalvo[p] = v;

    		pont =  0x3F000 + 2*p;

    		//Cpu_DisableInt();

    		dado = dadosalvo[p];
    		IFsh1_SetWordFlash(pont, dado);
    		// IFsh1_SetWordFlash(pont, dado);
    	}      //  if (p != 0)
    }



    Cpu_EnableInt();
}
/*************************************************************/
void readflash(void)
{
  unsigned char aux;
  unsigned long pont;
  unsigned int auxdp;
  word Data;

  // Lê os dados de programacao a cada 32 bits (0x04) pois cada dado tem 32 bits
  // Os dados estão escritos a partir do endereco 0x3F000 na flash. O espaco é 1Kbytes. Endereco final = 0x3F000 + 1000 bytes

  // Se a leitura estiver correta: flag.salvos = 1
  // Se os dados forem 0xffff: flag.salvos = 0

 // DisableInterrupts;
  Cpu_DisableInt();
  aux = 0;
  pont =  0x3F000;
  while (aux <= 59)          // lê dados salvos
  {                                    // total de 24 dados
   // dadosalvo[aux] = *(word*)pont;IFsh1_GetWordFlash();
	   IFsh1_GetWordFlash(pont,&Data);

	   dadosalvo[aux] = (uint16_t*)Data;

    aux++;
    pont = pont + 0x02;       // incrementa o endereco que pula de 0x02 em 0x02 (16 bits)
  }
  Cpu_EnableInt();

 if(dadosalvo[0] == 0xAA)
 {
	 auxPulsos_odo = dadosalvo[1];  // define quantos pulsos tem em 100 metros
	 odometroMetro = dadosalvo[2];
	 odometroTotal = dadosalvo[3];
	 pulsosPorVolta = dadosalvo[4];
	 nivelTanqMin = dadosalvo[5] ;
	 nivelTanqMeio = dadosalvo[6];
	 nivelTanqMax = dadosalvo[7];
	 voltsOleomin = dadosalvo[8];
	 voltsCombMin = dadosalvo[9];

	voltsOleoMax = dadosalvo[10];  // volts correspondente a medida máxima para a medição do óleo
	pressOleoMax = dadosalvo[11]; // pressão maxima do oleo

	voltsCombMax = dadosalvo[12];   // volts do combustível máximo
	pressCombMax = dadosalvo[13];// pressão máxima do combustível

	oleoPress = dadosalvo[14]; // modo em que vai ser medido a pressão do òleo / = 0 vai ser em volts / =1 conforme tabela fornecido pelo fabricante do sensor
	combPress  = dadosalvo[15];   // modo em que vai ser medido a pressão do combustível / = 0 vai ser em volts / =1 conforme tabela fornecido pelo fabricante do sensor

	tensaoLambdaMax = dadosalvo[16];

	unityLambMin =dadosalvo[17];  // variáveis que iram configurar as medidas da sonda lâmbda
	unityLambMax = dadosalvo[18];// variáveis que iram configurar as medidas da sonda lâmbda

	 engAgua= dadosalvo[19];  // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith
	 engOleo = dadosalvo[20]; // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith

	 engOleoA = dadosalvo[21];  // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith
	 engOleoB = dadosalvo[22]; // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith

	 tensaoLambdaMin =  dadosalvo[23];

	 lamb = dadosalvo[24];

	 a = dadosalvo[25];
	 b = dadosalvo[26];
	 c = dadosalvo[27];
	 d = dadosalvo[28];
	 e = dadosalvo[29];
	 f = dadosalvo[30];
	 g = dadosalvo[31];
	 h = dadosalvo[32];

	 maxTempOleo = dadosalvo[33] ;
	  maxTempAgua = dadosalvo[34] ;
	  maxTempA = dadosalvo[35] ;
	  maxTempB = dadosalvo[36] ;

	  engMap = dadosalvo[37] ;

	  minTempAgua = dadosalvo[38] ;
	  minTempOleo = dadosalvo[39] ;
	  minTempA = dadosalvo[40] ;
	  minTempB= dadosalvo[41] ;

	  pOleomin = dadosalvo[42] ;
	  pOleomax = dadosalvo[43] ;
	  pCombmin = dadosalvo[44] ;
	  pCombmax = dadosalvo[45] ;
	  pMapmin = dadosalvo[46] ;
	  pMapmax = dadosalvo[47] ;

	  boia = dadosalvo[48] ;

	   pulsosHora_= dadosalvo[49] ;

	   kmRest = dadosalvo[50];
	   nivel_alarme = dadosalvo[51];
	   contKmfuel = dadosalvo[52];

	   kmRest = dadosalvo[53];
	   kmRest_ = dadosalvo[54];
	   percentConfig = dadosalvo[55];
	   flag.histereze = dadosalvo[56];
	   odometroParcial = dadosalvo[57];

	   senha =  dadosalvo[58];

	   rangeSensor =  dadosalvo[59];


	 dadosSalvos = 1;
 }



 // EnableInterrupts;
}
/**********************************************************************/
void calibracaoPadrao(void)
{

	dadosalvo[0] = 0xAA;

	auxPulsos_odo = 100;
	odometroMetro = 0;
	odometroTotal = 0;
	odometroParcial = 0;
	pulsosPorVolta = 1;

	 nivelTanqMin = 571;
	 nivelTanqMeio = 203;
	 nivelTanqMax = 95;

	 tensaoLambdaMax = 330; //3,30 volts

	 unityLambMin = 2;
	 unityLambMax = 14;

	 engAgua = 1; // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith
	 engOleo =1; // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith

	 engOleoA = 1; // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith
	 engOleoB =1; // variaveis responsáveis por definir a unidade de engenharia das temperaturas = 1 celsius/ = 0 fahreneith

	 voltsCombMax = 450;
	 voltsOleoMax = 450;

	 pulsosHora_ = 597;


	 a = '?';
	 b = '?';
	 c = '?';
	 d = '?';
	 e = '?';
	 f = '?';
	 g = '?';
	 h = '?';

	 maxTempOleo= 90 ;
	  maxTempAgua=90;
	  maxTempA = 90 ;
	  maxTempB  =90;

	  engMap = 2; // define como unidade de engenharia kPa como default


	ano = 2018; dia = 14; mes = 9;

	hora = 21; minuto = 39;

	  minTempAgua = 0;
	  minTempOleo = 0;
	  minTempA  = 0;
	  minTempB = 0;

	  pOleomin = 0;
	  pOleomax =50;
	  pCombmin = 0;
	  pCombmax = 50;
	  pMapmin = 0;
	  pMapmax =50;

	  pulsosHora =  60;

	  boia = 1;
	  showTanque = 0;

	  kmRest= 0;

	  contKmfuel = 0;
	  senha = 0;
	  rangeSensor = 1;

	setRtc(hora,minuto);

	TmDt1_SetDate(ano,mes,dia);
}
/*****************************************************************************/
void getRtc(void)  // lê a hopra
{
	//TIMEREC Time;
	byte h,hh,m,mm;

	LDD_TDeviceData *MyRTCPtr;
	LDD_RTC_TTime Time;

	//TmDt1_GetTime(&Time);

	RTC1_GetTime(MyRTCPtr,&Time);
	hora =  Time.Hour;
	minuto = Time.Minute;

	if(tela == 100)
	{
		h = Time.Hour/10;
		hh = Time.Hour%10;

		m = Time.Minute/10;
		mm = Time.Minute%10;

		if(!almTempA)
		{
			move_character(4,12);
			L(h); L(hh);L(':'); L(m);L(mm);
		}
		contSetHora = 30000;
	}
}
/***********************************************************************************/
void setRtc(byte hora, byte minute)
{
	LDD_TDeviceData *MyRTCPtr;
	LDD_RTC_TTime Time;
	LDD_TError Error;

	Time.Hour = hora;
	Time.Minute = minute;
	Time.Second = 0;
	Time.Day = 28;
	Time.Month = 12;
	Time.Year = 2018;
	Error = RTC1_SetTime(MyRTCPtr, &Time);


	//TmDt1_SetTime(hora, minute, 0, 0);
}
/****************************************************************************/
void getDate(void)
{
	DATEREC Date;

	LDD_TDeviceData *MyRTCPtr;
	LDD_RTC_TTime Time;
	//TmDt1_GetDate(&Date);
	RTC1_GetTime(MyRTCPtr,&Time);
	dia = Date.Day;
	mes = Date.Month;
	ano = Date.Year;
}


