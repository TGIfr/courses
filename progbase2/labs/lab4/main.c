#include <progbase.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"
#include "dino.h"
#include "totest.h"
#include "saves.h"
#include "list.h"


int main(int argc, char * argv[]) {

    char key = '\0';
    if(argc > 1 && (!strcmp(argv[1], "-test"))){
        test();
    }
    const struct conShift MAIN_SHIFT = { 0, -10 + MAX_SIZE};
    const char *START_TEXT = "Hello User!  Welcome to jurasic's park pre-alpha version 0.0.2.255\n" \
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
    struct List * list = readFile(readFileName);
    cleanCanvas();
    printText(START_TEXT);
    printStructArr(list);
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
                changeField(List_elementAt(list, atoi(number)), field, toChange, list);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
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
                changeField(List_elementAt(list, atoi(numberOfDino)), "name", name, list);
                changeField(List_elementAt(list, atoi(numberOfDino)), "age", age, list);
                changeField(List_elementAt(list, atoi(numberOfDino)), "friend", friend, list);
                changeField(List_elementAt(list, atoi(numberOfDino)), "mass", mass, list);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
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
                delete(list, atoi(numberToDelete));
                free(numberToDelete);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
                printResult("Dino was deleted. Or not");
                break;
            case '4':
                ;
                char * saveFileName = getStringInter("save file name");
                if(!saveFile(list, saveFileName)){
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
                rewrite(list, atoi(first), atoi(second));
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
                printResult("Data copied");
                free(first);
                free(second);
                break;
            case '6':
                ;
                char * massLower = getStringInter("mass");
                char * result = findByMass(list, atof(massLower));
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
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
                if(!writeFromStr(list, data)){
                    printResult("Added successfully");
                } else {
                    printResult("Added not successfully");
                }
                printText(START_TEXT);
                printStructArr(list);
                free(data);
                break;
            case '8':
                fillRandList(list);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
                printResult("Dinos were randomized");
                break;
            case 'h':
                cleanCanvas();
                printInfoText(START_INFO);
                cleanCanvas();
                printText(START_TEXT);
                printStructArr(list);
                break;
            default: ;
        }
    }
    List_free(&list);
    exitInter();
    return 0;
}