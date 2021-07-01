/*
Definitions for the functions declared in -.h file
AUTHOR: [me]
*/
//required libraries
#include <iostream>
#include <string>

//header file that declared these functions
#include "getInput.h"

//function to ask for input and returns string
std::string getInput(std::string item) {
	//ask for item
	std::cout << "Please enter " + item + ":" << std::endl;
	//string to place things in for now
	std::string temp;
	std::getline(std::cin, temp);
	//return string
	return temp;
}
//separate function to handle ints (tried to template this function but had other issues implementing)
int getIntInput(std::string item) {
	//int to place things in
	int temp;
	//ask for item
	std::cout << "Please enter " + item + ", as an integer:" << std::endl;
	//place and return the int
	std::cin >> temp;
	//ignore newlines
	std::cin.ignore();
	return temp;
}