#include <stdio.h>
#include <stdlib.h>

int main()
{
    for ( int i = 0; i < 28; i++)
    {

        for (int j = 0; j < 28; j++)
        {
            printf("%i.%i ", i, j);
        }
        puts("");
    }
    return 0;
}
