#include "board.h"

/*引数:盤面情報,手番,座標,方向,返すことができる個数*/
/*戻り値:返せる個数*/
int count_reversi(int stone[STONE_MAX_X][STONE_MAX_Y],
				int turn,int stone_x,int stone_y,
				int direction_x,int direction_y,
				int reversi_stone){
	/*座標を方向先に変更する*/
	stone_x+=direction_x;
	stone_y+=direction_y;

	/*調べる座標が壁なら返せる個数を0で返す*/
	if (stone_x==-1||stone_x==STONE_MAX_X+1){
		reversi_stone =0 ;
		return reversi_stone;
	}
	if (stone_y==-1||stone_y==STONE_MAX_Y+1){
		reversi_stone = 0;
		return reversi_stone;
	}

	/*調べる座標に石がないなら返せる個数を0にする*/
	if (stone[stone_x][stone_y]==NONE_STONE){
		reversi_stone = 0;
		return reversi_stone;
	}

	/*調べる座標に相手の石があるなら,返す個数+1して再起処理*/
	if (stone[stone_x][stone_y]!=turn)
	{
		return count_reversi(stone,turn,stone_x,stone_y,direction_x,direction_y,++reversi_stone);
	}

	/*調べる座標に自分の石があるなら返す個数を返す*/
		return reversi_stone;
	

}