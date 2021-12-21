#include<ncurses.h>
#include<unistd.h>
#include "board.h"

void draw_player(int turn,int stone[][STONE_MAX_Y]){
	int black_stone=0,white_stone=0;
	int i,j;

	/*プライヤー表示*/
	mvprintw(WHITE_PLAYER_Y,WHITE_PLAYER_X,"白");
	mvprintw(BLACK_PLAYER_Y,BLACK_PLAYER_X,"黒");

	/*所持石の探索*/
	for ( i = 0; i <STONE_MAX_Y ; i++)
	{
		for ( j = 0; j < STONE_MAX_X; j++)
		{
			switch (stone[j][i])
			{
			case WHITE_STONE:
				white_stone++;
				break;
			case BLACK_STONE:
				black_stone++;
				break;
			}
		}
	}

	/*所持石の表示*/
	mvprintw(BLACK_PLAYER_Y,BLACK_PLAYER_X+4,"%2d",black_stone);
	mvprintw(WHITE_PLAYER_Y,WHITE_PLAYER_X+4,"%2d",white_stone);


	/*今のプレイヤーを明示*/
	switch (turn)
	{
	case BLACK_STONE:
		mvprintw(BLACK_PLAYER_Y,BLACK_PLAYER_X-2,"→");
		break;
	case WHITE_STONE:
		mvprintw(WHITE_PLAYER_Y,WHITE_PLAYER_X-2,"→");
		break;
	}
	curs_set(0);
	refresh();
}