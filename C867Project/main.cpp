#include <iostream>
#include <string>
#include "roster.h"



using namespace std;

int main()
{
	cout << "------------------------------------------" << std::endl;
	cout << "C867: Scripting and Programming Applications" << std::endl;
	cout << "Created in C++" << std::endl;
	cout << "By Jesse Perez, studentID: 010397732 " << std::endl;
	cout << "------------------------------------------";

	const string rosterData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY ",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SOFTWARE",
		"A5,Jesse,Perez,jesseorhs@gmail.com,25,30,31,32,SOFTWARE"
	};

	const int rosterArraySize = 5;

	Roster roster;
	cout << "Displaying roster: " << endl;
	roster.printAll();

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by Degree Program: " << degreeProgramStrings[i] << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Displaying invalid email addresses: " << endl;
	roster.printInvalidEmails();

	cout << "Displaying average days in each course: " << endl;
	for (int i = 0; i < rosterArraySize; i++) roster.printAverageDaysInCourse(roster.getClassRosterArray()[i]->getID());

	cout << "Removing student A3: " << endl;
	roster.removeByID("A3");
	roster.printAll();
	roster.removeByID("A3");

	cout << "Display complete. Destructor will be called upon exit." << endl;

	return 0;
};

