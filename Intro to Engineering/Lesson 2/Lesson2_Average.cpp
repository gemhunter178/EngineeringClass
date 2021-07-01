#include <iostream>
using namespace std;
//using floats so people can input signed decimal values. The average is a float as it may not be an integer
float average = 0, add;
int main() {
	//give instructions and input first number
	cout<< "input your data set to find the average, only 5 numbers per set" << endl << "What is your first value?  ";
	cin>>add;
	//take input and start adding to "average", which is the totl at this point.
	average = average + add;
	//repeat for next 4 values
	cout<< "What is your second value? ";
	cin>>add;
	average = average + add;
	cout<< "What is your third value?  ";
	cin>>add;
	average = average + add;
	cout<< "What is your fourth value? ";
	cin>>add;
	average = average + add;
	cout<< "What is your fifth value?  ";
	cin>>add;
	average = average + add;
	//divide total by 5 to get average, the extra endline is just to make the result more prominent
	average = average / 5;
	cout<< endl << "the average of this set is " << average;
	return 0;
}
