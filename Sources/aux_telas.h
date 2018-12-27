/*
 * aux_telas.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_AUX_TELAS_H_
#define SOURCES_AUX_TELAS_H_


void cadastro_senha(void);
void alarmes(void);
void sonda_lambda(void);
void sens_temperatura(void);
void sensor_pressao(void);
void config_rpm(void);
void verSenha(void);
void AuxSenha(void);

void sensors(void);
void SensorTempAgua(void);

bool calVolts(bool sens);// se a medi��o do sensor for press�o do oleo sens = 1, se for combustivel = 2.
void configPressOleo(byte sens);
void calResistivo(bool tipoSens);
void pressaoComb(bool modo);
void pressaoOleo(bool modo);
void temperaturaAuxA(bool mode);
void temperaturaAuxB(bool mode);
void temperaturaOleo(bool mode);
void auxAlarmeOleo(bool tipo, uint16_t temp,byte s);
void pressAlarm(byte sensors);

byte contConFig,contConFig_;
byte pulsosPorVolta;
int contSetHora;
uint16_t senha;

uint16_t pressCombMin,pressCombMeio,pressCombMax;  // variaveis para a armazenar as medidas das anal�gicas da press�o do combust�vel
uint16_t pressOleoMax,pressOleoMeio,pressOleoMin;  // variaveis de medidas de press�o do oleo
uint16_t voltsCombMin,voltsCombMax, voltsOleomin,voltsOleoMax;
uint16_t tensaoOleoMax,tensaoOleoMin,pressaoOleoMax, pressaoOleoMin;

bool oleoPress,combPress;  // modo em que v�o ser medido o as press�es do �leo e combust�vel
bool lamb; // seleciona qual � a sonda lambda a ser instalada = 0 � Narrow = 1 � WB
byte pOleomin,pOleomax,pCombmin,pCombmax,pMapmin,pMapmax;
uint16_t oleoPressao,combPressao;
bool senhaHabilitada;

#endif /* SOURCES_AUX_TELAS_H_ */
