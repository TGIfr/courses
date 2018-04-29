//
// Created by tgifr on 03.12.16.
//
#include "dino.h"

#ifndef LAB3_SAVES_H
#define LAB3_SAVES_H

struct List * readFile(char *readFileName);
int saveFile(struct List *list, char *saveFileName);
#endif //LAB3_SAVES_H
