//
// Created by tgifr on 03.12.16.
//
#include <pbconsole.h>
#include <progbase.h>
#include <string.h>
#include "dino.h"

#ifndef INTERFACE_H
#define INTERFACE_H


void redraw(int cols, int rows);
void clearAnim();

void printText(const char *TEXT);
void printInfoText(const char *HELP);

struct conShift{
    short cols;
    short rows;
};
void conDefPos();
void cleanInp();
void cleanCanvas();
char * getStringInter(char * whatGet);
void exitInter();
void printStructArr(struct List ( *list));
int start(const char *START_TEXT);
void printResult(char * result);

#endif //LAB3_INTERFACE_H