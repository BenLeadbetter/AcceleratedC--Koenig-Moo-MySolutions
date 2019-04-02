#include <iostream>
#include <algorithm>
#include "Vec.h"

using namespace std;

int main()
{
    Vec<int> test_vec(10, 9);

    Vec<int> other_vec = test_vec;

    for(Vec<int>::size_type i = 0; i != other_vec.size(); ++i)
    {
        other_vec[i] += i;
    }

    for(Vec<int>::size_type i = 0; i != other_vec.size(); ++i)
        cout << other_vec[i] << endl;
 
    other_vec.erase(other_vec.begin() + 3, other_vec.begin() + 6);

    for(Vec<int>::size_type i = 0; i != other_vec.size(); ++i)
        cout << other_vec[i] << endl;

    other_vec.clear();

    for(Vec<int>::size_type i = 0; i != other_vec.size(); ++i)
        cout << other_vec[i] << endl;

    cout << other_vec.size() << endl;

    copy(test_vec.begin(), test_vec.begin() + 5, back_inserter(other_vec));

    for(Vec<int>::size_type i = 0; i != other_vec.size(); ++i)
        cout << other_vec[i] << endl;

    return 0;
}