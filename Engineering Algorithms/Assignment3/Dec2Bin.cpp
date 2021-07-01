/*
Dec2Bin.cpp
the implementation fiels for Dec2Bin.h
created by [me]
Used initially for Assignment 3, EECE2560
*REQUIRES "ArrayStack.h" and "ArrayStack.cpp" files*
*/
#pragma once
//include header
#include "Dec2Bin.h"
//include ArrayStack for Stack/Iterative implementation
#include "ArrayStack.h"
#include "ArrayStack.cpp"

//will need cout and cin from this library
#include <iostream>

void Dec2Bin::readDecNum()
{
	//ask for the number to be placed in decNum
	std::cout << "What is the decimal number? "; //done to match example output
	//place in decNum
	std::cin >> decNum;
}

void Dec2Bin::dec2bin_rcv(int d)
{
	//this is a recursive function
	//based on the binary converter mentioned in class
	//base case
	if (d == 0) {
		//do nothing
	} else {
		//first, call the function again so the most significant bit will be displayed first
		dec2bin_rcv(d / 2);
		//print out the result for this bit
		std::cout << d % 2;
	}
	return;
}

void Dec2Bin::dec2bin_itr()
{
	//create object of ArrayStack
	//default: can store 50 bits, int is only 32, so, should be adequate
	ArrayStack<int> decConvert;
	//create local integer of decNum that will be altered
	int d = decNum;
	//as iterative: can loop, loop until stack of all required bits is made
	while (d != 0) {
		decConvert.push(d % 2);
		d = d / 2;
	}
	//then print out all the bits from the top until stack is empty.
	while (!decConvert.isEmpty()) {
		std::cout<< decConvert.peek();//print top of stack
		decConvert.pop();//pop the top of the stack
	}
	return;
}
