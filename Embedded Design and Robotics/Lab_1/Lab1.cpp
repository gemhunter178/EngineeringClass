/*
Name: Lab 1
Author: [me]
Date edited: 2019/01/17
Desc: The Code for Lab 1: Provides a menu for the following lab using the "switch" control structure and option
*/

#include <iostream>

//Declare other two required functions
void Initialize();
void Finalize();
//int arg as this grow function can grow the vector to a specified size of that int
void Grow(int);
void AddElement();
void PrintVector();
void RemoveElement();
void InsertElement();
void Shrink();

//initialize global variables
double *v;
int count;
int size;

//main function
int main(){
	//initialize global variables
	Initialize();
	//declare input variable
	int input;
	//run until user chooses exit
	while(true){
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
				PrintVector();
				break;
			case 2: 
				std::cout<<"You selected \"Append element at the end\"" << std::endl << std::endl;
				AddElement();
				break;
			case 3: 
				std::cout<<"You selected \"Remove last element\"" << std::endl << std::endl;
				RemoveElement();
				//EC: If statement for invoking shrink or not
				if((count + 0.0)/size <= 0.30){
					//call shrink if so
					Shrink();
				}
				break;
			case 4: 
				std::cout<<"You selected \"Insert one element\"" << std::endl << std::endl;
				InsertElement();
				break;
			case 5: 
				//deallocate data
				Finalize();
				//exits the program. Return 0 to indicate this end condition was met
				return 0;
			default:
				//if no other case fit, option is invalid.
				std::cout<<"That is not a valid option" << std::endl << std::endl;
				break;	
		}
	//run until "exit"
	}
	//just in case the code somehow gets here
	return 1;
}

//define other two functions
void Initialize(){
	count = 0;
	size = 2;
	v = new double[size];
}

//delete v
void Finalize(){
	delete[] v;
}

//function to grow the "vector"
void Grow(int growto){
	//cout "Vector grown"
	std::cout<< "Vector grown" <<std::endl;
	//cout the old size
	std::cout<< "Previous capacity: " << size << " elements" << std::endl;
	//create new array pointer
	double *nv;
	//initialize array with size of input
	nv = new double[growto];
	//copy over v to nv
	for(int loop = 0; loop < size; loop++){
		//copy over each index value
		nv[loop] = v[loop];
	}
	//the "vector" is now this size
	size = growto;
	//cout the new size
	std::cout<< "New capacity: " << size << " elements" << std::endl;
	//delete v
	delete[] v;
	//set v to nv
	v = nv;
	
}

//function for AddElement
void AddElement(){
	float added;
	//ask user for element
	std::cout<< "Enter the new element: ";
	//get input float
	std::cin>> added;
	//if condition if there are empty spaces or not
	if(count == size){
		//grow vector (double it)
		Grow(2*size);
	}
	//insert added to the grown vector
	v[count] = added;
	//cout that it has been added
	std::cout<< added << " has been placed at v[" << count << "]" << std::endl;
	//count increments
	count++;
	//cout for organization
	std::cout<< std::endl << std::endl;
}

//function to print Vector
void PrintVector(){
	//provide a header
	std::cout<< "The elements in v are as follows: " << std::endl;
	//iterate through v and cout each
	for(int i = 0; i < count; i++){
		std::cout<< v[i] << "  ";
	}
	//cout for organization
	std::cout<< std::endl << std::endl;
}

//function to remove an element
void RemoveElement(){
	//check count to see if there is anything there.
	if(count == 0){
		//no elements, print error message
		std::cout<< "ERROR: nothing contained in vector v!";
	} else {
		//reduce count, next value placed will overwrite the value
		count--;
		//for security
		v[count] = 0;
		//cout message that it was successful
		std::cout<< "Element removed!";
	}
	//cout for organization
	std::cout<< std::endl << std::endl;
}

//function to insert an element at a specific location
void InsertElement() {
	//cout instructions
	std::cout<< "Please enter the index (from 0 to " << count << "): ";
	//declare index value
	int index;
	//ask for value
	std::cin>> index;
	//if statement to check if the index is valid
	if(index >= 0 && index <= count){
		//ALL CODE IN THIS BLOCK IS FOR VALID
		//declare number to be inserted
		float val;
		//count more instructions
		std::cout<< "Please specify a value to insert into v[" << index << "]: ";
		//input into val
		std::cin>>val;
		//grow vector if needed before anything else
		if(count == size){
			Grow(2*size);
		}
		//place everything right of it into the next index, starting from the right so we do not need a temp variable
		for(int j = count; j > index; j--){
			//place the varable from the left to the right
			v[j] = v[j-1];
		}
		//increment count to reflect new next index
		count++;
		v[index] = val;
		//debug or general info cout
		std::cout<< val << " has been placed at v[" << index <<"]";
	} else {
		//INVALID! make error message
		std::cout<< "ERROR: index is invalid";
	}
	//cout for organization
	std::cout<< std::endl << std::endl;
}

//Shrink function extra credit
void Shrink(){
	//cout "Vector shrunk"
	std::cout<< "Vector shrunk" <<std::endl;
	//cout the old size
	std::cout<< "Previous capacity: " << size << " elements" << std::endl;
	//create new array pointer
	double *nv;
	//initialize array with 0.5 size of original
	nv = new double[size/2];
	//copy over v to nv
	for(int loop = 0; loop < size/2; loop++){
		//copy over each index value
		nv[loop] = v[loop];
	}
	//the "vector" is now this size
	size = size/2;
	//cout the new size
	std::cout<< "New capacity: " << size << " elements" << std::endl;
	//delete v
	delete[] v;
	//set v to nv
	v = nv;
}
