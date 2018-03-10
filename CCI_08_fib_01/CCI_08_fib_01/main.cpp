/*


*/

#include <iostream>
#include <Windows.h>

using namespace std;

int fib_01(int i){
	cout << i << endl;
	if(i == 0){ return 0; }
	if(i == 1){ return 1; }
	return fib_01(i-1) + fib_01(i-2);
}

int fib_02(int i);

int fib_helper(int i, int* memo){
	if (i <= 0) { return 0; }
	if (i == 1) { return 1; }
	if (memo[i] != -1) { return memo[i]; }
	memo[i] = fib_helper(i - 1, memo) + fib_helper(i - 2, memo);
	return memo[i];
}

int fib_02(int i){
	int *arr = new int[i+1](); // The +1 is so we can use i as a index and a position.
	for(int j=0; j<=i; j++){ 
		arr[j] = -1;
	}
	int outVar = fib_helper(i, arr);
	delete arr;
	return outVar;
}

int main(void){

	cout << fib_01(20) << endl;
	cout << "fib_01(20)" << endl;
	cin.ignore();

	cout << fib_02(20) << endl;
	cout << "fib_02(20)" << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}
