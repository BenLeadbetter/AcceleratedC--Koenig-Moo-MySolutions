#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "student_info.h"
#include "splitting_function_iter.h"

using namespace std;

int main()
{
    string::size_type maxlen = 0;

    
    // open a file stream and read the information 
    // into a vector of Student_info objects
    ifstream file_stream;
    file_stream.open("./student_data.csv");
    if (!file_stream)
    {
        cout << "could not open file" << endl;
        return 1;
    }
    
    vector<Student_info> students;
    Student_info record;
    while(record.read_from_file(file_stream))
    {
        students.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }

    file_stream.close();

    // put students into ascending order, by grade
    sort (students.begin(), students.end(), compare_grades);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0;
        i != students.size();
        ++i)
        {
            cout << students[i].name()
                 << string(maxlen + 5 - students[i].name().size(), ' ');
            
            try {
                double final_grade = students[i].grade();
                streamsize prec = cout.precision();
                cout << setprecision(3)
                     << final_grade
                     << setprecision(prec)
                     << endl;
            } catch (domain_error e) {
                cout << e.what() << endl;
            }
        }

    return 0;
}