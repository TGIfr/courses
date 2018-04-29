#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list.h>
#include <events.h>
#include <pbconsole.h>
#include <string.h>

/* custom constant event type ids*/
typedef struct Timer Timer;
struct Timer {
    int id;
    int timeCounter;
    int state;
};
enum {
    KeyInputEventTypeId,
    EnterPressed = 1,
    TimerInit,
    TimerStop,
    TimerRunning,
    TimerChange,
    XTime = 3000,

};

typedef struct enterData enterData;

/* event handler functions prototypes */
void UpdatePrintHandler_update(EventHandler * self, Event * event);
void KeyInputHandler_update(EventHandler * self, Event * event);
void CustomHandler_handleEvent(EventHandler * self, Event * event);
void Timer_handleEvent(EventHandler * self, Event * event);


int main(void) {
    // startup event system
    EventSystem_init();

    // add event handlers
    EventSystem_addHandler(EventHandler_new(NULL, NULL, UpdatePrintHandler_update));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, KeyInputHandler_update));
    //#0
    Timer * timer = malloc(sizeof(Timer));
    timer->id = 0;
    timer->timeCounter = 0;
    timer->state = TimerRunning;
    EventSystem_addHandler(EventHandler_new(timer, free, Timer_handleEvent));
    //#1
     timer = malloc(sizeof(Timer));
    timer->id = 1;
    timer->timeCounter = 0;
    timer->state = TimerRunning;
    EventSystem_addHandler(EventHandler_new(timer, free, Timer_handleEvent));
    //#2
     timer = malloc(sizeof(Timer));
    timer->id = 2;
    timer->timeCounter = 0;
    timer->state = TimerRunning;
    EventSystem_addHandler(EventHandler_new(timer, free, Timer_handleEvent));
    //#3
     timer = malloc(sizeof(Timer));
    timer->id = 3;
    timer->timeCounter = 0;
    timer->state = TimerRunning;
    EventSystem_addHandler(EventHandler_new(timer, free, Timer_handleEvent));
    //#4
     timer = malloc(sizeof(Timer));
    timer->id = 4;
    timer->timeCounter = 0;
    timer->state = TimerRunning;
    EventSystem_addHandler(EventHandler_new(timer, free, Timer_handleEvent));

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
            printf("Press q to exit \n");
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

void Timer_handleEvent(EventHandler * self, Event * event) {
    Timer * timer = (Timer *)self->data;
    switch(event->type) {
        case UpdateEventTypeId: {
            if (timer->state == TimerRunning) {
                double elapsedMillis = *(double *)event->data;
                timer->timeCounter += elapsedMillis;
                if (timer->timeCounter  >= XTime) {
                    printf("\nTimer #%i: X\n", timer->id);
                    timer->timeCounter = 0;
                }
            }
            break;
        }
        case TimerInit:
            if(*(int *) event->data == timer->id){
                timer->state = TimerStop;
                timer->timeCounter = 0;
                printf("\nTimer #%i: Inited\n", timer->id);
            }
            break;
        case TimerChange:
            if(*(int *) event->data == timer->id){
                if (timer->state == TimerRunning) {
                    timer->state = TimerStop;
                    printf("\nTimer #%i: Stopped\n", timer->id);
                } else {
                    timer->state = TimerRunning;
                    printf("\nTimer #%i: Running\n", timer->id);
                }
            }
            break;
    }
}

void CustomHandler_handleEvent(EventHandler *self, Event *event) {
    if (event->type == KeyInputEventTypeId) {
        char *keyCodePtr = (char *) event->data;
        char keyCode = *keyCodePtr;
        switch (keyCode) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':;
                int *toSendChange = malloc(sizeof(int));
                *toSendChange = keyCode - '0';
                EventSystem_raiseEvent(Event_new(self, TimerChange, toSendChange, free));
                break;
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':;
                int *toSendInit = malloc(sizeof(int));
                *toSendInit = keyCode - '5';
                EventSystem_raiseEvent(Event_new(self, TimerInit, toSendInit, free));
                break;
            case 'q':
                EventSystem_exit();
                break;
        }
    }
}


