#include <iostream>
#include "roster.h"

using namespace std;


Roster::Roster()
{
};



void Roster::parse(string row)
{
	cout << "Parsing . . .\n";
	DegreeProgram dp = DegreeProgram::SOFTWARE; //Default is software

	if (row.back() == 'E')
	{
		dp = DegreeProgram::SOFTWARE;
	}
	else if (row.back() == 'K')
	{
		dp = DegreeProgram::NETWORK;
	}
	else
	{
		dp = DegreeProgram::SECURITY;
	}
	string parsed[10];
	int rhs = 0;
	int lhs = 0;
	for (int i = 0; i < 10; i++)
	{
		rhs = row.find(",", lhs);
		parsed[i] = row.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
	}
	add(parsed[0], parsed[1], parsed[2], parsed[3], stoi(parsed[4]), stod(parsed[5]), stod(parsed[6]), stod(parsed[7]), dp);
};
Student** Roster::getClassRosterArray()
{
	return this->classRosterArray;
};


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram degreeProgram)
{
	double daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
	cout << "Student added to class roster at row " << lastIndex + 1 << endl;
};

void Roster::removeByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			success = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[classRosterArraySize - 1];
			classRosterArray[classRosterArraySize - 1] = temp;
			Roster::lastIndex--;

		}
	}
	if (success)
	{
		cout << "Student" << studentID << "removed successfully." << endl;
		printAll();
	}
	else cout << "Student" << studentID << " not found." << endl;
};

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
};

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
		}
	}
};


void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = classRosterArray[i]->getEmailAddress();
		if (email.find(' ') != string::npos || email.find('.') == string::npos || email.find('@') == string::npos)
			cout << "Invalid email address" << endl;
	}
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();

};

Roster::~Roster()
{
	for (int i = 0; i < classRosterArraySize; i++)
	{
		cout << "Destructor successfully called for " << classRosterArray[i]->getID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};