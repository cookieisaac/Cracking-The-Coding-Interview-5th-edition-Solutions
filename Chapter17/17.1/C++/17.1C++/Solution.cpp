#include "Solution.h"

void swap(int& A, int& B)
{
	A = A^B;
	B = A^B;
	A = A^B;
}