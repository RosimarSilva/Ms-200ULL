/*
 * analogicas.c
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#include "main.h"
#include "analogicas.h"
#include "dadosFlash.h"
#include "auxiliar.h"

extern byte  p_cursor;

uint16_t analogicasmed(byte adc_chanels, byte canal)
{
	int amostras;
	word Data=0;
	uint32_t bits=0;

	if(adc_chanels == ADC0)
	{
		if(canal == TEMP_OLEO_B)
		{
			ADC0_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC0_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}

			bits = (bits/5);
		}//if(canal == OLEO_TEMP_B)


		if(canal == TEMP_AGUA)
		{
			ADC0_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC0_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}

			bits = (bits/5);
		}//if(canal == TEMP_AGUA)

		if(canal == PRESSAO_OLEO)
		{
			ADC0_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC0_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}

			bits = (bits/5);
		}//if(canal == PRESSAO_OLEO)

		if(canal == SONDA_LAMBDA)
		{
			ADC0_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC0_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}

			bits = (bits/5);
		}//if(canal == SONDA_LAMBDA)

		if(canal == NIVEL_TANQUE)
		{
			ADC0_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC0_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}

			bits = (bits/5);
		}//if(canal == NIVEL_TANQUE)


	}
/************************************************************************************************************************/
	if(adc_chanels == ADC1)
	{
		if(canal == CHAVE_POS)
		{
			ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC1_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida

				}


			}

			bits = (bits/5);
		}//if(canal == CHAVE_POS)

		if(canal == TEMP_OLEO_A)
		{
			ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					//ADC1_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					ADC1_chanells_GetChanValue16(canal,&Data);
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida

				}


			}

			bits = (bits/5);
		}//if(canal == OLEO_TEMP_A)


		if(canal == TEMP_OLEO)
		{
			ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC1_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena

					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}
			bits = (bits/5);
		}//if(canal == TEMP_OLEO)

		if(canal == COMB_PRESSAO)
		{
			ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC1_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena

					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}
			bits = (bits/5);
		}//if(canal == COMB_PRESSAO)

		if(canal == BAT_VOLTS)
		{
			ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC1_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena

					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}
			bits = (bits/5);
		}//if(canal == BAT_VOLTS)

		if(canal == MAP)
		{
			ADC1_chanells_MeasureChan(1,canal);
			//ADC1_chanells_MeasureChan(1,canal);  // seleciona o canal para fazer a medida em bits
			if(!ERR_OK)
			{
				for(amostras = 0; amostras <= 4; ++amostras)
				{
					ADC1_chanells_GetChanValue16(canal,&Data);  // pega o valor medido e bits e armazena
					Data = Data >> 4;
					bits += Data; // soma o valor de bits a cada medida
				}
			}

			bits = (bits/5);
		}//if(canal == MAP)
	}

	return(bits);
}
/********************************************************************************************************************/
uint16_t tensao(byte t)
{
	uint16_t tensao=0;
	uint16_t valor=0;

	switch(t)
	{
		case 10 :
		{
			valor =  sondaLambda(); // pega os bits do conversor AD
			tensao = ((valor*555)/4096);  // faz a regra de 3
		}break;

		case BAT_VOLTS :
		{
			valor =  tensaoBateria(); // pega os bits do conversor AD
			tensao = ((valor*496)/4096);  // faz a regra de 3
			tensao = (tensao * 211.8)/496;
			if(tensao > 148)
			{
				tensao = tensao -= 4;
			}
		}break;

		case 20 :
		{
			valor =  tensaoCombustivel(); // pega os bits do conversor AD
			tensao = ((valor*555)/4096);  // faz a regra de 3
		}break;

		case PRESSAO_OLEO :
		{
			valor =  tensaoOleo(); // pega os bits do conversor AD
			tensao = ((valor*553)/4096);  // faz a regra de 3


		}break;

		case MAP:
		{
			valor =  tensaoMap(); // pega os bits do conversor AD
			tensao = ((valor*532)/4096);  // faz a regra de 3

		}break;


	}

	return (tensao);
}
/****************************************************************************************************************/
void Tensao_display(uint16_t tensao)
{
	uint16_t quociente,resto,resto_;

	//if(tensao > 375) tensao = 0;

	quociente = (tensao/100);
	resto = (tensao /10)%10;
	resto_ =(tensao%100)%10;

	L(quociente); L('.'); L(resto); L(resto_);
}
/*******************************************************************************************************************/
void SensorRange(void)
{
	bool config=0;
	byte cursor = 2;
	move_character(1,3);
	L('R'); L('A'); L('N'); L('G');  L('E');  L(' '); L('S'); L('E'); L('N'); L('S'); L('O');  L('R');

	move_character(2,5);
	L(2); L(5); L(0);L(' ');L('k'); L('P'); L('a');

	move_character(3,5);
	L(7); L(5); L(0);L(' ');L('k'); L('P'); L('a');
	moveSeta(cursor,14);
	while(!config)
	{
		switch(tecla)
		{
			case DOWN:
			{
				tecla = 0;
				cursor ++;

				if(cursor > 3)cursor = 2;

				moveSeta(cursor,14);
			}break;

			case UP:
			{
				tecla = 0;
				cursor --;

				if(cursor < 2)cursor = 3;

				moveSeta(cursor,14);
			}break;

			case ENTER:
			{
				tecla = 0;

				if(cursor == 2)rangeSensor = 0;
				else rangeSensor = 1;

				 writeflash(flashdataadr,59,rangeSensor);  // salva os dados de calibração

				config = 1;

			}break;

			case MENU:
			{
				tecla = 0;
				config = 1; // só sai fora

			}break;
		}
		//p_cursor = 4;
	}

}
void sensorMap(void)
{
	bool configMap =1;
	byte cursor;
	limpa_disp();

	SensorRange();
	limpa_disp();
	move_character(1,5);
	L('U'); L('N'); L('I'); L('D');  L('A');  L('D'); L('E');

	move_character(2,7);
	L('k'); L('P'); L('a');

	move_character(3,7);
	L('b'); L('a'); L('r');

	move_character(4,7);
	L('p'); L('s'); L('i');

	cursor = engMap;
	moveSeta(cursor,12);
	tecla = 0;

	while(configMap)
	{
		switch(tecla)
		{
			case DOWN:
			{
				tecla = 0;
				cursor ++;

				if(cursor > 4)cursor = 2;

				moveSeta(cursor,12);
			}break;

			case UP:
			{
				tecla = 0;
				cursor --;

				if(cursor < 2)cursor = 4;

				moveSeta(cursor,12);
			}break;

			case ENTER:
			{
				tecla = 0;
				if(cursor == 2){engMap = 2;}  // a unidade é kPa
				if(cursor == 3){engMap = 3;}  // a inidade é bar
				if(cursor == 4){engMap = 4;}  // a unidade é  psi

				 writeflash(flashdataadr,37,engMap);  // salva os dados de calibração

				configMap = 0;

			}break;

			case MENU:
			{
				tecla = 0;
				configMap = 0; // só sai fora

			}break;
		}
		//p_cursor = 4;
	}
}
/*************************************************************************************/
void pressMap(byte unidade)
{
	uint16_t tensao_=0,map = 714;
	byte q,r,qq,rr,qqq;

	 tensao_ = tensao(MAP);

	//map = (tensao_* 700)/470;  // esta em kpa
	map = unityMap(tensao_,rangeSensor); // esta em kpa

	if(!chupa)
	{

	switch(unidade)
	{
		case 2:
		{
			qqq= (map/1000);
			r= (map/100)%10;
			qq= (map%100)/10;
			rr= (map%100)%10;
			move_character(1, 5);
			L(' '); L(r);L(qq);L(rr);

		}break;

		case 3:  // bar
		{
			//map = map/10;
			//map = map*10;

			if(map < 9)
			{
				r= (map/10);
				qq= (map%10);
				move_character(1, 5);
				L(0);L(',');L(r);L(qq);
			}

			if((map >=10)&&(map <=99))
			{
				r= (map/10);
				qq= (map%10);
				move_character(1, 5);
				L(0);L(',');L(r);L(qq);
			}

			if((map >=100)&&(map <=999))
			{
				rr= (map/100);
				r= (map%100)/10;
				qq= ((map%100)%10);

				move_character(1, 5);
				L(rr);L(',');L(r);L(qq);
			}

		}break;
		case 4:  // bar
		{
			//map = map/10;
			//map = map*0.14504;
			map = map*1.4504;

			if(map < 9)
			{
				r= (map/10);
				qq= (map%10);
				move_character(1, 5);
				L(' ');	L(r);L(',');L(qq);
			}

			if((map >=10)&&(map <=99))
			{
				r= (map/10);
				qq= (map%10);
				move_character(1, 5);
				L(' ');L(r);L(',');L(qq);
			}

			if((map >=100)&&(map <=999))
			{
				rr= (map/100);
				r= (map%100)/10;
				qq= ((map%100)%10);

				move_character(1, 5);
				L(' ');L(rr);L(r);L(',');L(qq);
			}
			if((map >=1000)&&(map <=9999))
			{
				qqq= (map/1000);
				rr= (map/100)%10;
				r= (map%100)/10;
				qq= ((map%100)%10);

				move_character(1, 5);
				L(qqq);L(rr);L(r);L(',');L(qq);
			}

		}break;
	}
	}

}

