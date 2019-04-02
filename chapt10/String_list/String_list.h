#ifndef GUARD_STRING_LIST
#define GUARD_STRING_LIST

#include <string>

class String_list
{

    private:
        std::string* l;
        std::size_t size;
        std::size_t max;

        void resize();


    public:

        typedef std::string* iterator;

        // Default constructor
        String_list(): l(new std::string[1]), size(0), max(1) {};
        String_list(const String_list& src);
        ~String_list();

        void push_back(std::string);
        iterator begin() { return l; }
        iterator end() { return l + size; }

};


#endif // !GUARD_STRING_LIST