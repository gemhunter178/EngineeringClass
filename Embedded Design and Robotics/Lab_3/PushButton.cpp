/*
AUTHOR: Base given by anonymous
EDITED: [me]
DATE: 2019, JANUARY 31st
DESC: Lab 3 - this code is meant to control LEDs and read switch states on a Zedboard
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
//missing iostream
#include <iostream>

using namespace std;

// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;

// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;

/*These values are more fro reference than actually used. Save memory.
const int gpio_led1_offset = 0x12C;  // Offset for LED1
const int gpio_led2_offset = 0x130;  // Offset for LED2
const int gpio_led3_offset = 0x134;  // Offset for LED3
const int gpio_led4_offset = 0x138;  // Offset for LED4
const int gpio_led5_offset = 0x13C;  // Offset for LED5
const int gpio_led6_offset = 0x140;  // Offset for LED6
const int gpio_led7_offset = 0x144;  // Offset for LED7
const int gpio_led8_offset = 0x148;  // Offset for LED8

const int gpio_sw1_offset = 0x14C;  // Offset for Switch 1
const int gpio_sw2_offset = 0x150;  // Offset for Switch 2
const int gpio_sw3_offset = 0x154;  // Offset for Switch 3
const int gpio_sw4_offset = 0x158;  // Offset for Switch 4
const int gpio_sw5_offset = 0x15C;  // Offset for Switch 5
const int gpio_sw6_offset = 0x160;  // Offset for Switch 6
const int gpio_sw7_offset = 0x164;  // Offset for Switch 7
const int gpio_sw8_offset = 0x168;  // Offset for Switch 8

const int gpio_pbtnl_offset = 0x16C;  // Offset for left push button
const int gpio_pbtnr_offset = 0x170;  // Offset for right push button
const int gpio_pbtnu_offset = 0x174;  // Offset for up push button
const int gpio_pbtnd_offset = 0x178;  // Offset for down push button
const int gpio_pbtnc_offset = 0x17C;  // Offset for center push button
*/

/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *
 * @param pBase		Base address returned by 'mmap'.
 * @parem offset	Offset where device is mapped.
 * @param value		Value to be written.
 */
void RegisterWrite(char *pBase, int offset, int value)
{
	* (int *) (pBase + offset) = value;
}

/**
 * Read a 4-byte value from the specified general-purpose I/O location.
 *
 * @param pBase		Base address returned by 'mmap'.
 * @param offset	Offset where device is mapped.
 * @return		Value read.
 */
int RegisterRead(char *pBase, int offset)
{
	return * (int *) (pBase + offset);
}

/**
 * Initialize general-purpose I/O
 *  - Opens access to physical memory /dev/mem
 *  - Maps memory at offset 'gpio_address' into virtual address space
 *
 * @param  fd	File descriptor passed by reference, where the result
 *		of function 'open' will be stored.
 * @return	Address to virtual memory which is mapped to physical,
 *          	or MAP_FAILED on error.
 */
char *Initialize(int *fd)
{
	*fd = open( "/dev/mem", O_RDWR);
	return (char *) mmap(
			NULL,
			gpio_size,
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			*fd,
			gpio_address);
}

/**
 * Close general-purpose I/O.
 *
 * @param pBase	Virtual address where I/O was mapped.
 * @param fd	File descriptor previously returned by 'open'.
 */
void Finalize(char *pBase, int fd)
{
	munmap(pBase, gpio_size);
	close(fd);
}

/** Changes the state of an LED (ON or OFF)
* @param pBase base address of I/O
* @param ledNum LED number (0 to 7)
* @param state State to change to (ON or OFF)
* DEFINED BELOW int main()
*/
void Write1Led(char *, int, int);

/** Reads the value of a switch
* - Uses base address of I/O
* @param pBase base address of I/O
* @param switchNum Switch number (0 to 7)
* @return Switch value read
* DEFINED BELOW int main()
*/
int Read1Switch(char *, int);

//Function to write a number from 0-255 to LEDs
void WriteBin(char *pBase, int);

//Function to read the number formed by switches (in binary)
int ReadBin(char *pBase);

//Function to read push buttons
int PushButtonGet(char *pBase);

