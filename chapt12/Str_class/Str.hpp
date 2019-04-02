
#ifndef GUARD__STR
#define GUARD__STR

// Header file for the Str class

#include "Vec.h"
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>

class Str
{
    friend std::istream& operator>>(std::istream&, Str&);

    public:
    
        typedef char* iterator;
        typedef const char* const const_iterator;
        typedef char value_type;
        typedef Vec<char>::size_type size_type;
        
        // various constructors
        Str() { }
        Str(size_type n, char c): data(n, c) { }
        Str(const char* cp) 
        {
            std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
        }
        
        template<class In>
        Str(In b, In e)
        {
            std::copy(b, e, std::back_inserter(data));
        }

        // operators
        char& operator[](size_type i) { return data[i]; }
        const char& operator[] (size_type i) const { return data[i]; }
        Str& operator+=(const Str& s)
        {
            std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
            return *this;
        }


        // other interface functions
        size_type size() const { return data.size(); }

    private:

        Vec<char> data;
};

Str operator+(const Str& s, const Str& t)
{
    Str r = s;
    r += t;
    return r;
}

// input output operators
std::istream& operator>>(std::istream& is, Str& s)
{
    // obliterate the existing value
    s.data.clear();

    // read and discard leading whitespace
    char c;
    while (is.get(c) && isspace(c))
        ;
    // if there's stil something to read, do so until next whitespace
    if (is)
    {
        do s.data.push_back(c);
        while (is.get(c) && !isspace(c));

        // if we read white space, put it back onto the stream
        if(is)
            is.unget();
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for(Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}



#endif