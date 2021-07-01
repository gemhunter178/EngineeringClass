#include <iostream>
using namespace std;

int main(int argc, char** argv){
	int a;
	do {
		cout<< "type in the letter e: ";
		cin>> a;
		cout<< "you typed an " << a << endl;
	} while (a != 'e');
	return 0;
}
