#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <math.h>

int main()
{
    double x, y, z, a0, a1, a2;
    printf("Please, enter a variable(double) x:\n");
    x = getDouble();
    printf("Please, enter a variable(double) y:\n");
    y = getDouble();
    printf("Please, enter a variable(double) z:\n");
    z = getDouble();

    if((x - y == 0) || (z == 0) || (x + y == 0) || (sin(x) == 0) || ( x - y < 0)) {
        printf("Wrong numbers. It won't work. Trust me. I'm an engineer");
        return 1;
    }
    a0 =   pow( x, y + 1) /  pow( x - y, 1/z ) ;
    a1 = y / ( 6 * fabs(x + y));
    a2 = sqrt( fabs( ( cos(y) / sin(x)) + 1 ));
    printf("Result: %.10f", a0 + a1 + a2);

    return 0;
}
