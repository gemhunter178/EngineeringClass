#include <iostream>
#include <vector>
#include <iomanip>
#include <time.h>
#include <cstdlib>

using namespace std;

int width = 15;

float randFloat();
void printVector(vector<vector<float>> &Vector);

int main() {
	srand(time(NULL));
	vector<vector<float>> Vector;
	vector<float> temp1{randFloat(),randFloat()};
	vector<float> temp2{randFloat(),randFloat()};
	vector<float> temp3{randFloat(),randFloat()};
	Vector.push_back(temp1);
	Vector.push_back(temp2);
	Vector.push_back(temp3);
	//bug fixing
	//cout<< Vector[0].size();
	printVector(Vector);
	return 0;
}

float randFloat(){
	float randNum;
	randNum = (rand() + 0.0)/RAND_MAX;
	return randNum;
}
void printVector(vector<vector<float>> &Vector){
	int row = 0;
	int column = 0;
	while(true){
		if(column == Vector[row].size()){
			column = 0;
			row++;
			cout<< "\n\n";
		}
		if(row == Vector.size()){
			//bug fizing
			//cout<< "returned!";
			return;
		}
		cout<< setw(width) << Vector[row][column];
		//more bug fixing
		//cout<< " " << row << " " << column << "   ";
		column++;
	}
}

