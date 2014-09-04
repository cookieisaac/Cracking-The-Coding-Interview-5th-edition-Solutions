#ifndef _SOLUTION_H
#define _SOLUTION_H

/*
Input
@ array - integer array;
@ N - size of array;

Output
@ start - starting index of max sum array;
@ end - ending index of max sum array;

Note:
1. At least one of the element in array should be none-negative
2. This is a O(N) solution
*/
int findMaxSum(int * array, int N, int& start, int& end);

#endif