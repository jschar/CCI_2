/*
	12.1 Last K Lines: Write a method to print the last K lines of an input file using c++.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class ArrQue {
private:
	int *arr;
	int size;
	int capacity;
	int start;
	int end;

public:
	ArrQue();
	void enQueue(int inData);
	int deQueue();
	int front();
	void doubleArray();
	void halfArray();
	void rebuildArray();

};

ArrQue::ArrQue(): arr(new int[10]()), size(0), capacity(10), start(0), end(0){

}

/*
	enQueue(int)
	inData: element to add to the end of the queue.

		
*/
void ArrQue::enQueue(int inData){
	if(size == capacity){
		this->doubleArray();
	}
	end = (end+1)%capacity;
	arr[end] = inData;
	size++;
}

int ArrQue::deQueue(){
	if(size <= 0){ return INT_MIN; }
	int rVal = arr[end];
	arr[end] = INT_MIN;
	end--;
	if(end <= -1){ end = capacity-1; }
	size--;
	if(capacity > 10 && size == capacity/4){
		this->halfArray();
	}
	return rVal;
}

int ArrQue::front(){
	return (size > 0)?arr[start]:INT_MIN;
}

void ArrQue::doubleArray(){
	int *tArr = new int[capacity*2]();
	int index = 0;
	while(this->front() != INT_MIN){
		tArr[index] = this->deQueue();
		index++;
	}
	start = 0;
	end = index-1;
	delete this->arr;
	this->arr = tArr;
}

void ArrQue::halfArray(){
	int *tArr = new int[capacity/2]();
	int index = 0;
	while(this->front() != INT_MIN){
		tArr[index] = this->deQueue();
		index++;
	}
	start = 0;
	end = index - 1;
	delete this->arr;
	this->arr = tArr;
}

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