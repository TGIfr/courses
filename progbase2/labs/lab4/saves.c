//
// Created by tgifr on 03.12.16.
//
#include <stdio.h>
#include "dino.h"
#include "list.h"


struct List * readFile(char *readFileName){
    FILE * read;
    char temp[150] = "";
    struct List * list = createDinoList();
    initializeList(list);
    if((read = fopen(readFileName, "r")) == NULL){
        return list;
    }
    while(!feof(read)){
        fgets(temp, 150, read);
        if(writeFromStr(list, temp)){
            break;
        }
    }
    fclose(read);
    return list;
}

int saveFile(struct List *list, char *saveFileName){
    FILE * save;
    if((save = fopen(saveFileName, "w")) == NULL){
        return EXIT_FAILURE;
    }
    char * toWrite = writeInText(list);
    fprintf(save, "%s", toWrite);
    free(toWrite);
    fclose(save);
    return EXIT_SUCCESS;
}

