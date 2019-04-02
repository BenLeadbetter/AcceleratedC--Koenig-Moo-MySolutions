#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream in("main.cpp");
    
    if(!in)
        cerr << "Could not open file\n";
    
    string line;
    while(getline(in, line))
        cout << line << endl;
    
    in.close();
    
    return 0;
}