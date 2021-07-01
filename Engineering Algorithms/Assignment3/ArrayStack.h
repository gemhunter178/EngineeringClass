/*header file For the Array Implementation of the stack
from the lecture slides.
Copied directly, Student does not claim authorship*/

#pragma once
//make sure we don't have multiple declarations
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
template<class ItemType>
class StackInterface {
public:
	/*Sees whether this stack is empty. 
	@return True if the stack is empty, or false if not. */
	virtual bool isEmpty() const = 0;
	/*Adds a new entry to the top of this stack. 
	@post If the operation was successful, newEntry is at the top of the stack. 
	@param newEntry The object to be added as a new entry. 
	@return True if the addition is successful or false if not.*/
	virtual bool push(const ItemType& newEntry) = 0;
	/*Removes the top of this stack.
	@post if the operation was successful, the top of the stack has been removed
	@return True if the removal is successful or false if not*/
	virtual bool pop() = 0;
	/*Returns the top of the stack
	@pre The stack is not empty
	@post The top of the stack has been returned, and the stack is unchanged
	@return The top of the stack*/
	virtual ItemType peek() const = 0;
}; //end StackInterface

template<class ItemType>
class ArrayStack : public StackInterface<ItemType> {
private:
	static const int DEFAULT_CAP = 50;
	ItemType items[DEFAULT_CAP]; //array of stack items
	int top; //index to top of stack
public:
	ArrayStack(); //default constructor
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const;
}; //end ArrayStack

#endif // !ARRAYSTACK_H
