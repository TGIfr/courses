//
// Created by tgifr on 15.12.16.
//

#include "save.h"
struct player * readSave(){
    FILE * read;
    char temp[150] = "";
    struct player * arr = malloc(PLAYERS_MAX * sizeof(struct player));
    initializeArr(arr);
    if((read = fopen(saveFile, "r")) == NULL){
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
int save(char * nickname, int score, struct player * leaderboard){
    FILE * save;
    if((save = fopen(saveFile, "w")) == NULL){
        return EXIT_FAILURE;
    }
    char * toWrite = writeInText(leaderboard, nickname, score);
    fprintf(save, "%s", toWrite);
    free(toWrite);
    fclose(save);
    return EXIT_SUCCESS;
}
int writeFromStr(struct player * arr, char * str){
    int i = 0;
    char test[100] = "";
    strcpy(test, str);
    char * temp = strtok(test, " ");
    while(strcmp(arr[i].nickname, "") || arr[i].score){
        i++;
        if(i == PLAYERS_MAX){
            return EXIT_FAILURE;
        }
    }
    if(temp != NULL && isalpha(temp[0])){
        strcpy(arr[i].nickname, temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && isdigit(temp[0])){
        arr[i].score = atoi(temp);
    }
    return EXIT_SUCCESS;
}
char * writeInStr(struct player * pers){
    char *result = malloc(200 * sizeof(char));
    if(result == NULL){
        return 0;
    }
    sprintf(result, " %s %i \n", pers->nickname, pers->score);
    return  result;
}

char * writeInText(struct player *arr, char * nickname, int score){
    char * temp;
    int flag = 1;
    char result[1000] = "";
    for (int i = 0; i < PLAYERS_MAX; ++i) {
        if(score >= arr[i].score && flag){
            char toCopy[100] = "";
            sprintf(toCopy, " %s %i \n", nickname, score);
            strcat(result, toCopy);
            i --;
            flag = 0;
        } else {
            temp = writeInStr(&arr[i]);
            strcat(result, temp);
            free(temp);
        }
    }
    temp = malloc((strlen(result) + 5 ) * sizeof(char));
    if(temp == NULL){
        return 0;
    }
    strcpy(temp, result);
    return temp;
}
void initializeArr(struct player * arr){
    for(int i = 0; i < PLAYERS_MAX; i ++){
        strcpy(arr[i].nickname, "");
        arr[i].score = 0;
    }
}