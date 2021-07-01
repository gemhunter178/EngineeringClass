#include <iostream>
#include <vector>
using namespace std;

int main(){
	int input;
	cout<< "what number of Fibonacci numbers do you want? ";
	cin>> input;
	//make fibonacci array
	vector<unsigned int> fibonacci(2);
	//set first two numbers and output
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	if(input == 1){
		cout<< "The first fibonacci number is 0";
	} else if(input <= 0) {
		cout<< "there is no " << input << "th fibonacci number";
	} else {
		cout<< "The first " << input << " numbers are: 0, 1";
	}
	for(int index = 2; index < input; index++) {
		fibonacci.push_back(0);
		fibonacci[index] = fibonacci[index - 1] + fibonacci[index - 2];
		cout<< ", " << fibonacci[index];
	}
}


