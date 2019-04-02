#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "student_info.h"
#include "grade.h"

using namespace std;

string::size_type longest_name_width(const list<Student_info>& ls)
{
	string::size_type ret = 0;
	
	for(list<Student_info>::const_iterator i = ls.begin(); i != ls.end(); ++i)
		ret = max(ret, (*i).name.size());
		
	return ret;
}

list<Student_info> extract_fails(list<Student_info>& ls)
{
	list<Student_info> ret;
	
	for(list<Student_info>::iterator i = ls.begin(); i != ls.end(); ++i)
	{
		if(failed(*i))
		{
			ret.push_back(*i);
			i = ls.erase(i);
		} else 
			++i;
	}
	
	return  ret;
}


int main()
{
	//open file stream and read it into a list<Student_info>
	ifstream i_file;
	i_file.open("/home/ben/Documents/cpp/Chapter_Five_Exercises/grading_program_2/student_data.2.csv");
	
	if(!i_file)
	{
		cerr << "Could not open file student_data.csv";
		exit(1);
	}
	
	list<Student_info> student_data;
	read_student_data_to_list(i_file, student_data);
	
	i_file.close();
	
	//grab longest name length
	string::size_type maxlen = longest_name_width(student_data);
	
	//extract students who failed the course
	list<Student_info> failing_students = extract_fails(student_data);
	
	//name and shame the failing students
	cout << "Student Name" << string(5 + maxlen - 12, ' ') << "Grade" << endl;
	for(list<Student_info>::const_iterator i = failing_students.begin(); i != failing_students.end(); ++i)
		cout << (*i).name << string(5 + maxlen - (*i).name.size(), ' ') << grade(*i) <<endl;
	
	return 0;
}
