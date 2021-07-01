//usual initializations
#include <iostream>
// next two for a random generation and for the rand functions
#include <stdlib.h> 
#include <time.h>
//for the circle calculations
#define _USE_MATH_DEFINES
#include <cmath>
//for table organizaion
#include <iomanip>
using namespace std;

int main() {
	//makes the rand function more random
	srand(time(NULL));
	//input is the amount of test points
	int input;
	//test is the amount of times it has run through the while loop
	int test;
	//hit is how many times it falls in between the selected area
	int hit;
	//in this case, these are the coordinates squared, the last one is the distance from the origin.
	float test_x, test_y, dist;
	cout<< "please enter how many test points you wish to have to approximate pi: ";
	cin>> input;
	//this do...while loop allows the user to try a different number of test variables
	do {
		//these intgers are defined here to allow subsequent inputs to work
		test = 0;
		hit = 0;
		//a for loop can be used too
		while(test < input) {
			//the + 0.0 makes it a float. the -0.5 centers the points around 0
			test_x = pow(2*((rand() + 0.0) / RAND_MAX - 0.5), 2);
			test_y = pow(2*((rand() + 0.0) / RAND_MAX - 0.5), 2);
			dist = sqrt(test_x + test_y);
			//bug fixing
			//cout<< test_x << ", " << test_y << endl;
			//tests it the point is within the circle
			if(dist <= 1){
				hit++;
			}
			test++;
		}
		//this is the approximate area of the circle, since the entire test area was 4 square units. 
		//As the area of a circle with radius 1, this is also the approximation of pi
		float area = 4* (hit + 0.0) / input;
		float error = M_PI - area;
		//output (editted from original to fit assignment requirements)
		//defines the look of the table
		const int width = 15;
		//actual output
		cout<< "*********************************************\n" << left << setw(width) << "No. of Samples" << "  " << left << setw(width) 
		<< "Estimate of pi" << "  " << left << setw(width) << "Error" << endl;
		cout<< left << setw(width) << input << "  " << left << setw(width) << area << "  " 
		<< left << setw(width) << error;
		//added functionality for multiple inputs
		cout<< "\n\nplease enter another amount of test points you wish to test or enter 0 to end: ";
		cin>> input;
	} while(input != 0);	
	return 0;
}
