#include <stdlib.h>
#include <stdio.h>
#include <events.h>
#include <pbconsole.h>
#include <string.h>
#include <ctype.h>
#include "dataManagement.h"


const char * CONFIG_STR = "configuration.xml";
const char * AT_START = "Press q to exit (not in entering mode)\n"
        "Press enter to enter some data that will be send according to your further commands\n"
        "p for path, a for age, n for name, s for score, number from 0 to 9"
        " for book(data must be in format \"[field] data\"\n";

/* custom constant event type ids*/
enum {
    EnterUnpressed = -1,
    KeyInputEventTypeId,
    EnterPressed = 1,
    StrFillStopped,
    ChangePath,
    ChangeName,
    ChangeAge,
    ChangeScore,
    ChangeBook,
    LoadDataAtStart,
    SaveData,
    GivePath

};
struct enterData{
    int isPressedEnter;
    char str[200] ;
};
typedef struct enterData enterData;

/* event handler functions prototypes */
void UpdatePrintHandler_update(EventHandler * self, Event * event);
void KeyInputHandler_update(EventHandler * self, Event * event);

void CUIHandler_handleEvent(EventHandler * self, Event * event);
void ConfigurationHandler_handleEvent(EventHandler * self, Event * event);
void DataHandler_handleEvent(EventHandler * self, Event * event);
void EnteringHandler_handleEvent(EventHandler * self, Event * event);


int main(void) {
    // startup event system
    EventSystem_init();

    // add event handlers
    EventSystem_addHandler(EventHandler_new(NULL, NULL, UpdatePrintHandler_update));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));

    char * filePath = malloc(sizeof(200));
    EventSystem_addHandler(EventHandler_new(filePath, free, ConfigurationHandler_handleEvent));

    Teacher * teacher = Teacher_new();
    EventSystem_addHandler(EventHandler_new(teacher, free, DataHandler_handleEvent));

    enterData * tempData = malloc(sizeof(enterData));
    tempData->isPressedEnter = EnterUnpressed;
    tempData->str[0] = '\0';
    EventSystem_addHandler(EventHandler_new(tempData, free, EnteringHandler_handleEvent));

    enterData * data = malloc(sizeof(data));
    data->isPressedEnter = EnterUnpressed;
    data->str[0] = '\0';
    EventSystem_addHandler(EventHandler_new(data, free, CUIHandler_handleEvent));

    // start infinite event loop
    EventSystem_loop();
    // cleanup event system
    EventSystem_cleanup();
    return 0;
}

