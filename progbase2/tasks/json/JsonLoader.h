//
// Created by tgifr on 03.03.17.
//

#ifndef XML_XMLLOADER_H
#define XML_XMLLOADER_H

typedef struct Book Book;
typedef struct List List;
typedef struct Teacher Teacher;

void JsonLoader_saveToString(char *str, Teacher *teacher);
void JsonLoader_loadFromString(Teacher *teacher, const char *jsonStr);
void JsonLoader_saveListToString(char *str, List *teachers);
void JsonLoader_loadListFromString(List *teachers, const char *jsonStr);
#endif //XML_XMLLOADER_H
