/*
Eng Algorithms, ASSIGNMENT 6, part 2
Author: [me]
ID: [ID withheld]
Description: One program to simulate a undirected, weighted graph or certain locations at the university.
Refer to the submission write up or "HW6Map_Final.png" for reference
Asks the user for a beginning pint and end point, then uses dijkstra's to find the shortest path
*/

#include <string> //std::string
#include <fstream> //ofstream, ifstream
#include <iostream> //for input output operations on console
#include <cassert> //assert()
#include <limits> //INT_MAX

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//global variables

//number of vertices in my file, required to pass a 2D graph into my functions
const int numVerts = 22;

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//function declarations, defined below main()

//reads the edge data after the array has been initialized
void readGraphFile(std::string, int[numVerts][numVerts]);
//fills an array with a value
void fillArray(int[numVerts][numVerts], int);
//more of a debug function, will output the array.
void printArray(int[numVerts][numVerts]);
//a very bad hash function that just refines all the keys selectively. Done as there aren't too many vertices and this is faster for this assignment
//returns index of vertex given the input "name"
int convertToIndex(std::string);
//does the opposite
std::string convertToName(int);


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//Class declarations, actual definitions are below main()

//object that contains values important for dijkstra's algo
class djkObj {
	//everything is public for simplicity
public:
	//array of edges
	int edges[numVerts][numVerts];
	//current minimum distance array
	int minDist[numVerts];
	//previous vertex that got this value
	int pastVert[numVerts];
	//order of vertices
	int vertexOrder[numVerts];
	//function to sort remaining, unvisited vertices, returns the next vertex in the sequence
	int sortAndReturnNext(int);
	//function to find the path using dujkstra's algo
	int findPath(int, int);
	//traces back path. Only should be used AFTER findPath is used
	void tracePath(int, int);
	//resets vertexOrder array for subsequent path finds
	void resetOrder();
	//constructs by setting arrays to default values
	djkObj();
	//empty destructor
	~djkObj();
};



/*-------------------
MAIN
-------------------*/

int main() {
	//initialize Dijkstra obj
	djkObj dijkstra;
	//fill array with the maximum integer value
	fillArray(dijkstra.edges, INT_MAX);
	//read input file
	readGraphFile("GRAPH.txt", dijkstra.edges);
	//values for user input
	std::string userInput;
	int userStart, userEnd;
	//debug
	//printArray(edges);
	//some basic instructions
	std::cout << "Please refer to the attached map to show available locations in this program...\n\n";
	//loop until user is done with finding paths
	do {
		//reset order in case this is a subsequent run
		dijkstra.resetOrder();
		//ask user for end and start desitinations
		std::cout << "Please enter a starting location: ";
		std::getline(std::cin, userInput);
		//convert to internal index
		userStart = convertToIndex(userInput);
		std::cout << "Please enter an ending location: ";
		std::getline(std::cin, userInput);
		//convert to internal index
		userEnd = convertToIndex(userInput);
		//find the path
		dijkstra.findPath(userStart, userEnd);
		//outputs
		std::cout << "\nThe shortest path goes from ";
		dijkstra.tracePath(userStart, userEnd);
		std::cout << "\nThis path is " << dijkstra.minDist[userEnd] << "m long";
		//ask if user wants to continue
		std::cout << "\n\nDo you wish to find another path? (y/n): ";
		std::getline(std::cin, userInput);
	} while (userInput != "n");
	
	//wait for user input before closing
	//std::cin.ignore();
	return 0;
}

/*-------------------
END OF MAIN
-------------------*/


void readGraphFile(std::string fileName, int Edges[numVerts][numVerts]) {
	//opening file
	std::ifstream inputFile;
	inputFile.open(fileName);
	//make sure file is open
	assert(!inputFile.fail());
	//pull out number of vertices
	std::string inputStr;
	std::getline(inputFile, inputStr);
	int thisNumVerts = std::stoi(inputStr);
	//check that this matches the const set above, and display error if not
	if (thisNumVerts != numVerts) {
		std::cout << "Number of vertices do not match with global variable, please check that they match.";
		//end program
		assert(false);
	}
	//debug
	//std::cout << "File has been opened.";

	//to keep index values
	int startIndex, endIndex, distance;
	//run until end of file. This reads the edge data
	while (!inputFile.eof()) {
		//the following reads one line
		std::getline(inputFile, inputStr, '\t');
		startIndex = std::stoi(inputStr);
		std::getline(inputFile, inputStr, '\t');
		endIndex = std::stoi(inputStr);
		std::getline(inputFile, inputStr);
		distance = std::stoi(inputStr);
		
		//now this data is put into the edge array. As this is undirected, it goes both ways
		Edges[startIndex][endIndex] = distance;
		Edges[endIndex][startIndex] = distance;
	}

	//done with the input file, it can be closed now
	inputFile.close();
	return;
}

//fills an array with some value
void fillArray(int Array[numVerts][numVerts], int value) {
	for (int i = 0; i < numVerts; i++) {
		for (int j = 0; j < numVerts; j++) {
			Array[i][j] = value;
		}
	}
	return;
}

