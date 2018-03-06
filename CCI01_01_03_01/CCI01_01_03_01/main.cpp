/*

	Cptr.1, pg.90, IQ.1.3
	URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string.(Note: If implementing in Java, please use a character array so that your can
perform this operation in place.)

Example:
Inpute: "Mr John Smith     ",13
Output: "Mr%20John%20Smith"

*/

#include <iostream>
#include <string>

using namespace std;

string urlifyCPY(const string &inStr);
char* urlifyPTR(const string &inStr, const int n);

int main(void){

	string str1 = "The googles yo";
	string str2 = "ab cd";

	cout << urlifyCPY(str1) << endl;
	cout << urlifyPTR(str1, str1.length() + 6) << endl;
	//cout << urlifyPTR(str2, 7) << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}

string urlifyCPY(const string &inStr){
	if(inStr.length() <= 0){ return inStr; }

	string outStr = "";
	for(int i=0; i < inStr.length(); i++){
		if(inStr[i] == ' '){
			outStr += "%20";
		} else {
			outStr += inStr[i];
		}
	}
	return outStr;
}

char* urlifyPTR( const string &inStr, const int n){
	
	char *cArr = new char[n+1];
	int j = 0;
	for(int i=0; i < inStr.length(); i++){
		if(inStr[i] == ' '){
			cArr[j] = '%'; j++;
			cArr[j] = '2'; j++;
			cArr[j] = '0'; j++;
		} else {
			cArr[j] = inStr[i];
			j++;
		}
	}
	cArr[j] = '\0';

	return cArr;
}