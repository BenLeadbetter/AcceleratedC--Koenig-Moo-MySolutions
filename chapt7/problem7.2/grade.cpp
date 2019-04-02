//source file for grade.h

#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "student_info.h"

using std::domain_error;	using std::vector;

double grade (double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
		
		
	return grade(midterm, final, median(hw));
}


double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool failed(Student_info s)
{
	return grade(s) < 60;
}

char letter_grade(Student_info s)
{
	double g = grade(s);
	if (g > 90)
		return 'A';
	else if (g > 80)
		return 'B';
	else if (g > 70)
		return 'C';
	else if (g > 60)
		return 'D';
	else
		return 'F';
}


