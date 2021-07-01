/*
Eng Algorithms, ASSIGNMENT 4, part 1
Author: [me]
ID: [ID withheld]
Description: Main progr4am to test moves and comps of each sorting algorithm
Requires dbugSorts.h and dBugSorts.cpp for sorting and helpers to sorting functions
*/

#include <iostream> //cout
#include <stdlib.h> //rand()
#include <time.h> //time() and others for file naming
#include <fstream> //creating/writing to file
#include <string> //naming file

//include sorting functions
#include "dbugSorts.h"

//create arrays of 1000 ints (currently in global scope)
const int ARRAY_SIZE = 1000;
int BST[ARRAY_SIZE], AVG[ARRAY_SIZE], WST[ARRAY_SIZE];

//initialize arrays
//for BST
void mkBST(int BSTarray[], const int size) {
	int i;
	for (i = 0; i < size; i++) {
		//would initialize the array in ascending numberical order
		BSTarray[i] = i * 5;
	}
	return; //return when done
}

//for AVG
void mkAVG(int AVGarray[], const int size) {
	int i;
	for (i = 0; i < size; i++) {
		//would initialize the array with random numbers
		AVGarray[i] = rand() % 100001; //assignment specifies between 0 and 100000
	}
	return; //return when done
}

//for WST
void mkWST(int WSTarray[], const int size) {
	int i;
	for (i = 0; i < size; i++) {
		//would initialize the array in descending numberical order
		WSTarray[i] = (size-i) * 5;
	}
	return; //return when done
}

//(re)initializes all the arrays provided they are the same size
void makeArrays(int BST[], int AVG[], int WST[], const int size) {
	mkBST(BST, size);
	mkAVG(AVG, size);
	mkWST(WST, size);
}

//tests a function with an array
void testSortFunc(int Array[], const int size, void (*sortMethod)(int[],const int, int&, int&),void (*printSortInfo)(int,int), int& moves, int& comps) {
	//reset moves and comps counters
	moves = 0, comps = 0;
	sortMethod(Array, size, moves, comps);
	printSortInfo(moves, comps);
}

//debug function that prints the array
template <class itmType>
void printArr(itmType array[], const int size) {
	int i;
	for (i = 0; i < size; i++) {
		//print out every element from [0] to [size]
		std::cout << array[i];
		if (i == size - 1) {
			std::cout << ".\n"; //end of the print, make neat
		}
		else {
			std::cout << ", "; //not at end of print
		}
	}
	return; //return when done
}

//function for creating text file for writing, returns file name for future use
std::string createFile(std::string fileName) {
	//make File stream
	std::ofstream File;
	//make a date that could be written to text file name
	//taken from example on http://www.cplusplus.com/reference/ctime/strftime/
	time_t rawtime;
	//different from example as localtime_s is being used
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	//safer way of getting local time
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "%Y_%m_%d_%H_%M", &timeinfo);
	//append .txt and the date
	std::string convToTxt = fileName + buffer + ".txt";
	//create file
	File.open(convToTxt.c_str());
	//test if file successfully created
	if (!File) {
		std::cout << "File creation failed!\n";
		//exit
		exit(1);
	}
	else {
		std::cout << convToTxt << " created!\n";
	}
	File.close();
	return convToTxt;
}

//function for writing a row of data into the open file
//void writeDataLine(std::ofstream inputStream, std::string sortType, std::string sortArray, int moves, int comps);

