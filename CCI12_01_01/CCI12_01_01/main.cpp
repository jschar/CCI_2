/*
	12.1 Last K Lines: Write a method to print the last K lines of an input file using c++.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

fstream* openFile(const string &fName);
void lastKlines(const string& fName, int k);

/*
	lastKlines(string, int)
	string fName: file to open and read.
	int k: Number of last lines to read.
		The original idea was to count all the lines in the file and then seek to the beginning of the last k.
	A better idea is to just maintain a queue of size k and when we stop reading from the file we must have the
	last k lines in the queue.
*/

void lastKlines(const string& fName, int k){
	fstream *myFile = openFile(fName);
	if(!myFile){ cout << "File not found." << endl; return; }
	string line;
	queue<string> queLines;
	
	while(myFile->peek() != EOF){
		getline(*myFile,line);
		queLines.push(line);
		if(queLines.size() > k){
			queLines.pop();
		}
	}

	while(queLines.size()){
		cout << queLines.front() << endl;
		queLines.pop();
	}
	myFile->close();
}

/*
	openFile(string)
	fName: File name to open.

	opens a file for reading.
*/
fstream* openFile(const string &fName){
	fstream *rFile = new fstream(fName, istream::in);
	return rFile->good()?rFile:nullptr;
}

int main(void){

	string fileStr = "testFile.txt";
	lastKlines("otherFile.txt",5);
	lastKlines(fileStr, 3);

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}