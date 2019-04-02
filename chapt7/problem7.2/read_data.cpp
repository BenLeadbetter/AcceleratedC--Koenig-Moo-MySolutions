//source file for read_data.h

#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

ifstream& read_data(ifstream& i_file, vector<string>& vec)
{
	string str;
	
	while(getline(i_file, str))
		vec.push_back(str);
	
	return i_file;
}

ifstream& read_data(ifstream& i_file, list<string>& ls)
{
	string str;
	
	while(getline(i_file, str))
		ls.push_back(str);
		
	return i_file;
}

