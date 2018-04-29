//
// Created by tgifr on 19.02.17.
//

#include <assert.h>
#include "list.h"
#include "dino.h"
#include "dino.h"

struct List {
    dino * head;
};

struct List * createDinoList(){
    struct List * result = malloc(sizeof(struct List));
    result->head = dino_new();
    struct dino * temp = result->head;
    for (int i = 1; i < MAX_SIZE; ++i) {
        temp->next = dino_new();
        temp = temp->next;
    }
    return result;
}
int dino_count(struct List *self) {
    int count = 0;
    struct dino * cur = self->head;
    while (cur != NULL) {
        count += 1;
        cur = cur->next;
    }
    return count;
}
struct dino * List_elementAt(struct List *self, int position) {
    assert(position >= 0);
    if (self == NULL) assert(0); // just to throw error
    int i = 0;
    struct dino * cur = self->head;
    while (cur->next != NULL && i != position) {
        i += 1;
        cur = cur->next;
    }
    if (i != position) assert(0);
    return cur;
}
struct dino *dino_new() {
    struct dino * node = (struct dino*)malloc(sizeof(struct dino));
    node->next = NULL;
    return node;
}

void List_free(struct List **self) {
    assert(NULL != self);
    struct dino * temp;
    struct dino * cur = (*self)->head;
    while(cur!= NULL){
        temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(*self);
    *self = NULL;
}
