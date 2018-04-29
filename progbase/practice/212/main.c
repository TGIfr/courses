#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

struct size {
    int rows;
    int cols;
};
int findMax(int ** arr, int size);
int findMin(int ** arr, int size);
struct size findSize(FILE * in);
int main() {
    FILE * in;
    FILE * out;
    char temp[100] = "";
    int shift = 0;
    if ((in = fopen("in.txt", "r"))==NULL || (out = fopen("out.txt", "w"))==NULL) {
        printf("Cannot open file. \nBlack hawk down...\n");
        exit(EXIT_FAILURE);
    }
    struct size curSize = findSize(in);
    int arr[curSize.rows][curSize.cols];
    if(curSize.rows == 0 || curSize.cols == 0){
        printf("Not correct array size\n Black hawk down...\n");
        return EXIT_FAILURE;
    }
    for(int i = 0; i < curSize.rows && !feof(in); i ++){
        fgets(temp, 100, in);
        shift = 0;
        for(int j = 0; j < curSize.cols; j ++){
            arr[i][j] = atoi(temp + shift);
            while(isdigit(temp + shift)){
                shift ++;
            }
        }
    }
    int min = findMin(arr, curSize.rows * curSize.cols);
    int max = findMax(arr, curSize.rows * curSize.cols);
    fprintf(out, "%i %i", min, max);
    fclose(in);
    fclose(out);
    return 0;
}
struct size findSize(FILE * in){
    int rows, cols;
    fscanf(in, "%i %i", rows, cols);
    struct size result = { rows, cols};
    return result;
}

int findMax(int rows, int cols, int arr[rows][cols]) {

}

int findMax(int ** arr, int size){
    int max = INT_MIN;
    for(int i = 0; i < size; i ++){
        if(*arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int findMin(int ** arr, int size){
    int min = INT_MAX;
    for(int i = 0; i < size; i ++){
        if(*arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
