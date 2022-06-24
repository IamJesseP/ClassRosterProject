#ifndef STUDENT_H
#define STUDENT_H
#include <string>

#include "degree.h"

using namespace std;


class Student
{
public:
	const static int daysInCourseArray = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysInCourse[daysInCourseArray];
	DegreeProgram degreeProgram;
public: //methods
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysToComplete[], DegreeProgram degreeProgram);
	~Student();

	//getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	const double* getDaysInCourse(); //Cannot return arrays, only pointers
	DegreeProgram getDegreeProgram();

	//setters
	void setStudentID(string sID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmailAddress(string eAddress);
	void setAge(int age);
	void setDaysInCourse(const double dInCourse[]);
	void setDegreeProgram(DegreeProgram degProgram);

	static void printHeader();

	void print();

};

#endif