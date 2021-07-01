#include <iostream>
#include <cstdlib>
using namespace std;

void PrintArray(int v[], int size){
	for(int loopnum = 0; loopnum < size; loopnum++){
		cout<< v[loopnum] << ", ";
	}
	return;
}
void RandomArray(int v[], int size){
	for(int loopnum = 0; loopnum < size; loopnum++){
		v[loopnum] = rand()%100;
	}
	return;
}
void SortArray(int v[], int size){
	for(int count = 0; count < size; count++){
		int min = v[count];
		int pos = count;
		int ctr;
		for(ctr = count + 1; ctr < size; ctr++){
			if(v[ctr] < min){
				min = v[ctr];
				pos = ctr;
			} 
		}
		if(v[count] != min){
			ctr = v[count];
			v[count] = v[pos];
			v[pos]=ctr;
		}
	}
	return;
}

int main(){
	int array[10];
	RandomArray(array,10);
	PrintArray(array,10);
	cout<< endl;
	SortArray(array,10);
	PrintArray(array,10);
	cout<< endl;
	return 0;
}
