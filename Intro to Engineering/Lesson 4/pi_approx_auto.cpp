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
	//test is the amount of times it has run through the while loop
	int test;
	//hit is how many times it falls in between the selected area
	int hit;
	//in this case, these are the coordinates squared, the middle one is the distance from the origin. The next two are self-explainitory.
	float test_x, test_y, dist, pi_approx, error;
	//defines the look of the table
	const int width = 15;
	cout<< "this program is built to run 100000 sample points to approximate pi, results will follow as test points are run";
	//these intgers are defined here to allow subsequent inputs to work
	test = 0;
	hit = 0;
	//a for loop can be used too
	while(test <= 100000) {
		//makes the first test point the first test point (instead of 0)
		test++;
		//the + 0.0 makes it a float. the -0.5 centers the points around 0.
		test_x = pow(2*((rand() + 0.0) / RAND_MAX - 0.5), 2);
		test_y = pow(2*((rand() + 0.0) / RAND_MAX - 0.5), 2);
		dist = sqrt(test_x + test_y);
		//bug fixing
		//cout<< test_x << ", " << test_y << endl;
		//tests it the point is within the circle
		if(dist <= 1){
			hit++;
		}
		if(test == 10 || test == 100 || test == 1000 || test == 10000 || test == 100000) {
			//this is the approximate area of the circle, since the entire test area was 4 square units. 
			//As the area of a circle with radius 1, this is also the approximation of pi
			pi_approx = 4* (hit + 0.0) / test;
			error = M_PI - pi_approx;
			//output (editted from original to fit assignment requirements)
			cout<< "\n*********************************************\n" << left << setw(width) << "No. of Samples" << "  " << left << setw(width) 
			<< "Estimate of pi" << "  " << left << setw(width) << "Error" << endl;
			cout<< left << setw(width) << test << "  " << left << setw(width) << pi_approx << "  " 
			<< left << setw(width) << error;
		}
	}
	return 0;
}
