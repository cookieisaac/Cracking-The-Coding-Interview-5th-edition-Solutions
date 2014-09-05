#include "Solution.h"
#include <iostream>
#include <sstream>
#include <cctype> //tolower
#include <algorithm> //transform

std::string lowerString(std::string word)
{
	std::string lower=word;
	std::transform(word.begin(), word.end(), lower.begin(), std::tolower);

	return lower;
}

WordCount::WordCount(std::string fileName)
{
	m_fileName = fileName;
	buildDictionary();
};

void WordCount::setFile(std::string fileName)
{
	m_fileName = fileName;
}

void WordCount::buildDictionary()
{
	std::ifstream fileToBuild(m_fileName);
	if (!fileToBuild)
	{
		std::cout << "Please assoaciate a file with current class! " << std::endl;
	}
	else
	{
		while (!fileToBuild.eof())
		{
			//Read line by line
			std::string line;
			getline(fileToBuild, line);

			//For each line, count word by word
			const char delim = ' ';
			std::string word;
			std::istringstream lineStream(line);
			while (getline(lineStream, word, delim))
			{
				m_dictionary[lowerString(word)]++;
			}
		}
	}
}

int WordCount::getWordOccurence(std::string word)
{
	return m_dictionary[word];
}

WordCount::~WordCount()
{

}

