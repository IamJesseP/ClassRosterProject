#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
using namespace std;

class Roster
{
private:
	const static int classRosterArraySize = 5;
	int lastIndex = -1; //starting position
	Student* classRosterArray[classRosterArraySize] = {nullptr, nullptr, nullptr, nullptr, nullptr};

public:
	Roster(); //paramterless constructor

	void parse(string row); //parse function

	Student** getClassRosterArray();


	//Roster Methods
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram degreeProgram);
	void removeByID(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();//Destructor
};

#endif