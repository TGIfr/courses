#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list.h>
#include <events.h>
#include <pbconsole.h>
#include <string.h>

/* custom constant event type ids*/
enum {
    EnterUnpressed = -1,
    KeyInputEventTypeId,
    EnterPressed = 1,

};
struct enterData{
    int isPressedEnter;
    char str[100] ;
};
typedef struct enterData enterData;

/* event handler functions prototypes */
void UpdatePrintHandler_update(EventHandler * self, Event * event);
void KeyInputHandler_update(EventHandler * self, Event * event);
void CustomHandler_handleEvent(EventHandler * self, Event * event);
void EnteringHandler_handleEvent(EventHandler * self, Event * event);


int main(void) {
    // startup event system
    EventSystem_init();

    // add event handlers
    EventSystem_addHandler(EventHandler_new(NULL, NULL, UpdatePrintHandler_update));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));
    enterData * data = malloc(sizeof(enterData));
    data->isPressedEnter = EnterUnpressed;
    data->str[0] = '\0';
    EventSystem_addHandler(EventHandler_new(data, free, EnteringHandler_handleEvent));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, CustomHandler_handleEvent));

    // start infinite event loop
    EventSystem_loop();
    // cleanup event system
    EventSystem_cleanup();
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
            printf("Press q to exit \n Enter unpressed, your input is not saving now \n\n");
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

void EnteringHandler_handleEvent(EventHandler * self, Event * event){
    enterData * data = (enterData *)self->data;
    switch (event->type) {
        case EnterPressed:
            data->isPressedEnter = -data->isPressedEnter;
            if(data->isPressedEnter == EnterPressed){
                conClear();
                data->str[0] = '\0';
                printf("Enter pressed, your input is saving now \n\n");
            } else {
                conClear();
                printf("Enter unpressed, your input is not saving now \n\n");
                puts(data->str);
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
void CustomHandler_handleEvent(EventHandler * self, Event * event) {
    switch (event->type) {
        case KeyInputEventTypeId: {
            char * keyCodePtr = (char *)event->data;
            char keyCode = *keyCodePtr;
            if (keyCode == '\n') {
                EventSystem_raiseEvent(Event_new(self, EnterPressed, NULL, NULL));
            }
            if (keyCode == 'q') {
                EventSystem_exit();
            }
            break;
        }
    }
}


