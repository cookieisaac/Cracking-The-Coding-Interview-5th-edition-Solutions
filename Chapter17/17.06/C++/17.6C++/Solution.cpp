#include "Solution.h"

// Return the min value of array[start, end]
int getArrayMin(int* array, int start, int end)
{
	int min = array[start];

	for (int i = start; i <= end; i++)
		if (min > array[i])
			min = array[i];
	return min;
}

// Return the max value of array[start, end]
int getArrayMax(int* array, int start, int end)
{
	int max = array[start];

	for (int i = start; i <= end; i++)
		if (max < array[i])
			max = array[i];

	return max;
}

/*
Returns (start, end) denoting that array[start, end] needs to be ordered.
If the array is orderly assending, returns (-1, -1)
If the array is oderly descending, returns (0, N-1)
Array of size is considered as orderly ascending.
*/
void findUnordered(int* array, int N, int& start, int& end)
{
	start = 0;
	end = N - 1;

	/*
	Step 0: Pre-execution analysis:
	Array of size 1 is considered ordered all the time
	Array of size 2 is considered ordered if ascending, unordered if descending
	*/
	if (N == 1)
	{
		start = -1; end = -1; return;
	}
	else if (N == 2 && array[0] > array[1])
	{
		start = 0; end = 1; return;
	}
	else if (N == 2)
	{
		start = -1; end = -1; return;
	}

	/* Step 1: partition the array into three array
	// Left (Ordered): [0, start - 1]
	// Middle (Unordered or Ordered): [start, end];
	// Right (Ordered): [end + 1, N - 1] 
	Note we might to minimize the unodrdered list Middle as much as possible, so we use >= and <=
	*/
	for (start = 1, end = N - 2; start < end;)
	{
		if (array[start] >= array[start-1])
			start++;
		else if (array[end] <= array[end + 1])
			end--;
		else
			break;
	}

	/* Step 2: Shrink Left and Right so that 
	min(Middle) >= max(Left) && max(Middle ) =< min(Right)
	*/
	while (start > 0 || end < N-1 ) //Middle is at most [0, N-1]
	{
		if (start > 0 && getArrayMin(array, start, end) < getArrayMax(array, 0, start - 1))
			start--;
		else if (end < N - 1 && getArrayMax(array, start, end) > getArrayMin(array, end + 1, N - 1))
			end++;
		else
			break;
	}

	/* Step 3: Post-result analysis
		if start equals end, then the whole array is ordered 
		if start and end differ by 1, and two values are equal, then the whole array is also ordered
	*/
	if ( end - start == 0)
	{
		start = -1;
		end = -1;
		return;
	}
	else if (end - start == 1 && array[start] == array[end])
	{
		start = -1;
		end = -1;
		return;
	}
}

