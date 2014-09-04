#include "Solution.h"

int findMaxSum(int * array, int N, int& start, int& end)
{
	start = 0;
	end = 0;
	int maxSum = -1;
	int tempSum = 0;
	int tempStart = 0;

	for (int i = 0; i < N; i++)
	{
		tempSum += array[i];
		if (tempSum > maxSum)
		{
			maxSum = tempSum;
			start = tempStart;
			end = i;
		}

		if (tempSum < 0)
		{
			tempSum = 0;
			tempStart = i + 1;
		}
	}
	
	return maxSum;
}