/*
Eng Algorithms, ASSIGNMENT 3, part 3
Author: [me]
ID: [ID withheld]
Description:
Fibonacci using recursives, one with dynamic programming, one without.
*/

//inputs and output needed for user
#include <iostream>

//fibonacci without dynamic
int fib(int n) { //where n is the nth number of the sequence we are finding
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return fib(n-1)+fib(n-2);
	}
}

/*fibonacci with dynamic. requires an array initialized to 0, 1, and
then -1 for uncalculated values*/
int fib_dyn(int n, int array[]) {
	//only needs to do something if the value has not been calculated yet
	//n-1 to save that one partition of space (not wasting index 0)
	if (array[n-1] = -1) {
		array[n-1] = fib(n - 1) + fib(n - 2);
	}
	//return value in the array
	return array[n-1];
}

int main() {
	//making array
	//default to 75 as it's ample indexes for the problem
	const int DEFAULT_DYN_ARRAY = 75;
	int fibArray[DEFAULT_DYN_ARRAY] = { 0,1 };//0,1 are the first two numbers.
	//initialize rest to -1
	int i;
	for (i = 2; i < DEFAULT_DYN_ARRAY; i++) {
		//make that index = -1
		fibArray[i] = -1;
	}
	//testing the functions:
	//output calculated
	//5
	std::cout << "Without dynamic programming, the fibonacci number at " << 5 << " is " << fib(5) << "\n";
	std::cout << "With dynamic programming, the fibonacci number at " << 5 << " is " << fib_dyn(5, fibArray) << "\n\n";
	//10
	std::cout << "Without dynamic programming, the fibonacci number at " << 10 << " is " << fib(10) << "\n";
	std::cout << "With dynamic programming, the fibonacci number at " << 10 << " is " << fib_dyn(10, fibArray) << "\n\n";
	//20
	std::cout << "Without dynamic programming, the fibonacci number at " << 20 << " is " << fib(20) << "\n";
	std::cout << "With dynamic programming, the fibonacci number at " << 20 << " is " << fib_dyn(20, fibArray) << "\n\n";
	//30
	std::cout << "Without dynamic programming, the fibonacci number at " << 30 << " is " << fib(30) << "\n";
	std::cout << "With dynamic programming, the fibonacci number at " << 30 << " is " << fib_dyn(30, fibArray) << "\n\n";
	//40
	std::cout << "Without dynamic programming, the fibonacci number at " << 40 << " is " << fib(40) << "\n";
	std::cout << "With dynamic programming, the fibonacci number at " << 40 << " is " << fib_dyn(40, fibArray) << "\n\n";



	/*//testing user input number (will be removed later as it contains a loop)
	//number to input to
	int input = 3;//default to first meaningful calculation
	while (input != 0) {
		//request
		std::cout << "Enter the nth fibonacci number you want, or 0 to quit: ";
		//take input
		std::cin >> input;
		//output calculated
		std::cout << "Without dynamic programming, the fibonacci number at " << input << " is " << fib(input) << "\n";
		std::cout << "With dynamic programming, the fibonacci number at " << input << " is " << fib_dyn(input, fibArray) << "\n";
		
	}
	//previous debug
	//std::cout << fib(4) << "\n";*/

	//stop to see output (debug)
	std::cout << "\nEnter anything to exit ";
	//ignore value
	int ignore;
	std::cin >> ignore;

	//return normal
	return 0;
}
