// source file for student_info and related functions

#include "student_info.h"

using std::istream;	using std::vector;
using std::cout;	using std::endl;

bool compare (const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	cout << "Enter student's name followed by midterm and finals grades:" << endl;
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is, s.homework);
	
	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		cout << "Input homework grades" << endl;
		// get rid of prev. contents
		hw.clear();
		
		//read homework grades
		double x;
		while(in >> x)
			hw.push_back(x);
			
		//clear the stream for the next student
		in.clear();
	}
	return in;
}
