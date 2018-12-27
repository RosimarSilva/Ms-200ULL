/*
 * Bluethoot.c
 *
 *  Created on: 02/11/2018
 *      Author: Rosimar
 */


#include "Bluethoot.h"

void comandosBluethoot(int comando)
{
	int s=0;
	blueEnv[0]= 'A'; blueEnv[1]= 'T';blueEnv[2]= '+';
	switch (comando)
	{
		case RESET:
		{
			comando = RESET;
			blueEnv[3] = 'R'; blueEnv[4] = 'E'; blueEnv[5] = 'S'; blueEnv[6] = 'E'; blueEnv[7] = 'T';
			s = 7;
		}break;

		case SLEEP:
		{
			comando = SLEEP;
			blueEnv[3] = 'S'; blueEnv[4] = 'L'; blueEnv[5] = 'E'; blueEnv[6] = 'E'; blueEnv[7] = 'P';
			s = 7;
		}break;

		case START:
		{
			comando = START;
			blueEnv[3] = 'S'; blueEnv[4] = 'T'; blueEnv[5] = 'A'; blueEnv[6] = 'R'; blueEnv[7] = 'T';
			s = 7;
		}break;

		case OK:
		{
			comando = OK;
			blueEnv[0] = 'A'; blueEnv[1] = 'T';
			s = 1;
		}break;

		case LED:
		{
			comando = LED;
			blueEnv[3] = 'P'; blueEnv[4] = 'I'; blueEnv[5] = 'O'; blueEnv[6] = '1'; blueEnv[7] = '1';
			s = 7;
		}break;

		case NAME:
		{
			comando = NAME;
			blueEnv[3] = 'N'; blueEnv[4] = 'A'; blueEnv[5] = 'M'; blueEnv[6] = 'E'; blueEnv[7] = 'M'; blueEnv[8] = 'S'; blueEnv[9] = '-'; blueEnv[10] = '1'; blueEnv[11] = '0';
			s = 11;
		}break;
		case CLEAR:
		{
			comando = CLEAR;
			blueEnv[3] = 'C'; blueEnv[4] = 'L'; blueEnv[5] = 'E'; blueEnv[6] = 'A'; blueEnv[7] = 'R';
			s = 7;
		}break;
	}

		for(int i =0; i<= s;i++)  Bluethoot_SendChar(blueEnv[i]);
		for(int i=0;i<=20;i++)blueEnv[i]=0;
}
/*********************************************/
void convertNumerBlu(char number)
{
	switch(number)
	{
		/*case 0: Bluethoot_SendChar('0');break;
		case 1: Bluethoot_SendChar('1');break;
		case 2: Bluethoot_SendChar('2');break;
		case 3: Bluethoot_SendChar('3');break;
		case 4: Bluethoot_SendChar('4');break;
		case 5: Bluethoot_SendChar('5');break;
		case 6: Bluethoot_SendChar('6');break;
		case 7: Bluethoot_SendChar('7');break;
		case 8: Bluethoot_SendChar('8');break;
		case 9: Bluethoot_SendChar('9');break;*/
	}
}
