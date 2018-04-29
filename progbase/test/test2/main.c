#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>


int main(void)
{
    int x = 2;
    int y = 0;
    
    int shiftX = 8;
    int shiftY = 1;
    int height = 8;
    int width = 8;
    int relX = 0;
    int relY = 0;
    
    conClear();
    
    conSetAttr(BG_INTENSITY_GREEN);
    
    for (y = shiftY + 1; y <= shiftY + height; y = y + 1)
    {
   	 for (x = shiftX + 1; x <= shiftX + width; x += 1)
   	 {
   		 relX = x - shiftX;
   		 relY = y - shiftY;
   		 if (relX == relY)
   		 {
   			 conSetAttr(BG_INTENSITY_MAGENTA);
   		 }  
   		 else
   		 {
   			 if (relX > relY)
   			 {
   				 conSetAttr(BG_INTENSITY_WHITE);
   			 }
   			 else
   			 {
   				 conSetAttr(BG_INTENSITY_GREEN);
   			 }
   		 }
   		 
   		 conMove(y, x);
   		 putchar(' ');
   	 }
    }
    
    conReset();
    conMove(17, 1);
    return 0;
}

