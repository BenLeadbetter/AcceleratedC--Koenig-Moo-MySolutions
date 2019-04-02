
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Equal algrithm - works!
template<class In>
bool equal_bl(In beg, In end, In alt_beg)
{
    while(beg != end)
        if(*beg != *alt_beg)
            return false;
        else{
            ++beg;
            ++alt_beg;
        }
    
    return true;
}

// Find algorithm - defined recursively
template<class In, class X>
In find_bl(In beg, In end, const X& x)
{
    if (beg == end || *beg == x)
        return beg;
    else
        ++beg;
    
    return find_bl(beg, end, x);
}


// find_if algorithm
template<class In, class X>
In find_if_bl(In beg, In end, bool p(const X&))
{
    if (beg == end || p(*beg))
        return beg;
    else
        ++beg;
    
    return find_if_bl(beg, end, p);
}

// Search algorithm
template<class In>
In search_bl(In beg1, In end1, In beg2, In end2)
{   
    while(beg1 != end1)
    {
        // Advance beg1 until we find the start of the required sequence
        while(*beg1 != *beg2)
            ++beg1;
        
        
        // If we're not yet at the end of search range
        if(beg1 != end1)
        {
            // Check whether we've found the required sequence
            if(equal_bl(beg2, end2, beg1))
                return beg1;
        }

        ++beg1;
    }

    return beg1;
}


// Copy algorithm
template<class In, class Out>
Out copy_bl(In beg, In end, Out des)
{
    while(beg != end)
        *des++ = *beg++;

    return des;    
}

// Remove_copy algorithm
template<class In, class Out, class X>
Out remove_copy_bl(In beg, In end, Out des, const X& x)
{
    while(beg != end)
        if(!(*beg == x))
            *des++ = *beg++;
        else
            ++beg;
    
    return des;
}

// Remove_copy_if algorithm
template<class In, class Out, class X>
Out remove_copy_if_bl(In beg, In end, Out des, bool p(const X&))
{
    while(beg != end)
        if(!p(*beg))
            *des++ = *beg++;
        else
            ++beg;
    
    return des;
}
// swap algorithm
template<class In>
void swap_bl(In it1, In it2)
{
    swap(*it1, *it2);
}

// Remove algorithm
template<class In, class X>
In remove_bl(In beg, In end, const X& x)
{
    In aux_itr = beg;

    while(aux_itr != end)
    {
        // advance beg to the next removable term
        while(*beg != x && beg != end)
            ++beg;
        
        // Advance an auxilery iterator to the next includable
        aux_itr = beg;
        while(*aux_itr == x)
            ++aux_itr;
        
        // Swap the values if aux_itr hasn't reached the end
        if(aux_itr != end)
            swap_bl(beg, aux_itr);

        ++beg;
    }
    return beg;
}

// Remove_if algorithm
template<class In, class X>
In remove_if_bl(In beg, In end, bool p(const X&))
{
    In aux_itr = beg;

    while(aux_itr != end)
    {
        // advance beg to the next removable term
        while(!p(*beg) && beg != end)
            ++beg;
        
        // Advance an auxilery iterator to the next includable
        aux_itr = beg;
        while(p(*aux_itr))
            ++aux_itr;
        
        // Swap the values if aux_itr hasn't reached the end
        if(aux_itr != end)
            swap_bl(beg, aux_itr);

        ++beg;
    }
    return beg;
}

// Some arbitrary predicate for testing the algorithms
bool aux_checker(const int& i)
{
    return (i != 0 && i % 3 == 0);
}

int main()
{
    // Create a vector containing the multiples of two less than 50
    vector<int> multiples_of_two;
    for(int i = 0; i < 50; i += 2)
        multiples_of_two.push_back(i);
    
    // Create also a vector containing the mutliples of three less than 50
    vector<int> multiples_of_three;
    for (int i = 0; i < 50; i += 3)
        multiples_of_three.push_back(i);

    vector<int> empty_vec;
    
    // Create some strings to test our functions too
    string str1 = "uncomplicated";
    string str2 = "complicate";
    string empty_str;

    remove_if_bl(multiples_of_two.begin(), multiples_of_two.end(), aux_checker);

    for(vector<int>::const_iterator itr = multiples_of_two.begin(); itr != multiples_of_two.end(); ++itr)
        cout << *itr << endl;

    return 0;
}