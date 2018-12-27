/*
 * auxiliar.c

 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#include "main.h"
#include "display.h"
#include "auxiliar.h"
#include "analogicas.h"
#include "aux_telas.h"
#include "dadosFlash.h"
#include "velocimetro.h"
#include  "nivel_tanque.h"
#include "Bluethoot.h"


extern byte  p_cursor;

/***************************************************************************************/
byte teclado(void)
{
	uint16_t chave;
	bool habButon = 0;
	WDog1_Clear();


	if(!MENU0_GetVal())
	{
		ContBotao = 0;

		Teclado_Disable();
		habButon = 1;

		while((!MENU0_GetVal()) && (ContBotao < 100))
		{
			tecla = MENU;
			 WDog1_Clear();
		}
	}

	if(!UP_GetVal())
	{
		ContBotao = 0;
		Teclado_Disable();
		habButon = 1;

		while((!UP_GetVal()) && (ContBotao < 100))
		{
			tecla = UP;
			 WDog1_Clear();
		}
	}

	if(!DOWN_GetVal())
	{
		ContBotao = 0;
		Teclado_Disable();
		habButon = 1;

		while((!DOWN_GetVal()) && (ContBotao < 100))
		{
			tecla = DOWN;
			 WDog1_Clear();
		}
	}

	if(!ENTER_GetVal())
	{
		ContBotao = 0;
		Teclado_Disable();
		habButon = 1;

		while((!ENTER_GetVal()) && (ContBotao < 100))
		{
			tecla = ENTER;
			 WDog1_Clear();
		}
	}

	//while(!MENU0_GetVal()||!UP_GetVal()||!ENTER_GetVal()||!DOWN_GetVal() &&(ContBotao < 99)){ WDog1_Clear();}


 	chave = analogicasmed(ADC1,CHAVE_POS);
	if(chave <350)
	{
		WDog1_Clear();

	}

	else
	{
		contDesliga = 30000;
	}

	if(habButon == 1) Teclado_Enable();

	return tecla;


}
/***************************************************************************************/
uint16_t temp_agua(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC0,TEMP_AGUA);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t sens_temp_a(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC1,TEMP_OLEO_A);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t sens_temp_b(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC0,TEMP_OLEO_B);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t temp_oleo(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC1,TEMP_OLEO);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t pressao_oleo(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC0,PRESSAO_OLEO);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t pressao_comb(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC1,COMB_PRESSAO);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t sondaLambda(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC0,SONDA_LAMBDA);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t nivelTanque(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC0,NIVEL_TANQUE);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t tensaoBateria(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC1,BAT_VOLTS);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t tensaoCombustivel(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC1,COMB_PRESSAO);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t tensaoOleo(void)
{
	uint16_t analog_bits = 0;

	analog_bits = analogicasmed(ADC0,PRESSAO_OLEO);

	return(analog_bits);
}
/***************************************************************************************/
uint16_t tensaoMap(void)
{
	int i;
	uint32_t bits=0;
	uint16_t analog_bits = 0;
for(i = 0; i<= 100;i++){
	analog_bits = analogicasmed(ADC1,MAP);

	bits = bits + analog_bits;
}
		analog_bits= bits/101;

	return(analog_bits);
}
/***************************************************************************************/
float conversoes_temp(uint16_t temp)
{
	float temperature = 0;

	int aux,aux1,aux2,i,aux_temp;

	if(temp >= medida_ana[0]) temperature = 0;

	for(i = 0 ; i <= 16; i++)
	{
		WDog1_Clear();
		// Nessa parte do programa compara- se a medida atual e faz o calculo de quantos lumens esta medindo

		if((temp >= medida_ana[i]) && (temp <= medida_ana[i-1]))
		{
			aux = (temp - medida_ana[i]) * (temperatura[i-1] - temperatura[i]);

			aux1 = medida_ana[i-1] - medida_ana[i];

			aux2 = aux / aux1;

			temperature = temperatura[i] + aux2;

			i = 30;
		}
	}

		// Nessa perte do programa faz o claculo se o aparelho fazer uma medida maior que o valor que est� armazenada na mem�ria

		if(temp < medida_ana[16])
		{
			temperature = (( medida_ana[16] - temp ) * (temperatura[16] - temperatura[15]));

			aux_temp = medida_ana[16] - medida_ana[15];

			temperature = (temperature / aux_temp) + temperatura[16];

			i = 30;
		}
	return(temperature);
}
/***************************************************************************************/
byte convert_press(uint16_t press)
{

	byte i ;
	float aux, aux1, aux2;
	float bar = 0.0,aux_bar = 0.0;

	if(press <= medida_ana_press[0]) bar = 0.0;

	for(i = 1 ; i <= 10; i++)
	{
		WDog1_Clear();
		// Nessa parte do programa compara- se a medida atual e faz o calculo de quantos lumens esta medindo

		if((press <= medida_ana_press[i]) && (press >= medida_ana_press[i-1]))
		{
			aux = (press - medida_ana_press[i-1]) * (pressao[i] - pressao[i-1]);

			aux1 = medida_ana_press[i] - medida_ana_press[i-1];

			aux2 = aux/aux1;

			bar = pressao[i-1] + aux2;

			i = 30;
		}

		// Nessa perte do programa faz o claculo se o aparelho fazer uma medida maior que o valor que está armazenada na memória

		if(press > medida_ana_press[10])
		{
			bar = ((press - medida_ana_press[10]) * (pressao[10] - pressao[9]));

			aux_bar = medida_ana_press[10] - medida_ana_press[9];

			bar = (bar/aux_bar) + pressao[10];

			i = 30;
		}
	}

	return(bar);

}
/********************************************************************************************************/
void SensorTempAgua(void) //configura as unidades de engenharia a ser mostradas em display : obs prescisa mudar o nome da função
{
	linha(3);
	 L(' '); L(' '); L('F'); L('A'); L('H'); L('R');  L('E');  L('N'); L('H'); L('E'); L('I');L('T');

	linha(4);
	 move_character(4,5);// LEVA O CURSOR
	 L('C'); L('E'); L('L'); L('S');  L('I');  L('U'); L('S');

	 show_cursor(1);
	 if(contConFig==1)
	 {
		 if(engAgua)  p_cursor = 4;
		 else   p_cursor = 3;
	 }

	 if(contConFig==2)
	 {
		 if(engOleo)  p_cursor = 4;
		 else   p_cursor = 3;
	 }

	 if(contConFig==3)
	 {
		 if(engOleoA)  p_cursor = 4;
		 else   p_cursor = 3;
	 }

	 if(contConFig==4)
	 {
		 if(engOleoB)  p_cursor = 4;
		 else   p_cursor = 3;
	 }

	 move_character(p_cursor,13);
	while(contConFig == contConFig_)  // cont config =1 equivale a configuração da marcaçã da unidade de engenharia da agua, = 2 do óleo, = 3 da temp oleo a, e 4 temp oleo b
	{
		if(tecla)
		{
			switch(tecla)
			{
				case DOWN :
				{
					p_cursor ++; tecla = 0;
					if(p_cursor > 4) p_cursor =3;
					move_character(p_cursor,13);
				}break;

				case UP :
				{
					p_cursor--; tecla =0;

					if(p_cursor < 3) p_cursor =4;
					move_character(p_cursor,13);
					move_character(p_cursor,13);
				}break;

				case MENU :
				{
					contConFig = 5;
					 tecla =0;
					 show_cursor(0);

				}break;


				case ENTER :
				{
					if(p_cursor == 3)
					{
						 show_cursor(0);
						 clear_line(4);
						 linha(3);
						   L(' '); L(' '); L('F'); L('A'); L('H'); L('R');  L('E');  L('N'); L('H'); L('E'); L('I');L('T');

						   if(contConFig == 1){engAgua = 0; writeflash(flashdataadr,19,engAgua);limit.agua = 0; pergunta();}//definirAlarmes();}
						   if(contConFig == 2){engOleo = 0; writeflash(flashdataadr,20,engOleo);limit.oleo = 0; pergunta();}//definirAlarmes();}
						   if(contConFig == 3){engOleoA = 0;   writeflash(flashdataadr,21,engOleoA);limit.tempa = 0;pergunta();}// textIput('A');definirAlarmes();}  // salva os dados de calibração}
						   if(contConFig == 4){engOleoB = 0; writeflash(flashdataadr,22,engOleoB);limit.tempb = 0;pergunta();} //textIput('B');definirAlarmes();}

						 tecla = 0;
						 delay(500);



						 contConFig ++;
					}

					if(p_cursor == 4)
					{
						 show_cursor(0);
						 clear_line(3);
						 clear_line(4);
						 linha(3);
						 L(' '); L(' '); L(' '); L(' '); L('C'); L('E'); L('L'); L('S');  L('I');  L('U'); L('S');

						   if(contConFig == 1){engAgua = 1;   writeflash(flashdataadr,19,engAgua);pergunta();}//definirAlarmes();}  // salva os dados de calibração}
						   if(contConFig == 2){engOleo = 1; writeflash(flashdataadr,20,engOleo);pergunta();}//definirAlarmes();}
						   if(contConFig == 3){engOleoA = 1;   writeflash(flashdataadr,21,engOleoA);pergunta();}// textIput('A');definirAlarmes();}  // salva os dados de calibração}
						   if(contConFig == 4){engOleoB = 1; writeflash(flashdataadr,22,engOleoB); pergunta();}//textIput('B');definirAlarmes();}


						 contConFig ++;
						 tecla = 0;
						 delay(500);
					}
				}break;
			}

		}
		 WDog1_Clear();
	}
	contConFig_ = contConFig;
	// show_cursor(0);
}

