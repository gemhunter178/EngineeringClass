#include <iostream>
using namespace std;
int i = 1, j = 1, k = 0, fib = 0,N;
string prefix;
int main() {
cout << "which nth fibonacci number do you want? (accurate up to the 47th) ";
cin >> N;
while(i <= N) {
	if(i%10 <= 3) {
		if(i%10 == 1 && i%100 != 11){
			prefix = "st";
		}
		if(i%10 == 2 && i%100 != 12){
			prefix = "nd";
		}
		if(i%10 == 3 && i%100 != 13){
			prefix = "rd";
		}
	} else {
		prefix = "th";
	}
	if(i == N){
	cout << "the "<< i<< prefix<< " Fibonacci number is "<< fib<< endl;
	}
	k = j;
	j = fib;
	fib = j + k;
	i = i + 1;
}
}



