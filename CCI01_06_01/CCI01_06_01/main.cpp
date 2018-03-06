/*

	String Compression:Implement a method to perform basic string compression using the counts
of repeated characters. For example, the stirng aabcccccaaa would become a2b1c5a3.
If the "compressed" string would not become smaller than the original string, your method
should return the original string. You can assume the string has uppercase and lowercase
letters (a-z).

*/

#include <iostream>
#include <string>

using namespace std;

string cmpStr( const string &inStr ){

	if(inStr.length() < 2){ return inStr; }

	string outStr = "";
	char lastChar = '\0';
	int count = 0;
	outStr = "";

	for( const char &c : inStr ){
		if( tolower(c) != lastChar ){
			if(count != 0){ 
				outStr += to_string(count);
			}
			count = 1;
			lastChar = tolower(c);
			outStr += lastChar;
		} else {
			count++;
		}
	}
	outStr += to_string(count);
	return (outStr.length() < inStr.length()) ? outStr : inStr;
}

int main(void){

	string str01 = "aaabbbcccc";
	cout << str01 << " : " << cmpStr(str01) << endl;

	str01 = "abcdef";
	cout << str01 << " : " << cmpStr(str01) << endl;

	str01 = "aAabcccZzz";
	cout << str01 << " : " << cmpStr(str01) << endl;

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}