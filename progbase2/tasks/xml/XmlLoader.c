//
// Created by tgifr on 03.03.17.
//

#include <stdio.h>
#include <memory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "list.h"


void XmlLoader_saveToString(char *str, Teacher *teacher){
    if(str == NULL || teacher == NULL){
        return;
    }
    xmlDoc * doc = NULL;
    xmlNode * rootNode = NULL;
    xmlNode * teacherNode = NULL;
    xmlNode * bookNodes = NULL ;
    char strBuf[1000];

    doc = xmlNewDoc(BAD_CAST "1.0");

    // create xml tree

    // create one root element
    rootNode = xmlNewNode(NULL, BAD_CAST "teachers");
    xmlDocSetRootElement(doc, rootNode);

    // student child
    teacherNode = xmlNewChild(rootNode, NULL, BAD_CAST "teacher", NULL);
    xmlNewChild(teacherNode, NULL, BAD_CAST "name", BAD_CAST Teacher_getName(teacher));
    sprintf(strBuf, "%i", Teacher_getAge(teacher));  // copy number to string
    xmlNewChild(teacherNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
    sprintf(strBuf, "%f", Teacher_getScore(teacher));  // copy number to string
    xmlNewChild(teacherNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
    // create group element as student child

    for (int i = 0; i < BOOKS_SIZE; i++) {
        if(Teacher_getBook(teacher,i)->rating == 0 ) continue;
        bookNodes = xmlNewChild(teacherNode, NULL, BAD_CAST "book", NULL);
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

void XmlLoader_loadFromString(Teacher * teacher, const char * xmlStr){
    int count = 0;
    if(teacher == NULL) return;
    xmlDoc * xDoc = xmlReadMemory(xmlStr, (int)strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return ;
    }
    xmlNode * xBook[BOOKS_SIZE];
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    xmlNode * xCur = xRootEl->children->next;
    if (XML_ELEMENT_NODE == xCur->type) {
        for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
            if (XML_ELEMENT_NODE == xJ->type) {
                char * content = (char *)xmlNodeGetContent(xJ);
                if (xmlStrcmp(xJ->name, BAD_CAST "book") == 0) {
                    xmlNode * xGroup = xJ;
                    xBook[count] = xGroup->children->next;
                    char * name = (char *)xmlGetProp(xGroup, BAD_CAST "name");
                    teacher->books[count] = (Book) {
                            .rating = atoi(content)
                    };
                    strcpy(teacher->books[count].name, name);
                    count ++;
                    xmlFree(name);
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

void XmlLoader_saveListToString(char *str, List *teachers){
    if(str == NULL){
        return;
    }
    xmlDoc * doc = NULL;
    xmlNode * rootNode = NULL;
    xmlNode * teacherNode = NULL;
    xmlNode * bookNodes = NULL ;
    char strBuf[4000];

    doc = xmlNewDoc(BAD_CAST "1.0");

    // create xml tree

    // create one root element
    rootNode = xmlNewNode(NULL, BAD_CAST "books");
    xmlDocSetRootElement(doc, rootNode);

    // student child
    for (int j = 0; j < List_count(teachers); j ++) {
        Teacher * teacher = List_get(teachers, j);
        teacherNode = xmlNewChild(rootNode, NULL, BAD_CAST "student", NULL);
        xmlNewChild(teacherNode, NULL, BAD_CAST "name", BAD_CAST Teacher_getName(teacher));
        sprintf(strBuf, "%i", Teacher_getAge(teacher));  // copy number to string
        xmlNewChild(teacherNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
        sprintf(strBuf, "%f", Teacher_getScore(teacher));  // copy number to string
        xmlNewChild(teacherNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
        // create group element as student child

        for (int i = 0; i < BOOKS_SIZE; i++) {
            if(Teacher_getBook(teacher,i)->rating == 0 ) continue;
            bookNodes = xmlNewChild(teacherNode, NULL, BAD_CAST "book", NULL);
            xmlNewProp(bookNodes, BAD_CAST "name", BAD_CAST Teacher_getBook(teacher,i)->name);
            sprintf(strBuf, "%i", Teacher_getBook(teacher,i)->rating);
            xmlNewChild(bookNodes, NULL, BAD_CAST "rating", BAD_CAST strBuf);
        }
    }

    // copy xml contents to char buffer
    xmlBuffer * bufferPtr = xmlBufferCreate();
    xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
    sprintf(str, "%s", (const char *)bufferPtr->content);
    xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
}

void XmlLoader_loadListFromString(List *teachers, const char *xmlStr){
    int count = 0;
    if(teachers == NULL) return;
    xmlDoc * xDoc = xmlReadMemory(xmlStr, (int)strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return ;
    }
    xmlNode * xFac[BOOKS_SIZE];
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);

    for (xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        if (XML_ELEMENT_NODE == xCur->type) {
            Teacher * teacher = Teacher_new();
            for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
                if (XML_ELEMENT_NODE == xJ->type) {
                    char * content = (char *)xmlNodeGetContent(xJ);
                    if (xmlStrcmp(xJ->name, BAD_CAST "book") == 0) {
                        xmlNode * xGroup = xJ;
                        xFac[count] = xGroup->children->next;
                        char * name = (char *)xmlGetProp(xGroup, BAD_CAST "name");
                        teacher->books[count] = (Book) {
                                .rating = atoi(content)
                        };
                        strcpy(teacher->books[count].name, name);
                        count ++;
                        xmlFree(name);
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "name") == 0) {
                        strcpy(teacher->name, (char *) content);
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "age") == 0) {
                        teacher->age =  atoi((char *) content);
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "score") == 0) {
                        teacher->score =  (float) atof((char *) content);
                    } else {
                        printf("ERROR WHILE READING");
                        return;
                    }
                    xmlFree(content);
                }
            }
            List_add(teachers, teacher);
        }
    }
    xmlFreeDoc(xDoc);
}

