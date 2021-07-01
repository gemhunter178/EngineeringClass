/*
Assign1Header headerfile
AUTHOR: [me]
Declares classes required for Assignment 1 of EECE 2560
Requires <string>
*/
#pragma once
#ifndef ASSIGN1HEADER_H
#define ASSIGN1HEADER_H

//creating class "Person"
class Person {
private:
	std::string fullname;//the person’s last name followed by first name
	std::string address; //address
	int age;
public:
	//functions will be declared here, and defined after main
	void readPersonInfo(); //fills the above three private attributes by keyboard input operations 
	void printPersonInfo(); //displays the above three private attributes 
	int personAGE(); //returns the person’s age 
	std::string personName(); //returns the person’s fullname 
};

//creating class "Student" that is a child of "Person"
class Student : public Person {
private:
	std::string ID;
	std::string major;
	float gpa;
public:
	//as with parent, these functions defined after main
	void readStudentInfo(); //first calls the base class function: readPersonInfo, then fills the student’s three private attributes by keyboard input operations 
	void printStudentInfo(); //first invokes the base class function printPersonInfo, then prints the student’s three private attributes.
	float studentGPA(); //returns the student’s GPA
};

//class "Course"
class Course {
private:
	std::string ID;
	std::string title;
	int credits;
public:
	//defined after main
	//constructor (allows default, and tells user that these should have been filled in)
	Course();
	//constructor with allowing direct write to private variables
	Course(std::string, std::string, int);
	//destructor
	virtual ~Course();
	void printCourseInfo(); //displays the Course's three private attributes
};

//class "CourseSection" that is a child of "Course"
class CourseSection :public Course {
private:
	int sectionSize; //Number of students enrolled in the section
					 /*to store a list of Student objects representing the students enrolled in the section.
					 This list should be always sorted by the students’ full name in alphabetical order*/
	Student *roster;
public:
	//functions all defined after main
	//constructor (default)
	CourseSection();
	//constructor with section size
	CourseSection(std::string, std::string, int, int);
	//destructor
	virtual ~CourseSection();
	/*read the info of all students in the section one at a time, using readStudentInfo().
	After reading the info of a student object, insert it in the roster list.
	Make sure to insert every new student object in the correct place in the list so that the list is always sorted by the students’ full name */
	void fillRosterInfo();
	void printSectionInfo(); //prints the section info starting with its course info, followed by printing the info of all students in the section
	void printAverageGPA(); //prints the average GPA of the students in the section
	void printYoungestStudent(); //prints info of youngest student in class
};

#endif // !ASSIGN1HEADER_H
