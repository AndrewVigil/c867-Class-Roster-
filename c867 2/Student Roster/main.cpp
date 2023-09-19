/*
 * main.cpp
 *
 *  Created on: Jul 19, 2022
 *      Author: andrewstephens
 */



#include <iostream>
#include <iomanip>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;



int main() {


	std::cout << "C867 -- SCRIPTING AND PROGRAMMING LANGUAGES" << std::endl;
	std::cout << "PROGRAMMING LANGUAGE: C++" << std::endl;
	std::cout << "WGU STUDENT ID: 0012345" << std::endl;
	std::cout << "PROGRAMMMER: ANDREW VIGIL" << std::endl;
	std::cout << std::endl;


	const string studentData[] =
	{
			"A1,John,Smith,john1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,the_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Andrew,Vigil,andrewvigil@live.com,30,40,50,50,SOFTWARE"
	};

	Roster classRoster;

	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		classRoster.ClassRosterParse(studentData[i]);
	}

	std::cout << "Printing student list: " << std::endl;
	classRoster.PrintAll();

	std::cout << std::endl;

	std::cout << "List of invalid email addresses: " << std::endl;
	classRoster.PrintInvalidEmails();


	std::cout << std::endl << "Average days in courses, per student: " << std::endl;
		for (int i = 0; i < TOTAL_STUDENTS; ++i){
			classRoster.PrintAvgDaysInCourse(classRoster.classRosterArray[i]->Student::getStudentID());

		}


	classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);

	std::cout << std::endl;


	// show removal of student
	classRoster.Remove("A3");
	std::cout << std::endl;

	classRoster.PrintAll();
	std::cout << std::endl;

	classRoster.Remove("A3");
	std::cout << std::endl;



	classRoster.~Roster();



	return 0;
}



