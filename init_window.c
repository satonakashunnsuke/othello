#include "board.h"
void draw_stone(int stone[][STONE_MAX_Y]);
void draw_player(int turn,int stone[][STONE_MAX_Y]);

void init_window(int *turn,int stone[][STONE_MAX_Y]){
	int i,j;

	/*盤面情報初期化*/
	for ( i = 0; i < STONE_MAX_Y; i++)
	{
		for ( j = 0; j < STONE_MAX_X; j++)
		{
			stone[j][i]=0;
		}
	}
	stone[STONE_MAX_X/2-1][STONE_MAX_Y/2]=WHITE_STONE;
	stone[STONE_MAX_X/2][STONE_MAX_Y/2-1]=WHITE_STONE;
	stone[STONE_MAX_X/2-1][STONE_MAX_Y/2-1]=BLACK_STONE;
	stone[STONE_MAX_X/2][STONE_MAX_Y/2]=BLACK_STONE;

	/*プレイヤー情報初期化*/
	*turn=BLACK_STONE;
	/*draw_player*/
	draw_player(*turn,stone);
	/*draw_stone*/
	draw_stone(stone);
}