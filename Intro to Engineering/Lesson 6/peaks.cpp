#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//bool to stop program if it fails to find file
bool readFile(string FileName, vector<vector<float>> &Elevations);

//outputs elevations as a grid
void displGrid(vector<vector<float>> &Elevations);

//finds peaks and their position, returns total number of peaks. Also handles finding the biggest peak
int findPeak(vector<float> &peaks, vector<vector<float>> &Elevations);



int main(){
	string FileName;
	cout<< "What is the file name the elevations are stored in? ";
	getline(cin, FileName);
	//bug fixing
	//cout<< FileName;
	vector<vector<float>> Elevations;
	vector<float> peaks;
	if(readFile(FileName, Elevations) == 0){
		return 1;
	}
	displGrid(Elevations);
	//bug fixing
	//cout<< Elevations.size() << Elevations[1].size();
	int peakCount = findPeak(peaks, Elevations);
	//makes grammar correct, outputs the number of peaks
	//the 0 peaks condiction was handled in the findPeak function
	if(peakCount == 1){
		cout<< "There was 1 peak in the file";
	} else if(peakCount > 1){
		cout<< "\nThere were " << peakCount << " peaks in " << FileName << '.';
	}
	return 0;
}

bool readFile(string FileName, vector<vector<float>> &Elevations) {
	ifstream fileIn(FileName, ios::in);
	if(!fileIn.is_open()) {
		cout<< "could not open file! \n";
		return 0;
	} else {
		float readNum;
		int loopNum = 0;
		int rowNum = 0;
		//this is the flag for an "unfilled" grid
		bool filled = 1;
		vector<float> temprow;
		//ignores essentially the first line, which are words
		fileIn.ignore(5000,'\n');
		while(rowNum != 7){
			fileIn>> readNum;
			temprow.push_back(readNum);
			//bug fixing
			//cout<< "cleared!";
			if(loopNum == 6){
				//checks if this row has the same number of indexes as the first
				if(Elevations.size() >= 1 && temprow.size() != Elevations[0].size()){
					filled = 0;
				}
				Elevations.push_back(temprow);
				temprow.clear();
				rowNum++;
				loopNum = 0;
			} else {
				loopNum++;
			}
		}
		//outputs there might be a problem with unfilled rectangles
		if(filled != 1){
			cout<< "The elevations in this file do not make a full 7x7 grid, errors may occur";
		}
		//more bug fixing
		//cout<< Elevations[0][0] << " " << Elevations[1][0] << " " << Elevations[2][0] ;	
		return 1;	
	}
}

void displGrid(vector<vector<float>> &Elevations){
	int loopNum = 0;
	int rowNum = 0;
	const int width = 8;
	//makes it neater
	cout<< "\nthe elevations in that file are...\n\n";
	while(rowNum != 7){
		cout<< setw(width) << Elevations[rowNum][loopNum];
		if(loopNum == 6){
			cout<< "\n\n";
			rowNum++;
			loopNum = 0;
		} else {
			loopNum++;
		}
	}
	return;
}

int findPeak(vector<float> &peaks, vector<vector<float>> &Elevations){
	//peaks can't be on the edges, so we can ignore row and column 1.
	int loopNum = 1;
	int rowNum = 1;
	const int width = 10;
	int peakCount = 0;
	//this variable is for the largest peak
	float bigPeak = 0;
	//Makes a header for the function output
	cout<< "These are the peaks:\n" << setw(width) << " Value:" << setw(width) << " Row:" << setw(width) << " Column:";
	//we don't have to check the other edges either
	while(rowNum != Elevations.size() - 1){
		//big blocky if to check for peaks
		if(Elevations[rowNum][loopNum] > Elevations[rowNum][loopNum-1] &&
		Elevations[rowNum][loopNum] > Elevations[rowNum][loopNum+1] &&
		Elevations[rowNum][loopNum] > Elevations[rowNum-1][loopNum] &&
		Elevations[rowNum][loopNum] > Elevations[rowNum+1][loopNum]){
			//stores peak value, location
			peaks.push_back(Elevations[rowNum][loopNum]);
			peaks.push_back(rowNum);
			peaks.push_back(loopNum);
			//outputs this information
			//we don't normally think of rows and columns starting at 0, so this adjusts that
			cout<< '\n' << setw(width) << peaks[peakCount*3] << setw(width) << peaks[peakCount*3+1] + 1 << setw(width) << peaks[peakCount*3+2] + 1;
			if(peaks[peakCount*3] > bigPeak){
				bigPeak = peaks[peakCount*3];
			}
			// brings peak count up by 1
			peakCount++;
		}
		if(loopNum == Elevations[rowNum].size() - 2){
			rowNum++;
			loopNum = 1;
		} else {
			loopNum++;
		}
	}
	if(peakCount != 0){
		cout<< "\n...and the tallest peak is: " << bigPeak << endl;
	} else {
		cout<< "\n...there were no peaks";
	}
	return peakCount;
}
