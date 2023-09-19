/*
 * student.cpp
 *
 *  Created on: Jul 19, 2022
 *      Author: andrewstephens
 */

#include "student.h"
#include <iostream>
using std::string;

// CONSTRUCTORS //
//blank student init //


Student::Student() : studentID(""), firstName(""), lastName(""), emailAddress(""), studentAge(-1), daysInCourse(new int[DAYS_SIZE]), degree(){
	for (int i = 0; i < DAYS_SIZE; ++i){
		this->daysInCourse[i] = 0;
	}
}

// create student obj using mutators

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degree)
{
	setStudentID(studentID);
	setFName(firstName);
	setLName(lastName);
	setEmailAddress(emailAddress);
	setStudentAge(age);
	setDaysInCourse(numDays);
	setDegree(degree);

}

// GETTERS

string Student::getStudentID() const {
	return studentID;
}
string Student::getFName() const {
	return firstName;
}
string Student::getLName() const {
	return lastName;
}
string Student::getEmailAddress() const {
	return emailAddress;
}
int Student::getStudentAge() const {
	return studentAge;
}
int* Student::getDaysInCourse() const {
	return daysInCourse;
}
DegreeProgram Student::getDegree(){
	return degree;
}


// SETTERS

void Student::setStudentID(string studentID){
	this->studentID = studentID;
}
void Student::setFName(string firstName){
	this->firstName = firstName;
}
void Student::setLName(string lastName){
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress){
	this->emailAddress = emailAddress;
}
void Student::setStudentAge(int age){
	this->studentAge = age;
}
void Student::setDaysInCourse(int numDays[]){
	this->daysInCourse = new int[DAYS_SIZE];
	for (int i = 0; i < DAYS_SIZE; ++i){
		this->daysInCourse[i] = numDays[i];
	}
}
void Student::setDegree(DegreeProgram degree){
	this->degree = degree;
}


//print student record

void Student::Print(){
	std::cout << getStudentID();
	std::cout << "\tFirst Name: " << getFName();
	std::cout << "\tLast Name: " << getLName();
	std::cout << "\tEmail Address: " << getEmailAddress();
	std::cout << "\tAge: " << getStudentAge();
	int* days = getDaysInCourse();
	std::cout << "\t \tDays in courses: ";
	for (int i = 0; i < DAYS_SIZE; ++i){
		std::cout << days[i] << " ";
	}


	// using switch to check use cases and assign degree to degreeprogram variable then print
	string degreeString = "";
	switch (getDegree()) {
	case DegreeProgram::SECURITY:
		degreeString = "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		degreeString = "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	}
	std::cout << "\tDegree: " << degreeString << std::endl;
}

// DECONSTRUCTOR

Student::~Student(){}




