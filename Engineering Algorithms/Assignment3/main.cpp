/*
Eng Algorithms, ASSIGNMENT 3
Author: [me]
ID: [ID withheld]
Description: 
How to run: Make sure header files "Dec2Bin.h" and "ArrayStack.h"
the corresponding source files and the makefile are in the same folder,
compile using the provided makefile and run "./Assignment3"
*/

//need input/output stream
#include <iostream>

//include StackInterface and Array Implementation of Stack from slides
//#include "ArrayStack.h"

//header file for Dec2Bin class
#include "Dec2Bin.h"


//main taken from assignment document
int main() {
	//make object of class Dec2Bin
	Dec2Bin db;
	//enter a number
	db.readDecNum();
	//output recursive result
	std::cout << "The binary number using recursive method = ";
	db.dec2bin_rcv(db.decNum);
	//output iterative result
	std::cout << "\nThe binary number using iterative method = ";
	db.dec2bin_itr();
	
	//stop to see output (debug)
	std::cout << "\nEnter anything to exit ";
	//ignore value
	int ignore;
	std::cin >> ignore;

	return 0;
}