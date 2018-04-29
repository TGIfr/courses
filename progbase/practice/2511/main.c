#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


struct arguments {
    char  inName[100];
    char  outName[100];
    bool decompress;
};
struct arguments analyze (int argc, char * argv[]);
void compress (char * inName, char * outName);
void deCompress (char * inName, char * outName);
void inOutRename(char *inName, char *outName, bool decompress);
FILE * openOut(char *outName);
bool checkFiles(FILE *inFile, FILE *outFile);
int isHasSignature(char *name);

int main(int argc, char * argv[]) {
    struct arguments anRes = analyze(argc, argv);
    if(!anRes.decompress){
        compress(anRes.inName, anRes.outName);
    } else {
        deCompress(anRes.inName, anRes.outName);
    }
    return 0;
}
struct arguments analyze (int argc, char * argv[]){
    int i = 1;
    struct arguments result = { "", "", false};
    while(i < argc){
        if(argv[i] == "-d"){
            result.decompress = true;
        } else if(argv[i] == "-o" && argc > i + 1){
            strcpy(result.outName, argv[i + 1]);
            i++;
        } else {
            strcpy(result.inName, argv[i]);
        }
        i++;
    }
    return result;
}
bool checkFiles(FILE *inFile, FILE *outFile) {
    if(inFile == NULL || outFile == NULL){
        printf("File not found. Black hawk down.....\n\n");
        return false;
    }
    return true;
}
void compress (char * inName, char * outName){
    FILE * in;
    FILE * out = openOut(outName);
    in = fopen(inName, "r");
    char number = 0;
    char B ;
    char temp;
    if(!checkFiles(in, out)){
        return;
    }
    B = (char)fgetc(in);
    while(!feof(in)){
        number = 0;
        do {
            temp = (char)fgetc(in);
            number ++;
        } while (B == temp && number != 255);
        fprintf(out, "%c%c", number, B);
        B = temp;
    }
    fclose(in);
    fclose(out);
    inOutRename(inName, outName, false);
}
FILE * openOut(char *outName){
    FILE * result;
    if(strlen(outName) == 0){
        result = fopen("temp", "w");
    } else {
        result = fopen(outName, "w");
    }
    return result;
}
void deCompress (char * inName, char * outName){
    FILE * in;
    FILE * out = openOut(outName);
    char number = 0;
    char B ;
    in = fopen(inName, "r");
    if(!checkFiles(in, out)){
        return;
    }
    while(!feof(in)){
        int i = 0;
        number = (char)fgetc(in);
        B = (char)fgetc(in);
        for(i = 0; i <= number; i ++){
            fputc(B, out);
        }
    }
    fclose(in);
    fclose(out);
    inOutRename(inName, outName, true);
}
void inOutRename(char *inName, char *outName, bool decompress) {
    char toAdd [100];
    char toRename[100];
    int dot;
    if(decompress){
        strcpy(toAdd, ".decompress");
    } else {
        strcpy(toAdd, ".compress");
    }
    if(strlen(outName) != 0){
        rename("temp", outName);
        return;
    }
    if(!(dot = isHasSignature(inName))){
        if(inName[strlen(inName) - 1] == '.'){
            inName[strlen(inName) - 1] = '\0';
        }
    } else {
        inName[dot] = '\0';
    }
    strcpy(toRename, inName);
    strcat(toRename, toAdd);
    rename("temp", toRename);
}
int isHasSignature(char *name){
    char * temp = name;
    while(*name != '\0'){
        if(*name == '.' && isalnum(*(name + 1))){
            return (int)(name - temp);
        }
        name ++;
    }
    return false;
}