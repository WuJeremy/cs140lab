#include <ncurses.h>
#include <unistd.h>

#define DELAY 90000
#define SWARM_CHAR "*"
#define SWARM_ROWS 5
#define SWARM_COLS 10

int swarm[SWARM_ROWS][SWARM_COLS] = { {0,0,0,1,1,1,1,0,0,0}, {0,0,1,1,1,1,1,1,0,0}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {0,0,1,1,1,1,1,1,0,0} };

void print_swarm(int topleft_y, int topleft_x)
{
	int x = topleft_x;
	int y = topleft_y;
    int i, j;

	for (i = 0; i < SWARM_ROWS; i++) {
		for (j = 0; j < SWARM_COLS; j++) {
			if (swarm[i][j])
				mvprintw(topleft_y+i, topleft_x+j, SWARM_CHAR);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) 
{
    int x = 0, y = 0;
    int max_y = 0, max_x = 0;
    int next_x = 0;
    int direction = 1;
    int swipe_count = 0;	

    initscr();
    noecho();
    curs_set(FALSE);

    while(1) {
        clear();
    	getmaxyx(stdscr, max_y, max_x);

    	print_swarm(y, x);
	    refresh();

        usleep(DELAY);

        next_x = x + direction;

        if (next_x + SWARM_COLS >= max_x || next_x < 0) {
            direction*= -1;
            swipe_count++;
		
            if (swipe_count % 3 == 0) y++;
        } else {
            x+= direction;
        }

    }

    endwin();
}
