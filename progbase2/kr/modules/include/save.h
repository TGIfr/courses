//
// Created by tgifr on 19.02.17.
//

#ifndef NLP_TEXTPROCESSOR_H
#define NLP_TEXTPROCESSOR_H

#include <stdio.h>
#include "listP.h"

#define CRIT_LENGTH 7
Text * readText(const char* inputF);
void saveText(const char *outputF, Text *text);

Sentence * readSentence(char *str);
void saveSentence(FILE *outputF, Sentence *sentence);

static int isStop(char ch);


#endif //NLP_TEXTPROCESSOR_H
