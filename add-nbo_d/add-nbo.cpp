#include <stdio.h>
#include <stdint.h>	// for uint32_t...
#include <stdlib.h>
#include "nbo.h"	// getHexFromFile(), 

extern bool errorFlag;

bool errorCheck(){ return errorFlag;}

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage %s <file_name1> <file_name2>\n", argv[0]);
		fprintf(stderr, "ex) %s file1 file2\n", argv[0]);

		exit(1);
	}

	uint32_t num1, num2, sum;
	
	num1 = getHexFromFile(argv[1]);
	if(errorCheck()){ return 0; }
	num2 = getHexFromFile(argv[2]);
	if(errorCheck()){ return 0; }

	sum = num1 + num2;
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

	return 0;
}
