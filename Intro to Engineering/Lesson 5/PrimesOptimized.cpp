#include <iostream>
#include <vector>
using namespace std;


int testTo;

//sorts an input number as a prime or not a prime
void primeSort(int testNum, vector<int> &primes);

int main(){
	vector<int> primes(1);
	primes[0] = 2;
	cout<< "Up to what number do you want to look for primes?: ";
	cin>> testTo;
	//We're looking for less than our number, not equal to, so I subtract the input number by one.
	testTo = testTo - 1;
	/*There are no primes less than 2, so this message appears if 2 or any other number was entered 
	(remember we immediately subtract 1 from the input) */
	if(testTo < 2) {
		cout<< "There are no primes less than " << testTo + 1;
		return 1;
	}
	//starts testing numbers from 2 as 1 may cause problems.
	int testNumber = 2;
	/*I needed to enter 2 here since 2 is always going to be on the list, 
	and testing 2 against this would say it's not prime even when it is (2 is already in the vector) */
	cout<< "The primes less than " << testTo + 1 << " are:\n2";
	//tests every number up to the input - 1
	while(testNumber <= testTo){
		//calls the function to see if the number is prime or not.
		primeSort(testNumber, primes);
		testNumber++;
		//bug fixing
		//cout<< testNumber;
	}
	//outputs the size of the vector (therefore the amount of primes less than our input)7
	cout<< "\n\nThere are " << primes.size() << " primes less than " << testTo + 1;
	return 0;
}

//actual function
void primeSort(int testNum, vector<int> &primes) {
	int index = 0;
	do {
		//if the modulo is 0 at some point, there is no need to test any more.
		if(testNum % primes[index] == 0) {
			//bug fixing
			//cout<< " eliminated: " << testNum;
			return;
		}
		//if the function ran through all the primes up to the square root of the input number, it is a prime and is entered as such.
		if(primes[index] * primes[index] > testNum) {
			primes.push_back(testNum);
			cout<< ", " << testNum;
			return;
		}
		index++;
	} while(testNum > index); //failsafe;
}

