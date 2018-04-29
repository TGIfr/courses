#include <stdio.h>
#include <memory.h>
#include "loader.h"

void printSite(struct WebSite * site);

int main() {
    struct WebSite site ;
    strcpy(site.siteName, "testPage");
    for (int i = 0; i < PAGES_SIZE; ++i) {
        sprintf(site.pages[i].content, "content%i", i);
        sprintf(site.pages[i].urlPath, "path%i", i);
        site.pages[i].contentLength = 8;
    }
    char str[1000] = "";
    JsonLoader_saveToString(str, &site);
    puts(str);
    struct WebSite site2;
    JsonLoader_loadFromString(&site2, str);
    printSite(&site2);
    return 0;
}
void printSite(struct WebSite * site){
    printf("%s", site->siteName);
    for (int i = 0; i < PAGES_SIZE; ++i) {
        printf("page number %i\n",  i);
        printf("content: %s\n",  site->pages[i].content);
        printf("path: %s\n",  site->pages[i].urlPath);
        printf("contentLength: %i\n",  site->pages[i].contentLength);
    }
    puts("\n");
}