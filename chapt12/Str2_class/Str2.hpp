
#ifndef GUARD__STR2
#define GUARD__STR2

// Header file for the Str2 class managing the data for the Str as a null-terminated array
// e.g. Str s = "string" == ['s', 't', 'r', 'i', 'n', 'g', '\0']
 
 #include <iostream>
 #include <memory>

class Str
{
    friend std::ostream& operator<<(std::ostream&, const Str);
    
    public:
        
        //typedefs
        typedef char* iterator;
        typedef const char* const_iterator;
        typedef size_t size_type;

        // constructors
        Str() { create(); }
        Str(const_iterator begin) { create(begin); }

        // returns a pointer to a copy of the data, 
        // stored seperately and subject to change
        iterator c_str() { update_copy();     return data_copy; }


        // copy constructor - needs to change
        // Str(const Str& s) { create(data); }

        // destructor
        ~Str() { uncreate(); }

        // assignment operator
        Str& operator=(const Str&);

        // iterator return - not allowed!!
        // iterator begin() { return data; }
        // const_iterator begin() const { return data; }

        // size function
        size_type size() const { return length; }
    
    private:
        
        // pointer to the data
        iterator data;

        // pointer to ephemeral copied data
        iterator data_copy;

        // length of the string
        size_type length;

        // memory handler
        std::allocator<char> alloc;

        //memory management functions
        void create();
        void create(const char* begin);
        void uncreate();
        void update_copy();

};

// 
Str::size_type null_terminated_size(const char* begin)
{
    Str::size_type ret = 0;
    while(*begin != '\0')
    {
        ++begin;
        ++ret;
    }

    return ret;
}



void Str::create()
{
    data = 0;
    length = 0;
    data_copy = 0;
}

void Str::create(const char* begin)
{
    length = null_terminated_size(begin);
    data = alloc.allocate(length);
    iterator itr = data;

    for(size_type i = 0; i != length; ++i)
        *itr++ = *begin++;

    data_copy = 0;
    

}

// To implement this c_str function we'll first run a function
// update_copy() - then return a constant pointer to this copy
void Str::update_copy()
{
    // allocate space for the copy, if not already
    if(data_copy = 0)
    {
        data_copy = alloc.allocate(length);
    }

    for(size_type i = 0; i != length; ++i)
        *data_copy++ = *data++;
}


void Str::uncreate()
{
    if(data != 0)
    {
        // destroy the characters
        iterator itr = data;
        for(size_type i = 0; i != length; ++i)
            alloc.destroy(itr++);
        
        alloc.deallocate(data, length);
    }
    // destroy the copy too
    if(data_copy != 0)
    {
        // destroy the characters
        iterator itr = data_copy;
        for(size_type i = 0; i != length; ++i)
            alloc.destroy(itr++);
        
        alloc.deallocate(data_copy, length);
    }

    length = 0;
    data = 0;
    data_copy = 0;
}

std::ostream& operator<<(std::ostream& os, const Str s)
{
    Str::const_iterator itr = s.data;
    for(Str::size_type i = 0; i != s.length; ++i)
        os << *itr++;
    
    return os;
}


// Assignment operator needs to change
Str& Str::operator=(const Str& rhs)
{
    // check for self assignment
    if(&rhs != this)
    {
        // destroy the lhs
        uncreate();

        // copy elements from rhs to lhs
        create(rhs.c_str());
    }
    return *this;
}

#endif