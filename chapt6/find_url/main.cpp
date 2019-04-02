//program finds and extracts url links from a document
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// This boolean function will check whether or not
// a character is a possible url character.
bool not_url_char(char c)
{
    // Define a static string containing all the 
    // possible charracters which could be url char.s
    // in addition to the standard alphanumeric ones
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // See whether c could appear in a url and return the negative
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

// This function will find the beginning of a url
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks where the seperator was found
    iter i = b;

    while((i = search(i, e, sep.begin(), sep.end())) != e)
    {
        // Make sure the seperator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e)
        {

            //beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalnum(beg[-1]))
                --beg;
            
            // Is there at least one appropriate char. 
            // before and after the seperator
            if (beg != i && !not_url_char(beg[sep.size()]))
                return beg;
        }

        // otherwise, the seperator was not part of a url
        // advance i beyond the seperator
        i += sep.size();
    }

    return e;
}

// This function will find the end of a url
// given an iterator positioned at the start
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

// This function returns a vector containing
// all the URL links found in a given string
vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // Look through the entire input
    while(b != e)
    {
        // First we look for one or more letters followed by ://
        b = url_beg(b, e);

        // If we found it...
        if (b != e)
        {
            // we get the rest of the url
            iter after = url_end(b, e);

            // Record the url
            ret.push_back(string(b, after));

            // Advance b and check for further urls
            b = after;
        }
    }
    return ret;

}



int main()
{
    // First we load an example text file
    // into one, long string
    ifstream i_file;
    i_file.open("watchmen_as_historiographic_novel.txt");

    // Check that the file opened correctly
    if (!i_file)
    {
        cerr << "Could not open file: watchmen_as_historiographic_novel.txt";
        return 1;
    }

    // Write file into one, long string
    // the sting 'text' will contain the text to be analysed 
    string str;
    string text;
    while(getline(i_file, str))
    {
        text = text + str;
    }

    // Close the file when we're done
    i_file.close();    

    vector<string> url_links = find_urls(text);

    for(vector<string>::const_iterator i = url_links.begin(); i != url_links.end(); ++i)
        cout << *i << endl;
        

    return 0;
}