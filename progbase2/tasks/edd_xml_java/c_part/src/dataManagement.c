//
// Created by tgifr on 18.03.17.
//

#include <memory.h>
#include <malloc.h>
#include "dataManagement.h"
#include <libxml/parser.h>

Teacher *Teacher_new() {
    Teacher * res = malloc(sizeof(Teacher));
    for(int i = 0; i < BOOKS_SIZE; i++){
        strcpy(res->books[i].name, "");
        res->books[i].rating = 0;
    }
    return res;
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


int writeText(const char * filename, const char * text){
    FILE * write ;
    if((write = fopen(filename, "w")) == NULL) return 0;
    fprintf(write, "%s", text);
    fclose(write);
    return 1;
}
int readAllText(const char * filename, char * text) {
    char line[100];

    FILE * fr = fopen(filename, "r");
    if (fr == NULL) return 0;
    while(fgets(line, 100, fr)) {
        strcat(text, line);
    }
    fclose(fr);
    return 1;
}
void savePathToXmlString(char *str, char * path){
    if(str == NULL || path == NULL){
        return;
    }
    xmlDoc * doc = NULL;
    xmlNode * rootNode = NULL;

    doc = xmlNewDoc(BAD_CAST "1.0");

    // create xml tree

    // create one root element
    rootNode = xmlNewNode(NULL, BAD_CAST "root");
    xmlDocSetRootElement(doc, rootNode);
    xmlNewChild(rootNode, NULL, BAD_CAST "path", BAD_CAST path);


    // copy xml contents to char buffer
    xmlBuffer * bufferPtr = xmlBufferCreate();
    xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
    sprintf(str, "%s", (const char *)bufferPtr->content);
    xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
}
void loadPathFromXmlString(char * path, const char *xmlStr){
    if(path == NULL) return;
    xmlDoc * xDoc = xmlReadMemory(xmlStr, (int)strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return ;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    xmlNode * xCur = xRootEl->children->next;
    if (XML_ELEMENT_NODE == xCur->type) {
        char *content = (char *) xmlNodeGetContent(xCur);
        if (xmlStrcmp(xCur->name, BAD_CAST "path") == 0) {
            strcpy(path,  content);
        } else {
            printf("ERROR WHILE READING");
            return;
        }
        xmlFree(content);
    }
    xmlFreeDoc(xDoc);
}
void saveTeacherToXmlString(char *str, Teacher *teacher){
    if(str == NULL || teacher == NULL){
        return;
    }
    xmlDoc * doc = NULL;
    xmlNode * rootNode = NULL;
    xmlNode * bookNodes = NULL ;
    char strBuf[1000];

    doc = xmlNewDoc(BAD_CAST "1.0");

    // create xml tree

    // create one root element
    rootNode = xmlNewNode(NULL, BAD_CAST "teacher");
    xmlDocSetRootElement(doc, rootNode);

    // student child

    xmlNewChild(rootNode, NULL, BAD_CAST "name", BAD_CAST Teacher_getName(teacher));
    sprintf(strBuf, "%i", Teacher_getAge(teacher));  // copy number to string
    xmlNewChild(rootNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
    sprintf(strBuf, "%f", Teacher_getScore(teacher));  // copy number to string
    xmlNewChild(rootNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
    xmlNode * books = xmlNewChild(rootNode, NULL, BAD_CAST "books", NULL);
    // create group element as student child

    for (int i = 0; i < BOOKS_SIZE; i++) {
        if(Teacher_getBook(teacher,i)->rating == 0 ) continue;
        bookNodes = xmlNewChild(books, NULL, BAD_CAST "book", NULL);
        xmlNewProp(bookNodes, BAD_CAST "name", BAD_CAST Teacher_getBook(teacher,i)->name);
        sprintf(strBuf, "%i", Teacher_getBook(teacher,i)->rating);
        xmlNewChild(bookNodes, NULL, BAD_CAST "rating", BAD_CAST strBuf);
    }

    // copy xml contents to char buffer
    xmlBuffer * bufferPtr = xmlBufferCreate();
    xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
    sprintf(str, "%s", (const char *)bufferPtr->content);
    xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
}

void loadTeacherFromXmlString(Teacher *teacher, const char *xmlStr){
    int count = 0;
    if(teacher == NULL) return;
    xmlDoc * xDoc = xmlReadMemory(xmlStr, (int)strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return ;
    }
    xmlNode * xCur = xmlDocGetRootElement(xDoc);
    if (XML_ELEMENT_NODE == xCur->type) {
        for (xmlNode * xJ = xCur->children->next; NULL != xJ ; xJ = xJ->next) {
            if (XML_ELEMENT_NODE == xJ->type) {
                char * content = (char *)xmlNodeGetContent(xJ);
                if (xmlStrcmp(xJ->name, BAD_CAST "books") == 0) {
                    for (xmlNode * bookNode = xJ->children->next; NULL != bookNode; bookNode = bookNode->next) {
                        if (XML_ELEMENT_NODE == bookNode->type) {
                            xmlNode * xGroup = bookNode;
                            char * bookContent = (char *)xmlNodeGetContent(bookNode);
                            char * name = (char *)xmlGetProp(xGroup, BAD_CAST "name");
                            teacher->books[count] = (Book) {
                                    .rating = atoi(bookContent)
                            };
                            strcpy(teacher->books[count].name, name);
                            count ++;
                            xmlFree(name);
                        }
                    }
                } else if (xmlStrcmp(xJ->name, BAD_CAST "name") == 0) {
                    strcpy(teacher->name,  content);
                } else if (xmlStrcmp(xJ->name, BAD_CAST "age") == 0) {
                    teacher->age =  atoi( content);
                } else if (xmlStrcmp(xJ->name, BAD_CAST "score") == 0) {
                    teacher->score =  (float) atof( content);
                } else {
                    printf("ERROR WHILE READING");
                    return;
                }
                xmlFree(content);
            }
        }
    }
    xmlFreeDoc(xDoc);
}