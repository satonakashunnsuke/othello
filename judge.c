#include <ncurses.h>
#include <unistd.h>
#include "board.h"

void judge(int stone[STONE_MAX_X][STONE_MAX_Y])
{
	int white = 0, black = 0;
	int i, j;

	for (i = 0; i < STONE_MAX_Y; i++)
	{
		for (j = 0; j < STONE_MAX_X; j++)
		{
			if (stone[j][i] == BLACK_STONE)
				black++;
			if (stone[j][i] == WHITE_STONE)
				white++;
		}
	}

	mvprintw(20,0,"          ");
	refresh();
	if (black > white)
	{
		mvprintw(20, 3, "BLACK WINNER");
		refresh();
		sleep(5);
		return;
	}
	if (white > black)
	{
		mvprintw(20, 3, "WHITE WINNER");
		refresh();
		sleep(5);
		return;
	}

	mvprintw(20, 3, "DRAW");
	refresh();
	sleep(5);
	return;
}