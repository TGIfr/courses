//
// Created by tgifr on 03.12.16.
//
#include <ctype.h>
#include "dino.h"


const char * DIN0_NAMES[10] = { "Kvadrat", "Jurasic", "Star", "Katzchen", "Jet",
                                "Half", "life", "3", "Night_Fury", "Moonshine"};

int writeFromStr(struct dino *arr, char *str){
    int i = 0;
    char test[100] = "";
    strcpy(test, str);
    char * temp = strtok(test, " ");
    while(strcmp(arr[i].name, "") || arr[i].age != 0 || arr[i].mass != 0.0){
        i++;
        if(i == MAX_SIZE){
            return EXIT_FAILURE;
        }
    }
    if(temp != NULL && isalpha(temp[0])){
        strcpy(arr[i].name, temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && isdigit(temp[0])){
        arr[i].age = atoi(temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && isdigit(temp[0])){
        arr[i].mass =  atof(temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && atoi(temp) < MAX_SIZE && atoi(temp) > -1  && isdigit(temp[0])){
        arr[i].friend = &arr[atoi(temp)];
    }
    return EXIT_SUCCESS;
}
char * writeInStr(struct dino * dyno){
    char *result = malloc(200 * sizeof(char));
    if(result == NULL){
        return 0;
    }
    sprintf(result, "%s %i %.3f %i\n", dyno->name, dyno->age, dyno->mass, dyno->friend->number);
    return  result;
}
struct dino * writeFromText(char * text){
    char temp[200] = "";
    struct dino * arr = malloc(MAX_SIZE * sizeof(struct dino));
    if(arr == NULL){
        return NULL;
    }
    initializeArr(arr);
    char toCopy[2] = "";
    toCopy[1] = '\0';
    for (int i = 0; text[i] != '\0'; ++i) {
        toCopy[0] = text[i];
        strcat(temp, toCopy);
        if(text[i] == '\n'){
            temp[i] = '\0';
            if (!writeFromStr(arr, temp)) {
                break;
            }
            strcpy(temp, "");
        }
    }
    return arr;
}
char *writeInText(struct dino *arr){
    char * temp;
    char result[1000] = "";
    for (int i = 0; i < MAX_SIZE; ++i) {
        temp = writeInStr(&arr[i]);
        strcat(result, temp);
        free(temp);
    }
    temp = malloc((strlen(result) + 5 ) * sizeof(char));
    if(temp == NULL){
        return 0;
    }
    strcpy(temp, result);
    return temp;
}
void delete(struct dino * arr,  int toDelete){
    if(toDelete >= MAX_SIZE || toDelete < 0){
        return;
    }
    strcpy(arr[toDelete].name, "");
    arr[toDelete].age = 0;
    arr[toDelete].mass = 0.0;
    arr[toDelete].friend = &arr[0];
}
void rewrite(struct dino * arr,  int toRewrite, int toCopy){
    if(toRewrite >= MAX_SIZE || toCopy >= MAX_SIZE || toCopy < 0 || toRewrite < 0){
        return;
    }
    strcpy(arr[toRewrite].name, arr[toCopy].name);
    arr[toRewrite].age = arr[toCopy].age;
    arr[toRewrite].mass = arr[toCopy].mass;
    arr[toRewrite].friend = arr[toCopy].friend;
}
void changeField(struct dino *dyno, char *field, char *toChange, struct dino *arr) {
    if(!strcmp("name", field)){
        strcpy(dyno->name, toChange);
    } else if(!strcmp("age", field)){
        dyno->age = atoi(toChange);
    } else if(!strcmp("mass", field)){
        dyno->mass = atof(toChange);
    } else if(!strcmp("friend", field) && atoi(toChange) < MAX_SIZE){
        dyno->friend = &arr[atoi(toChange)];
    }
}
char* findByMass(struct dino *arr, double mass){
    char temp[300] = "";
    for (int i = 0; i < MAX_SIZE; ++i) {
        if(arr[i].mass < mass){
            strcat(temp, arr[i].name);
            strcat(temp, " ");
        }
    }
    char * result = malloc((strlen(temp) + 5)* sizeof(char));
    if(result == NULL){
        return "";
    }
    strcpy(result, temp);
    return result;
}
void initializeArr(struct dino * arr){
    for(int i = 0; i < MAX_SIZE; i ++){
        strcpy(arr[i].name ,"");
        arr[i].number = i;
        arr[i].friend = &arr[0];
        arr[i].age = 0;
        arr[i].mass = 0.0;
    }
}
void fillRandArr(struct dino * arr){
    srand(time(0));
    for(int i = 0; i < MAX_SIZE; i ++){
        strcpy(arr[i].name, DIN0_NAMES[rand() % 10]);
        arr[i].friend = &arr[ rand() % NAMES_SIZE];
        arr[i].age =  (rand() % 1000) + 1;
        arr[i].mass = 50.0 / ((rand() % 50) + 1)  ;
    }
}

