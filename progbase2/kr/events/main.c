#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list.h>
#include <events.h>
#include <pbconsole.h>
#include <string.h>
#include <ctype.h>

/* custom constant event type ids*/
enum {

    KeyInputEventTypeId,
    CharGetFromFile,
    TimeToGetChar,
    SpaceBarPressed,
    OutputGo,
    OutputPause,
    FileEnd,
    PunctFound,
    XTime = 250,


};

typedef struct Timer Timer;
struct Timer {
    int state;
    int timeCounter;
};


/* event handler functions prototypes */
void UpdatePrintHandler_update(EventHandler * self, Event * event);
void KeyInputHandler_update(EventHandler * self, Event * event);
void CustomHandler_handleEvent(EventHandler * self, Event * event);
void Timer_handleEvent(EventHandler * self, Event * event);
void FileReadHandler_update(EventHandler * self, Event * event);
void FileInputHandler_handleEvent(EventHandler * self, Event * event);
void PunctInputHandler_handleEvent(EventHandler * self, Event * event);

void fcloseWrap(void * file){
    fclose(file);
}
const char * INPUT_F = "input.txt";

int main(void) {
    // startup event system
    EventSystem_init();

    // add event handlers
    EventSystem_addHandler(EventHandler_new(NULL, NULL, UpdatePrintHandler_update));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));
    Timer * timer = malloc(sizeof(Timer));
    timer->timeCounter = 0;
    timer->state = OutputGo;
    EventSystem_addHandler(EventHandler_new(timer, free, Timer_handleEvent));
    FILE * input;
    if(!(input = fopen(INPUT_F, "r"))){
        printf("CANT OPEN FILE");
        EventSystem_cleanup();
        return EXIT_FAILURE;
    }
    EventSystem_addHandler(EventHandler_new(input, fcloseWrap, FileReadHandler_update));
    List * list = List_new();
    EventSystem_addHandler(EventHandler_new(list, NULL, FileInputHandler_handleEvent));
    EventSystem_addHandler(EventHandler_new(list, NULL, PunctInputHandler_handleEvent));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, CustomHandler_handleEvent));
    // start infinite event loop
    EventSystem_loop();
    // cleanup event system
    EventSystem_cleanup();
    List_free(&list);
    return 0;
}

/* event handlers functions implementations */

void UpdatePrintHandler_update(EventHandler * self, Event * event) {
    switch (event->type) {
        case StartEventTypeId: {
            conClear();
            puts("");
            puts("<<<START!>>>");
            puts("");
            printf("Press ' ' to stop, q to exit \n n\n");
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
void FileReadHandler_update(EventHandler * self, Event * event) {
    if (event->type == TimeToGetChar) {
        FILE * input = (FILE *) self->data;
        if (!feof(input)) {
            char * chToSend = malloc(sizeof(char));
            *chToSend = fgetc(input);
            printf("%c", *chToSend);
            fflush(stdout);
            EventSystem_raiseEvent(Event_new(self, CharGetFromFile, chToSend, free));
        } else {
            EventSystem_raiseEvent(Event_new(self, FileEnd, NULL, NULL));
            printf("FILE END\n\n\n");
            EventSystem_exit();
        }
    }
}

void Timer_handleEvent(EventHandler * self, Event * event) {
    Timer * timer = (Timer *)self->data;
    switch(event->type) {
        case UpdateEventTypeId:
            if (timer->state == OutputGo) {
                double elapsedMillis = *(double *) event->data;
                timer->timeCounter += elapsedMillis;
                if (timer->timeCounter >= XTime) {
                    EventSystem_raiseEvent(Event_new(self, TimeToGetChar, NULL, NULL));
                    timer->timeCounter = 0;
                }
            }

            break;
        case SpaceBarPressed:
            if(timer->state == OutputGo) timer->state = OutputPause;
                else timer->state = OutputGo;
            break;


    }
}
void FileInputHandler_handleEvent(EventHandler * self, Event * event) {
    List* list = (self->data);
    switch (event->type) {
        case CharGetFromFile: {
            char * keyCodePtr = (char *)event->data;
            char keyCode = *keyCodePtr;
            char * toSave  = malloc(sizeof(char));
            *toSave = keyCode;
            if (ispunct(keyCode)) {
                List_add(list, toSave);

                EventSystem_raiseEvent(Event_new(self, PunctFound, NULL, NULL));

            }
            if (keyCode == 'q') {
                EventSystem_exit();
            }
            break;
        }
    }
}
void PunctInputHandler_handleEvent(EventHandler * self, Event * event) {
    List* list = (self->data);
    switch (event->type) {
        case PunctFound: {
            printf("\nPUNCT FOUND\n");
            for (int i = 0; i < List_count(list); ++i) {
                char * ch = List_get(list, i);
                char key = * ch;
                printf("%c\n", key);
            }
        }
    }
}
void CustomHandler_handleEvent(EventHandler * self, Event * event) {
    switch (event->type) {
        case KeyInputEventTypeId: {
            char * keyCodePtr = (char *)event->data;
            char keyCode = *keyCodePtr;
            if (keyCode == ' ') {
                EventSystem_raiseEvent(Event_new(self, SpaceBarPressed, NULL, NULL));
            }
            if (keyCode == 'q') {
                EventSystem_exit();
            }
            break;
        }
    }
}


