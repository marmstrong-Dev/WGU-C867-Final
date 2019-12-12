#include <iostream>
#include <string>
#include <array>
#include <cstdlib>

#include "./roster.h"


//Dividing Section Border
void borderStars()
{
	for (int i = 0; i < 15; i++)
	{ std::cout << "*****"; }
	std::cout << std::endl;
}

/*
Displays Student Info Banner
*/
void headerBanner()
{
	//Project Submission Info
	std::string wguCourseTitle = " C867 - Scripting and Programming: Applications";
	std::string wguProgrammingLanguage = " C++ Version 14.23.27820.0";
	std::string wguStudentId = " #001256349";
	std::string wguStudentName = " Michael Armstrong";

	borderStars();

	//Header Printout
	std::cout << wguCourseTitle << std::endl << wguProgrammingLanguage << std::endl;
	std::cout << std::endl << wguStudentName << std::endl << " Student ID: " << wguStudentId << std::endl;

	borderStars();
}

//Initial Empty Constructor
Roster::Roster()
{
	this->rosterSize = 0;
	this->rosterIndex = -1;
	this->studentRoster = nullptr;
}

//Defines Constructor Declaring Roster Size
Roster::Roster(int rosterSize)
{
	this->rosterSize = rosterSize;
	this->rosterIndex = -1;
	this->studentRoster = new Student * [rosterSize];
}

//Defines Deconstructor
Roster::~Roster()
{
	for (int i = 0; i <= rosterIndex; i++)
	{ delete this->studentRoster[i]; }

	delete studentRoster;
}

/*
Parses and Generates Student Objects
*/
void Roster::studentsGenerator(std::string studentData)
{
	if (rosterIndex < rosterSize)
	{
		rosterIndex++;
		//Temp Storage Variables
		std::string tempID;
		std::string tempFirstName;
		std::string tempLastName;
		std::string tempAge;
		std::string tempEmail;
		double tempDTC[3];
		Degree tempDT;
		

		//Stores Position of Delimiter
		size_t delim = studentData.find(',');

		//Stores String Position
		size_t pos = 0;

		tempID = studentData.substr(pos, delim);

		pos = delim + 1;
		delim = studentData.find(',', pos);
		tempFirstName = studentData.substr(pos, (delim - pos));
		
		pos = delim + 1;
		delim = studentData.find(',', pos);
		tempLastName = studentData.substr(pos, (delim - pos));

		pos = delim + 1;
		delim = studentData.find(',', pos);
		tempEmail = studentData.substr(pos, (delim - pos));

		pos = delim + 1;
		delim = studentData.find(',', pos);
		tempAge = studentData.substr(pos, (delim - pos));

		for (int i = 0; i < 3; i++)
		{
			pos = delim + 1;
			delim = studentData.find(',', pos);
			tempDTC[i] = stod(studentData.substr(pos, (delim - pos)));
		}

		double tempDTC1 = tempDTC[0];
		double tempDTC2 = tempDTC[1];
		double tempDTC3 = tempDTC[2];

		pos = delim + 1;
		delim = studentData.find(',', pos);

		if (studentData.substr(pos, (delim - pos)) == "SECURITY")
		{ tempDT = SECURITY; }
		else if (studentData.substr(pos, (delim - pos)) == "NETWORK")
		{ tempDT = NETWORK; }
		else if (studentData.substr(pos, (delim - pos)) == "SOFTWARE")
		{ tempDT = SOFTWARE; }
		else
		{ std::cout << "Invalid Degree Program"; exit(-1); }

		//Generate Student Object
		addStudent(tempID, tempFirstName, tempLastName, tempEmail, tempAge, tempDTC1, tempDTC2, tempDTC3, tempDT);
	}
	
}

/*
Creates New Student Object
*/
void Roster::addStudent
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
)
{
	//Converts Individual Doubles to Array
	double daysToComplete[Student::dtcSize];

	daysToComplete[0] = tempDTC1;
	daysToComplete[1] = tempDTC2;
	daysToComplete[2] = tempDTC3;

	//Add Student Case Switch
	switch (tempDT)
	{
	case SECURITY:
		studentRoster[rosterIndex] = new SecurityStudent(tempID, tempFirstName, tempLastName, tempEmail, tempAge, daysToComplete, tempDT);
		break;

	case NETWORK:
		studentRoster[rosterIndex] = new NetworkStudent(tempID, tempFirstName, tempLastName, tempEmail, tempAge, daysToComplete, tempDT);
		break;
	
	case SOFTWARE:
		studentRoster[rosterIndex] = new SoftwareStudent(tempID, tempFirstName, tempLastName, tempEmail, tempAge, daysToComplete, tempDT);
		break;
	}
}

