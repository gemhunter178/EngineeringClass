//usual initializations
#include <iostream>
// next two for a random generation and for the rand functions
#include <stdlib.h> 
#include <time.h>
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
	float test_x,test_y;
	cout<< "please enter how many test points you wish to have: ";
	cin>> input;
	//a for loop can be used too
	while(test < input) {
		//the + 0.0 makes it a float, the 2 * makes test_x fall in between 0 and 2
		test_x = 2* ((rand() + 0.0) / RAND_MAX);
		test_y = (rand() + 0.0) / RAND_MAX;
		//bug fixing
		//cout<< test_x << ", " << test_y << endl;
		if(test_x <= 1 && test_y >= 0.5){
			hit++;
		}
		test++;
	}
	float percent = (hit + 0.0) / input;
	//output
	cout<< "\nout of " << input << " drops, " << hit << " number of drops fell in the target \nFor a " << percent << "% accuracy" ;
	return 0;
}
