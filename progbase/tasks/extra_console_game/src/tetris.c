//
// Created by tgifr on 14.12.16.
//
#include "tetris.h"
#include "interface.h"

const char * TETRIS_TEXT = {"Hello player!\n"
                                    "Controls: w - rotate\na - move left\n"
                                    "d - move right\ns - fall down\n"
                                    "q - quit\n "
                                    "Press h to start\n"
};

int randColor(){
    srand(time(0));
    return 41 + rand() % COLOR_MAX;
}

int tetris(struct settings *setts) {
    int field[FIELD_ROWS][FIELD_COLS];

    //initializing
    for (int i = 0; i < (FIELD_ROWS) * (FIELD_COLS); ++i) {
        field[0][i] = 0;
    }

    int score = 0;
    char cmd = 0;
    int time1, time2;
    int endGame = 0;
    struct tetr current = spawnNewTetr(), next = spawnNewTetr();
    redraw();
    printT(LOGO_ROW, LOGO_COL, 0);
    printTextWait(TETRIS_TEXT);


    conHideCursor();
    time1 = clock();
    showNext(&next);
    printTetr(&current);
    printField(field);
    printResult(score, setts->level);
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
        }
        time2 = clock();
        if (((time2 - time1) * 1000 / CLOCKS_PER_SEC) > setts->fallTime) {
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


            printTetr(&current);
            time1 = clock();
            if (endGame) {
                break;
            }
        }
    }

    conShowCursor();

    return score;
}
int isFreeBlock (int row, int col, int field[][FIELD_COLS]) {
    if(field [row][col]){
        return 0;
    } else {
        return 1;
    }
}
void checkLevel(int score, int * level){
    int check = *level;
    if(score < 100){
        *level = 1;
    }
    if(score >= 100){
        *level = 2;
    }
    if(score >= 200){
        *level = 3;
    }
    if(score >= 300){
        *level = 4;
    }
    if(score >= 400){
        *level = 5;
    }
    if(score >= 500){
        *level = 6;
    }
    if(score >= 600){
        *level = 7;
    }
    if(score >= 700) {
        *level = 8;
    }
    if(score >= 800){
        *level = 9;
    }
    if(check > *level){
        *level = check;
    }
}

int tetrCheck(struct tetr *current, int field[][FIELD_COLS]) {
    for (int iField = current->row, iTetr = 0; iField < current->row + TETR_MX_SIZE; iField++, iTetr++) {
        for (int jField = current->col, jTetr = 0; jField < current->col + TETR_MX_SIZE; jField++, jTetr++) {
            if (jField < 0 ||
                jField > FIELD_COLS - 1 ||
                iField > FIELD_ROWS - 1) {
                if (isTetrFilled(current, iTetr, jTetr) != 0)
                    return 0;
            }
            if (jField >= 0) {
                if ((isTetrFilled(current, iTetr, jTetr) != 0) &&
                    (!isFreeBlock(iField, jField, field)))
                    return 0;
            }
        }
    }
    return 1;
}
int deletePossibleLines(int field[][FIELD_COLS]) {
    int count = 0;
    for (int j = 0; j < FIELD_ROWS; j++) {
        int i = 0;
        while (i < FIELD_COLS) {
            if (!field[j][i]) break;
            i++;
        }
        if (i == FIELD_COLS) {
            count++;
            deleteLine(j, field);
        }
    }
    return count;
}
struct tetr spawnNewTetr() {
    struct tetr result;
    result.type = randTetr();
    result.color = randColor();
    result.col = XTetrStartPos(&result);
    result.row = YTetrStartPos(&result);
    result.rotation = 0;
    return result;
}
int randTetr(){
    srand(clock());
    return rand() % TETR_TYPES;
}
void deleteLine(int row, int field[][FIELD_COLS]) {
    for (int j = row; j > 0; j--) {
        for (int i = 0; i < FIELD_COLS; i++) {
            field[j][i] = field[j - 1 ][i];
        }
    }
}

int isGameOver(int field[][FIELD_COLS]) {
    for (int i = 0; i < FIELD_COLS; i++) {
        if (field[0][i]) return 1;
    }
    return 0;
}

int isTetrFilled(struct tetr *current, int row, int col) {
    return tetrs[current->type][current->rotation][row][col];
}

int XTetrStartPos(struct tetr *current) {
    return tetrsStartPos[current->type][0];
}

int YTetrStartPos(struct tetr *current) {
    return tetrsStartPos[current->type][1];
}

void addTetrToField(struct tetr *current, int field[][FIELD_COLS]) {
    for (int iField = current->row, iTetr = 0; iField < current->row + TETR_MX_SIZE; iField++, iTetr++) {
        for (int jField = current->col, jTetr = 0; jField < current->col + TETR_MX_SIZE; jField++, jTetr++) {
            if (isTetrFilled(current, iTetr, jTetr) != 0)
                field[iField][jField] = current->color;
        }
    }
}

char tetrs[7 /*kind */ ][4 /* rotation */ ][5 /* horizontal*/ ][5 /* vertical */ ] = {
        // Square
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        // I
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 1},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {1, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        // L
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        // L mirrored
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        // Z
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        // Z mirrored
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        },
        // T
        {
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                },
                {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 2, 1, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                }
        }
};

int tetrsStartPos[7 /*kind */ ][2 /* position */] = {
        {6, -2},// Square
        {6, -2},// I
        {6, -1},// L
        {6, -1},// L mirrored
        {6, -1},// z
        {6, -1},// Z mirrored
        {6, -1},// T
};
