#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include "splitting_function.h"

using namespace std;

// Define the types that we will use
typedef vector<string> Rule;
typedef vector<Rule>    Rule_collection;
typedef map<string, Rule_collection> Grammar;

// This function will read a grammar file from an input stream
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // Read the input
    while(getline(in, line))
    {
        // split the input into words
        vector<string> entry = split(line);
        if(!entry.empty())
            // Use the catagory to store the associated rule
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}



bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// Return a random integer from the interval [0, n)
int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);
    
    return r;
}
// *****Here we change this into a template**********
void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if(!bracketed(word))
        ret.push_back(word);
    else {
        // Locate the rule which corresponds to word
        Grammar::const_iterator it = g.find(word);
        if(it == g.end())
            throw logic_error("empty rule");
        
        //fetch the set of possible rules
        const Rule_collection& c = it->second;

        // From which we select one at random
        const Rule& r = c[nrand(c.size())];

        // Recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

// This function will generate a sentence
vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

int main()
{
    
    
    
    // Open a file stream to read the grammar file
    ifstream file_stream;
    file_stream.open("./grammer_from_book.txt");
    
    // Read the grammar file
    Grammar grammar = read_grammar(file_stream);

    // Close the file stream
    file_stream.close();

    // Generate the sentence
    vector<string> sentence = gen_sentence(grammar);

    //Write the first word, if any
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty())
    {
        cout << *it;
        ++it;
    }

    // Write the rest of the words, each preceded by a sopace
    while(it != sentence.end())
    {
        cout << " " << *it;
        ++it;
    }

    // Finish the sentence by ending the line
    cout << endl;

    for(int i = 1; i != 20; ++i)
        cout << nrand(5) << endl;

    return 0;
}