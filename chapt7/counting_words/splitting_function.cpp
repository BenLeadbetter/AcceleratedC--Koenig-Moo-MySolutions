// source file for the splitting_function.h header

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 

using namespace std;

bool space(char c)
{
	return isspace(c);
}
bool notspace(char c)
{
	return !isspace(c);
}
bool alphabet(char c)
{
	return isalpha(c);
}
bool notalphabet(char c)
{
	return !isalpha(c);
}

vector<string> split(const string& str)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter i = str.begin();
	
	while(i != str.end())
	{
		//ignore leading blanks
		i = find_if(i, str.end(), notspace);
		
		//find end of the word, if any
		iter j = find_if(i, str.end(), space);
		
		//add word onto the end of the vector
		if(i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

vector<string> word_split(const string& str)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter i = str.begin();
	
	while(i != str.end())
	{
		//ignore leading non-alphabetic characters
		i = find_if(i, str.end(), alphabet);
		
		//find end of the word, if any
		iter j = find_if(i, str.end(), notalphabet);
		
		//add word onto the end of the vector
		if(i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}



