//
// Created by tgifr on 03.03.17.
//

#include <stdio.h>
#include <memory.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "list.h"
#include <jansson.h>

void JsonLoader_saveToString(char * str, Teacher * teacher){
    if(str == NULL || teacher == NULL) return;
    // object construction
    json_t * json = json_object();
    json_object_set_new(json, "name", json_string(teacher->name));
    json_object_set_new(json, "age", json_integer(teacher->age));
    json_object_set_new(json, "score", json_real(teacher->score));
    json_t * arrBook = json_array();
    for (int i = 0; i < BOOKS_SIZE; i++) {
        if(teacher->books[i].rating == 0) continue;
        json_t * book = json_object();
        json_object_set_new(book, "name", json_string(teacher->books[i].name));
        json_object_set_new(book, "rating", json_integer(teacher->books[i].rating));
        json_array_append(arrBook, book);

    }
    json_object_set_new(json, "books", arrBook);

    // create JSON document string
    char * jsonString = json_dumps(json, JSON_INDENT(2));
    sprintf(str, "%s", jsonString);
    free(jsonString);

    // decrease reference count (free's memory when count is 0')
    json_decref(json);
}

void JsonLoader_loadFromString(Teacher *teacher, const char *jsonStr){
    if(teacher == NULL || jsonStr == NULL) return;
    json_error_t err;
    json_t * jsonArr = json_loads(jsonStr, 0, &err);
    int indexB = 0;
    json_t * valueB = NULL;
    strcpy(teacher->name, (char *)json_string_value(json_object_get(jsonArr, "name")));
    teacher->score = (float)json_real_value(json_object_get(jsonArr, "score"));
    teacher->age = (int)json_integer_value(json_object_get(jsonArr, "age"));
    json_t * bookArr = json_object_get(jsonArr, "books");
    json_array_foreach(bookArr, indexB, valueB){
        strcpy(teacher->books[indexB].name, (char *)json_string_value(json_object_get(valueB, "name")));
        teacher->books[indexB].rating = (int)json_integer_value(json_object_get(valueB, "rating"));
    }


    json_decref(jsonArr);
}

void JsonLoader_saveListToString(char *str, List *teachers){
    if(str == NULL || teachers == NULL) return;
    // object construction
    json_t * json = json_object();
    json_t * arr = json_array();
    for (int i = 0; i < List_count(teachers); i++) {
        Teacher * teacher = List_get(teachers, i);
        json_t * teacherJ = json_object();
        json_object_set_new(teacherJ, "name", json_string(teacher->name));
        json_object_set_new(teacherJ, "age", json_integer(teacher->age));
        json_object_set_new(teacherJ, "score", json_real(teacher->score));
        json_t * arrBook = json_array();
        for (int j = 0; j < BOOKS_SIZE; j++) {
            if(teacher->books[j].rating == 0) continue;
            json_t * groupObj = json_object();
            json_object_set_new(groupObj, "name", json_string(teacher->books[j].name));
            json_object_set_new(groupObj, "rating", json_integer(teacher->books[j].rating));
            json_array_append(arrBook, groupObj);

        }
        json_object_set_new(teacherJ, "books", arrBook);
        json_array_append(arr, teacherJ);
    }
    json_object_set_new(json, "teachers", arr);

    // create JSON document string
    char * jsonString = json_dumps(json, JSON_INDENT(2));
    sprintf(str, "%s", jsonString);
    free(jsonString);

    // decrease reference count (free's memory when count is 0')
    json_decref(json);
}

void JsonLoader_loadListFromString(List *teachers, const char *jsonStr){
    if(teachers == NULL || jsonStr == NULL) return;
    json_error_t err;
    json_t * jsonArr = json_loads(jsonStr, 0, &err);
    int index = 0;
    json_t * value = NULL;
    int indexB = 0;
    json_t * valueB = NULL;
    json_array_foreach(jsonArr, index, value) {
        Teacher * teacher = Teacher_new();
        strcpy(teacher->name, (char *) json_string_value(json_object_get(value, "name")));
        teacher->score = (float) json_real_value(json_object_get(value, "score"));
        teacher->age = (int) json_integer_value(json_object_get(value, "age"));
        json_t *bookArr = json_object_get(value, "books");
        json_array_foreach(bookArr, indexB, valueB) {
            strcpy(teacher->books[indexB].name, (char *) json_string_value(json_object_get(valueB, "name")));
            teacher->books[indexB].rating = (int) json_integer_value(json_object_get(valueB, "rating"));
        }
        List_add(teachers, teacher);
    }
    json_decref(jsonArr);
}

