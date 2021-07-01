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
	//int for input
	int input;
	//give user options
	cout<< "What would you like to do?" << endl;
	while(true){
		//print out menu for options
		cout<<"1. Turn on an LED" << endl;
		cout<<"2. Detect if a switch is on" << endl;
		cout<<"3. Display Binary" << endl;
		cout<<"4. Read Binary" << endl;
		cout<<"5. Exit Program" << endl << endl;
		cout<<"Please choose an option: ";
		//get input
		cin>>input;
		//switch case to go through options
		switch(input){
			case 1:
				//Turn on an LED
				//organization cout:
				cout<< endl;
				
				//integers for the LED to be used and the state
				int useLED, stateLED;
				//ask for which LED to be turned on
				cout<<"Which LED do you want to control? (0-7) ";
				//take the input
				cin>> useLED;
				//ask for the state
				cout<<"What should be done to LED" << useLED <<"? (1 for on, 0 for off): ";
				//take the value for input
				cin>> stateLED;
				//if statement to check if the option is valid
				if(useLED <=7 && useLED >= 0 && stateLED >= 0 && stateLED <=1){
					//use the Write1Led function to do the desired action
					Write1Led(pBase, useLED, stateLED);
					//cout that it should have worked
					cout<< endl << "LED" << useLED << " is ";
					//for readability
					if(stateLED == 1){
						//cout on
						cout<< "on!" << endl;
					} else {
						//only other option is off
						cout<< "off!" << endl;
					}
				} else {
					//output error message
					cout<< "The command provided is invalid, remember LED numbers go from 0 to 7 and can only be on (1) or off (0)";
				}
				
				
				//organization cout:
				cout<< endl;
				break;
			case 2:
				//Detect switch
				//organization cout:
				cout<< endl;
				
				//integers for the Switch to be used
				int useSwitch;
				//ask for which Switch to be turned on
				cout<<"Which Switch do you want to control? (0-7) ";
				//take the input
				cin>> useSwitch;
				//if statement to check if the option is valid
				if(useSwitch <=7 && useSwitch >= 0){					
					//cout that it should have worked
					cout<< endl << "Switch" << useSwitch << " is ";
					//for readability
					//use the Read1Switch within the if statement to show if the switch is "on" or "off"
					if(Read1Switch(pBase, useSwitch) == 1){
						//cout on
						cout<< "on!" << endl;
					} else {
						//only other option is off
						cout<< "off!" << endl;
					}
				} else {
					//output error message
					cout<< "The command provided is invalid, remember switch numbers go from 0 to 7";
				}
				
				//organization cout:
				cout<< endl;
				break;
			case 3:
				//write a binary on the LEDs
				//organization cout:
				cout<< endl;
				
				//ask for number from 0-255 to be written to LEDs
				//input int
				int intVal;
				cout<< "Please enter a number from 0 to 255: ";
				//read number
				cin>> intVal;
				//write the number to LEDS (binary)
				Write1Led(pBase, 0, intVal % 2);
				Write1Led(pBase, 1, (intVal/2) % 2);
				Write1Led(pBase, 2, (intVal/4) % 2);
				Write1Led(pBase, 3, (intVal/8) % 2);
				Write1Led(pBase, 4, (intVal/16) % 2);
				Write1Led(pBase, 5, (intVal/32) % 2);
				Write1Led(pBase, 6, (intVal/64) % 2);
				Write1Led(pBase, 7, (intVal/128) % 2);
				//cout that the function has been performed:
				cout<< intVal << " has been written in binary on the LEDs!" << endl;
				
				//organization cout:
				cout<< endl;
				break;
			case 4:
				//write a binary on the LEDs
				//organization cout:
				cout<< endl;
				
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
				//output the number stored
				cout<< "The number stored in the switches is " << switchBin << endl;				
				
				//organization cout:
				cout<< endl;
				break;
			case 5:
				//exit
				return 0;
			default:
				//error message printed
				cout<< "That is not a valid option, please choose another" << endl;
		}
	}

	// Done
	Finalize(pBase, fd);
	return 0;
}

//Write1Led() defined here
void Write1Led(char *pBase, int ledNum, int state){
	//use RegisterWrite to write correct values
	RegisterWrite(pBase, 0x12C + (4*ledNum),state);
}

//Read1Switch() defined here
int Read1Switch(char *pBase, int switchNum){
	//use RegisterRead() to read the value
	return RegisterRead(pBase, 0x14C + (4*switchNum));
}
