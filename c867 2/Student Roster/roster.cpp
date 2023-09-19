/*
 * roster.cpp
 *
 *  Created on: Jul 19, 2022
 *      Author: andrewstephens
 */


#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using std::string;


// creating new student objects

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree){

	int numDays[] = {days1, days2, days3};

	classRosterArray[++index] = new Student();
	classRosterArray[index]->setStudentID(studentID);
	classRosterArray[index]->setFName(firstName);
	classRosterArray[index]->setLName(lastName);
	classRosterArray[index]->setEmailAddress(emailAddress);
	classRosterArray[index]->setStudentAge(age);
	classRosterArray[index]->setDaysInCourse(numDays);
	classRosterArray[index]->setDegree(degree);

	}


// parses data from studentdata and input to roster class

void Roster::ClassRosterParse(string record){
	std::vector<string> tokens;
	DegreeProgram testDegree;
		{
		std::stringstream ss(record);

		while (ss.good()){
			string subStr;
			std::getline(ss, subStr, ',');
			tokens.push_back(subStr);
		}

		if (tokens[8] == "SECURITY"){
						testDegree = DegreeProgram::SECURITY;
					}
					if (tokens[8] == "NETWORK"){
						testDegree = DegreeProgram::NETWORK;
					}
					if (tokens[8] == "SOFTWARE"){
						testDegree = DegreeProgram::SOFTWARE;
					}
		}
	Roster::Add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), stoi(tokens.at(4)), stoi(tokens.at(5)), stoi(tokens.at(6)), stoi(tokens.at(7)), testDegree);
}

// remove student from roster

void Roster::Remove(string studentID){
	std::cout << "Removing student record with student ID: " << studentID << "..." << std::flush;
	for (int j = 0; j < TOTAL_STUDENTS; ++j){
		if (classRosterArray[j] == nullptr){
			std::cout << "...student does not exist!" << std::endl;
			break;
		}
		else if (studentID == classRosterArray[j]->Student::getStudentID()){
					classRosterArray[j] = nullptr;
					std::cout << "Student record removed!" << std::endl;
				}
	}
}

// retrieves number of days array and averages days and outputs
void Roster::PrintAvgDaysInCourse(string studentID){
	for (int h = 0; h < TOTAL_STUDENTS; ++h){
		if (studentID == classRosterArray[h]->Student::getStudentID()){
			int* days = classRosterArray[h]->getDaysInCourse();
			std::cout << studentID << "'s average days in course: ";
			int avgDays = (days[0] + days[1] + days[2]) /3;
			std::cout << avgDays << std::endl;
		}

	}
}

// print all current students in the roster
void Roster::PrintAll(){
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		if (classRosterArray[i] != nullptr){
			classRosterArray[i] -> Student::Print();
		}
	}
}



// print emails that have a space or are lacking a '@' or '.'

void Roster::PrintInvalidEmails(){
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		bool foundSpace = false;
		bool foundAt = false;
		bool foundPeriod = false;
		string email = "";
		email = classRosterArray[i]->Student::getEmailAddress();

		for (char &charIndex : email){
			if (charIndex == '@'){
				foundAt = true;
			}
			if (charIndex == '.'){
				foundPeriod = true;
			}
			if (charIndex == ' '){
				foundSpace = true;
			}
		}
		if (foundAt == false || foundPeriod == false || foundSpace == true){
			std::cout << classRosterArray[i]->Student::getEmailAddress() << std::endl;
		}
	}
}

// print by degree program
void Roster::PrintByDegreeProgram(DegreeProgram degree){
	std::cout << std::endl << "Printing by degree..." << std::endl;
	for (int i = 0; i < TOTAL_STUDENTS; ++i){
		if (classRosterArray[i] != nullptr){
			if (degree ==classRosterArray[i]->Student::getDegree()){
				classRosterArray[i]->Student::Print();
			}
		}
	}
}

Roster::~Roster(){}
