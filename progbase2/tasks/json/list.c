//
// Created by tgifr on 26.02.17.
//

#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include "list.h"


Teacher *Teacher_new() {
    Teacher * res = malloc(sizeof(Teacher));
    for(int i = 0; i < BOOKS_SIZE; i++){
        strcpy(res->books[i].name, "");
        res->books[i].rating = 0; // 0 means that it is empty
    }
    return res;
}
void Teacher_free(Teacher ** teacher){
    free(*teacher);
    *teacher = NULL;
}

char * Teacher_getName(Teacher *teacher){
    return teacher->name;
}
int Teacher_getAge(Teacher *teacher){
    return teacher->age;
}
float Teacher_getScore(Teacher *teacher){
    return teacher->score;
}
Book *Teacher_getBook(Teacher *teacher, int index) {
    return &(teacher->books[index]);
}



#define throw(MSG) assert(0 && MSG);

struct List {
    size_t capacity;
    size_t size;
    void ** items;    /**< holds a pointer to items array */
};

static const int initialCapacity = 4;

static void __ensureCapacity(List * self, size_t min);

List * List_new(void) {
    List * self = malloc(sizeof(struct List));
    self->capacity = initialCapacity;
    self->size = 0;
    self->items = malloc(0);
    __ensureCapacity(self, 0);
    return self;
}

void List_free(List ** selfPtr) {
    if (selfPtr == NULL) throw("Null pointer on free()");
    List * self = *selfPtr;
    free(self->items);
    free(self);
    *selfPtr = NULL;
}

void * List_get(List * self, int index) {
    if (index < 0 || index >= self->size) throw("Index out of bounds");
    return self->items[index];
}
void List_set(List * self, int index, void * ref) {
    if (ref == NULL) throw("NULL reference");
    if (index < 0 || index >= self->size) throw("Index out of bounds");
    self->items[index] = ref;
}
void List_add(List * self, void * ref) {
    if (ref == NULL) throw("NULL reference");
    if (self->size <= self->capacity) {
        __ensureCapacity(self, self->size + 1);
    }
    List_set(self, self->size++, ref);
}


int List_indexOf(List * self, void * ref) {
    if (ref == NULL) throw("NULL reference");
    for (int i = 0; i < self->size; i++) {
        if (self->items[i] == ref) {
            return i;
        }
    }
    return -1;
}

int List_contains(List * self, void * ref) {
    if (ref == NULL) throw("NULL reference");
    return List_indexOf(self, ref) >= 0;
}



int List_isEmpty(List * self) {
    return self->size == 0;
}

int  List_count(List * self) {
    return self->size;
}


static void __ensureCapacity(List * self, size_t min) {
    if (self->size <= min) {
        int newCapacity = self->size == 0 ? initialCapacity : self->size * 2;
        if (newCapacity < min) newCapacity = min;
        self->capacity = newCapacity;
        size_t newSize = sizeof(void *) * self->capacity;
        self->items = realloc(self->items, newSize);
    }
}

