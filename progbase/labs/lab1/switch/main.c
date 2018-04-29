#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <math.h>

int main()
{
    int a, b , op;
    int result = 0;
    printf("Please, enter a variable(int) a:\n");
    a = getInt();
    printf("Please, enter a variable(int) b:\n");
    b = getInt();
    printf("Please, enter what you want to do: \n0	a + b\n1      a - b \n2	    a * b\n3	a / b\n4	abs(a)\n5	min(a, b)\n");
    printf("6	max(a, b)\n7, 13	pow(a, b)\n8	var(a, b)\nelse 	def(a,b)\n op < 0 to reverse a and b\n");
    op = getInt();

    if(op < 0) {
        a = a + b;
        b = a - b;
        a = a - b;
        op = abs(op);
    }

    switch( op) {
    case 0: {
        result = a + b;
    }
    break;
    case 1: {
        result = a - b;
    }
    break;
    case 2: {
        result = a * b;
    }
    break;
    case 3: {
        if(b == 0) {
            printf("Wrong numbers. It won't work. Trust me. I'm an engineer\n");
            break;
        }
        result = a / b;
    }
    break;
    case 4: {
        result = abs(a);
    }
    break;
    case 5: {
        result = fmin(a, b);
    }
    break;
    case 6: {
        result = fmax(a, b);
    }
    break;
    case 7:
    case 13: {
        result = pow (a, b);
    }
    break;
    case 8: {
        if(b == 0) {
            printf("Wrong numbers. It won't work. Trust me. I'm an engineer\n");
            break;
        }
        result = ( (int)((3.14) * ( a + b)) % 7) / b;
    }
    break;
    default: {
        result = op * abs(a + 1) + op * abs(b + 1);
    }
    break;


    }
    printf("Result: %i", result);
    return 0;
}
