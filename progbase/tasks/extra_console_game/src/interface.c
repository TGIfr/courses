//
// Created by tgifr on 14.12.16.
//
#include <ctype.h>
#include "interface.h"
#include "save.h"
#include "snake.h"


const char * LEADERBOARD = " _    ___   _   ___  ___ ___ ___  ___   _   ___ ___  \n"
        "| |  | __| /_\\ |   \\| __| _ \\ _ )/ _ \\ /_\\ | _ \\   \\ \n"
        "| |__| _| / _ \\| |) | _||   / _ \\ (_) / _ \\|   / |) |\n"
        "|____|___/_/ \\_\\___/|___|_|_\\___/\\___/_/ \\_\\_|_\\___/";
const char * START_TEXT = " ___________________  _________  _____   __ ______\n"
        " /_  __/ __/_  __/ _ \\/  _/ __/ |/ / _ | / //_/ __/\n"
        "  / / / _/  / / / , _// /_\\ \\/    / __ |/ ,< / _/  \n"
        " /_/ /___/ /_/ /_/|_/___/___/_/|_/_/ |_/_/|_/___/ ";
const char * EXIT_TEXT = "   _____  ____   ____  _____  ______     ________ \n"
        "  / ____|/ __ \\ / __ \\|  __ \\|  _ \\ \\   / /  ____|\n"
        " | |  __| |  | | |  | | |  | | |_) \\ \\_/ /| |__   \n"
        " | | |_ | |  | | |  | | |  | |  _ < \\   / |  __|  \n"
        " | |__| | |__| | |__| | |__| | |_) | | |  | |____ \n"
        "  \\_____|\\____/ \\____/|_____/|____/  |_|  |______|\n";

const char * GAME_OVER  = "      ___           ___           ___           ___     \n"
        "     /  /\\         /  /\\         /__/\\         /  /\\    \n"
        "    /  /:/_       /  /::\\       |  |::\\       /  /:/_   \n"
        "   /  /:/ /\\     /  /:/\\:\\      |  |:|:\\     /  /:/ /\\  \n"
        "  /  /:/_/::\\   /  /:/~/::\\   __|__|:|\\:\\   /  /:/ /:/_ \n"
        " /__/:/__\\/\\:\\ /__/:/ /:/\\:\\ /__/::::| \\:\\ /__/:/ /:/ /\\\n"
        " \\  \\:\\ /~~/:/ \\  \\:\\/:/__\\/ \\  \\:\\~~\\__\\/ \\  \\:\\/:/ /:/\n"
        "  \\  \\:\\  /:/   \\  \\::/       \\  \\:\\        \\  \\::/ /:/ \n"
        "   \\  \\:\\/:/     \\  \\:\\        \\  \\:\\        \\  \\:\\/:/  \n"
        "    \\  \\::/       \\  \\:\\        \\  \\:\\        \\  \\::/   \n"
        "     \\__\\/         \\__\\/         \\__\\/         \\__\\/    \n"
        "      ___                        ___           ___      \n"
        "     /  /\\          ___         /  /\\         /  /\\     \n"
        "    /  /::\\        /__/\\       /  /:/_       /  /::\\    \n"
        "   /  /:/\\:\\       \\  \\:\\     /  /:/ /\\     /  /:/\\:\\   \n"
        "  /  /:/  \\:\\       \\  \\:\\   /  /:/ /:/_   /  /:/~/:/   \n"
        " /__/:/ \\__\\:\\  ___  \\__\\:\\ /__/:/ /:/ /\\ /__/:/ /:/___ \n"
        " \\  \\:\\ /  /:/ /__/\\ |  |:| \\  \\:\\/:/ /:/ \\  \\:\\/:::::/ \n"
        "  \\  \\:\\  /:/  \\  \\:\\|  |:|  \\  \\::/ /:/   \\  \\::/~~~~  \n"
        "   \\  \\:\\/:/    \\  \\:\\__|:|   \\  \\:\\/:/     \\  \\:\\      \n"
        "    \\  \\::/      \\__\\::::/     \\  \\::/       \\  \\:\\     \n"
        "     \\__\\/           ~~~~       \\__\\/         \\__\\/     ";

