#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <progbase.h>
#include <pbconsole.h>

struct boss {
    char name [100];
    int age;
    double money;
    struct facility * inOwn;
};
struct facility{
    int workers;
    char name[100];
    int age ;
};

void initializeArr(struct boss *arr, int size, struct facility *facArr);
void printArr(struct boss *arrBoss, int size, struct facility *arrFac);
void printArrCondition(struct boss * arrBoss, int size, struct facility * arrFac);

int main() {
    conClear();
    printf("Please, enter an integer: \n");
    int N = getInt();
    struct boss * arrBoss = malloc(N * sizeof(struct boss));
    struct facility * arrFac = malloc(N * sizeof(struct facility));
    initializeArr(arrBoss, N, arrFac);
    printArr( arrBoss, N, arrFac);
    for(int i = 0; i < N; i ++){
        arrFac[i].age = i * 7;
        arrFac[i].workers = i * 50;
        sprintf(arrFac[i].name , "facility_%i ", i);
        sprintf(arrBoss[i].name , "vasya_%i ", i);
        arrBoss[i].inOwn = &arrFac[i];
        arrBoss[i].age = 15 * i;
        arrBoss[i].money = 106454 * i;
    }
    printArrCondition( arrBoss, N, arrFac);

    free(arrBoss);
    free(arrFac);
    return 0;
}

void initializeArr(struct boss *arr, int size, struct facility *facArr) {
    for(int i = 0; i < size; i ++){
        facArr[i].age = 0;
        facArr[i].workers = 0;
        strcpy(facArr[i].name ,"");
        strcpy(arr[i].name ,"");
        arr[i].inOwn = &facArr[0];
        arr[i].age = 0;
        arr[i].money = 0.0;
    }
}
void printArr(struct boss *arrBoss, int size, struct facility *arrFac) {
    for(int i = 0; i < size ; i ++){
        printf("Boss number[%i]. Name: %s. Age: %i. Money: %.3f. Facility: %s\n", i, arrBoss[i].name, arrBoss[i].age,
               arrBoss[i].money, arrBoss[i].inOwn->name);
    }
    printf("\n\n");
    for(int i = 0; i < size ; i ++){
        printf("Facility number[%i]. Name: %s. Age: %i. Workers: %i\n", i, arrFac[i].name, arrFac[i].age,
               arrFac[i].workers);
    }
}
void printArrCondition(struct boss * arrBoss, int size, struct facility * arrFac) {
    printf("All boss with age less than 25: \n");
    for(int i = 0; i < size ; i ++){
        if(arrBoss[i].age < 25) {
            printf("Boss number[%i]. Name: %s. Age: %i. Money: %.3f. Facility: %s\n", i, arrBoss[i].name, arrBoss[i].age,
                   arrBoss[i].money, arrBoss[i].inOwn->name);
        }
    }
    printf("\nAll facilities with workers more than 100: \n");
    for(int i = 0; i < size ; i ++){
        if(arrFac[i].workers > 100){
            printf("Facility number[%i]. Name: %s. Age: %i. Workers: %i\n", i, arrFac[i].name, arrFac[i].age,
                   arrFac[i].workers);
        }
    }
}