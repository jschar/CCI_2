/*
	One Away: There are three types of edits that can be performed on 
strings: insert a character, remove character, or replace a character. 
Given two strings, write a function to check if they are one edit (or zero edits) away.

Example:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false

	Solution 1: Step through both strings at the same time and skip the first different
but fail on the second.

*/

#include <iostream>
#include <string>

using namespace std;

bool oneAway_01(const string &str01, const string &str02);
bool oneAwayPair(const string &str01, const string &str02);
bool oneAwaySkew(const string &str01, const string &str02);

int main(void){

	string str1 = "";
	string str2 = "";

	str1 = "aabb";
	str2 = "aabb";
	cout << str1 << " | " << str2 << ": " <<  oneAway_01(str1,str2) << endl;

	str1 = "aabb";
	str2 = "aacc";
	cout << str1 << " | " << str2 << ": " << oneAway_01(str1, str2) << endl;

	str1 = "aabb";
	str2 = "aacb";
	cout << str1 << " | " << str2 << ": " << oneAway_01(str1, str2) << endl;

	str1 = "aabb";
	str2 = "aab";
	cout << str1 << " | " << str2 << ": " << oneAway_01(str1, str2) << endl;

	str1 = "aabb";
	str2 = "aac";
	cout << str1 << " | " << str2 << ": " << oneAway_01(str1, str2) << endl;

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}

bool oneAway_01(const string &str01, const string &str02){
	// If both strings are empty or only have one character between them then they're "one away".
	if( str01.length() <= 1 && str02.length() <= 1 ){ return true; }

	//If either string has a length difference of more than 2 then they can't be "one away".
	if( (int)str01.length() - (int)str02.length() >= 2 
	 || (int)str02.length() - (int)str01.length() >= 2 ){ return false; }

	bool retVal = false;
	if( str01.length() == str02.length() ){
		retVal = oneAwayPair( str01, str02 );
	} else {
		retVal = oneAwaySkew( str01, str02 );
	}
	return retVal;
}

bool oneAwayPair(const string &str01, const string &str02){
	if (str01.length() != str02.length()) { return false; } // Strings must be the same length.
	bool strike = false; // Flag to keep track of differences.
	
	for( int i=0; i<str01.length(); i++ ){
		if(str01[i] != str02[i]){
			if(!strike){
				strike = true;
			} else {
				return false;
			}
		} 
	}
	return true;
}

bool oneAwaySkew(const string &str01, const string &str02){

	if( str01.length() == str02.length() ){ return false; } // String can't be same length.

	string smStr = (str01.length() < str02.length()) ? str01 : str02;
	string lgStr = (str01.length() > str02.length()) ? str01 : str02;
	bool strike = false;

	int i=0, j=0;

	while( i < smStr.length() ){
		if(smStr[i] != lgStr[j]){
			if(!strike){
				strike = true;
			} else {
				return false;
			}
		} else {
			i++;
		}
		j++;
	}
	return true;
}