/*
Get Students For Specific ID
*/
Student* Roster::getStudents(int studentIndex)
{
	return studentRoster[studentIndex];
}

/*
Prints Average Days To Complete
*/
void Roster::printAverageDaysInCourse(std::string studentID)
{
	bool studentPresent = false;

	//Loops Through Student Roster
	for (int i = 0; i <= rosterIndex; i++)
	{
		//If Student is Found By ID, Prints Avg Days For Course Completion
		if (this->studentRoster[i]->getStudentID() == studentID)
		{
			studentPresent = true;
			double* dtc = studentRoster[i]->getDTC();
			double avgDTC = (dtc[0] + dtc[1] + dtc[2]) / 3;
			std::cout << "Student Average Days To Complete: " << studentID << "  " << avgDTC << std::endl;
		}	
	}

	//Prints Error if Student ID is Not Found
	if (studentPresent == false)
	{ std::cout << "Student ID Not Found" << std::endl; }
}

/*
Print All Invalid Email Addresses
*/
void Roster::printInvalidEmails()
{
	bool emailCorrect = false;

	for (int i = 0; i <= rosterIndex; i++)
	{
		emailCorrect = false;
		std::string emails = studentRoster[i]->getStudentEmail();
		
		if (emails.find('@') < 100 && emails.find('.') < 100)
		{
			if (emails.find(' ') > 100)
			{
				emailCorrect = true;
			}
		}

		if (!emailCorrect)
		{ 
			std::cout << "Invalid : " << emails << std::endl;
		}
		
	}
}

/*
Print By Degree Program
*/
void Roster::printByDegreeProgram(Degree dt)
{
	for (int i = 0; i <= rosterIndex; i++)
	{
		if (this->studentRoster[i]->getDegreeProgram() == dt)
		{
			this->studentRoster[i]->printStudents();
		}
	}
}

/*
Removes a Student From Roster
*/
bool Roster::removeStudent(std::string studentID)
{
	bool studentPresent = false;

	//Loops Through Student Roster
	for (int i = 0; i <= rosterIndex; i++)
	{
		//If Student is Found By ID, Remove Student and Set New Index
		if (this->studentRoster[i]->getStudentID() == studentID)
		{
			studentPresent = true;
			delete this->studentRoster[i];
			this->studentRoster[i] = this->studentRoster[rosterIndex];
			rosterIndex--;
		}
	}

	return studentPresent;
}

/*
Full Roster Printer
*/
void Roster::printAll()
{
	for (int i = 0; i <= this->rosterIndex; i++)
	{ (this->studentRoster)[i]->printStudents(); }
}


//Main Method
int main()
{
	int rosterSize = 5;

	//Defines Student Data Set
	const std::string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Michael,Armstrong,marms83@my.wgu.edu,30,20,40,33,SOFTWARE"
	};

	headerBanner();

	Roster* newRoster = new Roster(rosterSize);

	//Populates Roster
	std::cout << "Generating Roster: " << std::endl << std::endl;
	for (int ri = 0; ri < rosterSize; ri++)
	{ newRoster->studentsGenerator(studentData[ri]); }
	borderStars();

	//Prints All Students
	std::cout << "All Enrolled Students: " << std::endl << std::endl;
	newRoster->printAll();
	borderStars();

	//Print All SOFTWARE Students
	std::cout << "All SOFTWARE Students: " << std::endl << std::endl;
	newRoster->printByDegreeProgram(SOFTWARE);
	borderStars();

	//Prints Avg Days To Complete Courses
	std::cout << "Average Days To Complete Courses: " << std::endl << std::endl;
	for (int ri = 0; ri < rosterSize; ri++)
	{ newRoster->printAverageDaysInCourse(newRoster->getStudents(ri)->getStudentID()); }
	borderStars();

	//Print Invalid Emails
	std::cout << "List of Invalid Email Addresses: " << std::endl << std::endl;
	newRoster->printInvalidEmails();
	borderStars();

	//Removes Student A3
	if (newRoster->removeStudent("A3"))
	{
		std::cout << "Removing Student: A3 " << std::endl;
		newRoster->removeStudent("A3");
		rosterSize--;
	}
	else
	{ std::cout << "Student With This ID Was Not Found" << std::endl; }

	//Remove A3 Again as Test
	if (newRoster->removeStudent("A3"))
	{
		std::cout << "Removing Student: A3 " << std::endl;
		newRoster->removeStudent("A3");
		rosterSize--;
	}
	else
	{ std::cout << "Student With This ID Was Not Found" << std::endl; }
	borderStars();

	//Calls Deconstructor
	newRoster->~Roster();

	return 0;
}
