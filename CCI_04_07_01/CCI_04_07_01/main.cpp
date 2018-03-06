/*

	4.7: Build Order: You are given a list of projects and a list of dependencies (which is a list
of pairs of projects, where the first project is dependent of the second project). All of a project's
dependencies must be built before the project is. Find a build order that will alllow the projects 
to be built. If there is no valid build order, return an error.

input:
projects: a,b,c,d,e,f
dependencies: (d,a), (b,f), (d,b), (a,f), (c,d)
output: f,e,a,b,d,c


*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <stack>
#include <utility>

using namespace std;

class Graph{
private:
	unordered_map<string, list<string>> adj;

public:
	void addNode(string node);
	void addEdge(string start, string end);

};

void Graph::addNode(string node){
	adj[node];
}


void Graph::addEdge(string start, string end){
	if( adj.count(start) > 0 ){
		adj[start].remove(end);
	}
	adj[start].push_front(end);
}

void topologicalSortUtil(unordered_map<string,list<string>> &inMap, string node, unordered_map<string, bool> &visited, stack<string> &inSta){
	visited[node] = true;
	for( auto it = inMap[node].begin(); it != inMap[node].end(); it++ ){
		if(!visited[*it]){
			topologicalSortUtil(inMap, *it, visited, inSta);
		}
	}
	inSta.push(node);	
}

void topologicalSort(unordered_map<string,list<string>> &inMap){
	stack<string> aSta;
	unordered_map<string, bool> visited;

	for( auto it = inMap.begin(); it != inMap.end(); it++ ){
		visited[it->first] = false;
	}

	for( auto it = inMap.begin(); it != inMap.end(); it++ ){
		if(!visited[it->first]){
			topologicalSortUtil(inMap, it->first, visited, aSta);
		}
	}

	while(!aSta.empty()){
		cout << aSta.top() << " ";
		aSta.pop();
	}
}

int main(void){

	unordered_map<string,list<string>> aMap;

	aMap["5"].push_front("2");
	aMap["5"].push_front("0");
	aMap["4"].push_front("0");
	aMap["4"].push_front("1");
	aMap["2"].push_front("3");
	aMap["3"].push_front("1");
	aMap["1"];
	aMap["0"];

	topologicalSort(aMap);

	cout << "End of line." << endl;
	cin.ignore();
	return 0;
}