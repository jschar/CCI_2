/*

Route between nodes: Given a directed graph, design an algorithm to find out whether there
is a route between two nodes.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include "BinaryTree.hpp"
#include "GraphInter.hpp"

using namespace std;

enum PLACES_T { ALABAMA=0, IOWA, NEVADA, TEXES, WISCONSIN, OHIO, PL_MAX };

string place2string( PLACES_T inPlace ){
	string outStr = "";
	switch(inPlace){
		case 0: outStr = "Alabama"; break;
		case 1: outStr = "Iowa"; break;
		case 2: outStr = "Nevada"; break;
		case 3: outStr = "Texes"; break;
		case 4: outStr = "Wisconsin"; break;
		case 5: outStr = "Ohio"; break;
		default: outStr = "Error"; break;
	};
	return outStr;
}

string str2Upper( string inStr ){
	for( int i=0; i<inStr.length(); i++ ){
		inStr[i] = toupper(inStr[i]);
	}
	return inStr;
}

#define SSPACE 6

int main(void){

	GraphInterface<int> aGra(PL_MAX);

	aGra.add(ALABAMA, NEVADA);
	aGra.add(NEVADA, WISCONSIN);
	aGra.add(WISCONSIN, OHIO);
	aGra.add(IOWA,TEXES);
	//aGra.printMat();

	cout << setw(SSPACE) << ' '; // Spacing.
	for( int i=0; i<PL_MAX; i++ ){
		// Names across top.
		string state = place2string(PLACES_T(i));
		cout << setw(SSPACE)<< right << str2Upper(state.substr(0,4));
	}
	cout << endl;
	for(int j=0; j<PL_MAX; j++){
		string state = place2string(PLACES_T(j));
		cout << setw(SSPACE) << str2Upper(state.substr(0,4));
		for( int k=0; k<PL_MAX; k++ ){
			cout << right << setw(SSPACE) << aGra.isConnected(j,k);
		}
		cout << '\n' << endl;
	}

	cout << (aGra.findPath(ALABAMA, OHIO)? "True":"False") << endl;
	cout << (aGra.findPath(IOWA, OHIO)? "True":"False") << endl;
	
	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}