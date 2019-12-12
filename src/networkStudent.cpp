#include <iostream>
#include <string>
#include <cstdlib>

#include "./networkStudent.h"


//Sets Degree Program to NETWORK in Empty Constructor
NetworkStudent::NetworkStudent() :Student()
{
	degreeProgram = NETWORK;
}

//Sets Degree Program to NETWORK in Constructor With Parameters
NetworkStudent::NetworkStudent
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
	degreeProgram = NETWORK;
}

//Overrides Virtual Function in Student Class
Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

//Overrides Virtual Print Function in Student Class
void NetworkStudent::printStudents()
{
	this->Student::printStudents();
	std::cout << "Degree Program: NETWORK" << std::endl << std::endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}