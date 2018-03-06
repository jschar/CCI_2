/*

	Zero Matrix: Write an algorithm such that if an element is a MxN matrix
is 0, its entire row and column are set to 0.

*/

#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

template <class T>
void zeroMat( T arr[][5], int n );

template <class T>
void printMat( T arr[][5], int n);

int main(void){

	int arr_01[][5] = {	{ 1, 2, 3, 4, 5},
						{ 6, 0, 8, 9,10},
						{11,12,13,14,15},
						{16,17,18, 0,20},
						{21,22,23,24,25}};

	printMat( arr_01, 5);
	zeroMat( arr_01, 5 );
	printMat( arr_01, 5 );

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}

template <class T>
void zeroMat( T arr[][5], int n ){

	if( n <= 0 ){ return; }

	bitset<5> rows(0);
	bitset<5> colm(0);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j] == 0 ){
				rows.set(i,1);
				colm.set(j,1);
			}
		}
	}

	for(int r=0; r<n; r++){
		for (int c = 0; c<n; c++) {
			if(rows.test(r) || colm.test(c)){ arr[r][c] = 0; }
		}
	}

	return;
}

template <class T>
void printMat(T arr[][5], int n){

	for( int i=0; i<n; i++ ){
		for( int j=0; j<n; j++ ){
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	return;
}