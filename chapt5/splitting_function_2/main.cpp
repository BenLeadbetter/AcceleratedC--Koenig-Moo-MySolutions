//another splitting function using iterators

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

int main()
{
	//read a line of words from the user
	string unsplit_line;
	getline(cin, unsplit_line);
	
	//split the line into a new vector
	vector<string> word_vec = split(unsplit_line);
	
	//check that the split was successful by printing each element
	for(vector<string>::const_iterator i = word_vec.begin(); i != word_vec.end(); ++i)
		cout << *i << endl;
	
	return 0;
}


