/*
Name: Lab 1
Author: [me]
Date edited: 2019/01/16
Desc: The Pre-Lab for Lab 1: Provides a menu for the following lab using the "switch" control structure
*/

#include <iostream>

//Declare other two required functions
void Initialize();
void Finalize();

//global variables
double *v;
int count;
int size;

//main function
int main(){
	//initialize global variables
	Initialize();
	//declare input variable
	int input;
	//declare valid bool (false if input unrecognized)
	bool valid;
	//run at least once: shows menu, allows user input
	do{
		//write out the menu
		std::cout<<"Main Menu" << std::endl << std::endl;
		std::cout<<"1. Print the array" << std::endl;
		std::cout<<"2. Append element at the end" << std::endl;
		std::cout<<"3. Remove last element" << std::endl;
		std::cout<<"4. Insert one element" << std::endl;
		std::cout<<"5. Exit" << std::endl << std::endl;
		//first selection instruction
		std::cout<<"Select an option: ";
		std::cin>>input;
		//switch to show what the user selected, or exit, or invalid error message
		switch(input){
			case 1: 
				std::cout<<"You selected \"Print the array\"" << std::endl << std::endl;
				valid = true;
				break;
			case 2: 
				std::cout<<"You selected \"Append element at the end\"" << std::endl << std::endl;
				valid = true;
				break;
			case 3: 
				std::cout<<"You selected \"Remove last element\"" << std::endl << std::endl;
				valid = true;
				break;
			case 4: 
				std::cout<<"You selected \"Insert one element\"" << std::endl << std::endl;
				valid = true;
				break;
			case 5: 
				//exits the program. Return 1 to indicate this end condition was met
				return 1;
			default:
				//if no other case fit, option is invalid.
				std::cout<<"That is not a valid option" << std::endl << std::endl;
				valid = false;
				break;	
		}
	//for now, run until "exit"
	}while(true/*valid == false*/);
	
	//options after the input is valid
	//for now....
	Finalize();
	return 0;
}

//define other two functions
void Initialize(){
	count = 0;
	size = 2;
	v = new double[size];
}
void Finalize(){
	delete[] v;
}
