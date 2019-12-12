#pragma once
#include <string>

#include "./student.h"

class SecurityStudent : public Student
{
public:
	//Overrides printStudent Method in Student Class
	void printStudents();

	//Overrides getDegreeProgram Method in Student Class
	Degree getDegreeProgram();

	//Constructors
	SecurityStudent();
	SecurityStudent
	(
		std::string studentID,
		std::string studentFirstName,
		std::string studentLastName,
		std::string studentEmai,
		std::string studentAge,
		double daysToComplete[],
		Degree degreeProgram
	);

	//Deconstructor
	~SecurityStudent();
};