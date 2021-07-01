//initialize the usual
#include <iostream>
using namespace std;


int main() {
	/* define variables, I used strings for the inputs as I should be getting strings as the input (t and f are characters) I could use char, but I'm less familiar right now.
	the integer loop is just to tell the program which step it's on
	xor2 is set to either "t" or "f" to allow a check further down the line to pass. It will be replaced by the 2nd input anyways */
	string xor1, xor2 = "t";
	int loop = 0;
	//initial instructions
	cout<< "please enter 2 booleans and I will output the xor result. t is true, f is false \n";
	// this while loop will keep running until two valid strings are entered. For is not used as loop should only be incremented if certain conditions are met.
	while(loop < 2){
		//enter xor1 and xor 2, depending on which step it's on
		if(loop == 0){
			cout<< "please enter your first value: ";
			cin>> xor1;
		} else if(loop == 1){
			cout<< "please enter your second value: ";
			cin>> xor2;
		}
		//allows the program to go to the next step if the input is valid, and repeat the loop if not. This is why xor2 was initally set to "t"
		if(xor1 != "f" && xor1 != "t" or xor2 != "f" && xor2 != "t"){
			cout<< "invalid input, please try again. Remember t is true and f is false \n";
		} else {
			++loop;
		}
	}
	//reminds the user of their inputs
	cout<< endl
	<< "your inputs were: " << xor1 << " and " << xor2;
	//once the inputs are in, this tells the result. if one is true but not the other, it's true. if not, it's false.
	if(xor1 == "f" && xor2 == "t" || xor1 == "t" && xor2 == "f"){
		cout<< endl
		<< "The exclusive or of those two inputs is true";
	} else {
		cout<< endl
		<< "The exclusive or of those two inputs is false";
	}
}

