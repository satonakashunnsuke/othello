#include <ncurses.h>
#include <unistd.h>
#include "board.h"

void print_direction(int reversi_stone[REVERSI_LENGTH]){
	
	mvprintw(17,0,"%2d %2d %2d\n%2d 00 %2d\n%2d %2d %2d",reversi_stone[0],reversi_stone[1],reversi_stone[2],reversi_stone[3],reversi_stone[4],reversi_stone[5],reversi_stone[6],reversi_stone[7]);
	refresh();
	sleep(5);
}