#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ch;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	int posX, posY;
	posX = posY = 0;

	int foodX, foodY;
	foodX = rand() % 20;
	foodY = rand() % 20;

	while (1) {

		mvprintw(posY, posX, "O");
		mvprintw(foodY, foodX, "*");

		if (posX == foodX && posY == foodY) {
			foodX = rand() % getmaxx(stdscr);
			foodY = rand() % getmaxy(stdscr);
		}
		refresh();

		ch = getch();

		if (ch == KEY_LEFT || ch == 'h') {
			posX--;
			refresh();
			clear();
			if ((posX < 0)) {
				posX = 0;	

			}
		}

		if (ch == KEY_RIGHT || ch == 'l') {
			posX++;
			refresh();
			clear();
			if ((posX > getmaxx(stdscr))) {
				posX = getmaxx(stdscr) - 1;
			}
		}

		if (ch == KEY_UP || ch == 'k') {
			posY--;
			refresh();
			clear();
			if ((posY < 0)) {
				posY = 0;
			}
		}

		if (ch == KEY_DOWN || ch == 'j') {
			posY++;
			refresh();
			clear();
			if ((posY > getmaxy(stdscr))) {
				posY = getmaxy(stdscr) - 1;
			}
		}

		if (ch == 'G') {
			posY = getmaxy(stdscr) - 1;
			refresh();
			clear();
		}

		if (ch == 'g') {
			posY = 0;
			refresh();
			clear();
		}
	}
	getch();

	endwin();
	return 0;
}
