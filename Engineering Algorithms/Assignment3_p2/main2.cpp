/*
Eng Algorithms, ASSIGNMENT 3, Part 2
Author: [me]
ID: [ID withheld]
Description:
Tests the code given in part 2 of Assignment 3
Just compile this file and run
*/

//for cout
#include <iostream>

//function 1, given in the assignment
int F1(int n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		int result = F1(n / 2);
		return result * result;
	}
	else {
		return 2 * F1(n - 1);
	}
}

//function 2 given in the assignment
int F2(int n) {
	if (n == 0) return 1;
	return 2 * F2(n - 1);
}

//function 3 
int F3(int n) {
	if (n == 0) return 1;
	return F3(n - 1) + F3(n - 1);
}

int main() {
	//making a loop to test values 1,3,5,16,24,26,30
	const int ArraySize = 7;
	//array with all the values to be tested
	int testNums[ArraySize] = { 1, 3, 5, 16, 24, 26, 30 };
	//count for the for loop below
	int i;
	for (i = 0; i < ArraySize; i++) {
		//show what is being input
		std::cout << "\nThe outputs when " << testNums[i] << " is input:\n";
		//tell which function is being used and output value
		std::cout << "F1: " << F1(testNums[i]) << "\n";
		std::cout << "F2: " << F2(testNums[i]) << "\n";
		std::cout << "F3: " << F3(testNums[i]) << "\n";
	}

	//stall to see output
	std::cout << "enter any number to exit ";
	int ignore;
	std::cin >> ignore;
	
	//return normal
	return 0;
}
