#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct List List;

List * List_new(int size);
void List_free(List ** listPtr);

int main(void) {
    List * list = List_new(100);
    List_free(&list);
    return 0;
}

struct List {
    int size;
    int * array;
};

List * List_new(int size) {
    List * list = malloc(sizeof(List));
    list->array = malloc(size * sizeof(int));
    memset(list->array, 0, size * sizeof(int));
    list->size = size;
    return list;
}

void List_free(List ** listPtr) {
    free((*listPtr)->array);
    free(*listPtr);
    *listPtr = NULL;
}