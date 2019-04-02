#ifndef GUARD_student_info
#define GUARD_student_info

//student_info.h header file

#include <string>
#include <vector>

class Student_info
{
	public:
		std::string name() const {return n;}
		bool valid() const { return !homework.empty(); }
		std::istream& read(std::istream&);
		double grade() const;

		// constructors
		Student_info();
		Student_info(std::istream&);

	private:
		std::string n;
		double midterm, final;
		std::vector<double> homework;

};


bool compare(const Student_info&, const Student_info&);
double median(std::vector<double>);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);



#endif