void redraw(){
    int i = 0;
    conResize(DEF_SIZE.rows , DEF_SIZE.cols );
    conClear();
    const struct consize actSize = { DEF_SIZE.cols , DEF_SIZE.rows};
    conSetAttr(BG_WHITE);
    conSetAttr(FG_INTENSITY_BLUE);
    for(i = 1; i <= actSize.cols; i ++){
        conMove(1, i );
        printf("~");
        conMove(actSize.rows, i );
        printf("~");
        if(i > actSize.cols - 15){
            conMove(4, i);
            printf("~");
            conMove(9, i);
            printf("~");
            conMove(14, i);
            printf("~");
        }
        fflush(stdout);
        sleepMillis(MILLIS_WAIT/3);
    }
    for(i = 1; i <= actSize.rows; i ++){
        conMove(i , 1);
        printf("|");
        conMove(i , actSize.cols);
        printf("|");
        conMove(i , actSize.cols - 14);
        printf("|");
        fflush(stdout);
        sleepMillis(MILLIS_WAIT);
    }
    conSetAttr(BG_DEFAULT);
    conMove(2 , actSize.cols - 8);
    printf("SCORE");
    conMove(3 , actSize.cols - 8);
    printf(" 0 ");
    conMove(5 , actSize.cols - 8);
    printf("NEXT");
    conMove(10 , actSize.cols - 8);
    printf("LEV");
    conDefPos();
}
void printAtStart(void){
    int i = 0;
    conResize(DEF_SIZE.rows , DEF_SIZE.cols + 17);
    conClear();
    const struct consize actSize = conGetSize();
    conSetAttr(BG_WHITE);
    conSetAttr(FG_INTENSITY_BLUE);
    for(i = 1; i <= actSize.cols; i ++){
        conMove(1, i );
        printf("~");
        conMove(actSize.rows, i );
        printf("~");
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
    conMove(3, 3);
    conSetAttr(FG_BLUE);
    printText(START_TEXT);
    conReset();
    printT(T_ROW, T_COL, 0);
    printS(S_ROW, S_COL, 0);
    printTS(TS_ROW, TS_COL, 0);
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
void printTextWait(const char *text){
    char key = '\0';
    cleanCanvas();
    printText(text);
    while (key != 'h'){
        key = conGetChar();
    }
}
void conDefPos(){
    struct consize actSize = conGetSize();
    conMove(actSize.rows - 2, 3);
}
void cleanInp(){
    int i = 0;
    struct consize actSize = conGetSize();
    for(i = 3; i < actSize.cols - 15; i++){
        conMove(actSize.rows - 2, i);
        printf(" ");
        conMove(actSize.rows - 3, i);
        printf(" ");
    }
    conDefPos();
}
void cleanCanvas(){
    int i = 0;
    int j = 0;
    conReset();
    struct consize actSize = conGetSize();
    for(j = 2; j < 22; j ++){
        for(i = 2; i < 24; i++){
            conMove(j, i);
            printf(" ");
        }
    }
    conDefPos();
}
char * getStringInter(char * whatGet){
    struct consize actSize = conGetSize();
    conMove(actSize.rows - 3, 3);
    printf("%s:", whatGet);
    conDefPos();
    char * result = getString();
    cleanInp();
    return result;
}
void exitInter(){
    conResize(20, 60);
    clearAnim();
    printText(EXIT_TEXT);
    sleepMillis(MILLIS_WAIT * 100);
    conClear();
}
int gameOver(){
    conResize(30, 60);
    clearAnim();
    struct consize actSize = conGetSize();
    printText(GAME_OVER);
    conMove(actSize.rows - 3, 3);
    printf("Play again? y / any key(not y)");
    conDefPos();
    char r = conGetChar();
    cleanInp();
    if (r == 'y') return 1;
    else return 0;
}


void printField(int  field [FIELD_ROWS ][FIELD_COLS]){
    for (int i = 0; i < FIELD_ROWS; ++i) {
        for (int j = 0; j < FIELD_COLS; ++j) {
            conMove(i + (FIELD_SHIFT), j + (FIELD_SHIFT));
            int cell = field [i][j];
            if(cell){
                conSetAttr(cell);
                if(cell == BG_INTENSITY_RED){
                    printf("%c", 169);
                } else {
                    printf(" ");
                }
            } else {
                conSetAttr(BG_DEFAULT);
                printf(" ");
            }
        }
    }
    conReset();
}
void printSnake(struct snake * head){
    conSetAttr(BG_INTENSITY_GREEN);
    struct snake * cur = head;
    while(cur != NULL){
        conMove(cur->row + FIELD_SHIFT, cur->col + FIELD_SHIFT);
        printf(" ");
        cur = cur->next;
    }
}
void showNext(struct tetr * current){
    for (int i = 0; i < TETR_MX_SIZE - 1; ++i) {
        for (int j = 0; j < TETR_MX_SIZE; ++j) {

            conMove(NEXT_ROW + i, NEXT_COL + j);

            if(isTetrFilled(current, i, j)){
                conSetAttr(current->color + 1);
                printf(" ");
            } else {
                conReset();
                printf(" ");
            }
        }
    }
    conReset();
}
void printTetr(struct tetr * current){
    conSetAttr(current->color);
    for (int i = 0; i < TETR_MX_SIZE; ++i) {
        for (int j = 0; j < TETR_MX_SIZE; ++j) {
            if(isTetrFilled(current, i, j)){
                conMove(current->row + i + FIELD_SHIFT, current->col + j + FIELD_SHIFT);
                if(isTetrFilled(current, i, j) == 2){
                    conSetAttr(current->color + 1 );
                }
                printf(" ");
                if(isTetrFilled(current, i, j) == 2){
                    conSetAttr(current->color + 1);
                }
            }
        }
    }
    conReset();
}


struct settings start() {
    struct settings result;
    struct consize actSize = conGetSize();
    result.fallTime = LEVELS[1];
    result.level = 1;
    char cmd= '\0';
    printAtStart();
    result.nickname = getStringInter("Enter your nickname");
    result.gameMode = askGameMode();
    conMove(actSize.rows - 3, 3);
    printText("\n\n\n\n\n\n\n\n\n\n\n\n"
                      "Hello player!\n"
                   "Press 1 to play\n"
                   "Press 2 to start from certain level (1 - 9)\n"
                   "Press 3 to see leaderboard. q - quit\n\n");
    char * temp;
    result.leaderboard = readSave();
    while(cmd != '1' && cmd != '2' && cmd != 'q'){
        cmd = conGetChar();
        switch (cmd){
            case 'q':
                result.gameMode = 0;
                break;
            case '2':
                temp = getStringInter("Enter level");
                result.level = atoi(temp);
                if (result.level > -1 && result.level <= MAX_LEVEL && isdigit(temp[0])) {
                    result.fallTime = LEVELS[result.level];
                } else {
                    result.level = 1;
                }
                free(temp);
                break;
            case '3':
                printLeaderboard(result.leaderboard);
                break;
        }
    }
    return result;
}
int askGameMode(){
    struct consize actSize = conGetSize();
    char cmd = '\0';
    int intense = 1;
    conHideCursor();
    conMove(actSize.rows - 3, 3);
    printf("Choose your destiny. A - left, D - right, W - select");
    while(cmd != 'w'){
        printIntense(intense);
        cmd = conGetChar();
        switch (cmd){
            case 'a':
                intense --;
                break;
            case 'd':
                intense ++;
                break;
        }
        if(intense > 3) intense = 1;
        if(intense < 1) intense = 3;
    }
    for(int i = 3; i < actSize.cols; i++){
        conMove(actSize.rows - 2, i);
        printf(" ");
        conMove(actSize.rows - 3, i);
        printf(" ");
    }
    printIntense(0);
    conShowCursor();

    return intense;
}
void printIntense(int intense){
    intense == 1 ? printT(T_ROW, T_COL, 1) : printT(T_ROW, T_COL, 0);
    intense == 2 ? printS(S_ROW, S_COL, 1) : printS(S_ROW, S_COL, 0);
    intense == 3 ? printTS(TS_ROW, TS_COL, 1) : printTS(TS_ROW, TS_COL, 0);
    return;
}
void printResult(int score, int level){
    conReset();
    conMove( 3, 31);
    printf("%i", score);
    conMove( 11, 30);
    printf("%i", level);
    conDefPos();
}
void printLeaderboard(struct player * arr){
    char temp;
    conClear();
    printText(LEADERBOARD);
    for(int i = 0; i < PLAYERS_MAX ; i ++){
        conMove(10 + i, 3);
        if(strcmp(arr[i].nickname, "") || arr[i].score != 0) {
            printf("[%i]. %s Score : %i", i + 1, arr[i].nickname, arr[i].score);
        }
        if(i == PLAYERS_MAX - 1){
            conMove(15 + i + 1, 3);
            printf("Press c to close leaderboard");
            while((temp = conGetChar()) != 'c'){
            }
        }
    }
    conClear();
    printAtStart();
    conSetAttr(FG_BLUE);
    printText(START_TEXT);
    conReset();
    printText("\n\n\n\n\n\n\n\n\n\n\n\n"
                      "Hello player!\n"
                      "Press 1 to play\n"
                      "Press 2 to start from certain level (1 - 9)\n"
                      "Press 3 to see leaderboard. q - quit\n\n");
    conDefPos();
}
void printT(int row, int col, int isIntense){
    if (!isIntense) {
        conSetAttr(BG_BLUE);
    } else {
        conSetAttr(BG_INTENSITY_RED);
    }
    conMove(row, col);
    printf("     ");
    conMove(row + 1 , col + 2);
    printf(" ");
    conMove(row + 2 , col + 2);
    printf(" ");
    conMove(row + 3 , col + 2);
    printf(" ");
    conMove(row + 4 , col + 2);
    printf(" ");
    conReset();
}
void printS(int row, int col, int isIntense){
    if (!isIntense) {
        conSetAttr(BG_GREEN);
    } else {
        conSetAttr(BG_INTENSITY_RED);
    }
    conMove(row, col);
    printf("   ");
    conMove(row + 1 , col);
    printf(" ");
    conMove(row + 2 , col);
    printf("   ");
    conMove(row + 3 , col + 2);
    printf(" ");
    conMove(row + 4 , col);
    printf("   ");
    conReset();
}
void printTS(int row, int col, int isIntense) {
    if (!isIntense) {
        conSetAttr(BG_BLUE);
    } else {
        conSetAttr(BG_INTENSITY_RED);
    }

    conMove(row, col);
    printf("     ");
    conMove(row + 1 , col + 2);
    printf(" ");
    if (!isIntense) {
        conSetAttr(BG_GREEN);
    } else {
        conSetAttr(BG_INTENSITY_RED);
    }
    conMove(row + 2 , col + 1);
    printf("   ");
    conMove(row + 3 , col + 3);
    printf(" ");
    conMove(row + 4 , col + 1);
    printf("   ");
    conReset();
}
