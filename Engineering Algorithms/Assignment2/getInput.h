/*
getInput headerfile
AUTHOR: [me]
Declares functions to ask for an input and get said input
Includes function for reading from an ifstream as well
Requires <string>
*/
#pragma once
#ifndef GETINPUT_H
#define GETINPUT_H
//function to ask for input and returns string
std::string getInput(std::string);
//separate function to handle ints (tried to template this function but had other issues implementing)
int getIntInput(std::string);

#endif // GETINPUT_H