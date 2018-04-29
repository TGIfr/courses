//
// Created by tgifr on 14.12.16.
//
#include "pbconsole.h"

#ifndef EXTRA_CONSOLE_GAME_SETTINGS_H
#define EXTRA_CONSOLE_GAME_SETTINGS_H
#define COLOR_MAX 6
#define PLAYERS_MAX 5

#define EMPTY 0
#define TETRIS 1
#define SNAKE 2
#define TETRSNAKE 3

#define ROWS 22
#define COLS 38
#define MAX_LEVEL 9



#define TETR_TYPES 7
#define RIGHT 1
#define LEFT -1
#define UP -1
#define DOWN 1
#define FIELD_SHIFT 2

#define NEXT_ROW 5

enum logoCoord {
    FIELD_ROWS = (ROWS - 2),
    FIELD_COLS = (COLS - 16),
    NEXT_COL = COLS - 9,
    LOGO_ROW = 16,
    LOGO_COL = COLS - 9,
    T_ROW = 10,
    T_COL = 12,
    S_ROW = 10,
    S_COL = 25,
    TS_ROW = 10,
    TS_COL = 37,
    TETR_MX_SIZE = 5
};
struct settings{
    int level;
    int fallTime;
    char * nickname;
    int gameMode;
    struct player * leaderboard;
};
const int LEVELS[10];
const struct consize DEF_SIZE;
unsigned long int MILLIS_WAIT;
const char * saveFile ;

#endif //EXTRA_CONSOLE_GAME_SETTINGS_H
