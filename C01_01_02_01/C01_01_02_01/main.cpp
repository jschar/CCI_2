/*
	Chapter 1, IQ 1.2, pg.90.
	1.2 Check Permutation: Given two strings, write a method to decide if one is a 
permutation of the other.
*/

#include <iostream>
#include <string>

using namespace std;

bool perm(const string &str1, const string &str2);

int main(void){

	string str1 = "aabbccdd";
	string str2 = "abcddddd";
	string str3 = "aabbccdd";

	perm(str1, str2) ? cout << "True." : cout << "False."; cout << endl;
	perm(str1, str3) ? cout << "True." : cout << "False."; cout << endl;
	
	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}

bool perm(const string &inStr1, const string &inStr2){
	const int NCHAR = 256; // Max number of chars.

	if(inStr1.length() != inStr2.length()){ return false; }

	int arr[NCHAR] = {0};
	int sum = 0;

	for(int i=0; i < inStr1.length(); i++){
		arr[inStr1[i]]++;
		arr[inStr2[i]]--;
	}

	for(int k=0; k < NCHAR; k++){
		if(arr[k] != 0){ return false; }
	}

	return true;
}