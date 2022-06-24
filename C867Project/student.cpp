#include <string>
#include <iostream>

#include "student.h"

using namespace std;

Student::Student() // Empty Constructor 
{
	this->studentID = " "; //Set to empty string to avoid a nullpter exception
	this->firstName = " ";
	this->lastName = " ";
	this->emailAddress = " ";
	this->age = 0;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE; //default will be software
}


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse[], DegreeProgram degreeProgram) //Full constructor
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;

}

Student::~Student() {}; //Destructor

//Getters
string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
const double* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//Setters
void Student::setStudentID(string sID) { this->studentID = sID; }
void Student::setFirstName(string fName) { this->firstName = fName; }
void Student::setLastName(string lName) { this->lastName = lName; }
void Student::setEmailAddress(string eAddress) { this->emailAddress = eAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(const double dInCourse[])
{
	for (int i = 0;i < daysInCourseArray; i++) this->daysInCourse[i] = dInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degProgram) { this->degreeProgram = degProgram; }


void Student::printHeader()
{
	cout << "Student ID\t";
	cout << "First Name\t";
	cout << "Last Name\t";
	cout << "Email Address\t";
	cout << "Age\t";
	cout << "Days to Complete\t";
	cout << "Degree Program\t" << endl;
}

void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	cout << this->daysInCourse[0] << '\t';
	cout << this->daysInCourse[1] << '\t';
	cout << this->daysInCourse[2] << '\t';

	cout << degreeProgramStrings[(int)this->degreeProgram] << endl;
}