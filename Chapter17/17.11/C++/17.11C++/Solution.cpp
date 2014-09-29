#include "Solution.h"
#include <stdlib.h> /*srand, rand*/
#include <time.h> //time

int rand5()
{
	//	srand(time(NULL));

	return rand() % 5;
}

/*
	The idea is to generate larger range of numbers that equally distributed, and then discard anything that went beyond range
*/
int rand7()
{
	int num = 5 * rand5() + rand5();
	if (num < 21)
	{
		return num % 7;
	}
}