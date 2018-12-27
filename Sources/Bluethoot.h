/*
 * Bluethoot.h
 *
 *  Created on: 02/11/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_BLUETHOOT_H_
#define SOURCES_BLUETHOOT_H_

#define RESET 0
#define START 1
#define CLEAR 2
#define OK 3
#define SLEEP 4
#define NAME 5
#define LED 6

void comandosBluethoot(int comando);


char blueEnv[20];
char blueRec[20];

int comando;
void convertNumerBlu(char number);

#endif /* SOURCES_BLUETHOOT_H_ */
