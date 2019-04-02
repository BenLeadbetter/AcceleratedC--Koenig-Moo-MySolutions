#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::cin;

int main()
{
	
	for(int i = 0; i != 20; i++)
	{
		string asterisk_string_i (i, '*');
		
		cout << asterisk_string_i << setw(20) << "****9****" << endl;
	}
	
	return 0;
}
