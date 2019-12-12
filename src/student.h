#pragma once
#include <iostream>
#include <string>
#include "./degree.h"


//Student Class
class Student
{
public:
	//Determines Size of daysToComplete Array
	const static int dtcSize = 3;

protected:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string age;
	double daysToComplete[dtcSize];
	Degree degreeProgram;

public:
	//Constructors
	Student();
	Student
	(
		std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		std::string age,
		double daysToComplete[]
	);

	//Getters
	std::string getStudentID();
	std::string getStudentEmail();
	std::string getFirstName();
	std::string getLastName();
	std::string getStudentAge();
	double* getDTC();
	virtual Degree getDegreeProgram() = 0;

	//Setters
	void setStudentId(std::string studentID);
	void setStudentEmail(std::string emailAddress);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setStudentAge(std::string age);
	void setDTC(double daysToComplete[]);
	Degree setDegreeProgram();

	//Printer
	virtual void printStudents() = 0;

	//Destructor
	~Student();
};
