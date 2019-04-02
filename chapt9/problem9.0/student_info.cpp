// source file for student_info and related functions

#include "student_info.h"
#include <exception>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare (const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
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

istream& Student_info::read(istream& is)
{
	is >> n >> midterm >> final;
	
	read_hw(is, homework);
	
	return is;
}

//compute the median of a vector<double>
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error ("median of an empty vector");
		
	sort(vec.begin(), vec.end());
	
	vec_sz mid = size/2;
	
	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
	
}

// Grade functions
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
double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

// Definitions for our constructors
Student_info::Student_info (): midterm(0), final(0) { }
Student_info::Student_info (istream& is) {read(is); }

