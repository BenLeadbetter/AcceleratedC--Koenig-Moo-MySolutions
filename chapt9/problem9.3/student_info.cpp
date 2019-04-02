// source file for student_info and related functions

#include "student_info.h"
#include "splitting_function_iter.h"
#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>

using namespace std;

bool compare (const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}
bool compare_grades (const Student_info& x, const Student_info& y)
{
	return x.grade() < y.grade();
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
// This function is for checking whether a vector of data is valid
bool not_alphanumeric(char c)
{
	return !isalnum(c);
}
bool not_float_char(char c)
{
	return !(isdigit(c) || c == '.');
}

bool is_valid_data(const vector<string>& data_vec)
{
	if(data_vec.size() < 3)
		return false;
	
	if(find_if(data_vec[0].begin(), data_vec[0].end(), not_alphanumeric) != data_vec[0].end())
		return false;
	
	for(vector<string>::size_type i = 1; i != data_vec.size(); ++i)
		if(find_if(data_vec[i].begin(), data_vec[i].end(), not_float_char) != data_vec[i].end())
			return false;

	return true;	
}

// this member function reads student data from a data file
istream& Student_info::read_from_file(istream& fstream)
{
	// grab next line of input file
	string line;
	if(getline(fstream, line))
	{
		// split that line into a vector of strings
		vector<string> split_line;
		word_split(line, back_inserter(split_line));

		// check to see whether data is valid
		if(!is_valid_data(split_line))
		{
			cerr << "file line is invalid data input" << endl;
		}

		// Now read the vector's content into the Student_info object
		n = split_line[0];
		midterm = stof(split_line[1]);
		final = stof(split_line[2]);

		// Read the rest into the homework vector
		for(vector<string>::size_type i = 3; i != split_line.size(); ++i)
			homework.push_back(stof(split_line[i]));
	} else fstream.get();
	
	return fstream;
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

