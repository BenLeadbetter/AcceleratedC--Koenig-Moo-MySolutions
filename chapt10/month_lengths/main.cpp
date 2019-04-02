#include <iostream>

using namespace std;

const int month_lengths[] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

/*
// This didn't work:

size_t arr_size(const int* arr)
{
    size_t length = sizeof(arr) / sizeof(*arr);

    return length;
}
*/

int main()
{
    cout << *(month_lengths + 5) << endl;
    cout << endl;

    for(size_t i = 0; i != 12; ++i)
        cout << month_lengths[i] << endl;


    return 0;
}