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

bool calVolts(bool sens);// se a medição do sensor for pressão do oleo sens = 1, se for combustivel = 2.
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

uint16_t pressCombMin,pressCombMeio,pressCombMax;  // variaveis para a armazenar as medidas das analógicas da pressão do combust´vel
uint16_t pressOleoMax,pressOleoMeio,pressOleoMin;  // variaveis de medidas de pressão do oleo
uint16_t voltsCombMin,voltsCombMax, voltsOleomin,voltsOleoMax;
uint16_t tensaoOleoMax,tensaoOleoMin,pressaoOleoMax, pressaoOleoMin;

bool oleoPress,combPress;  // modo em que vão ser medido o as pressões do óleo e combustível
bool lamb; // seleciona qual é a sonda lambda a ser instalada = 0 é Narrow = 1 é WB
byte pOleomin,pOleomax,pCombmin,pCombmax,pMapmin,pMapmax;
uint16_t oleoPressao,combPressao;
bool senhaHabilitada;

#endif /* SOURCES_AUX_TELAS_H_ */
