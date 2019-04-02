// Source file for the String_list class

#include "String_list.h"

using namespace std;

// Constructor for initializing a String_list from another String_list
String_list::String_list(const String_list& src)
{
    *this = src;
    l = new string[max];

    for(size_t i = 0; i < size; ++i)
        l[i] = src.l[i];

}

//don't know what the tilde means 
// -presumably clear the String_list / class generally?
String_list::~String_list()
{
    delete[] l;
}

// Doesn't this leave the String_list contents unchanged,
// except there are now a load of empty positions at the end?
// I suppose, if that's what you want. . .
void String_list::resize()
{
    max *= 2;

    string* copy = new string[max];

    for (size_t i = 0; i != size; ++i)
        copy[i] = l[i];
    
    delete[] l;

    l = copy;

}

void String_list::push_back(string str)
{
    if(size == max)
        resize();   //thus doubling the number of free positions
    
    l[size++] = str;
}