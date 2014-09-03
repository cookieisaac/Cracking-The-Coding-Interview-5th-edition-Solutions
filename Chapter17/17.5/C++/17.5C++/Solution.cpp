#include "Solution.h"
#include  <string>
#include <map>
using namespace std;


int min(int a, int b)
{
	return (a < b) ? a : b ;
}

void checkGuess(string target, string guess, int& hit, int& psuedoHit)
{
	hit = 0;
	psuedoHit = 0;

	map <char, int> targetColorBucket;
	map <char, int> guessColorBucket;
	map <char, int> hitColorBucket;

	for (string::size_type i = 0; i < target.length(); i++)
	{
		if (target[i] == guess[i])
		{
			hitColorBucket[target[i]]++;
		}
		targetColorBucket[target[i]]++;
		guessColorBucket[guess[i]]++;
		
	}

	for (map<char, int>::iterator ii = targetColorBucket.begin(); ii != targetColorBucket.end(); ++ii)
	{
		char color = (*ii).first;

		hit += hitColorBucket[color];
		psuedoHit += min(targetColorBucket[color], guessColorBucket[color]) - hitColorBucket[color];
	}
}
