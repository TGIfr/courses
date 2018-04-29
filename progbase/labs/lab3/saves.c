//
// Created by tgifr on 03.12.16.
//
#include <stdio.h>
#include "dino.h"
struct dino * readFile(char * readFileName){
    FILE * read;
    char temp[150] = "";
    struct dino * arr = malloc(MAX_SIZE * sizeof(struct dino));
    initializeArr(arr);
    if((read = fopen(readFileName, "r")) == NULL){
        return arr;
    }
    while(!feof(read)){
        fgets(temp, 150, read);
        if(writeFromStr(arr, temp)){
            break;
        }
    }
    fclose(read);
    return arr;
}
int saveFile(struct dino * arr, char * saveFileName){
    FILE * save;
    if((save = fopen(saveFileName, "w")) == NULL){
        return EXIT_FAILURE;
    }
    char * toWrite = writeInText(arr);
    fprintf(save, "%s", toWrite);
    free(toWrite);
    fclose(save);
    return EXIT_SUCCESS;
}

