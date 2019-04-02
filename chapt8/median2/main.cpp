// Rewriting the median function in generic form

#include <iostream>
#include <cmath>
#include <vector>
#include "iter_median.h"

using namespace std;



int main()
{
    // Create some vectors with interesting numbers for testing
    vector<float>   float_vec;
    vector<int>     int_vec;
    for(float i = 1.0; i != 9; ++i)
        float_vec.push_back(pow(i-3, 2) / 5);
    for(int i = 1; i != 9; ++i)
        int_vec.push_back(pow(i - 4, 3) - 2 * pow(i, 2) + 8 * i);

    
    // Read out the content of each vector before we begin
    cout << "float_vec" << "\t" << "int_vec" << endl;
    vector<float>::const_iterator fit = float_vec.begin();
    vector<int>::const_iterator iit = int_vec.begin();
    while(fit != float_vec.end() && iit != int_vec.end())
    {
        cout << *fit << "\t\t" << *iit << endl;
        ++fit;
        ++iit;
    }
    cout << endl;

    // Output the sorted vetors' contents
    sort(float_vec.begin(), float_vec.end());
    sort(int_vec.begin(), int_vec.end());
    cout << "sorted vectors" << endl;
    cout << "float_vec" << "\t" << "int_vec" << endl;
    fit = float_vec.begin();
    iit = int_vec.begin();
    while(fit != float_vec.end() && iit != int_vec.end())
    {
        cout << *fit << "\t\t" << *iit << endl;
        ++fit;
        ++iit;
    }
    cout << endl;
    

    // Now output the median of each
    cout << "medians" << endl;
    cout << "float_vec" << "\t" << "int_vec" << endl;
    cout << median(float_vec.begin(), float_vec.end()) << "\t\t" << median(int_vec.begin(), int_vec.end()) << endl;



    return 0;
}