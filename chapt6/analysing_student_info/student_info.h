#ifndef GUARD_student_info
#define GUARD_student_info

//student_info.h header file

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <cctype>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::ifstream& read_student_data_to_list(std::ifstream&, std::list<Student_info>&);
std::ifstream& read_student_data_to_vector(std::ifstream&, std::vector<Student_info>&);
std::istream& read(std::istream&, Student_info&);
Student_info init_student_from_data(const std::vector<std::string>&);

std::istream& read_hw(std::istream&, std::vector<double>&);

std::vector<std::string> split(const std::string&);
bool notpunct(char);
bool punct(char);

#endif
