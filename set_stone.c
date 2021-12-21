#include "board.h"

void set_direction(int stone[STONE_MAX_X][STONE_MAX_Y],
				   int turn, int stone_x, int stone_y,
				   int direction_x, int direction_y,
				   int reversi_stone);

/*
指定した座標に手番のプレイヤーの石を置き、その座標を始点に
8方向、裏返す
*/
/*
引数:盤面情報,座標,ターン,裏返す石の個数
戻り値:なし
*/
void set_stone(int stone[STONE_MAX_X][STONE_MAX_Y],int stone_x,int stone_y,int turn,int reversi_stone[REVERSI_LENGTH]){
	/*指定した座標に石をセット*/
	stone[stone_x][stone_y]=turn;



	set_direction(stone,turn,stone_x,stone_y,-1,-1,reversi_stone[0]);
	set_direction(stone,turn,stone_x,stone_y,0,-1,reversi_stone[1]);
	set_direction(stone,turn,stone_x,stone_y,1,-1,reversi_stone[2]);
	set_direction(stone,turn,stone_x,stone_y,-1,0,reversi_stone[3]);
	set_direction(stone,turn,stone_x,stone_y,1,0,reversi_stone[4]);
	set_direction(stone,turn,stone_x,stone_y,-1,1,reversi_stone[5]);
	set_direction(stone,turn,stone_x,stone_y,0,1,reversi_stone[6]);
	set_direction(stone,turn,stone_x,stone_y,1,1,reversi_stone[7]);

}