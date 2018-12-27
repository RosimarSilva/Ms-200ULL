/*
 * nivel_tanque.c
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#include "main.h"
#include "display.h"
#include "auxiliar.h"
#include "nivel_tanque.h"
#include  "dadosFlash.h"
#include "velocimetro.h"

extern byte  p_cursor;
/************************************************************************************************/
void tanque_config(void)
{
	byte cont_etapa = 1,i;
	 limpa_disp(); // limpa o display

	 L('B'); L('O'); L('I'); L('A');  L('-');L(2);  L(4); L(0);L('-'); L(8); L(5); L('-');L(4);L(0);
	  linha(2);
	  L('B'); L('O'); L('I'); L('A');  L('-');L(2);  L(6); L(0);L('-'); L(1); L(5);L(0); L('-');L(4);L(0);
	 linha(3);
	 L('B'); L('O'); L('I'); L('A');  L('-');L(2); L('-'); L(4); L(6); L('-');L(9);L(0);
	 linha(4);
	 L('C'); L('A'); L('L'); L('I');L('B');L('R'); L('A'); L('R'); L('-'); L('B'); L('O'); L('I'); L('A');

	 tela = 5;
	 tanque.etapa = 1;
	 while(tela == 5)
	 {
		tecla = 0;
		if(cont_etapa == 1)
		{
			p_cursor = 1;
			moveSeta(p_cursor,16);

			while(cont_etapa == 1)   // valores pré definidos
			{
				WDog1_Clear();
				if(tecla == DOWN)
				{
					p_cursor ++; tecla = 0;
					if(p_cursor > 4) p_cursor =1;   // faz a seta se mover
					moveSeta(p_cursor,16);
				}

				if(tecla == UP)
				{
					p_cursor--; tecla =0;

					if(p_cursor < 1) p_cursor =4;   // faz a seta se mover
					moveSeta(p_cursor,16);
				}

				if(tecla == ENTER)
				{
					show_cursor(0);
					tecla = 0;
					switch(p_cursor)
					{
					case 1:
					{
						for(i=2;i<=4;++i) clear_line(i);
						linha(2); // limpa o display
						L('S'); L('A'); L('L'); L('V');L('A');L('N'); L('D'); L('O'); L(' '); L('D'); L('A'); L('D'); L('O');L('S');
						linha(3);
						L('A'); L('G'); L('U'); L('A');L('R');L('D'); L('E'); L('.'); L('.'); L('.');

						boia = 1;
						writeflash(flashdataadr,48,boia);
						delay(3000);
						tela = 4;cont_etapa = 10;

					}break;

					case 2:
					{
						for(i=1;i<=4;++i) clear_line(i);
						linha(1);
						L('B'); L('O'); L('I'); L('A');  L('-');L(2);  L(6); L(0);L('-'); L(8); L(5); L('-');L(4);L(0);
						linha(2); // limpa o display
						L('S'); L('A'); L('L'); L('V');L('A');L('N'); L('D'); L('O'); L(' '); L('D'); L('A'); L('D'); L('O');L('S');
						linha(3);
						L('A'); L('G'); L('U'); L('A');L('R');L('D'); L('E'); L('.'); L('.'); L('.');
						boia = 2;
						writeflash(flashdataadr,48,boia);
						delay(3000);
						tela = 4;cont_etapa = 10;

					}break;

					case 3:
					{
						for(i=1;i<=4;++i) clear_line(i);
						linha(1);
						L('B'); L('O'); L('I'); L('A');  L('-');L(2); L('-'); L(4); L(6); L('-');L(9);L(0);
						linha(2);
						L('S'); L('A'); L('L'); L('V');L('A');L('N'); L('D'); L('O'); L(' '); L('D'); L('A'); L('D'); L('O');L('S');
						linha(3);
						L('A'); L('G'); L('U'); L('A');L('R');L('D'); L('E'); L('.'); L('.'); L('.');
						boia = 3;
						writeflash(flashdataadr,48,boia);
						delay(3000);
						tela = 4;cont_etapa = 10;

					}break;

					case 4:  // aqui vai ter que calibrar meio começo e fim
					{
						for(i=1;i<=4;++i) clear_line(i);
						linha(1);
						L('C'); L('A'); L('L'); L('I');L('B');L('R'); L('A'); L('R'); L('-'); L('B'); L('O'); L('I'); L('A');
						cont_etapa = 2;
						linha(2);
						L('V'); L('A'); L('Z'); L('I');L('O');
						linha(3);
						L('M'); L('E'); L('I');L('O');
						linha(4);
						L('C'); L('H');L('E'); L('I');L('O');

								// show_cursor(1);
						p_cursor = 2;

						moveSeta(p_cursor,16);   // faz a seta se mover
						boia =4;
						writeflash(flashdataadr,48,boia);

					}break;

					}

				}//if(tecla == ENTER)
				if(tecla == MENU) {tela = 4;cont_etapa = 10;}

			} //while(tanque.etapa == 1)

			while(cont_etapa == 2)
			{
				WDog1_Clear();
				if(tecla == DOWN)
				{
					p_cursor ++; tecla = 0;
					if(p_cursor > 4) p_cursor =2;
					moveSeta(p_cursor,16); // faz a seta se mover
				}

				if(tecla == UP)
				{
					p_cursor--; tecla =0;

					if(p_cursor < 2) p_cursor =4;
					moveSeta(p_cursor,6); // faz a seta se mover
				}

				if(tecla == ENTER)
				{
					tecla =0;
							// show_cursor(0);
					switch(p_cursor)
					{
					case 2:
					{
						for(i=2;i<=4;++i) clear_line(i);

						linha(2);
						L('V'); L('A'); L('Z'); L('I');L('O');

						linha(3);
						L(' '); L(' '); L(' '); L('A'); L('G'); L('U'); L('A');L('R');L('D'); L('E'); L('.'); L('.'); L('.');

						analogTanq(1);
						delay(2000);
							atualiza_medTanq();

					}break;

					case 3:
					{
						for(i=2;i<=4;++i) clear_line(i);

						linha(2);
						L('M'); L('E'); L('I');L('O');

						linha(3);
						L(' '); L(' '); L(' '); L('A'); L('G'); L('U'); L('A');L('R');L('D'); L('E'); L('.'); L('.'); L('.');

						analogTanq(2);
						delay(2000);
						atualiza_medTanq();

					}break;

					case 4:
					{
						for(i=2;i<=4;++i) clear_line(i);

						linha(2);
						L('C'); L('H');L('E'); L('I');L('O');

						linha(3);
						L(' '); L(' '); L(' '); L('A'); L('G'); L('U'); L('A');L('R');L('D'); L('E'); L('.'); L('.'); L('.');

						analogTanq(3);
						delay(2000);
						//atualiza_medTanq();
						tela = 4;cont_etapa = 10; p_cursor = 4;

					}break;
					}
				}
						if(tecla == MENU) {tela = 4;cont_etapa = 10; p_cursor = 4; tecla = 0;}
			}

		}

			// }
		WDog1_Clear();
	 }
	 p_cursor = 4;
	 tecla = 0;
}
/*************************************************************************************/
void atualiza_medTanq(void)
{
	byte i;

	 for(i=2;i<=4;++i) clear_line(i);
	 linha(2);
	 L('V'); L('A'); L('Z'); L('I');L('O');
	 linha(3);
	 L('M'); L('E'); L('I');L('O');
	 linha(4);
	 L('C'); L('H');L('E'); L('I');L('O');

	 //show_cursor(1);
	 p_cursor+=1;
	 if(p_cursor>4) tela = 4;
	 moveSeta(p_cursor,16);
}
/*****************************************************************************************/
void analogTanq(byte config)  // armazenara os bits correspondentes a cada medida
{
	uint16_t bits=0;
	byte i;
	switch(config)
	{
		case 1:
		{
			for(i = 1;i<= 10; i++)
			{
				bits = nivelTanque();

				bits += bits;
			}

			bits = (bits/10);

			nivelTanqMin = bits;
			 writeflash(flashdataadr,5,nivelTanqMin);
			 anaBoia4[0] = nivelTanqMin;

		}break;

		case 2:
		{
			for(i = 1;i<= 10; i++)
			{
				bits = nivelTanque();

				bits += bits;
			}

			bits = (bits/10);

			nivelTanqMeio = bits;

			 writeflash(flashdataadr,6,nivelTanqMeio);

			 anaBoia4[1] =nivelTanqMeio;


		}break;

		case 3:
		{
			for(i = 1;i<= 10; i++)
			{
				bits = nivelTanque();

				bits += bits;
			}

			bits = (bits/10);

			nivelTanqMax = bits;

			 writeflash(flashdataadr,7,nivelTanqMax);
			 anaBoia4[2] = nivelTanqMax;


		}break;
	}
}
/*****************************************************************************************
void medTanque(void)
{
	uint16_t medida=0;
	byte nivel=0;
	byte r,q,qq;

	byte i=0;

	for(i=1;i<=10;++i)
	{
		medida = nivelTanque();

		medida += medida;
	}

	medida = (medida/10);

 	if(medida < nivelTanqMin) nivel = 0;

	if(medida >= nivelTanqMin  && medida <= nivelTanqMax)
	{
		//nivel = (medida*50)/ nivelTanqMeio;
		nivel =(medida* 100)/nivelTanqMax;
	}

	else
	{
		nivel = 100;
	}

	if((!flag.alarme )&&(mede >= 1050))
	{

	if(nivel <100)
	{
		q = nivel/10;
		r = nivel%10;

		move_character(4, 7);
		 L(' ');  L(q); L(r);
	}

	else
	{
		q = nivel/10;
		r = nivel%100;
		qq = nivel/100;

		move_character(4, 7);
		L(qq); L(q); L(r);

	}
	}
}
**********************************************************************************************/
void medTanque(byte config)
{
	uint16_t multiplicador=0,divisor=0;
	uint32_t medida=0;

	//byte nivel=0;
	byte r,q,qq;

	byte i=0;

	for(i=1;i<=10;++i)
	{
		medida = nivelTanque();

		medida += medida;
		// WDog1_Clear();
	}

	medida = (medida/10);

	switch(config)
	{
		case 1:
		{
			if(medida > anaBoia1[0]) nivel = 0;


			if(medida < anaBoia1[2]) nivel = 100;


			for(i =1;i<=2;++i)
			{
				if((medida <= anaBoia1[i-1] && medida >= anaBoia1[i]))
				{
					multiplicador = ((anaBoia1[i-1]- medida) * (percent[i]-percent[i-1]));

					divisor = anaBoia1[i-1] - anaBoia1[i];

					nivel =(multiplicador/divisor);//+ -percent[i-1]);
					nivel = nivel + percent[i-1];


					i=5;
				}
			}
		}break;

		case 2:
		{
			if(medida > anaBoia2[0]) nivel = 0;

			if(medida < anaBoia2[2]) nivel = 100;

			for(i =1;i<=2;++i)
			{
				if((medida <= anaBoia2[i-1] && medida >= anaBoia2[i]))
				{
					multiplicador = ((anaBoia2[i-1]- medida) * (percent[i]-percent[i-1]));

					divisor = (anaBoia2[i-1] - anaBoia2[i]);

					nivel =(multiplicador/divisor);//+ -percent[i-1]);
					nivel = nivel + percent[i-1];
					i=5;
				}
			}
		}break;

		case 3:
		{
			if(medida > anaBoia3[0]) nivel = 100;

			if(medida < anaBoia3[2]) nivel = 0;

			for(i =1;i<=2;++i)
			{
				if((medida >= anaBoia3[i-1] && medida <= anaBoia3[i]))
				{
					multiplicador = (( medida - anaBoia3[i-1]) * (percent[i]-percent[i-1]));

					divisor = (anaBoia3[i] - anaBoia3[i-1]);

					nivel =(multiplicador/divisor);//+ -percent[i-1]);
					nivel = nivel + percent[i-1];


					i=5;
				}
			}
		}break;

		case 4:
		{
 			if(medida > anaBoia4[0]) nivel = 0;

			if(medida < anaBoia4[2]) nivel = 100;

			for(i =1;i<=2;++i)
			{
				if((medida <= anaBoia4[i-1] && medida >= anaBoia4[i]))
				{
					multiplicador = ((anaBoia4[i-1]- medida) * (percent[i]-percent[i-1]));

					divisor = (anaBoia4[i-1] - anaBoia4[i]);

					nivel =(multiplicador/divisor);//+ -percent[i-1]);
					nivel = nivel + percent[i-1];


					i=5;
				}
			}
		}break;
	}

	if((!flag.alarme )&&(mede >= 1050))
	{
		if(contNivel <= 0){
		//if(aux_nivel != nivel)
	//	{

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

			aux_nivel = nivel;

			contNivel = 800;

		//}
		}
	}

	//if(contFuel > 1)
	//{
		contFuel = 0;
		chekKm(nivel_alarme,nivel);
	//}
	//organizaAlarmes();

	if(nivel < 25)KmRemaining();

	else
	{
		KmRemaining();
	}


}
/***************************************************************************************************/

