#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <string.h>
#include <ctype.h>

int main()
{
    /*int flag = 1;
    char arr[100] = "fj890hgk gj kf hdj fh df jgf jhg ";
    for(int i = 0; i < strlen(arr); i ++){
        if(isalpha(arr[i])){
            printf("%c", arr[i]);
            flag = 1;
        } else if(flag){
            flag = 0;
            printf("\n");
        }
    }*/
    char arr[100] = "44.12";
    int flag = 0;
    int summ = 0;
    int tmp1 = 0;
    for(int i = 0; i < strlen(arr); i ++){
        if(arr[i] == ' '  && arr[i-1] != ' '){
            tmp1 = atoi(&arr[i]);
            if(tmp1 == 0 && arr[i + 1] != '0'){
                continue;
            }
            summ += tmp1;
            flag = 1;
        } else if( i ==  0){
            tmp1 = atoi(&arr[i]);
            if(tmp1 == 0 && arr[i + 1] != '0'){
                continue;
            }
            summ += tmp1;
            flag = 1;
        }
    }

    if(!flag){
        printf("NO INTEGERS");
    } else {
        printf("Summ: %i", summ);
    }


    return 0;
}

