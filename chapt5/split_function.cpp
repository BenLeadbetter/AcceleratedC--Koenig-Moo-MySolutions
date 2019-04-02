#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using std::cout;		using std::endl;
using std::vector;		using std::string;
using std::isspace;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	
	//invariant: we have processed characters [original value of i, i)
	while(i != s.size())
	{
		//ignore leading blanks
		//invariant characters [original i,current i) are all spaces
		while(i != s.size() && isspace(s[i]))
			++i;
		
		//find end of next word
		string_size j = i;
		//invariantL non of the characters in range [i, j) are spaces
		while(j != s.size() && !isspace(s[j]))
			++j;
		
		//push_back word if we found any non white spaces
		if (i != j)
		{
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}

int main()
{
	string string_of_words = "Alfred Lord Tennison lived only    on venison. Not  cheap, I fear, beacause  venison is deer";
	vector<string> s = split(string_of_words);
	cout << s.size() << endl;
	for(vector<string>::size_type i = 0; i != s.size(); ++i)
		cout << s[i] << endl;
	
	
	return 0;
}

