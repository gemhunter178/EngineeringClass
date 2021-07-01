#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string line1, line2, restline;
	ifstream fileIn("testfile.txt");
	if(!fileIn.is_open()) {
		cout<< "could not open file! \n";
	} else {
		getline(fileIn,line1);
		cout<< line1 + "\n";
		getline(fileIn,line2);
		cout<< line2 + "\n";
		getline(fileIn,restline);
		cout<< restline;
	}
	return 0;
}
