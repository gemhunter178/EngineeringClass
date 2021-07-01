/*
Definitions for the functions declared in -.h file
AUTHOR: [me]
*/
//required libraries
#include <iostream>
#include <string>
//extra for INT_MAX
#include <climits>
//header file that declares these classes
#include "Assign1Header.h"
//the getInput functions are also used here
#include "getInput.h"

//START DEFINING FUNCTIONS
//Functions for class "Person"
void Person::readPersonInfo() {
	//this needs to accept input from user and place into private variables.
	//ask for full name
	fullname = getInput("full name");
	//ask for address
	address = getInput("address");
	//ask for age
	age = getIntInput("age");
	//return
	return;
}

void Person::printPersonInfo() {
	//prints out person's info
	std::cout << "Name: " + fullname << std::endl;
	std::cout << "Address: " + address << std::endl;
	std::cout << "Age:" << age << std::endl;
	//return
	return;
}

int Person::personAGE() {
	//returns private integer age
	return age;
}

std::string Person::personName() {
	//returns private string name
	return fullname;
}

//Functions for subclass "Student"
void Student::readStudentInfo() {
	//first call the readPersonInfo function
	readPersonInfo();
	//then ask for extra variables
	ID = getInput("ID");
	major = getInput("major");
	//this one has no function as it is a float, so it is written out.
	//ask for GPA
	std::cout << "Please enter GPA (as a Float):" << std::endl;
	//put input into GPA private variable
	std::cin >> gpa;
	//ignore newline
	std::cin.ignore();
	//return
	return;
}

void Student::printStudentInfo() {
	//invoke printPersonInfo()
	printPersonInfo();
	//then print the other information fo the student
	std::cout << "ID: " + ID << std::endl;
	std::cout << "major: " + major << std::endl;
	std::cout << "gpa: " << gpa << std::endl;
}

float Student::studentGPA() {
	//return GPA
	return gpa;
}

//class "Course" functions
Course::Course() {
	//this default shouldn't have been invoked
	//state an error
	std::cout << "Creating an object of 'Course' required additional variables. Please create one in the form <Name>(<ID>, <TITLE>, <CREDITS>) in the form string, string, int";
	delete this; //this should delete this improperly initiated object.
	return;
}

//correct form of creating a "Course"
Course::Course(std::string enterID, std::string enterTitle, int enterCredits) {
	//initiates said values into private variables
	ID = enterID;
	title = enterTitle;
	credits = enterCredits;
}

//destructor
Course::~Course() {
	//debug for now
	//std::cout << "Course destroyed";
}

void Course::printCourseInfo() {
	//prints private variables in "Course"
	//first line for organization:
	std::cout << "Course Information:" << std::endl;
	std::cout << "ID: " + ID << std::endl;
	std::cout << "title: " + title << std::endl;
	std::cout << "credits: " << credits << std::endl << std::endl;
	return;
}

//Functions for CourseSection
CourseSection::CourseSection() {
	//this default shouldn't have been invoked
	//state an error
	std::cout << "Creating an object of 'CourseSection' required additional variables. Please create one in the form <Name>(<ID>, <TITLE>, <CREDITS>, <ClASSSIZE>) in the form string, string, int, int";
	delete this; //this should delete this improperly initiated object.
	return;
}

//Correct CourseSection constructor
CourseSection::CourseSection(std::string enterID, std::string enterTitle, int enterCredits, int classSize)
//this should first invoke the parent constructor?
	: Course(enterID, enterTitle, enterCredits) {
	sectionSize = classSize;
	//allocate array of students
	roster = new Student[sectionSize];
}
//destructor
CourseSection::~CourseSection() {
	//debug
	//std::cout << "CourseSection destroyed";
	//delete the array created
	delete[]roster;
}

void CourseSection::fillRosterInfo() {
	//According to the example, the instructions should be outside this function, in main.
	//loop through creating students until the roster is full
	//debug
	//std::cout << "Filling Roster Info"<< std::endl;
	int i, j, k;
	for (i = 0; i < sectionSize; i++) {
		//debug that is now part of the code for organization
		std::cout << std::endl << "Enter information for student #" << i + 1 << std::endl; //i+1 for readability
																						   //create students
		roster[i].readStudentInfo();
		//sort as you go, using a version of insertion sort
		for (j = 0; j < i; j++) {
			//if the current name is alphabetically ahead, shift rest of the array backwards
			if (roster[i].personName() < roster[j].personName()) {
				//place current student in a temp slot
				Student temp = roster[i];
				//shift all students forward
				for (k = i; k > j; k--) {
					roster[k] = roster[k - 1];
				}
				roster[j] = temp;
				//should be sorted and could continue to the next student
				break;
			}
			//if this never gets triggered, the new entry stays at the back of the array
		}
		//debug to see if sorting correctly
		//printSectionInfo();
	}
	return;
}

void CourseSection::printSectionInfo() {
	//first evoke the parent class's printCourseInfo
	printCourseInfo();
	//then print all the student's info
	int i;
	for (i = 0; i < sectionSize; i++) {
		//actual print part, hopefully alphabetical
		roster[i].printStudentInfo();
		//make more readable
		std::cout << std::endl;
	}
	return;
}

void CourseSection::printAverageGPA() {
	int i;
	//total
	float total = 0;
	//go through all the students
	for (i = 0; i < sectionSize; i++) {
		total += roster[i].studentGPA();
	}
	//find average
	total = total / sectionSize;
	//print average
	std::cout << "The average GPA of the class is " << total << std::endl;
	return;
}

void CourseSection::printYoungestStudent() {
	//initialize variables to run the for loop and to store the youngest person's name and age
	int i;
	int yAge = INT_MAX;//this should always be older than someone in the class unless they overflow the integer.
	std::string yPerson;
	//bool for plurality (if there are more than one person for youngest age)
	bool plural;
	std::string studentPl = "student is "; //default is singular
										   //loop through all and find youngest person
	for (i = 0; i < sectionSize; i++) {
		//test if younger
		if (roster[i].personAGE() < yAge) {
			yAge = roster[i].personAGE();
			yPerson = roster[i].personName();
			//if this happens there is only currently one younger student, plural is false
			plural = false;
		}
		else if (roster[i].personAGE() == yAge) { //but there's also a case where they are equal
												  //yAge is still unchanged in this case
												  //using some concat to make the output look good
			yPerson = yPerson + " and " + roster[i].personName();
			//now there are more than one person
			plural = true;
		}

		//handling plurals
		if (plural) {
			//if plural is true, make string "students"
			studentPl = "students are ";
		}
		else {
			//else keep singular
			studentPl = "student is ";
		}
	}
	//output sentence
	std::cout << "The youngest " + studentPl + yPerson + " with an age of " << yAge << std::endl;
	return;
}