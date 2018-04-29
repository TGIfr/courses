//
// Created by tgifr on 18.03.17.
//

#ifndef C_PART_DATAMANAGEMENT_H
#define C_PART_DATAMANAGEMENT_H
typedef struct Book Book;
typedef struct Teacher Teacher;

#define BOOKS_SIZE 2

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

int writeText(const char * filename, const char * text);
int readAllText(const char * filename, char * text);
void savePathToXmlString(char *str, char * path);
void loadPathFromXmlString(char * path, const char *xmlStr);
void saveTeacherToXmlString(char *str, Teacher *teacher);
void loadTeacherFromXmlString(Teacher *teacher, const char *xmlStr);
#endif //C_PART_DATAMANAGEMENT_H
