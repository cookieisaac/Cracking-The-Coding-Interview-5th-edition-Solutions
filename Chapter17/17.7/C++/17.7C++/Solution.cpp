#include "Solution.h"
#include <sstream>
using namespace std;


string readInDigit(int N)
{
	string name;

	switch (N)
	{
		case 1: name = "One"; break;
		case 2: name = "Two"; break;
		case 3: name = "Three"; break;
		case 4: name = "Four"; break;
		case 5: name = "Five"; break;
		case 6: name = "Six"; break;
		case 7: name = "Seven"; break;
		case 8: name = "Eight"; break;
		case 9: name = "Nine"; break;
	}

	return name;
}

string readInTenth(int N)
{
	string name;

	if (N / 10 == 0)
		name += readInDigit(N);
	else if (N / 10 == 1)
	{
		switch (N % 10)
		{
			case 0: name = "Ten"; break;
			case 1: name = "Eleven"; break;
			case 2: name = "Twelve"; break;
			case 3: name = "Thirteen"; break;
			case 4: name = "Fourteen"; break;
			case 5: name = "Fifteen"; break;
			case 6: name = "Sixteen"; break;
			case 7: name = "Seventeen"; break;
			case 8: name = "Eighteen"; break;
			case 9: name = "Nineteen"; break;
		}
	}
	else
	{
		switch (N / 10)
		{
			case 2: name = "Twenty"; break;
			case 3: name = "Thirty"; break;
			case 4: name = "Forty"; break;
			case 5: name = "Fifty"; break;
			case 6: name = "Sixty"; break;
			case 7: name = "Seventy"; break;
			case 8: name = "Eighty"; break;
			case 9: name = "Ninety"; break;
		}

		if (N % 10 == 0)
			return name;
		else
			name += "-" + readInDigit(N % 10);
	}
	return name;
}


/* 0 < N <= 999 */
string readInHundreds(int N)
{
	string name;

	if (N / 100 > 0)
	{
		name += readInDigit(N / 100) + " Hundred";
		if (N % 100 == 0)
			return name;
		else
		{
			name += " and " + readInTenth(N % 100);
		}
	}
	else
		name += readInTenth(N);

	return name;
}

string readInteger(int N)
{
	string name = "";

	if (N == 0)
		return "Zero";
	else if (N < 0)
	{
		name += "Negative ";
		N *= -1;
	}

	if (N / 1000000000 > 0)
	{
		name += readInHundreds(N / 1000000000) + " Billion";
		if (N % 1000000000 == 0)
			return name;
		else
		{
			name += ", ";
			N = N % 1000000000;
		}
	}

	if (N / 1000000 > 0)
	{
		name += readInHundreds(N / 1000000) + " Million";
		if (N % 1000000 == 0)
			return name;
		else
		{
			name += ", ";
			N = N % 1000000;
		}
	}

	if (N / 1000 > 0)
	{
		name += readInHundreds(N / 1000) + " Thousand";
		if (N % 1000 == 0)
			return name;
		else
		{
			name += ", ";
			N = N % 1000;
		}
	}

	name += readInHundreds(N);

	return name;
}