/*******************************************************************************************************************************/
void  adjustLamb(byte lamb)
{
	bool config=1,etapa= 1;
	uint16_t lambda,lambda_ant,aux_lamb=0;
	byte i, conf =0,p_cursor_;

	linha(2);
	L(' ');	L('S'); L('E'); L('L'); L('.'); L('T'); L('E'); L('N'); L('S'); L('A');  L('O');  L(' '); L('M'); L('A');L('X');
	linha(3);
	L(' '); L(' ');L('T'); L('E'); L('N'); L('S'); L('A');  L('O');

	 move_character(3,10);// LEVA O CURSOR

	Tensao_display(tensaoLambdaMax);  // mostra o valor da  tensão média


		while(config)
		{
			 move_character(3,10);// LEVA O CURSOR
			lambda = tensao(10);// o mesmo que a sonda lâmbda

			if(lambda != lambda_ant) // se a medida não mudou
			{
				Tensao_display(lambda);  // mostra a tensão no display
				lambda_ant = lambda;
			}

			if(tecla == ENTER)  // ao pressionar a tecla enter
			{
				tecla = 0;
				clear_line(3);  // LIMPA ALINHA SELECIONADA
				linha(3);

				 move_character(3,4);// LEVA O CURSOR
				L('A'); L('G'); L('U'); L('A'); L('R'); L('D'); L('E'); L('.'); L('.');  L('.');
				for(i = 1; i <= 10; ++i) // faz a media da tensão
				{
					lambda = tensao(10);// o mesmo que a sonda lâmbda

					aux_lamb = aux_lamb += lambda;

					delay(500);
				}

				tensaoLambdaMax = (aux_lamb/10);// faz a media da tensão max.

				clear_line(3);  // LIMPA ALINHA SELECIONADA

				 move_character(3,3);// LEVA O CURSOR

				 L('T'); L('E'); L('N'); L('S'); L('A');  L('O');

				 move_character(3,10);// LEVA O CURSOR

				Tensao_display(tensaoLambdaMax);  // mostra o valor da  tensão média


				 p_cursor = 4;

				 clear_line(4);  // LIMPA ALINHA SELECIONADA

				 L('C'); L('O'); L('N'); L('F'); L('I');  L('R');  L('M');  L('A');  L('?');  L(' ');  L('S');  L(' '); L('N');
				 move_character(4,12);
				 show_cursor(1);// FAZ O CURSOR PISCAR
				 p_cursor_ = 12;
				while(!conf) // pede a comfirmação da tensao selecionada
				{
					if(tecla)  // se há tecla pressionada/;
					{
						switch(tecla)  // procura a tecla
						{
							case DOWN :  // se for a tecla
							{
								p_cursor_ += 2; tecla = 0;     // Rola o cursor para i osim o não
								if(p_cursor_ > 14) p_cursor_ =12;
								move_character(4,p_cursor_);
							}break;

							case UP :
							{
								p_cursor_ -= 2; tecla =0;

								if(p_cursor_ < 12) p_cursor_ =14;
								move_character(4,p_cursor_);
							}break;

							case ENTER :
							{
								tecla = 0;
								if(p_cursor_ ==12)
								{
									//salva o valor da tensão maxima na memória

									 writeflash(flashdataadr,16,tensaoLambdaMax);  // salva os dados de calibração
									 show_cursor(0);
									ConfLamb(); // seleciona o range ao valor equivalente a tensão para a lambida
									conf =1;
									config =0;
									tela= 4;

								}
								else
								{
									//salva porra nenhuma

									conf =1;   // não salva nada  e volta para a tela de menu
									config =0;
									tela= 4;
								}
								 show_cursor(0);

							}break;

							case MENU :   // volta direto para o menu
							{
								tela= 4;
								 tecla =0;
								 conf = 10;
								 config =0;
								 show_cursor(0);
							}break;
						}
					}//tecla
				} //!conf
			}
			WDog1_Clear();
		}
}
/************************************************************************************************/
void ConfLamb(void)
{
	byte p_cursor_ = 12,aux_lamb,r_lamb;

	uint16_t volts=tensaoLambdaMin;

	byte lambda = 0,etapa =1;
	clear_line(2);  // LIMPA ALINHA SELECIONADA
	clear_line(3);  // LIMPA ALINHA SELECIONADA
	clear_line(4);  // LIMPA ALINHA SELECIONADA

	linha(2);
	 L(' '); L(' '); L('S'); L('E'); L('L'); L(' '); L('O');  L(' ');  L('R');  L('A');  L('N');  L('G');  L('E');

	 move_character(3,1);
	 L('V'); L('O'); L('L'); L('T');   L(' ');  L('M');  L('I');  L('N');  L(' ');

	 move_character(3,10);

	  Tensao_display(tensaoLambdaMin); L('V'); move_character(3,16);  L('<');

	 linha(4);
	 L('E'); L('Q'); L('U'); L('I'); L('V');  L('A');  L('L');  L('E');  L(' ');

	 aux_lamb = unityLambMin/10;
	 r_lamb = unityLambMin%10;
	 lambda=unityLambMin;
	 move_character(4,10);
	 L(aux_lamb);  L(r_lamb);  L(' ');   L('A');   L('F');   L('R');
	 while(etapa <= 4)
	 {
		 WDog1_Clear();
		 if(tecla)
		 {
			 switch(tecla)
			 {
			 case UP : // INCREMENTA  o fator lambida
			 {
				 if((etapa == 2) ||(etapa == 4))
				 {
					 lambda += 1; tecla = 0;
					 if(lambda > 30) lambda =30;

					 aux_lamb = lambda/10;
					 r_lamb = lambda%10;

					 move_character(4,10);
					 L(aux_lamb);  L(r_lamb);
				 }
				 else
				 {
					 volts +=10; tecla = 0;

					 move_character(3,10);

					  Tensao_display(volts);
				 }

			 }break;

			 case DOWN :  // decrementa o fator lambda
			 {
				 if((etapa == 2) ||(etapa == 4))
				 {
					 lambda -= 1; tecla = 0;
					 if(lambda > 100) lambda = 0;

					 aux_lamb = lambda/10;
					 r_lamb = lambda%10;

					 move_character(4,10);
					 L(aux_lamb);  L(r_lamb);
				 }

				 else
				 {
					 volts -=10; tecla = 0;
					 if(volts > 4000) volts = 0;

					 move_character(3,10);

					  Tensao_display(volts);
				 }

			 }break;

			 case ENTER : // aceita a medição e vai configurar o maximo
			 {
				 tecla = 0;


				if(etapa == 2)
				{
					unityLambMin = lambda;
					 writeflash(flashdataadr,17,unityLambMin);  // salva os dados de calibração

					 tensaoLambdaMin = volts;
					 writeflash(flashdataadr,23,tensaoLambdaMin);  // salva os dados de calibração
					 clear_line(3);   clear_line(4);
					 move_character(3,1);
					 L('V'); L('O'); L('L'); L('T');   L(' ');  L('M');  L('A');  L('X');  L(' ');

					 move_character(3,10);

					  Tensao_display(tensaoLambdaMax); L('V');
					  volts = tensaoLambdaMax;

					 linha(4);
					 L('E'); L('Q'); L('U'); L('I'); L('V');  L('A');  L('L');  L('E');  L(' ');
					 aux_lamb = unityLambMin/10;
					 r_lamb = unityLambMin%10;
					 lambda=unityLambMin;
					 move_character(4,10);
					 L(aux_lamb);  L(r_lamb);    L(' ');   L('A');   L('F');   L('R');

				}

				if(etapa == 4)
				{
					unityLambMax = lambda;
					 writeflash(flashdataadr,18,unityLambMax);  // salva os dados de calibração

					 tensaoLambdaMax = volts;
					 writeflash(flashdataadr,16,tensaoLambdaMax);  // salva os dados de calibração

					 tela = 4;

				}
				etapa ++;
				if((etapa ==2)||(etapa == 4))
				{
					move_character(3,16); L(' ');
					move_character(4,16); L('<');
				}

				if(etapa ==3)
				{
					move_character(3,16); L('<');
					move_character(4,16); L(' ');
				}


			 }break;

			 case MENU : // volta para o menu direto
			 {
				 tela= 4;
				 tecla =0;
				 etapa = 10;
				 show_cursor(0);
			 }break;
			 }
		 }//tecla
	 }
}
/*****************************************************************************************************/
//byte aux_temp =1;

