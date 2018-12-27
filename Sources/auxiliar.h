/*
 * auxiliar.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_AUXILIAR_H_
#define SOURCES_AUXILIAR_H_

#define MENU 1
#define UP 2
#define DOWN 3
#define ENTER 4

#define AGUA 1
#define OLEO 2
#define TEMPA 5
#define TEMPB 4

byte teclado(void);
uint16_t temp_agua(void);
uint16_t sens_temp_a(void);
uint16_t sens_temp_b(void);
uint16_t temp_oleo(void);
uint16_t pressao_oleo(void);
uint16_t pressao_comb(void);
uint16_t sondaLambda(void);
void  adjustLamb(byte lamb);
float conversoes_temp(uint16_t temp);
byte convert_press(uint16_t press);
void tempAgua(bool mode);
uint16_t tensaoBateria(void);
uint16_t nivelTanque(void);
uint16_t tensaoOleo(void);
uint16_t tensaoOleo(void);
uint16_t tensaoBateria(void);
uint16_t sondaLambda(void);
uint16_t tensaoMap(void);
void lambda(bool unity);  // verifica qual é a unidade de engenharia a ser mostrada no display
void bateria(void);
void pergunta(void);

void definirAlarmes(void);
void organizaAlarmes(void);
void ver_alarmes(void);
void aux_temper(byte temper);

uint16_t unityMap(uint16_t analogMap, bool range);
uint16_t unityPressOleo(uint16_t analogOleo);
uint16_t unityPressComb(uint16_t analogComb);

uint16_t medida_ana[20];
uint16_t temperatura[20];

uint16_t tensaoLambdaMax,tensaoLambdaMin;
byte unityLambMin,unityLambMax;
bool engAgua,engOleo,engOleoB,engOleoA;

byte pressao[14];
uint16_t medida_ana_press[14];

uint16_t maxTempOleo, maxTempAgua,maxTempA,maxTempB;
uint16_t minTempOleo, minTempAgua,minTempA,minTempB;

int cont_piScAgua,cont_piScOleo,cont_piScA,cont_piScB;

bool piscAgua,piscOleo,piscA,piscB,agua,oleo,tempA,tempB;
byte histerezeAgua,histerezeOleo,histerezeA,histerezeB;

byte tecla;
byte chupa,almAgua,almOleo,almTempA,almTempB;
uint16_t aguaTemp,oleoTemp,TempA,TempB;

uint16_t aguaTemp;
int alarde;
byte alarme_[10];
int contShowAlarme,mede,contVerAlarme;
bool back;

uint16_t bateria_;
int ContBotao;


struct
{
	bool config : 1; //  ==1 está no modo de configuração do velocimetro
							//  ==o não está no modo de configuração do velocimetro
}velocimetro;

struct
{
	bool agua:1;
	bool oleo:1;
	bool tempa:1;
	bool tempb:1;
}limit;

struct
{
	bool config :1;
}odometro_;

struct
{
	bool alarme :1;
	bool histereze :1;
	bool configVelocidade:1;
}flag;



#endif /* SOURCES_AUXILIAR_H_ */
