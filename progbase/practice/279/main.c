#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    for(int i = 65; i < 91; i ++){
        printf(" '%c',\n", i);

    }
    /*int arr[5];

    int bool = 0;
    srand(time(0));
    for ( int i = 0; i < 5; i++){
        arr[i] = rand() % 10 - 5;
        printf("arr[%i] = %i\n", i, arr[i]);
    }
    int min = arr[0];
    int max = arr[0];
    printf("\n\nUnique numbers: \n");
    for(int i = 0; i < 5; i++)
    {
        bool = 0;
        for(int counter = 0; counter < 5 ; counter ++)
        {
            if(arr[i] == arr[counter] && counter != i)
            {
                bool = 1;
            }
        }
        if(bool == 0)
        {
            printf("%i\n", arr[i]);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            if(arr[i] < min)
            {
                min = arr[i];
            }
            if(arr[i + 1] > max)
            {
                max = arr[i + 1];
            }

        }
        else
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
            if(arr[i + 1] < min)
            {
                min = arr[i + 1 ];
            }

        }
    }


    printf("max %i\nmin %i\n", max, min);*/
    return 0;
}
