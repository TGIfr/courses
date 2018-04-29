//
// Created by tgifr on 03.12.16.
//
#include <stdio.h>
#include "../include/dino.h"
#include "../include/list.h"
#include <libxml/parser.h>
#include "../include/list.h"
#include <jansson.h>
#include "../include/saves.h"

enum{
TXT, XML, JSON, NO_EXTENSION = -1
};

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
int analyzeExtension(const char * str){
    const char * dot = str;
    while(*dot != '.' && *dot != '\0'){
        dot++;
    }
    if(*dot != '.'){
        return NO_EXTENSION;
    }
    dot ++;
    if(strcmp(dot, "xml") == 0)return XML;
    else if(strcmp(dot, "json") == 0) return JSON;
    else if(strcmp(dot, "txt") == 0) return TXT;
    else return NO_EXTENSION;

}
int Storage_write(const char *filePath, List *list){
    switch (analyzeExtension(filePath)){
        case NO_EXTENSION:
            return EXIT_FAILURE;
        case XML:
            return Storage_writeAsXml(filePath, list);
        case JSON:
            return Storage_writeAsJson(filePath, list);
        case TXT:
            return Storage_writeAsTxt(list, filePath);
        default:
            return EXIT_FAILURE;
    }
}
List * Storage_read(const char * filePath){
    switch (analyzeExtension(filePath)){
        case XML:
            return Storage_readAsXml(filePath);
        case JSON:
            return Storage_readAsJson(filePath);
        default:
            return Storage_readAsTxt(filePath);
    }
}
int Storage_writeAsXml(const char *filePath, List *list){
    FILE * write;
    if((write = fopen(filePath, "w")) == NULL){
        return EXIT_FAILURE;
    }
    xmlDoc * doc = NULL;
    xmlNode * rootNode = NULL;
    xmlNode * dinoNode = NULL;
    char strBuf[4000];

    doc = xmlNewDoc(BAD_CAST "1.0");

    // create xml tree

    // create one root element
    rootNode = xmlNewNode(NULL, BAD_CAST "dinos");
    xmlDocSetRootElement(doc, rootNode);

    // student child
    for (int j = 0; j < MAX_SIZE; j ++) {
        dino * dino = List_elementAt(list, j);
        dinoNode = xmlNewChild(rootNode, NULL, BAD_CAST "dino", NULL);
        xmlNewChild(dinoNode, NULL, BAD_CAST "name", BAD_CAST dino->name);
        sprintf(strBuf, "%i", dino->age);  // copy number to string
        xmlNewChild(dinoNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
        sprintf(strBuf, "%f", dino->mass);  // copy number to string
        xmlNewChild(dinoNode, NULL, BAD_CAST "mass", BAD_CAST strBuf);
        sprintf(strBuf, "%i", dino->friend->number);  // copy number to string
        xmlNewChild(dinoNode, NULL, BAD_CAST "friend", BAD_CAST strBuf);

    }

    // copy xml contents to char buffer
    xmlBuffer * bufferPtr = xmlBufferCreate();
    xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
    fprintf(write, "%s", (const char *)bufferPtr->content);
    xmlBufferFree(bufferPtr);
    xmlFreeDoc(doc);
    fclose(write);
    return EXIT_SUCCESS;
}
List * Storage_readAsXml(const char * filePath){
    char xmlStr[3000];
    if(readAllText(filePath, xmlStr) == 0);
    List * list = createDinoList();
    initializeList(list);

    xmlDoc * xDoc = xmlReadMemory(xmlStr, (int)strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return list;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);

    for (xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        if (XML_ELEMENT_NODE == xCur->type) {
            dino * cur = dino_new();
            for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
                if (XML_ELEMENT_NODE == xJ->type) {
                    char * content = (char *)xmlNodeGetContent(xJ);
                    if (xmlStrcmp(xJ->name, BAD_CAST "friend") == 0) {
                        cur->friend = List_elementAt(list, atoi(content));
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "name") == 0) {
                        strcpy(cur->name,  content);
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "age") == 0) {
                        cur->age =  atoi( content);
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "mass") == 0) {
                        cur->mass =  (float) atof( content);
                    } else {
                        printf("ERROR WHILE READING");
                        return list;
                    }
                    xmlFree(content);
                }
            }
            char * temp = writeInStr(cur);
            free(cur);
            writeFromStr(list, temp);
            free(temp);
        }
    }
    xmlFreeDoc(xDoc);
    return list;

}

int Storage_writeAsJson(const char *filePath, List *list){
    FILE * write;
    if((write = fopen(filePath, "w")) == NULL){
        return EXIT_FAILURE;
    }
    if(filePath == NULL || list == NULL) return EXIT_FAILURE;
    // object construction
    json_t * arr = json_array();
    for (int i = 0; i < List_count(list); i++) {
        dino * cur = List_elementAt(list, i);
        json_t * curJ = json_object();
        json_object_set_new(curJ, "name", json_string(cur->name));
        json_object_set_new(curJ, "age", json_integer(cur->age));
        json_object_set_new(curJ, "score", json_real(cur->mass));
        json_object_set_new(curJ, "friend", json_integer(cur->friend->number));
        json_array_append(arr, curJ);
    }

    // create JSON document string
    char * jsonString = json_dumps(arr, JSON_INDENT(2));
    fprintf(write, "%s", jsonString);
    free(jsonString);

    // decrease reference count (free's memory when count is 0')
    json_decref(arr);
    fclose(write);
    return EXIT_SUCCESS;
}
List * Storage_readAsJson(const char * filePath){
    char jsonStr[3000];
    if(readAllText(filePath, jsonStr) == 0);
    List * list = createDinoList();
    initializeList(list);

    json_error_t err;
    json_t * jsonArr = json_loads(jsonStr, 0, &err);
    int index = 0;
    json_t * value = NULL;
    json_array_foreach(jsonArr, index, value) {
        dino * cur = dino_new();
        strcpy(cur->name, (char *) json_string_value(json_object_get(value, "name")));
        cur->mass = (float) json_real_value(json_object_get(value, "mass"));
        cur->age = (int) json_integer_value(json_object_get(value, "age"));
        cur->friend = List_elementAt(list, (int) json_integer_value(json_object_get(value, "friend")));

        char * temp = writeInStr(cur);
        writeFromStr(list, temp);
        free(temp);
        free(cur);
    }
    json_decref(jsonArr);
    return  list;
}


struct List * Storage_readAsTxt(const char *readFileName){
    FILE * read;
    char temp[150] = "";
    struct List * list = createDinoList();
    initializeList(list);
    if((read = fopen(readFileName, "r")) == NULL){
        return list;
    }
    while(!feof(read)){
        fgets(temp, 150, read);
        if(writeFromStr(list, temp)){
            break;
        }
    }
    fclose(read);
    return list;
}

int Storage_writeAsTxt(struct List *list, const char *saveFileName){
    FILE * save;
    if((save = fopen(saveFileName, "w")) == NULL){
        return EXIT_FAILURE;
    }
    char * toWrite = writeInText(list);
    fprintf(save, "%s", toWrite);
    free(toWrite);
    fclose(save);
    return EXIT_SUCCESS;
}

