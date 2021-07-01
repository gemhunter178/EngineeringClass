#include <iostream>
using namespace std;
//using integers since that's what was asked. The average is a float as it may not be an integer. These are the only 2 variables.
int add;
float total = 0;
int main() {
	//give instructions and input first number
	cout<< "input your data set to find the average, only 5 integers per set" << endl 
	<< "What is your first value?  ";
	cin>>add;
	//take input and start adding to "total", which is the total at this point.
	total = total + add;
	//repeat for next 4 values
	cout<< "What is your second value? ";
	cin>>add;
	total = total + add;
	cout<< "What is your third value?  ";
	cin>>add;
	total = total + add;
	cout<< "What is your fourth value? ";
	cin>>add;
	total = total + add;
	cout<< "What is your fifth value?  ";
	cin>>add;
	total = total + add;
	//divide total by 5 to get average, the extra endline is just to make the result more prominent
	total = total / 5;
	cout<< endl 
	<< "the average of this set is " << total;
	return 0;
}
