//
// Created by tgifr on 03.12.16.
//
#include <pbconsole.h>
#include <progbase.h>
#include <string.h>
#include <time.h>
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
};
int writeFromStr(struct dino *arr, char *str);
char * writeInStr(struct dino * dyno);

struct dino * writeFromText(char * text);
char *writeInText(struct dino *arr);

void delete(struct dino * arr,  int toDelete);
void rewrite(struct dino * arr,  int toRewrite, int toCopy);

void changeField(struct dino *dyno, char *field, char *toChange, struct dino *arr);

char* findByMass(struct dino *arr, double mass);

void initializeArr(struct dino * arr);
void fillRandArr(struct dino * arr);

#endif //LAB3_DYNO_H