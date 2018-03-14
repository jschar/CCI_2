/*
	12.2: Reverse String: Implement a function void reverse(char* str) in C or C++
	which reverses a null-terminated string.
*/

#include <iostream>

using namespace std;

void reverse(char* str){
	if(str == nullptr){ return; } // No string.
	if(str[0] == '\0' || str[1] == '\0'){ return; } // Return if the string is empty or has one element.
	int size = 0;
	while(str[size] != '\0'){
		size++;
	}
	for(int i = 0; i < size/2; i++){
		char temp = str[i];
		str[i] = str[size-1-i];
		str[size-1-i] = temp;
	}
}

int main(void){
	char arr[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	reverse(arr);
	int index = 0;
	while(arr[index] != '\0'){
		cout << arr[index] << ' ';
		index++;
	}
	cout << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}