int main()
{
	// Initialize
	int fd;
	char *pBase = Initialize(&fd);

	// Check error
	if (pBase == MAP_FAILED)
	{
		perror("Mapping I/O memory failed - Did you run with 'sudo'?\n");
		return -1;
	}	
	
// ************** Put your code here **********************
	//Took out menu, this is ONLY the push button controls
	//Push Button controls
	//organization cout:
	cout<< endl;
	
	//print out controls
	cout<< "LEDs are now under push button controls." << endl;
	cout<< "Up and Down increase and decrease the number displayed" << endl;
	cout<< "Left and Right performs a bitwise shift" << endl;
	cout<< "The center button resets the value to the one given by the switches" << endl;
	//Give a way to exit
	cout<< "Hold the center button to quit" << endl;
	//initialize values
	//dispVal is the value being displayed, set to the switch values here.
	int dispVal = ReadBin(pBase);
	//use dispVal to output a that number on the LEDs
	WriteBin(pBase,dispVal);
	//value for buttons
	int btnState;
	//value for previous input to check for change. Set to PushButtonGet() in case a button is already being held down
	int prevState = PushButtonGet(pBase);
	//value for how long a button has been pressed (only used for quitting functionality)
	int holdBtn = 0;
	
	
	//while loop for moving around. btnState = 6 only after the button has been held down (see farther down)
	while(btnState != 6){
		btnState = PushButtonGet(pBase);
		//only change something when the button state has changed
		if(btnState != prevState){
			//major part of code here
			//reset holdBtn timer
			holdBtn = 0;
			//switch structure for what to do with each option
			switch(btnState){
				case 1:
					//left does bitwise shift left
					dispVal = dispVal<<1;
					break;
				case 2:
					//right does bitwise shift right
					dispVal = dispVal>>1;
					break;
				case 3:
					//up increments display
					dispVal++;
					break;
				case 4:
					//down decreases display
					dispVal--;
					break;
				case 5:
					//center resets to switch value
					dispVal = ReadBin(pBase);
					break;
				default:
					//includes the 0 state.
					//does nothing
					
					break;
			}
			//update display
			WriteBin(pBase,dispVal);
			//wait for 2 msec (should be imperceiveable) to aoid "double pressing"
			usleep(2000);
			//change prevState to current state
			prevState = btnState;
		} else if(btnState == 5){
			//increment holdBtn if center button is held down
			holdBtn++;
			//wait for .5 msec (should be imperceiveable)
			usleep(500);
			//half a second of holding
			if(holdBtn == 1000){	
				//print message that program is quitting
				cout<< "Quitting in 3 seconds..." << endl;
			} else if(holdBtn == 3000){ //1.5 seconds of holding
				//print message that program is quitting
				cout<< "            2 seconds..." << endl;
			} else if(holdBtn == 5000){ //2.5 seconds of holding
				//print message that program is quitting
				cout<< "            1 second ..." << endl;
			} else if(holdBtn == 7000){ //3.5 seconds
				//breaks while loop
				btnState = 6;
			}
		}
	}
	
	//organization cout:
	cout<< endl;

	// Done
	Finalize(pBase, fd);
	return 0;
}

//Write1Led() defined here
void Write1Led(char *pBase, int ledNum, int value){
	//Updated directly performs what RegisterWrite was doing.
	* (int *) (pBase + 0x12C + (4*ledNum)) = value;
}

//Read1Switch() defined here
int Read1Switch(char *pBase, int switchNum){
	//Updated version directly performs what RegisterRead was doing.
	return * (int *) (pBase + 0x14C + (4*switchNum));
}

//Writing a number to LEDs here
void WriteBin(char *pBase, int intVal){
	//write the number to LEDS (binary)
	Write1Led(pBase, 0, intVal % 2);
	Write1Led(pBase, 1, (intVal/2) % 2);
	Write1Led(pBase, 2, (intVal/4) % 2);
	Write1Led(pBase, 3, (intVal/8) % 2);
	Write1Led(pBase, 4, (intVal/16) % 2);
	Write1Led(pBase, 5, (intVal/32) % 2);
	Write1Led(pBase, 6, (intVal/64) % 2);
	Write1Led(pBase, 7, (intVal/128) % 2);
}

//read the binary number on the switches
int ReadBin(char *pBase){
	//stored int for the value of the switches
	int switchBin;
	//set the number to 0
	switchBin = 0;
	//add the values associated with each switch
	switchBin = switchBin + Read1Switch(pBase, 0);
	switchBin = switchBin + 2 * Read1Switch(pBase, 1);
	switchBin = switchBin + 4 * Read1Switch(pBase, 2);
	switchBin = switchBin + 8 * Read1Switch(pBase, 3);
	switchBin = switchBin + 16 * Read1Switch(pBase, 4);
	switchBin = switchBin + 32 * Read1Switch(pBase, 5);
	switchBin = switchBin + 64 * Read1Switch(pBase, 6);
	switchBin = switchBin + 128 * Read1Switch(pBase, 7);
	//return the value
	return switchBin;
}

//Function to read push buttons
int PushButtonGet(char *pBase){
	//the order determines which button is read over the others when more than one is pressed
	//
	if(RegisterRead(pBase, 0x17C)==1){
		//middle button is 5 It is here as I want it to have priority over everything else.
		return 5;
	} else if(RegisterRead(pBase, 0x16C)==1){
		//left is 1
		return 1;
	} else if(RegisterRead(pBase, 0x170)==1){
		//right is 2
		return 2;
	} else if(RegisterRead(pBase, 0x174)==1){
		//up is 3
		return 3;
	} else if(RegisterRead(pBase, 0x178)==1){
		//down is 4
		return 4;
	} else {
		//no buttons pressed
		return 0;
	}
}
