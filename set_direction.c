#include "board.h"
/*
指定した方向に裏返す個数分を手番の石にセットする。
*/

/*
引数:盤面情報,ターン,座標,方向,裏返す個数
戻り値:なし
*/

void set_direction(int stone[STONE_MAX_X][STONE_MAX_Y],
				   int turn, int stone_x, int stone_y,
				   int direction_x, int direction_y,
				   int reversi_stone)
{
	/*
	裏返す石が残っているなら指定した座標の石を手番の石に
	変更。そのあと裏返す石の個数を一つ減らす.
	*/
	while (reversi_stone > 0)
	{
		stone_x += direction_x;
		stone_y += direction_y;
		stone[stone_x][stone_y] = turn;
		reversi_stone--;
	}
}