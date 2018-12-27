/*
 * display.h
 *
 *  Created on: 03/08/2018
 *      Author: Rosimar
 */

#ifndef SOURCES_DISPLAY_H_
#define SOURCES_DISPLAY_H_


void display_init(void);
void reseta_saidas_lcd(void);
void limpa_disp(void);  // limpa todo display
//void move_character(byte linha, byte coluna);
void lcd_write(void); // coloca o lcd do modo de escrita
void criaLambda(void);
void L(char letra);
void lcd_write(void) ;
void escreve_lcd(void); // da um pulso para escrever no display
//void moveSeta(byte linha, byte coluna);
void textIput(char sensor);
char a,b,c,d,e,f,g,h;

int atualiza_med;

struct
{
	int almAgua:1;
}alarme;



#endif /* SOURCES_DISPLAY_H_ */
