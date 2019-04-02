#include <iostream>

using namespace std;

int main()
{
    int x = 5;

    // Pointer p points to x
    int* p = &x;
    cout << "x = " << x << endl;

    // Change the value of x through p
    *p = 6;
    cout << "x = " << x << endl;

    return 0;
}