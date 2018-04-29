#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE * fp;
    FILE * fw;
    char buf[200];
    if ((fp = fopen("main.c", "r"))==NULL) {
        printf("Cannot open file main.c\n");
        exit(EXIT_FAILURE);
    }
    if ((fw = fopen("output.txt", "w"))==NULL) {
        printf("Cannot open file output.txt");
    }
    while(!feof(fp)){
        fgets(buf, 200, fp);
        buf[strlen(buf) - 1 ] = '\0';
        for(int i = 0; i < strlen(buf); i ++){
           if(buf[i] == '\"' && isalpha(buf[i+1])){
               do {
                   i ++;
                   fputc(buf[i], fw);
               } while(buf[i + 1] != '"');
               fputc('\n', fw);
           }
        }
    }
    fclose(fp);
    fclose(fw);
    return 0;
}
