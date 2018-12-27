/*
 * velocimetro.c

 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */


#include "main.h"
#include "auxiliar.h"
#include "display.h"
#include "Velocimetro.h"
#include "aux_telas.h"
#include "dadosFlash.h"
#include "nivel_tanque.h"

/****************************************************************************************/

void odometro(void)
{
	byte show_disp = 0;
	bool esc = 0;
	byte i = 1; // indice para somar o cursor
	bool cursor = 0;
	bool inicioconfig = 0;
	 limpa_disp(); // limpa o display
	 linha(1);
	 L('C'); L('O'); L('N');  L('F'); L('I'); L('G'); L('.');   L('O'); L('D');  L('O');  L('M');   L('E');  L('T');  L('R');  L('O'); // L('T'); L('R');  L('O');

	  while(tela == 1)
	 {
		//if(tecla ==  UP) tela = 2;
		//if(tecla == MENU) tela = 4;

		//if(tecla == ENTER)  // ao pressionar a tecla enter entra no modo de calibração do sensor do velocímetro
		//{
			 linha(2);
			 L('S'); L('E'); L('L');   L('.');  L(' '); L('A'); L(' ');L('D');  L('I');  L('S');   L('T');  L('A');  L('N');  L('C');  L('I'); L('A');



			 L(2); L(0); L(0); L('m');   L(' '); L(' ');  L(5);  L(0);   L(0);  L('m');  L(' ');  L(1);  L(0); L(0);  L(0);  L('m');

			velocimetro.config = 1;
			tecla = 0;

			show_cursor(1);

			posiciona_cursor(i);

			cursor = 1;

	//	}

		if(cursor)
		{
			tecla = 0;
			while(!esc)
			{
				 WDog1_Clear();
				if(tecla == UP)
				{
					i += 1;
					if(i > 3) i =1;

					posiciona_cursor(i);
					tecla = 0;
				}


				if(tecla == DOWN)
				{
					i-= 1;
					if(i <= 0) i =3;
					posiciona_cursor(i);
					tecla = 0;
				}

				if(tecla == ENTER)
				{
					cursor = 0;
					tecla = 0;
					esc = 1;
				}

				if(tecla == MENU)
				{
					tela = 4;

					esc =1;
				}


			}

			show_cursor(0);

		}
		esc = 0;

		inicioconfig = 0;

		while((velocimetro.config)&& (tela == 1))
		{
			 WDog1_Clear();


			 if(!show_disp)
			 {
				 if(i == 1) // ANDE 200 METROS!
				 {
					 linha(2);
					 L('R'); L('O'); L('D'); L('E'); L(' ');   L(2); L(0);  L(0);  L(' ');   L('M');  L('E');  L('T');  L('R');  L('O'); L('S');  L('!');

					 move_character(3,1);

					 L(' '); L('T'); L('E'); L('C'); L('L'); L('E');   L(' '); L('U');  L('P');  L(' ');   L('P');  L('A');  L('R');  L('A');  L(' '); L(' ');  L(' ');

					 clear_line(4);
					 move_character(4,5);

					L('I'); L('N'); L('I'); L('C');   L('I'); L('A');  L('R');  L(' ');   L(' ');  L(' '); L(' ');  L(' ');  L(' ');
					 tecla = 0;
					 show_disp =1;
				 }


				 if(i == 2)  // ANDE 500 METROS!
				 {
					 linha(2);
					 L('R'); L('O'); L('D'); L('E'); L(' ');   L(5); L(0);  L(0);  L(' ');   L('M');  L('E');  L('T');  L('R');  L('O'); L('S');  L('!');

					 move_character(3,1);

					 L(' '); L('T'); L('E'); L('C'); L('L'); L('E');   L(' '); L('U');  L('P');  L(' ');   L('P');  L('A');  L('R');  L('A');  L(' '); L(' ');  L(' ');

					 clear_line(4);
					 move_character(4,5);

					  L('I'); L('N'); L('I'); L('C');   L('I'); L('A');  L('R');   L(' ');  L(' ');  L(' '); L(' ');  L(' ');  L(' ');
					 tecla = 0;
					 show_disp =1;
				 }


				 if(i == 3)// ANDE 1000 METROS!
				 {
					 linha(2);
					 L('R'); L('O'); L('D'); L('E'); L(' ');   L(1); L(0);  L(0);  L(0); L(' ');  L('M');  L('E');  L('T');  L('R');  L('O'); L('S');

					 move_character(3,1);

					 L(' '); L('T'); L('E'); L('C'); L('L'); L('E');   L(' '); L('U');  L('P');  L(' ');   L('P');  L('A');  L('R');  L('A');  L(' '); L(' ');  L(' ');

					 clear_line(4);
					 move_character(4,5);

					 L('I'); L('N'); L('I'); L('C');   L('I'); L('A');  L('R');  L(' ');  L(' ');  L(' '); L(' ');  L(' ');  L(' ');
					 tecla = 0;
					 show_disp =1;
				 }
			 }

				if((tecla == UP) &&(!inicioconfig))  // se ainda não foi dado o começo para aquisição dos dados aceita somente essa tecla up
				{
					pulsos_odo =0;
					odometroMetro = 0;
					odometroTotal = 0;
					odometroParcial =0;
					linha(2);
					 L('C'); L('O'); L('L'); L('E'); L('T');   L('A'); L('N');  L('D');  L('O'); L(' ');  L('D');  L('A');  L('D');  L('O');  L('S'); L(' ');

					 move_character(3,1);

					 L(' '); L('T'); L('E'); L('C'); L('L'); L('E');   L(' '); L('E');  L('N');  L('T');   L('E');  L('R');  L(' ');  L('P');  L('/'); L(' ');  L(' ');

					 clear_line(4);
					 move_character(4,4);

					 L('F'); L('I'); L('N'); L('A');   L('L'); L('I');  L('Z');  L('A');  L('R');    L(' '); L(' ');  L(' ');  L(' ');
					 tecla = 0;
					 inicioconfig =1 ;

				}

				if((tecla == ENTER) &&(inicioconfig))
				{
					if(i == 1)  // se a distância escolhida for 200 metros:
					{
						auxPulsos_odo = pulsos_odo/2;  // assim então sabemos que a cada 100 metros são xxx pulsos0
					}

					if(i == 2)  // se a distância escolhida for 500 metros:
					{
						auxPulsos_odo  = pulsos_odo/5;  // assim então sabemos que a cada 100 metros são xxx pulsos
					}

					if(i == 3)  // se a distância escolhida for 1000 metros:
					{
						auxPulsos_odo  = pulsos_odo/10;  // assim então sabemos que a cada 100 metros são xxx pulsos
					}


					 limpa_disp(); // limpa o display
					 linha(2);
					 L(' '); L(' ');  L('A'); L('G');  L('U');  L('A');   L('R');  L('D');  L('E'); L('.'); L('.');   L('.');

					  velocimetro.config = 0;
					  tecla = 0;
					  show_disp = 0;


					  delay(2000);

					  limpa_disp(); // limpa o display
					  linha(1);
					  //L('C'); L('O'); L('N');  L('F'); L('I'); L('G'); L('.');   L('O'); L('D');  L('O');  L('M');   L('E');  L('T');  L('R');  L('O');
					  tela = 4;
				}

				if(tecla == MENU)
				{
					tela = 4;

					  velocimetro.config = 0;
					  tecla = 0;
					  show_disp = 0;

				}

		}
		 WDog1_Clear();
	 }
	  writeflash(flashdataadr,1,auxPulsos_odo);  // salva os dados de calibração
	 tecla = 0;
}
/****************************************************************************************/
/****************************************************************************************/
void config_velocimetro(void)
{
	bool show = 0;
	 limpa_disp(); // limpa o display
	 linha(1);
	 L('C'); L('O'); L('N'); L('F');  L('.');  L('V'); L('E'); L('L'); L('O');L('C'); L('I'); L('M'); L('E'); L('T'); L('R');  L('O');
	 linha(2);
	 L('A'); L('N'); L('D'); L('A');  L('R');  L(' '); L('A'); L(' '); L(6);L(0); L('K'); L('m'); L('/'); L('h'); L('!');
	 move_character(3,6);
	  L('T'); L('E'); L('C'); L('L');  L('E');
	 linha(4);
	 L('E'); L('N'); L('T');L('E'); L('R');L(' '); L('P'); L('/'); L(' ');L('A'); L('C');L('E');L('I'); L('T');L('A');L('R');
	 show = 1;
	 tecla = 0;
	 odometro_.config =1;


	 while(tela == 2)
	 {
	/*	 if(tecla == ENTER)
		 {
			 if(!show)
			 {
				 linha(2);
				 L('A'); L('N'); L('D'); L('A');  L('R');  L(' '); L('A'); L(' '); L(6);L(0); L('K'); L('m'); L('/'); L('h'); L('!');
				 move_character(3,6);
				  L('T'); L('E'); L('C'); L('L');  L('E');
				 linha(4);
				 L('E'); L('N'); L('T');L('E'); L('R');L(' '); L('P'); L('/'); L(' ');L('A'); L('C');L('E');L('I'); L('T');L('A');L('R');
				 show = 1;
				 tecla = 0;
				 odometro_.config =1;
			 }
		 }*/


	//	 while(odometro_.config)
	//	 {
			 WDog1_Clear();
			 if(tecla == ENTER)
			 {
				 limpa_disp(); // limpa o display
				 move_character(2,4);
				 L('A'); L('G');  L('U');  L('A'); L('R'); L('D'); L('E');L(' .'); L('.'); L('.');

				 calculaVelocidade(0); // lÊ os pulsos e armazena quantos pulsos em 1s
				 delay(2000);

				 limpa_disp(); // limpa o display
				 linha(2);
				 L(' '); L('V'); L('E'); L('L'); L('O');  L('C');  L('I'); L('M'); L('E'); L('T');L('R'); L('O'); L(' ');  L('O'); L('K');

				 delay(1000);
				 flag.configVelocidade =0;

				// limpa_disp(); // limpa o display
				// linha(1);
				// L('C'); L('O'); L('N'); L('F');  L('.');  L('V'); L('E'); L('L'); L('O');L('C'); L('I'); L('M'); L('E'); L('T'); L('R');  L('O');

				 odometro_.config = 0;
				 tecla = 0;
				 tela = 4;
				 show = 0;
			 }

		// }

		 if(tecla ==  DOWN) tela = 1;
		 if(tecla == MENU) tela = 4;

		 WDog1_Clear();
	 }
	 tecla = 0;
}
/*****************************************************************************/
void calculaVelocidade(bool config)
{

	uint16_t velocity=0;
	//uint32_t pulsosHora;
	byte r,q,qq;

	 WDog1_Clear();
	pulsosHora_=0;
	pulsosHora_= (10000000 /timeVel);


	if(config == 0)
	{
		writeflash(flashdataadr,49,pulsosHora_);
		pulsosHora = (pulsosHora_*60)*60;
		referVelocidade = pulsosHora;  // referencia para calibrar a velocidade em 60 km por hora
	}

	else
	{
		//if(!chupa){
		if(cont_vel <= 0)
		{
			if(contVelocimetro > 0)
			{
				pulsosHora = (pulsosHora_*60)*60;
				velocity = (pulsosHora*60) / referVelocidade;///referVelocidade;

			}
			else
			{
				velocity =0;
			}

			velocity=acelerom(velocity);

			if(velocity <=99)  // se a velocidade for menor que 100
			{
				q = velocity/10;
				r= velocity%10;
				move_character(1, 1);
				L(' '); L(q); L(r);
			}

			else  // se for maior ou igual
			{
				qq= velocity/100;
				q = (velocity/10)%10;
				r= velocity%10;

				move_character(1, 1);
				L(qq); L(q); L(r);
			}

			cont_vel = 1300;

		}
//	}
	}
}
/**********************************************************************************/
uint16_t acelerom(uint16_t velocidade)
{
	int array=0;
	if(flag.configVelocidade)
	{
		if(velocidade > velocidadeAnt)
		{
			array = velocidade - velocidadeAnt;

			if(array > 35)
			{
				//if(velocidadeAnt == 0)
					flag.configVelocidade =0;

				return velocidadeAnt;
			} // = velocidadeAnt;}
			else
			{
				velocidadeAnt=velocidade;
				return velocidade;
			}
		}
		else
		{
			velocidadeAnt=velocidade;
			return velocidade;
		}
	}

	else
	{
		velocidadeAnt=velocidade;
		flag.configVelocidade =1;
		return velocidade;
	}


}
/**********************************************************************************/
void calculaOdometro(void)
{


	// getPulsosOdo();

	if(pulsos_odo >= auxPulsos_odo)  // auxPulsos_odo "É uma constante, seu valor não muda "
	{

		pulsos_odo = 0;  // zera o contador de pulsos
		odometroMetro +=1;   // incrementa o valor do metro percorrido
		contFuel ++; // contagem para dizer a medir o alrme do tanque

		// writeflash(flashdataadr,2,odometroMetro);  // salva os dados de calibração

		if(odometroMetro!=10)
		{
			//if(!almTempB)
			//{
 				if(tela == 100)
				{
					move_character(2, 13);
					L('.');L(odometroMetro);
				}
			//}
		}


		else
		{
			if(tela == 100)
			{
				move_character(2, 13);
				L('.');L(0);
			}
		}

		if(odometroMetro >9)  // se percorrer 1km zera o contador do metro e acrescenta 1km
		{
			odometroMetro = 0; // zera o contador de metro
			odometroTotal += 1; // incrementa a quantidade de quilometros
			odometroParcial += 1;
			if(odometroParcial >999) odometroParcial = 0;
			contKmfuel +=1;
			if(!almTempB)
			{
				if(tela == 100)
				{
					showOdometro();
				}
			}

				// writeflash(flashdataadr,3,odometroTotal);  // salva os dados de calibração
		}
	}
}
/******************************************************************************/
void showOdometro(void)
{
	 byte err,r,q,qq,rr;

	 if(!OkFuel){
		 kmRest -= 1;
		 if(kmRest > 254)kmRest =0;
	 }

	if((odometroTotal <10)||(odometroParcial <10))
	{
		if(odometroParcial <10)
		{
			rr= (odometroParcial%100)%10;
			move_character(2, 10);
			L(' ');L(' ');L(rr);
		}

		if(OkFuel == 1)
		{
			if(odometroTotal <10)
			{
				rr= (odometroTotal%100)%10;
				move_character(2, 6);
				L(rr);
			}
		}
	}

	if (((odometroTotal >=10)&&(odometroTotal < 100))||((odometroParcial >=10)&&(odometroParcial < 100)))
	{
		if ((odometroParcial >=10)&&(odometroParcial < 100))
		{
			qq= (odometroParcial%100)/10;
			rr= (odometroParcial%100)%10;
			move_character(2, 10);
			L(' ');L(qq);	L(rr);L('.');	L(0);
		}

		if(OkFuel == 1)
		{
			if((odometroTotal >=10)&&(odometroTotal < 100))
			{
				qq= (odometroTotal%100)/10;
				rr= (odometroTotal%100)%10;

				move_character(2, 5);
				L(qq);	L(rr);
			}
		}

	}

	if(((odometroTotal >=100)&&(odometroTotal < 1000)) ||((odometroParcial >=100)&&(odometroParcial < 1000)))
	{
		if((odometroParcial >=100)&&(odometroParcial < 1000))
		{
			r= (odometroParcial/100)%10;
			qq= (odometroParcial%100)/10;
			rr= (odometroParcial%100)%10;
			move_character(2, 10);
			L(r);L(qq);	L(rr);
		}

		if(OkFuel == 1)
		{
			if((odometroTotal >=100)&&(odometroTotal < 1000))
			{
				r= (odometroTotal/100)%10;
				qq= (odometroTotal%100)/10;
				rr= (odometroTotal%100)%10;

				move_character(2, 4);
				L(r);L(qq);	L(rr);
			}
		}
	}

	if ((odometroTotal >=1000)&&(odometroTotal < 10000))
	{
		q= (odometroTotal/100)/10;
		r= (odometroTotal/100)%10;
		qq= (odometroTotal%100)/10;
		rr= (odometroTotal%100)%10;

		if(OkFuel == 1)
		{
			move_character(2, 3);
			L(q); L(r);L(qq);	L(rr);
		}
	}
	//chekKm( aux_nivel, nivel);
}
/*********************************************************************************/
void getRpm(void)
{

	uint16_t q,r,qq,rr,qqq;


	uint16_t bits = 0;

	if(!chupa){

	  if(contMedRpm <= 0){

		  if(teta <= 0){ time_ = 0;}
		  if(time_){
		  bits = (60000000/time_);
		  //teta = 0;

		  bits = bits /pulsosPorVolta;
		  if(bits > 15000) bits =15000;
		  }
		  else  bits =0;


		 // if(bits < 600) bits = 600;
	//	 qqq= (bits/1000)/10;
		 if(bits < 10000){
		 q= (bits/100)/10;
		 r= (bits/100)%10;
		 qq= (bits%100)/10;
		 rr= (bits%100)%10;
		 move_character(1, 9);
		 L(' '); L(q); L(r);L(qq);L(rr);
		 }

		 else
		 {
			 qqq= (bits/1000)/10;
			 q= (((bits/100)/10)%10);
			 r= (bits/100)%10;
			 qq= (bits%100)/10;
			 rr= (bits%100)%10;
			 move_character(1, 9);
			 L(qqq); L(q); L(r);L(qq);L(rr);

		 }
		 contMedRpm = 1000;
	  }
	}

	  WDog1_Clear();

}
