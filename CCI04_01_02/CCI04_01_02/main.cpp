#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class GraphMap{

private:
	unordered_map<string, list<string>> adjList;

public:

	void add(string start, string end);
	void removeNode(string node);
	void removeEdge(string start, string end);
	bool findPath(string start, string end);
	void print();

};

void GraphMap::add(string start, string end){
	adjList[start];
	adjList[end];
	adjList[start].remove(end);
	adjList[start].push_front(end);
}

void GraphMap::removeNode(string node){
	if(adjList.count(node) > 0){
		adjList.erase(node);
		for( unordered_map<string,list<string>>::iterator it = adjList.begin(); it != adjList.end(); it++ ){
			it->second.remove(node);
		}
	}
}

void GraphMap::removeEdge(string start, string end) {
	adjList[start].remove(end);
}

bool GraphMap::findPath(string start, string end){
	if(start == end){ return true; } // Start and end at the same place.
	if(adjList.empty()){ return false; } // Return false is the adjacency list is empty.
	if(adjList.count(start) == 0 || adjList.count(end) == 0){ return false; } // One of the nodes is missing.
	queue<string> aQue;
	aQue.push(start);
	while(!aQue.empty()){
		string place = aQue.front();
		aQue.pop();
		for( list<string>::iterator it = adjList[place].begin(); it != adjList[place].end(); it++ ){
			if(*it == end){ return true; }
			aQue.push(*it);
		} 
	}
	return false;
}

void GraphMap::print(){
	for( unordered_map<string, list<string>>::iterator it = adjList.begin(); it != adjList.end(); it++ ){
		cout << it->first << " :";
		for( list<string>::iterator lIt = it->second.begin(); lIt != it->second.end(); lIt++ ){
			cout << ' ' << *lIt;
		}
		cout << endl;
	}
}

int main(void){

	GraphMap aGra;

	//aGra.add("A","B");
	//aGra.add("B","C");
	//aGra.add("B","D");
	//aGra.print(); cout << "////////" << endl;
	//aGra.removeNode("E");
	//aGra.removeNode("C");
	//aGra.print(); cout << "////////" << endl;
	//aGra.removeEdge("B","D");
	//aGra.print(); cout << "///////" << endl;

	aGra.add("A","B");
	aGra.add("B","C");
	aGra.add("B","D");
	aGra.add("D","E");
	aGra.print(); cout << endl;
	
	cout << (aGra.findPath("A","E")? "True":"False") << endl;

	aGra.removeEdge("B","C");
	cout << (aGra.findPath("A","C")? "True":"False") << endl;

	cout << "End of line." << endl;
	cin.ignore();

	return 0;
}