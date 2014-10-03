#include "Solution.h"
#include <algorithm>

void replaceAllSpace(std::string& str)
{
	size_t start_pos = 0;
	std::string space = " ";
	std::string newSpace = "%20";

	while ((start_pos = str.find(space, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, space.length(), newSpace);
	}
}