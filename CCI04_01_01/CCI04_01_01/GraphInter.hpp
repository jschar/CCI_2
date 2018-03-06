#pragma once
#ifndef _GRAPH_INTER_HPP
#define _GRAPH_INTER_HPP

#include <iostream>
#include <utility>
#include <queue>

template<class T>
class GraphInterface {

private:
	bool **adjMat;
	int size;

public:

	GraphInterface();
	GraphInterface( int n );
	~GraphInterface();
	void printMat();
	void printList();

	//virtual int getNumVertices() const = 0;
	//virtual int getNumEdges() const = 0;
	//virtual bool add( T start, T end, int edgeWeight) = 0;
	//virtual bool remove(T start, T end) = 0;
	//virtual int getEdgeWeight(T start, T end) const = 0;
	//virtual void depthFirstTraversal(T start, void visit(T&)) = 0;
	//virtual void breadthFirstTraversal(T start, void visit(T&)) = 0;
	//bool add(T start, T end, int edgeWeight);
	bool add(int start, int end);
	bool remove(int start, int end);
	bool isConnected(int start, int end);
	bool findPath(int start, int end);

	bool addL(int start, int end);
	bool removeL(int start, int end);

};

template<class T>
GraphInterface<T>::GraphInterface() {
	adjMat = nullptr;
	size = 0;
	adjList = nullptr;
}

template<class T>
GraphInterface<T>::GraphInterface(int n) {
	if( n > 0 ){
		adjMat = new bool*[n];
		adjMat[0] = new bool[n*n]{0};
		for( int i = 1; i < n; i++ ){
			adjMat[i] = adjMat[0] + i * n;
		}
		size = n;
	}
}

template<class T>
GraphInterface<T>::~GraphInterface(){
	if(adjMat[0]){ delete [] adjMat[0]; }
	delete [] adjMat;
}

template<class T>
void GraphInterface<T>::printMat(){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout << ' ' << adjMat[i][j];
		}
		cout << endl;
	}
}

template<class T>
void GraphInterface<T>::printList(){
	for( int i=0; i<size; i++ ){
		adjList[i].print();
	}
}

template<class T>
bool GraphInterface<T>::add(int start, int end){
	if(adjMat){
		adjMat[start][end] = true;
		adjMat[end][start] = true;
		return true;
	}
	return false;
}

template<class T>
bool GraphInterface<T>::remove(int start, int end){
	if(adjMat){
		adjMat[start][end] = false;
		adjMat[end][start] = false;
		return true;
	}
	return false;
}

template<class T>
bool GraphInterface<T>::isConnected(int start, int end){
	return adjMat[start][end];
}

template<class T>
bool GraphInterface<T>::findPath(int start, int end){
	if(start == end){ return true; }
	bool *visited = new bool[size]{0};
	queue<int> mQue;
	int *pl = nullptr;
	visited[start] = true;
	mQue.push(start);
	while(mQue.size() > 0){
		if(mQue.front() == end){
			return true;
		}
		for(int i=0; i<size; i++){
			if(adjMat[mQue.front()][i] == true && !visited[i]){
				mQue.push(i);
			} 
		}
		mQue.pop();
	}
	return false;	
}

template<class T>
bool GraphInterface<T>::addL(int start, int end){
	bool success = false;
	if(adjList){
		success = adjList[start].add(end);
	}
	return success;
}

template<class T>
bool GraphInterface<T>::removeL(int start, int end){

}

#endif
