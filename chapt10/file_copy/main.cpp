#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    int fail_count = 0;
    for (int i = 1; i != argc; ++i)
    {
        ifstream in(argv[i]);

        // if the stream opens, write the file to the st'd output
        if (in)
        {
            string line;
            while(getline(in, line))
                cout << line << endl;
        
        // otherwise write a message onto the error stream
        } else {
            cerr << "cannot open file " << argv[i] << endl;
            ++fail_count;
        }
    }

    return fail_count;
}