//
// Created by tgifr on 19.02.17.
//

#include <string.h>
#include <stdlib.h>
#include "listP.h"
#include "save.h"

Text * readText(const char* inputF){
    FILE * input;
    if((input = fopen(inputF, "r")) == NULL){
        printf("ERROR: input file not opened");
        exit(1);
    }
    Text * text = Text_new();

    while (1) {
        char temp[500] = "";
        int i;
        char ch = (char)fgetc(input);
        for(i = 0; !isStop(ch) && !feof(input); i ++ ){
            temp[i] = ch;
            ch = (char)fgetc(input);
        }
        temp[i] = '\0';
        if(!feof(input)){
            Text_addLast(text, readSentence(temp));
        } else break;
    }
    fclose(input);
    return text;
}

int isStop(char ch) {
    if(ch == '.' || ch == '!' || ch == '?' ){
        return 1;
    } else{
        return 0;
    }
}

void saveText(const char *outputF, Text *text){
    FILE * output;
    if((output = fopen(outputF, "w")) == NULL){
        printf("ERROR: output file not opened");
        exit(1);
    }
    for(int i = 0; i < textLength(text); i ++){
        Sentence * sentence = Text_getSentenceAt(text, i);
        saveSentence(output, sentence);
    }
    fclose(output);
}

void saveSentence(FILE *outputF, Sentence *sentence){
    for(int i = 0; i < sentenceLength(sentence); i ++){
        Word * word = Sentence_getWordAt(sentence, i);
        fprintf(outputF, "%s, ", Word_getStr(word));
    }
    fprintf(outputF, "\n");
}

Sentence * readSentence(char *str){
    Sentence * list = Sentence_new();
    char * tokens = " ,<>[]{}:-\"";
    char * temp = strtok(str, tokens);
    while(temp != NULL){
        Sentence_addLast(list, Word_new(temp));
        temp = strtok(NULL, tokens);
    }
    return list;
}


