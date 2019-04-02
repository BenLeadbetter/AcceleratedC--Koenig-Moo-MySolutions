#include <iostream>

using namespace std;

template<class T>
T max_ben(const T& left, const T& right)
{
    return left > right ? left : right;
}

int main()
{
    cout << max_ben(3, 5) << endl;
    string sb = "ben";
    string st = "tashi";
    cout << max_ben(sb, st) << endl;
    cout << max_ben(10.9, 30.46);


    return 0;
}