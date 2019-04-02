// Here we test our new String_list class

#include <iostream>
#include "String_list.h" 

using namespace std;

int main()
{
    String_list str_list;

    str_list.push_back("test");
    str_list.push_back("some");
    str_list.push_back("strings");
    str_list.push_back("bumbaclaat");

    String_list::iterator iter = str_list.begin();

    while (iter != str_list.end())
        cout << *iter++ << endl;

    return 0;
}
