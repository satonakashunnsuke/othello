#include <ncurses.h>
#include <unistd.h>
#include "board.h"

/*パスした場合、パスしたことを表示する*/

void print_info(int pathFlag){
	if (pathFlag!=0)
	{
		mvprintw(20,0,"path");
		refresh();
		sleep(3);
	}
}