/* event handlers functions implementations */
void CUIHandler_handleEvent(EventHandler * self, Event * event){
    enterData * data = (enterData *)self->data;
    if(event->type == StrFillStopped){
        strcpy(data->str, event->data);
    }
    if(event->type == KeyInputEventTypeId) {
        char ch = *(char *)(event->data);
        if(ch == '\n'){
            EventSystem_raiseEvent(Event_new(self, EnterPressed, NULL, NULL));
            data->isPressedEnter = -data->isPressedEnter;
        }
        //for blocking ANY other input while string in EnteringHandler is filling
        if (data->isPressedEnter == EnterUnpressed && strlen(data->str) != 0) {
            switch(ch) {
                case 'q':
                    EventSystem_exit();
                    break;
                case 'a':
                    ;
                    int * age = malloc(sizeof(int));
                    *age = atoi(data->str);
                    EventSystem_raiseEvent(Event_new(self, ChangeAge, age, free));
                    data->str[0] = '\0';
                    break;
                case 's':
                    ;
                    float * score = malloc(sizeof(float));
                    *score = (float)atof(data->str);
                    EventSystem_raiseEvent(Event_new(self, ChangeScore, score, free));
                    data->str[0] = '\0';
                    break;
                case 'n':
                    ;
                    char * name = malloc(sizeof(data->str));
                    strcpy(name, data->str);
                    EventSystem_raiseEvent(Event_new(self, ChangeName, name, free));
                    data->str[0] = '\0';
                    break;
                case 'p':
                    ;
                    char * path = malloc(sizeof(data->str));
                    strcpy(path, data->str);
                    EventSystem_raiseEvent(Event_new(self, ChangePath, path, free));
                    data->str[0] = '\0';
                    break;
                case 'b':
                    ;
                    char * bookData = malloc(sizeof(data->str));
                    strcpy(bookData, data->str);
                    EventSystem_raiseEvent(Event_new(self, ChangeBook, bookData, free));
                    data->str[0] = '\0';
                    break;
            }
        }
    }
}
void ConfigurationHandler_handleEvent(EventHandler * self, Event * event){
    char * curPath = (char*) self->data;
    char * sendPath = NULL;
    switch (event->type) {
        case StartEventTypeId: {
            char temp[400] = "";
            if (readAllText(CONFIG_STR, temp) == 0) {
                printf("Cant find config file\n\n");
                EventSystem_exit();
                return;
            }
            loadPathFromXmlString(curPath, temp);
            //copies for sending

            sendPath = malloc(sizeof(curPath));
            strcpy(sendPath, curPath);
            EventSystem_raiseEvent(Event_new(self, LoadDataAtStart, sendPath, free));
            break;
        }
        case ChangePath: {
            char * newPath = (char *)event->data;
            strcpy(curPath, newPath);
            //copies for sending
            sendPath = malloc(sizeof(curPath));
            strcpy(sendPath, curPath);
            EventSystem_raiseEvent(Event_new(self, SaveData, sendPath, free));
            //saving new path in configuration.xml
            char xmlStr[200] = "";
            savePathToXmlString(xmlStr, curPath);

            if(writeText(CONFIG_STR, xmlStr) == 0)
                printf("Error while saving config\n");
            else
                printf("Config saved\n");
            break;
        }
        case GivePath:
            sendPath = malloc(sizeof(curPath));
            strcpy(sendPath, curPath);
            EventSystem_raiseEvent(Event_new(self, SaveData, sendPath, free));
            break;
    }
}
void DataHandler_handleEvent(EventHandler * self, Event * event){
    Teacher * teacher = (Teacher *) self->data;
    char * eventStr = (char *) event->data;
    switch (event->type) {
        case LoadDataAtStart: {
            char xmlStr[400] = "";
            if (readAllText(eventStr, xmlStr) == 0) {
                printf("Cant find data file\n\n");
                EventSystem_exit();
                return;
            }
            loadTeacherFromXmlString(teacher, xmlStr);
            printf("Teacher loaded\n");
            break;
        }
        case SaveData: {
            char strToSave[400] = "";
            saveTeacherToXmlString(strToSave, teacher);
            if(writeText(eventStr, strToSave) == 0)
                printf("Error saving data\n");
            else
                printf("Data saved\n");
            break;
        }
        case ChangeBook:
            ;
            int bookNumber = 0;
            char field[20];
            char data[50];
            char * temp = strtok(eventStr, " ");
            if(temp != NULL){
                bookNumber = atoi(temp);
                if(bookNumber < 0 || bookNumber > 9){
                    printf("Not correct number\n");
                    return;
                }
                temp = strtok(NULL, " ");
            }
            if(temp != NULL){
                strcpy(field, temp);
                temp = strtok(NULL, " ");
            }
            if(temp != NULL){
                strcpy(data, temp);
            }
            if(strcmp(field, "name") == 0){
                strcpy(teacher->books[bookNumber].name, data);
            } else if(strcmp(field, "rating") == 0){
                teacher->books[bookNumber].rating = atoi(data);
            } else {
                printf("Not correct field\n");
                return;
            }
            EventSystem_raiseEvent(Event_new(self, GivePath, NULL, NULL));
            break;
        case ChangeScore:
            ;
            float newScore = *(float *)event->data;
            teacher->score = newScore;
            EventSystem_raiseEvent(Event_new(self, GivePath, NULL, NULL));
            break;
        case ChangeAge:
            ;
            int age = *(int *)event->data;
            teacher->age = age;
            EventSystem_raiseEvent(Event_new(self, GivePath, NULL, NULL));
            break;
        case ChangeName:
            strcpy(teacher->name, eventStr);
            EventSystem_raiseEvent(Event_new(self, GivePath, NULL, NULL));
            break;

    }
}

void UpdatePrintHandler_update(EventHandler * self, Event * event) {

    switch (event->type) {
        case StartEventTypeId: {
            conClear();
            puts("");
            puts("<<<START!>>>");
            puts("");
            printf("%s", AT_START);
            break;
        }
        case ExitEventTypeId: {
            puts("");
            puts("<<<EXIT!>>>");
            puts("");
            break;
        }
    }
}

void KeyInputHandler_update(EventHandler * self, Event * event) {
    if (conIsKeyDown()) {  // non-blocking key input check
        char * keyCode = malloc(sizeof(char));
        *keyCode = getchar();
        EventSystem_raiseEvent(Event_new(self, KeyInputEventTypeId, keyCode, free));
    }
}

// part of CUI module
void EnteringHandler_handleEvent(EventHandler * self, Event * event){
    enterData * data = (enterData *)self->data;
    switch (event->type) {
        case EnterPressed:
            data->isPressedEnter = -data->isPressedEnter;
            if(data->isPressedEnter == EnterPressed){
                conClear();
                data->str[0] = '\0';
                printf("%sEnter pressed, your input is saving now \n\n", AT_START);
            } else {
                conClear();
                printf("%sEnter unpressed, your input is not saving now \n\n", AT_START);
                char * tempStr = malloc(sizeof(data->str));
                strcpy(tempStr, data->str);
                EventSystem_raiseEvent(Event_new(self, StrFillStopped, tempStr, free));
            }
        case KeyInputEventTypeId: {
            if(data->isPressedEnter == EnterUnpressed || event->data == NULL ) return;

            char buf[2];
            if(*((char *)event->data) == '\n') return;
            buf[0] = *((char *)event->data);
            buf[1] = '\0';
            strcat(data->str, buf);
            break;
        }
    }
}