void chekKm(uint16_t nilvelAlarde, uint16_t nivelBoia)  // (porcentagem armazenada, nivel real)
{
	const byte aux = 2;
	uint16_t percentFuel=0;
	int cur=0;

	if((nivelBoia > 25)&&(flag.histereze ==0))
	{
		if(nivel > auxBoia)
		{
			auxBoia = nivel + aux;
			contKmfuel = 0;
			nivel_alarme = nivel;
			  writeflash(flashdataadr,51,nivel_alarme);  // salva os dados de calibração
			  percentConfig = 0;
			  showFuel = 0;
		}
		OkFuel = 1;  // não ta em alarme de combustível
	}
	else
	{
		OkFuel = 0; // esta el alarme de combustível
		cur =nivel_ant-nivel;
		if(flag.histereze ==1)
		{
			if(nivelBoia>= 27) {flag.histereze =0;

			auxBoia_ =0;
			writeflash(flashdataadr,55,flag.histereze);

			}
		}
		if(percentConfig == 0)
		{
			percentFuel = nivel_alarme -15;

			kmRest = (15*contKmfuel)/percentFuel;
			auxBoia = 0;
			kmRest_ = kmRest;
			percentConfig = 1;
			flag.histereze =1;
			 writeflash(flashdataadr,52,kmRest);  // salva os dados de calibração
			 writeflash(flashdataadr,53,kmRest_);
			 writeflash(flashdataadr,54,percentConfig);
			 writeflash(flashdataadr,55,flag.histereze);
		}

		if((flag.histereze ==1)&&(nivelBoia <25))
		{
			if(conta == 0)
			{
				nivel_ant = nivel + aux;
				conta =1;
			}

			if(nivel >=nivel_ant)
			{
				kmRest = (nivel*kmRest_)/15;
				conta =0;
				 writeflash(flashdataadr,53,kmRest_);
			}
			if(nivel < nivel_ant - 2)
			{
				conta =0;
			}





		}
	}

}
/***************************************************************************************************/
bool show__ = 0;
void KmRemaining(void)
{
	byte q,r,qq,rr;
	if(!OkFuel)
	{
		if(showFuel == 0)
		{
			move_character(2,1);
			L(' ');  L(' '); L(' ');  L(' '); L(' ');  L(' ');
			move_character(2,1);
			L('F');  L('/');
			showFuel = 1;
			show__ = 0;
		}

		if(kmRest >99)
		{
			r= (kmRest/100)%10;
			qq= (kmRest%100)/10;
			rr= (kmRest%100)%10;
			move_character(2, 4);
			L(r);L(qq);	L(rr);
		}


		else
		{
			qq= (kmRest%100)/10;
			rr= (kmRest%100)%10;
			move_character(2, 4);
			L(' ');L(qq);	L(rr);

		}
	}

	else
	{
		if(show__ == 0)
		{
			show__ = 1;
		move_character(2,1);
		L(' ');  L(' '); L(' ');  L(' '); L(' ');
		showOdometro();

		move_character(2,7);
		 L('K'); L('m');

		}

	}
}




