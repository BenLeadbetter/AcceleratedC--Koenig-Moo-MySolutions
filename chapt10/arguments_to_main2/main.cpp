// this program takes two strings as arguments and then 
// writes them to the standard output stream

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    // if the argument matches the right value, respond in turn
    if(argc > 1) {
        if(strcmp(argv[1], "insult") == 0)
            cout << "You're a fat bastard.\n";
        else
            cout << "You're alright!\n";
    }

    return 0;
}