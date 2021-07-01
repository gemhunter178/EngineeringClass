/*
Assign2Classes headerfile
AUTHOR: [me]
Declares classes required for Assignment 2 of EECE 2560
Requires <string>
*/
#pragma once
#ifndef ASSIGN2CLASSES_H
#define ASSIGN2CLASSES_H

//creating class "Person"
class Person {
private:
	//the person’s last name followed by first name
	std::string fullname;
	//address
	std::string address; 
	int age;
public:
	//functions will be declared here, and defined in corresp. .cpp file
	//fills the above three private attributes from the text file through its file stream pointer pf
	void readPersonInfo(std::ifstream* pf); 
	//displays the above three private attributes 
	void printPersonInfo(); 
	//returns the person’s age 
	int personAGE(); 
	//returns the person’s fullname 
	std::string personName(); 
};

//creating class "Student" that is a child of "Person"
class Student : public Person {
private:
	std::string ID;
	std::string major;
	float gpa;
public:
	//as with parent, these functions defined in corresponding .cpp file
	void readStudentInfo(std::ifstream* sf); //first calls the base class function: readPersonInfo, then fills the student’s three private attributes from the text file
	//first invokes the base class function printPersonInfo, then prints the student’s three private attributes.
	void printStudentInfo(); 
	//returns the student’s GPA
	float studentGPA(); 
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
	//Number of students enrolled in the section
	int sectionSize; 
	/*to store a list of Student objects representing the students enrolled in the section.
	This list does not need to be sorted*/
	Student *roster;
	//list of pointers to the Student objects in thwe roster, sorted by name
	Student* *sortedNames;
	//list of pointers to the Student objects in thwe roster, sorted by age
	Student* *sortedAges;
	//list of pointers to the Student objects in thwe roster, sorted by GPA
	Student* *sortedGPAs;
	/*arrange the pointers in sortedNames to access the students’
	records in an alphabetical order of their name.*/
	void sortNames(); 
	/*arrange the pointers in sortedAges to access the students’
	records in an ascending order of their age.*/
	void sortAges(); 
	/*arrange the pointers in sortedGPAs to access the students’
	records in a descending order of their gpa.*/
	void sortGPAs(); 
public:
	//functions all defined after main
	//constructor (default)
	CourseSection();
	//constructor with section size
	CourseSection(std::string, std::string, int, int);
	//destructor
	virtual ~CourseSection();
	/*read the info of all students in the section from the text file through its
	file stream pointer rf by calling readStudentInfo(ifstream* sf).
	Read the info in the order given in the file and no need to insert them sorted in the
	roster list. Also, fill the sortedNames, sortedAges, and sortedGPAs arrays with
	pointers to the students’ objects you just inserted in roster. Finally, call the methods
	sortNames(), sortAges(), and sortGPAs().*/
	void fillRosterInfo(std::ifstream *rf);
	/*print the section info starting with its course info, followed by printing, in a       
	tabular format, the students’ info through the pointers in the sortedNames array.*/
	void printSectionInfoByName();
	/*print the section info starting with its course info, followed by printing, in a
	tabular format, the students’ info through the pointers in the sortedAges array.*/
	void printSectionInfoByAge();
	/*print the section info starting with its course info, followed by printing, in a
	tabular format, the students’ info through the pointers in the sortedGPAs array.*/
	void printSectionInfoByGPA();
	/*Old from assignment 1
	//prints the section info starting with its course info, followed by printing the info of all students in the section
	void printSectionInfo(); 
	//prints the average GPA of the students in the section
	void printAverageGPA(); 
	//prints info of youngest student in class
	void printYoungestStudent();  */
};

#endif // !ASSIGN2CLASSES_H
