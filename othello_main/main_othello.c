#include<ncurses.h>
#include<unistd.h>
#include <locale.h>

void call_othello(void);

int main(void){
	setlocale(LC_ALL, "");
	initscr();

	call_othello();

	endwin();
	return 0;
}