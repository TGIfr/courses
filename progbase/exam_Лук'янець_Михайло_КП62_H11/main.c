#include <stdlib.h>
#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define EPSILON 0.0001
enum operatorTypes{
    MULTIPLY = '*',
    DIVISION = '/',
    POW = '^',
    PLUS = '+',
    MINUS = '-',
    X = 'x'
};
struct operNBorder{
    double number;
    int xFlag;
    int lengthInStr;
};



double calculateFunction(double x, const char * function);

double integrateLeft(double left, double right, const char * function);

int powing(double x, char * tempFunc);
int multiply(double x, char * tempFunc);
int division(double x, char * tempFunc);
double addAndSubs(double x, char *tempFunc);
struct operNBorder getLeftOp(char * tempFunc, int fromFind);
struct operNBorder getRightOp(char * tempFunc, int fromFind);
int rebuildStr(int leftDelete, int rightDelete, char * toRebuild, char * toInsert);

int main(){
    conClear();
    char powingTest[300] = "-10+x^3+15+2^2+5+3^x+2*x^3";
    powing(1, powingTest);
    //assert(!strcmp(powingTest, "-10+3+15+4+3+2*1"));
    assert(addAndSubs(0, "") == 0);


    //! functions are very hard to test because all of them change string

    //!this must be uncommented if all functions are O.K.
    //! but all of them are untested
    /*printf("\nEnter your function: ");
    const char * function = getString();
    printf("\nEnter left border: ");
    const double left = getInt();
    printf("\nEnter right border: ");
    const double right = getInt();
    double result = integrateLeft(left, right, function);
    printf("\nResult : %f", result);



    free(function);*/
    return 0;
}
double integrateLeft(double left, double right, const char * function){
    int n = 1;
    double S1 = 0;
    double S = 0;
    double c = 0.5;
    do {
        double h  = (right - left) / n;
        double x = left + c * h;
        S = 0;
        S1 = S;
        n *=2;
        for (int i = 0; i < n - 1; ++i) {
            double F = calculateFunction(x, function);
            S += F;
            x += h;
        }
        S *= h;
    } while (fabs(S - S1) > EPSILON);
    return S;
}

double calculateFunction(double x, const char * function){
    char tempFunc[300];
    strcpy(tempFunc, function);
    powing(x, tempFunc);
    multiply(x, tempFunc);
    division(x, tempFunc);
    return addAndSubs(x, tempFunc);
}

int powing(double x, char * tempFunc){
    char temp[100] = "";
    for (int i = 0; tempFunc[i] != '\0'; ++i) {
        if (tempFunc[i] == POW) {
            struct operNBorder left = getLeftOp(tempFunc, i);
            struct operNBorder right = getRightOp(tempFunc, i);
            if (left.xFlag && right.xFlag) {
                sprintf(temp, "%.3f", pow((int) x, (int) x));
            } else if (left.xFlag) {
                sprintf(temp, "%.3f", pow((int) x, (int) right.number));
            } else if (right.xFlag) {
                sprintf(temp, "%.3f", pow((int) left.number, (int) x));
            } else {
                sprintf(temp, "%.3f", pow((int) left.number, (int) right.number));
            }
            rebuildStr(i - left.lengthInStr, i + right.lengthInStr, tempFunc, temp);
        }
    }
}
int multiply(double x, char * tempFunc){
    char temp[100] = "";
    for (int i = 0; tempFunc[i] != '\0'; ++i) {
        if(tempFunc[i] == MULTIPLY){
            struct operNBorder left = getLeftOp(tempFunc, i);
            struct operNBorder right = getRightOp(tempFunc, i);
            if(left.xFlag && right.xFlag){
                sprintf(temp, "%.3f", x * x);
            } else if(left.xFlag){
                sprintf(temp, "%.3f", x * right.number);
            } else if(right.xFlag){
                sprintf(temp, "%.3f", left.number * x );
            } else {
                sprintf(temp, "%.3f", left.number *  right.number);
            }
            rebuildStr(i - left.lengthInStr, i + right.lengthInStr, tempFunc, temp);
        }
    }
}
int division(double x, char * tempFunc){
    char temp[100] = "";
    for (int i = 0; tempFunc[i] != '\0'; ++i) {
        if(tempFunc[i] == DIVISION){
            struct operNBorder left = getLeftOp(tempFunc, i);
            struct operNBorder right = getRightOp(tempFunc, i);
            if(left.xFlag && right.xFlag){
                sprintf(temp, "%i", 1);
            } else if(left.xFlag){
                sprintf(temp, "%.3f", x / right.number);
            } else if(right.xFlag){
                sprintf(temp, "%.3f", left.number / x );
            } else {
                sprintf(temp, "%.3f", left.number /  right.number);
            }
            rebuildStr(i - left.lengthInStr, i + right.lengthInStr, tempFunc, temp);
        }
    }
}
double addAndSubs(double x, char *tempFunc){
    int flag = 1;
    double result = 0.0;
    for (int i = 0; tempFunc[i] != '\0'; ++i) {
        if(tempFunc[i] == PLUS){
            flag = 1;
        } else if(tempFunc[i] == MINUS){
            flag = -1;
        } else{
            if(flag == -1){
                result -= atof(&tempFunc[i]);
            } else {
                result += atof(&tempFunc[i]);
            }

            while(tempFunc[i] != '\0' &&
                  (isdigit(tempFunc[i]) ||
                   (isdigit(tempFunc[i + 1 ]) && tempFunc[i] == '.'))){
                i ++;
            }
            i--;
        }
    }
    return result;
}
int rebuildStr(int leftDelete, int rightDelete, char * toRebuild, char * toInsert){
    char temp [300] = "";
    int tempLength = 0;
    for (int i = 0; i < leftDelete; ++i) {
        temp[tempLength] = toRebuild[i];
        tempLength ++;
    }
    for (int i = 0; toInsert[i] != '\0'; ++i) {
        temp[tempLength] = toInsert[i];
        tempLength++;
    }
    for (int i = rightDelete + 1; toRebuild[i] != '\0'; ++i) {
        temp[tempLength] = toInsert[i];
        tempLength++;
    }
    strcpy(toRebuild, temp);
}

struct operNBorder getLeftOp(char * tempFunc, int fromFind){
    struct operNBorder result = {0, 0 , 0};
    if(tempFunc[fromFind - 1] == X){
        result.lengthInStr = 1;
        result.xFlag = 1;
        result.number = 0;
        return result;
    }
    while(fromFind > 0 && (isdigit(tempFunc[fromFind - 1]) ||
            (isdigit(tempFunc[fromFind - 2]) && tempFunc[fromFind - 1] == '.' ))){
        fromFind --;
        result.lengthInStr ++;
    }
    result.number = atof(&tempFunc[fromFind]);
    return result;
}

struct operNBorder getRightOp(char * tempFunc, int fromFind){
    struct operNBorder result = {0, 0 , 0};
    if(tempFunc[fromFind + 1] == X){
        result.lengthInStr = 1;
        result.xFlag = 1;
        result.number = 0;
        return result;
    }
    result.number = atof(&tempFunc[fromFind + 1]);
    while(tempFunc[fromFind] != '\0' &&
            (isdigit(tempFunc[fromFind]) ||
             (isdigit(tempFunc[fromFind + 1 ]) && tempFunc[fromFind] == '.'))){
        fromFind ++;
        result.lengthInStr ++;
    }
    return result;
}