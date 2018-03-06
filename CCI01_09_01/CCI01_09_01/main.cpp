/*

	1.9 String Rotation: Assume you have a method isSubstring which checks if
one word is a substring of another. Given two string, s1 and s2, write code to
check if s2 is a rotation of s1 using only one call to isSubstring(e.g.,"waterbottle"
is a rotation of "erbottlewat").

*/

#include <iostream>
#include <string>

using namespace std;

bool isSubstring( const string &gStr, const string &fStr);

bool isRot(const string &rotStr, const string &fStr);

int main(void){

	string str1 = "", str2 = "";

	str1 = "apple";
	str2 = "pplea";
	cout << str1 << " | " << str2 << " : " << ((isRot( str1, str2 ))? "True" : "False"); cout << endl;

	str1 = "racecar";
	str2 = "ecarrac";
	cout << str1 << " | " << str2 << " : " << ((isRot(str1, str2)) ? "True" : "False"); cout << endl;

	str1 = "racecar";
	str2 = "eccarra";
	cout << str1 << " | " << str2 << " : " << ((isRot(str1, str2)) ? "True" : "False"); cout << endl;

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}

bool isSubstring( const string &gStr, const string &fStr){
	return ( gStr.find(fStr) != string::npos );
}

bool isRot( const string &rotStr, const string &fStr ) {
	if(rotStr.length() <= 1 || rotStr.length() != fStr.length()){ return false; }
	string tempBuff = rotStr + rotStr;
	return isSubstring(tempBuff, fStr);
}