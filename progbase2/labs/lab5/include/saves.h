//
// Created by tgifr on 03.12.16.
//
#include "dino.h"

#ifndef LAB3_SAVES_H
#define LAB3_SAVES_H
int Storage_writeAsXml(const char *filePath, List *list);
List * Storage_readAsXml(const char * filePath);

int Storage_writeAsJson(const char *filePath, List *list);
List * Storage_readAsJson(const char * filePath);

int Storage_write(const char *filePath, List *list);
List * Storage_read(const char * filePath);
struct List * Storage_readAsTxt(const char *readFileName);
int Storage_writeAsTxt(struct List *list, const char *saveFileName);
#endif //LAB3_SAVES_H
