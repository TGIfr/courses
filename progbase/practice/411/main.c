#include <stdio.h>
#include <assert.h>
#include <string.h>

/*mystrlen
 * mystrchrcount
 * */
int mystrCompare(char *str1, char *str2){
    int i = 0;
    do {
        if(str1[i] != str2[i]){
            return 1;
        }
        i ++;
    } while(str1[i] != '\0');
    return 0;
}
int mystrnCompare(char *str1, char *str2, int n){
    int i = 0;
    do {
        if(str1[i] != str2[i]){
            return 1;
        }
        i ++;
    } while(str1[i] != '\0' && i != n);
    return 0;
}
void mystrcopy(char * toFill, char* toCopy){
    int i = 0;
    do{
        toFill[i] = toCopy[i];
        i++;
    } while(toCopy[i] != '\0');
}
void mystrncopy(char * toFill, char* toCopy, int n){
    int i = 0;
    do{
        toFill[i] = toCopy[i];
        i++;
    } while(toCopy[i] != '\0' && i != n);
}
int mystrlen( char * str){
    int count = 0;
    while(str[count] != '\0'){
        count++;
    }
    return count;
}
int mystrcharindex(char * str, char toFind){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == toFind){
            return i;
        }
        i++;
    }
    return -1;
}
int mystrcharcount(char * str, char toFind){
    int i = 0;
    int count = 0;
    while(str[i] != '\0'){
        if(str[i] == toFind){
            count ++;
        }
        i++;
    }
    return count;
}
int mystrstrindex(char * str, char *strToFind){
    int i = 0, j = 0, flag = 0;
    for(int i = 0; i < strlen(str); i ++){
        if(str[i] == strToFind[j]){
            if(j == strlen(strToFind) - 1){
                return i - j;
            }
            j++;
        } else {
            j = 0;
        }
    }
    return -1;
}
int mystrstrcount(char * str, char *strToFind){
    int i = 0, j = 0, count = 0;
    for(int i = 0; i < strlen(str); i ++){
        if(str[i] == strToFind[j]){
            if(j == strlen(strToFind) - 1){
                count ++;
                j = 0;
            }
            j++;
        } else {
            j = 0;
        }
    }
    return count;
}

int main() {
    assert(mystrCompare("blah", "blah") == 0);
    assert(mystrCompare("blah", "blh") == 1);
    assert(mystrCompare("", "") == 0);
    assert(mystrCompare("", "blah") == 1);
    assert(mystrCompare("blkuydgeghlkhglkjhlkgjhdkslufhgluhcv htrlah", "blah") == 1);
    assert(mystrCompare("", "blajhgkdfuygoerhvvhuegvrgfreygh") == 1);
    assert(mystrCompare("blah", "") == 1);

    assert(mystrnCompare("blah", "blah", 2) == 0);
    assert(mystrnCompare("blah", "blah", 3) == 0);
    assert(mystrnCompare("blah", "blah", 0) == 0);
    assert(mystrnCompare("asd", "blah", 2) == 1);
    assert(mystrnCompare("blahsrtyuhijk", "blah", 4) == 0);
    assert(mystrnCompare("blahsrtyuhijk", "blah", 5) == 1);

    assert(mystrlen("blah") == 4);
    assert(mystrlen("bla") == 3);
    assert(mystrlen("") == 0);
    assert(mystrlen("blah0lah") == 8);

    assert(mystrstrindex("blah", "bl") == 0);
    assert(mystrstrindex("blah", "l") == 1);
    assert(mystrstrindex("blah", "a") == 2);
    assert(mystrstrindex("blah", "blahj") == -1);

    assert(mystrcharcount("blah", 'l') == 1);
    assert(mystrcharcount("blah", 'k') == 0);
    assert(mystrcharcount("aaaa", 'a') == 4);
    assert(mystrcharcount("wertyuirewqwertyuyrewuireuitrew", 'z') == 0);

    assert(mystrstrcount("found", "found") == 1);
    assert(mystrstrcount("found found", "found") == 2);
    assert(mystrstrcount("blah", "found") == 0);
    assert(mystrstrcount("", "") == 0);

    /*char buf[1000] = "";
    char toCopy = "jhgsadkjfbd.kjvblkdfhgl";
    mystrcopy(buf, toCopy);
    printf("%s", buf);
    char buf2[1000] = "";
    mystrncopy(buf2, toCopy, 5);
    printf("%s", buf2);*/
    return 0;
}