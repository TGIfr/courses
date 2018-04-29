//
// Created by tgifr on 26.02.17.
//

#ifndef PROGBASE2GH_LIST_H
#define PROGBASE2GH_LIST_H

typedef struct Book Book;
typedef struct List List;
typedef struct Teacher Teacher;

#define BOOKS_SIZE 10

struct Book{
    char  name[40];
    int rating;
};
struct Teacher {
    char name[40];
    int age;
    float score;
    Book books[BOOKS_SIZE];
};
Teacher *Teacher_new();

char * Teacher_getName(Teacher *teacher);

int Teacher_getAge(Teacher *teacher);
float Teacher_getScore(Teacher *teacher);
Book *Teacher_getBook(Teacher *teacher, int index);


void Teacher_free(Teacher ** teacher);


typedef struct List List;

List * List_new(void);

void List_free(List ** self);

void * List_get(List * self, int index);

void List_set(List * self, int index, void * ref);

void List_add(List * self, void * ref);

int List_isEmpty(List * self);

int  List_count(List * self);

int  List_indexOf(List * self, void * ref);

int List_contains(List * self, void * ref);




#endif //PROGBASE2GH_LIST_H
