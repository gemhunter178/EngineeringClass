#include <iostream>
using namespace std;
short i = 1, N;
unsigned int fib = 0,j = 1, k = 0;
string suffix;
int main() {
cout << "which nth fibonacci number do you want? (accurate up to the 48th) ";
cin >> N;
while(i <= N) {
	if(i%10 <= 3) {
		if(i%10 == 1 && i%100 != 11){
			suffix = "st";
		}
		if(i%10 == 2 && i%100 != 12){
			suffix = "nd";
		}
		if(i%10 == 3 && i%100 != 13){
			suffix = "rd";
		}
	} else {
		suffix = "th";
	}
	cout << "the "<< i<< suffix<< " Fibonacci number is "<< fib<< endl;
	k = j;
	j = fib;
	fib = j + k;
	i = i + 1;
}
}



