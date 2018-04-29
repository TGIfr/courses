//
// Created by tgifr on 03.12.16.
//
#include <ctype.h>
#include "dino.h"
#include "list.h"


const char * DIN0_NAMES[10] = { "Kvadrat", "Jurasic", "Star", "Katzchen", "Jet",
                                "Half", "life", "3", "Night_Fury", "Moonshine"};

int writeFromStr(struct List *list, char *str){
    int i = 0;
    char test[100] = "";
    strcpy(test, str);
    char * temp = strtok(test, " ");

    struct dino * tempDino = List_elementAt(list, i);
    while(strcmp(tempDino->name, "") || tempDino->age != 0 || tempDino->mass != 0.0){
        i++;
        tempDino = List_elementAt(list, i);
        if(i == MAX_SIZE){
            return EXIT_FAILURE;
        }
    }
    if(temp != NULL && isalpha(temp[0])){
        strcpy(tempDino->name, temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && isdigit(temp[0])){
        tempDino->age = atoi(temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && isdigit(temp[0])){
        tempDino->mass =  atof(temp);
        temp = strtok(NULL, " ");
    }
    if(temp != NULL && atoi(temp) < MAX_SIZE && atoi(temp) > -1  && isdigit(temp[0])){
        tempDino->friend = List_elementAt(list,atoi(temp));
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
struct List * writeFromText(char *text){
    char temp[200] = "";

    struct List * list = createDinoList();
    if(list == NULL){
        return NULL;
    }
    initializeList(list);
    char toCopy[2] = "";
    toCopy[1] = '\0';
    for (int i = 0; text[i] != '\0'; ++i) {
        toCopy[0] = text[i];
        strcat(temp, toCopy);
        if(text[i] == '\n'){
            temp[i] = '\0';
            if (!writeFromStr(list, temp)) {
                break;
            }
            strcpy(temp, "");
        }
    }
    return list;
}
char *writeInText(struct List *list){
    char * temp;
    char result[1000] = "";
    for (int i = 0; i < MAX_SIZE; ++i) {
        temp = writeInStr(List_elementAt(list, i));
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

void delete(struct List *list, int toDelete){
    if(toDelete >= MAX_SIZE || toDelete < 0){
        return;
    }
    struct dino * temp = List_elementAt(list, toDelete);
    strcpy(temp->name, "");
    temp->age = 0;
    temp->mass = 0.0;
    temp->friend = List_elementAt(list, 0);
}

void rewrite(struct List *list, int toRewrite, int toCopy){
    if(toRewrite >= MAX_SIZE || toCopy >= MAX_SIZE || toCopy < 0 || toRewrite < 0){
        return;
    }
    struct dino * toRewriteD = List_elementAt(list, toRewrite);
    struct dino * toCopyD = List_elementAt(list, toCopy);
    strcpy(toRewriteD->name, toCopyD->name);
    toRewriteD->age = toCopyD->age;
    toRewriteD->mass = toCopyD->mass;
    toRewriteD->friend = toCopyD->friend;
}


void changeField(struct dino *dyno, char *field, char *toChange, struct List *list) {
    if(!strcmp("name", field)){
        strcpy(dyno->name, toChange);
    } else if(!strcmp("age", field)){
        dyno->age = atoi(toChange);
    } else if(!strcmp("mass", field)){
        dyno->mass = atof(toChange);
    } else if(!strcmp("friend", field) && atoi(toChange) < MAX_SIZE){
        dyno->friend = List_elementAt(list,atoi(toChange));
    }
}

char* findByMass(struct List *list, double mass){
    char temp[300] = "";
    for (int i = 0; i < MAX_SIZE; ++i) {
        struct dino * tempD = List_elementAt(list, i);
        if(tempD->mass < mass){
            strcat(temp, tempD->name);
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

void initializeList(struct List *list){
    for(int i = 0; i < MAX_SIZE; i ++){
        struct dino * temp = List_elementAt(list, i);
        strcpy(temp->name ,"");
        temp->number = i;
        temp->friend = List_elementAt(list, 0);
        temp->age = 0;
        temp->mass = 0.0;
    }
}

void fillRandList(struct List *list){
    srand(time(0));
    for(int i = 0; i < MAX_SIZE; i ++){
        struct dino * temp = List_elementAt(list, i);
        strcpy(temp->name, DIN0_NAMES[rand() % NAMES_SIZE]);
        temp->friend = List_elementAt(list, rand() % MAX_SIZE);
        temp->age =  (rand() % 1000) + 1;
        temp->mass = 50.0 / ((rand() % 50) + 1)  ;
    }
}

