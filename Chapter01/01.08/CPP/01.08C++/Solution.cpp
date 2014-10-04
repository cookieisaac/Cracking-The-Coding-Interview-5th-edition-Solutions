#include "Solution.h"

bool isSubstiring(std::string strA, std::string strB)
{
	std::size_t found = strA.find(strB);
	if (found != std::string::npos)
		return true;
	else
		return false;
}

bool isRotation(std::string strA, std::string strB)
{
	return isSubstiring(strB + strB, strA);
}


