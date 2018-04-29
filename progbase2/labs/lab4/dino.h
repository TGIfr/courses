//
// Created by tgifr on 03.12.16.
//
#include <pbconsole.h>
#include <progbase.h>
#include <string.h>
#include <time.h>
#include "list.h"
#ifndef LAB3_DYNO_H
#define LAB3_DYNO_H
#define MAX_SIZE 10
#define NAMES_SIZE 10

const char * DIN0_NAMES[10] ;

struct dino {
    char name[100];
    int age;
    double mass;
    struct dino * friend;
    int number;
    struct dino * next;
};
int writeFromStr(struct List *list, char *str);
char * writeInStr(struct dino * dyno);

struct List * writeFromText(char *text);
char *writeInText(struct List *list);

void delete(struct List *list, int toDelete);
void rewrite(struct List *list, int toRewrite, int toCopy);

void changeField(struct dino *dyno, char *field, char *toChange, struct List *list);

char* findByMass(struct List *list, double mass);

void initializeList(struct List *list);
void fillRandList(struct List *list);

#endif //LAB3_DYNO_H