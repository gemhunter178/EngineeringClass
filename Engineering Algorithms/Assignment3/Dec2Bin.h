/*header file that included the declarations
for the Dec2Bin class*/

//needed for dec2bin_itr()
//#include "ArrayStack.h"

#pragma once
//make sure we don't have multiple declarations
#ifndef DEC2BIN_H
#define DEC2BIN_H

//Class that has all the required functions
class Dec2Bin {
public:
	int decNum; //the positive interger to be converted to binary
	Dec2Bin() :decNum(0) {};//default constructor that akes deNum = 0
	void readDecNum(); //asks the user for the it to be converted into binary
	void dec2bin_rcv(int d); //display the binary equivalent of d using the recursive method. d should take decNum.
	void dec2bin_itr();//display the binary equivalent of decNum using the iterative method, suign a stack.
};
#endif // !DEC2BIN_H
