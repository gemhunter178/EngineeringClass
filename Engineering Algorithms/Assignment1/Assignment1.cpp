/*
Eng Algorithms, ASSIGNMENT 1
Author: [me]
ID: [ID withheld]
Description: Basic OOD review. 
Functions as a rudimentary student organizer for classes
Comments of class variables and functions taken from the assignement
How to run: Make sure header files "Assign1Header.h", "getInput.h", 
the corresponding source files and the makefile are in the same folder, 
compile using the provided makefile and run "./Assignment1"
Current main function tests a single, rewriteable, courseSection class
*/
//input, output and string libraries needed
#include <iostream>
#include <string>
//header file for class definitions
#include "Assign1Header.h"
//header file for "as for input" functions
#include "getInput.h"

//Declared classes are all in Assign1Header.h

//getInput functions are in getInput.h

/* UNUSED as selectionsort was implemented in CourseSection::fillRosterInfo(); 
//function to sort things, template-ized for use in more than just sorting students by alphabetical order
template <class T>
//going to use selectionsort as it's easy to implement
void selectionSort(T usortArray[], int size) {
	//get array size if not defined
	if (size <= 0) {
		size = sizeof(usortArray) / sizeof(*(usortArray));
		//debug
		std::cout << "size not defined, detected size of" << size << std::endl;
	}	

}*/

int main() {
	//entering data for the section
	std::string courseID = getInput("course ID");
	std::string courseTitle = getInput("course title");
	int courseCred = getIntInput("total course credits");
	int classSize = getIntInput("the number of students in this class");

	CourseSection test(courseID, courseTitle, courseCred, classSize);

	//tell user that they are entering roster info now
	std::cout << std::endl << "Course Configuration complete, please start entering the information for the students in the course:" << std::endl;
	test.fillRosterInfo();
	//inform they are done
	std::cout << std::endl << "Roster filled." << std::endl;
	//test.printSectionInfo();
	//debug "menu"
	int input;
	//to allow an exit of the loop
	bool cont = true;
	while (cont) {
		std::cout << std::endl << "What would you like to do now? type:" << std::endl
			<< "1 to overwrite roster" << std::endl
			<< "2 to print section info" << std::endl
			<< "3 to find the average GPA" << std::endl
			<< "4 to show the youngest student" << std::endl
			<< "5 to end the program" << std::endl << std::endl;
		//take input
		std::cin >> input;
		//ignore newline
		std::cin.ignore();
		//switch for menu functions
		switch (input) {
			case 1:
				//redundant, possibly unessessary to avoid edge cases where the program skips the option to abort
				input = 0;
				//as this might involve a lot of re-done work, an option to abort is included
				std::cout << "This is irreversable - Are you sure? (type 1 for yes, 0 for no): " << std::endl;
				//get input again
				std::cin >> input;
				std::cin.ignore();
				//only activates if user wants to continue
				if (input == 1) {
					test.fillRosterInfo();
				}
				break;
			case 2:
				test.printSectionInfo();
				break;
			case 3:
				test.printAverageGPA();
				break;
			case 4:
				test.printYoungestStudent();
				break;
			case 5:
				cont = false;
				std::cout << "Quitting application";
				break;
			default:
				//print error
				std::cout << "Input not recognized, please try again" << std::endl;
				break;
		}
	}

	//return no error if it gets here
	return 0;
}

//Functions defined in corresponding .cpp files (same name as headers with a .cpp file type)
