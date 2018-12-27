/*
 * aux_telas.c
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#include "display.h"
#include "main.h"
#include "aux_telas.h"
#include "auxiliar.h"
#include "dadosFlash.h"
#include "analogicas.h"

extern byte  p_cursor;
//extern uint16_t a,b,c,d,e,f,g,h;

void config_rpm(void)
{

	limpa_disp();  // limpa todo display
	 move_character(1, 3);
	L('C'); L('O'); L('N');  L('F'); L('I'); L('G'); L('.');   L('R'); L('P');  L('M');
	 move_character(2, 1);
	  L('P'); L('U'); L('L');   L('S'); L('O');  L('S');  L(' ');  L('P'); L('/'); L(' ');  L('V'); L('O');  L('L');L('T');  L('A');
	  move_character(3, 6);
	  L('P'); L('U');  L('L');L('S');  L('O');L('S');
	 // show_cursor(1);
	  move_character(3, 4); L(pulsosPorVolta);
	while(tela == 6)
	{
		WDog1_Clear();

		switch(tecla)//verifica qual tecla foi pressionada
		{
			case UP:// se é para aumentar o setpoint:
			{ tecla = 0;
			pulsosPorVolta += 1;  //incrementa o n° de voltas

			if(pulsosPorVolta >9) pulsosPorVolta = 1;  // não deixa a o n de voltas ultrapassar  9
				 move_character(3, 4);  // move o cursor para uma posição do display
				 L(pulsosPorVolta);  // mostra no dispplay

			}break;

			case DOWN:// se é para aumentar o setpoint:
			{ tecla = 0;
				pulsosPorVolta -= 1;//decrementa o n° de voltas
				if(pulsosPorVolta < 1) pulsosPorVolta = 9;  // não deixa o numero passar para 256 ja que que se trata de uma váriavel byte que não tem numero negativo
				if(pulsosPorVolta >9) pulsosPorVolta = 1;    // não deixa o numero de voltas ultrappasar
				 move_character(3, 4);  // move o cursor para uma posição do display
				 L(pulsosPorVolta);// mostra no dispplay

			}break;

			case ENTER:
			{
				tecla = 0;

				clear_line(2); clear_line(3);

				 move_character(2,3);

				 L('A'); L('G');  L('U');L('A');  L('R');L('D');L('E');  L('.');L('.');L('.');

				 delay(1000);
				// tela = 4;
				 tela = 4;

				// vai la e salva na memoria toda vez que mudar esses pulsos
			}

		}

		if(tecla == MENU)
		{
			tela = 4;

			tecla = 0;
		}
	}
	 writeflash(flashdataadr,4,pulsosPorVolta);  // salva os dados de calibração
	p_cursor = 5;  // para quando chegar no menu o cursor estiver exatamente no menu de rpm
}
/********************************************************************************************/
void sensor_pressao(void)
{
	limpa_disp();  // limpa o display
	 move_character(1,3);  // Mmove o cracter para a linha e posição do display
	L('C'); L('A'); L('L'); L('.');   L('P'); L('R'); L('E'); L('S'); L('S');L('A'); L('O');
	linha(2); // prepara para escrever na linha 2
	L(1); L(' '); L('P'); L('R'); L('E'); L('S'); L('S');L('A'); L('O'); L(' ');L('O'); L('L'); L('E'); L('O');
	linha(3);// prepara para escrever na linha 3
	L(2);L(' ');;L('C'); L('O'); L('M'); L('B');L('U'); L('S'); L('T'); L('I');  L('V');  L('E'); L('L');
	linha(4);// prepara para escrever na linha 4
	L(3);L(' ');;L('S'); L('E'); L('N'); L('S');L('O'); L('R'); L(' '); L('M');  L('A');  L('P');



	//show_cursor(1);
	// move_character(2,15);
	 moveSeta(2,15);
	 tecla = 0;
	 p_cursor = 2;
	while(tela == 7)
	{
		WDog1_Clear();
		if(tecla !=0)
		{

			switch(tecla)  // seleciona qual tecla foi pressionada
			{
				case DOWN :{p_cursor ++; tecla = 0; if(p_cursor > 4) p_cursor =2;  moveSeta(p_cursor,15);}break;  // move ocursor para escolher o que vc vai calibrar

				case UP :{p_cursor--; tecla =0; if(p_cursor < 2) p_cursor =4; moveSeta(p_cursor,15);}break;  // move ocursor para escolher o que vc vai calibrar

				case  MENU:{tela = 4;tecla = 0;}break;  // volta para o menu principal

				case ENTER:{
					tecla = 0;
					if(p_cursor == 2){ configPressOleo(1);  return;}// configura a presão do óleo
					if(p_cursor == 3){ configPressOleo(2);  return;}// configura a pressão do combustivel , não va pelo nome da função
					if(p_cursor == 4){ sensorMap();  return;}//

					//else configPressComb();  // configura apressão do combustivel
				}break;
			}
		} //if(tecla !=0)

	}//while(tela == 7)
	p_cursor = 6;
}
/********************************************************************************************/
void sens_temperatura(void)
{
	contConFig =1;
	contConFig_ =1;
	bool conf= 1;
	limpa_disp();
	linha(1);
	move_character(1,1);
	L('T'); L('E'); L('M'); L('P');  L('.');  L('A'); L('G'); L('U'); L('A');

	move_character(2,1);
	L('T'); L('E'); L('M'); L('P');  L('.');  L('O'); L('L'); L('E'); L('O');

	move_character(3,1);
	L('T'); L('E'); L('M'); L('P');  L('.'); L(a);L(b);L(c);L(d);

	move_character(4,1);
	 L('T'); L('E'); L('M'); L('P');  L('.'); L(e);L(f);L(g);L(h);

	//   move_character(1,13);
	 moveSeta(p_cursor=1,11);
	while(conf)
	{
		WDog1_Clear();

		if(tecla)
		{
			switch(tecla)
			{
				case DOWN :
				{
					p_cursor ++; tecla = 0;
					if(p_cursor > 4) p_cursor =1;
					//move_character(p_cursor,13);
					 moveSeta(p_cursor,11);
				}break;

				case UP :
				{
					p_cursor--; tecla =0;

					if(p_cursor < 1) p_cursor =4;
					 moveSeta(p_cursor,11);
				}break;

				case ENTER :
				{
					 tecla =0;
					 contConFig = p_cursor;
					 conf = 0;

				}break;

				case MENU :
				{
					 tecla =0;
					tela = 4;
					p_cursor =7;
					conf = 0;

				}break;
			}
	}
	}


	limpa_disp();
	move_character(1,1);
	L('S'); L('E'); L('N'); L('S');  L('.');  L('T'); L('E'); L('M'); L('P');L('E'); L('R'); L('A');L('T'); L('U'); L('R');L('A');


	 while(tela == 8)
	{
		WDog1_Clear();
		switch(contConFig)
		{
			case 1:
			{
				move_character(2,1);
				L('T'); L('E'); L('M'); L('P');  L('.');  L('A'); L('G'); L('U'); L('A');
				SensorTempAgua();break;
			} break;
			case 2:
			{
				move_character(2,1);
				L('T'); L('E'); L('M'); L('P');  L('.');  L('O'); L('L'); L('E'); L('O');
				SensorTempAgua();
			} break;

			case 3:
			{
				move_character(2,1);
				L('T'); L('E'); L('M'); L('P');  L('.');  L('O'); L('L'); L('E'); L('O'); L(' '); L('A');
				SensorTempAgua();
			} break;

			case 4:
			{
				move_character(2,1);
				 L('T'); L('E'); L('M'); L('P');  L('.');  L('O'); L('L'); L('E'); L('O');  L(' ');L('B');
				SensorTempAgua();
			} break;


		}



		if((tecla == MENU) ||(contConFig > 4))
		{
			tela = 4;
			tecla = 0;
			p_cursor=7;
		}

	}

}
/********************************************************************************************/
void sonda_lambda(void)
{
	limpa_disp();
	linha(1);

	 move_character(1,3);
	L('S'); L('O'); L('N');  L('D'); L('A'); L(' '); L('L');   L('A'); L('M');  L('B'); L('D');  L('A');
	linha(2);
	 move_character(2,6);
	  L('N'); L('A'); L('R'); L('R');  L('O'); L('W');
	linha(3);
	 move_character(3,8);
	  L('W'); L('B');
	// show_cursor(1);
	 p_cursor = 2;
	 moveSeta(p_cursor,15);
	 while(tela == 9)
	{
		WDog1_Clear();

		if(tecla)
		{
			switch(tecla)
			{
				case DOWN :
				{
					p_cursor ++; tecla = 0;
					if(p_cursor > 3) p_cursor =2;
					 moveSeta(p_cursor,15);
				}break;

				case UP :
				{
					p_cursor--; tecla =0;

					if(p_cursor < 2) p_cursor =3;
					 moveSeta(p_cursor,15);
				}break;

				case MENU :
				{
					tela= 4;
					 tecla =0;
					 //show_cursor(0);

				}break;


				case ENTER :  // confirma qual vai usar narrow ou wind band
				{
					if(p_cursor == 2)
					{
						// show_cursor(0);
						 clear_line(3);
						 linha(2);
						 move_character(2,6);
						  L('N'); L('A'); L('R'); L('R');  L('O'); L('W');

						delay(2000);
						tela= 4;
						tecla = 0;

						lamb =0; // significa que a sonda lambda é narrow

					}

					if(p_cursor == 3)
					{
						 tecla = 0;
						// show_cursor(0);
						 clear_line(2);
						 clear_line(3);
						 linha(2);

						 move_character(2,8);
							 L('W'); L('B');
							// adjustLamb(3);
							 ConfLamb(); // seleciona o range ao valor equivalente a tensão para a lambida

							 lamb = 1; // significa que a sonda lambda é WB
					}
				}break;
			}

		}
	}
	 p_cursor = 8;
}
/********************************************************************************************/
void setDate(void)
{
	TIMEREC Time;
	DATEREC Date;

	byte d,dd,m,mm,a,aa,h,hh,n,nn,pont=1;


	limpa_disp();
	move_character(1,5);

	L('D'); L('A'); L('T'); L('A');  L('/');  L('H'); L('O');L('R'); L('A');

	getDate();
	getRtc();

	d = dia/10; dd = dia%10;
	m = mes/10; mm = mes%10;
	a =(ano -2000)/10; aa = (ano -2000)%10;

	h = hora/10;
	hh = hora%10;

	n = minuto/10;
	nn =minuto%10;

	move_character(2,5);
	L(d); L(d); L('/'); L(m); L(mm); L('/');L(a); L(aa);
	move_character(3,6);
	L(h); L(hh); L(':'); L(n); L(nn);

	move_character(2,1);
	L('D'); L('I'); L('A');
	tecla = 0;

	//Teclado_Disable();
	while(tela == 10)
	{
		WDog1_Clear();
		contSetHora = 500;

		if(tecla)
		{
			switch(tecla)
			{
				case DOWN :
				{
					 tecla = 0;
					 if(pont < 1) pont = 1;

					 switch(pont)
					 {
					 	 case 1:
					 	 {
					 		 dia--;
					 		 if(dia < 1) dia = 31;
					 		d = dia/10; dd = dia%10;
					 		move_character(2,5);
					 		L(d); L(dd);
					 	 }break;

					 	 case 2:
					 	 {
					 		 mes--;
					 		if(mes <1) mes = 12;
					 		 d = mes/10; dd = mes%10;
					 		 move_character(2,8);
					 		 L(d); L(dd);
					 	 }break;

					 	 case 3:
					 	 {
					 		 ano--;
					 		if(ano <8) ano = 25;
					 		 d = ano/10; dd = ano%10;
					 		 move_character(2,11);
					 		 L(d); L(dd);
					 	 }break;

					 	 case 4:
					 	 {
					 		 hora--;
					 		 if(hora >30) hora = 23;
					 		 d = hora/10; dd = hora%10;
					 		 move_character(3,6);
					 		 L(d); L(dd);
					 	 }break;

					 	 case 5:
					 	 {
					 		 minuto--;
					 		 if(minuto>70) minuto = 59;
					 		 d = minuto/10; dd = minuto%10;
					 		 move_character(3,9);
					 		 L(d); L(dd);
					 	 }break;

					 }// switch(pont)

				}break;  // Down

				case UP :
				{
					tecla = 0;
					 if(pont > 5) pont = 5;
					switch(pont)
					{
					case 1:
					{
						dia++;
						if(dia >31) dia = 1;
						d = dia/10; dd = dia%10;
						move_character(2,5);
						L(d); L(dd);
					}break;

					case 2:
					{
						mes++;
						if(mes >12) mes = 1;
						d = mes/10; dd = mes%10;
						move_character(2,8);
						L(d); L(dd);
					}break;

					case 3:
					{
						ano++;
						if(ano >99) ano = 8;
						d = ano/10; dd = ano%10;
						move_character(2,11);
						L(d); L(dd);
					}break;

					case 4:
					{
						hora++;
						if(hora>23) hora = 0;
						d = hora/10; dd = hora%10;
						move_character(3,6);
						L(d); L(dd);
					}break;

					case 5:
					{
						minuto++;
						if(minuto>59) minuto = 0;
						d = minuto/10; dd = minuto%10;
						move_character(3,9);
						L(d); L(dd);
					}break;

					}// switch(pont)
				}break;

				case MENU :
				{
					tela = 4;
					tecla = 0;

				}break;


				case ENTER :
				{
					pont++;

					tecla = 0;
					if(pont >5) pont = 1;

					if(pont == 1){move_character(2,1);L('D'); L('I'); L('A');}
					if(pont == 2){move_character(2,1);L('M'); L('E'); L('S');}
					if(pont == 3){move_character(2,1);L('A'); L('N'); L('O');}

					if(pont == 4){move_character(3,1);L('H'); L('O'); L('R'); L('A');}
					if(pont == 5){move_character(3,1);L('M'); L('I'); L('N'); L(' ');}

					delay(300);

				}break;
			}

		}
	}

		setRtc(hora,minuto);

		ano = ano+2000;

		TmDt1_SetDate(ano,mes,dia);
//Teclado_Enable();
}
/********************************************************************************************/
void AuxSenha(void)
{
	byte c = 16;
	bool conf = 1;
	limpa_disp();
	 move_character(1,5);
	 L('S'); L('E'); L('N'); L('H');  L('A');

	 move_character(2,3);
	 L('C'); L('A'); L('D'); L('A');  L('S'); L('T'); L('R');  L('A');  L('R');
	 move_character(3,3);
	 L('H'); L('A'); L('B'); L('I');  L('L'); L('I'); L('T');  L('A'); L('R');
	 move_character(4,3);
	 L('D'); L('E'); L('S'); L('A'); L('B'); L('I');  L('L'); L('I'); L('T');  L('A'); L('R');

	 p_cursor = 2;
	 moveSeta(p_cursor,c);
	 while(conf)
	 {
		if(tecla == DOWN)
		{
			p_cursor ++;
			if(p_cursor > 4) p_cursor = 2;
			 moveSeta(p_cursor,c);
			 tecla = 0;
		}
		if(tecla == UP)
		{
			p_cursor --;
			if(p_cursor <2) p_cursor = 4;
			 moveSeta(p_cursor,c);
			 tecla = 0;
		}

		if(tecla == ENTER)
		{
			 tecla = 0;
			if(p_cursor == 2)
			{
				conf = 0;
				tela == 11;
				cadastro_senha();
			}
			if(p_cursor == 3)
			{
				conf = 0;
				 senhaHabilitada = 0;  //esta habilitada
				 tela = 4;
				 p_cursor =9;
			}

			if(p_cursor == 4)
			{
				conf = 0;
				 senhaHabilitada = 1;  //não esta habilitada
				 tela = 4;
				 p_cursor =9;
			}

		}
	 }
	 p_cursor =9;

}
void cadastro_senha(void)
{

	 int contserie = 1, caracter = 7;
	 uint16_t aux_senha = 0, pont = 8;
	 bool salvar = 0,sim = 1,habilitar = 0;
	 byte tel= 1;

	 uint16_t senhaAnt = senha;

	 senha = 0;

	limpa_disp();
	linha(1);

	L('C'); L('A'); L('D');L('A'); L('S'); L('T');L('R'); L('O'); L(' ');L('S'); L('E'); L('N'); L('H');  L('A');  L('S');

	 move_character(2,1);
	 L('S'); L('E'); L('N'); L('H');  L('A');
	 show_cursor(1);
	 move_character(2,caracter);
		while(tela == 11)
		{
			if(tecla == UP)
			{
				if(contserie <= 4)
				{
					aux_senha ++;
					if(aux_senha> 9) aux_senha = 0;

					move_character(2,caracter);
					L(aux_senha);
					move_character(2,caracter);

					tecla = 0;
				}

				else
				{
					if(tel== 1)
					{
						 move_character(4,8);
						 sim = 1;
						 habilitar = 1;
					}
					else
					{
					 move_character(4,7);
					 sim = 1;
					 habilitar = 1;
					 senhaHabilitada = 0;  //esta habilitada
					}
					 tecla = 0;

				}
			}

			else if(tecla == DOWN)
			{
				if(contserie <= 4)
				{
					aux_senha --;
					if(aux_senha > 9) aux_senha = 9;

					move_character(2,caracter);
					L(aux_senha);
					move_character(2,caracter);
					tecla = 0;
				}
				else
				{
					if(tel== 1)
					{
						move_character(4,11);
						sim = 0;
						habilitar = 0;
					}
					else
					{
						move_character(4,10);
						sim = 0;
						habilitar = 0;
						senhaHabilitada = 1;  // não está habilitada
					}
					 tecla = 0;

				}
			}

			else if(tecla == ENTER)
			{

				if(habilitar == 1)
				{
					if(sim == 1)
					{
						if(tel == 1)
						{
							writeflash(flashdataadr,58,senha);  // salva os dados de calibração
							move_character(3,1);
							L('H'); L('A');L('B'); L('I'); L('L');L('I');L('T'); L('A'); L('R'); L(' ');L('S');L('E');L('N');L('H');;L('A');;L('?');

							clear_line(4);
							move_character(4,7);
							L('S'); L(' '); L(' ');L('N');
							move_character(4,10);

						}
						if(tel == 2)
						{
							if(sim == 1)
							{
								tela = 4;
								senhaHabilitada = 0;  // não está habilitada
							}
							else
							{
								tela = 4;
								senhaHabilitada = 1;  // não está habilitada
							}
						}
						tel ++;
					}
					else
					{
						sim = 0;
					}
				}

				else
				{
					if(contserie > 4)
					{
						tela =4;
						senha = senhaAnt;
					}
				}

				if(salvar == 0)
				{
					if(contserie <= 3)
					{
						senha += aux_senha;
						senha = senha * 10;
						move_character(2,caracter);
						L('*');
						caracter ++;
						move_character(2,caracter);
						tecla = 0;
						contserie ++;
					}

					else
					{
						senha = senha += aux_senha;
						tecla = 0;
						tel = 1;
						contserie ++;
						move_character(3,3);
						L('S'); L('A'); L('L');L('V'); L('A'); L('R'); L(' ');L('S');L('E');L('N');L('H');;L('A');;L('?');
						move_character(4,8);
						L('S'); L(' '); L(' ');L('N');
						//show_cursor(1);
						move_character(4,8);

						salvar = 1;
						habilitar = 1;
					}

				}

				tecla = 0;
			}

			else if(tecla == MENU)
			{
				tela = 4;
				tecla = 0;
			}

		}
}
/************************************************************************************/
void verSenha(void)
{

	 int contserie = 1, caracter = 8;
	 uint16_t aux_senha = 0, pont = 8;

	 uint16_t senha_=0;

	bool senhaok=1;
	//Buzzer_PutVal(0);
	limpa_disp();
	move_character(2,2);
	L('S'); L('e'); L('n');L('h');L('a'); L(':');

	 show_cursor(1);
	while(senhaok)
	{
		if(tela == 90) senhaok = 0;
		if(tecla == UP)
		{
			if(contserie <= 4)
			{
				aux_senha ++;
				if(aux_senha> 9) aux_senha = 0;

				move_character(2,caracter);
				L(aux_senha);
				move_character(2,caracter);

				tecla = 0;
			}


		}

		else if(tecla == DOWN)
		{
			if(contserie <= 4)
			{
				aux_senha --;
				if(aux_senha > 9) aux_senha = 9;

				move_character(2,caracter);
				L(aux_senha);
				move_character(2,caracter);
				tecla = 0;
			}

				 tecla = 0;
		}

		else if(tecla == ENTER)
		{
			if(contserie <= 3)
			{
				senha_ += aux_senha;
				senha_ = senha_ * 10;
				move_character(2,caracter);
				L('*');
				caracter ++;
				move_character(2,caracter);
				tecla = 0;
				contserie ++;
			}

			else
			{
				senha_ = senha_ += aux_senha;
				tecla = 0;
				if(senha_ == senha)
				{
 					tela = 4;
					senhaok = 0;
				}
				else
				{
					 show_cursor(0);
					tela = 100;
				move_character(2,1);
				L('S'); L('e'); L('n');L('h');L('a'); L(' ');L('i'); L('n'); L('c');L('o');L('r'); L('r');L('e');L('t'); L('a'); L('!');
				senhaok = 0;
				delay(2000);
				}
			}
			tecla = 0;
		}

		else if(tecla == MENU)
		{
			tela = 100;
			tecla = 0;
			senhaok = 0;
		}

	}
	 show_cursor(0);

}
void sensors(void)
{
	bool sense=1;
	uint16_t temp,temp1,temp2,temp3,temp_ant;
	limpa_disp();
	linha(1);
	 L('T'); L('E'); L('M');L('P'); L('E'); L('R');L('A'); L('T'); L('U');L('R'); L('A'); L('S');
	 linha(2);
	 L('O'); L('L'); L('E'); L('O');

	 linha(3);
	 L('A'); L('G'); L('U'); L('A');

	 linha(4);
	 L('A');


	 while(sense)
	{
		temp = conversoes_temp(sens_temp_a());

		temp = temp*10;

		temp1 = temp/100;
		temp2 = (temp%100)/10;
		temp3 = (temp%100)%10;

		if(atualiza_med <= 0)
		{
		if(temp != temp_ant){
		 move_character(2,6);
		 L(temp1); L(temp2); L('.'); L(temp3);
		 temp_ant = temp;
		 atualiza_med = 2000;
		}
		}
	}

}
/************************************************************************************/
void configPressOleo(byte sens)  // OLEO SÓ O NOME PODE SER COMBUSTIVEL TAMBÉM
{
	bool conf =1;
	limpa_disp();  // limpa o display
	//show_cursor(0);  // faz o cursor parar de piscar
	 move_character(1,3);  // escreve na linha 1 posição 3
	 if(sens == 1){ L('P'); L('R'); L('E'); L('S'); L('S');L('A'); L('O'); L(' ');L('O'); L('L'); L('E'); L('O');}

	 if(sens == 2){ L('P'); L('R'); L('E'); L('S'); L('S');L('.');L('C'); L('O'); L('M');L('B'); }


	 move_character(2,6);  // escreve na linha 1 posição 3
	 L('V'); L('O'); L('L'); L('T'); L('S');
	 move_character(3,4);  // escreve na linha 1 posição 3
	 L('R'); L('E'); L('S'); L('I'); L('S');L('T'); L('I'); L('V');L('O');

	 //show_cursor(1);// coloca o cursor piscando
	 p_cursor =2;
	 moveSeta(p_cursor,15); // escreve na linha 1 posição 3
	 tecla = 0;

	 while(conf)
	 {
			switch(tecla)  // seleciona qual tecla foi pressionada
			{
				case DOWN :{p_cursor ++; tecla = 0; if(p_cursor > 3) p_cursor =2; moveSeta(p_cursor,15);}break;

				case UP :{p_cursor--; tecla =0; if(p_cursor < 2) p_cursor =3; moveSeta(p_cursor,15);}break;

				case  MENU:{tela = 4;tecla = 0; conf = 0;p_cursor = 6;}break;

				case ENTER:{
					if(p_cursor == 2)
					{
						 tecla = 0;
						clear_line(3);
						 if(sens == 1)
						 {
							 calVolts(1);  // vai calibrar em volts a configurção de oleo
							 pressAlarm(1);  // configura os valores de alarme de pressão para os sensores de pressões
						 }

						 else
						 {
							 calVolts(2);  // vai calibrar em volts a configurção do combustivel
							 pressAlarm(2);  // configura os valores de alarme de pressão para os sensores de pressões
						 }

						 tecla = 0;
						 conf = 0;
					}

					else
					{
						tecla = 0;
						// show_cursor(1);// coloca o cursor piscando
						 if(sens == 1)
						 {
							 pressAlarm(1);  // configura os valores de alarme de pressão para os sensores de pressões
							 oleoPress =1;
							 writeflash(flashdataadr,14,oleoPress);  // salva os dados de calibração
						 }
						 else
						 {
							 pressAlarm(2);  // configura os valores de alarme de pressão para os sensores de pressões
							 combPress =1;
							 writeflash(flashdataadr,15,combPress);  // salva os dados de calibração
						 }
						 move_character(p_cursor,13);  // volta o cursor para o valor de p_cursor para indicar de qual menu ele saiu

					}
					tecla = 0;
					//else calRes();
					 conf = 0;

				}break;
			}

	 }

}
/*********************************************************************************************/
bool calVolts(bool sens)// se a medição do sensor for pressão do oleo sens = 1, se for combustivel = 2.
{
	int volts , pressao = 0;
	byte config =1;
	byte quociente = 0,resto = 0;

	 if(sens == 1)
	 {
		 volts =voltsOleomin/10;
		 quociente = volts/10;
		 resto = volts%10;
	 }
	 else
	 {
		 volts =voltsCombMin/10;
		 quociente = volts/10;
		 resto = volts%10;

	 }
	 //show_cursor(0);
	 move_character(2,15); ;L(' '); //
	 move_character(3,1);  // escreve na linha 1 posição 3
	 L('T'); L('E'); L('N'); L('S'); L('A');L('O'); L(' '); L('M');L('I'); L('N'); L(' '); L(quociente);L('.'); L(resto); L('V');L('<');
	 move_character(4,3);  // escreve na linha 1 posição 3
	 L('P'); L('R'); L('E'); L('S'); L('S');L('A'); L('O');L(' ');L(0);
	 move_character(3,16);
	 tecla = 0;



	 while(config <=3)
	 {
			switch(tecla)  // seleciona qual tecla foi pressionada
			{
				case DOWN : // seta para baixo
				{
					tecla = 0;
					if(config <= 2)   // diminui o set do volts
					{
						volts -=1;
						move_character(3,12);  // escreve na linha 1 posição 3

						if(volts <=0|| volts == 0xFFFF) volts = 0;
						quociente = volts/10;
						resto = volts%10;

						L(quociente); L('.'); L(resto);L('V');
					}

					else  // diminui o set de pressão
					{

						tecla = 0;
						pressao -= 1;

						if(pressao < 0) pressao = 0;  // não deixa o set de pressão ficar negativo

						quociente = pressao/10;
						resto = pressao%10;

						move_character(4,11);  // escreve na linha 1 posição 3
						L(quociente); L(resto);L(' ');

					}


				}break;


				case UP :  // seta para cima
				{
					if(config <= 2)  //aumenta  o set de volts
					{
						volts +=1; tecla =0;

						if(volts <0) volts = 0;

						if(volts > 50) volts = 50;
						quociente = volts/10;
						resto = volts%10;
						move_character(3,12);  // escreve na linha 1 posição 3
						L(quociente); L('.'); L(resto);L('V');
					}

					else// aumenta o set em pressão
					{
						tecla = 0;
						pressao += 1;

						quociente = pressao/10;
						resto = pressao%10;

						move_character(4,11);  // escreve na linha 1 posição 3
						L(quociente); L(resto);L(' ');

					}


				}break;

				case  ENTER:  // aceita os valores setados
				{

					if(config == 1)
					{
						if(sens == 1)
						{
							voltsOleomin = volts*10;  // tensão selacionada para medição em volts correspondente ao óleo minimo
							pressaoOleoMin = 0;  // pressao correspondente ao óleo minimo

							 writeflash(flashdataadr,8,voltsOleomin);  // salva os dados de calibração
						}
						else
						{
							voltsCombMin = volts*10;  // volts correspondente a medida minima em volts para combustível
							pressCombMin = 0;     // pressão minima do combustível

							 writeflash(flashdataadr,9,voltsCombMin);  // salva os dados de calibração
						}

					}

					config ++;tecla = 0;
					if(config == 2)
					{

						 if(sens == 1)
						 {
							 volts =voltsOleoMax/10;
							 quociente = volts/10;
							 resto = volts%10;
							 move_character(3,1);  // escreve na linha 1 posição 3
							 L('T'); L('E'); L('N'); L('S'); L('A');L('O'); L(' '); L('M');L('A'); L('X'); L(' '); L(quociente);L('.'); L(resto); L('V');

							 pressao =pressOleoMax;
							 quociente = pressao/10;
							 resto = pressao%10;

							 move_character(4,11);  // escreve na linha 1 posição 3
							 L(quociente); L(resto);L(' ');

						 }
						 else
						 {
							 volts =voltsCombMax/10;
							 quociente = volts/10;
							 resto = volts%10;

							 move_character(3,1);  // escreve na linha 1 posição 3
							 L('T'); L('E'); L('N'); L('S'); L('A');L('O'); L(' '); L('M');L('A'); L('X'); L(' '); L(quociente);L('.'); L(resto); L('V');

							 pressao = pressCombMax;
							 quociente = pressao/10;
							 resto = pressao%10;

							 move_character(4,11);  // escreve na linha 1 posição 3
							 L(quociente); L(resto);L(' ');
						 }

					}

					if(config == 3)  // apenas muda o cursor para ajustar a pressão correspondente e volts maximo
					{
						move_character(4,11);  // escreve na linha 1 posição 3
					}

					if(config == 4)  // armazena o valor de pressão correspondente ao volts máximo
					{
						if(sens == 1)
						{
							oleoPress = 0;
							voltsOleoMax = volts*10;  // volts correspondente a medida máxima para a medição do óleo
							pressOleoMax = pressao;  // pressão maxima do oleo
							writeflash(flashdataadr,10,voltsOleoMax);  // salva os dados de calibração
							writeflash(flashdataadr,11,pressOleoMax);  // salva os dados de calibração
							writeflash(flashdataadr,14,oleoPress);  // salva os dados de calibração
						}

						else
						{
							combPress =0;  // o modo em vão ser medida  a pressão do combustivel / = 0 medida vai ser em volts
																								// =1 vai ser medido pela tabela resistiva do sensor conforme manual do sensor fornecido pelo fabricante
							voltsCombMax = volts*10;   // volts do combustível máximo
							pressCombMax = pressao;// pressão máxima do combustível

							writeflash(flashdataadr,12,voltsCombMax);  // salva os dados de calibração
							writeflash(flashdataadr,13,pressCombMax);  // salva os dados de calibração
							writeflash(flashdataadr,15,combPress);  // salva os dados de calibração
						}
					}

					if(config == 4)
					{
						move_character(3,16); L(' ');
						move_character(4,16); L('<');
					}

					if(config ==3)
					{
						move_character(3,16); L(' ');
						move_character(4,16); L('<');
					}



				}break;

				case MENU:  // volta para o menu e não salva nada
				{
					tela = 4; tecla =0;
					return 0;;
				}break;
			}
	 }
	// show_cursor(1);
	 return 0;
}
/***********************************************************************************************************/
void pressaoComb(bool modo)  //mede pressão do combustível
{
	uint16_t analog=0,bits;

	uint16_t q,r,qq,rr,volts;

	if(modo == 1)
	{
		analog	= convert_press(pressao_comb());

		combPressao = analog;

		if(tela == 99)
		{
			if(analog <= 99)
			{
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(2, 8);
				L(' '); L(qq); L('.');L(rr);
			}

			else
			{
			// q= (bits/100)/10;
				r= (analog/100)%10;
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(2, 8);
				L(r);L(qq);L('.');L(rr);
			}
		}
	}
	else  // modo =0 medição feita em volts conforme configurado no menu de configuração
	{
		volts = tensao(20);
		//volts = (volts*500)/300;
		//	qwvolts *= 10;

		//analog = (volts*(pressCombMax*10))/voltsCombMax;
		analog = unityPressComb(volts);
		combPressao = analog;

		//analog*=10;
		if(tela == 99)
		{
			if(analog <= 99)
			{
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(2, 8);
				L(' '); L(qq); L('.');L(rr);
			}

			else
			{
				// q= (bits/100)/10;
				r= (analog/100)%10;
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(2, 8);
				L(r);L(qq);L('.');L(rr);
			}
		}
	}
}
/***********************************************************************************************************/
void pressaoOleo(bool modo)
{
	uint16_t analog=0,bits;

	uint16_t q,r,qq,rr,volts;
	//if(!almAgua)
	//{

	if(modo == 1)  // modo =1 medição pela tabela fornecida pelo fabricante do sensor
	{
		analog	= convert_press(pressao_oleo());
		oleoPressao = analog;

		if(tela == 99)
		{
			if(analog <= 99)
			{
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(3, 8);
				L(' '); L(qq); L('.');L(rr);
			}

			else
			{
			// q= (bits/100)/10;
				r= (analog/100)%10;
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(3, 8);
				L(r);L(qq);L('.');L(rr);

			}
		}
	}

	else  // modo =0 medição feita em volts conforme configurado no menu de configuração
	{
		volts = tensao(PRESSAO_OLEO);

		//volts = (volts*500)/300;
		//volts *= 10;

		//analog = (volts*(pressOleoMax*10))/voltsOleoMax;
		analog = unityPressOleo(volts);

		//analog = (volts* pressOleoMax) / voltsOleoMax;

		oleoPressao = analog;
		///analog*=10;
		if(tela == 99)  /// não dixa mostrar no display se não estiver em sua tela
		{
			if(analog <= 99)
			{
				qq= (analog%100)/10;
				rr= (analog%100)%10;
				move_character(3, 8);
				L(' '); L(qq); L('.');L(rr);
			}

			else
				{
				// q= (bits/100)/10;
					r= (analog/100)%10;
					qq= (analog%100)/10;
					rr= (analog%100)%10;
					move_character(3, 8);
					L(r);L(qq);L('.');L(rr);
				}
			}
		}
}
/**********************************************************************************************************/
void temperaturaOleo(bool mode)
{
	uint16_t temp=0;
	byte q,r,qq,rr,qqq;

	temp = conversoes_temp(temp_oleo());
	oleoTemp = temp;
	if(mode == 0)
	{
		temp = temp*18;
		temp += 320;
	}
if(tela == 99)
{
	if(!chupa)
	{
		switch(mode)
		{
			case 0:  // É farenheit
			{
	//if(!engOleoB) {

	//}
				if(temp <= 999)
				{
					if(!chupa)
					{
						r= (temp/100)%10;
						qq= (temp%100)/10;
						rr= (temp%100)%10;
						move_character(1, 10);
						L(' '); L(r);L(qq);L('.');L(rr);
					}
				}

				else
				{
					if(!chupa)
					{
						qqq= (temp/1000);
						r= (temp/100)%10;
						qq= (temp%100)/10;
						rr= (temp%100)%10;
						move_character(1, 10);
						L(qqq); L(r);L(qq);L('.');L(rr);
					}
				}
			}break;

			case 1:
			{
				if(temp <= 99)
				{
					qq= (temp%100)/10;
					rr= (temp%100)%10;
					move_character(1, 12);
					L(' ');L(qq);L(rr);
				}

				else
				{
					r= (temp/100)%10;
					qq= (temp%100)/10;
					rr= (temp%100)%10;
					move_character(1, 12);
					L(r);L(qq);L(rr);
				}
			}break;
		}
	}
}

		//alarmes_(OLEO,temp);
}
/**********************************************************************************************************/
void temperaturaAuxA(bool mode)
{
	byte temp=0;
	byte q,r,qq,rr,qqq;

	temp = conversoes_temp(sens_temp_a());
	TempA = temp;
	if(mode == 0)
	{
		temp = temp*18;
		temp += 320;
	}


	if(tela == 99)
	{
		if((!flag.alarme )&&(mede >= 1050))
		{
			switch(mode)
			{
				case 0:  // É farenheit
				{
					if(temp <= 999)
					{
						r= (temp/100)%10;
						qq= (temp%100)/10;
						rr= (temp%100)%10;
						move_character(4, 10);
						L(' '); L(r);L(qq);L('.');L(rr);
					}

					else
					{
						qqq= (temp/1000);
						r= (temp/100)%10;
						qq= (temp%100)/10;
						rr= (temp%100)%10;
						move_character(4, 10);
						L(qqq); L(r);L(qq);L('.');L(rr);
					}
				}

				case 1:
				{
					if(temp <= 99)
					{
						qq= (temp%100)/10;
						rr= (temp%100)%10;
						move_character(4, 12);
						 L(' ');L(qq);L(rr);
					}

					else
					{
						 r= (temp/100)%10;
						 qq= (temp%100)/10;
						 rr= (temp%100)%10;
						 move_character(4, 12);
						 L(r);L(qq);L(rr);
					}


				}break;
			}
		}
	}
	//alarmes_(TEMPA,temp);
}
/**********************************************************************************************************/
void temperaturaAuxB(bool mode)
{
	uint16_t temp=0;
	byte q,r,qq,rr,qqq;

	temp = conversoes_temp(sens_temp_b());
	TempB = temp;
	if(mode == 0)
	{
		temp = temp*18;
		temp += 320;
	}
if(tela == 101)
{
	//if(!almTempB)
	//{
	switch(mode)
	{
	case 0:  // É farenheit
	{
	//if(!engOleoB) {

	//}
		if(temp <= 999)
		{
			r= (temp/100)%10;
			qq= (temp%100)/10;
			rr= (temp%100)%10;
			move_character(2, 10);
			L(' '); L(r);L(qq);L('.');L(rr);
		}

		else
		{
			qqq= (temp/1000);
			r= (temp/100)%10;
			qq= (temp%100)/10;
			rr= (temp%100)%10;
			move_character(2, 10);
			L(qqq); L(r);L(qq);L('.');L(rr);
		}
	}break;

	case 1:
	{
		if(temp <= 99)
		{
			qq= (temp%100)/10;
			rr= (temp%100)%10;
			move_character(2, 12);
			 L(' ');L(qq);L(rr);
		}

		else
		{
			 r= (temp/100)%10;
			 qq= (temp%100)/10;
			 rr= (temp%100)%10;
			 move_character(2, 12);
			 L(r);L(qq);L(rr);
		}


	}break;
	}
//}
}

	//alarmes_(TEMPB,temp);
}
/**********************************************************************************************************/
void auxAlarmeOleo(bool tipo, uint16_t temp,byte s)
{
	byte q,r,qq,rr,qqq;

	switch(tipo)
	{

	case 0:  // É farenheit
	{

		if(temp <= 999)
		{
			r= (temp/100)%10;
			qq= (temp%100)/10;
			rr= (temp%100)%10;
			if(s== 1)move_character(3, 10);  // sensor agua
			if(s== 2)move_character(1, 10);  // sensor oleo
			if(s== 4)move_character(2, 10);
			L(' '); L(r);L(qq);L('.');L(rr);
		}

		else
		{
			qqq=  (temp/1000);
			r= (temp/100)%10;
			qq= (temp%100)/10;
			rr= (temp%100)%10;
			if(s== 1)move_character(3, 10);  // sensor agua
			if(s== 2)move_character(1, 10);  // sensor oleo
			if(s== 4)move_character(2, 10);
			L(qqq); L(r);L(qq);L('.');L(rr);
		}
	}break;

	case 1:
	{
		if(temp <= 99)
		{
			qq= (temp%100)/10;
			rr= (temp%100)%10;
			if(s== 1)move_character(3, 12);  // sensor agua
			if(s== 2)move_character(1, 12);  // sensor oleo
			if(s== 3)move_character(4, 11);
			if(s== 4)move_character(2, 12);
			 L(' ');L(qq);L(rr);
		}

		else
		{
			 r= (temp/100)%10;
			 qq= (temp%100)/10;
			 rr= (temp%100)%10;
				if(s== 1)move_character(3, 12);  // sensor agua
				if(s== 2)move_character(1, 12);  // sensor oleo
				if(s== 3)move_character(4, 11);
				if(s== 4)move_character(2, 12);
			 L(r);L(qq);L(rr);
		}
	}break;
	}

}
/********************************************************************************************************/
void pressAlarm(byte sensors)
{
	byte config = 1,presion=0;
	byte quociente = 0,resto = 0;
		move_character(2,1);
		L('A');L('L');L('A');L('R');L('M');L('E');L(' ');L('M');L('I');L('N');L('I');L('M');L('O');
		clear_line(3);

		if(sensors ==1)
		{
			presion = pOleomin/10;
			quociente = presion/10;
			resto = presion%10;
		}

		else
		{
			presion = pCombmin/10;
			quociente = presion/10;
			resto = presion%10;

		}
		L('P');L('R');L('E');L('S');L('S');L('A');L('O');L(' ');L(quociente);L(resto);
		clear_line(4);
	while(config <= 2)
	{
		WDog1_Clear();
		switch(tecla)
		{
			case UP:
			{

				tecla = 0;
				presion += 1;

				//if(presion < 0) presion = 0;  // não deixa o set de pressão ficar negativo

				quociente = presion/10;
				resto = presion%10;

				move_character(3,9);  // escreve na linha 1 posição 3
				L(quociente); L(resto);L(' ');
			}break;

			case DOWN:
			{

				tecla = 0;
				presion -= 1;

				if((presion < 0)||(presion == 255)) presion = 0;  // não deixa o set de pressão ficar negativo

				quociente = presion/10;
				resto = presion%10;

				move_character(3,9);  // escreve na linha 1 posição 3
				L(quociente); L(resto);L(' ');
			}break;

			case ENTER:
			{
				tecla = 0;
				if(sensors == 1) // se for oleo
				{
					if(config == 1)
					{
						pOleomin = presion;
						pOleomin = (pOleomin*10);
						writeflash(flashdataadr,42,pOleomin);
						move_character(2,1);
						L('A');L('L');L('A');L('R');L('M');L('E');L(' ');L('M');L('A');L('X');L('I');L('M');L('O');

						presion = pOleomax/10;
						quociente = presion/10;
						resto = presion%10;

						move_character(3,9);  // escreve na linha 1 posição 3
						L(quociente); L(resto);L(' ');


					}
					else
					{
						pOleomax = presion;
						pOleomax = (pOleomax*10);
						writeflash(flashdataadr,43,pOleomax);
					}
				}

				if(sensors == 2) // se for combustivel
				{
					if(config == 1)
					{
						pCombmin = presion;
						pCombmin = pCombmin*10;
						writeflash(flashdataadr,44,pCombmin);
						move_character(2,1);
						L('A');L('L');L('A');L('R');L('M');L('E');L(' ');L('M');L('A');L('X');L('I');L('M');L('O');

						presion = pCombmax/10;
						quociente = presion/10;
						resto = presion%10;

						move_character(3,9);  // escreve na linha 1 posição 3
						L(quociente); L(resto);L(' ');

					}
					else
					{
						pCombmax = presion;
						pCombmax = pCombmax*10;
						writeflash(flashdataadr,45,pCombmax);
					}
				}

				if(sensors == 3) // se for map
				{
					if(config == 1)
					{
						pMapmin = presion;
						pMapmin = pMapmin*10;
						writeflash(flashdataadr,46,pMapmin);
						move_character(2,1);
						L('A');L('L');L('A');L('R');L('M');L('E');L(' ');L('M');L('A');L('X');L('I');L('M');L('O');

					}
					else
					{
						pMapmax = presion;
						pMapmax = pMapmax*10;
						writeflash(flashdataadr,47,pMapmax);
					}
				}

				config ++;

			}break;

			case MENU:
			{
				config = 10;
			}break;

		}
	}
}

