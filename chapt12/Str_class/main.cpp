#include "Str.hpp"
#include <iostream>

using namespace std;

int main()
{
    Str s("This is a string");

    Str t = s;

    s[3] = 'x';
    s[5] = 'x';
    s[7] = 'x';
    s[9] = 'x';

    cout << s + t << endl;

    return 0;
}