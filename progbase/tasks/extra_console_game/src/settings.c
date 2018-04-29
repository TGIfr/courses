//
// Created by tgifr on 14.12.16.
//
#include "settings.h"

const int LEVELS[10] = {
        0, 400, 370, 340, 310, 270, 250, 230, 210, 190
};
unsigned long int MILLIS_WAIT = 30;

const struct consize DEF_SIZE = {COLS, ROWS};


const char * saveFile  = "leaderboard.save";
