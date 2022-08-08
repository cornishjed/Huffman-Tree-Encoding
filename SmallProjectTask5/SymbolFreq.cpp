#include "SymbolFreq.h"

SymbolFreq::SymbolFreq()
{
	chars = new map<char, double>;
	charCount = 0;
}

SymbolFreq::~SymbolFreq()
{
	delete chars;
}

void SymbolFreq::searchFile(string n)
{
	char currentLetter;

	fstream fileIn(n, fstream::in);

	map<char, double>::iterator it;

	while (fileIn >> noskipws >> currentLetter) {
		for (it = chars->begin(); it != chars->end(); it++) {
			if (it->first == currentLetter) {
				it->second++;
				charCount++;
				break;
			}
		}
		if (it == chars->end()) {
			addChar(currentLetter);
			charCount++;
		}
	}
}

void SymbolFreq::addChar(char cl)
{
	chars->insert(pair<char, double>(cl, 1));
}

void SymbolFreq::print()
{
	map<char, double>::iterator it;

	for (double i = charCount; i > 0; i--) {
		for (it = chars->begin(); it != chars->end(); it++) {
			if (it->second == i) {
				cout << it->first << " :: " << it->second << endl;
			}
		}
	}
}