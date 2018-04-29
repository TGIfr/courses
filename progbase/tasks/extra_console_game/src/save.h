//
// Created by tgifr on 15.12.16.
//
#include "settings.h"
#include "tetris.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef EXTRA_CONSOLE_GAME_SAVE_H
#define EXTRA_CONSOLE_GAME_SAVE_H

struct player * readSave();
int save(char * nickname, int score, struct player * leaderboard);
void initializeArr(struct player * arr);
char * writeInText(struct player *arr, char * nickname, int score);
char * writeInStr(struct player * pers);
int writeFromStr(struct player * arr, char * str);

#endif //EXTRA_CONSOLE_GAME_SAVE_H
