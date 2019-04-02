#ifndef GUARD_splitting_function_h
#define GUARD_splitting_function_h

#include <vector>
#include <string>
#include <algorithm>

bool space(char);
bool notspace(char);
bool is_comma_space(char);
bool is_not_comma_space(char);

template<class Out>
void split(const std::string& str, Out os)
{
	typedef std::string::const_iterator iter;
	iter i = str.begin();
	
	while(i != str.end())
	{
		//ignore leading blanks
		i = find_if(i, str.end(), notspace);
		
		//find end of the word, if any
		iter j = find_if(i, str.end(), space);
		
		//add word onto the end of the vector
		if(i != str.end())
			*os++ = std::string(i, j);
		i = j;
	}
}

template<class Out>
void word_split(const std::string& str, Out os)
{
	typedef std::string::const_iterator iter;
	iter i = str.begin();
	
	while(i != str.end())
	{
		//ignore leading punct spaces
		i = find_if(i, str.end(), is_not_comma_space);
		
		//find end of the word, if any
		iter j = find_if(i, str.end(), is_comma_space);
		
		//add word onto the end of the vector
		if(i != str.end())
			*os++ = std::string(i, j);
		i = j;
	}
}

#endif