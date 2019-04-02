// This is problem 6.3 from the Accelerated c++ textbook

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << endl;
    }

    cout << v.size() << endl;


    return 0;
}