void tempAgua(bool mode)
{
	uint16_t temp =0;
	byte r,q,rr,qqq,qq;
	temp = conversoes_temp(temp_agua());
	 aguaTemp = temp;
	if(mode == 0)
	{
		temp = temp*18;
		temp += 320;
	}
if(tela == 100)
{

	switch(mode)
	{
	case 0:  // É farenheit
	{
	//if(!engOleoB) {
		//temp = temp*18;
		//temp += 320;
	//}

			if(temp <= 999)
			{
				if(!almAgua)
				{
					r= (temp/100)%10;
					qq= (temp%100)/10;
					rr= (temp%100)%10;
					move_character(3, 10);
					L(' '); L(r);L(qq);L('.');L(rr);
				}
			}


		else
		{
			if(!almAgua)
			{
				qqq= (temp/1000);
				r= (temp/100)%10;
				qq= (temp%100)/10;
				rr= (temp%100)%10;
				move_character(3, 10);
				L(qqq); L(r);L(qq);L('.');L(rr);
			}
		}
	}break;

	case 1:
	{

			if(temp > 99)
			{
				if(!almAgua)
				{
					r= (temp/100)%10;
					q= (temp%100)/10;
					rr= (temp%100)%10;
					move_character(3,12);
					L(r); L(q);  L(rr);
				}
			}

		else
		{
			if(!almAgua)
			{
				q= (temp%100)/10;
				rr= (temp%100)%10;
				move_character(3,12);
				L(' '); L(q);  L(rr);
			}
		}
	}break;
	}
}


	//alarmes_(AGUA,temp);



		///aux_temp = temp;
	//}
}
/*****************************************************************************************************/
void press_com(void)
{
	byte press=0;
	byte r,q,rr;

	press = convert_press(pressao_comb());

	//if(aux_temp!= temp)
	{
		if(press > 99)
		{
			r= (press/100)%10;
			q= (press%100)/10;
			rr= (press%100)%10;
			move_character(2,12);
			L(r); L(q);  L(rr);
		}
		else
		{
			q= (press%100)/10;
			rr= (press%100)%10;
			move_character(2,12);
			L(' '); L(q);  L(rr);
		}

		//aux_temp = temp;
	}
}
/************************************************************************************************************/
void lambda(bool unity)  // verifica qual é a unidade de engenharia a ser mostrada no display
{
	uint16_t voltsLambda=0;
	byte lambada = 0,quociente,resto,resto_;

	voltsLambda = tensao(10);// o mesmo que a sonda lâmbda
if(!almAgua)
{
	if(!unity) // se a configuração for NARROW mostra apenas a voltagem e o sinal no display
	{
			move_character(3,5);
		  Tensao_display(voltsLambda);
	}
	else
	{
		if(voltsLambda >= tensaoLambdaMin)
		{
			lambada = (voltsLambda*(unityLambMax*10))/tensaoLambdaMax;  // multiplica por 10 para mostrar no display
			if(lambada <= 99)
			{
				resto = (lambada /10);
				resto_ =(lambada%10);
				move_character(3,5);  // falta definir onde vão essas paradas
				 L(' ');  L(resto);  L('.');  L(resto_);
			}
			else
			{
				quociente = (lambada/100);
				resto = (lambada /10)%10;
				resto_ =(lambada%100)%10;

				move_character(3,5);  // falta definir onde vão essas paradas
				 L(quociente);  L(resto);  L('.');  L(resto_);
			}
		}

		if(voltsLambda > tensaoLambdaMax)  // se a medida for maior quer o set mostra o valor máximo
		{
			lambada = unityLambMax*10;

			quociente = (lambada/100);
			resto = (lambada /10)%10;
			resto_ =(lambada%100)%10;

			move_character(3,5);  // falta definir onde vão essas paradas
			 L(quociente);  L(resto);  L('.');  L(resto_);

		}

		if(voltsLambda < tensaoLambdaMin) // se a medida for menor quer o set mostra o valor mínimo
		{
			resto = (lambada /10);
			resto_ =(lambada%10);
			move_character(3,5);  // falta definir onde vão essas paradas
			 L(' ');  L(resto);  L('.');  L(resto_);

		}
	}// else
}
}
/**********************************************************************************/
void bateria(void)
{

	byte quociente,resto,resto_;

	bateria_ = tensao(BAT_VOLTS);



	quociente = (bateria_/100);
	resto = (bateria_ /10)%10;
	resto_ =(bateria_%100)%10;

	if(tela == 101)
	{
		move_character(3,9);  // falta definir onde vão essas paradas
		L(quociente);  L(resto);  L('.');  L(resto_);  L('V');

		//Bluethoot_SendChar('B');Bluethoot_SendChar('A');Bluethoot_SendChar('T');Bluethoot_SendChar('-');

		convertNumerBlu(quociente);

		convertNumerBlu(resto);convertNumerBlu(',');convertNumerBlu(resto_);
	}
}
/**************************************************************************/
void pergunta(void)
{
	byte pergunta=1;
	byte cursor = 10;

	clear_line(3);clear_line(4); //limpa as linhas 3 e 4 para definir alarmes
	move_character(3,1);  // move o cursor para a teceira linha e escreve:
	 L('D'); L('E'); L('F'); L('I');  L('N');  L('I'); L('R'); L(' '); L('A');L('L'); L('A'); L('R'); L('M'); L('E');
	 move_character(4,1);
	 L('M'); L('A'); L('X'); L('I');  L('M');  L('O'); L('?');  L(' ');  L(' '); L('S');  L(' '); L('N');

	 move_character(4,cursor);
	 show_cursor(1);
	 tecla = 0;
	 while(pergunta)
	 {
		 WDog1_Clear();
		 switch(tecla)
		 {
		 case UP:
		 {
			 cursor+= 2;
			 if(cursor>12)cursor=10;
			 move_character(4,cursor);

			 tecla = 0;
		 }break;

		 case DOWN:
		 {
			 cursor -= 2;
			 if(cursor<10)cursor=12;
			 move_character(4,cursor);

			 tecla = 0;
		 }break;

		 case ENTER:
		 {
			 tecla = 0;
			 if(cursor == 10){
				 if(contConFig == 3){ clear_line(4); show_cursor(0);textIput('A');}
				 if(contConFig == 4) {clear_line(4); show_cursor(0);textIput('B');}

				 definirAlarmes();
				 pergunta = 0;
			 }

			 else
			 {
				 pergunta = 0;
				 readflash();
				 if(!engAgua){maxTempAgua = maxTempAgua *18; maxTempAgua += 320;}
				 if(!engOleo){ maxTempOleo = maxTempOleo *18; maxTempOleo += 320;}
				 if(!engOleoA){ maxTempA = maxTempA *18; maxTempA += 320;}
				 if(!engOleoB){ maxTempB = maxTempB *18; maxTempB += 320;}
			 }


		 }break;

		 }
	 }
	 show_cursor(0);
	 clear_line(3); clear_line(4);

}
/*********************************************************************/
void definirAlarmes(void)  // escreve com quantos graus deve deve apresentar o alarme de temperatura alta
{
	byte rr,r,q;
	byte temperature=90;
	bool config=1;

	clear_line(3);clear_line(4); //limpa as linhas 3 e 4 para definir alarmes
	move_character(3,1);  // move o cursor para a teceira linha e escreve:
	 L('D'); L('E'); L('F'); L('I');  L('N');  L('I'); L('R'); L(' '); L('A');L('L'); L('A'); L('R'); L('M'); L('E');
	 move_character(4,1);
	 L('M'); L('A'); L('X'); L('I');  L('M');  L('O');
	 move_character(4,11);  L('°');  L('C');
	 tecla = 0;
	 show_cursor(0);
	 aux_temper(temperature);
	 while(config<=2)
	 {
		 WDog1_Clear();
		 switch(tecla)
		 {
		 case UP:
		 {
			 temperature ++;
			 aux_temper(temperature);
			 tecla = 0;
		 }break;

		 case DOWN:
		 {
			 temperature --;
			 aux_temper(temperature);
			 tecla = 0;
		 }break;

		 case ENTER:
		 {
			tecla = 0;
			if(contConFig == 1)
			{   // salva o valor para alarme na temperatura do  óleo
				if(config ==1)
				{
					maxTempAgua= temperature;
					writeflash(flashdataadr,34,maxTempAgua);
					if(engAgua==0){maxTempAgua = maxTempAgua *18; maxTempAgua += 320;}
					limit.agua = 0;
				}

				else
				{
					minTempAgua= temperature;
					writeflash(flashdataadr,38,minTempAgua);
					if(engAgua==0){minTempAgua = minTempAgua *18; minTempAgua += 320;}
				}
			}
			if(contConFig == 2)
			{ // salva o valor para alarme na temperatura da agua
				if(config ==1)
				{
					maxTempOleo = temperature;
					writeflash(flashdataadr,33,maxTempOleo);
					if(engOleo==0){ maxTempOleo = maxTempOleo *18; maxTempOleo += 320;}
					limit.oleo = 0;
				}
				else
				{
					minTempOleo = temperature;
					writeflash(flashdataadr,39,minTempOleo);
					if(engOleo==0){ minTempOleo = minTempOleo *18; minTempOleo += 320;}
				}
			}

			if(contConFig == 3)
			{  // // salva o valor para alarme na temperatura AA
				if(config ==1)
				{
					maxTempA = temperature;
					writeflash(flashdataadr,40,maxTempA);
					if(engOleoA==0){ maxTempA = maxTempA *18; maxTempA += 320;}
					limit.tempa = 0;
				}

				else
				{
					minTempA = temperature;
					writeflash(flashdataadr,41,minTempA);
					if(engOleoA==0){ minTempA = minTempA *18; minTempA += 320;}
				}
			}

			if(contConFig == 4)
			{ // salva o valor para alarme na temperatura BB
				if(config ==1)
				{
					maxTempB = temperature;
					writeflash(flashdataadr,36,maxTempB);
					if(engOleoB==0){ maxTempB = maxTempB *18; maxTempB += 320;}
					limit.tempb = 0;
				}

				else
				{
					minTempB = temperature;
					writeflash(flashdataadr,36,minTempB);
					if(engOleoB==0){ minTempB = minTempB *18; minTempB += 320;}
				}
			}

			config++;
			 move_character(4,1);
			 L('M'); L('I'); L('N'); L('I');  L('M');  L('O');

		 }break;

		 case MENU:
		 {
			 tecla = 0;
			 config = 0;
		 }break;


		 }
	 }

	 clear_line(3); clear_line(4);
}


