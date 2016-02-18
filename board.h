#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BOARD_H
#define BOARD_H

typedef enum {
	TERMINE_COLOR_DEFAULT = 1,
	TERMINE_COLOR_CURSOR,
	TERMINE_COLOR_MINE,
	TERMINE_COLOR_FLAG,
	TERMINE_COLOR_1,
	TERMINE_COLOR_2,
	TERMINE_COLOR_3,
	TERMINE_COLOR_4,
	TERMINE_COLOR_5
} TERMINE_COLOR;

enum tile_info {
	TILE_OPENED = 1,
	TILE_MINE = 1 << 1,
	TILE_FLAG = 1 << 2
};

enum direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

struct board {
	int width;
	int height;
	float mine_density;
	int cursor_x;
	int cursor_y;
	bool game_over;
	bool mines_placed;
	uint8_t *data;
};

void board_init(struct board *board, int width, int height, float mine_density);
void board_deinit(struct board *board);
void render(WINDOW *window, struct board *board);
void move_cursor(struct board *board, enum direction direction);
void open_tile_at_cursor(struct board *board);
void toggle_flag_at_cursor(struct board *board);

#endif
