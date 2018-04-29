//
// Created by tgifr on 14.12.16.
//

#include <pbconsole.h>
#include <progbase.h>
#include "settings.h"
#include <string.h>
#include "tetris.h"
#include "snake.h"
#ifndef EXTRA_CONSOLE_GAME_INTERFACE_H
#define EXTRA_CONSOLE_GAME_INTERFACE_H

void redraw();
void clearAnim();

void printText(const char *TEXT);
void printTextWait(const char *text);

void conDefPos();
void cleanInp();
void cleanCanvas();
char * getStringInter(char * whatGet);
void exitInter();
int gameOver();
struct settings start();
void printResult(int score, int level);
void printLeaderboard(struct player * arr);

void printField(int  field [FIELD_ROWS ][FIELD_COLS]);

void printTetr(struct tetr * current);
void showNext(struct tetr * current);

int askGameMode();
void printIntense(int intense);
void printAtStart(void);
void printT(int row, int col, int isIntense);
void printS(int row, int col, int isIntense);
void printTS(int row, int col, int isIntense);
void printSnake(struct snake * head);
#endif //EXTRA_CONSOLE_GAME_INTERFACE_H
