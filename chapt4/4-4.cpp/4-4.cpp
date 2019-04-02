#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::string;

istream& read_words(istream& input_stream, string& word)
{
	input_stream >> word;

	return input_stream;
};


int main()
{
	string first_word;
	
	read_words(cin, first_word);
	
	cout << first_word << endl;
	
	
	return 0;
}
