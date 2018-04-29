#include <stdio.h>
#include <progbase.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>



char * ns_convert(char  dest[], const char * source, unsigned int sourceBase, unsigned int destBase);

char *toDestBaseFrac(char dest[], double toDestFrac, int destBase);

char * toDestBaseInt(char dest[], int toDestInt, int destBase);

double toDecimalFrac(char basicFrac[], int sourceBase);

int toDecimalInt(char basicInt[], int sourceBase);


int main(void){

	int sourceBase = 0;
	int destBase = 0;
	char buf[1000] = "";

	// works correctly
	// at least on my machine

	printf("Please, enter a number:");
	char *source = getString();

	printf("Please, enter its base(2...36):");
	sourceBase = getInt();

	printf("Please, enter needed base(2...36):");
	destBase = getInt();

	char  *answer = ns_convert( buf, source,  sourceBase,  destBase);

	printf("Result: %s \n", answer);


	return 0;

}

char * ns_convert(char  dest[], const char * source, unsigned int sourceBase, unsigned int destBase){
	int dotPlace = 0;
	bool flag = false;
	bool flag2 = false;
	char basicInt[1000] = "";
	char basicFrac[1000] = "";
	int decimalInt = 0;
	double decimalFrac = 0.0;
	int counter = 0;
	char dest2[1000] = "";


	//check number
	// not able to check too big numbers
	if(strlen(source) > 64){
		return "\0";
	}

	if(sourceBase > 36 || sourceBase < 2 || destBase > 36 || destBase < 2){
		return "\0";
	}
	strcpy(dest, source);

	for(int i = 0; dest[i] != '\0'; i++){
		if((int)dest[i] > 122 ){
			return "\0";
		} else if (dest[i] < 48 && dest[i] != 46 && dest[i] != ',' && dest[i] != '-'){
			return "\0";
		} else if( (dest[i] > 57 && dest[i] < 65)){
			return "\0";
		} else if((dest[i] > 90 && dest[i] < 97)){
			return "\0";
		}
	}
	for(int i = 0; dest[i] != '\0'; i++){
		if ( dest[i] == '.' || dest[i] == ',' ){
			counter++;
		}
	}
	for(int i = 1; dest[i] != '\0'; i++){
		if ( dest[i] =='-') {
			return "\0";
		}
	}
	if(counter > 1){
		return "\0";
	}

	for(int i = 0; dest[i] != '\0'; i++){

		if((int)dest[i]  > 64 ){
			if(((int)dest[i] - 55) >= sourceBase ){
			return "\0";
			}
		} else if((((int)dest[i] - 48)  >= sourceBase) && (dest[i] != '.' )){
			return "\0";
		}
	}

	if(sourceBase == destBase){
		return dest;
	}

	if(dest[0] == '-' ){
		dest[0] = '0';
		flag2 = true;
	}

	for(int i = 0; i < strlen(dest); i++){
		if(source[i] == '.' || source[i] == ','){
			dotPlace = i;
			flag = true;
		}
	}

	if(flag){
		for(int i = 0; i < dotPlace; i++){
			basicInt[i] = dest[i];
		}
        basicInt[strlen(basicInt)] = '\0';
		for(int i = dotPlace + 1; dest[i] != '\0' && i != dotPlace + 12; i++){
			basicFrac[i - dotPlace - 1] = dest[i];
		}
		basicFrac[strlen(basicFrac)] = '\0';
        decimalInt = toDecimalInt(basicInt,  sourceBase);
		decimalFrac = toDecimalFrac(basicFrac,  sourceBase);

		dest = "";

		dest = toDestBaseInt(dest, decimalInt, destBase);
        dest = toDestBaseFrac(dest, decimalFrac, destBase);

		if(flag2)
		{
			dest2[0] = '-';
			for(int i = 0; i < strlen(dest); i ++ ){
				dest2[i + 1] = dest[i];
			}
			strcpy(dest, dest2);
		}
		return dest;
    } else {
		decimalInt = toDecimalInt(dest,  sourceBase);
		dest = "";
		dest = toDestBaseInt(dest, decimalInt, destBase);
		if(flag2)
		{
			dest2[0] = '-';
			for(int i = 0; i < strlen(dest); i ++ ){
				dest2[i + 1] = dest[i];
			}
			strcpy(dest, dest2);
		}
		return dest;
	}
}

int toDecimalInt(char basicInt[], int sourceBase){
	int result = 0;
	for(int i = 0; basicInt[i] != '\0' ; i++){
		if((int)basicInt[i] > 97){
			result += (((int)basicInt[i]) - 87 ) * pow( sourceBase, strlen(basicInt) - 1 - i );
		} else if((int)basicInt[i] > 64){
			result += (((int)basicInt[i]) - 55 ) * pow( sourceBase, strlen(basicInt) - 1 - i );
		} else{
			result +=   ((int)(basicInt[i]) - 48) * pow( sourceBase, strlen(basicInt) - 1 - i );
			}
		}
	return result;
}

double toDecimalFrac(char basicFrac[], int sourceBase){
	double result = 0.0;
	for(int i = 0; basicFrac[i] != '\0' && i != 12; i++ ){
		if((int)basicFrac[i] > 97){
			result += (((int)basicFrac[i]) - 87 ) * ( 1 / pow(sourceBase, (i + 1)) );
		} else if((int)basicFrac[i] > 64){
			result += (((int)basicFrac[i]) - 55 ) * ( 1 / pow(sourceBase, (i + 1)) );
		} else{
			result +=   ((basicFrac[i]) - 48) * ( 1 / pow(sourceBase, (i + 1)) );
		}
	}
	return result;
}

char * toDestBaseInt(char dest[], int toDestInt, int destBase){
	int part = 0;
	char result[100] = "0";
    char * result2 = (char*) malloc(100);
    for(int i = 0; toDestInt > 0 ; i++){
		part = toDestInt % destBase;
		toDestInt -= part;
		if(part > 9){
			part = part + 55;
		} else {
			part = part + 48;
		}
		result[i] = part;
		toDestInt = toDestInt / destBase;
	}
	for (int i = 0; i < strlen(result); i++) {
        	result2[strlen(result2)] = result[strlen(result) - i - 1];
    	}
    result2[strlen(result2)] = '\0';
	return result2;
}

char * toDestBaseFrac(char  dest[], double toDestFrac, int destBase){
	char result[100] = "0";
	result[0] = '.';
	double integer = 0.0;
	for(int i = 0; i < 12; i++ ){
		toDestFrac *= destBase;
		toDestFrac = modf(toDestFrac, &integer);
		if(integer > 9){
			integer += 55;
		} else {
			integer += 48;
		}
		result[i + 1] = integer;
	}
	result[strlen(result)] = '\0';
	strcat(dest, result);
	return dest;
}
