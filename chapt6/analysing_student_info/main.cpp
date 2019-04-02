// This program is for comparing different marking schemes
// Addressing the issue of what to do when a student has not submitted homework assignments
// 


#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "student_info.h"
#include "grade.h"
#include "median.h"

using namespace std;


// Boolean checking whether a student has completed all their hw
bool did_all_homework(const Student_info s)
{
    return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}
// auxilery grade function to make sure the error handling works
double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}
// This function analyses how students do using a standard median on their hw grades
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

    return median(grades);
}

// This function analyses how students do using a mean average on their hw grades
double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), average_grade);

    return median(grades);
}
// This function analyses how students do using an optimistic median on their hw grades
double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median_grade);

    return median(grades);
}
// This function will compare the grades given to two different groups of students
// based on a user defined marking scheme
void write_analysis(ostream& out, 
    const string& name, 
    double analysis(const vector<Student_info>&),
    const vector<Student_info>& group1,
    const vector<Student_info>& group2) 
{
        out << name << ": median (group 1) = " << analysis(group1) <<
                   ", median (group 2) = " << analysis(group2) << endl;
    
    return;
}



int main()
{
	//open file stream and read it into a vector<Student_info>
	ifstream i_file;
	i_file.open("./student_data3.csv");
	
	if(!i_file)
	{
		cerr << "Could not open file student_data.csv";
		exit(1);
	}
	
	vector<Student_info> student_data;
	read_student_data_to_vector(i_file, student_data);
	
	i_file.close();
	
    // Create two new vector<Student_info> did and didnt 
    // to distiguish bewteen students who did/didn't do all their hw
    vector<Student_info> did, didnt;
    for(vector<Student_info>::const_iterator i = student_data.begin(); i != student_data.end(); ++i)
    {
        if(did_all_homework(*i))
            did.push_back(*i);
        else
            didnt.push_back(*i);
    }

    // Check that both groups contain some data
    if (did.empty())
    {
        cout << "No students did any homework" << endl;
        return 1;
    }
    if (didnt.empty())
    {
        cout << "Every student did all their homework" << endl;
        return 1;
    }

    // Do the analysis
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);	

	return 0;
}
