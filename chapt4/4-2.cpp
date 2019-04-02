#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

using std::log10;
using std::cout;
using std::endl;
using std::setw;
using std::cin;
using std::floor;


int main()
{
	int upper_limit;
	
	//Read a user defined integer to determine how far to list the squares
	cin >> upper_limit;
	cout << endl;
	
	//determine the necessary maximum width of the first collumn
	int column_width = floor(log10(upper_limit * upper_limit)) + 5;
	
	cout << column_width << endl;
	cout << endl;
	
	
	for(int i = 1; i != upper_limit + 1; ++i)
	{
		cout << i << setw(column_width) << i*i << endl;
	}
	
	return 0;
}
