//
// Created by tgifr on 16.12.16.
//
#include "snake.h"
#include "tetris.h"

#ifndef EXTRA_CONSOLE_GAME_TETRISNAKE_H
#define EXTRA_CONSOLE_GAME_TETRISNAKE_H

int tetrisnake(struct settings *setts);
int tetrCheckSnake(struct tetr *current, struct snake * head,  int * directionRow, int * directionCol);

#endif //EXTRA_CONSOLE_GAME_TETRISNAKE_H
