//
// Created by tgifr on 03.12.16.
//

#include "interface.h"

unsigned long int MILLIS_WAIT = 30;
const struct consize DEF_SIZE = {87, 25};
const char * EXIT_TEXT = "   _____  ____   ____  _____  ______     ________ \n"
        "  / ____|/ __ \\ / __ \\|  __ \\|  _ \\ \\   / /  ____|\n"
        " | |  __| |  | | |  | | |  | | |_) \\ \\_/ /| |__   \n"
        " | | |_ | |  | | |  | | |  | |  _ < \\   / |  __|  \n"
        " | |__| | |__| | |__| | |__| | |_) | | |  | |____ \n"
        "  \\_____|\\____/ \\____/|_____/|____/  |_|  |______|\n";
void redraw(int cols, int rows){
    int i = 0;
    conResize(DEF_SIZE.rows + (unsigned short)rows, DEF_SIZE.cols + (unsigned short)cols);
    conClear();
    const struct consize actSize = { DEF_SIZE.cols + (unsigned short)cols, DEF_SIZE.rows + (unsigned short)rows};
    conSetAttr(BG_WHITE);
    conSetAttr(FG_INTENSITY_BLUE);
    for(i = 1; i <= actSize.cols; i ++){
        conMove(1, i );
        printf("=");
        conMove(actSize.rows - 5, i);
        printf("=");
        conMove(actSize.rows, i );
        printf("=");
        fflush(stdout);
        sleepMillis(MILLIS_WAIT/3);
    }
    for(i = 1; i <= actSize.rows; i ++){
        conMove(i , 1);
        printf("|");
        conMove(i , actSize.cols);
        printf("|");
        fflush(stdout);
        sleepMillis(MILLIS_WAIT);
    }
    conReset();
    conMove( actSize.rows - 4, 3);
    printf("Print here: ");
}
void clearAnim(){
    int i = 0;
    int j = 0;
    const struct consize size = conGetSize();
    for(i = 1; i <= size.cols; i ++){
        conSetAttr(BG_INTENSITY_BLACK);
        for(j = 1; j <= size.rows; j ++){
            conMove(j, i);
            printf(" ");
            conMove(j, i + 1);
            printf(" ");
        }
        conSetAttr(BG_DEFAULT);
        if (i != 1) {
            for(j = 1; j <= size.rows; j ++){
                conMove(j, i - 1);
                printf(" ");
            }
        }
        if (i == size.cols) {
            for(j = 1; j <= size.rows; j ++){
                conMove(j, i);
                printf(" ");
            }
        }
        fflush(stdout);
        sleepMillis(MILLIS_WAIT);
    }
    conReset();
    conDefPos();
}
void printText(const char *TEXT){
    int i = 0, yShift = 0;
    conMove(3, 3);
    for(i = 0; i < strlen(TEXT); i ++){
        if(TEXT[i] == '\n'){
            yShift++;
            conMove(3 + yShift, 3);
        } else printf("%c", TEXT[i]);
    }
    conDefPos();
}
void printInfoText(const char *HELP){
    char key = '\0';
    cleanCanvas();
    printText(HELP);
    while (key != 'h'){
        key = conGetChar();
    }
    cleanInp();
}
void conDefPos(){
    struct consize actSize = conGetSize();
    conMove(actSize.rows - 4, 3 + sizeof("Print here: "));
}
void cleanInp(){
    int i = 0;
    struct consize actSize = conGetSize();
    for(i = sizeof("Print here: ") + 3; i < actSize.cols - 2; i++){
        conMove(actSize.rows - 4, i);
        printf(" ");
        conMove(actSize.rows - 3, i - sizeof("Print here: "));
        printf(" ");
    }
    conMove(actSize.rows - 6, 3 );
    printf("                                      ");
    conDefPos();
}
void cleanCanvas(){
    int i = 0;
    int j = 0;
    conReset();
    struct consize actSize = conGetSize();
    for(j = 2; j < actSize.rows - 5; j ++){
        for(i = 2; i < actSize.cols; i++){
            conMove(j, i);
            printf(" ");
        }
    }
    conDefPos();
}
char * getStringInter(char * whatGet){
    struct consize actSize = conGetSize();
    conMove(actSize.rows - 6, 3 );
    printf("Please, enter %s:", whatGet);
    conDefPos();
    char * result = getString();
    cleanInp();
    return result;
}
void exitInter(){
    clearAnim();
    printText(EXIT_TEXT);
    sleepMillis(MILLIS_WAIT * 100);
    conClear();
}
void printStructArr(struct dino *arr){
    for(int i = 0; i < MAX_SIZE ; i ++){
        conMove(6 + i, 3);
        if(strcmp(arr[i].name, "") || arr[i].age != 0 || arr[i].mass != 0.0) {
            printf("Dino number[%i]. Name: %s. Age: %i. Mass: %.3f. Friend: %s", i, arr[i].name, arr[i].age,
                   arr[i].mass, arr[i].friend->name);
        }
    }
    conDefPos();
}
int start(const char *START_TEXT){
    conMove(3,3);
    char key = '\0';
    printf("%s", START_TEXT);
    while(key != '1' && key != '2'){
        key = conGetChar();
    }
    return key - '0';
}
void printResult(char * result){
    struct consize actSize = conGetSize();
    conMove(actSize.rows - 6 , 3);
    printf("%s", result);
    conDefPos();
}
