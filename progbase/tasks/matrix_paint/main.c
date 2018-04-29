#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>


int main() {
    char image[28][28] = {
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { 'D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D' },
    { 'D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D' },
    { 'D','D','D','D','D','D','D','D','D','D','B','B','B','D','D','D','D','D','D','D','D','D','D','D','D','D','D','D' },
    { 'D','D','D','D','D','D','D','D','D','2','B','2','B','B','D','D','D','D','D','D','D','D','D','D','D','D','D','D' },
    { 'D','D','D','D','A','D','D','D','D','2','2','9','2','B','D','D','D','9','9','9','D','D','D','D','D','D','D','D' },
    { 'D','D','A','A','3','A','A','D','D','2','A','2','A','B','D','D','9','9','6','9','9','D','D','D','D','D','D','D' },
    { 'D','A','A','3','9','3','A','A','D','D','D','4','D','D','D','D','D','9','9','9','D','D','D','D','D','D','D','D' },
    { 'D','D','A','A','3','4','A','A','D','D','D','4','D','D','4','D','D','D','5','D','D','D','D','D','D','D','D','D' },
    { 'D','D','D','A','A','A','4','D','D','D','D','4','4','4','4','D','D','D','5','D','D','D','D','D','D','D','D','D' },
    { 'D','D','D','D','D','4','4','4','D','D','4','4','D','D','D','D','D','5','D','D','D','D','D','D','D','D','D','D' },
    { '6','D','D','D','D','D','D','D','4','D','4','D','D','D','D','D','5','D','D','D','D','D','D','D','D','D','D','6' },
    { '6','6','D','D','D','D','D','D','D','4','5','D','D','D','D','5','4','4','4','5','D','D','D','D','6','6','6','6' },
    { '6','6','6','6','D','D','6','D','D','D','5','6','D','D','5','D','5','5','5','4','5','D','6','6','6','6','6','6' },
    { '6','6','6','6','6','6','6','6','6','6','5','6','6','5','6','6','6','6','6','6','6','6','6','6','6','6','6','6' },
    { '6','6','6','6','6','6','6','6','6','6','5','6','5','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6' },
    { '6','6','6','6','6','6','6','6','6','6','6','5','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6','6' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' },
    { '1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1' }
};
    const char colorsTable[16][2] = {
        {'0', BG_BLACK},
        {'2', BG_RED},
        {'4', BG_GREEN},
        {'3', BG_YELLOW},
        {'E', BG_BLUE},
        {'A', BG_MAGENTA},
        {'8', BG_CYAN},
        {'7', BG_WHITE},
        {'1', BG_INTENSITY_BLACK },
        {'C', BG_INTENSITY_RED} ,
        {'5', BG_INTENSITY_GREEN},
        {'6', BG_INTENSITY_YELLOW},
        {'9', BG_INTENSITY_BLUE},
        {'B', BG_INTENSITY_MAGENTA},
        {'D', BG_INTENSITY_CYAN},
        {'F', BG_INTENSITY_WHITE}
    };

    /*  Change TIME_TASKS_SHOW to change pause between tasks */
    const unsigned long TIME_TASKS_SHOW = 2000;


    const unsigned long MILLIS = 20;
    int colorsTableLength = sizeof(colorsTable) / sizeof(colorsTable[0]);
    char colorsPalette[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int colorsPaletteLength = sizeof(colorsPalette) / sizeof(colorsPalette[0]);
    int i = 0, j = 0, x = 0, y = 0;
    int colorPairIndex = 0;
    int x_change = 0, y_change = 0;
    char temp = '\0';
    conClear();
    /* TASK 1*/
    for (i = 0; i < colorsPaletteLength; i++)
    {
        char colorCode = '\0';
        char color = '\0';
        /* get current color code from colorsPalette */
        colorCode = colorsPalette[i];
        /* find corresponding color in table */
        for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
        {
            char colorPairCode = colorsTable[colorPairIndex][0];
            char colorPairColor = colorsTable[colorPairIndex][1];
            if (colorCode == colorPairCode)
            {
                color = colorPairColor;
                break;  /* we have found our color, break the loop */
            }
        }
        /* print space with founded color background */
        conSetAttr(color);
        putchar(' ');
    }
    puts("");
    conReset();
    sleepMillis(TIME_TASKS_SHOW);

    /*TASK 2*/
    /* I don`t know why conClear makes all background white, so I don't use it here*/
    /*conClear();*/
    for(i = 0; i < 28; i++){
        for(j = 0; j < 28; j ++){
            char colorCode = '\0';
            char color = '\0';
            colorCode = image[i][j];
            for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];
                if (colorCode == colorPairCode) {
                    color = colorPairColor;
                    break;
                }
            }
            conSetAttr(color);
            putchar(' ');
            /*fflush(stdout);
            sleepMillis(MILLIS);*/
        }
        conReset();
        puts("");
    }
    conReset();
    puts("");
    sleepMillis(TIME_TASKS_SHOW);

    /*TASK 3*/
    conClear();
    for(x = 0, y = 0; x < 28 && y < 28; ){
        char colorCode = '\0';
        char color = '\0';
        conMove(y + 1, x + 1 );
        colorCode = image[y][x];
        for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
        {
            char colorPairCode = colorsTable[colorPairIndex][0];
            char colorPairColor = colorsTable[colorPairIndex][1];
            if (colorCode == colorPairCode) {
                color = colorPairColor;
                break;
            }
        }
        conSetAttr(color);
        putchar(' ');
        fflush(stdout);
        sleepMillis(MILLIS);
        if(x == 0 && !x_change  && y != 27 ){
            x_change = 1;
            y_change = 0;
            y ++;
            continue;
        }
        if( y == 0 && !y_change  && x != 27){
            y_change = 1;
            x_change = 0;
            x ++;
            continue;
        }
        if(y == 27 && y_change){
            y_change = 0;
            x_change = 1;
            x ++;
            continue;
        }
        if(x == 27 && x_change ){
            x_change = 0;
            y_change = 1;
            y ++;
            continue;
        }
        if(x_change == 1){
            x ++;
            y --;
        }
        if(y_change == 1){
            y ++;
            x --;
        }
    }
    conReset();
    conMove(28,0);
    puts("");
    sleepMillis(TIME_TASKS_SHOW);

    /*TASK 4*/
    conClear();
    for(i = 0, x = 27; i < 14; i++, x --){
        for(j = 0, y = 27; j < 28; j ++, y --){
            temp = image[i][j];
            image[i][j] = image[x][y];
            image[x][y] = temp;
        }
    }
    for(i = 0; i < 28; i++){
        for(j = 0; j < 28; j ++){
            char colorCode = '\0';
            char color = '\0';
            colorCode = image[i][j];
            for (colorPairIndex = 0; colorPairIndex < colorsTableLength; colorPairIndex++)
            {
                char colorPairCode = colorsTable[colorPairIndex][0];
                char colorPairColor = colorsTable[colorPairIndex][1];
                if (colorCode == colorPairCode) {
                    color = colorPairColor;
                    break;
                }
            }
            conSetAttr(color);
            putchar(' ');
            /*fflush(stdout);
            sleepMillis(MILLIS);*/
        }
        conReset();
        puts("");
    }
    conReset();
    puts("");
    return 0;
}
