//#include "pch.h" /*needed only for Visual Studio */
//on Linux compile this with g++ -std=c++11

/* Create a text file in the same folder as this program and name it myfile.txt.
   Save the file with the following three lines in its content

John Smith
20
3.4

*/

#include <iostream>
#include <fstream> //Required for ifstream, ofstream
#include <stdexcept>

using namespace std;


int main() { //reads from a text file that contains three lines: string, an integer, and a float
	string s;
	int i;
	float f;
	ifstream inf;

	inf.open("myfile.txt");
	if (inf.fail()) 	{ 
		cerr << "Error: Could not open input file\n";
		exit(1);
	}

	inf.exceptions(ifstream::failbit | ifstream::badbit); //activate the exception handling of inf stream 

	string tempS;
	try {
		getline(inf, s);
		getline(inf, tempS); i = stoi(tempS); //convert string to an integer
		getline(inf, tempS); f = stof(tempS); //convert string to a float
	}
	catch (ifstream::failure e) {
		cerr << "Error: File does not have enough data\n";
		exit(1);
	}
	catch (invalid_argument e) { //if stoi or stof cannot convert tempS to a number
		cerr << "Error: File contains invalid data\n";
		exit(1);
	}

	cout << "s = " << s << endl;
	cout << "i = " << i << endl;
	cout << "f = " << f << endl;
	return 0;
}

