#include <ncurses.h>
#include <unistd.h>
#include "board.h"

/*
画面からクリックされた座標を取得して、盤面の座標に変える.
*/
int chose_area(void)
{
	int point_X, point_y;
	int c;
	MEVENT event;

	/* マウスを利用 */
	keypad(stdscr, TRUE);
	cbreak();
	/* 全てのマウスイベントを検知 */
	mousemask(ALL_MOUSE_EVENTS, NULL);

	while (1)
	{
		c = getch();
		if (c == KEY_MOUSE)
		{
			if (getmouse(&event) == OK)
			{
				if (event.bstate & BUTTON1_PRESSED)
				{
					/*終了をクリックした*/
					/*始めからをクリックした*/
					/*盤面内をクリックした時にbreak*/
					if ((BOARD_X <= event.x && event.x < STONE_MAX_X * 2 + BOARD_X) && (BOARD_Y <= event.y && event.y < STONE_MAX_Y + BOARD_Y))
					{
						/*画面の座標を盤面の座標に変更する*/
						point_X = (event.x - BOARD_X) / 2;
						point_y = event.y - BOARD_Y;
						nocbreak();
						break;
					}
				}
				getmouse(&event);
			}
		}
	}
	return point_X * 100 + point_y;
}