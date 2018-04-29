#include <progbase.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"
#include "dino.h"
#include "totest.h"
#include "saves.h"



int main(int argc, char * argv[]) {
    char key = '\0';
    if(argc > 1 && (!strcmp(argv[1], "-test"))){
        test();
    }
    const struct conShift MAIN_SHIFT = { 0, -10 + MAX_SIZE};
    const char *START_TEXT = "Hello User!  Welcome to jurasic's park pre-alpha version 0.0.0.0.0.0.1\n" \
        "You can choose what to do via pressing needed button. Press h for info\nPress q to quit program\n\0";
    const char *START_INFO = "Press 1 to rewrite certain field\n"
            "Press 2 to rewrite one dino\n"
            "Press 3 to delete needed position\n"
            "Press 4 to save data\n"
            "Press 5 to copy data from one dino to another\n"
            "Press 6 to find all dinos with mass less than X\n"
            "Press 7 to add dino if possible\n"
            "Press 8 to fill with some random data ALL fields(for tests only!)\n"
            "\n"
            "Press h to return\n\0";
    redraw(MAIN_SHIFT.cols , MAIN_SHIFT.rows );
    int flagMode = start("Press 1 for new array. Press 2 for existing array");
    char readFileName[100] = "";
    if(flagMode == 2){
        char * readFileTemp = getStringInter("read file name");
        strcpy( readFileName , readFileTemp);
        free(readFileTemp);
    }
    struct dino * arr = readFile(readFileName);
    cleanCanvas();
    printText(START_TEXT);
    printStructArr(arr);
    while(key != 'q'){
        key = conGetChar();
        switch (key) {
            case '1':
                ;
                char * number = getStringInter("number of a dino");
                char * toChange = getStringInter("new data");
                char * field = getStringInter("field to rewrite");
                if(atoi(number) >= MAX_SIZE || !isdigit(number[0])){
                    free(number);
                    free(toChange);
                    free(field);
                    continue;
                }
                changeField(&arr[atoi(number)], field, toChange, arr);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                printResult("field was changed");
                free(number);
                free(toChange);
                free(field);
                break;
            case '2':
                ;
                char * numberOfDino = getStringInter("number of a dino");
                char * name = getStringInter("name");
                char * age = getStringInter("age");
                char * friend = getStringInter("number of friend");
                char * mass = getStringInter("mass");
                if(atoi(numberOfDino) >= MAX_SIZE || !isdigit(numberOfDino[0])){
                    printResult("Not correct number");
                    free(numberOfDino);
                    free(name);
                    free(age);
                    free(friend);
                    free(mass);
                    continue;
                }
                changeField(&arr[atoi(numberOfDino)], "name", name, arr);
                changeField(&arr[atoi(numberOfDino)], "age", age, arr);
                changeField(&arr[atoi(numberOfDino)], "friend", friend, arr);
                changeField(&arr[atoi(numberOfDino)], "mass", mass, arr);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                printResult("Data was changed");
                free(numberOfDino);
                free(name);
                free(age);
                free(friend);
                free(mass);
                break;
            case '3':
                ;
                char * numberToDelete = getStringInter("number of a dino to delete");
                if(!isdigit(numberToDelete[0])){
                    printResult("Not correct number");
                    free(numberToDelete);
                    continue;
                }
                delete(arr, atoi(numberToDelete));
                free(numberToDelete);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                printResult("Dino was deleted. Or not");
                break;
            case '4':
                ;
                char * saveFileName = getStringInter("save file name");
                if(!saveFile(arr, saveFileName)){
                    printResult("Data saved");
                } else {
                    printResult("Save was absolutely sabotaged");
                }
                free(saveFileName);
                break;
            case '5':
                ;
                char * first = getStringInter("dino to rewrite");
                char * second = getStringInter("dino to copy");
                if(!isdigit(first[0]) || !isdigit(second[0]) ||
                        atoi(first) >= MAX_SIZE || atoi(second) >= MAX_SIZE){
                    printResult("Not correct numbers");
                    free(first);
                    free(second);
                    continue;
                }
                rewrite(arr, atoi(first), atoi(second));
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                printResult("Data copied");
                free(first);
                free(second);
                break;
            case '6':
                ;
                char * massLower = getStringInter("mass");
                char * result = findByMass(arr, atof(massLower));
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                if(strlen(result) == 0){
                    printResult("Not found");
                } else {
                    printResult(result);
                }
                free(result);
                free(massLower);
                break;
            case '7':
                ;
                char * data = getStringInter("data in format name age mass number of friend");
                cleanCanvas();
                if(!writeFromStr(arr, data)){
                    printResult("Added successfully");
                } else {
                    printResult("Added not successfully");
                }
                printText(START_TEXT);
                printStructArr(arr);
                free(data);
                break;
            case '8':
                fillRandArr(arr);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                printResult("Dinos were randomized");
                break;
            case 'h':
                cleanCanvas();
                printInfoText(START_INFO);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(arr);
                break;
            default: ;
        }
    }
    free(arr);
    exitInter();
    return 0;
}