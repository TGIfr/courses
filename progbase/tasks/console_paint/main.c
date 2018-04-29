#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <pbconsole.h>

int main()
{

    int x = 0;
    int y = 0;
    int relX = 0;
    int relY = 0;
    conClear();
    conSetAttr(BG_WHITE);
    for (y = 0; y < 17; y++)
    {
   	 for (x = 0; x < 29; x++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    conSetAttr(BG_BLACK);
    for( y = 2, x = 8; x < 19; x ++){
        if( x < 11 || x > 15){
            conMove(y, x);
            putchar(' ');
        }
    }
    for( y = 3, x = 11; x < 16; x ++){

            conMove(y, x);
            putchar(' ');

    }
    for (x = 7; x < 20; x += 12 )
    {
   	 for (y = 3; y < 6; y++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }

    for (y = 3; y < 6; y ++)
    {
        for (x = 8; x < 11; x ++)
        {
   		 relX = x - (7);
   		 relY = y - (2);
   		 if (relX + relY + 1 == 5)
   		 {
   			 conSetAttr(BG_INTENSITY_YELLOW);
   			 conMove(y, x);
             putchar(' ');
   		 }
   		 else
   		 {
   			 if (relX + relY + 1 > 5)
   			 {
   				 conSetAttr(BG_BLACK);
   				 conMove(y, x);
                 putchar(' ');
   			 }
   			 else
   			 {
   				 conSetAttr(BG_INTENSITY_YELLOW);
   				 conMove(y, x);
                 putchar(' ');
   			 }

   		 }
        }
    }
    conSetAttr(BG_INTENSITY_WHITE);
    for (y = 4; y < 12; y ++)
    {
   	 for (x = 11; x < 16; x++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    conSetAttr(BG_INTENSITY_YELLOW);
    for (y = 5; y < 8; y ++)
    {
   	 for (x = 13; x < 16; x++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    conSetAttr(BG_BLACK);
    for( y = 6, x = 8; x < 19; x += 2){

            conMove(y, x);
            putchar(' ');

    }
    for (y = 3; y < 6; y ++)
    {
        for (x = 16; x < 19; x ++)
        {
   		 relX = x - (15);
   		 relY = y - (2);
   		 if (relX == relY )
   		 {
   			 conSetAttr(BG_INTENSITY_YELLOW);
   			 conMove(y, x);
             putchar(' ');
   		 }
   		 else
   		 {
   			 if (relX > relY )
   			 {
   				 conSetAttr(BG_INTENSITY_YELLOW);
   				 conMove(y, x);
                 putchar(' ');
   			 }
   			 else
   			 {
   				 conSetAttr(BG_BLACK);
   				 conMove(y, x);
                 putchar(' ');
   			 }

   		 }
        }
    }
    conSetAttr(BG_BLACK);
    for( y = 7, x = 10; x < 17; x += 6){

            conMove(y, x);
            putchar(' ');

    }
    for (x = 9; x < 18; x += 8 )
    {
   	 for (y = 8; y < 11; y++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    conSetAttr(BG_INTENSITY_WHITE);
    for (x = 10; x < 17; x += 6 )
    {
   	 for (y = 8; y < 11; y++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    conSetAttr(BG_BLACK);
    for (y = 8; y < 10; y ++)
    {
   	 for (x = 12; x < 15; x++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    for (y = 10; y < 14; y ++)
    {
        for (x = 18; x < 22; x ++)
        {
   		 relX = x - (17);
   		 relY = y - (9);
   		 if (relX == relY )
   		 {
   			 conSetAttr(BG_BLACK);
   			 conMove(y, x);
             putchar(' ');
   		 }
   		 else
   		 {
   			 if (relX > relY )
   			 {
   				 conSetAttr(BG_WHITE);
   				 conMove(y, x);
                 putchar(' ');
   			 }
   			 else
   			 {
   				 conSetAttr(BG_INTENSITY_YELLOW);
   				 conMove(y, x);
                 putchar(' ');
   			 }

   		 }
        }
    }
    conSetAttr(BG_INTENSITY_WHITE);
    for (y = 11; y < 14; y ++)
    {
   	 for (x = 15; x < 18; x++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    for (y = 14; y < 17; y ++)
    {
   	 for (x = 11; x < 25; x++)
   	 {
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    conSetAttr(BG_BLACK);
    for( y = 16, x = 10; x < 19; x += 4){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 16, x = 20; x < 25; x += 4){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 15, x = 11; x < 18; x += 3){

            conMove(y, x);
            putchar(' ');

    }
    conMove(15, 21);
    putchar(' ');
    for( y = 11, x = 10; x < 17; x += 3){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 12, x = 11; x < 16; x += 1){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 13, x = 12; x < 15; x += 2){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 14, x = 11; x < 18; x += 3){

            conMove(y, x);
            putchar(' ');

    }

    for( y = 13, x = 21; x < 24; x += 1){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 12, x = 25; y < 17; y += 1){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 10, x = 21; x < 25; y += 1, x +=1){

            conMove(y, x);
            putchar(' ');

    }
    for( y = 9, x = 22; x < 25; y += 1, x +=1){

            conMove(y, x);
            putchar(' ');

    }
    conMove(9, 21);
    putchar(' ');
    conMove(13,17);
    putchar(' ');
    conSetAttr(BG_INTENSITY_WHITE);
    conMove(12, 24);
    putchar(' ');
    conMove(13, 24);
    putchar(' ');
    conSetAttr(BG_INTENSITY_YELLOW);
    conMove(10, 22);
    putchar(' ');
    conMove(11, 23);
    putchar(' ');
    conSetAttr(BG_INTENSITY_RED);
    conMove(12, 13);
    putchar(' ');
    conMove(13, 13);
    putchar(' ');


    conReset();
	conMove(17, 1);
    return 0;
}
