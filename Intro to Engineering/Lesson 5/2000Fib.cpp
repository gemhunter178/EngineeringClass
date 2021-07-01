#include <iostream>
#include <vector>
using namespace std;

int main(){
	int input;
	cout<< "up to what value do you want to output fibonacci numbers to? ";
	cin>> input;
	//make fibonacci array
	vector<unsigned int> fibonacci(2);
	//set first two numbers and output
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	if(input == 0){
		cout<< "The only Fibonacci number less than or equal to 0 is 0";
	} else if(input <= 0) {
		cout<< "there are no fibonacci numbers less than or equal to " << input;
	} else {
		cout<< "The Fibonacci numbers less than or equal to " << input << " are: \n0, 1";
			for(int index = 2; fibonacci[index - 1] <= input; index++) {
			fibonacci.push_back(0);
			fibonacci[index] = fibonacci[index - 1] + fibonacci[index - 2];
			if(fibonacci[index] <= input) {
				cout<< ", " << fibonacci[index];
			}
			if(fibonacci[index] < fibonacci[index - 1]) {
				cout<< "\nERROR: OVERFLOW IMMENENT";
				return 1;
			}
		}
	}
return 0;
}


