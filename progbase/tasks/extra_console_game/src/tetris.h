//
// Created by tgifr on 14.12.16.
//
#include "settings.h"
#include <time.h>


#ifndef EXTRA_CONSOLE_GAME_TETRIS_H
#define EXTRA_CONSOLE_GAME_TETRIS_H
struct tetr {
    int col;
    int row;
    int rotation;
    int type;
    int color;
};


int randColor();
char tetrs [7 /*type */ ][4 /* rotation */ ][5 /* horizontal*/ ][5 /* vertical */ ];
int tetrsStartPos  [7 /*kind */ ][2 /* position */];

int isTetrFilled(struct tetr *current, int row, int col);
int XTetrStartPos(struct tetr *current);
int YTetrStartPos(struct tetr *current);

void addTetrToField(struct tetr  * current, int field[][FIELD_COLS]);
int isGameOver(int field [][FIELD_COLS]);
void deleteLine(int row, int field[][FIELD_COLS]);
int deletePossibleLines(int field[][FIELD_COLS]);

int randTetr();
struct tetr spawnNewTetr();
void checkLevel(int score, int * level);

int isFreeBlock (int col, int row, int field[][FIELD_COLS]);
int tetrCheck(struct tetr *current, int field[][FIELD_COLS]);


struct player {
    char  nickname[100];
    int score;
};

int tetris(struct settings * setts);

#endif //EXTRA_CONSOLE_GAME_TETRIS_H