//prints array
void printArray(int Array[numVerts][numVerts]) {
	for (int i = 0; i < numVerts; i++) {
		for (int j = 0; j < numVerts; j++) {
			std::cout << Array[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	return;
}

//our terrible function that is like a hash function
int convertToIndex(std::string uncovStr) {
	int converInt = std::stoi(uncovStr);
	//debug
	//std::cout << uncovStr << " initially converted to " << converInt << std::endl;
	//indexes 1-6 are direct and won't need conversions
	if (converInt >= 1 && converInt <= 6) {
		return converInt;
	}
	else if (converInt != 23){
		//these are the conversions that do not involve west village numbers
		switch (converInt) {
			case 46:
				return 0;
			case 33:
				return 10;
			case 24:
				return 11;
			case 30:
				return 12;
			case 31:
				return 13;
			case 55:
				return 14;
			case 38:
				return 15;
			case 41:
				return 16;
			case 59:
				return 17;
			case 50:
				return 18;
			case 52:
				return 19;
			case 48:
				return 20;
			case 49:
				return 21;
		}
	}
	//handle west village numbers
	if (uncovStr == "23A" || uncovStr == "23a") {
		return 7;
	}
	if (uncovStr == "23G" || uncovStr == "23g") {
		return 8;
	}
	if (uncovStr == "23C" || uncovStr == "23c") {
		return 9;
	}

	//default error value
	return -1;

}

//does opposite of above
std::string convertToName(int index)
{
	if (index >= 1 && index <= 6) {
		return std::to_string(index);
	}
	switch (index) {
		case 0:
			return "46";
		case 7:
			return "23A";
		case 8:
			return "23G";
		case 9:
			return "23C";
		case 10:
			return "33";
		case 11:
			return "24";
		case 12:
			return "30";
		case 13:
			return "31";
		case 14:
			return "55";
		case 15:
			return "38";
		case 16:
			return "41";
		case 17:
			return "59";
		case 18:
			return "50";
		case 19:
			return "52";
		case 20:
			return "48";
		case 21:
			return "49";
	}
	//default return "error"
	return "error";
}

int djkObj::sortAndReturnNext(int firstIndex)
{
	//uses selection sort as we're not dealing with a lot of numbers and it's easy to implement
	for (int i = firstIndex; i < numVerts; i++) {
		int indOfMin = i;
		for (int j = i; j < numVerts; j++) {
			if (minDist[vertexOrder[j]] < minDist[vertexOrder[indOfMin]]) {
				indOfMin = j;
			}
		}
		if (indOfMin != i) {
			int temp = vertexOrder[i];
			//swap vertex order
			vertexOrder[i] = vertexOrder[indOfMin];
			vertexOrder[indOfMin] = temp;
			/* Not requried as we vertexOrder will point to the right index to use
			//swap the min distance that got said order
			temp = minDist[i];
			minDist[i] = minDist[indOfMin];
			minDist[indOfMin] = temp;
			*/
		}
	}
	//debug
	//std::cout << minDist[vertexOrder[firstIndex]] << " at vertex " << convertToName(vertexOrder[firstIndex]) << " is the current min\n";
	return vertexOrder[firstIndex];
}

int djkObj::findPath(int start, int end)
{
	//first set distance to itself is 0, and that it is the first index in vertexOrder
	minDist[start] = 0;
	vertexOrder[0] = start;
	//place "0" back int the unsorted part of vertexOrder
	vertexOrder[start] = 0;
	
	//repeat until destination has been reached
	//curOrderIndex is the current index in vertexOrder that we are testing
	for (int curOrderIndex = 0; curOrderIndex < numVerts; curOrderIndex++) {
		//current index adding from
		int curIndex = vertexOrder[curOrderIndex];
		//if current index is our destination, we have found a/the minimum path
		if (curIndex == end) {
			break;
		}
		int curDist = minDist[curIndex];
		//code to add to minDist from the current point, also relaxes the minDist by not updating if the current value is already better.
		//does not check for "visited" as, given no negative weights, it shouldn't update previously visited vertices. Inefficient, but, good enough for our small case
		for (int i = 0; i < numVerts; i++) {
			//only updates if vertex is reachable directly and is less than the current existing value
			if (edges[curIndex][i] != INT_MAX && edges[curIndex][i] + curDist < minDist[i]) {
				minDist[i] = edges[curIndex][i] + curDist;
				pastVert[i] = curIndex;
			}
		}
		//re-sort remaining vertex distances
		sortAndReturnNext(curOrderIndex + 1);
		//return value not really used

	}
	
	return minDist[end];
}

void djkObj::tracePath(int start, int end)
{
	if (start == end) {
		std::cout << convertToName(start) << " ";
	}
	else {
		tracePath(start, pastVert[end]);
		std::cout << convertToName(end) << " ";
	}
}

void djkObj::resetOrder()
{
	for (int i = 0; i < numVerts; i++) {
		//default order (ascending)
		vertexOrder[i] = i;
	}
}

djkObj::djkObj()
{
	for (int i = 0; i < numVerts; i++) {
		//default NO PATH
		minDist[i] = INT_MAX;
		//default NO PREVIOUS
		pastVert[i] = -1;
		//default order (ascending)
		vertexOrder[i] = i;
	}
}

djkObj::~djkObj()
{
}
