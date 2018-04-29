//
// Created by tgifr on 03.03.17.
//

#ifndef XML_XMLLOADER_H
#define XML_XMLLOADER_H

typedef struct Book Book;
typedef struct List List;
typedef struct Teacher Teacher;

void XmlLoader_saveToString(char *str, Teacher *teacher);
void XmlLoader_loadFromString(Teacher * teacher, const char * xmlStr);
void XmlLoader_saveListToString(char *str, List *teachers);
void XmlLoader_loadListFromString(List *teachers, const char *xmlStr);
#endif //XML_XMLLOADER_H
