#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <ctype.h>


/*
 * @brief find minimum integer represented in string
 * @param str - input string
 * @returns min integer or INT_MAX otherwise
 */
int get_min_int(const char * str);


int main(int argc, char * argv[]) {
    assert(get_min_int(NULL) == INT_MAX);
    assert(get_min_int("") == INT_MAX);
    assert(get_min_int("abra *(^*^)*") == INT_MAX);
    assert(get_min_int("13") == 13);
    assert(get_min_int("13t-4") == -4);
    assert(get_min_int("-100 0 100") == -100);
    return EXIT_SUCCESS;
}
int get_min_int(const char * str){
    int min = INT_MAX;
    int temp;
    if(str == NULL){
        return min;
    }
    while(* str != '\0'){
        if (!isdigit(*str) && (*str != '-' && !isdigit(*(str+1)) )) {
            while(!isdigit(*str) && *str != '\0' && *str != '-'){
                str ++;
            }
        } else {
            temp = atoi(str);
            if(min > temp){
                min = temp;
            }
            while(isdigit(*str) || *str == '-'){
                str ++;
            }
        }
    }
    return min;
}