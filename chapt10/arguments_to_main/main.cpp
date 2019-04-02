// this program takes two strings as arguments and then 
// writes them to the standard output stream

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // if there are arguments write them
    if(argc > 1) {
        int i;
        for (i = 1; i < argc - 1; ++i)
            cout << argv[i] << " ";
        
        cout << argv[i] << endl;
    }

    return 0;
}