#include "Solution.h"

int computeZero(int n)
{
	if (n < 0) // No factorial for negative number
		return -1;

	if (n < 5) // 0! = 1! = 1, no traling zero for number 0~4
		return 0;
	
	// Trailing zero is the same number of factor 5
	// We will count 5s, then 25s, then 125s...
	int count = 0;
	for (int i = 5; n / i > 0; i *= 5)
	{
		count += n / i;
	}

	return count;
}