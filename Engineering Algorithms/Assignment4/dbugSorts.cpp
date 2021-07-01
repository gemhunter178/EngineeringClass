/*
dbugSorts.cpp
Implementation files for the sorting functions with debug numbers (moves and comparisions)
*/

//include header file for the implementations
#include "dbugSorts.h"
#include <iostream> //cout

#pragma once

//definitions
template <class itmType>
int findIndexWithLargest(const itmType Array[], int array_size, int& comps) {
	int currentLargest = 0; //initializes to first index
	//go through the entire Array
	for (int currentIndex = 1; currentIndex < array_size; currentIndex++) {
		//see if current index holds value greater than item at currentLargest
		if (Array[currentIndex] > Array[currentLargest]) {
			currentLargest = currentIndex;
		} //end if
		comps++; //increase comparisons as the if statement makes a comparison
	} //end for
	return currentLargest;
}

template<class itmType>
void swapItms(itmType Array[], int index1, int index2, int & moves)
{
	itmType temp = Array[index2];
	Array[index2] = Array[index1];
	Array[index1] = temp;
	//increase moves
	moves = moves + 3;
}

//selection sort
//template<class itmType>
void selectionSort(int Array[], const int array_size, int& moves, int& comps)
{
	//cycle through entire array, swap largest with end of unsorted array
	for (int cycle = 0; cycle < array_size; cycle++) {
		//find largest value in unsorted part of array
		int largest = findIndexWithLargest(Array, array_size - cycle, comps);
		//only switch if largest is not at the end
		if (largest != array_size - cycle - 1) {
			//use swap function with increment moves capability
			swapItms(Array, largest, array_size - cycle - 1, moves);
			//debug
			//std::cout << "Move #" << moves << " swapped " << Array[largest] << " with " << Array[array_size - cycle - 1] << "\n";
		} //end swap if
		//this if statement above is also a comparison
		comps++;
	} //end for
	return;
}


//bubblesort
void bubbleSort(int Array[], const int array_size, int& moves, int& comps)
{
	//bool for if the array requires more sorting
	bool sorted = false; //default false so it will check at least once
	//what cycle we are on
	int cycle = 1;
	//runs as long as it's not sorted and we have not cycled everything
	while (!sorted && cycle < array_size) {
		//assume sorted until a moe proves otherwise
		sorted = true;
		for (int curIndex = 0; curIndex < array_size - cycle; curIndex++){
			//move if the items are in the wrong order
			if (Array[curIndex] > Array[curIndex + 1]) {
				swapItms(Array, curIndex, curIndex + 1, moves);
				sorted = false;
			}//end if
			//above is a comparison
			comps++;
		}//end for
		//prepare for next pass
		cycle++;
	}//end while
	return;
}

//insertionsort
void insertionSort(int Array[], const int array_size, int& moves, int& comps)
{
	//loop for looking through the unsorted part of the array (first index at int "unsorted") and placing into correct place in sorted array
	for (int unsorted = 1; unsorted < array_size; unsorted++) {
		//temporarily save current index item
		int currentInt = Array[unsorted];
		//is a move, according to assignment
		moves++;
		//current location that is being shifted right
		int loc = unsorted;
		//keep shifting items right until value at Array[unsorted] is less than tested value (where it should be inserted)
		while (loc > 0) {
			if (Array[loc - 1] > currentInt) {
				//shift right
				Array[loc] = Array[loc - 1];
				loc--;
				//this is a move
				moves++;
			}
			else {
				//once location is found, break the while loop
				//one extra comparison that would not have counted
				comps++;
				break;
			}//end if...else
			//this if has a comparison
			comps++;
			
		}//end while
		
		//now loc should be where the currentInt should go...
		if (loc != unsorted) { //do not switch if item already in right location
			//place item there
			Array[loc] = currentInt;
			//this is a move
			moves++;
		}//end if
		 //this if has a comparison
		comps++;
	}//end while
	return;
}

//mergesort and helper "merge()"
void merge(int Array[], int first, int mid, int last, int& moves, int& comps) {
	//make temporary array
	int tempArray[1000]; //max size of an array in this program (unfortunately, value is stored in main1.cpp and this value needs to change if value in main1.cpp is changed)
	//initialize index variables
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	//while both subarrays are not empty, copy smaller value into temporary array
	//current active index in tempArray
	int index = first1;
	while ((first1 <= last1) && (first2 <= last2)) {
		//while statement has 2 comparisons
		comps = comps + 2;
		if (Array[first1] <= Array[first2]) {
			//debug (commented out)
			//std::cout << "\n" << first1 << " " << Array[first1] << ", " << first2 << " " << Array[first2];
			//if Array[first1] has a smaller value
			tempArray[index] = Array[first1];
			//this is a move
			moves++;
			first1++;
		}
		else { //Array[first2] has a smaller value
			tempArray[index] = Array[first2];
			//also a move
			moves++;
			first2++;
		}//end if else
		//move index up one
		index++;
		//if has a comparison
		comps++;
	}//end while
	//missing one set of 2 comparisons from FALSE of while loop
	comps = comps + 2;
	//finish off the subarray that wasn't completely moved over yet
	while (first1 <= last1) {
		//these are comparisons
		comps++;
		// At this point, tempArray[first..index‐1] is in order
		tempArray[index] = Array[first1];
		//this is a move
		moves++;
		first1++;
		index++;
	} // end while
	while (first2 <= last2) {
		//these are comparisons
		comps++;
		// At this point, tempArray[first..index‐1] is in order
		tempArray[index] = Array[first2];
		//this is a move
		moves++;
		first2++;
		index++;
	} // end while
	//account for two comparisons that made the while loop false
	comps = comps + 2;
	  // Copy the result back into the original array
	for (index = first; index <= last; index++) {
		//debug (commented out)
		/*
		if (index < 2) {
			std::cout << "\npassing " << tempArray[index] << " to " << index;
		}
		*/
		Array[index] = tempArray[index];
		//this is a move
		moves++;
	}//end for
	return;
}

