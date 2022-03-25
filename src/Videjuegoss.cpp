#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX_ALTO 20
#define Max_largo 80

#define LIMIT_RIGHT 79
#define LIMIT_DOWN 19
#define LIMIT_UP 1
#define LIMIT_LEFT 1

#define HALF_X 40
#define HALF_Y 100
#define LONG_M 5

void gotoxy(uint8_t x,uint8_t y);
void hide_cursor(void);
void resize_console(uint8_t hight, uint8_t width);
void hide_cursor(void);
void rectangle ();
void wall1 (uint8_t *p_wallx1,uint8_t *p_wally1,uint8_t *p_wall1_f,uint8_t long_m,uint8_t rectangle);
void wall2 (uint8_t *p_wallx2,uint8_t *p_wally2,uint8_t *p_wall2_f,uint8_t long_m,uint8_t rectangle);
void w_random_simbol(uint8_t *p_randomy, uint8_t *p_randomx);
void randoms(uint8_t *wally1,uint8_t *wally2 );
void write_sim(uint8_t *o_x, uint8_t *o_y);
void o_move_two(uint8_t randomx, uint8_t randomy,uint8_t *o_x, uint8_t *o_y, uint8_t wall1, uint8_t wall2);
bool test_wall1 (uint8_t o_x,uint8_t o_y,uint8_t wallx1,uint8_t wally1, uint8_t long_m);
bool test_wall2 (uint8_t o_x,uint8_t o_y,uint8_t wallx2,uint8_t wally2, uint8_t long_m);
bool win ( uint8_t *o_y, uint8_t *o_x, uint8_t randomy, uint8_t randomx);
void o_desplace (uint8_t *o_x, uint8_t *o_y);
void o_move(uint8_t randomx, uint8_t randomy,uint8_t *o_x, uint8_t *o_y, uint8_t wall1, uint8_t wall2);
void ready (void);
void win_song(void);
void you_lose__song(void);



int main (){

 	uint8_t randomy = 0;
	uint8_t randomx = 0;
	uint8_t wallx1 = 0;
	uint8_t wallx2 = 0;
	uint8_t wally1 = 0;
	uint8_t wally2 = 0;
	uint8_t o_x = 0;
	uint8_t o_y = 0;
	uint8_t wall1_f = 0;
	uint8_t wall2_f = 0;
	bool gg = false;
	bool finish = false;


	hide_cursor();
	srand(time(NULL));
	resize_console(21, 81);
	randoms( &wally1, &wally2);
	rectangle();
	wall1(&wallx1, &wally1,&wall1_f, LONG_M, LIMIT_RIGHT);
	wall2(&wallx2, &wally2,&wall2_f, LONG_M, LIMIT_RIGHT);
	write_sim(&o_x, &o_y);
	w_random_simbol(&randomy, &randomx);
	ready();


////////////////////////////////////////////////////////////////////////////////////////////
	while( 1== 1){

	o_move(randomx, randomy, &o_x, &o_y, wallx1, wallx2);
	if(true == win(&o_y, & o_x, randomy, randomx)){
		gg= true;
		break;
	}
	if(true == test_wall1(o_x, o_y, wallx1, wally1, LONG_M)){
		finish= true;
		break;
	}
	if(true == test_wall2(o_x, o_y, wallx2, wally2, LONG_M)){
		finish= true;
		break;
		}
	}

	if(true == gg){
		Beep(750, 800);
		w_random_simbol(&randomy, &randomx);
		while( 1== 1){

			o_move_two(randomx, randomy, &o_x, &o_y, wallx1, wallx2);
			if(true == win(&o_y, & o_x, randomy, randomx)){
				gg= true;
				break;
			}
			if(true == test_wall1(o_x, o_y, wallx1, wally1, LONG_M)){
				finish= true;
				break;
			}
			if(true == test_wall2(o_x, o_y, wallx2, wally2, LONG_M)){
				finish= true;
				break;
				}
			}

	}
	if(true == gg){
		gotoxy(35, 10);
		printf("gg");
		win_song();

				}
	if(true == finish){
		gotoxy(35, 10);
		printf("Try Again");
		you_lose__song();
		}

getchar();
}
//////////////////////////////////////////////////////////////////////////////////////////////////




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

void rectangle (){
		gotoxy(Max_largo, 0);
		printf("%c", 187);
		gotoxy(Max_largo, MAX_ALTO);
		printf("%c", 188);
		gotoxy(0, 0);
		printf("%c", 201);
		gotoxy(0, MAX_ALTO);
		printf("%c", 200);

	/////////////////////////////////////////////////////////////////////////
		for(uint8_t vertical = 1; vertical<MAX_ALTO; vertical++)
			{
			gotoxy( 0, vertical);
			printf("%c", 186);
			}

		for(uint8_t vertical2 = 1; vertical2<MAX_ALTO; vertical2++)
			{
			gotoxy(Max_largo, vertical2);
			printf("%c", 186);
			}
	//////////////////////////////////////////////////////////////////////////////
		for(uint8_t horizontal = 1; horizontal<Max_largo; horizontal++)
			{
			gotoxy( horizontal, 0);
			printf("%c", 205);
			}

		for(uint8_t horizontal2 = 1; horizontal2<Max_largo; horizontal2++)
			{
			gotoxy(horizontal2, MAX_ALTO);
			printf("%c", 205);
			}
}

