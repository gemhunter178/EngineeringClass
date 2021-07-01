/*
Definitions for the functions declared in -.h file
AUTHOR: [me]
*/
//required libraries
#include <iostream>
#include <string>
//extra for INT_MAX
#include <climits>
//assignment 2: ifstream stuff
#include <fstream>
//header file that declares these classes
#include "Assign2Classes.h"
//the getInput functions are also used here
#include "getInput.h"

//START DEFINING FUNCTIONS
//Functions for class "Person"
void Person::readPersonInfo(std::ifstream* sectionfile) {
	//this needs to accept input from user and place into private variables.
	//get for full name
	std::getline(*sectionfile,fullname);
	//get for address
	std::getline(*sectionfile, address);
	//temp string before converting
	std::string tempString;
	//get for age
	std::getline(*sectionfile, tempString);
	//convert and place age into age variable
	age = std::stoi(tempString);
	//return
	return;
}

void Person::printPersonInfo() {
	//prints out person's info
	std::cout << "Name:\t" << fullname << "\n";
	std::cout << "Addr:\t" << address << "\n";
	std::cout << "Age:\t" << age << "\n";
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
void Student::readStudentInfo(std::ifstream* sectionfile) {
	//first call the readPersonInfo function
	readPersonInfo(sectionfile);
	//then get the other variables
	std::getline(*sectionfile, ID);
	std::getline(*sectionfile, major);
	//get for GPA
	//needs a tempString for getline before converting
	std::string tempString;
	std::getline(*sectionfile, tempString);
	//convert to float
	gpa = stof(tempString);
	//return
	return;
}

void Student::printStudentInfo() {
	//invoke printPersonInfo()
	printPersonInfo();
	//then print the other information fo the student
	std::cout << "ID:\t" << ID << "\n";
	std::cout << "Major:\t" << major << "\n";
	std::cout << "GPA:\t" << gpa << "\n";
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
	std::cout << "credits: " << credits << std::endl;
	return;
}

void CourseSection::sortNames()
{
	//ints for the for loops
	int i, j, k;
	for (i = 0; i < sectionSize; i++) {
		//debug line
		//std::cout << std::endl << "Sorting name for student #" << i + 1 << std::endl; //i+1 for readability
		//place current student into the array of student pointers
		sortedNames[i] = &roster[i];
		//sort as this looks through the roster, using a version of insertion sort
		for (j = 0; j < i; j++) {
			//if the current name is alphabetically ahead, shift rest of the array backwards
			if (sortedNames[i]->personName() < sortedNames[j]->personName()) {
				//place current student pointer in a temp slot
				Student* temp = sortedNames[i];
				//shift all students pointers forward
				for (k = i; k > j; k--) {
					sortedNames[k] = sortedNames[k - 1];
				}
				sortedNames[j] = temp;
				//should be sorted and could continue to the next student
				break;
			}
			//if this never gets triggered, the new entry stays at the back of the array
		}
	}
}

void CourseSection::sortAges()
{
	//ints for the for loops
	int i, j, k;
	for (i = 0; i < sectionSize; i++) {
		//debug line
		//std::cout << std::endl << "Sorting age for student #" << i + 1 << std::endl; //i+1 for readability
																					  //place current student into the array of student pointers
		sortedAges[i] = &roster[i];
		//sort as this looks through the roster, using a version of insertion sort
		for (j = 0; j < i; j++) {
			//if the current age is smaller, shift rest of the array backwards
			if (sortedAges[i]->personAGE() < sortedAges[j]->personAGE()) {
				//place current student pointer in a temp slot
				Student* temp = sortedAges[i];
				//shift all students pointers forward
				for (k = i; k > j; k--) {
					sortedAges[k] = sortedAges[k - 1];
				}
				sortedAges[j] = temp;
				//should be sorted and could continue to the next student
				break;
			}
			//if this never gets triggered, the new entry stays at the back of the array
		}
	}
}

void CourseSection::sortGPAs()
{
	//ints for the for loops
	int i, j, k;
	for (i = 0; i < sectionSize; i++) {
		//debug line
		//std::cout << std::endl << "Sorting GPA for student #" << i + 1 << std::endl; //i+1 for readability
																					  //place current student into the array of student pointers
		sortedGPAs[i] = &roster[i];
		//sort as this looks through the roster, using a version of insertion sort
		for (j = 0; j < i; j++) {
			//if the current GPA is higher, shift rest of the array backwards
			if (sortedGPAs[i]->studentGPA() > sortedGPAs[j]->studentGPA()) {
				//place current student pointer in a temp slot
				Student* temp = sortedGPAs[i];
				//shift all students pointers forward
				for (k = i; k > j; k--) {
					sortedGPAs[k] = sortedGPAs[k - 1];
				}
				sortedGPAs[j] = temp;
				//should be sorted and could continue to the next student
				break;
			}
			//if this never gets triggered, the new entry stays at the back of the array
		}
	}
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
	//allocate arrays of students
	roster = new Student[sectionSize];
	sortedNames = new Student*[sectionSize];
	sortedAges = new Student*[sectionSize];
	sortedGPAs = new Student*[sectionSize];
}
//destructor
CourseSection::~CourseSection() {
	//debug
	//std::cout << "CourseSection destroyed";
	//delete the array created
	delete[]roster;
	//delete the other arrays made
	delete[]sortedNames;
	delete[]sortedAges;
	delete[]sortedGPAs;
}

void CourseSection::fillRosterInfo(std::ifstream *sectionfile) {
	//According to the example, the instructions should be outside this function, in main.
	//loop through creating students until the roster is full
	//does not have a sort within this function
	//debug
	//std::cout << "Filling Roster Info"<< std::endl;
	int i;
	for (i = 0; i < sectionSize; i++) {
		//debug that is now removed as it reads from a file.
		//std::cout << std::endl << "Enter information for student #" << i + 1 << std::endl; //i+1 for readability
																						   //create students
		roster[i].readStudentInfo(sectionfile);
		//debug
		//roster[i].printStudentInfo();
	}
	//call the fucntions to sort the roster
	sortNames();
	sortAges();
	sortGPAs();
	return;
}

void CourseSection::printSectionInfoByName()
{
	//print a line to say this is by name:
	std::cout << "Section info sorted by student's names: \n=======================================\n";
	//evoke the parent class's printCourseInfo
	printCourseInfo();
	//organization
	std::cout << "======================================= \n";
	//print organization like example
	//unfortunately will be "off" if longer data is used
	//std::cout << std::left << std::setw(8) << "Seq" << std::setw(16) << "Name" << std::setw(16) << "Address" << std::setw(8) << "Age" << std::setw(16) << "ID" << std::setw(8) << "Major" << "GPA\n";
	//print the divider bunch
	//std::cout << std::left << std::setw(8) << "===" << std::setw(16) << "====" << std::setw(16) << "=======" << std::setw(8) << "===" << std::setw(16) << "==" << std::setw(8) << "=====" << "===\n";
	//then print all the student's info
	int i;
	for (i = 0; i < sectionSize; i++) {
		//print seq number (like example)
		std::cout << "Seq#\t" << i + 1 << "\n";
		//actual print part, hopefully alphabetical
		sortedNames[i]->printStudentInfo();
		//make more readable
		std::cout << std::endl;
	}
	//separate from future outputs
	std::cout << std::endl;
	return;
}

void CourseSection::printSectionInfoByAge()
{
	//print a line to say this is by age:
	std::cout << "Section info sorted by student's ages: \n=======================================\n";
	//evoke the parent class's printCourseInfo
	printCourseInfo();
	//organization
	std::cout << "======================================= \n";
	//print organization like example
	//unfortunately will be "off" if longer/shorter data is used
	//std::cout << std::left << std::setw(8) << "Seq" << std::setw(16) << "Name" << std::setw(16) << "Address" << std::setw(8) << "Age" << std::setw(16) << "ID" << std::setw(8) << "Major" << "GPA\n";
	//print the divider bunch
	//std::cout << std::left << std::setw(8) << "===" << std::setw(16) << "====" << std::setw(16) << "=======" << std::setw(8) << "===" << std::setw(16) << "==" << std::setw(8) << "=====" << "===\n";
	//then print all the student's info
	int i;
	for (i = 0; i < sectionSize; i++) {
		//print seq number (like example)
		std::cout << "Seq#\t" << i + 1 << "\n";
		//actual print part, by Age
		sortedAges[i]->printStudentInfo();
		//make more readable
		std::cout << std::endl;
	}
	//separate from future outputs
	std::cout << std::endl;
	return;
}

void CourseSection::printSectionInfoByGPA()
{
	//print a line to say this is by GPA:
	std::cout << "Section info sorted by student's GPAs: \n=======================================\n";
	//evoke the parent class's printCourseInfo
	printCourseInfo();
	//organization
	std::cout << "======================================= \n";
	//print organization like example
	//unfortunately will be "off" if longer/shorter data is used
	//std::cout << std::left << std::setw(8) << "Seq" << std::setw(16) << "Name" << std::setw(16) << "Address" << std::setw(8) << "Age" << std::setw(16) << "ID" << std::setw(8) << "Major" << "GPA\n";
	//print the divider bunch
	//std::cout << std::left << std::setw(8) << "===" << std::setw(16) << "====" << std::setw(16) << "=======" << std::setw(8) << "===" << std::setw(16) << "==" << std::setw(8) << "=====" << "===\n";
	//then print all the student's info
	int i;
	for (i = 0; i < sectionSize; i++) {
		//print seq number (like example)
		std::cout << "Seq#\t" << i + 1 << "\n";
		//actual print part, by GPA
		sortedGPAs[i]->printStudentInfo();
		//make more readable
		std::cout << std::endl;
	}
	//separate from future outputs
	std::cout << std::endl;
	return;
}

/*old from hw1
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
*/