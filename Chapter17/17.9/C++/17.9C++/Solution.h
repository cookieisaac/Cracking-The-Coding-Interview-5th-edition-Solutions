#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <map>
#include <string>
#include <fstream>

std::string lowerString(std::string word);

class WordCount
{
public:
	WordCount();
	WordCount(std::string fileName);

	void setFile(std::string file);
	int getWordOccurence(std::string word);

	~WordCount();

private:
	std::string m_fileName;
	std::map<std::string, int> m_dictionary;
	void buildDictionary();
};


#endif