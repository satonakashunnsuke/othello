#include "board.h"

int chose_area(void);
void count_stone(int stone[STONE_MAX_X][STONE_MAX_Y], int stone_x, int stone_y, int turn, int reversi_stone[REVERSI_LENGTH]);
void set_stone(int stone[STONE_MAX_X][STONE_MAX_Y], int stone_x, int stone_y, int turn, int reversi_stone[REVERSI_LENGTH]);
void print_info(int pathFlag);


/*
オセロの対戦の処理を行う。パスが2回なら-1を返す
*/
int run_othello(int pathFlag, int turn, int stone[STONE_MAX_X][STONE_MAX_Y])
{
	int point; /*上3桁がX座標,下3桁がy座標*/
	int reversi_stone[REVERSI_LENGTH];
	int reversi_flag = 1; /*反転可能:0,反転不可能:1*/
	int i;

	/*パスがされていないなら対戦をする*/
	if (pathFlag == 0)
	{
		point = chose_area();
		while (1)
		{
			/*reversi_stoneの初期化*/
			for (i = 0; i < REVERSI_LENGTH; i++)
				reversi_stone[i] = 0;
			/*始めからが押されたら*/
			/*終了が押されたか*/
			/*
			座標が盤面内なら反転石数調査をして
			反転不可能ではないならメッセージ処理
			反転可能であればbreak
			*/
			count_stone(stone, point / 100, point % 100, turn, reversi_stone);
			for (i = 0; i < REVERSI_LENGTH; i++)
			{
				/*反転可能*/
				if (reversi_stone[i] != 0)
					reversi_flag = 0;
			}

			/*反転可能なのでbreak*/
			if (reversi_flag == 0)
			{
				break;
			}

			point = chose_area();
		}
		/*配置更新処理*/
		set_stone(stone, point / 100, point % 100, turn, reversi_stone);

	}
	/*情報通知*/
	print_info(pathFlag);
	/*pathが2連続で起きたなら終了(終了)*/
	if (pathFlag == 2)
	{
		return 1;
	}

	/*終了(続行)*/
	return 0;
}