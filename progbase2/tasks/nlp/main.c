#include <stdio.h>
#include "listP.h"
#include "save.h"



void sort(struct Text **self);

const char * inputF = "input.txt";
const char * outputF = "output.txt";

int main() {
    Text * text = readText(inputF);
    sort(&text);
    saveText(outputF, text);
    Text_free(&text);
    return 0;
}

void sort(struct Text **self)
{
    struct Text *sorted = Text_new();
    struct Sentence *current;
    int length = textLength(*self);
    for (int i = 0; i < length; ++i) {
        current = Text_deleteFirst(*self);
        sortedInsert(sorted, current);
    }
    *self = sorted;
}