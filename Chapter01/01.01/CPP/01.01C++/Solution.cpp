#include "Solution.h"
#include <string>
#include <map>
using namespace std;

bool isUnique(std::string testString)
{
	map<char, int> charTable;

	for (string::iterator it = testString.begin(); it != testString.end(); ++it)
	{
		if (charTable[*it] > 0)
			return false;
		else
			charTable[*it]++;
	}
	return true;
}