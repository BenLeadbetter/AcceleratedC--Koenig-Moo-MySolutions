#ifndef GUARD_VEC
#define GUARD_VEC

#include <memory>
#include <algorithm>

template<class T>
class Vec
{
    public:
        // interface
        // type definitions
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        // operations
        Vec()                                           { create(); }                       // default constructor*  -> these need to be there
        Vec(const Vec& v)                               { create(v.begin(), v.end()); }     // copy constructor*
        explicit Vec(size_type n, const T& val = T())   { create(n, val); }                 // custom constructor
        ~Vec()                                          { uncreate(); }                     // destructor*
        Vec& operator=(const Vec&);                                                         // assignment operator*     -> the 'rule of three' 
                                                                                            //                              - copy constructor
                                                                                            //                              - destructor
                                                                                            //                              - assignment operator
        
        size_type size() const          { return avail - data; }
        T& operator[] (size_type i)     { return data[i]; }
        void push_back(const T&);
        iterator erase(iterator);
        iterator erase(iterator, iterator);
        void clear()                    { uncreate(); }

        // operations returning iterators
        iterator begin()                { return data; }
        const_iterator begin() const    { return data; }

        iterator end()                  { return avail; }
        const_iterator end() const      { return avail; }
    
    private:
        iterator data;        // first element in vec
        iterator avail;       // (one past) the last constructed element 
        iterator limit;       // (one past) the last available element in vec

        // facilities for memory alocation
        std::allocator<T> alloc;

        // allocate and initialize memory 
        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        // destroy initialized memory
        void uncreate();

        // support functions for push_back
        void grow();
        void unchecked_append(const T&);

};

// Assignmnet operator (different from the copy operator - involves destroying the lhs first!)
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    // check for self-assignmnet
    if(&rhs != this)
    {
        // free the array on the left-hand-side
        uncreate();

        // copy the elements from the right-hand to the left-hand side
        create(rhs.begin(), rhs.end());
    }

    return *this;
}

// definition for the push_back function
template <class T>
void Vec<T>::push_back(const T& val)
{
    if (avail == limit)     // get space if needed
        grow();
    unchecked_append(val);  // append the new element
}

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator it)
{
    iterator ret = it;

    // working from the term to delete, replace each term with the next
    // we stop at the last constructed term
    while(it != avail - 1)
    {
        *it = *(it + 1);
        ++it;
    }
    

    //remove the final term
    alloc.destroy(it);

    // redefine avail
    avail = it;

    return ret;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator pos1, Vec<T>::iterator pos2)
{
    iterator ret = pos1;
    
    // Copy terms above the deletion range down into the rest of the vector
    while(pos2 != avail)
    {
        *pos1++ = *pos2++;
    }

    // Destroy the copied terms at the top of the Vec
    while(pos2 != pos1)
        alloc.destroy(--pos2);

    // Redefine avail
    avail = pos1;

    //return iterator on past the last deleted term
    return ret;
}



template <class T>
void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    data = alloc.allocate(j - i);
    limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate()
{
    if(data)
    {
        // destroy, in reverse order, the elements that were constructed
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        
        // return all the space that was allocated
        alloc.deallocate(data, limit - data);
    }
    // reset the pointers, indicating that Vec is empty
    data = avail = limit = 0;
}

// These are the definitions for the support functions for push_back
template <class T>
void Vec<T>::grow()
{
    // we will allocate two the required size each time grow is called
    size_type new_size = std::max(2 * (limit - data), std::ptrdiff_t(1));

    // allocate new space and copy existing elements into the new space
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // return the old space
    uncreate();

    // reset the pointers to point to the newly allocated space
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

// This function assumes that the place to which we are appending is empty
template <class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}


#endif 