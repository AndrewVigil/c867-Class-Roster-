/*
 * student.h
 *
 *  Created on: Jul 19, 2022
 *      Author: andrewstephens
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#pragma once
#include "degree.h"
#include <stdio.h>
#include <string>


using std::string;


//student class header file and declarations

class Student {

public:

// constructors

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degree);


	// getters

	string getStudentID() const;
	string getFName() const;
	string getLName() const;
	string getEmailAddress() const;
	int getStudentAge() const;
	int* getDaysInCourse() const;
	DegreeProgram getDegree();
	void Print();


	const int DAYS_SIZE = 3;

// setters
	void setStudentID(string studentID);
	void setFName(string firstName);
	void setLName(string lastName);
	void setEmailAddress(string emailAddress);
	void setStudentAge(int age);
	void setDaysInCourse(int numDays[]);
	void setDegree(DegreeProgram degree);



// destructor
	~Student();





private:
//data members
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int* daysInCourse;
	DegreeProgram degree;
};







#endif /* STUDENT_H_ */
