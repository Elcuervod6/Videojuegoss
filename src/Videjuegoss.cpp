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
void rectangle1();
void rectangle2();

int main (){

	uint8_t game_mode= 0;
	hide_cursor();
	srand(time(NULL));

	mode(&game_mode);

switch(game_mode){
	case (1):
		fflush(stdin);
		getchar();
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
	*p_game_mode = 	getch();
	if('1' == *p_game_mode ){
		*p_game_mode = 1;
	}
	}

void select(){
	gotoxy(40,15);
	printf("\t Elija el modo de juego\n\r");
	getchar();
	gotoxy(40,15);
	printf("                                          ");
	gotoxy(30,10);
	printf("\tPulsa 1 para modo individual o pulsa 2 para modo local\n\r");
	rectangle1();
	rectangle2();
}
void rectangle1 (){



	/////////////////////////////////////////////////////////////////////////
		for(uint8_t vertical = 15; vertical<25; vertical++)
			{
			gotoxy(50, vertical);
			printf("%c", 186);
			}

		for(uint8_t vertical2 = 15; vertical2<25; vertical2++)
			{
			gotoxy(20, vertical2);
			printf("%c", 186);
			}
	//////////////////////////////////////////////////////////////////////////////
		for(uint8_t horizontal = 20; horizontal<50; horizontal++)
			{
			gotoxy( horizontal, 15);
			printf("%c", 205);
			}

		for(uint8_t horizontal2 = 20; horizontal2<50; horizontal2++)
			{
			gotoxy(horizontal2, 25);
			printf("%c", 205);
			}
		gotoxy(50, 15);
		printf("%c", 187);
		gotoxy(50, 25);
		printf("%c", 188);
		gotoxy(20, 15);
		printf("%c", 201);
		gotoxy(20, 25);
		printf("%c", 200);

		gotoxy(35,19);
		printf("%c", 186);
		gotoxy(34,20);
		printf("%c%c%c", 204, 206, 185);

		gotoxy(33,20);
		printf("*");
		gotoxy(25,16);
		printf("*");
		gotoxy(40,19);
		printf("*");
		gotoxy(35,10);
		printf("*");
		gotoxy(25,16);
		printf("*");
		gotoxy(45,22);
		printf("*");
		gotoxy(22,24);
		printf("*");


		gotoxy(35, 18);
		printf("%c", 250);
}
void rectangle2 (){



	/////////////////////////////////////////////////////////////////////////
		for(uint8_t vertical = 15; vertical<25; vertical++)
			{
			gotoxy(100, vertical);
			printf("%c", 186);
			}

		for(uint8_t vertical2 = 15; vertical2<25; vertical2++)
			{
			gotoxy(70, vertical2);
			printf("%c", 186);
			}
	//////////////////////////////////////////////////////////////////////////////
		for(uint8_t horizontal = 70; horizontal<100; horizontal++)
			{
			gotoxy( horizontal, 15);
			printf("%c", 205);
			}

		for(uint8_t horizontal2 = 70; horizontal2<100; horizontal2++)
			{
			gotoxy(horizontal2, 25);
			printf("%c", 205);
			}
		gotoxy(100, 15);
		printf("%c", 187);
		gotoxy(100, 25);
		printf("%c", 188);
		gotoxy(70, 15);
		printf("%c", 201);
		gotoxy(70, 25);
		printf("%c", 200);

		gotoxy(85,17);
		printf("%c", 186);
		gotoxy(84,16);
		printf("%c%c%c", 204, 206, 185);

		gotoxy(75,23);
		printf("%c", 186);
		gotoxy(74,24);
		printf("%c%c%c", 204, 206, 185);

		gotoxy(75, 16);
		printf("%c", 250);

		gotoxy(85, 18);
		printf("%c", 250);
}
void printfnave(uint8_t centro_x, uint8_t centro_y){
	gotoxy(centro_x,centro_y-1);
	printf("%c", 186);
	gotoxy(centro_x-1,centro_y);
	printf("%c%c%c", 204, 202, 185);
}

