/*
	Bubble sort, insertion sort, selection sort, merge sort, quick sort, radix sort, heap sort.

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

/* Print the given array.*/
void printArr(int *arr, int size);
void bubbleSort(int *arr, int size);
void insertionSort(int *arr, int size);
void selectionSort(int *arr, int size);
void mergeSort(int *arr, int size);
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void quickSort(int *arr, int size);
void quickSort(int *arr, int start, int end);
int getMax(int *arr, int size);
int getMin(int *arr, int size);
void countSort(int *arr, int size);
void radixSort(int *arr, int size);
void countSort(int *arr, int size, int exp);
void heapSort(int *arr, int size);
void heapify(int *arr, int size, int i);
void swap( int* a, int* b);

/*
	Bubble sort. O(n^2)
	Bubble sort or as I like to call it push sort, since we're pushing values to the beginning/end
	of the array.
	Bubble sort is bad because of its slow execution time. We have to iterate through the entire list and compare
	all elements for every element.
*/
void bubbleSort(int *arr, int size) {
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

/*
	getMax
	Return the largest value in an array.
*/
int getMax(int *arr, int size){
	if(size <= 0){ return INT_MIN; }
	if(size == 1){ return arr[0]; }
	int max = arr[0];
	for(int i=0;i<size; i++){
		if(arr[i] > max){ max = arr[i]; }
	}
	return max;
}

/*
	getMin
	Return the smallest value in an array.
*/
int getMin(int *arr, int size){
	if(size <= 0){ return INT_MIN; }
	if(size == 1){ return arr[0]; }
	int min = arr[0];
	for(int i=0; i<size; i++){
		if(arr[i] < min){ min = arr[i]; }
	}
	return min;
}

/*
	Counting sort. Time O(n+k), Space O(n+k)

	With counting sort we count all the numbers in the unsorted into another array. The count array is then added
	together which then becomes a position array. Elements in the unsorted array are read again but are used to
	look up it positions in the count array, sort of like a hash. Using the positions and the elements in the
	unsorted array a new sorted arrary is made.

	Points to be noted:
	1. Counting sort is efficient if the range of input data is not significantly greater than the number
	of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K
	and the data is 10, 5, 10K, 5K.
	2. It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
	3. It is often used as a sub-routine to another sorting algorithm like radix sort.
	4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
	5. Counting sort can be extended to work for negative inputs also.
*/

void countSort(int *arr, int size) {
	if(size <= 1){ return; }
	int low = getMin(arr, size);
	int high = getMax(arr, size);
	int cSize = high-low+1; // size of the count array.
	int *cArr = new int[cSize](); // The count and position array.
	int *sArr = new int[size](); // The array sorted.

	for(int i=0; i<size; i++){
		cArr[arr[i]-low]++;	// Count elements in the array.	
	}

	for(int i=0; i<cSize-1; i++){
		cArr[i+1] = cArr[i] + cArr[i+1]; //Add up array.
	}

	for(int i=0; i<size; i++){ // Sort array.
		sArr[cArr[arr[i]-low]-1] = arr[i]; 
		cArr[arr[i]-low]--;
	}

	for(int i=0; i<size; i++){ // Copy elements from the sorted array into the in array.
		arr[i] = sArr[i];
	}
}

/*
	Radix sort. 

	Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in range from 1 to k. What if
	the elements are in range from 1 to n2?	We can’t use counting sort because counting sort will take O(n2) which is worse
	than comparison based sorting algorithms. Can we sort such an array in linear time?	Radix Sort is the answer. The idea
	of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort
	uses counting sort as a subroutine to sort.

	What is the running time of Radix Sort?
	Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers,
	for example, for decimal system, b is 10. What is the value of d? If k is the maximum possible value, then d would be
	O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison
	based sorting algorithms for a large k. Let us first limit k. Let k <= nc where c is a constant. In that case, the
	complexity becomes O(nLogb(n)). But it still doesn’t beat comparison based sorting algorithms. What if we make value of
	b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we get the time complexity
	as O(n). In other words, we can sort an array of integers with range from 1 to nc if the numbers are represented in base
	n (or every digit takes log2(n) bits).
*/

void radixSort(int *arr, int size){
	int m = getMax(arr,size); // Largest has the most digits to step through.
	for( int exp=1; m/exp>0; exp*=10){
		countSort(arr, size, exp);
	}
}

/*
	Counting sort for radix.
	exp is used to sort a digit at a specific place.
*/

void countSort(int *arr, int size, int exp) {
	if (size <= 1) { return; }
	int cSize = 10; // 0-9.
	int *cArr = new int[cSize](); // The count and position array.
	int *sArr = new int[size](); // The array sorted.

	for (int i = 0; i<size; i++) {
		cArr[(arr[i]/exp)%10]++;	// Count elements in the array.	
	}

	for (int i = 0; i<cSize - 1; i++) {
		cArr[i + 1] += cArr[i]; //Add up array.
	}

	for (int i = size-1; i>=0; i--) { // Step backwads through the array.
		sArr[cArr[(arr[i]/exp)%10]-1] = arr[i];
		cArr[(arr[i]/exp)%10]--;
	}

	for (int i = 0; i<size; i++) { // Copy elements from the sorted array into the in array.
		arr[i] = sArr[i];
	}
}

/*
	Max heapSort.

	Time Complexity: Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap()
	is O(n) and overall time complexity of Heap Sort is O(nLogn).

	Manipulate an array so it resembles a max heap.
*/
void heapSort(int *arr, int size){
	for(int i = size / 2 - 1; i >= 0; i--){
		heapify(arr, size, i);
	}
}

void heapify(int *arr, int size, int i){
	int largest = i; // I is the temp root for the tree underneath it.
	int l = 2*i+1; // Left child of the temp root.
	int r = 2*i+2; // Right child of the temp root.

	// If the left child is larger than the root then swap it.
	if( l < size && arr[l] > arr[largest] ){
		largest = l;
	}

	// If the right child is larger than the root then swap it.
	if( r < size && arr[r] > arr[largest] ){
		largest = r;
	}

	// If the largest changed then it won't be the root and we need to swap it.
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, size, largest); // Largest is the index of the child we swapped so recurse down that way.
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


void printArr(int *arr, int size){
	for(int i=0; i<size; i++){
		cout << setw(4) << arr[i];
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
	cout << "Merge sort." << endl;
	printArr(iArr, 20);
	mergeSort(iArr, 20);
	printArr(iArr, 20);

	for (int i = 0; i<20; i++) { iArr[i] = (rand() % 20) + 1; }
	cout << "Quick sort." << endl;
	printArr(iArr, 20);
	quickSort(iArr, 20);
	printArr(iArr, 20);

	for (int i = 0; i<20; i++) { iArr[i] = (rand() % 40) + 1 - 20; }
	cout << "Count sort." << endl;
	printArr(iArr, 20);
	countSort(iArr, 20);
	printArr(iArr, 20);

	for (int i = 0; i<20; i++) { iArr[i] = rand() % 20 + 1; }
	cout << "Count sort." << endl;
	printArr(iArr, 20);
	radixSort(iArr, 20);
	printArr(iArr, 20);
*/

	for (int i = 0; i<20; i++) { iArr[i] = rand() % 20 + 1; }
	cout << "Heap sort." << endl;
	printArr(iArr, 20);
	heapSort(iArr, 20);
	printArr(iArr, 20);
	
	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}