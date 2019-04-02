// This program will count the number of occurances of each distinct 'word'
// in a given input

#include <iostream>
#include <cctype>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "splitting_function.h"

using namespace std;

char to_lower_case(char c)
{
    return tolower(c);
}

bool ordering(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    string s;
    map<string, int> counters;

    // open the text file
    ifstream file_stream;
    file_stream.open("./no_more_heroes.txt");

    // read the input, keeping track of each word and how often we see it
    while(getline(file_stream, s))
    {
        vector<string> words_in_line = word_split(s);
        for(vector<string>::const_iterator i = words_in_line.begin(); i != words_in_line.end(); ++i)
        {
            string word;
            transform((*i).begin(), (*i).end(), back_inserter(word), to_lower_case);
            ++counters[word];
        }
    }

    // close the file stream
    file_stream.close();

    // Write the map into a vector of pairs
    // This is to allow us to write the output in order
    vector<pair<string, int> > counters_vec;
    for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
        counters_vec.push_back(*it);
    
    // Sort the vector according to the value of the seconds
    sort(counters_vec.begin(), counters_vec.end(), ordering);

    // write the words and the ascosiated counters
    for(vector<pair<string, int> >::const_iterator it = counters_vec.begin(); 
        it != counters_vec.end(); ++it)
        cout << (*it).first << "\t" << (*it).second << endl;


    return 0;
}