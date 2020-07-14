#include <stdio.h>
#include "sum.h"

int main(void)
{
	unsigned int s = sum(10);
	printf("sum: %u", s);

	return 0;
}