void wall1 (uint8_t *p_wallx1,uint8_t *p_wally1,uint8_t *p_wall1_f,uint8_t long_m,uint8_t rectangle){
		*p_wallx1 =  rectangle / 3;
		*p_wall1_f =  *p_wally1 + long_m;

	for(uint8_t i = *p_wally1; i<*p_wall1_f; i++)
				{
				gotoxy(*p_wallx1, i);
				printf("%c", 186);
				}

}

void wall2 (uint8_t *p_wallx2,uint8_t *p_wally2,uint8_t *p_wall2_f,uint8_t long_m,uint8_t rectangle){
	*p_wallx2 = (rectangle* 2) /3;
	*p_wall2_f =  *p_wally2 + long_m;

		for(uint8_t i = *p_wally2; i<*p_wall2_f; i++){
						gotoxy(*p_wallx2, i);
						printf("%c", 186);
					}

}
void w_random_simbol(uint8_t *p_randomy, uint8_t *p_randomx){
	*p_randomy= (rand()% 18)+1;
	*p_randomx= (rand()% 78)+1;
	gotoxy(*p_randomx,*p_randomy);
	printf("@");

}
void write_sim(uint8_t *o_x, uint8_t *o_y){
	*o_x = 11;
	*o_y = 5;
	gotoxy(*o_x,*o_y);
	printf("O");
}
void randoms(uint8_t *wally1, uint8_t *wally2 ){

	*wally1 = (rand()% 14)+1;
	*wally2 = (rand()% 14)+1;

}

void o_move_two(uint8_t randomx, uint8_t randomy,uint8_t *o_x, uint8_t *o_y, uint8_t wall1, uint8_t wall2){

	o_desplace(&*o_x, &*o_y);


			if(*o_x<randomx){
				*o_x= *o_x +1;
				o_desplace(&*o_x, &*o_y);
				gotoxy(*o_x-1, *o_y);
				printf(" ");
			}
			if(*o_x>randomx){
				*o_x= *o_x -1;
				o_desplace(&*o_x, &*o_y);
				gotoxy(*o_x+1, *o_y);
				printf(" ");
			}
			if(*o_y<randomy){
				*o_y = *o_y +1;
				o_desplace(&*o_x, &*o_y);
				gotoxy(*o_x, *o_y-1);
				printf(" ");
			}
			if(*o_y>randomy){
				*o_y= *o_y-1;
				o_desplace(&*o_x, &*o_y);
				gotoxy(*o_x, *o_y+1);
				printf(" ");
			}
}

void o_move(uint8_t randomx, uint8_t randomy,uint8_t *o_x, uint8_t *o_y, uint8_t wall1, uint8_t wall2){

	o_desplace(&*o_x, &*o_y);
	gotoxy(*o_x, *o_y);
	printf(" ");

			if(*o_x<randomx){
				*o_x= *o_x +1;

			}
			if(*o_x>randomx){
				*o_x= *o_x -1;
			}
			if(*o_y<randomy){
				*o_y = *o_y +1;

			}
			if(*o_y>randomy){
				*o_y= *o_y-1;

			}
}

bool win ( uint8_t *o_y, uint8_t *o_x, uint8_t randomy, uint8_t randomx){
	if((*o_x == randomx) &&(*o_y == randomy)){
					return true;
	}
	else{
		return false;
	}
}

bool test_wall1 (uint8_t o_x,uint8_t o_y,uint8_t wallx1,uint8_t wally1, uint8_t long_m){
	if(((o_x == wallx1)&&(o_y >= wally1-1)&&(o_y <= wally1+LONG_M))){
		return true;
	}
	else{
		return false;
	}
}
bool test_wall2 (uint8_t o_x,uint8_t o_y,uint8_t wallx2,uint8_t wally2, uint8_t long_m){
	if(((o_x == wallx2)&&(o_y >= wally2-1)&&(o_y <= wally2+long_m))){
		return true;
	}
	else{
		return false;
	}

}
void o_desplace (uint8_t *o_x, uint8_t *o_y){
	gotoxy(*o_x, *o_y);
	printf("%c", 79);
	Sleep(300);
}
void ready (void){
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("        ");
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("READY");
		Beep(200, 800);
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("        ");
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("STEADY");
		Beep(100, 800);
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("        ");
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("GO");
		Beep(500, 800);
		gotoxy(LIMIT_RIGHT/2, LIMIT_DOWN/2);
		printf("      ");
}

void win_song(void){
	Beep(500, 539);
	Beep(356, 422);
	Beep(489, 351);
	Beep(716, 500);
}



void you_lose__song(void){
		Beep(500, 800);
		Beep(200, 800);
		Beep(100, 800);
		Beep(80, 1500);
}
