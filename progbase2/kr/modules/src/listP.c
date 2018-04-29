//
// Created by tgifr on 19.02.17.
//

#include "listP.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



struct Word {
    char* value;
    struct Word * next;
};


struct Sentence {
    struct Word* head;
    struct Sentence* next;
};

struct Text {
    struct Sentence * head;
};

struct Word * Word_new(char* value){
    Word * node = (Word *)malloc(sizeof(struct Word));
    if(value == NULL){
        node->value = malloc(sizeof(char));
        strcpy(node->value, "");
    } else {
        node->value = malloc(sizeof(char) * (1 + strlen(value)));
        strcpy(node->value, value);
    }

    return node;
}

struct Sentence * Sentence_new(void){
    Sentence * list = (Sentence *)malloc(sizeof(struct Sentence));
    list->head = NULL;
    list->next = NULL;
    return list;
}
struct Text * Text_new(void){
    Text * list = (Text *)malloc(sizeof(struct Text));
    list->head = NULL;
    return list;
}

void Word_free(struct Word ** self){
    assert(NULL != self);
    free((*self)->value);
    free(*self);
    *self = NULL;
}
void Sentence_free(struct Sentence ** self){
    assert(NULL != self);
    Word *cur = (*self)->head;
    while(cur!= NULL){
        Word* temp = cur;
        cur = cur->next;
        Word_free(&temp);
    }
    free(*self);
    *self = NULL;
}
void Text_free(struct Text ** self){
    assert(NULL != self);
    Sentence *cur = (*self)->head;
    while(cur!= NULL){
        Sentence * temp = cur;
        cur = cur->next;
        Sentence_free(&temp);
    }
    free(*self);
    *self = NULL;

}



void Sentence_addLast(struct Sentence *self, Word *newWord){
    if (self->head == NULL) {
        self->head = newWord;
        return;
    }
    struct Word * cur = self->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newWord;
}

void Text_addLast(struct Text *self, Sentence *newSentence){
    if (self->head == NULL) {
        self->head = newSentence;
        return;
    }
    struct Sentence * cur = self->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newSentence;
}



Sentence *  Text_deleteFirst(Text * self) {
    Sentence * node = self->head;
    if (node == NULL) assert(0);
    self->head = node->next;
    return node;
}

Sentence *  Text_deleteAt(Text * self, int position) {
    assert(position >= 0);
    if (position == 0) {
        return Text_deleteFirst(self);
    }
    int i = 0;
    Sentence * cur = self->head;
    while (cur->next->next != NULL && i != position - 1) {
        i += 1;
        cur = cur->next;
    }
    if (i != position - 1) assert(0);
    Sentence * node = cur->next;
    cur->next = node->next;
    return node;
}
int sentenceWordsLength(Sentence *sentence){
    if(sentence == NULL){
        return 0;
    }
    Word * cur = sentence->head;
    int sumLength = 0;
    while (cur != NULL){
        sumLength += wordLength(cur);
        cur = cur->next;
    }
    return sumLength;
}

Word * Sentence_getWordAt(Sentence * self, int position){
    assert(position >= 0);
    if (self->head == NULL) assert(0); // just to throw error
    int i = 0;
    Word * cur = self->head;
    while (cur->next != NULL && i != position) {
        i += 1;
        cur = cur->next;
    }
    if (i != position) assert(0);
    return cur;
}
Sentence* Text_getSentenceAt(Text * self, int position){
    assert(position >= 0);
    if (self->head == NULL) assert(0); // just to throw error
    int i = 0;
    Sentence * cur = self->head;
    while (cur->next != NULL && i != position) {
        i += 1;
        cur = cur->next;
    }
    if (i != position) assert(0);
    return cur;
}

char * Word_getStr (Word * word){
    return word->value;
}

int wordLength(Word * word){
    return (int)strlen(word->value);
}
int sentenceLength(Sentence * sent){
    int count = 0;
    Word * cur = sent->head;
    while (cur != NULL) {
        count += 1;
        cur = cur->next;
    }
    return count;
}
int textLength(Text * text){
    int count = 0;
    Sentence * cur = text->head;
    while (cur != NULL) {
        count += 1;
        cur = cur->next;
    }
    return count;
}



void sortedInsert(Text *self, struct Sentence *new_node) {
    struct Sentence* current;
    struct Sentence* head = self->head;

    if (head == NULL || sentenceWordsLength(self->head) >= sentenceWordsLength(new_node)) {
        new_node->next = head;
        self->head = new_node;
    } else {
        current = self->head;
        while (current->next!=NULL &&
               sentenceWordsLength(current->next) < sentenceWordsLength(new_node)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


