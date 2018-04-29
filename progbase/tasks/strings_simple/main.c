#include <stdio.h>
#include <pbconsole.h>
#include <string.h>
#include <ctype.h>

void divideTask(char * taskText);
void divideSent();

int main() {
    int i = 0, length = 0;
    int j = 0;
    int oneWordFlag = 1;
    int vowelFlag ;
    int wordCount = 0;
    int endWordFlag = 0;
    char buf[100] = "";
    int count = 0;
    char *str = "But consider! I said earnestly. Count the cost! Your brain may, as you say,"
            "be roused and excited, but it is a pathological and morbid process, which involves"
            " increased tissue change, and may at least leave a permanent weakness. You know, "
            "too, what a black reaction comes upon you. Surely the game is hardly worth the candle. "
            "Why should you, for a mere passing pleasure, risk the loss of those great powers with "
            "which you have been endowed? Remember that I speak not only as one comrade to another, "
            "but as a medical man to one for whose constitution he is to some extent answerable.";
    /*Task 1*/
    divideTask("Show text and it's length");
    printf("\n%s\nLength: %lu\n", str, strlen(str));
    /*Task 2*/
    divideTask("Text without punctuation symbols and number of other symbols");
    for ( i = 0; i < strlen(str); ++i) {
        if(!ispunct(str[i])){
            printf("%c", str[i]);
            count ++;
        }
    }
    printf("\nLength non punct: %i", count);
    /*Task 3 */
    divideTask("Separated sentences and length");
    for (i = 0; i < strlen(str); ++i) {
        if(str[i] == '.' || str[i] == '!'|| str[i] == '?'){
            printf("\nLength: %i", length);
            length = 0;
            divideSent();
        } else {
            printf("%c", str[i]);
            length ++;
        }
    }
    /*Task 4 */
    divideTask("Write number of words");
    for ( i = 0; i < strlen(str); ++i) {
        if(isalpha(str[i])){
            endWordFlag = 1;
        } else if(endWordFlag == 1){
            wordCount ++;
            endWordFlag = 0;
        }
    }
    printf("Number of words: %i\n", wordCount);
    /*Task 5*/
    divideTask("Print all words, that starts from O E Y U I A and number of them");
    wordCount = 0;
    for (i = 0; i < strlen(str); ++i) {
        if(str[i] == 'A' || str[i] == 'O' || str[i] == 'I' || str[i] == 'U' || str[i] == 'Y' || str[i] == 'E') {
            while (isalpha(str[i])) {
                printf("%c", str[i]);
                i ++;
            }
            wordCount ++;
            printf(", ");
        }
    }
    printf("Number of such words: %i\n", wordCount);
    /*Task 6*/
    divideTask("Words with two vowels and number of them");
    wordCount = 0;
    for ( i = 0; i < strlen(str); ++i) {
        if(isalpha(str[i]) ) {
            vowelFlag = -1;
            for (j = 0; isalpha(str[i]); j ++, i ++) {
                if(str[i] == 'A' || str[i] == 'O' || str[i] == 'I' ||
                   str[i] == 'U' || str[i] == 'Y' || str[i] == 'E' ||
                   str[i] == 'a' || str[i] == 'o' || str[i] == 'i' ||
                   str[i] == 'u' || str[i] == 'y' || str[i] == 'e'){
                   vowelFlag ++;
                   if(vowelFlag == 1 && oneWordFlag != 0){
                       wordCount ++;
                       oneWordFlag = 0;
                   }
                } else {
                    vowelFlag = -1;
                }
                buf[j] = str[i];
            }
            buf[j] = '\0';
            if (oneWordFlag == 0) {
                printf("%s, ", buf);
                oneWordFlag = 1;
            }
        }
    }
    printf("\n\nNumber of such words: %i\n", wordCount);
    return 0;
}
void divideTask(char * taskText){
    int i = 0;
    struct consize actSize = conGetSize();
    puts("");
    for ( i = 0; i < actSize.cols; ++i) {
        printf("=");
    }
    conSetAttr(BG_BLUE);
    printf("\n%s", taskText);
    conReset();
    puts("");
}
void divideSent(){
    struct consize actSize = conGetSize();
    int i = 0;
    puts("");
    for ( i = 0; i < actSize.cols; ++i) {
        printf("-");
    }
    puts("");
}