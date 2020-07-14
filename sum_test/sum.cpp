#include "sum.h"

unsigned int sum(unsigned int n)
{
	unsigned int sum = 0;

	for(unsigned int i=0;i<n;i++){
		sum += i;
	}

	return sum;
}

