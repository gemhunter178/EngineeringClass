/*
Eng Algorithms, ASSIGNMENT 2
Author: [me]
ID: [ID withheld]
Description: Extension of Assignment 1, with file reading
Functions as a rudimentary student organizer for classes
Comments of class variables and functions taken from the assignement
How to run: Make sure header files "Assign2Classes.h", "getInput.h", 
the corresponding source files and the makefile are in the same folder, 
compile using the provided makefile and run "./Assignment2"
Current main function reads from "c:\\temp\\section01.txt" and displays the roster in the same order as in the example.
*/
//input, output and string libraries needed
#include <iostream>
#include <string>
//ifstream for part 2
#include <fstream>
//needed to make a neat output regardless of size of name/address/etc. entered
#include <iomanip>
//header file for class definitions
#include "Assign2Classes.h"
//header file for "as for input" functions
#include "getInput.h"
//(still used in the beginning of main())

//Declared classes are all in Assign2Classes.h

//getInput functions are in getInput.h

int main() {
	//getting ifstream data
	std::ifstream sectionFile;
	//attempt to open the file
	sectionFile.open("c:\\temp\\section01.txt");
	//local file in same folder
	if (sectionFile.fail()) {
		std::cerr << "Could not open section01.txt! Did you place the file in the right location?" << std::endl;
		exit(1);
	}
	//from the example to activate exception handling
	sectionFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); //activate the exception handling of inf stream 
	//entering data for the section
	std::string courseID = getInput("course ID");
	std::string courseTitle = getInput("course title");
	int courseCred = getIntInput("total course credits");
	int classSize = getIntInput("the number of students in this class");

	//create CourseSection based on input
	CourseSection test(courseID, courseTitle, courseCred, classSize);
	//fill roster and sort the students
	test.fillRosterInfo(&sectionFile);
	//test if the sort and print functions work/worked
	test.printSectionInfoByName();
	test.printSectionInfoByAge();
	test.printSectionInfoByGPA();
	//debug (wait before exit)
	/*std::cout << "Enter a '1' to exit.";
	//check for exit
	char temp = 0;
	while (temp != '1') {
		std::cin >> temp;
	}*/
	
	
	//close file
	sectionFile.close();
	

	//return no error if it gets here
	return 0;
}

//Functions defined in corresponding .cpp files (same name as headers with a .cpp file type)
