#include <iostream>
#include <string>
#include <cstdlib>

#include "./softwareStudent.h"


//Sets Degree Program to SOFTWARE in Empty Constructor
SoftwareStudent::SoftwareStudent() :Student()
{
	degreeProgram = SOFTWARE;
}

//Sets Degree Program to SOFTWARE in Constructor With Parameters
SoftwareStudent::SoftwareStudent
(
	std::string studentID,
	std::string studentFirstName,
	std::string studentLastName,
	std::string studentEmail,
	std::string studentAge,
	double daysToComplete[],
	Degree degreeProgram
)
	:Student(studentID, studentFirstName, studentLastName, studentEmail, studentAge, daysToComplete)
{
	degreeProgram = SOFTWARE;
}

//Overrides Virtual Function in Student Class
Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::printStudents()
{
	this->Student::printStudents();
	std::cout << "Degree Program: SOFTWARE" << std::endl << std::endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
