// An alternative implementation of the find_if algorithm
// this one is better than defining bool p(const T&) because
// it may work with non-boolean functions, if they happend to fit?


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class In, class Pred>
In find_if_bl(In begin, In end, Pred f)
{
    while (begin != end && !f(*begin))
        ++begin;
    
    return begin;
}


// Boolean tests whether a number is a square number

template<class T>
bool is_square(T n)
{
    double root = sqrt(n);
    double root_tail = root - floor(root);
    return root_tail == 0.0;
}

/*

// same as above but defined for int, not template
bool is_square(int n)
{
    double root = sqrt(n);
    double root_tail = root - floor(root);
    return root_tail == 0.0;
}
*/

bool aux_is_square(const int& n)
{
    return is_square(n);
}

int main()
{
    vector<int> test_vec;
    for (int i = 2; i != 10; ++i)
        test_vec.push_back(i);
    
    cout << *find_if_bl(test_vec.begin(), test_vec.end(), is_square<int>) << endl;

    return 0;
}