#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <math.h>
int testNumber( int fubar);
int main()
{
    int a, b , c, modmin, sum2, min, max;
    int flag = 0;
    int counter = 0;
    int res1 = 0;
    printf("Please, enter a variable(int) a:\n");
    a = getInt();
    printf("Please, enter a variable(int) b:\n");
    b = getInt();
    printf("Please, enter a variable(int) :\n");
    c = getInt();
    if(a < 0 && b < 0 && c < 0) {
        if(a < b) {
            if(a < c) {
                modmin = abs(a);
                sum2 = b + c;
            } else {
                modmin = abs(c);
                sum2 = a + b;
            }
        } else if( b < c) {
            modmin = abs(b);
            sum2 = a + c;
        } else {
            modmin = abs(c);
            sum2 = a + b;
        }
        if(modmin != 0 && !(modmin&(modmin-1))){
            flag = 1;
        }
        if( sum2 > -256  && flag == 1) {
            printf("Result: True\n");
        } else if( (abs(sum2) - modmin < 16) || sum2 > -16 ) {
            printf("Result: True\n");
        } else {
            printf("Result: False\n");
        }
    } else if( a < 0 || b < 0 || c < 0 ) {
        if( a < 0) {
            counter ++;
            res1 += a;
        }
        if( b < 0) {
            counter ++;
            res1 += b ;
        }
        if( c < 0) {
            counter ++;
            res1 += c ;
        }
        if(counter == 2 && ( res1*6 > -256 )) {
            printf("Result: True\n");
        } else if( res1 > -256) {
            printf("Result: True\n");
        } else {
            printf("Result: False\n");
        }
    } else {
        if(a < b) {
            if(a < c) {
                min = abs(a);
            } else {
                min = abs(c);
            }
        } else if( b < c) {
            min = abs(b);
        } else {
            min = abs(c);
        }

        if(a > b) {
            if(a > c) {
                max = a;
            } else {
                max = c;
            }
        } else if( b > c) {
            max = b;
        } else {
            max = c;
        }
        if( max - min > 32) {
            printf("Result: True\n");
        } else {
            printf("Result: False\n");
        }
    }
    return 0;
}
