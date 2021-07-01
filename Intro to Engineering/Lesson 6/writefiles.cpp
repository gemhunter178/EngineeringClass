#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
	srand(time(NULL));
	string line1, line2, restline;
	ofstream fileOut("randomnumber.txt",ios::app);
	if(!fileOut.is_open()) {
		cout<< "could not open file! \n";
	} else {
		for(int ctr = 1; ctr <= 10; ctr++){
			fileOut<< rand()%1000 << " ";
		}
		fileOut<< "\n";
	}
	return 0;
}
