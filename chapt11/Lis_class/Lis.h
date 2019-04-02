#ifndef GUARD__LIS
#define GUARD__LIS

#include <memory>

template <class T>
class Lis
{
    public:
    // typedefs
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;

    // functions
    Lis() { create(); } // default construct
    explicit Lis(const_iterator i, const_iterator j) { create(i, j); }   // special constructor
    Lis(const Lis& l) { create(l.begin(), l.end()); }   // copy constructor
    ~Lis() { uncreate(); } // destructor
    Lis& operator=(const Lis&); // assignment operator
    void push_back(const T&);
    iterator begin() { return data;}
    iterator end() { return avail; }
    size_type size() { return limit - data; }

    private:
    // data <= avail <= limit
    iterator data;
    iterator avail;
    iterator limit;

    // facility for memory allocation in the underlying array
    std::allocator<T> alloc;
    
    void create();
    void create(const_iterator, const_iterator);
    void uncreate();

    // support functions for the push_back function
    void grow();
    void unchecked_append(const T& val);

};

// Careful creation functions - dealing with memory allocation
template <class T>
void Lis<T>::create()
{
    data = avail = limit = 0;  // set the read-outs to empty
}

template <class T>
void Lis<T>::create(Lis<T>::const_iterator i, Lis<T>::const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Lis<T>::grow()
{
    size_type new_size = limit - data == 0 ? ptrdiff_t(1) : 2 * (limit - data);

    // allocate new space to a fresh array and copy in the elements
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // Destroy old information
    uncreate();

    // redefine the new data and avail;
    data = new_data;
    avail = new_avail;
    limit = data + new_size;

}

template <class T>
void Lis<T>::uncreate()
{
    if(data)
    {
        // destroy the elements in reverse order
        iterator it = avail;
        while(it != data)
            alloc.destroy(--it);
        
        // return all the allocated space
        alloc.deallocate(data, limit - data);
    }

    //reset the pointers
    data = avail = limit = 0;
}

// this is the assignment operator!
template <class T>
Lis<T>& Lis<T>::operator=(const Lis<T>& rhs)
{
    // first check for self-assignment
    if (&rhs != this)
    {
        // destroy the Lis on the left
        uncreate();

        create(rhs.begin(), rhs.end());
    }
}

//push_back function
template <class T>
void Lis<T>::push_back(const T& val)
{
    if(avail == limit)
        grow();
    
    unchecked_append(val);
}

// this function assumes that there will be space to append to
template <class T>
void Lis<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}



#endif 