#include <iostream>

using namespace std;

int main()
{
    string str1 = "comparison_string";
    cout << "str1 = " << str1 << endl;

    string str2 = "comparison_string";
    cout << "str2 = " << str2 << endl;
    
    
    if (str1 == str2)
        cout << "The two strings are the same.\n";
    else
        cout << "The two strings are not the same.\n";
    cout << endl;

    char char_arr1[] = {'c', 'o', 'm', 'p', 'a', 'r', 'i', 's',
                        'o', 'n', '_', 's', 't', 'r', 'i', 'n', 'g', '\0'};
    
    if (str1 == char_arr1)
        cout << "The two strings are the same.\n";
    else
        cout << "The two strings are not the same.\n";
    cout << endl;

    // Given that the string-literals are in fact arrays of char variables
    // their return type should be a pointer to their first element.
    // I.e. the address for where the first element of data is stored

    // Does this mean that all these strings are in fact stored in the same place?
    // perhaps some function of the sompiler in order to save memory?

    // At any rate, these comparisons sometimes fail (when comparing string pointers
    // from arguments to the main function)

    return 0;
}