//
// Created by tgifr on 16.12.16.
//

#include "interface.h"
#include "tetrisnake.h"

const char * TETRISNAKE_TEXT = {"Hello player!\n"
                                   "Controls: i - up\nj - left\n"
                                   "l - right\nk -  down\n"
                                   "w - rotate\na - move left\n"
                                   "d - move right\ns - fall down\n"
                                   "q - quit\n "
                                   "Press h to start\n"
};


int tetrisnake(struct settings *setts) {
    int field[FIELD_ROWS][FIELD_COLS];

    //initializing
    for (int i = 0; i < (FIELD_ROWS) * (FIELD_COLS); ++i) {
        field[0][i] = 0;
    }

    int score = 0;
    char cmd = 0;
    int time1T, time2T, time1S, time2S;
    int endGame = 0;
    struct tetr current = spawnNewTetr(), next = spawnNewTetr();
    redraw();
    int directionCol = 0, directionRow = DOWN;
    printTS(LOGO_ROW, LOGO_COL, 0);
    printTextWait(TETRISNAKE_TEXT);
    int foodOnField = 1;

    conHideCursor();
    time1S = time1T = clock();
    struct snake head = {10, 10, NULL};
    initializeSnake(&head);

    printResult(score, setts->level);
    showNext(&next);
    printField(field);
    printTetr(&current);
    printSnake(&head);
    while (cmd != 'q') {
        conLockInput();
        cmd = getchar();
        conUnlockInput();
        switch (cmd) {
            case 'w':
                current.rotation = (current.rotation + 1) % 4;
                if (!tetrCheck(&current, field)) {
                    current.rotation = (current.rotation + 3) % 4;
                }
                break;
            case 'a':
                current.col += LEFT;
                if (!tetrCheck(&current, field)) {
                    current.col += RIGHT;
                }
                break;
            case 'd':
                current.col += RIGHT;
                if (!tetrCheck(&current, field)) {
                    current.col += LEFT;
                }
                break;
            case 's':
                setts->fallTime = LEVELS[0];
                break;
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
        time2S = time2T = clock();
        if (((time2T - time1T) * 1000 / CLOCKS_PER_SEC) > setts->fallTime) {
            current.row++;
            if (!tetrCheck(&current, field)) {
                current.row--;
                addTetrToField(&current, field);
                if (isGameOver(field)) {
                    endGame = 1;
                }
                current = next;
                next = spawnNewTetr();
                showNext(&next);

                score += 100 * deletePossibleLines(field); //deleting with dropping
                printResult(score, setts->level);

                checkLevel(score, &setts->level);
                setts->fallTime = LEVELS[setts->level];
            }
            printField(field);
            printSnake(&head);

            printTetr(&current);
            time1T = clock();
            if (endGame) {
                break;
            }
        }

        if (((time2S - time1S) * 1500 / CLOCKS_PER_SEC) > setts->fallTime) {
            //stop tetr while falling if head is close
            if (!tetrCheckSnake(&current, &head , &directionCol, &directionRow)) {
                addTetrToField(&current, field);
                current = next;
                next = spawnNewTetr();
                showNext(&next);
            }
            endGame = move(&head, &directionCol, &directionRow, &foodOnField, field);
            if (!foodOnField) {
                foodOnField = 1;
                score += 35;
                printResult(score, setts->level);
                checkLevel(score, &setts->level);
            }
            printField(field);
            printSnake(&head);
            printTetr(&current);

            time1S = clock();
            if (endGame) {
                break;
            }
        }
    }

    conShowCursor();

    return score;
}

int tetrCheckSnake(struct tetr *current, struct snake * head,  int * directionRow, int * directionCol) {
    int rowShift = head->row + *directionRow - current->row;
    int colShift = head->col + *directionCol - current->col;
    if(rowShift >= 0 && rowShift < TETR_MX_SIZE && colShift >= 0 && colShift < TETR_MX_SIZE   ){
        if( isTetrFilled(current, rowShift, colShift)){
            return 0;
        }
    }
    return 1;
}