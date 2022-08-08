#ifndef SYMBOLFREQ_H
#define SYMBOLFREQ_H

#include <map>
#include <fstream>
#include <iostream>
using namespace std;

class SymbolFreq
{
public:
	SymbolFreq();
	~SymbolFreq();
	void searchFile(string);
	void addChar(char);
	void print();

protected:
	double charCount; //doubles used to enable large number of characters read
	map<char, double>* chars;
};




















#endif // SYMBOLFREQ.H

