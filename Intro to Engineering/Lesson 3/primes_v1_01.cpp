//the usual initializations
#include <iostream>
using namespace std;

int main() {
	//Start with an integer as it still needs to be signed to detect invalid (negative) inputs
	int inputNumber = -1;
	//instroductions and instructions
	cout<< "Welcome to [my] prime numbers program v1.01, \nplease enter the number you want to find the primes up until (inclusive):";
	//keeps running until a valid input is given
	do {	
		cin>> inputNumber;
		//this commented out line was for testing what the input saw
		//cout<< inputNumber;
		//explanations for invalid inputs
		if(inputNumber < 0) {
			cout<< "That number is invalid, we are not here to debate if negatives can be primes \n\nplease enter a positive integer: ";
		}
	} while(inputNumber < 0);
	//stop the program if 0 or some other character was entered (if another character, this would be the error state)
	if(inputNumber == 0) {
		/* entering a non-integer value messes things up, even if the output returns inputNumber = 0, 
		to avoid this, we're going to stop the program if these characters are entered */
		cout<< "\nEither you entered an invalid character or 0, there are no primes less than 0. \nthe program will now close, please reopen and use a positive integer";
		return 1; //a return of 1 will say that this exception was triggered
	}
	//due to how the primes are found, 1 is not valid and must have a specific case
	if(inputNumber == 1) {
		cout<< "\nThere are 0 primes less than or equal to 1.";
		return 2; //a return of 2 is not an error, but distiguishes from the "normal" sort
	}
	//the program continues once inputNumber is valid
	//creates an array the size of the input... this is a bit unoptimized
	int allArr[inputNumber - 2];
	//each number from 2 to the input number is assigned to spots (0 and 1 are ignored due to how the primes will be sorted later)
	for(int Loop = 0; Loop <= inputNumber - 2; Loop++){
		allArr[Loop] = Loop + 2;
		//testing if it worked
		//cout<< allArr[Loop] << endl;
	}
	//a few test numbers are initialized to use in sorting
	int testLoop = 0;
	int testNum = 0;
	int sortLoop = 0;
	//now the non-primes are sorted out by deleting multiples of previous primes
	/*the conditions in the while loop below stop the tests when it has run through the square root of the inputNumber
	this is because the last bit won't be needed as the way it sorts uses multiples of smaller primes. 
	a nonzero or one multiple after the square root of inputNumber won't be in the set*/
	do {
		//sets testNum to the next valid array value (not 0)
		do {
			testNum = allArr[testLoop];
			testLoop++;
			sortLoop = testLoop + 1;
		} while(testNum == 0);
		while(sortLoop <= inputNumber - 2){
			//bug fixing line below: outputs the test and the number tested on
			//cout<< testNum << ", " << allArr[sortLoop] << endl;
			//if the number was already cut out, this skips it.
			if(allArr[sortLoop] == 0){
				sortLoop++;
				//the modulo operand is used. If the number being tested is divsible by the test number, it should equal 0.
			} else if(allArr[sortLoop] % testNum == 0) {
				//sets matching values to 0 in the set, eliminating composites(multiples)
				allArr[sortLoop] = 0;
				sortLoop++;
				//just in case anyhing is missed
			} else {
				sortLoop++;
			}					
		}
			//do...while so it stops once the testNum has passed the set
	} while(testNum * testNum <= inputNumber);
	//repurposing/reusing testLoop
	testLoop = 0;
	//this integer is for the number of primes
	int primes = 0;
	//output results
	cout<< "\nThe primes less than or equal to " << inputNumber << " are: ";
	do {
		if(allArr[testLoop] > 0 ){
			cout<< allArr[testLoop];
			//aesthetic choice, but only works if the number inputted was prime.
			if(allArr[testLoop] == inputNumber){
				cout<< ".";
			} else {
				cout<< ", ";
			}
			primes++;
		}
		testLoop++;
	} while(allArr[testLoop] <= inputNumber);
	cout<< "\nThere are " << primes << " primes less than or equal to " << inputNumber << ".";
	return 0;
}

