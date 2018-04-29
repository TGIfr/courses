#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    BUF_SIZE = 100,
    TRUE = 1,
    FALSE = 0
};
int file_process(const char * readFileName, const char * writeFileName);
int strIsEmpty(char * str);
int main() {

    return file_process("read.txt", "write.txt");
}
int file_process(const char * readFileName, const char * writeFileName){
    FILE * read;
    FILE * write;
    char buf1[BUF_SIZE];
    char buf2[BUF_SIZE];
    if ((read = fopen(readFileName, "r")) == NULL
        ||(write = fopen(writeFileName, "w")) == NULL) return EXIT_FAILURE;
    fprintf(write, "Записати ті рядки, які стоять одразу перед кожним пустим рядком у тексті\n\n");

    fgets(buf1, BUF_SIZE, read);
    buf1[strlen(buf1) - 1 ] = '\0';
    while(!feof(read)){
        fgets(buf2, BUF_SIZE, read);
        buf2[strlen(buf2) - 1 ] = '\0';
        if(strIsEmpty(buf2)){
            fprintf(write, "%s\n", buf1);
        }
        strcpy(buf1, buf2);
    }

    fclose(read);
    fclose(write);
    return EXIT_SUCCESS;
}

int strIsEmpty(char * str){
    while(*str){
        if(* str != ' ' || * str != '\t')  return FALSE; /* isblank() function is unavaliable in C89*/
    }
    return TRUE;
}