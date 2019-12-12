#pragma once
#include <string>

#include "./student.h"

class SoftwareStudent : public Student
{
public:
	//Overrides printStudent Method in Student Class
	void printStudents();

	//Overrides getDegreeProgram Method in Student Class
	Degree getDegreeProgram();

	//Constructors
	SoftwareStudent();
	SoftwareStudent(
		std::string studentID,
		std::string studentFirstName,
		std::string studentLastName,
		std::string studentEmai,
		std::string studentAge,
		double daysToComplete[],
		Degree degreeProgram
	);

	//Deconstructor
	~SoftwareStudent();
};
