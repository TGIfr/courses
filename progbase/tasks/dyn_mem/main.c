#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <progbase.h>
#include <pbconsole.h>
#include <ctype.h>
#define  MEMORY_PROBLEM -1
#define DIGIT_FIND_PROBLEM  -2

void findFirstDigit(char *str, int *first);
void findLastDigit(char *str, int *last);
void printStr( char * str, int * first, int * last);

int main() {
	int * last = (int  *)malloc(sizeof(int)),  * first = (int  *)malloc(sizeof(int));
	char * str = NULL;
	char * startText = "Enter your string and say \n\"I solemnly swear that I am up to no good with pointers\"\n"
			"and I`ll  find product of the first and the last digit in your string\n";
    conClear();
    printf("%s", startText);
	str = strdup(getString());
    if( last == NULL || first == NULL || str == NULL){
        printf("\nOops, seems that there is no memory\n");
        free(last);
        free(first);
        free(str);
        return MEMORY_PROBLEM;
    }
    findLastDigit(str, last);
    findFirstDigit(str, first);
    if(*last < 0 && *first < 0){
        printf("\nOops, seems that there is no digits in your string\n");
        free(last);
        free(first);
        free(str);
        return DIGIT_FIND_PROBLEM;
    }
    printf("\nProduct is %i\n", (str[*first] - '0') * (str[*last]- '0'));
    printStr(str, first, last);
    free(last);
    free(first);
    free(str);
	return 0;
}
void findFirstDigit(char *str, int *first) {
    char * temp = str;
    while((*temp) != '\0' && isdigit(* temp) == 0 ){
        temp ++;
    }
    if(isdigit(*temp)){
        * first = (int)(temp - str);
    } else {
        * first = -1;
    }
}
void findLastDigit(char *str, int *last) {
    char * temp = str;
    * last = -1;
    while(* temp != '\0' ){
        if(isdigit( * temp) != 0){
            * last = (int)(temp - str);
        }
        temp ++;
    }
}
void printStr( char * str, int * first, int * last){
    int * i = malloc(sizeof(int));
    for(* i = 0;  str[*(i)] != '\0'; (* i) ++){
        if(* i == * first || * i == * last){
            conSetAttr(BG_BLUE);
            printf("%c", str[*i]);
            conReset();
        } else {
            printf("%c", str[*i]);
        }
    }
    puts("");
    free(i);
}