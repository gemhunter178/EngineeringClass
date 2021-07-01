/*
AUTHOR: Base given by anonymous
EDITED: [me]
DATE: 2019, FEB 14th
DESC: Lab 4 - this code is meant to control LEDs and read switch states on a Zedboard
*/

#ifndef ZEDBOARD_H
#define ZEDBOARD_H
//class Zedboard
class ZedBoard{
	private:
		char *pBase;
		int fd;
	public:
		//constructor is initialize function copied from below
		ZedBoard();
		
		//deconstructor is finalize function from below
		~ZedBoard();
		
		//function to get pBase
		char *getpBase();
		
		//Write1Led()
		void Write1Led(char *, int, int);
		
		//Writing a number to LEDs here
		void WriteAllLeds(char *, int);
		
		//Read an address
		int RegisterRead(char *, int);
		
		//Write a value
		void RegisterWrite(char *, int, int);
};

#endif
