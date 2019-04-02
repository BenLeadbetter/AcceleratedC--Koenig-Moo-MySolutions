#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"


using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;	using std::streamsize;

using std::endl;			using std::string;
using std::max;				using std::vector;


int main ()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;		//length of the longest name
	
	//read and store all of the students' data.
	// Invariant: 	vs contains all the student records
	// 				max contains the longest name in vs
	
	while (read(cin, record)){
		
		//find the longest name
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	
	// alphabetize the student records
	
	sort(students.begin(), students.end(), compare);
	
	//write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); i++){
		
		// write name with padding on the right, up to maxlen +1 char.s
		cout 	<< students[i].name
				<< string(maxlen + 1 - students[i].name.size(), ' ');
		
		//compute and write the grade
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e) {
			cout <<e.what();
		}
		cout << endl;
	}
			
	return 0;
	
}