//MAIN
int main() {
	//semi-randomize rand seed once
	srand(time(NULL));
	//initialize arrays
	makeArrays(BST, AVG, WST, ARRAY_SIZE);

	//create file
	std::string createdFile = createFile("Output");
	//open file for use
	std::ofstream openFile;
	openFile.open(createdFile);
	//test for file opened
	if (!openFile) {
		std::cout << "File could not be found!\n";
		//exit
		exit(1);
	}
	else {
		std::cout << "Folder Opened!\n";
	}
	//write header for the file
	openFile << "Data From:\t\tmoves:\tcomps:\n";
	//cout some key to interpret data below
	std::cout << "All data presented using \nBest (already sorted) Case, \nAverage (random) Case, and \nWorst (reverse sorted) Case in that order \n\n";
	//initialize moves and comps
	int moves, comps;

	//testing selectionSort
	//state this is selectionSort
	std::cout << "Selection Sort STATS: \n";
	//test starts, every other line writes to file
	testSortFunc(BST, ARRAY_SIZE, selectionSort, printSortInfo, moves, comps);
	openFile << "selection sort" << " on " << "BST" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(AVG, ARRAY_SIZE, selectionSort, printSortInfo, moves, comps);
	openFile << "selection sort" << " on " << "AVG" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(WST, ARRAY_SIZE, selectionSort, printSortInfo, moves, comps);
	openFile << "selection sort" << " on " << "WST" << ":\t" << moves << "\t" << comps << "\n";
	//check if arrays are sorted (debug)
	std::cout << "BST now sorted STATUS: " << checkSort(BST, ARRAY_SIZE) << '\n';
	std::cout << "AVG now sorted STATUS: " << checkSort(AVG, ARRAY_SIZE) << '\n';
	std::cout << "WST now sorted STATUS: " << checkSort(WST, ARRAY_SIZE) << "\n\n";//extra new line for organization
	

	//reinitialize arrays
	makeArrays(BST, AVG, WST, ARRAY_SIZE);

	//testing bubbleSort
	//state sorting method
	std::cout << "Bubble Sort STATS: \n";
	//test starts, every other line writes to file
	testSortFunc(BST, ARRAY_SIZE, bubbleSort, printSortInfo, moves, comps);
	openFile << "bubble sort" << " on " << "BST" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(AVG, ARRAY_SIZE, bubbleSort, printSortInfo, moves, comps);
	openFile << "bubble sort" << " on " << "AVG" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(WST, ARRAY_SIZE, bubbleSort, printSortInfo, moves, comps);
	openFile << "bubble sort" << " on " << "WST" << ":\t" << moves << "\t" << comps << "\n";
	//check if arrays are sorted (debug)
	std::cout << "BST now sorted STATUS: " << checkSort(BST, ARRAY_SIZE) << '\n';
	std::cout << "AVG now sorted STATUS: " << checkSort(AVG, ARRAY_SIZE) << '\n';
	std::cout << "WST now sorted STATUS: " << checkSort(WST, ARRAY_SIZE) << "\n\n";//extra new line for organization


	//reinitialize arrays
	makeArrays(BST, AVG, WST, ARRAY_SIZE);

	//testing insertion Sort
	//state sorting method
	std::cout << "Insertion Sort STATS: \n";
	//test starts, every other line writes to file
	testSortFunc(BST, ARRAY_SIZE, insertionSort, printSortInfo, moves, comps);
	openFile << "insertion sort" << " on " << "BST" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(AVG, ARRAY_SIZE, insertionSort, printSortInfo, moves, comps);
	openFile << "insertion sort" << " on " << "AVG" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(WST, ARRAY_SIZE, insertionSort, printSortInfo, moves, comps);
	openFile << "insertion sort" << " on " << "WST" << ":\t" << moves << "\t" << comps << "\n";
	//check if arrays are sorted (debug)
	std::cout << "BST now sorted STATUS: " << checkSort(BST, ARRAY_SIZE) << '\n';
	std::cout << "AVG now sorted STATUS: " << checkSort(AVG, ARRAY_SIZE) << '\n';
	std::cout << "WST now sorted STATUS: " << checkSort(WST, ARRAY_SIZE) << "\n\n";//extra new line for organization


	//reinitialize arrays
	makeArrays(BST, AVG, WST, ARRAY_SIZE);

	//testing mergeSort
	//state sorting method
	std::cout << "Merge Sort STATS: \n";
	//test starts, every other line writes to file
	testSortFunc(BST, ARRAY_SIZE, mergeSort, printSortInfo, moves, comps);
	openFile << "merge sort" << " on " << "BST" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(AVG, ARRAY_SIZE, mergeSort, printSortInfo, moves, comps);
	openFile << "merge sort" << " on " << "AVG" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(WST, ARRAY_SIZE, mergeSort, printSortInfo, moves, comps);
	openFile << "merge sort" << " on " << "WST" << ":\t" << moves << "\t" << comps << "\n";
	//debug print
	//printArr(AVG, 1000);
	//check if arrays are sorted (debug)
	std::cout << "BST now sorted STATUS: " << checkSort(BST, ARRAY_SIZE) << '\n';
	std::cout << "AVG now sorted STATUS: " << checkSort(AVG, ARRAY_SIZE) << '\n';
	std::cout << "WST now sorted STATUS: " << checkSort(WST, ARRAY_SIZE) << "\n\n";//extra new line for organization


	//reinitialize arrays
	makeArrays(BST, AVG, WST, ARRAY_SIZE);

	//testing quickSort
	//state sorting method
	std::cout << "Quick Sort STATS: \n";
	//test starts, every other line writes to file
	testSortFunc(BST, ARRAY_SIZE, quickSort, printSortInfo, moves, comps);
	openFile << "quick sort" << " on " << "BST" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(AVG, ARRAY_SIZE, quickSort, printSortInfo, moves, comps);
	openFile << "quick sort" << " on " << "AVG" << ":\t" << moves << "\t" << comps << "\n";
	testSortFunc(WST, ARRAY_SIZE, quickSort, printSortInfo, moves, comps);
	openFile << "quick sort" << " on " << "WST" << ":\t" << moves << "\t" << comps << "\n";
	//debug print
	//printArr(WST, 1000);
	//check if arrays are sorted (debug)
	std::cout << "BST now sorted STATUS: " << checkSort(BST, ARRAY_SIZE) << '\n';
	std::cout << "AVG now sorted STATUS: " << checkSort(AVG, ARRAY_SIZE) << '\n';
	std::cout << "WST now sorted STATUS: " << checkSort(WST, ARRAY_SIZE) << "\n\n";//extra new line for organization
	
	/*
	//debug test:
	std::cout << "BST: \n";
	printArr(BST, 10);
	std::cout << "AVG: \n";
	printArr(AVG, 10);
	std::cout << "WST: \n";
	printArr(WST, 10);
	*/

	//close file used
	openFile.close();
	//stop program from closing until user inputs something
	int toss;
	std::cin >> toss;
}