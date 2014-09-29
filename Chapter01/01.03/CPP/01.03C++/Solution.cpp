#include "Solution.h"

#include <algorithm>
bool isPermutation(std::string strA, std::string strB)
{
	if (strA.length() != strB.length())
		return false;
	
	std::sort(strA.begin(), strA.end());
	std::sort(strB.begin(), strB.end());

	if (strA == strB)
		return true;
	else
		return false;
}