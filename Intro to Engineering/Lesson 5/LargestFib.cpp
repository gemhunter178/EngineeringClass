#include <iostream>
#include <vector>
using namespace std;

int main(){
	//make fibonacci array
	vector<unsigned int> fibonacci(2);
	//set first two numbers and output
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	int index = 2;
	while(fibonacci[index - 1] >= fibonacci[index - 2]){
		fibonacci.push_back(0);
		fibonacci[index] = fibonacci[index - 1] + fibonacci[index - 2];
		index++;
	}
	cout<< "the largest fibonacci number with an unsigned int is " << fibonacci[index - 2];
return 0;
}


