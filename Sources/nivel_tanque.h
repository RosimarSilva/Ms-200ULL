/*
 * nivel_tanque.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_NIVEL_TANQUE_H_
#define SOURCES_NIVEL_TANQUE_H_
void tanque_config(void);
void atualiza_medTanq(void);
void medTanque(byte config);
void chekKm(uint16_t nilvelAlarde, uint16_t nivelBoia);
void KmRemaining(void);

uint16_t nivelTanqMin,nivelTanqMeio,nivelTanqMax,contKmfuel;
byte boia;
byte nivel,aux_nivel,nivel_ant;

bool showTanque,OkFuel;// verifica se é para ver o alrme do tanque
byte tanqueBrasil;
byte nivel_alarme; // última medida da porcentagem do tanque
int contNivel;
byte showFuel;// mosttra o aviso de km restantes na reserva
byte auxBoia,auxBoia_,conta;
bool percentConfig;

struct
{
	byte etapa:1;  // são tres etapas para calibração da medição vazio  metade totalmente cheio
}tanque;


#endif /* SOURCES_NIVEL_TANQUE_H_ */
