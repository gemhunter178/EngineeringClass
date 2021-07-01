/*header file for sorting methods, with counts for swaps (moves) and comparisons
based on slides, but written by [me]
Has Section, Bubble, Insertion, Merge and Quick sorts, with some helper functions*/

#pragma once
//make sure we don't have multiple declarations
#ifndef DBUGSORTS_H
#define DBUGSORTS_H

/*finds largest in given array
Array[]: the input array
array_size: the size of the array */
template <class itmType>
int findIndexWithLargest(const itmType[], const int, int&);

/* swaps given item and increases move counter by 1
Array[]: the array containing things to be swapped
index1: one of the indexes to by swapped to
index2: the other index in the swap
&moves: the move counter to increment*/
template <class itmType>
void swapItms(itmType[], int, int, int&);

/*typical selectionsort, using findIndexWithLargest()
Array[]: the array to sort
array_size: the size of the array
&moves: the number of moves used in sorting
&comps: the number of comparisons made in sorting*/
void selectionSort(int[], const int, int&, int&);


/*typical bubblesort
Array[]: the array to sort
array_size: the size of the array
&moves: the number of moves used in sorting
&comps: the number of comparisons made in sorting*/
void bubbleSort(int[], const int, int&, int&);

/*typical insertionsort
Array[]: the array to sort
array_size: the size of the array
&moves: the number of moves used in sorting
&comps: the number of comparisons made in sorting*/
void insertionSort(int[], const int, int&, int&);

/* helper "merge" for the end of mergesorting
Array[]: the array to sort
first: the first index
mid: the middle index
last: the last index
&moves: the number of moves used in sorting
&comps: the number of comparisons made in sorting
*/
void merge(int[], int, int, int, int&, int&);
/*mergesort
Array[]: the array to sort
array_size: the size of the array
&moves: the number of moves used in sorting
&comps: the number of comparisons made in sorting*/
void mergeSort(int[], const int, int&, int&);

/*order()
exchanges two array indices when necessary
Array[]: the array in question
i: the first index in question
j: the other index
&moves: the number of moves so far
&comps: the number of comparisons so far*/
void order(int[], int, int, int&, int&);
/*sortFirMidLas()
exchanges first, middle and last points of an array to be in order
Array[]: the array in question
first: the first index of the array
last: the last index of the array
&moves: the number of moves so far
&comps: the number of comparisons so far
returns the index of mid*/
int sortFirMidLas(int[], int, int, int&, int&);
/*partition()
partitions the entries in an array relative to a pivot
Array[]: the array in question
first: the first index of the array
last: the last index of the array
&moves: the number of moves so far
&comps: the number of comparisons so far
returns the new pivot index*/
int partition(int[], int, int, int&, int&);
/*quicksort
Array[]: the array to sort
array_size: the size of the array
&moves: the number of moves used in sorting
&comps: the number of comparisons made in sorting*/
void quickSort(int[], const int, int&, int&);

//prints moves and comps
void printSortInfo(int moves, int comps);

//checks if array is sorted
bool checkSort(int[], const int);


#endif // !DBUGSORTS_H