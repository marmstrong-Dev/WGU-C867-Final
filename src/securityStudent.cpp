#include <iostream>
#include <string>
#include <cstdlib>

#include "./securityStudent.h"


//Sets Degree Program to SECURITY in Empty Constructor
SecurityStudent::SecurityStudent() :Student()
{
	degreeProgram = SECURITY;
}

//Sets Degree Program to SECURITY in Constructor With Parameters
SecurityStudent::SecurityStudent
(
	std::string studentID,
	std::string studentFirstName,
	std::string studentLastName,
	std::string studentEmail,
	std::string studentAge,
	double daysToComplete[],
	Degree degreeProgram
)
	: Student(studentID, studentFirstName, studentLastName, studentEmail, studentAge, daysToComplete)
{
	degreeProgram = SECURITY;
}

//Overrides Virtual Function in Student Class
Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

void SecurityStudent::printStudents()
{
	this->Student::printStudents();
	std::cout << "Degree Program: SECURITY" << std::endl << std::endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}