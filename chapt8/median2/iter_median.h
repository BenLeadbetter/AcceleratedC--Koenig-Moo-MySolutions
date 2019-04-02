// Header file for the new, generic median function
#ifndef GUARD_MEDIAN
#define GUARD_MEDIAN


#include <algorithm>
#include <stdexcept>

// Declaration
template<class Ran>
float median(Ran beg, Ran end);


// Definition
template<class Ran>
float median(Ran beg, Ran end)
{   
    if(beg == end)
        throw std::domain_error("Median of an empty vector");
    
    std::sort(beg, end);

    Ran mid = beg + (end - beg) / 2;

    float ret;

    if ((end - beg) % 2 != 0)
        ret = *mid;
    else
        ret = (*mid + *(mid - 1)) / 2.0;
    
    return ret;

}

#endif