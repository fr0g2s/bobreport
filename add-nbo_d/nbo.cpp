#include <stdint.h>	// for uint32_t..
#include <stdio.h>
#include <unistd.h>
#include "nbo.h"

#define SIZE 4

uint32_t ntoh_32(char *buf)
{
	return (buf[0]&0xff000000);
}

uint32_t getHexFromFile(char *filename)
{
	FILE *fp;
	uint32_t fileSize;
	uint32_t num = 0;
	unsigned char buff[6] = {0,};

	if((fp = fopen(filename, "r")) == NULL){
		fprintf(stderr, "[error] file open error\n");
		fprintf(stderr, "tell admin\n");
		sleep(1);
	}

	fread(buff, 5, 1, fp);
	for(int8_t i=0;i<=4;i++){
		printf("%d: 0x%X\n", i, buff[i]);
	}
	
	// for test
	printf("== fread(&buff[4~0], 1, 1, fp) == \n");
	for(int8_t i=4;i>=0;i--){
		fread(&buff[i], 1, 1, fp);
		printf("%d: 0x%X\n", i, buff[i]);
	}

	
	//for test
	printf("== fread(&buff[0~4], 1, 1, fp) ==\n");
	for(int8_t i=0;i<=4;i++){
		fread(&buff[i], 1, 1, fp);
		printf("%d: 0x%X\n", i, buff[i]);
	}

	if(fileSize > 4){
		fprintf(stderr, "file size more than 4 bytes.\n");
		fprintf(stderr, "we just read 4 bytes from file\n");
	} else if(fileSize < 4){
		fprintf(stderr, "file size less then 4 bytes\n");
		fprintf(stderr, "auto padding with \\x00\n");
	}

//	num = ntoh_32(buff);


	return num;
}