/*******************************************************************************************/
void aux_temper(byte temper)  //apenas tem a função de mostrar valores no display
{
	byte rr,r,q;

	if(temper<=99)
	{
		r=temper/10;
		q=temper%10;
		move_character(4,8);
		  L(' ');  L(r);  L(q);
	}
	else
	{
		rr=(temper/100);
		r=(temper/10)%10;
		q=(temper%100)%10;
		move_character(4,8);
		 L(rr);  L(r);  L(q);

	}
}
/*******************************************************************************************/
void alarmes_(byte sensor,uint16_t temp)
{

	switch(sensor)
	{
		case AGUA:
		{

			if((temp > maxTempAgua)||(histerezeAgua==0))  // faz com que só saia do alarme se a temeperatura baixar 3 graus do limite máximmo
			{
				almAgua =1;
				if(temp > (maxTempAgua-3))
				{
					histerezeAgua = 0;
				}
				else
				{
					histerezeAgua = 1;
				}

				if(cont_piScAgua <=0)
				{
					cont_piScAgua = 600;

					if(piscAgua== 1)
					{
						clear_line(3);
						move_character(3,1);
						L('T'); L('e'); L('m'); L('p'); L(' '); L('A'); L('g'); L('u'); L('a'); L(':');auxAlarmeOleo(engAgua, temp,1);
						move_character(3,15);  L('°'); if(engAgua ==1) L('C'); else {L('F');}

						agua = 1;
						piscAgua = 0;
					}

					else
					{
						move_character(3,1);
						clear_line(3);
						//L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' ');
						agua = 1;
						piscAgua = 1;
					}

				}
			}

				else
				{
					if(tela == 100)
					{
						if(agua == 1)
						{
							move_character(3,1);
							L('T'); L('e'); L('m'); L('p'); L(' '); L('A'); L('g'); L('u'); L('a'); L(':');auxAlarmeOleo(engAgua, temp,1);
							move_character(3,15);  L('°'); if(engAgua ==1) L('C'); else {L('F');}
							agua = 0;
							almAgua =0;
						//alarme.almAgua=0;
						}
					}

					if(almAgua == 1)
					{
						switch(tela)
						{
							case 99:
							{
								clear_line(3);
								 move_character(3,1);
								L('P'); L('.'); L('O'); L('l'); L('e'); L('o');
								move_character(3,12); L('b'); L('a'); L('r');

								almAgua=0;

							}break;

							case 101:
							{
								clear_line(3);
								 move_character(3,1);
								 if(!lamb){ move_character(3,10);  L('?');} else{ move_character(3,10);  L('A'); L('F'); L('R');}

								almAgua=0;

							}break;

						}
					}
				}
			}break;

		case OLEO:
		{
			if((temp > maxTempOleo)||(histerezeOleo==0))  // faz com que só saia do alarme se a temeperatura baixar 3 graus do limite máximmo
			{
				chupa = 1;
				if(temp > (maxTempOleo-3))
				{
					histerezeOleo = 0;
				}
				else
				{
					histerezeOleo = 1;
				}

				if(cont_piScOleo <=0)
				{
					cont_piScOleo = 600;

					if(piscOleo== 1)
					{
						clear_line(1);
						move_character(1,1);
						L('T'); L('e'); L('m'); L('p'); L(' '); L('O'); L('l'); L('e'); L('o'); L(' '); auxAlarmeOleo(engOleo, temp,2);
						move_character(1,15);  L('°'); if(engOleo ==1) L('C'); else {L('F');}
						oleo = 1;
						piscOleo = 0;
					}

					else
					{
						move_character(1,1);
						clear_line(1);
						//L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' ');
						oleo = 1;
						piscOleo = 1;
					}

				}
			}

				else
				{
					if(tela == 99)
					{
						if(oleo == 1)
						{
							clear_line(1);
							move_character(1,1);
							L('T'); L('e'); L('m'); L('p'); L(' '); L('O'); L('l'); L('e'); L('o'); L(':'); auxAlarmeOleo(engOleo, temp,2);

							move_character(1,15);  L('°'); if(engOleo ==1) L('C'); else {L('F');}
							oleo = 0;
							chupa = 0;
						//alarme.almAgua=0;
						}
					}


				if(chupa == 1)
				{
					switch(tela)
					{
						case 100:
						{
							clear_line(1);
							move_character(1,4);
							 L('k'); L('m'); L('/'); L('h');
							 move_character(1,14);
								 L('r'); L('p');  L('m');
							 chupa = 0;

						}break;

						case 101:
						{
							clear_line(1);

							 L('M'); L('A'); L('P'); L(' ');  if(engMap == 2) {move_character(1,10);L('k'); L('P'); L('a'); }

							 if(engMap == 3) {move_character(1,11);L('b'); L('a'); L('r'); }

							 if(engMap == 4) {move_character(1,11);L('p'); L('s'); L('i'); }

							 chupa = 0;

						}break;

					}
				}
				}
		}break;

		case TEMPA:
		{
			if((temp > maxTempA)||(histerezeA==0))  // faz com que só saia do alarme se a temeperatura baixar 3 graus do limite máximmo
			{
				almTempA =1;

				if(temp > (maxTempA-3))
				{
					histerezeA = 0;
				}
				else
				{
					histerezeA = 1;
				}

				if(cont_piScA <=0)
				{
					cont_piScA = 600;

					if(piscA== 1)
					{
						clear_line(4);
						move_character(4,1);
						L('T'); L('e'); L('m'); L('p'); L(' '); L(a); L(b); L(c); L(d); L(':');  auxAlarmeOleo(engOleoA, temp,3);
						move_character(4,14);  L('°'); if(engOleoA ==1) L('C'); else {L('F');}
						tempA = 1;
						piscA = 0;
					}

					else
					{
						clear_line(4);
						//L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' ');
						tempA = 1;
						piscA = 1;
					}

				}
			}

				else
				{
					if(tela == 99)
					{
						if(tempA == 1)
						{
							 move_character(4,1);
							L('T'); L('e'); L('m'); L('p'); L(' '); L(a); L(b); L(c); L(d); L(':');  auxAlarmeOleo(engOleoA, temp,3);
							move_character(4,14);  L('°'); if(engOleoA ==1) L('C'); else {L('F');}
							tempA = 0;
							almTempA =0;
						//alarme.almAgua=0;
						}
					}

					if(almTempA == 1)
					{
						switch(tela)
						{
							case 100:
							{
								clear_line(4);
								 move_character(4,1);
								 L('N'); L('i');L('v'); L('e');L('l'); L(':');

								 move_character(4,10);
								 L('%');
								 almTempA =0;
								 getRtc();


							}break;

							case 101:
							{
								clear_line(4);
								 move_character(4,1);
								 L('B'); L('A'); L('T'); L('E'); L('R'); L('I'); L('A'); L(' ');
								 almTempA =0;

							}break;

						}
					}
				}
		}break;

		case TEMPB:
		{
			if((temp > maxTempB)||(histerezeB==0))  // faz com que só saia do alarme se a temeperatura baixar 3 graus do limite máximmo
			{
				almTempB =1;
				if(temp > (maxTempB-3))
				{
					histerezeB = 0;
				}
				else
				{
					histerezeB = 1;
				}

				if(cont_piScB <=0)
				{
					cont_piScB = 600;

					if(piscB== 1)
					{
						move_character(2,1);
						L('T'); L('e'); L('m'); L('p'); L(' ');  L(e); L(f); L(g); L(h); L(':');auxAlarmeOleo(engOleoB, temp,4);
						move_character(2,15);  L('°'); if(engOleoB ==1) L('C'); else {L('F');}
						tempB = 1;
						piscB = 0;
					}

					else
					{
						clear_line(2);
						//L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' '); L(' ');
						tempB = 1;
						piscB = 1;
					}

				}
			}

				else
				{
					if(tela == 101)
					{
						if(tempB == 1)
						{
							move_character(2,1);
							L('T'); L('e'); L('m'); L('p'); L(' ');  L(e); L(f); L(g); L(h); L(':');  auxAlarmeOleo(engOleoB, temp,4);
							move_character(2,15);  L('°'); if(engOleoB ==1) L('C'); else {L('F');}
							piscB = 0;
							tempB = 0;
							almTempB =0;
						//alarme.almAgua=0;
						}
					}

					else
					{
						if(almTempB == 1)
						{
							switch(tela)
							{
								case 99:
								{
									clear_line(2);
								//	move_character(4,1);
									move_character(2,1);
									L('P'); L('.'); L('C'); L('o'); L('m'); L('b');
									move_character(2,12); L('b'); L('a'); L('r');

									almTempB =0;
								}break;

								case 100:
								{
									clear_line(2);
									showOdometro(); move_character(2,13);

									L('.');L(odometroMetro);

									move_character(2,15);
									L('k'); L('m');

									move_character(2,7);
									L('k'); L('m');

									almTempB =0;
									getRtc();
								}break;
							}
						}
					}
				}
		}break;


	}
}
/*****************************************************************************/
uint16_t measureAlarm;

