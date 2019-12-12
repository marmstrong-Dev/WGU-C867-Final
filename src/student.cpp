#include <iostream>
#include <string>

#include "./student.h"


/*
Defines Empty Constructor for Student
*/
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";

	for (int i = 0; i < dtcSize; i++)
	{ this->daysToComplete[i] = 0; }
}

/*
Defines Constructor With Parameters for Variables
*/
Student::Student
(
	std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	std::string age,
	double daysToComplete[]
)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;

	for (int i = 0; i < dtcSize; i++)
	{ this->daysToComplete[i] = daysToComplete[i]; }
}

/*
Definitions For Getters
*/

//Student ID Getter
std::string Student::getStudentID()
{ return studentID; }

//Student First Name Getter
std::string Student::getFirstName()
{ return firstName; }

//Student Last Name Getter
std::string Student::getLastName()
{ return lastName; }

//Student Email Address Getter
std::string Student::getStudentEmail()
{ return emailAddress; }

//Student Age Getter
std::string Student::getStudentAge()
{ return age; }

//Days To Complete Courses Getter
double* Student::getDTC()
{ return daysToComplete; }

/*
Definitions For Setters
*/

//Sets Student ID
void Student::setStudentId(std::string studentID)
{ this->studentID = studentID; }

//Sets Student First Name
void Student::setFirstName(std::string firstName)
{ this->firstName = firstName; }

//Sets Student Last Name
void Student::setLastName(std::string lastName)
{ this->lastName = lastName; }

//Sets Student Email Address
void Student::setStudentEmail(std::string emailAddress)
{ this->emailAddress = emailAddress; }

//Sets Student Age
void Student::setStudentAge(std::string studentAge)
{ this->age = studentAge; }

//Sets Days To Complete Courses
void Student::setDTC(double daysToComplete[])
{ 
	for (int i = 0; i < 3; i++)
	{ this->daysToComplete[i] = daysToComplete[i]; }
}

/*
Roster Printer
*/
void Student::printStudents()
{
	std::cout << "ID: " << studentID;
	std::cout << "\t  First Name: " << firstName;
	std::cout << "\t Last Name: " << lastName;
	std::cout << "\t Email Address: " << emailAddress;
	std::cout << "\t Age: " << age;
	
	std::cout << "\t Days To Complete Courses: { ";
	for (int i = 0; i < 3; i++)
	{ std::cout << daysToComplete[i] << " "; }
	std::cout << "} \t";
}


//Definition for Deconstructor
Student::~Student(){}
