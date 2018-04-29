//
// Created by tgifr on 25.03.17.
//
#include <stdio.h>
#include <memory.h>
#include <libxml/parser.h>
#include <jansson.h>

#include "loader.h"
void JsonLoader_saveToString(char * str, struct WebSite * site){
    if(str == NULL || site == NULL) return;
    // object construction
    json_t * json = json_object();
    json_object_set_new(json, "siteName", json_string(site->siteName));
    json_t * arrPages = json_array();
    for (int i = 0; i < PAGES_SIZE; i++) {
        json_t * page = json_object();
        json_object_set_new(page, "urlPath", json_string(site->pages[i].urlPath));
        json_object_set_new(page, "content", json_string(site->pages[i].content));
        json_object_set_new(page, "contentLength", json_integer(site->pages[i].contentLength));
        json_array_append(arrPages, page);

    }
    json_object_set_new(json, "pages", arrPages);

    // create JSON document string
    char * jsonString = json_dumps(json, JSON_INDENT(2));
    sprintf(str, "%s", jsonString);
    free(jsonString);

    // decrease reference count (free's memory when count is 0')
    json_decref(json);
}

void JsonLoader_loadFromString(struct WebSite *site, const char *jsonStr){
    if(site == NULL || jsonStr == NULL) return;
    json_error_t err;
    json_t * jsonArr = json_loads(jsonStr, 0, &err);
    int indexPage = 0;
    json_t * valuePage = NULL;
    strcpy(site->siteName, (char *)json_string_value(json_object_get(jsonArr, "siteName")));
    json_t * bookArr = json_object_get(jsonArr, "pages");
    json_array_foreach(bookArr, indexPage, valuePage){
        strcpy(site->pages[indexPage].content, (char *)json_string_value(json_object_get(valuePage, "content")));
        strcpy(site->pages[indexPage].urlPath, (char *)json_string_value(json_object_get(valuePage, "urlPath")));
        site->pages[indexPage].contentLength = (int)json_integer_value(json_object_get(valuePage, "contentLength"));
    }


    json_decref(jsonArr);
}