void organizaAlarmes(void)
{
	uint8_t aux_measureAlarm =0;

	if((flag.alarme == 0) &&(contVerAlarme <= 0))
	{
		/*aguaTemp=120;
		oleoTemp=120;
		TempA=120;
		TempB=120;*/

		if((aguaTemp > maxTempAgua)||(aguaTemp < minTempAgua))
		{
			//almAgua =1;
			flag.alarme = 1;
			alarme_[0] = 1;
			measureAlarm = 800;

		alarde ++;
			aux_measureAlarm +=500;
		}


		if((oleoTemp > maxTempOleo)||(aguaTemp < minTempOleo))
		{
			//almOleo =1;
			flag.alarme = 1;
			alarme_[1] = 1;
			measureAlarm = 800;


			alarde ++;
			aux_measureAlarm +=500;
		}


		if((TempA > maxTempA)||(TempA < minTempA))
		{
			//almTempA =1;
			flag.alarme = 1;
			alarme_[2] = 1;
			measureAlarm = 800;


			alarde ++;
			aux_measureAlarm +=500;
		}


		if((TempB > maxTempB)||(TempB < minTempB))
		{
			//almTempB =1;
			flag.alarme = 1;
			alarme_[3] = 1;
			measureAlarm = 800;


			alarde ++;
			aux_measureAlarm +=500;
		}

		if(( oleoPressao >  pOleomax)||( oleoPressao < pOleomin))
		{
			////almTempB =1;
			flag.alarme = 1;
			alarme_[4] = 1;
			measureAlarm = 800;


			alarde ++;
			aux_measureAlarm +=500;
		}
		if(( combPressao >  pCombmax)||( combPressao < pCombmin))
		{
			////almTempB =1;
			flag.alarme = 1;
			alarme_[5] = 1;
			measureAlarm = 800;


			alarde ++;
			aux_measureAlarm +=500;
		}
		if( bateria_ < 95)
		{
			////almTempB =1;
			flag.alarme = 1;
			alarme_[6] = 1;
			measureAlarm = 800;


			alarde ++;
			aux_measureAlarm +=500;
		}

	/*	if(OkFuel == 0)
		{
			////almTempB =1;
			flag.alarme = 0;
			alarme_[7] = 1;
			measureAlarm = 800;

		}*/
}

	ver_alarmes();
}
/*******************************************************************************************************************************************************************/
void ver_alarmes(void)
{
	byte q,r,qq,rr;
	if(flag.alarme == 1)
	{
		Buzzer_PutVal(1);

		if((alarme_[0] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[0] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('T');L('E'); L('M'); L('P'); L(' '); L('A');  L('G'); L('U'); L('A');
			contShowAlarme = 1000;
			almAgua = 0;
			alarde --;
			mede = 0;
		}

		if((alarme_[1] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[1] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('T');L('E'); L('M'); L('P'); L(' '); L('O');  L('L'); L('E'); L('O');
			contShowAlarme = 1000;
			almOleo = 0;
			alarde --;
			mede = 0;
		}

		if((alarme_[2] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[2] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('T');L('E'); L('M'); L('P'); L(' '); L(a); L(b); L(c); L(d);
			contShowAlarme = 1000;
			almTempA = 0;
			alarde --;
			mede = 0;
		}

		if((alarme_[3] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[3] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('T');L('E'); L('M'); L('P'); L(' '); L(e); L(f); L(g); L(h);
			contShowAlarme = 1000;

			alarde --;
			mede = 0;
		}

		if((alarme_[4] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[4] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('P');L('.'); L('O'); L('L'); L('E'); L('O');
			contShowAlarme = 1000;

			alarde --;
			mede = 0;
		}

		if((alarme_[5] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[5] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('P');L('.'); L('C'); L('O'); L('M'); L('B');
			contShowAlarme = 1000;

			alarde --;
			mede = 0;
		}

		if((alarme_[6] == 1)&&(contShowAlarme <= 0))
		{
			alarme_[6] = 0;
			clear_line(4);
			L('A'); L('L'); L('M'); L(' '); L('B');L('A'); L('T'); L('E'); L('R'); L('I'); L('A');
			contShowAlarme = 1000;

			alarde --;
			mede = 0;
		}


		if((alarde <=1)||(alarde > 15))
		{
			flag.alarme = 0;

			//mede = 0;
			back = 0;

			contVerAlarme = 5000;
		}
	}

	if((mede >= 1050)&& (back == 0))
	{
		back = 1;
		switch(tela)
		{
			case 100:
			{
				Buzzer_PutVal(0);
				clear_line(4);
				 move_character(4,1);
				 L('N'); L('i');L('v'); L('e');L('l'); L(':');


					if(nivel <100)
					{
						q = nivel/10;
						r = nivel%10;

						move_character(4, 7);
						L(' ');  L(q); L(r);
					}

					else
					{
						q = (nivel/10)%10;
						r = nivel%100;
						qq = nivel/100;

						move_character(4, 7);
						L(qq); L(q); L(r);
					}

				 move_character(4,10);
				 L('%');
				// almTempA =0;
				 getRtc();


			}break;

			case 99:
			{
				Buzzer_PutVal(0);

					clear_line(4);
					move_character(4,1);
					L('T'); L('e'); L('m'); L('p'); L(' '); L(a); L(b); L(c); L(d);   auxAlarmeOleo(engOleoA, TempA,3);
					move_character(4,14);  L('°'); if(engOleoA ==1) L('C'); else {L('F');}

			}break;

			case 101:
			{
				Buzzer_PutVal(0);
				clear_line(4);
				// move_character(3,1);
				// L('B'); L('A'); L('T'); L('E'); L('R'); L('I'); L('A'); L(' ');
				 almTempA =0;

			}break;
		}
	}
}
/*******************************************************************************************/
uint16_t unityMap(uint16_t analogMap, bool range)
{
	int i=0;
	uint16_t press=0;
	uint32_t auxMapDiv=0,auxMapEnum=0;
	uint16_t voltsMap[3];
	uint16_t presMap[3];

	switch(range)
	{
		case 0:
		{
			voltsMap[0] = 20;
			voltsMap[1] = 239;
			voltsMap[2] = 492;

			presMap[0] = 20;
			presMap[1] = 127;
			presMap[2] = 250;

			if((analogMap < 20)||(analogMap > 492))
			{
				if(analogMap < 20) press = 0;

				else press = 250;
			}

			else
			{

				for( i = 1;i<= 2;++i)
				{
					if(analogMap >= voltsMap[i-1] && analogMap <=  voltsMap[i])
					{
						auxMapEnum = (( analogMap - voltsMap[i-1]) * (presMap[i]-presMap[i-1]));

						auxMapDiv =(voltsMap[i] - voltsMap[i-1]);

						press = auxMapEnum / auxMapDiv;

						press = press + presMap[i-1];

						i=100;
					}
				}
			}
		}break;

		case 1 :
		{
			voltsMap[0] = 20;
			voltsMap[1] = 230;
			voltsMap[2] = 473;

			presMap[0] = 20;
			presMap[1] = 375;
			presMap[2] = 750;

			if((analogMap < 20)||(analogMap > 473))
			{
				if(analogMap < 20) press = 0;

				else press = 750;
			}

			else
			{

				for( i = 1;i<= 2;++i)
				{
					if(analogMap >= voltsMap[i-1] && analogMap <=  voltsMap[i])
					{
						auxMapEnum = (( analogMap - voltsMap[i-1]) * (presMap[i]-presMap[i-1]));

						auxMapDiv =(voltsMap[i] - voltsMap[i-1]);

						press = auxMapEnum / auxMapDiv;

						press = press + presMap[i-1];

						i=100;
					}
				}
			}
		}break;

	}


	return(press);
}
/*******************************************************************************************/
uint16_t unityPressOleo(uint16_t analogOleo)
{
	uint16_t press=0;
	uint32_t auxMapDiv=0,auxMapEnum=0;

	if(analogOleo <= voltsOleomin)
	{
		press = 0;
	}

	else
	{
		auxMapEnum = ((analogOleo - voltsOleomin) * (pressOleoMax*10));

		auxMapDiv = (voltsOleoMax - voltsOleomin);

		press = auxMapEnum / auxMapDiv;
	}

	return(press);
}
/*******************************************************************************************/
uint16_t unityPressComb(uint16_t analogComb)
{
	uint16_t press=0;
	uint32_t auxMapDiv=0,auxMapEnum=0;

	if(analogComb <= voltsCombMin)
	{
		press = 0;
	}

	else
	{
		auxMapEnum = ((analogComb - voltsCombMin) * (pressCombMax*10));

		auxMapDiv = (voltsCombMax - voltsCombMin);

		press = auxMapEnum / auxMapDiv;
	}

	return(press);
}




