#include "Solution.h"
#include <sstream>
using namespace std;


// ss << currChar << charCount;
// ss >> compress;
/*The method above will leave out space characters and tabs
========================================
Original string: "space        "
Compressed string: "s1p1a1c1e1"
========================================
The expected result should be "s1p1a1c1e1 8".
*/


std::string compressString(std::string str)
{
	// Size of ompressed string is larger than 2, "a" ==> "a1"
	if (str.length() < 2)
	{
		return str;
	}

	stringstream ss;
	string compress = "";
	char currChar, lastChar = str[0];
	int charCount = 1;
	for (size_t pos = 1; pos < str.length(); pos++)
	{
		currChar = str[pos];
		if (currChar == lastChar)
		{
			charCount++;
			lastChar = currChar;
		}
		else
		{
			compress.append(string(1, lastChar));
			compress.append(to_string(charCount));
			lastChar = currChar;
			charCount = 1;
		}
	}

	// to_string will cast char as integer, string stream will ignore space, so we have to use string constructor
	compress.append(string(1, lastChar));
	compress.append(to_string(charCount));

	if (compress.length() > str.length())
	{
		return str;
	}

	return compress;
}