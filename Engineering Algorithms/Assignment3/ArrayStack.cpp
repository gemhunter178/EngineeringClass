/*
ArrayStack.cpp
Implementation files for the Array Implementation of stack
from the class slides.
Student does not claim authorship.
*/

//include header file for the implementations
#include "ArrayStack.h"
//for assert
#include <assert.h>

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1) {
	//default constructor does not have anything
}

//check if array is empty
template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
	return top < 0;
}

//push item into the stack
template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry) {
	//default false if push unsuccessful
	bool result = false;
	//only push if the array is not full
	if (top < DEFAULT_CAP - 1) {
		//go to next index
		top++;
		//place item in this index
		items[top] = newEntry;
		//mark push successful
		result = true;
	} //end if
	//return success of push
	return result;
}

//pop item from top of stack
template<class ItemType>
bool ArrayStack<ItemType>::pop() {
	//default to no success
	bool result = false;
	//can only pop if the array is not empty
	if (!isEmpty()) {
		//mark current top for overwrite
		top--;
		//successful pop
		result = true;
	}//end if
	return result;
}

//peek at the top of the stack
template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
	assert(!isEmpty()); //if empty, the program is terminated and displays an error message
	//if not empty, return top
	return items[top];
} //end peek
//end of implementation file