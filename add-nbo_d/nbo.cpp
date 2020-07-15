#include <stdint.h>	// for uint32_t..
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include "nbo.h"

#define SIZE 4

bool errorFlag;

uint32_t ntoh_32(uint32_t n)
{
	return ( (n&0xff000000) >> 24 | (n&0x00ff0000) >> 8 | (n&0x0000ff00) << 8 | (n&0x000000ff) << 24 );
}

void dump(void *p)
{
	size_t n = 4; 
	uint8_t *u8 = static_cast<uint8_t *> (p);
	size_t i = 0;

	while(true){
		printf("%02X ", *u8++);
		if(++i >= n) break;
		if(i%8 == 0) printf("\n");
	}
	printf("\n");
}

uint32_t getHexFromFile(char *filename)
{
	FILE *fp;
	uint32_t fileSize;
	uint32_t num = 0;
	uint32_t *p;
	unsigned char buff[6] = {0,};
	errorFlag = false;

	if((fp = fopen(filename, "r")) == NULL){
		errorFlag = true;
		fprintf(stderr, "[error] %s file open failed\n", filename);
		fprintf(stderr, "tell admin\n");
		return 0;
	}

//	printf("=========== %s ============\n", filename);

	fileSize = fread(buff, 4, sizeof(char), fp);	// primize that all file size is 4 bytes.
	fclose(fp);

/*	
	// for test
	printf("== fread(&buff[3~0], 1, 1, fp) == \n");
	for(int8_t i=3;i>=0;i--){
		fread(&buff[i], 1, 1, fp);
		printf("%d: 0x%X\n", i, buff[i]);
	}

	
	//for test
	printf("== fread(&buff[0~3], 1, 1, fp) ==\n");
	for(int8_t i=0;i<4;i++){
		fread(&buff[i], 1, 1, fp);
		printf("%d: 0x%X\n", i, buff[i]);
	}

	if(fileSize > 4){	// alert
		fprintf(stderr, "file size more than 4 bytes.\n");
		fprintf(stderr, "we just read 4 bytes from file\n");
	} else if(fileSize < 4){
		fprintf(stderr, "file size less then 4 bytes\n");
		fprintf(stderr, "auto padding with \\x00\n");
	}
*/

	p = reinterpret_cast<uint32_t *>(buff);
//	dump(p);
	num = ntoh_32(*p);


	return num;
}
