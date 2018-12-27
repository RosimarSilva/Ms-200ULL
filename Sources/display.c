/*
 * display.c
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#include "display.h"
#include "main.h"
#include "auxiliar.h"
#include "dadosFlash.h"

//uint16_t a,b,c,d,e,f,g,h;


void display_init(void) // inicializa o display
{
	// limpa o display
	LCD_0_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	delay(2);
	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	//vai para o cursor home
	LCD_1_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	delay(2);

	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	//fixa o modo de operação
	LCD_2_PutVal(1); LCD_1_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	//controle do display
	LCD_3_PutVal(1); LCD_2_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	//deslocamento do cursor ou da mensagem
	LCD_4_PutVal(1); LCD_2_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	//estabelece o modo de utilizaçãodo módulo lcd
	LCD_5_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

}

/*******************************************************************/
void reseta_saidas_lcd(void) // coloca o lcd em modo comando
{
	Lcd_RS_PutVal(0);  Lcd_RW_PutVal(0);

	LCD_0_PutVal(0);   LCD_1_PutVal(0); LCD_2_PutVal(0);   LCD_3_PutVal(0);

	LCD_4_PutVal(0);   LCD_5_PutVal(0); LCD_6_PutVal(0);   LCD_7_PutVal(0);

}
/*********************************************************************************/
void lcd_write(void)  // coloca o lcd do modo de escrita
{
	Lcd_RS_PutVal(1);  Lcd_RW_PutVal(0);

	LCD_0_PutVal(0);   LCD_1_PutVal(0); LCD_2_PutVal(0);   LCD_3_PutVal(0);

	LCD_4_PutVal(0);   LCD_5_PutVal(0); LCD_6_PutVal(0);   LCD_7_PutVal(0);

}
/******************************************************************************/
void show_cursor(bool enable)  // exibe o cursor do display
{
	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	if(enable)
	{
		//controle do display, coloca o display em um modo que o cursor fique exposto sem piscar
		LCD_3_PutVal(1); LCD_2_PutVal(1); LCD_1_PutVal(1);LCD_0_PutVal(1);

		Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);
	}

	else
	{
		//controle do display, apaga o cursor
		LCD_3_PutVal(1); LCD_2_PutVal(1);

		Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);

	}
}
/******************************************************************************/
void posiciona_cursor(byte coluna) // manda o cursor para algum lugar selecionado
{
	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando



	if(coluna == 1)
	{
		LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);

		Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);
	}

	if(coluna == 2)
	{
		LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1);  LCD_0_PutVal(1);

		Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);
	}

	if(coluna == 3)
	{
		LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1);  LCD_1_PutVal(1); LCD_0_PutVal(1);

		Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);
	}
}
/***********************************************************************************************************/
void limpa_disp(void)  /// limpa o display
{
	reseta_saidas_lcd(); // coloca todos os pinos em nível lógico baixo e coloca o lcd em modo de comando

	LCD_0_PutVal(1);

	Lcd_E_PutVal(1); delay(50); Lcd_E_PutVal(0);
}
/******************************************************************************/
void L(char letra) // Função que escreve os textos no display
{
	lcd_write(); // coloca o lcd do modo de escrita

	switch(letra){

	case 'A':{  LCD_6_PutVal(1); LCD_0_PutVal(1);} break;

		case 'B': {  LCD_6_PutVal(1); LCD_1_PutVal(1);} break;

	case 'C':{  LCD_6_PutVal(1);  LCD_1_PutVal(1); LCD_0_PutVal(1);} break;

		case 'D':{  LCD_6_PutVal(1); LCD_2_PutVal(1); } break;

	case 'E':{  LCD_6_PutVal(1); LCD_2_PutVal(1);     LCD_0_PutVal(1);} break;

		case 'F':{  LCD_6_PutVal(1); LCD_2_PutVal(1);  LCD_1_PutVal(1); } break;

	case 'G':{  LCD_6_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1);LCD_0_PutVal(1); } break;

		case 'H':{  LCD_6_PutVal(1); LCD_3_PutVal(1);} break;

	case 'I':{  LCD_6_PutVal(1); LCD_3_PutVal(1);  LCD_0_PutVal(1); } break;

		case 'J':{  LCD_6_PutVal(1); LCD_3_PutVal(1); LCD_1_PutVal(1);       } break;

	case 'K':{  LCD_6_PutVal(1);  LCD_3_PutVal(1);  LCD_1_PutVal(1); LCD_0_PutVal(1); } break;

		case 'L':{  LCD_6_PutVal(1);   LCD_3_PutVal(1); LCD_2_PutVal(1);   } break;

	case 'M':{  LCD_6_PutVal(1); LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_0_PutVal(1); } break;

		case 'N':{ LCD_6_PutVal(1); LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1);} break;

	case 'O':{   LCD_6_PutVal(1); LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1);  LCD_0_PutVal(1);} break;

		case 'P':{  LCD_6_PutVal(1); LCD_4_PutVal(1);} break;

	case 'Q':{  LCD_6_PutVal(1); LCD_4_PutVal(1); LCD_0_PutVal(1);} break;

		case 'R':{  LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_1_PutVal(1);} break;

	case 'S':{  LCD_6_PutVal(1);  LCD_4_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);} break;

		case 'T':{  LCD_6_PutVal(1); LCD_4_PutVal(1); LCD_2_PutVal(1);} break;

	case 'U':{  LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_2_PutVal(1); LCD_0_PutVal(1);} break;

		case 'V':{  LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_2_PutVal(1); LCD_1_PutVal(1);} break;

	case 'X':{  LCD_6_PutVal(1); LCD_4_PutVal(1);  LCD_3_PutVal(1);} break;

		case 'Z':{  LCD_6_PutVal(1); LCD_4_PutVal(1);  LCD_3_PutVal(1);  LCD_1_PutVal(1);} break;

	case 'W':{  LCD_6_PutVal(1); LCD_4_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1);  LCD_0_PutVal(1);} break;

		case 'Y':{  LCD_6_PutVal(1); LCD_4_PutVal(1);  LCD_3_PutVal(1);LCD_0_PutVal(1); } break;

	// LETRAS MINUSCULAS

	case 'a':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_0_PutVal(1);  } break;

		case 'b':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_1_PutVal(1);} break;

	case 'c':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_1_PutVal(1);LCD_0_PutVal(1);} break;// 01101111

		case 'd':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_2_PutVal(1);} break;

	case 'e':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_2_PutVal(1);   LCD_0_PutVal(1); } break;

	case 'f':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_2_PutVal(1);   LCD_1_PutVal(1); } break;

		case 'g':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_2_PutVal(1); LCD_1_PutVal(1);LCD_0_PutVal(1);} break;// 01101111

	case 'h':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1); } break;

		case 'i':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1); LCD_0_PutVal(1);} break;// 01101111

		case 'j':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1); LCD_1_PutVal(1);} break;// 01101111

		case 'k':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);} break;// 01101111

		case 'l':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1); LCD_2_PutVal(1);} break;// 01101111

	case 'm':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_0_PutVal(1); } break;

	case 'n':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1); } break;

		case 'o':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);} break;// 01101111

	case 'p':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1);} break;

	case 'q':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1);LCD_0_PutVal(1);} break;

		case 'r':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1);   LCD_1_PutVal(1);} break;

	case 's':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1);   LCD_1_PutVal(1); LCD_0_PutVal(1);} break;

	case 't':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1);   LCD_2_PutVal(1); } break;

	case 'u':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_2_PutVal(1);LCD_0_PutVal(1);} break;// 01101111

		case 'v':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_2_PutVal(1);LCD_1_PutVal(1);} break;// 01101111

		case 'x':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_3_PutVal(1);} break;// 01101111

		case 'z':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);} break;// 01101111

		case 'w':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);} break;// 01101111

		case 'y':{  LCD_6_PutVal(1); LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);} break;// 01101111



		// CARACTERES ESPECIAIS
		case ' ':{  LCD_5_PutVal(1);   } break;

			case '-':{  LCD_5_PutVal(1);   LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_0_PutVal(1); } break;


		case ':':{  LCD_5_PutVal(1);   LCD_4_PutVal(1);  LCD_3_PutVal(1);  LCD_1_PutVal(1); } break;

			case '.':{  LCD_5_PutVal(1);   LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1); } break;

		case ',':{  LCD_5_PutVal(1);   LCD_3_PutVal(1);  LCD_2_PutVal(1);  } break;

			case '/':{  LCD_5_PutVal(1);   LCD_3_PutVal(1);  LCD_2_PutVal(1);  LCD_1_PutVal(1);  LCD_0_PutVal(1); } break;

		case '!':{  LCD_5_PutVal(1);   LCD_0_PutVal(1); } break;

			case '°':{ LCD_7_PutVal(1);    LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1); } break;

		case '?':{   LCD_5_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1); } break;

			case '<':{  LCD_6_PutVal(1); LCD_5_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1); } break;

		case '%':{  LCD_5_PutVal(1);   LCD_2_PutVal(1);  LCD_0_PutVal(1); } break;
		// NÚMEROS

		case '´':{  LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1); } break;

			case '*':{  LCD_5_PutVal(1); LCD_3_PutVal(1); LCD_1_PutVal(1); } break;


		case 1:{  LCD_5_PutVal(1);  LCD_4_PutVal(1);  LCD_0_PutVal(1);   } break;

			case 0:{  LCD_5_PutVal(1);  LCD_4_PutVal(1); } break;

		case 2:{  LCD_5_PutVal(1);  LCD_4_PutVal(1);  LCD_1_PutVal(1);   } break;

			case 3:{  LCD_5_PutVal(1);  LCD_4_PutVal(1);  LCD_1_PutVal(1);  LCD_0_PutVal(1);} break;

		case 4:{  LCD_5_PutVal(1);  LCD_4_PutVal(1);  LCD_2_PutVal(1);   } break;

			case 5:{  LCD_5_PutVal(1);  LCD_4_PutVal(1);  LCD_2_PutVal(1);  LCD_0_PutVal(1);} break;

		case 6:{  LCD_5_PutVal(1);  LCD_4_PutVal(1);  LCD_2_PutVal(1); LCD_1_PutVal(1);  } break;

			case 7:{  LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_2_PutVal(1);  LCD_1_PutVal(1);  LCD_0_PutVal(1);} break;

		case 8:{  LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_3_PutVal(1);} break;

			case 9:{  LCD_5_PutVal(1);  LCD_4_PutVal(1); LCD_3_PutVal(1);  LCD_0_PutVal(1); } break;

	}

			escreve_lcd();

}
/*******************************************************************************/
void escreve_lcd(void) // da um pulso para escrever no display
{
	Lcd_E_PutVal(1);delay(2); Lcd_E_PutVal(0);
}
/*******************************************************************************/
void linha(byte linha)
{
	reseta_saidas_lcd();

	if(linha==2){LCD_7_PutVal(1);  LCD_6_PutVal(1);      Lcd_E_PutVal(1); delay(20); Lcd_E_PutVal(0); delay(2);}

	if(linha == 1){LCD_7_PutVal(1);  Lcd_E_PutVal(1); delay(20); Lcd_E_PutVal(0); delay(2);}

	if(linha == 3){LCD_7_PutVal(1);LCD_4_PutVal(1);  Lcd_E_PutVal(1); delay(20); Lcd_E_PutVal(0); delay(2);}

	if(linha == 4){LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);  Lcd_E_PutVal(1); delay(20); Lcd_E_PutVal(0); delay(2);}
}
/************************************************************************************/
void move_endline(byte line)
{
	reseta_saidas_lcd();
	if(line == 1)  // vá para o final da linha 1
	{
		LCD_7_PutVal(1);LCD_3_PutVal(1); LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  Lcd_E_PutVal(1); delay(20); Lcd_E_PutVal(0); delay(2);
	}

	else
	{
		LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1); LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  Lcd_E_PutVal(1); delay(20); Lcd_E_PutVal(0); delay(2);
	}
}
/*****************************************************************************************/
void move_character(byte linha, byte coluna)
{
	reseta_saidas_lcd();
	switch(linha)
	{
		case 1:
		{
			if(coluna == 1){ LCD_7_PutVal(1);  escreve_lcd();} // 80H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//81H

			if(coluna == 3) {LCD_7_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//82H

			if(coluna == 4){ LCD_7_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//83H

			if(coluna == 5){ LCD_7_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//84H

			if(coluna == 6){ LCD_7_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//85H

			if(coluna == 7) {LCD_7_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//86H

			if(coluna == 8) {LCD_7_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//87

			if(coluna == 9) {LCD_7_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// 88H

			if(coluna == 10){ LCD_7_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//89H

			if(coluna == 11) {LCD_7_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//8AH

			if(coluna == 12) {LCD_7_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//8BH

			if(coluna == 13) {LCD_7_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//8CH

			if(coluna == 14) {LCD_7_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//8DH

			if(coluna == 15) {LCD_7_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//8EH

			if(coluna == 16) {LCD_7_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//8F
		}break;
		/*****************************************************************************************************************************/
		case 2:
		case 5:
		case 8:
		{
			if(coluna == 1){ LCD_7_PutVal(1); LCD_6_PutVal(1); escreve_lcd();} // C0H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//C1H

			if(coluna == 3){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//C2H

			if(coluna == 4){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//C3H

			if(coluna == 5) {LCD_7_PutVal(1);LCD_6_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//C4H

			if(coluna == 6){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//C5H

			if(coluna == 7) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//C6H

			if(coluna == 8) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//C7

			if(coluna == 9){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// C8H

			if(coluna == 10){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//C9H

			if(coluna == 11){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//CAH

			if(coluna == 12){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//CBH

			if(coluna == 13){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//CCH

			if(coluna == 14) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//CDH

			if(coluna == 15){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//CEH

			if(coluna == 16){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//CF

		}break;
		/****************************************************************************************************************************************/
		case 3:
		case 6:
		case 9:
		{
			if(coluna == 1){ LCD_7_PutVal(1); LCD_4_PutVal(1);  escreve_lcd();} // 90H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//91H

			if(coluna == 3){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//92H

			if(coluna == 4){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//93H

			if(coluna == 5){ LCD_7_PutVal(1); LCD_4_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//94H

			if(coluna == 6){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//95H

			if(coluna == 7) {LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//96H

			if(coluna == 8){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//97

			if(coluna == 9){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// 98H

			if(coluna == 10){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//99H

			if(coluna == 11){ LCD_7_PutVal(1);  LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//9AH

			if(coluna == 12){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//9BH

			if(coluna == 13) {LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//9CH

			if(coluna == 14){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//9DH

			if(coluna == 15) {LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//9EH

			if(coluna == 16){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//9F
		}break;
			/*********************************************************************************************************************************************/
		case 4:
		case 7:
		case 10:
		{
			if(coluna == 1){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1); escreve_lcd();} // D0H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D1H

			if(coluna == 3){ LCD_7_PutVal(1); LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//D2H

			if(coluna == 4) {LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//D3H

			if(coluna == 5){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//C4H

			if(coluna == 6){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D5H

			if(coluna == 7){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//D6H

			if(coluna == 8){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D7

			if(coluna == 9) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// D8H

			if(coluna == 10){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D9H

			if(coluna == 11){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//DAH

			if(coluna == 12) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//DBH

			if(coluna == 13) {LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//DCH

			if(coluna == 14){LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//DDH

			if(coluna == 15) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//DEH

			if(coluna == 16){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//DF

		}break;
	}

}
/************************************************************************************************************************************************************************/
void clear_line(byte line)
{
	reseta_saidas_lcd();

	switch(line)
	{
		case 1:
		{
			linha(1);
			 L(' '); L(' '); L(' '); L(' ');  L(' ');L(' ');  L(' '); L(' ');L(' ');L(' '); L(' '); L(' ');L(' '); L(' '); L(' ');L(' ');

			 linha(1);
		}break;

		case 2:
		{
			linha(2);
			 L(' '); L(' '); L(' '); L(' ');  L(' ');L(' ');  L(' '); L(' ');L(' ');L(' '); L(' '); L(' ');L(' '); L(' '); L(' ');L(' ');
			 linha(2);
		}break;

		case 3:
		{
			linha(3);
			 L(' '); L(' '); L(' '); L(' ');  L(' ');L(' ');  L(' '); L(' ');L(' ');L(' '); L(' '); L(' ');L(' '); L(' '); L(' ');L(' ');
			 linha(3);
		}break;

		case 4:
		{
			linha(4);
			 L(' '); L(' '); L(' '); L(' ');  L(' ');L(' ');  L(' '); L(' ');L(' ');L(' '); L(' '); L(' ');L(' '); L(' '); L(' ');L(' ');
			 linha(4);
		}break;


	}
}
/************************************************************************************************************************************************************************/
void scrool_menu(byte  indice)
{
	switch(indice)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		{
			/*limpa_disp();
			linha(1);
			 L('M'); L('E'); L('N');  L('U'); L(' '); L('C'); L('O');   L('N'); L('F');  L('I');  L('G');   L('.'); L(' '); L(' '); L(' '); L(' ');  L(' ');L(' ');  L(' ');*/

			clear_line(2);
			 L('C'); L('O'); L('N');  L('F');  L('.');   L('O'); L('D');  L('O');  L('M');   L('E');  L('T');  L('R');  L('O');
			 clear_line(3);
			  L('V'); L('E'); L('L'); L('O');L('C'); L('I'); L('M'); L('E'); L('T'); L('R');  L('O');
			  clear_line(4);
			 L('N'); L('I'); L('V'); L('E');  L('L');L(' ');L('T'); L('A'); L('N');L('Q'); L('U'); L('E');

		}break;


		case 5:
		case 6:
		case 7:
		{

			clear_line(2);
			L('C'); L('O'); L('N');  L('F'); L('I'); L('G'); L('.');   L('R'); L('P');  L('M');
			clear_line(3);
			L('S'); L('E'); L('N'); L('S');  L('.');  L('P'); L('R');L('E'); L('S'); L('S');L('A'); L('O');
			clear_line(4);
			L('S'); L('E'); L('N'); L('S');  L('.');  L('T'); L('E'); L('M'); L('P');

		}break;

		case 8:
		case 9:
		case 10:
		{

			//clear_line(2);
			//L('S'); L('O'); L('N');  L('D'); L('A'); L(' '); L('L');   L('A'); L('M');  L('B'); L('D');  L('A');
			clear_line(2);
			L('C'); L('A'); L('L'); L('E');  L('D');  L('A'); L('R'); L('I');  L('O');
			clear_line(3);
			L('S'); L('E'); L('N'); L('H');  L('A');  L('S');
			clear_line(4);

		}break;

	}
}

/*****************************************************************************************/
void moveSeta(byte linha, byte coluna)
{
	reseta_saidas_lcd();
	switch(linha)
	{
		case 1:
		{
			if(coluna == 1){ LCD_7_PutVal(1);  escreve_lcd();} // 80H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//81H

			if(coluna == 3) {LCD_7_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//82H

			if(coluna == 4){ LCD_7_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//83H

			if(coluna == 5){ LCD_7_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//84H

			if(coluna == 6){ LCD_7_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//85H

			if(coluna == 7) {LCD_7_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//86H

			if(coluna == 8) {LCD_7_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//87

			if(coluna == 9) {LCD_7_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// 88H

			if(coluna == 10){ LCD_7_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//89H

			if(coluna == 11) {LCD_7_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//8AH

			if(coluna == 12) {LCD_7_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//8BH

			if(coluna == 13) {LCD_7_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//8CH

			if(coluna == 14) {LCD_7_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//8DH

			if(coluna == 15) {LCD_7_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//8EH

			if(coluna == 16) {LCD_7_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//8F
		}break;
		/*****************************************************************************************************************************/
		case 2:
		case 5:
		case 8:
		{
			if(coluna == 1){ LCD_7_PutVal(1); LCD_6_PutVal(1); escreve_lcd();} // C0H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//C1H

			if(coluna == 3){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//C2H

			if(coluna == 4){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//C3H

			if(coluna == 5) {LCD_7_PutVal(1);LCD_6_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//C4H

			if(coluna == 6){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//C5H

			if(coluna == 7) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//C6H

			if(coluna == 8) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//C7

			if(coluna == 9){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// C8H

			if(coluna == 10){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//C9H

			if(coluna == 11){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//CAH

			if(coluna == 12){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//CBH

			if(coluna == 13){ LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//CCH

			if(coluna == 14) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//CDH

			if(coluna == 15){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//CEH

			if(coluna == 16){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//CF

		}break;
		/****************************************************************************************************************************************/
		case 3:
		case 6:
		case 9:
		{
			if(coluna == 1){ LCD_7_PutVal(1); LCD_4_PutVal(1);  escreve_lcd();} // 90H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//91H

			if(coluna == 3){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//92H

			if(coluna == 4){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//93H

			if(coluna == 5){ LCD_7_PutVal(1); LCD_4_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//94H

			if(coluna == 6){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//95H

			if(coluna == 7) {LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//96H

			if(coluna == 8){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//97

			if(coluna == 9){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// 98H

			if(coluna == 10){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//99H

			if(coluna == 11){ LCD_7_PutVal(1);  LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//9AH

			if(coluna == 12){ LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//9BH

			if(coluna == 13) {LCD_7_PutVal(1); LCD_4_PutVal(1); LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//9CH

			if(coluna == 14){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//9DH

			if(coluna == 15) {LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//9EH

			if(coluna == 16){ LCD_7_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//9F
		}break;
			/*********************************************************************************************************************************************/
		case 4:
		case 7:
		case 10:
		{
			if(coluna == 1){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1); escreve_lcd();} // D0H

			if(coluna == 2){ LCD_7_PutVal(1); LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D1H

			if(coluna == 3){ LCD_7_PutVal(1); LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_1_PutVal(1);  escreve_lcd();}//D2H

			if(coluna == 4) {LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//D3H

			if(coluna == 5){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);  LCD_2_PutVal(1); escreve_lcd();}//C4H

			if(coluna == 6){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D5H

			if(coluna == 7){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//D6H

			if(coluna == 8){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D7

			if(coluna == 9) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);  escreve_lcd(); }// D8H

			if(coluna == 10){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//D9H

			if(coluna == 11){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//DAH

			if(coluna == 12) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1); LCD_3_PutVal(1);LCD_1_PutVal(1); LCD_0_PutVal(1);  escreve_lcd();}//DBH

			if(coluna == 13) {LCD_7_PutVal(1);LCD_6_PutVal(1); LCD_4_PutVal(1);LCD_3_PutVal(1); LCD_2_PutVal(1); escreve_lcd();}//DCH

			if(coluna == 14){LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//DDH

			if(coluna == 15) {LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);  escreve_lcd();}//DEH

			if(coluna == 16){ LCD_7_PutVal(1);LCD_6_PutVal(1);LCD_4_PutVal(1);LCD_3_PutVal(1);LCD_2_PutVal(1);LCD_1_PutVal(1);LCD_0_PutVal(1);  escreve_lcd();}//DF

		}break;
	}

	//move_character(linha,coluna); L('<');


		for(int i = 1; i<= 4; ++i)
		{
			if(i != linha)
			{
				move_character(i,coluna);
				L(' ');
			}
		}


	move_character(linha,coluna); L('<');
}
/************************************************************************************************************************************************************************/
void textIput(char sensor)
{
	char letra = 0x41;
	byte colun=5;
	bool text = 1;

	//move_character(3,1);
	clear_line(3);
	L('N'); L('O'); L('M'); L('E'); L(' '); L('S'); L('E'); L('N'); L('S'); L('O'); L('R');

	move_character(4,5);
	L(letra);
	tecla=0;
	while(text <= 4)
	{
		 WDog1_Clear();
		if(tecla)
		{
			switch(tecla)
			{
				case UP:
				{
					letra ++;
					if(letra == 0x5B) letra = 0x61;
					if(letra == 0x7A) letra = 0x00;
					if(letra == 0x0A) letra = 0x41;
					move_character(4,colun);
					L(letra);
					tecla = 0;
				}break;

				case DOWN:
				{
					letra --;
					if(letra == 0x60) letra = 0x5A;
					if(letra == 0x40) letra = 0x09;
					if(letra < 0) letra = 0x7A;
					move_character(4,colun);
					L(letra);
					tecla = 0;
				}break;

				case ENTER:
				{
					if(sensor == 'A')
					{
						if(text == 1) {
							a=letra;writeflash(flashdataadr,25,a);
						}
						if(text == 2) {
							b=letra;writeflash(flashdataadr,26,b);
						}
						if(text == 3) {
							c=letra;writeflash(flashdataadr,27,c);
						}
						if(text == 4) {
							d=letra;writeflash(flashdataadr,28,d);
						}
					}

					else
					{
						if(text == 1) {e=letra;writeflash(flashdataadr,29,e);}
						if(text == 2) {f=letra;writeflash(flashdataadr,30,f);}
						if(text == 3) {g=letra;writeflash(flashdataadr,31,g);}
						if(text == 4) {h=letra;writeflash(flashdataadr,32,h);}

					}

					text++;
					move_character(4,++colun);
					if(text != 6)L(letra);
					tecla = 0;

				}break;

				case MENU:
				{

					text--;
					if(text<1) text =1;
					move_character(4,colun);
					L(' ');
					--colun;
					if(colun < 5) colun=5;
					//if(colun < 5) text = 6;
					move_character(4,colun);
					tecla = 0;
				}break;


			}
		}
	}
}




