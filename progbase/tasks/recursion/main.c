#include <stdio.h>
#include <string.h>
#include <progbase.h>
#include <ctype.h>
int lastDigit(char * str, int length);
int main() {
    char * str;
    printf("PLease, enter a string: ");
    str = getString();
    printf("The last digit: %c\n", lastDigit(str, (int)strlen(str)));
    free(str);
    return EXIT_SUCCESS;
}
int lastDigit(char * str, int length){
    if(length == 0) {
        return '0';
    } else if(isdigit(str[length - 1])) {
        return str[length - 1];
    } else return lastDigit(str, length - 1);
}