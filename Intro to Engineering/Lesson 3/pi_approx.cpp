//usual initializations
#include <iostream>
// next two for a random generation and for the rand functions
#include <stdlib.h> 
#include <time.h>
//for the circle calculations
#include <math.h>
using namespace std;

int main() {
	//makes the rand function more random
	srand(time(NULL));
	//input is the amount of test points
	int input;
	//test is the amount of times it has run through the while loop
	int test = 0;
	//hit is how many times it falls in between the selected area
	int hit = 0;
	//in this case, these are the coordinates squared, the last one is the distance from the origin.
	float test_x, test_y, dist;
	cout<< "please enter how many test points you wish to have to approximate pi: ";
	cin>> input;
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
	//this is the approximate area of the circle, since the entire test area was 4 square units
	float area = 4* (hit + 0.0) / input;
	//output
	cout<< "\nthe approximate area of a circle with radius 1 with " << input << " test points is " << area << endl
	<< "this makes the approximation of pi = " << area;
	return 0;
}
