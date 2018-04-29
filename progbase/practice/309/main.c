#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <progbase.h>
#include <string.h>

int main(int argc, char * argv[])
{
    /* int arr[10];*/
    int startElem = 0;
    char arg[100] = "";
    int counter = 0;

    int i = 0;

    /*srand(time(0));
    printf("1\n");
    for (  i = 0; i < 10; i++){
        arr[i] = rand() % 11 + 10;
        printf("arr[%i] = %i\n", i, arr[i]);
    }
     printf("\n\n\n\n");
     printf("2\n");
    for (  i = 9; i != -1; i--){
        printf("arr[%i] = %i\n", i, arr[i]);
    }
     printf("\n\n\n\n");
     printf("3\n");
    for ( i = 0; i < 10; i += 2){

        printf("arr[%i] = %i\n", i, arr[i]);
    }
    printf("\n\n\n\n");
     printf("4\n");
    for (  i = 8; i != -2; i -= 2){
        printf("arr[%i] = %i\n", i, arr[i]);
    }*/

    for( i = argc - 1; i > -1; i --){
        printf("%s\n", argv[i]);
    }

    printf("\n\n\n\n");

    i = counter;
    for( i = 0; i < argc; i ++){
        strcpy(arg, argv[i]);
        startElem = (int)strlen(arg) / 2 ;
        if((i%2) != 0 ){

            for(counter = startElem; arg[counter] != '\0'; counter++){
                printf("%c", arg[counter]);
            }
            printf("\n");

        } else {
            for(counter = 0; counter != startElem ; counter++){
                printf("%c", arg[counter]);
            }
            printf("\n");
        }
    }


    if((argc % 2) != 0){
        return -1;
    }

    return 0;
}
