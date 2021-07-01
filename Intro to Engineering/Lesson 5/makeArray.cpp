#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

float randNum(){
	float Num;
	Num = 3*((rand()+ 0.0)/RAND_MAX) - 1;
	return Num;
}

int main(){
	int width = 15;
	srand(time(NULL));
	float Array[3][4];
	int x_index = 0;
	int y_index = 0;
	cout<< "\n";
	while(true){
		Array[y_index][x_index] = randNum();
		cout<< setw(width) << Array[y_index][x_index];
		if(x_index == 3){
			x_index = 0;
			y_index++;
			cout<< "\n\n";
		} else {
			x_index++;
		}
		if(y_index > 2) {
			break;
		}
		
	}
	return 0;
}
