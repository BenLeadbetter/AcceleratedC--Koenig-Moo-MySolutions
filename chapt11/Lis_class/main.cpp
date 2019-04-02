#include "Lis.h"
#include <iostream>

using namespace std;

int main()
{
    Lis<double> test_lis;

    for (int i = 1; i != 20; ++i)
        test_lis.push_back(1.0 / i);
    
    for(Lis<double>::const_iterator itr = test_lis.begin(); itr != test_lis.end(); ++itr)
        cout << *itr << endl;


    return 0;
}