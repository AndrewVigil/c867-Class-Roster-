/*
 * roster.h
 *
 *  Created on: Jul 19, 2022
 *      Author: andrewstephens
 */

#ifndef ROSTER_H_
#define ROSTER_H_

#pragma once

#include "degree.h"
#include "student.h"
#include <string>
using std::string;



const int DATA_COLS = 9;
static const unsigned int TOTAL_STUDENTS = 5;


// roster class files and declarations

class Roster {

public:

// pointers array
	Student* classRosterArray[TOTAL_STUDENTS] = {

				nullptr, nullptr, nullptr, nullptr, nullptr
		};


	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree);
	void ClassRosterParse(string record);
	void Remove(string studentID);
	void PrintAll();
	void PrintAvgDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degree);

//destructor
	~Roster();

private:
	// inc adding student object in Roster::Add

	int index = -1;
};





#endif /* ROSTER_H_ */
