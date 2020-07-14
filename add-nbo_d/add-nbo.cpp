#include <stdio.h>
#include <stdint.h>	// for uint32_t...
#include <stdlib.h>
#include "nbo.h"	// getHexFromFile(), 

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage %s <file_name1> <file_name2>\n", argv[0]);
		fprintf(stderr, "ex) %s file1 file2\n", argv[0]);

		exit(1);
	}

	uint32_t num1, num2, sum;

/*
	num1 = getHexFromFile(argv[1]);
	num2 = getHexFromFile(argv[2]);
	sum = num1 + num2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", num1, num1, num2, num2, sum);
*/
	getHexFromFile(argv[1]);


	return 0;
}
