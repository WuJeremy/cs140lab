#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 100000

int main(int argc, char *argv[]) 
{
	int x = 0, y = 0;
	int max_y = 0, max_x = 0;
	int next_x = 0;
	int direction = 1;
	char ch[2] = "o";
	int tmp;

	initscr();
	noecho();
	curs_set(FALSE);

	getmaxyx(stdscr, max_y, max_x);
	
	while(1) {
		clear();
		nodelay(stdscr, TRUE);
		if ((tmp = getch()) != ERR) {
			ch[0] = (char)tmp;	
		}
		mvprintw(y, x, ch);
		refresh();

		usleep(DELAY);

		next_x = x + direction;

		if (next_x >= max_x || next_x < 0) {
			direction*= -1;
		} else {
			x+= direction;
		}
	
	}

	endwin();
}
