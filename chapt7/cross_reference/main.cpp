// This program will count the number of occurances of each distinct 'word'
// in a given input

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "splitting_function.h"

using namespace std;

map<string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // Read the next line
    while (getline(in, line))
    {
        ++line_number;

        // Break the input up
        vector<string> words = find_words(line);

        // Remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
            ret[*it].push_back(line_number);
        
    }

    return ret;
}

int main ()
{
    // Open a file stream to a file to cross-reference
    ifstream file_stream;
    file_stream.open("no_more_heroes.txt");

    // Create cross-reference map
    map<string, vector<int> > file_xref = xref(file_stream, word_split);
    file_stream.close();

    // Write the results to the console
    for(map<string, vector<int> >::const_iterator it = file_xref.begin(); it != file_xref.end(); ++it)
    {
        // Write the word
        cout << it->first << " occurs on line(s): ";

        // Followed by one or more line numbers
        // Write the first line number
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;
        ++line_it;
        // Now write the rest (if any)
        while(line_it != it->second.end())
        {
            cout << ", " << *line_it;
            ++line_it;
        }
        // Write a new line to seperate each word
        cout << endl;
    }

    return 0;
}