#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.1

double fStringSumm(char *str);
int main() {

    assert(fStringSumm("10 45 5.5") > 60.5 - EPSILON &&
                   fStringSumm("10 45 5.5") < 60.5 + EPSILON);
    assert(fStringSumm("") > 0 - EPSILON &&
                   fStringSumm("") < 0 + EPSILON);
    assert(fStringSumm("0") > 0 - EPSILON &&
                   fabs(fStringSumm("0")) < 0 + EPSILON);
    assert(fStringSumm("dghdgkhlgdsffd rg rgkj h uei") > 0.0 - EPSILON &&
                   fStringSumm("dghdgkhlgdsffd rg rgkj h uei") < 0.0 + EPSILON);
    assert(fStringSumm(" 5.5 6.5 dshjlkjhgf") > 12.0 - EPSILON  &&
                   fStringSumm(" 5.5 6.5 dshjlkjhgf") < 12.0 + EPSILON );
    assert(fStringSumm(" 0.5 -10.5 2.9") == 0.0);
    FILE * in;
    FILE * out;
    double strSumm = 0.0;
    if((in = fopen("in.txt" , "r")) == NULL ||
       (out = fopen("out.txt" , "w")) == NULL) {
        printf("File not found. Black hawk down... \n" );
        exit(EXIT_FAILURE);
    }
    char buf[100] = "";
    while(!feof(in)){
        fgets(buf, 100, in);
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = '\0';
        }
        strSumm = fStringSumm(buf);
        fprintf(out, "%.3f \n", strSumm);
    }
    return 0;
}
double fStringSumm(char *str){
    double result = 0.0;
    double toAdd = 0.0;
    while(*str){
        if(isdigit(*str) || (*str == '-' && isdigit(*(str + 1 ))) ||
                (*str == '.' && isdigit(*(str + 1 )))){
            toAdd = atof(str);
            if(toAdd > 3){
                result += toAdd;
            }
            while(isdigit(*str) || (*str == '-' && isdigit(*(str + 1 ))) ||
                    (*str == '.' && isdigit(*(str + 1 )))){
                str ++;
            }
        }
        str ++;
    }
    return result;
}