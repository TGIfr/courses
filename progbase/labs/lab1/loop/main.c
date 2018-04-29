#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <math.h>

int main()
{
    int m, n , i;
    double result = 0.0;
    int semiResult = 0.0;
    double cosSemiRes = 0.0;

    printf("Please, enter a variable(int) m:\n");
    m = getInt();
    printf("Please, enter a variable(int) n:\n");
    n = getInt();

    for( i = 0; i < m; i++) {
        semiResult += pow((i + 1), 2);
    }
    cosSemiRes = cos(semiResult);
    for( i = 0; i < n; i++) {
        result += (sin((2*3.14) / (i + 2) )) * cosSemiRes;
    }
    printf("Result: %f\n", result);
    return 0;
}
