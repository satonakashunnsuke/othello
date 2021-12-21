
#include "board.h"

void init_window(int *turn,int stone[][STONE_MAX_Y]);
void draw_stone(int stone[][STONE_MAX_Y]);
void draw_player(int turn,int stone[][STONE_MAX_Y]);
int check_reversi(int turn,int stone[STONE_MAX_X][STONE_MAX_Y]);
int run_othello(int pathFlag,int turn,int stone[STONE_MAX_X][STONE_MAX_Y]);
void updaet_window(int turn,int stone[STONE_MAX_X][STONE_MAX_Y]);
void judge(int stone[STONE_MAX_X][STONE_MAX_Y]);

void call_othello(void){
	int stone[STONE_MAX_X][STONE_MAX_Y];/*盤面の情報*/
	int turn;/*誰のターンか？*/
	int pathFlag=0;/*パス回数を保持する*/
	int stone_num=0;/*盤面にある石の数を保持する*/
	int i,j;
	
	/*初期化*/
	init_window(&turn,stone);
	
	/**/
	while (1)
	{
		/*反転可能探索*/
		/*パス分岐*/
		/*パスをするならパスフラグをカウント*/
		/*パスをしないならパスフラグをリセット*/
		if (check_reversi(turn,stone)==-1){
			pathFlag++;
		}else{
			pathFlag=0;
		}
		
		/*対戦進行処理*/

		/*2連続パスされたなら対戦を終了する*/
		if (run_othello(pathFlag,turn,stone)!=0){
		break;
		}
		
		/*盤面に空きがなければ対戦終了*/
		stone_num=0;
		for ( i = 0; i < STONE_MAX_Y; i++)
		{
			for ( j = 0; j < STONE_MAX_X; j++)
			{
				if (stone[j][i]!=NONE_STONE)
					stone_num++;
			}
		}
		if (stone_num==STONE_MAX_X*STONE_MAX_Y)
			break;


		/*手番の交代*/
		if (turn==BLACK_STONE)
		{
			turn=WHITE_STONE;
		}else{
			turn=BLACK_STONE;
		}
		/*盤面更新*/
		updaet_window(turn,stone);
	}

	updaet_window(turn,stone);
	
	/*対戦結果*/
	judge(stone);

	return;
}