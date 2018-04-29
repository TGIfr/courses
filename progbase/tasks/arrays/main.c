#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <progbase.h>
#include <pbconsole.h>

int main()
{
    int A[10];
    char S[10];
    int i = 0;
    int min, maxMinus = -1000;
    int sum = 0, count = 0;
    double average = 0.0;
    int minIndex = 0, maxMinusIndex;
    srand(time(0));
    /*1*/
    printf("1. Array A:\n");
    for ( i = 0; i < 10; i++) {
        A[i] = rand() % 299 - 99;
        printf("A[%i] = %i\t", i, A[i]);
    }
    /*2*/
    printf("\n\n\n2. Array A, from -10 to 10:\n");
    for ( i = 0; i < 10; i++) {

        if(A[i] >= -10 && A[i] <= 10) {
            conSetAttr(BG_GREEN);
            printf("%i\t", A[i]);
            conReset();
        } else {
            printf("%i\t", A[i]);
        }
    }
    /*3*/
    printf("\n\n\n3. Array A, from -99 to 127 and some stats:\n");
    for ( i = 0; i < 10; i++) {

        if(A[i] >= -99 && A[i] <= 127) {
            conSetAttr(BG_BLUE);
            printf("%i\t", A[i]);
            conReset();
            count++;
            sum += A[i];
        } else {
            printf("%i\t", A[i]);
        }
    }
    average = (double)sum / count;
    printf("\nCount: %i\nSum: %i\nAverage: %f\n\n\n", count, sum, average );
    /*4*/
    printf("4. Max value, less than zero:\n");
    for( i = 0; i < 10; i++) {
        if(A[i] > maxMinus && A[i] < 0){
            maxMinus = A[i];
            maxMinusIndex = i;
        }
    }
    printf("Maximal value: %i. It`s index is %i\n\n\n", maxMinus, maxMinusIndex);
    /*5*/
    printf("5. Min value:\n");
    min = A[0];
    for( i = 0; i < 10; i++) {
        if(A[i] < min) {
            min = A[i];
            minIndex = i;
        }
    }
    printf("Minimal value: %i. It`s index is %i\n\n\n", min, minIndex);
    /*6*/
    printf("6. Char array:\n");
    for( i = 0; i < 10; i++) {
        S[i] = abs(A[i]) % 95 + 32;
    }
    S[9] = '\0';
    puts(S);
    /*7*/
    printf("\n\n7. Arr A, all elements that bigger than 127 are 0 now(also they are on red BG):\n");

    for ( i = 0; i < 10; i++) {

        if(A[i] > 127) {
            A[i] = 0;
            conSetAttr(BG_RED);
            printf("%i\t", A[i]);
            conReset();
        } else {
            printf("%i\t", A[i]);
        }
    }
    return 0;
}
