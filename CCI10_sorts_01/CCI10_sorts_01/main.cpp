/*
	Bubble sort, insertion sort, selection sort, merge sort, quick sort, radix sort, heap sort.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
	Bubble sort. O(n^2)
	Bubble sort or as I like to call it push sort, since we're pushing values to the beginning/end
	of the array.
	Bubble sort is bad because of its slow execution time. We have to iterate through the entire list and compare
	all elements for every element.
*/
void bubbleSort(int *arr, int size){
	for(int i=0; i<size-1; i++){
		for(int j=size-1; j>i; j--){
			if(arr[j-1] > arr[j]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

/*
	Insertion sort. O(n^2)
	As we iterate through our array, the new element is push through the array until its neighboris a value lower than it.
	Insertion sort is bad because as we iterate through the array we push the new value through the array by copying
	other values backward, making space for the new value next to an appropiate neighbor.
*/

void insertionSort(int *arr, int size){
	for(int i=1; i<size; i++){
		bool found = false;
		int j = i;
		while(!found && j>0){
			if(arr[j-1] > arr[j]){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
			} else {
				found = true;
			}
		}
	}
}

/*
	Selection sort.

	Iterate through the array and find the index of the smallest element and then swap it with the
	expanding sorted array.
	
*/

void selectionSort(int *arr, int size){
	for(int i=0; i<size-1; i++){
		int min_index = i;
		for(int j=i+1; j<size; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}



void mergeSort(int*,int);
void mergeSort(int*, int, int);
void merge(int*, int, int, int);

/*

Merge sort. Space O(n), Time O(nlogn)
Merge sort uses recursion to split an array into small pieces, then sorts those smallest pieces,
and then returns two sorted lists that then can be merged.

You have to copy the elements into a temp array.

*/
void mergeSort(int *arr, int size){
	if(size <= 1){ return; }
	mergeSort(arr, 0, size-1);
}

/*
	Merge sort helper.
	Passes split array and passes array to be merged.
*/

void mergeSort(int *arr, int start, int end){
	if( start < end ){
		int mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid+1, end); // Mid gets a +1 here because a size two array the start and mid will be the same index.
	}
}

/*
	merge
	Merge two sorted arrays. Uses a temporary array to merge the sorted array.
*/

void merge(int *arr, int start, int mid, int end){
	int tSize = end-start+1;	// Temporary size.
	int *tArr = new int[tSize](); // Temporary array to hold our sorted values.
	int sIndex = start; // The front of our sorted array.
	int mIndex = mid; // The front of the second sorted array.

	for(int i=0; i<tSize; i++){	// Loop the number of elements in our array.
		if( mIndex > end || (sIndex < mid && arr[sIndex] < arr[mIndex]) ){ // Take smaller element from left half of the array.
			tArr[i] = arr[sIndex];
			sIndex++;
		} else {					// Take smaller element from the right half of the array.
			tArr[i] = arr[mIndex];
			mIndex++;
		}
	}

	for(int j=0; j<tSize; j++){ // Copy eveything out of our temporary index.
		arr[start+j] = tArr[j];
	}
}

/*
	Quick Sort
	
	Take the end of the array as the pivot and swap it to the wall when done.
	Move a wall and iterate through the array swapping elements smaller than the pivot with the wall.
	Swap the pivot back with the wall, recurse and split the array.
*/

void quickSort(int*,int,int);
void quickSort(int *arr, int size){
	if(size <= 1){ return; }
	quickSort(arr,0,size-1);
}

void quickSort(int *arr, int start, int end){
	if(start >= end){ return; }
	int pivot = arr[end];
	int wIndex = start; // wall index.
	
	for(int i=start; i<end; i++){
		if(arr[i] <= pivot){
			if(i != wIndex) {
				int temp = arr[i];
				arr[i] = arr[wIndex];
				arr[wIndex] = temp;			
			}
			wIndex++;
		}
	}

	int temp = arr[end];
	arr[end] = arr[wIndex];
	arr[wIndex] = temp;

	quickSort(arr, start, wIndex-1); // Left half.
	quickSort(arr, wIndex, end);
}

void radixSort(int *arr, int size){

}

void heapSort(int *arr, int size){

}


void printArr(int *arr, int size){
	for(int i=0; i<size; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(void){
	
	srand(time(nullptr));

	int iArr[20] = {0};

/*
	for(int i=0; i<20; i++){ iArr[i] = (rand() % 20) + 1; }
	cout << "Bubble sort." << endl;
	printArr(iArr,20);
	bubbleSort(iArr,20);
	printArr(iArr,20);

	for (int i = 0; i<20; i++) { iArr[i] = (rand() % 20) + 1; }
	cout << "Insertion sort." << endl;
	printArr(iArr, 20);
	insertionSort(iArr, 20);
	printArr(iArr, 20);

	for (int i = 0; i<20; i++) { iArr[i] = (rand() % 20) + 1; }
	cout << "Selection sort." << endl;
	printArr(iArr, 20);
	selectionSort(iArr, 20);
	printArr(iArr, 20);

	for (int i = 0; i<20; i++) { iArr[i] = (rand() % 20) + 1; }
	cout << "Selection sort." << endl;
	printArr(iArr, 20);
	mergeSort(iArr, 20);
	printArr(iArr, 20);

	for (int i = 0; i<20; i++) { iArr[i] = (rand() % 20) + 1; }
	cout << "Selection sort." << endl;
	printArr(iArr, 20);
	quickSort(iArr, 20);
	printArr(iArr, 20);
*/
	
	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}