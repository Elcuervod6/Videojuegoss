#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <windows.h>
#include <time.h>



void gotoxy(uint8_t x,uint8_t y);
void hide_cursor(void);
void resize_console(uint8_t hight, uint8_t width);
void hide_cursor(void);
void mode(uint8_t *p_game_mode);
void select();
void nave();
int main (){

	uint8_t game_mode= 0;
	hide_cursor();
	srand(time(NULL));
	resize_console(61, 61);
	mode(&game_mode);

switch(game_mode){
	case (1):
		resize_console(61, 61);
		nave();
	}
//	case (2):
//
}


void resize_console(uint8_t hight, uint8_t width){
	SMALL_RECT windowSize = {0, 0, (SHORT) (width - 1), (SHORT) (hight - 1)};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &windowSize);
	COORD bufferSize = {SHORT(width), SHORT(hight + 1)};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
}
void hide_cursor(void)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void gotoxy(uint8_t x,uint8_t y){
	COORD pos;

	pos.X = int(x);
	pos.Y = int(y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void mode(uint8_t *p_game_mode){
	select();
	if('1' == getch() ){
			*p_game_mode = 1;
		}
	if('2' == getch() ){
		*p_game_mode = 2;
	}
}
void select(){
	printf("\t Elija el modo de juego\n\r");
	getchar();
	printf("\tPulsa 1 para modo individual o pulsa dos para modo coperativo\n\r");
	getch();
}
void nave(){

}
