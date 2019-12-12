#pragma once
#include <iostream>
#include <string>

#include "student.h"
#include "./softwareStudent.h"
#include "./networkStudent.h"
#include "./securityStudent.h"


//Roster Class
class Roster
{
private:
	int rosterIndex;
	int rosterSize;
	Student** studentRoster;

public:
	Student* getStudents(int studentIndex);
	void studentsGenerator(std::string studentData);
	bool removeStudent(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printByDegreeProgram(Degree dt);
	void printInvalidEmails();
	void addStudent
	(
		std::string tempID,
		std::string tempFirstName,
		std::string tempLastName,
		std::string tempEmail,
		std::string tempAge,
		double tempDTC1,
		double tempDTC2,
		double tempDTC3,
		Degree tempDT
	);

	//Constructors
	Roster();
	Roster(int rosterSize);

	//Deconstructor
	~Roster();
};
