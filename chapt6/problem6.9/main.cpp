// This is problem 6.3 from the Accelerated c++ textbook

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    // Read words from the user and push them onto a vector of strings
    vector<string> words;
    string str;
    cout << "Enter some words:" << endl;
    while (cin >> str)
        words.push_back(str);
    
    // Here I'm attampting to concatenate the strings in words using the accumulate 
    // algorithm (in <numeric>)
    string initial_string = "";
    string concatenated_words = accumulate(words.begin(), words.end(), initial_string);


    // And it works!
    cout << concatenated_words << endl;

    return 0;
}