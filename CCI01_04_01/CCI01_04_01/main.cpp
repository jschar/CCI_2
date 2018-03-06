/*

	1.4
	Palindrome Permutation: Given a string, write a function to check if it is a permutation
of a palindrome. A palindrome is a word  or phrase that is the same forwards and backwards. A 
permutation is a rearrangement of letters. The palindrome does not need to be limited to just
dictionary words.

Example:
Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc.)

*/

#include <iostream>
#include <string>

using namespace std;
int getCharIndex(char c);
void countFrequency(const string &inStr, int *frequency);
bool palinDrom_01(const string &inStr );
bool palinDrom_02(const string &inStr );
int toggle( int bitVector, int index );
bool isExactlyOneBitSet( int bitVector);
bool palinDrom_03(const string &inStr );

int main(void){

	string str("Tact Coa");
	cout << "Does \"" << str << "\" has a string whose permutatin is a pallindrome? "
		 << "( 1 for true, 0 for false ) : ";
	
	cout << "Approach 1: " << palinDrom_01(str) << endl;
	cout << "Approach 2: " << palinDrom_02(str) << endl;
	cout << "Approach 3: " << palinDrom_03(str) << endl;
	//--------------------------------
	str = "A big Cat";
	cout << "Does \"" << str << "\" has a string whose permutatin is a pallindrome? "
		<< "( 1 for true, 0 for false ) : ";

	cout << "Approach 1: " << palinDrom_01(str) << endl;
	cout << "Approach 2: " << palinDrom_02(str) << endl;
	cout << "Approach 3: " << palinDrom_03(str) << endl;
	//--------------------------------
	str = "Aba cbc";
	cout << "Does \"" << str << "\" has a string whose permutatin is a pallindrome? "
		<< "( 1 for true, 0 for false ) : ";

	cout << "Approach 1: " << palinDrom_01(str) << endl;
	cout << "Approach 2: " << palinDrom_02(str) << endl;
	cout << "Approach 3: " << palinDrom_03(str) << endl;
	
	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}

int getCharIndex(char c){
	int idx = -1;
	if( c >= 'a' && c <= 'z' ){
		idx = c -'a';
	} else if( c >= 'A' && c <= 'Z' ){
		idx = c - 'A';
	}
	return idx;
}

void countFrequency(const string &inStr, int *frequency){
	int idx;
	for(const char &c : inStr){
		idx = getCharIndex(c);
		if( idx != -1 ){
			++frequency[idx];
		}
	}
}

bool palinDrom_01(const string &inStr ){
	int frequency[26] = {0};
	countFrequency( inStr, frequency );

	bool oddAppeared = false;
	cout << endl;
	for( int i=0; i<26; i++ ){
		if( frequency[i] % 2 && oddAppeared ){
			return false;
		} else if ( frequency[i] % 2 && !oddAppeared ){
			oddAppeared = true;
		}
	}
	return true;
}

bool palinDrom_02(const string &inStr){
	int oddCount = 0;
	int frequency[26] = {0};
	int idx = 0;
	for( const char &c: inStr ){
		idx = getCharIndex(c);
		if( idx != -1 ){
			frequency[idx]++;
			if( frequency[idx] % 2 ){
				oddCount++;
			} else {
				oddCount--;
			}
		}
	}
	return (oddCount <= 1);
}

int toggle(int bitVector, int index){
	if(index < 0){ return bitVector; }
	int mask = 1 << index;
	if( (bitVector & mask) == 0 ){
		// This will add a bit the bitvector.
		bitVector |= mask;
	} else {
		//This removes a bit from the bitvector.
		bitVector &= ~mask;
	}
	return bitVector;
}

/*
	Helper funtion to find if a single bit is set
	i.e. if bitVector is a multiple of power 2.
*/
bool isExactlyOneBitSet(int bitVector){
	return(( bitVector & (bitVector - 1)) == 0);	
}

bool palinDrom_03(const string &inStr){
	int bitVector = 0;
	int id = 0;
	for( const char &c : inStr ){
		id = getCharIndex(c);
		bitVector = toggle(bitVector, id);
	}
	return( bitVector == 0 || isExactlyOneBitSet(bitVector) );
}