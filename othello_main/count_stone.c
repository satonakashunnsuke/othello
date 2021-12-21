#include "board.h"

int count_reversi(int stone[STONE_MAX_X][STONE_MAX_Y],
				int turn,int stone_x,int stone_y,
				int direction_x,int direction_y,
				int reversi_stone);

/*
指定した座標で8方向調べて裏返すことができる個数を判定する.
まず、指定した座標に石があれば何もしない
指定した座標に石がなければ8方向に裏返せる石の個数をカウントする.
*/

/*引数:盤面情報,石の座標,今のプレイヤー情報,返すことができる石*/
/*戻り値:なし*/
void count_stone(int stone[STONE_MAX_X][STONE_MAX_Y],int stone_x,int stone_y,int turn,int reversi_stone[REVERSI_LENGTH]){
	/*自分の石が置かれてないなら何もしない*/
	if (stone[stone_x][stone_y]!=NONE_STONE)
		return;

	/*右上方向調査*/
	reversi_stone[0]=count_reversi(stone,turn,stone_x,stone_y,-1,-1,0);
	/*上方向調査*/
	reversi_stone[1]=count_reversi(stone,turn,stone_x,stone_y,0,-1,0);
	/*左上方向調査*/
	reversi_stone[2]=count_reversi(stone,turn,stone_x,stone_y,1,-1,0);
	/*右方向調査*/
	reversi_stone[3]=count_reversi(stone,turn,stone_x,stone_y,-1,0,0);
	/*左方向調査*/
	reversi_stone[4]=count_reversi(stone,turn,stone_x,stone_y,1,0,0);
	/*右下方向調査*/
	reversi_stone[5]=count_reversi(stone,turn,stone_x,stone_y,-1,1,0);
	/*下方向調査*/
	reversi_stone[6]=count_reversi(stone,turn,stone_x,stone_y,0,1,0);
	/*左下方向調査*/
	reversi_stone[7]=count_reversi(stone,turn,stone_x,stone_y,1,1,0);
	
}