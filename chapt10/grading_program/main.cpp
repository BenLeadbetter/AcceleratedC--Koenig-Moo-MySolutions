#include <iostream>

using namespace std;

string letter_grade(double grade)
{
    // Range posts for numeric grades
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
    };

    // names for the letter grade
    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    // compute the number of grades given by the size of the array
    // and the size of a single element
    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    // if numbers returns a pointer to the first element of numbers, why doesn't
    // sizeof(numbers) return the size of that pointer?
    // cout << ngrades << endl;

    // given a numeric grade, find and compute the ascociated letter grade
    for (size_t i = 0; i < ngrades; ++i)
    {
        if(grade >= numbers[i])
            return letters[i];
    }

    return "\?\?\?";

}

int main()
{

    cout << letter_grade(89) << endl;

    return 0;
}