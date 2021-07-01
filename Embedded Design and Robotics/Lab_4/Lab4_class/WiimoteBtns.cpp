/*WiimoteBtns Class
* made by [me], based off of code from Blackboard
* allows reading of input from Wiimote, Lab 4 Embedded Design
* 2019, Feb 14th
*/
#include "WiimoteBtns.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

//constructor
WiimoteBtns::WiimoteBtns(){
	fd = open("/dev/input/event2", O_RDONLY);
	//error checking
	if (fd == -1){
		std::cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
}

//destructor
WiimoteBtns::~WiimoteBtns(){
	// Close Wiimote event file
	close(fd);
}

//Listen function
void WiimoteBtns::Listen(){
	while (true){
		// Read a packet of 32 bytes from Wiimote
		char buffer[32];
		read(fd, buffer, 32);
		// Extract code (byte 10) and value (byte 12) from packet
		int code = buffer[10];
		int value = buffer[12];
		// Print them
		ButtonEvent(code, value);
	}
}
		
//ButtonEvent function that prints out the code and value
void WiimoteBtns::ButtonEvent(int code, int value){
	//prints the integers passed in
	std::cout << "Code = " << code << ", value = " << value << '\n';
}
		

