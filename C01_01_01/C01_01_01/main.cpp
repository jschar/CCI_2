/*
	Chapter 1, Interview questions, 1.1, pg.90
1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannnot
use additional data structures?

S1. Have a hash table that keeps a tally of all characters used. If a character is used more than once, return false.


*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>

using namespace std;

bool UnqStr( const string &inStr );
bool vUnqStr( const string &inStr );
bool UnqStr_bitVec( const string &inStr );

int main(void) {

	map<char, bool> map1;
	string str1 = "The quick red fox jumps over the lazy brown dog.";
	string str2 = "abcdefghijklmnopqrstuvwxyz";

	//UnqStr(str1) ? cout << "True" << endl : cout << "False" << endl;
	//UnqStr(str2) ? cout << "True" << endl : cout << "False" << endl;

	//vUnqStr(str1) ? cout << "True" << endl : cout << "False" << endl;
	//vUnqStr(str2) ? cout << "True" << endl : cout << "False" << endl;

	UnqStr_bitVec(str1) ? cout << "True" << endl : cout << "False" << endl;
	UnqStr_bitVec(str2) ? cout << "True" << endl : cout << "False" << endl;

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}

bool UnqStr( const string &inStr)
{
	map<char,bool> map1;
	bool isUnique = true;

	for(int i = 0; i < inStr.length() && isUnique; i++){
		if(map1.count(inStr[i]) > 0 ){
			isUnique = false;
		} else {
			map1[inStr[i]];
		}
	}
	return isUnique;
}

bool vUnqStr( const string &inStr ){
	if(inStr.length() > 128){ return false; }
	bool isUnique = true;
	vector<bool> charSet(128);
	for(int i=0; i<inStr.length(); i++){
		int val = inStr[i];
		if(charSet[val]){
			return false;
		}
		charSet[val] = true;
	}
	return true;
}

bool UnqStr_bitVec(const string &inStr){
	bitset<256> bits(0);
	for(int i=0; i<inStr.length(); i++){
		int val = inStr[i];
		if(bits.test(val) > 0){
			return false;
		}
		bits.set(val);
	}
	return true;
}