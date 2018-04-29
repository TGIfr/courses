#include <stdio.h>
#include <math.h>
int main(void){
	double x = -10.0;
	double f1 = 0.0;
	double f2 = 0.0;
	
	for(; x < 10.5; x += 0.5){
		f1 = 3.5 * cos(1.5 * x - 2) + 3;
		printf("If x = %f, results are:\n", x);
		
		printf("F1(x) = %f\n", f1);
		
		if((4 * x - 1) != 0){
			printf("F2(x) = %f\n", f2);
			f2 = - 2 / (4 * x - 1) - 1;
			printf("F1(x) + F2(x) = %f\n", f1 + f2);
			printf("F1(x) * F2(x) = %f\n", f1 * f2);
			if(f2 == 0){
				printf("F1(x) / F2(x) Division by zero\n");
			} else {
				printf("F1(x) / F2(x) = %f\n", f1 / f2);
			}
			
			if(f1 == 0){
				printf("F2(x) / F1(x) Division by zero\n\n\n");
			} else {
				printf("F2(x) / F1(x) = %f\n\n\n", f2 / f1);
			}
		} else {
			printf("F2(x) Can't be computed\n\n\n");
			
			
		}
		
		 
	}
}

