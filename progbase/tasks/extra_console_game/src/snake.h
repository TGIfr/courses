//
// Created by tgifr on 16.12.16.
//


#include "settings.h"
#include <time.h>
#include "tetris.h"


#ifndef EXTRA_CONSOLE_GAME_SNAKE_H
#define EXTRA_CONSOLE_GAME_SNAKE_H

struct snake {
    int row;
    int col;
    struct snake * next;
};

int move(struct snake *head, int *directionCol, int *directionRow, int *foodOnField, int field[][FIELD_COLS]);
void addFood(struct snake * head, int field[][FIELD_COLS]);
struct snake * newPart(int row, int col);
void initializeSnake (struct snake * head);
int snake(struct settings *setts);
void swap (int * a, int * b);
#endif //EXTRA_CONSOLE_GAME_SNAKE_H