void mergeSort(int Array[], const int array_size, int& moves, int& comps)
{
	//will only run if array_size is not 1 (an array of just one int)
	if (array_size > 1) {
		//is a comparison
		comps++;
		const int subArr1size = array_size / 2; //size of smaller array 1
		const int subArr2size = array_size - subArr1size; //size of sub array 2
		//std::cout << "\n0: " << Array[0] <<"\tmid: " << Array[subArr1size] << "\tend: " << Array[array_size - 1];
		//sort left half of Array
		mergeSort(Array, subArr1size, moves, comps);
		//right half
		mergeSort(Array+subArr1size, subArr2size, moves, comps);
		//debug (commented out)
		//std::cout << subArr1size << ": " << Array[subArr1size] << '\t';
		//merge the two halves
		merge(Array, 0, subArr1size - 1, array_size - 1, moves, comps);
	}
	return;
}

//quicksort and helper functions

void order(int Array[], int i, int j, int &moves, int &comps)
{
	if (Array[i] > Array[j]) {
		swapItms(Array, i, j, moves);
		//swapItms should account for moves
	}//end if
	//if statement is a comparison
	comps++;
}

int sortFirMidLas(int Array[], int first, int last, int &moves, int &comps)
{
	//find middle index
	int mid = first + (last - first) / 2;
	//sorts these three relative to each other
	order(Array, first, mid, moves, comps);
	order(Array, mid, last, moves, comps);
	order(Array, first, mid, moves, comps);
	//return middle index
	return mid;
}

int partition(int Array[], int first, int last, int &moves, int &comps)
{
	//get pivot index from sortFirMidLas() (makes this median-of-three)
	int pivIndex = sortFirMidLas(Array, first, last, moves, comps);
	//reposition pivot to be last in the array (except the last last, as that was already determined to be greater)
	swapItms(Array, pivIndex, last - 1, moves);
	//set where the pivot is now
	pivIndex = last - 1;
	//save pivot value
	int pivot = Array[pivIndex];
	//determine two subarray regions
	int indexLeft = first + 1;
	int indexRight = last - 2;
	//bool for if the operations are done
	bool done = false;
	//moving entries that are greater to the right of the pivot, and less to the left of the pivot
	while (!done) {
		//find first entry on the left that is >= pivot
		while (Array[indexLeft] < pivot) {
			//is a comparison
			comps++;
			indexLeft++;
		}
		//find first entry on the right that is <= pivot
		while (Array[indexRight] > pivot) {
			//is a comparison
			comps++;
			indexRight--;
		}
		//both above whiles will have a false, leading to two unaccounted for comparisons
		comps = comps + 2;
		//swap entries if indexLeft and indexRight have yet to cross each other
		if (indexLeft < indexRight) {
			swapItms(Array, indexLeft, indexRight, moves);
			indexLeft++;
			indexRight--;
		}
		else {
			//subarrays correctly partitioned
			done = true;
		}//end if else
		//if else statement is a comparison
		comps++;
	}//end while

	//place pivot in new location and state its new location
	swapItms(Array, pivIndex, indexLeft, moves);
	pivIndex = indexLeft;
	//debug (commented out)
	//std::cout << "\npivot index: " << pivIndex << "\tvalue: " << Array[pivIndex];
	return pivIndex;
}

//variable for minimum size that quickSort should be used on
static const int MIN_SIZE = 10;

void quickSort(int Array[], const int array_size, int& moves, int& comps)
{
	//this quicksort is different as I passed in different variables
	if (array_size < MIN_SIZE) {
		//is also a comparison
		comps++;
		//use insertion sort
		insertionSort(Array, array_size, moves, comps);
	}
	else {
		//partition array into <pivot, pivot, >pivot and save pivot location
		int pivIndex = partition(Array, 0, array_size - 1, moves, comps);
		//determine size of subarrays
		int subArr1Size = pivIndex;
		int subArr2Size = array_size - subArr1Size - 1;
		//sort subarrays
		quickSort(Array, subArr1Size, moves, comps);
		quickSort(Array + pivIndex + 1, subArr2Size, moves, comps);
	}//end if else
	return;
}

void printSortInfo(int moves, int comps)
{
	//prints passed in info
	std::cout << "Number of moves: " << moves << "\tNumber of comparisons " << comps << std::endl;
	return;
}

//check sort
bool checkSort(int Array[], const int array_size) {
	//default true (until an error is found)
	bool sorted = true;
	//check the array for any errors in sorting (if one index is > than the next index)
	for (int i = 1; i < array_size; i++) {
		if (Array[i] < Array[i - 1]) {
			//error found
			sorted = false;
			//does not need to check for another error.
			break;
		} //end if
	} //end for
	return sorted;
}



//end of implementation file