#include<ncurses.h>
#include<unistd.h>
#include "board.h"

void draw_stone(int stone[][STONE_MAX_Y]){
	int i,j;
	for ( i = 0; i < STONE_MAX_Y; i++)
	{
		for ( j = 0; j < STONE_MAX_X; j++)
		{
			switch (stone[j][i])
			{
			case NONE_STONE:
				mvprintw(i+BOARD_Y,j*2+BOARD_X,"・");
				break;
			case WHITE_STONE:
				mvprintw(i+BOARD_Y,j*2+BOARD_X,"●");
				break;
			case BLACK_STONE:
				mvprintw(i+BOARD_Y,j*2+BOARD_X,"○");
				break;
			}
		}
	}
	refresh();
}