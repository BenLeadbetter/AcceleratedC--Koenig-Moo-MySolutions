// source file for student_info and related functions

#include "student_info.h"

using namespace std;

bool compare (const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
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

istream& read(istream& is, Student_info& s)
{
	cout << "Enter student's name followed by midterm and finals grades:" << endl;
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is, s.homework);
	
	return is;
}

//this function splits the line into parts, delimited by commas
bool comma(char c)
{
	return c == ',';
}
bool notcomma(char c)
{
	return c != ',';
}

//splits up a line of student info .csv data into a vector of strings
vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;
	while(i != str.end())
	{
		i = find_if(i, str.end(), notcomma);
		iter j = find_if(i, str.end(), comma);
		if(i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}	
	return ret;
}

//writes a vector<string> into a Student_info
Student_info init_student_from_data(const vector<string>& vec)
{
	Student_info ret;
	
	ret.name = vec[0];
	ret.midterm = stof(vec[1]);
	ret.final = stof(vec[2]);
	
	vector<double> hw;
	for(vector<string>::size_type i = 3; i != vec.size(); ++i)
		hw.push_back(stof(vec[i]));	
	ret.homework = hw;
	
	return ret;
}
//writes a .csv file into a list<Student_info>
ifstream& read_student_data_to_list(ifstream& i_file, list<Student_info>& ls)
{
	string str;
	Student_info student;	
	
	while(getline(i_file, str))
	{
		student = init_student_from_data(split(str));
		ls.push_back(student);
	}
		
	return i_file;
}
//writes a .csv file into a vector<Student_info>
ifstream& read_student_data_to_vector(ifstream& i_file, vector<Student_info>& vec)
{
	string str;
	Student_info student;	
	
	while(getline(i_file, str))
	{
		student = init_student_from_data(split(str));
		vec.push_back(student);
	}
		
	return i_file;
}
