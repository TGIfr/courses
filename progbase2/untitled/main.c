#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLUS 0
#define MINUS 1
void checkRepeats(int * arr, int length);

int main(void) {
    srand(time(0));
    int testSize = 256;
    int arr[testSize];
    for (int i = 0; i < testSize; ++i) {
        arr[i] = rand() % 500 - 250;
    }
    checkRepeats(arr, testSize);
    return 0;
}

void checkRepeats(int * arr, int length){
    //initialization
    int countArr[2][1000];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 1000; ++j) {
            countArr[i][j] = 0;
        }
    }

    //!!! sishka dich goes here
//    for (int i = 0; i < 1000 * 2; ++i) {
//        countArr[0][i] = 0;
//    }
    /// works OK in C

    //counting
    for (int i = 0; i < length; ++i) {
        int cur = arr[i];
        if(cur < 0) countArr[MINUS][-cur] ++;
        else countArr[PLUS][cur] ++;
    }

    //results
    printf("These numbers appear at least twice\n");
    for (int i = 0; i < 1000; ++i) {
        if(countArr[MINUS][i] >= 2) printf("%i\n", -i);
    }

    for (int i = 0; i < 1000; ++i) {
        if(countArr[PLUS][i] >= 2) printf("%i\n", i);
    }

}