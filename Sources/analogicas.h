/*
 * analogicas.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_ANALOGICAS_H_
#define SOURCES_ANALOGICAS_H_


#define ADC0 0
#define ADC1 1

#define PRESSAO_OLEO 2
#define TEMP_AGUA 0
#define TEMP_OLEO_B 1
#define SENSOR_VEL 3
#define RPM_OUT 4
#define SONDA_LAMBDA 3
#define NIVEL_TANQUE 4


#define TEMP_OLEO_A 2
#define MAP 5//  ??????????????????????????
#define COMB_PRESSAO 3
#define TEMP_OLEO 1
#define BAT_VOLTS 4
#define CHAVE_POS 0

uint16_t analogicasmed(byte adc_chanels,byte canal);
uint16_t tensao(byte t);
void Tensao_display(uint16_t tensao);
void sensorMap(void);
void SensorRange(void);
void pressMap(byte unidade);

byte engMap;
bool rangeSensor;



#endif /* SOURCES_ANALOGICAS_H_ */
