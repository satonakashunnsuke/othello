#include "board.h"

void count_stone(int stone[STONE_MAX_X][STONE_MAX_Y],
				int stone_x,int stone_y,int turn,
				int reversi_stone[REVERSI_LENGTH]);
int reversi_stone_0check(int reversi_stone[REVERSI_LENGTH]);

/*
そのターンにおいて、返すことができる石があるか調べる。
返すことができる座標が一つでもあるなら0
返すことができないなら-1を返す(パスする)
*/

int check_reversi(int turn,int stone[STONE_MAX_X][STONE_MAX_Y]){
	int reversi_stone[REVERSI_LENGTH];/*8方向返すことができる石の個数を保持する*/
	int i,j;

	/*reversi_stoneを初期化*/
	for ( i = 0; i < REVERSI_LENGTH; i++)
	{
		reversi_stone[i]=0;
	}
	
	/*全ての座標をチェック*/
		/*調べる座標に石をセット*/
		/*反転石数調査*/
		/*一つでもひっくり返せるか*/
			/*trueならパスをしない*/
		/*全てのマスを調べたか*/
			/*trueならパスする*/
	for ( i = 0; i < STONE_MAX_Y; i++)
	{
		for ( j = 0; j < STONE_MAX_X; j++)
		{
			count_stone(stone,j,i,turn,reversi_stone);
			if (reversi_stone_0check(reversi_stone)==-1)
			{
				return 0;
			}
		}
	}
	return -1;
}

/*返す個数があるか判定する*/
/*0以外なら-1、全て0なら0を返す*/
int reversi_stone_0check(int reversi_stone[REVERSI_LENGTH]){
	int i;
	for ( i = 0; i < REVERSI_LENGTH; i++)
	{
		if (reversi_stone[i]!=0)
			return -1;
	}
	return 0;
}