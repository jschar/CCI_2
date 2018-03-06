/*

	Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

*/

#include <iostream>
#include <iomanip>

using namespace std;

template <class T, size_t rows, size_t colm>
void rotMatShft( T(&arr)[rows][colm] );

template <class T, int n>
void rotMat( T(&arr)[n][n] );

template <class T, size_t rows, size_t colm>
void printMat( T(&arr)[rows][colm] );

int main(void){

	int arr[5][5] = { { 1, 2, 3, 4, 5},
					  { 6, 7, 8, 9,10},
					  {11,12,13,14,15},
					  {16,17,18,19,20},
					  {21,22,23,24,25}};

	//printMat( arr );
	//rotMatShft( arr );
	//cout << endl;
	//printMat( arr );

	printMat( arr );
	rotMat( arr );
	cout << endl;
	printMat( arr );

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}

template <class T, size_t rows, size_t colm>
void rotMatShft( T(&arr)[rows][colm] ){
	if(rows != colm){ return; } 

	T hold;
	size_t walker, levitate;
	for( size_t i = 0; i<rows/2; i++ ){
		hold = arr[i][i];
		size_t tlc = i;
		// walk right across the top.
		for(walker = i+1; walker < rows-i; walker++){
			// walker-1: copy walker backwards.
			arr[i][walker-1] = arr[i][walker];
		}
		// levitate down right side.
		for( levitate = i+1; levitate < colm-i; levitate++ ){
			arr[levitate-1][colm-i-1] = arr[levitate][colm-i-1];
		}
		// walk left across bottom.
		for( walker = colm-i-1-1; walker >= i; walker-- ){
			arr[rows-i-1][walker+1] = arr[rows-i-1][walker];
			if(walker == 0){ break; }
		}
		// levitate up but stop before second to last element.
		for( levitate = rows-i-1-1; levitate > i; levitate-- ){
			arr[levitate+1][i] = arr[levitate][i];
			if(levitate == 0){ break; }
		}
		// We copied the second to last element back and then insert
		// the element that would of been copied.
		arr[levitate+1][i] = hold;
	}

	return;
}

template <class T, int n>
void rotMat(T(&arr)[n][n]){

	if( n <= 1 || n <= 1 ){ return; }
	T hold;
	for(int i=0; i < n/2; i++){
		for(int j=i; j < n-i-1; j++){
			hold = arr[i][j]; // Top row.
			arr[i][j] = arr[n-1-j][i]; // Left side to top.
			arr[n-1-j][i] = arr[n-1-i][n-1-j]; // Bottom to left side.
			arr[n-1-i][n-1-j] = arr[j][n-1-i]; // Right side to bottom.
			arr[j][n-1-i] = hold; // Top to right side.
		}
	}

	return;
}

template <class T, size_t rows, size_t colm>
void printMat( T(&arr)[rows][colm] ){
	for( size_t i = 0; i < rows; i++ ){
		for( size_t j = 0; j < colm; j++ ){
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	return;
}