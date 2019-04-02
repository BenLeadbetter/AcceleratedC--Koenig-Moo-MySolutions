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



