#include<stdio.h>
#include<windows.h>
#include<conio.h>

void draw_ship(int x, int y);
void erase_ship1(int x, int y);
void erase_ship2(int x, int y);

int x, y,i;
void draw_ship(int x,int y) {
	 
	printf(" <_0_> ");
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
}
void erase_ship1(int x, int y) {
	printf("       ");
	COORD c = { x,y-- };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void erase_ship2(int x, int y) {
	printf("       ");
	COORD c = { x,y++ };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
/*void erase_ship3(int x, int y) {
	printf("      ");
	COORD c = { x,++y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}*/


int main() {
	char ch = ' ';
	int x = 0;
	int y = 0;
	do {
		if (_kbhit()) {
			ch = _getch();
			if ( x <= 80 && y>=0) {
				if (ch == 'a') {
					draw_ship(x--, y);
					erase_ship1(x, y);
				}
				if (ch == 'd') {
					draw_ship(x++, y);
					erase_ship2(x, y);
				}

				if (ch == 'w') {
				
					draw_ship(x, y--);
					erase_ship1(x, y);
				}
				if (ch == 's') {
				
					draw_ship(x, y++);
					erase_ship2(x, y);
					fflush(stdin);
				}
				continue;
			}
		}
		
		Sleep(100);
	} while (ch != 'x');
	
	return 0;
}