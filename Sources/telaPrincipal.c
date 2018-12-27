/*
 * telaPrincipal.c
 *
 *  Created on: 02/09/2018
 *      Author: Rosimar
 */
#include "main.h"
#include "display.h"
#include "auxiliar.h"
#include "velocimetro.h"
#include "aux_telas.h"
#include "analogicas.h"

#include "telaPrincipal.h"
#include "nivel_tanque.h"
#include"dadosFlash.h"
//extern uint16_t a,b,c,d,e,f,g,h;


void telaPrincipal(void)
{
	 byte err,r,q,qq,rr;
	 uint16_t bits;
	 uint16_t velocity;

	 limpa_disp();
	move_character(1,4);
	 L('k'); L('m'); L('/'); L('h');

	 move_character(1,14);
	 L('r'); L('p');  L('m');


	 showOdometro(); move_character(2,13);

	L('.');L(odometroMetro);

	 move_character(2,15);
	 L('k'); L('m');

	 medTanque(boia);

	 if(nivel <= 25)
	 {
		 move_character(2,1);
		 L(' ');  L(' '); L(' ');  L(' '); L(' ');  L(' ');
		 move_character(2,1);
		 L('F');  L('/');
	 }


	 move_character(2,7);
	 L('k'); L('m');


	 move_character(4,1);
	 L('N'); L('i');L('v'); L('e');L('l'); L(':');

	 move_character(4,10);
	 L('%');

	 move_character(3,1);
	 L('T'); L('e'); L('m'); L('p'); L(' '); L('A'); L('g'); L('u'); L('a'); L(':');


	 move_character(3,15);
	 L('°'); if(engAgua ==1) L('C'); else { L('F');}// else {if(!limit.agua){ maxTempAgua = maxTempAgua *18; maxTempAgua += 320;limit.agua=1;} L('F');} // if(engAgua == 0) {maxTempAgua = maxTempAgua *18; maxTempAgua += 320;}

	// if(!limit.oleo){ maxTempOleo = maxTempOleo *18; maxTempOleo += 320;limit.oleo=1;}

	 getRtc();

	 contMedRpm=0;
	 aux_nivel = 255;// ape

	 tecla = 0;
	while(tela == 100)
	{
		WDog1_Clear();

		teclasTela();

		getRpm();

		 calculaVelocidade(1);

		 calculaOdometro();

		 tempAgua(engAgua);

		 temperaturaOleo(engOleo);

		 temperaturaAuxA(engOleoA);

		 temperaturaAuxB(engOleoB);

		 pressaoOleo(oleoPress);

		 pressaoComb(combPress);


		 medTanque(boia);

		 bateria();

		 tensao(BAT_VOLTS);
		 organizaAlarmes();

	}
	if(tela == 4)
	{
		if(!senhaHabilitada) verSenha();
	}
	if(tela == 90)  // se for paara desligar grava
	{
		 writeflash(flashdataadr,2,odometroMetro);  // salva os dados de calibração
	 writeflash(flashdataadr,3,odometroTotal);  // salva os dados de calibração
	 writeflash(flashdataadr,57,odometroParcial);  // salva os dados de calibração
	 writeflash(flashdataadr,54,kmRest_);
	 writeflash(flashdataadr,53,kmRest);
	 writeflash(flashdataadr,52,contKmfuel);
	}

}
/*******************************************/
void telaPrincipalCont(void)
{
	 limpa_disp(); // limpa todo display

	 // escreve o titulo da variável a ser medido
	 move_character(1,1);
	L('T'); L('e'); L('m'); L('p'); L(' '); L('O'); L('l'); L('e'); L('o');

	move_character(1,15);  L('°'); if(engOleo ==1) L('C'); else { L('F');}//else {if(!limit.oleo){ maxTempOleo = maxTempOleo *18; maxTempOleo += 320;limit.oleo=1;} L('F');}

	// escreve o titulo da variável a ser medido
	 move_character(2,1);
	L('P'); L('.'); L('C'); L('o'); L('m'); L('b');
	move_character(2,12); L('b'); L('a'); L('r');

	// escreve o titulo da variável a ser medido
	 move_character(3,1);
	L('P'); L('.'); L('O'); L('l'); L('e'); L('o');
	move_character(3,12); L('b'); L('a'); L('r');

	// escreve o titulo da variável a ser medido
	 move_character(4,1);
	 L('T'); L('e'); L('m'); L('p'); L(' '); L(a); L(b); L(c); L(d);

	move_character(4,15);  L('°');  if(engOleoA ==1) L('C'); else { L('F');}//else {if(!limit.tempa){ maxTempA = maxTempA *18; maxTempA += 320;limit.tempa=1;} L('F');}

	while(tela == 99)
	{
		WDog1_Clear();

		 calculaOdometro();

		teclasTela();
		 tempAgua(engAgua);

		 temperaturaOleo(engOleo);

		 temperaturaAuxA(engOleoA);

		 temperaturaAuxB(engOleoB);

		pressaoOleo(oleoPress);

		pressaoComb(combPress);

		//temperaturaAuxA();
		bateria();
		organizaAlarmes();
	}
	if(tela == 4)
	{
		if(!senhaHabilitada) verSenha();
	}

	if(tela == 90)  // se for paara desligar grava
	{
	 writeflash(flashdataadr,3,odometroTotal);  // salva os dados de calibração
	 writeflash(flashdataadr,57,odometroParcial);  // salva os dados de calibração
	 writeflash(flashdataadr,54,kmRest_);
	 writeflash(flashdataadr,53,kmRest);
	 writeflash(flashdataadr,52,contKmfuel);
	}

}
/************************************************************************************************/
void telaPrincipal101(void)
{
	 limpa_disp(); // limpa todo display

	 // escreve o titulo da variável a ser medido
	 move_character(2,1);
	 L('T'); L('e'); L('m'); L('p'); L(' '); L(e); L(f); L(g); L(h);
	move_character(2,15);  L('°'); if(engOleoB ==1) L('C');  else { L('F');}

	//if(!lamb){ move_character(3,10);  L('?');} else{ move_character(3,10);  L('A'); L('F'); L('R');}

	 move_character(3,1);
	 L('B'); L('A'); L('T'); L('E'); L('R'); L('I'); L('A'); L(' ');

	 if(chupa == 0) // se não estiver em alarme
	 {
	 move_character(1,1);
	 L('M'); L('A'); L('P'); L(' ');  if(engMap == 2) {move_character(1,10);L('k'); L('P'); L('a'); }

	 if(engMap == 3) {move_character(1,10);L('b'); L('a'); L('r'); }

	 if(engMap == 4) {move_character(1,11);L('p'); L('s'); L('i'); }
	 }



	while(tela == 101)
	{
		WDog1_Clear();
		teclasTela();
		if(contMedRpm <= 0)
		{
			 calculaOdometro();

			 tempAgua(engAgua);

			 temperaturaOleo(engOleo);

			 temperaturaAuxA(engOleoA);

			 temperaturaAuxB(engOleoB);

			//lambda(lamb);

			bateria();

			pressMap(engMap);
			organizaAlarmes();
			pressaoOleo(oleoPress);

			pressaoComb(combPress);


			contMedRpm = 300;
		}
	}
		if(tela == 4)
		{
			if(!senhaHabilitada) verSenha();
		}

		if(tela == 90)  // se for paara desligar grava
		{
		 writeflash(flashdataadr,3,odometroTotal);  // salva os dados de calibração
		 writeflash(flashdataadr,57,odometroParcial);  // salva os dados de calibração
		 writeflash(flashdataadr,54,kmRest_);
		 writeflash(flashdataadr,53,kmRest);
		 writeflash(flashdataadr,52,contKmfuel);
		}
}
/************************************************************************************************/
 void teclasTela(void) // esssa função foi feita somente para a tela principal
{
	 uint8_t q,r,rr;

	 if(!contSetHora)  // atualiza a hora a cada 60 segundos
	 {
		 getRtc();
	 }
	switch(tecla)
	{

		case MENU:
		{
			tecla = 0;
			tela = 4;
			contMedRpm =0;
			return;
		}break;

		case DOWN:
		{
			tela --;
			if(tela <99) tela = 101;
			tecla =0;
		}break;

		case UP:
		{
			tela ++;
			if(tela >101) tela = 99;
			tecla =0;
		}break;

		case ENTER:
		{
			duty += 100;
			if(duty > 1000) duty = 100;
			BackLight_SetDutyUS(duty);

			delay(50);

			if(tela == 100)
			{
				if(duty < 1000)
				{
					q = (duty/10)/10;
					r = (duty%10)/10;

					move_character(4,12);
					L(' '); L(' ');L(q); L(r);L('%');
				}
				else
				{
					move_character(4,12);
					L(' ');L(1);L(0); L(0);L('%');
				}
			}
			tecla = 0;
			contSetHora = 5000;

		}break;
	}
}
 /**************************************************************************************************/



