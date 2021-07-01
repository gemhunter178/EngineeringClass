/*
AUTHOR: Base given by anonymous
EDITED: [me]
DATE: 2019, FEB 14th
DESC: Lab 4 - this code is meant to control LEDs and read switch states on a Zedboard
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
//missing iostream
#include <iostream>
#include "ZedBoard.h"

using namespace std;

// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;

// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;

//class Zedboard

ZedBoard::ZedBoard(){
	this->fd = open( "/dev/mem", O_RDWR);
	//debug
	cout<< "Class ZedBoard created\n";
	this->pBase = (char *) mmap(
			NULL,
			gpio_size,
			PROT_READ | PROT_WRITE,
			MAP_SHARED,
			fd,
			gpio_address);
}

//deconstructor is finalize function from below
ZedBoard::~ZedBoard(){
	munmap(this->pBase, gpio_size);
	close(this->fd);
	//debug
	cout<< "Class ZedBoard destroyed\n";
}
//function to get pBase
char *  ZedBoard::getpBase(){
	return this->pBase;
}

//Write1Led() defined here
void ZedBoard::Write1Led(char *pBase, int ledNum, int value){
	//Updated directly performs what RegisterWrite was doing.
	* (int *) (pBase + 0x12C + (4*ledNum)) = value;
}

//Writing a number to LEDs here
void ZedBoard::WriteAllLeds(char *pBase, int intVal){
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

int ZedBoard::RegisterRead(char *pBase, int offset){
	return * (int *) (pBase + offset);
}

void ZedBoard::RegisterWrite(char *pBase, int offset, int value){
	* (int *) (pBase + offset) = value;
}
