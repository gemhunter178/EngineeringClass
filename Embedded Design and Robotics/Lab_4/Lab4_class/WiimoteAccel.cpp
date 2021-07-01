/*WiimoteAccel Class
* made by [me], based off of code from Blackboard
* allows reading of input from Wiimote, Lab 4 Embedded Design
* 2019, Feb 14th
*/
#include "WiimoteAccel.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

//constructor
WiimoteAccel::WiimoteAccel(){
	fd = open("/dev/input/event0", O_RDONLY);
	if (fd == -1){
		std::cerr << "Error: Could not open event file - forgot sudo?\n";
		exit(1);
	}
}

//destructor
WiimoteAccel::~WiimoteAccel(){
	// Close Wiimote event file
	close(fd);
}

//Listen function
void WiimoteAccel::Listen(){
	while (true){
		// Read a packet of 16 bytes from Wiimote
		char buffer[16];
		read(fd, buffer, 16);
		// Extract code (byte 10) and value (byte 12) from packet
		int code = buffer[10];
		short acceleration = * (short *) (buffer + 12);
		// Print them (if no child class function overrides)
		AccelerationEvent(code,acceleration);
	}
}

//virtual file that can be overwritten later to print out the code and acceleration
void  WiimoteAccel::AccelerationEvent(int code, int acceleration){
	std::cout << "Code = " << code <<
	", acceleration = " << acceleration << '\n';
}

