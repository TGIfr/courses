//
// Created by tgifr on 16.12.16.
//
#include "snake.h"
#include "interface.h"

const char * SNAKE_TEXT = {"Hello player!\n"
                                    "Controls: i - up\nj - left\n"
                                    "l - right\nk -  down\n"
                                    "q - quit\n "
                                    "Press h to start\n"
};


int snake(struct settings *setts) {
    int field[FIELD_ROWS][FIELD_COLS];

    //initializing
    for (int i = 0; i < (FIELD_ROWS) * (FIELD_COLS); ++i) {
        field[0][i] = 0;
    }

    int score = 0;
    char cmd = 0;
    int time1, time2;
    int endGame = 0, foodOnField = 1;
    int directionCol = 0, directionRow = DOWN;
    printS(LOGO_ROW, LOGO_COL, 0);
    redraw();
    printTextWait(SNAKE_TEXT);

    cleanCanvas();
    struct snake head = {10, 10, NULL};
    conHideCursor();
    time1 = clock();
    initializeSnake(&head);
    addFood(&head, field);
    printField(field);
    printSnake(&head);
    printResult(score, setts->level);
    while (cmd != 'q') {
        conLockInput();
        cmd = getchar();
        conUnlockInput();
        switch (cmd) {
            case 'i':
                directionRow = UP;
                directionCol = 0;
                break;
            case 'j':
                directionCol = LEFT;
                directionRow = 0;
                break;
            case 'l':
                directionCol = RIGHT;
                directionRow = 0;
                break;
            case 'k':
                directionCol = 0;
                directionRow = DOWN;
                break;
        }
        time2 = clock();
        if (((time2 - time1) * 1000 / CLOCKS_PER_SEC) > setts->fallTime) {
            endGame = move(&head, &directionCol, &directionRow, &foodOnField, field);
            if (!foodOnField) {
                foodOnField = 1;
                score += 35;
                addFood(&head, field);

                checkLevel(score, &setts->level);
                printResult(score, setts->level);
                setts->fallTime = LEVELS[setts->level];

            }
            printField(field);
            printSnake(&head);


            time1 = clock();
            if (endGame) {
                break;
            }
        }
    }

    conShowCursor();
    return score;
}
void initializeSnake (struct snake * head){
    head->next = newPart(head->row - 1, head->col);
    head->next->next = newPart(head->row - 2, head->col );
    head->next->next->next = newPart(head->row - 3, head->col );
    head->next->next->next->next = newPart(head->row - 4, head->col );
}
struct snake * newPart(int row, int col){
    struct snake * new = malloc(sizeof(struct snake));
    new->col = col;
    new->row = row;
    new->next = NULL;
    return new;
}
void addFood(struct snake * head, int field[][FIELD_COLS]){
    srand(time(0));
    int row = - 1;
    int col;
    struct snake * cur = head;
    while(row == -1){
        row = rand() % 20;
        col = rand() % 22;
        while(cur != NULL ){
            if(cur->row == row && cur->col == col){
                row = -1;
                break;
            }
            cur = cur->next;
        }
    }
    field[row][col] = BG_INTENSITY_RED;
}
int move(struct snake *head, int *directionCol, int *directionRow, int *foodOnField, int field[][FIELD_COLS]) {
    int addFlag = 0;
    if((head->row + *directionRow == head->next->row) && (head->col + *directionCol == head->next->col)){
        *directionRow = - *directionRow;
        *directionCol = - *directionCol;
    }
    if(head->row + *directionRow < 0 || head->col + *directionCol > 29 ||
            head->row + *directionRow >  19 || head->col + *directionCol < 0){
        return 1;
    }
    if(field[head->row + *directionRow][head->col + *directionCol]){
        field[head->row + *directionRow][head->col + *directionCol] = 0;
        * foodOnField = 0;
        addFlag = 1;
    }
    int rowTemp;
    int colTemp;

    struct snake * cur = head;
    rowTemp = cur->row;
    colTemp = cur->col;
    while(cur->next != NULL ){



        swap(&cur->next->row , &rowTemp);
        swap(&cur->next->col , &colTemp);
        if(cur == head){
            head->col += *directionCol;
            head->row += *directionRow;
        }
        if(cur != head && (head->row == cur->next->row && head->col == cur->next->col)){
            return 1;
        }
        cur = cur->next;
    }
    if(addFlag){
        cur->next = newPart(rowTemp, colTemp);
    }


    return 0;
}
void swap (int * a, int * b){
    int temp = * a;
    * a = * b;
    * b = temp;
}
