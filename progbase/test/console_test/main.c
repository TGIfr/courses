#include <progbase.h>
#include <pbconsole.h>
#include <stdio.h>

int main(void) {
	char key = 0;
	int box_left = 10;
	int box_top = 3;
	int box_width = 60;
	int box_height = 18;
	int i = 0;
	int x = 40;
	int y = 5;
	int clear = 1;
	atexit(conClear);
	conClear();
	printf("Use 'wasd' to move, 'c' to toggle clear, 'q' to quit:\n");
	for (i = box_left; i <= box_left + box_width; i++) {
		conMove(box_top, i);
		putchar('=');
		conMove(box_top + box_height, i);
		putchar('=');
	}
	for (i = box_top + 1; i < box_top + box_height; i++) {
		conMove(i, box_left);
		putchar('|');
		conMove(i, box_left + box_width);
		putchar('|');
	}
	conMove(y, x);
	putchar('@');
	while (key != 'q') {
		conMove(2, 1);
		key = conGetChar();
		if (clear) {
			conMove(y, x);
			putchar(' ');
		}
		switch (key) {
		case 'w':
			y--;
			break;
		case 'a':
			x--;
			break;
		case 's':
			y++;
			break;
		case 'd':
			x++;
			break;
		case 'c':
			clear = !clear;
			break;
		}
		if (x <= box_left) x = box_left + 1;
		if (x >= box_left + box_width) x = box_left + box_width - 1;
		if (y <= box_top) y = box_top + 1;
		if (y >= box_top + box_height) y = box_top + box_height - 1;
		conMove(y, x);
		putchar('@');
	}
	printf("\nThe end.\n");
	return 0;
}
