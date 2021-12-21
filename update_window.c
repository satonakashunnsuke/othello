#include <ncurses.h>
#include <unistd.h>
#include "board.h"
void draw_stone(int stone[][STONE_MAX_Y]);
void draw_player(int turn,int stone[][STONE_MAX_Y]);

void updaet_window(int turn,int stone[STONE_MAX_X][STONE_MAX_Y]){
	clear();
	draw_stone(stone);
	draw_player(turn,stone);
}