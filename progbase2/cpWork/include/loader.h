//
// Created by tgifr on 25.03.17.
//

#pragma once
#define PAGES_SIZE 5

struct WebPage {
    char urlPath[100];
    char content[1000];
    int contentLength;
};

struct WebSite {
    struct WebPage pages[PAGES_SIZE];
    char siteName[100];
};

void JsonLoader_loadFromString(struct WebSite *site, const char *jsonStr);
void JsonLoader_saveToString(char * str, struct WebSite * site);