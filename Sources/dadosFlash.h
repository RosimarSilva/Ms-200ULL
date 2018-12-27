/*
 * dadosFlash.h
 *
 *  Created on: 12/09/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_DADOSFLASH_H_
#define SOURCES_DADOSFLASH_H_


void writeflash(unsigned long addrflash, int p, unsigned int v);
void readflash(void);
void calibracaoPadrao(void);
void gettRtc(void);
void setRtc(byte hora, byte minute);

unsigned long flashdataadr;       // endereco para salvar dados de calibracao
uint16_t dadosalvo[60];
bool dadosSalvos;

byte dia,mes,hora,minuto;
word ano;


#endif /* SOURCES_DADOSFLASH_H_ */
