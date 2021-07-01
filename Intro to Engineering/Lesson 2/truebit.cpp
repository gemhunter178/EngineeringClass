#include <iostream>
#include <cmath>
/*as a decimal, the probability has to be a float. As a possibly non-integer, surprise will also be float.
The value assigned to it is just to make sure the while loop runs at least once even if the user enters "2" for the first vlaue*/
float prob, surprise = 0;
using namespace std;
int main(int argc, char** argv){
	//Enters directions and accepts the input
	cout<< "let's find the surprise based on a probability!" << endl 
	<< "enter the probability (0 being impossible and 1 being certain)" << endl 
	<< "probability: ";
	cin >> prob;
	//allows for multiple subsequent probabilities to be entered, except 2, which is invalid anyway.
	while(prob != 2 or surprise == 0) {
		//Tests the input is valid, or would yield infinite (or close to it).
		if(prob > 1 or prob < 0) {
			cout<< "That value is invalid, remember 0 is impossible and 1 is certain" << endl;
		} else if(prob == 0){
			cout<< "That probability is too small! your surprise is too large!" << endl;
		//after invalids are sorted out, the surprise can be calculated for the rest
		} else {
			if(prob > .5 && prob != 1) {
				prob = 1 - prob;
			}
			surprise = -log2(prob);
			surprise = ceil(surprise);
			cout<< "the surprise for " << prob << " is " << surprise << endl;
		}
		//give the option to input another probability, endlines just make the program look neater
		cout<< endl 
		<< "enter another probability or enter 2 to end " << endl 
		<< "probability: ";
		cin >> prob;
		//Surprise is set to 1 so the program won't loop if 2 is entered
		surprise = 1;
	}	
	return 0;
}
