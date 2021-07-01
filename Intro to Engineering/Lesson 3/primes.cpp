//the usual initializations
#include <iostream>
using namespace std;

int main() {
	//Start with an integer as it still needs to be signed to detect invalid (negative) inputs
	int inputNumber = -1;
	//instroductions and instructions
	cout<< "Welcome to the prime numbers program v1, \nplease enter the number you want to find the primes up until (inclusive):";
	//keeps running until a valid input is given
	do {	
		cin>> inputNumber;
		//this commented out line was for testing what the input saw
		//cout<< inputNumber;
		//explanations for invalid inputs
		if(inputNumber < 0) {
			cout<< "That number is invalid, we are not here to debate if negatives can be primes \n\nplease enter a positive integer";
		}
	} while(inputNumber < 0);
	//stop the program if 0 or some other character was entered
	if(inputNumber == 0) {
		/* entering a non-integer value messes things up, even if the output returns inputNumber = 0, 
		to avoid this, we're going to stop the program if these characters are entered */
		cout<< "Either you entered an invalid character or 0, there are no primes less than 0 \nthe program will now close, please reopen and use a positive integer";
		return 1; //1 will say that this exception was triggered
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
	/*the conditions in the while loop below stop the tests when it has run through half the numbers
	the last half wont be needed as the way it sorts uses multiples of smaller primes. 
	a nonzero or one multiple after 1/2 the set won't be in the set*/
	while(testNum * 2 <= inputNumber){
		//if the number has been sorted out previously, it skips it, since it's multiples already fall in the multiples of the number that sorted it out
		//bugfix testLoop
		cout<< testLoop << ", " << allArr[testLoop] << "\n\n\n\n";
		
		if(allArr[testLoop] != 0) {
			//keep testing and deleting numbers in the allArr set that are composites
			//the next loop is to run through all multiples of a prime number
				do {
					//sets testNum to a mutliple of a prime(pervious composites filtered out above)
					do {
						testNum = allArr[testLoop];
						testLoop++;
						sortLoop = testLoop + 1;
					} while(testNum == 0);
					while(sortLoop <= inputNumber - 2){
						//bug fixing line below: outputs the test and the number tested on
						cout<< testNum << ", " << allArr[sortLoop] << endl;
						//compares this specific multiple to a relevant part of the allArr set
						if((allArr[sortLoop] % testNum) == 0) {
							//sets matching values to 0 in the set, eliminating composites
							allArr[sortLoop] = 0;
							sortLoop++;
						} else {
							sortLoop++;
						}					
					}
					//do...while so it stops once the testNum has passed the set
					
				} while(testNum <= inputNumber);
		}
		
	}
	//repurposing/reusing testLoop
	testLoop = 0;
	//this integer is for the number of primes
	int primes = 0;
	//output results
	cout<< "\n\nThe primes less than or equal to " << inputNumber << " are: ";
	//tesing this at the beginning would access those unused parts of the set, leading to an extra number for some reason
	do {
		if(allArr[testLoop] > 0 ){
			cout<< allArr[testLoop];
			if(allArr[testLoop] == inputNumber){
				cout<< ".";
			} else {
				cout<< ", ";
			}
			primes++;
		}
		testLoop++;
	} while(allArr[testLoop] <= inputNumber);
	cout<< "\nThere are " << primes << " primes less than or equal to " << inputNumber;
	return 0;
}

