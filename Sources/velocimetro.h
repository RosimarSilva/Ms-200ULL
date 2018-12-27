/*
 * velocimetro.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_VELOCIMETRO_H_
#define SOURCES_VELOCIMETRO_H_

#define RPM 1
#define KM 60

void config_velocimetro(void);
void odometro(void);
byte getPulsos(byte sensor); // lê pulsos de sensores
uint16_t getUnidades(byte sensor);
void calculaOdometro(void);
void getPulsosOdo(void);
void getRpm(void);
void calculaVelocidade(bool config);
void velocidade(void);
void showOdometro(void);
uint16_t acelerom(uint16_t velocidade);

uint16_t velocidadeAnt;
uint16_t pulsos_vel; // pulsos do sensor do velocimtro
uint16_t pulsos_odo ; // pulsos que o sensor emite a cada 100 metros
uint16_t auxPulsos_odo;
int contMedRpm,cont_vel;
uint32_t referVelocidade;
uint16_t odometroMetro,odometroParcial; // zera o contador de metro
uint32_t odometroTotal;
byte contpulsos,contFuel;

byte kmRest,kmRest_;

uint32_t pulsosHora;
uint16_t pulsosHora_;
int contVelocimetro;


int pulsos,vaicorintias;


#endif /* SOURCES_VELOCIMETRO_H_ */
