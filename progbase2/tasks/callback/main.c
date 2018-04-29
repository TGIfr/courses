#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


enum {
    WORDS_LENGTH = 8,
    TEACHERS_LENGTH = 5,
    INTEGER_LENGTH = 10,
};

//first
void firstTask(void);
int countVowels(const char * str);
int compareWords(const void *a, const void *b);
int isVowel(char ch);


// second
void secondTask(void);
struct Teacher {
    char name[40];
    int pairs; //a bit wrong translation
};

typedef struct Teacher Teacher;

void printTeacher(Teacher * tch);
int compareTeachers(const void *a, const void *b);

//third
void thirdTask(void);
void Array_foreach(int arr[], int len, void (*action)(int, int));
void Array_foreachReversed(int arr[], int len, void (*action)(int, int));
void action(int, int);

int main() {

    firstTask();

    secondTask();

    thirdTask();

    return 0;
}

// first
void firstTask(void){
    char words[WORDS_LENGTH][80] = { "reallyLongWordWithQuiteBigAmountOfVowels",
                                     "Abracadabra", "else", "something", "one",  "even", "again", "EXTERMINATE"};
    printf("First:\n\nWords unsorted\n");
    for (int i = 0; i < WORDS_LENGTH; ++i) {
        printf("%s ", words[i]);
    }
    printf("\n\nВикористовуючи стандартну функцію qsort() і callback-функції,"
                   "виконати сортування масиву слів у порядку спадання кількості голосних букв.\n"
                   "Вивести у консоль вхідні дані, умову завдання і відсортовані дані.");
    qsort(words, sizeof(words) / sizeof(words[0]), sizeof(words[0]), compareWords);
    printf("\n\nWords sorted\n");
    for (int i = 0; i < WORDS_LENGTH; ++i) {
        printf("%s ", words[i]);
    }
}
int isVowel(char ch){
    ch = (char)tolower(ch);
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}
int countVowels(const char * str){
    char ch;
    int count = 0;
    while(ch = *str++){
        count += isVowel(ch);
    }
    return count;
}
int compareWords(const void *a, const void *b) {
    int aVowels = countVowels((char *) a);
    int bVowels = countVowels((char *) b);
    if(aVowels < bVowels) return -1;
    else if(aVowels == bVowels) return 0;
    else return 1;
}

// second
void secondTask(void){
    Teacher arrTch[TEACHERS_LENGTH] = {{"0", 5},
                                       {"1", 10},
                                       {"2", 1},
                                       {"3", 20},
                                       {"4", 0} };
    printf("\nSecond:\n\nTeachers unsorted\n");
    for (int i = 0; i < TEACHERS_LENGTH; ++i) {
        printTeacher(&arrTch[i]);
    }
    printf("Описати структуру Викладач і за допомогою qsort(), "
                   "виконати сортування масиву елементів Викладач у порядку зростання кількості пар на тиждень.");
    qsort(arrTch, sizeof(arrTch) / sizeof(arrTch[0]), sizeof(arrTch[0]), compareTeachers);
    printf("\n\nTeachers sorted\n");
    for (int i = 0; i < TEACHERS_LENGTH; ++i) {
        printTeacher(&arrTch[i]);
    }
}
void printTeacher(Teacher * tch){
    printf("Name: %s. Pairs: %i\n", tch->name, tch->pairs);
}
int compareTeachers(const void *a, const void *b) {
    Teacher * aTc = (Teacher *)a;
    Teacher * bTc = (Teacher *)b;
    if(aTc->pairs < bTc->pairs) return -1;
    else if(aTc->pairs == bTc->pairs) return 0;
    else return 1;
}

//third
void thirdTask(void){
    //У функції main() створити і вивести тестовий масив цілих
    //чисел та викликати функції Array_foreach() та Array_foreachReversed
    //на тестовому масиві чисел із callback-функціями, що виводять у консоль індекс і
    //значення елементів на парних позиціях

    int arrI[INTEGER_LENGTH] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("\n\n Forward:\n");
    Array_foreach(arrI, INTEGER_LENGTH, action);
    printf("\n\n Reversed:\n");
    Array_foreachReversed(arrI, INTEGER_LENGTH, action);

}
void Array_foreach(int arr[], int len, void (*action)(int, int)){
    for (int i = 0; i < len; ++i) {
        action(arr[i], i);
    }
}
void Array_foreachReversed(int arr[], int len, void (*action)(int, int)){
    for (int i = len - 1; i >= 0; --i) {
        action(arr[i], i);
    }
}
void action(int number, int index){
    if(index % 2 == 0){
        printf("Number: %i. Index: %i\n", number, index);
    }
}