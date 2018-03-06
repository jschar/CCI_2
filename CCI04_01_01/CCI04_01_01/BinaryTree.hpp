#pragma once
#ifndef BTREE_H
#define BTREE_H

template<class T>
class BTree{
private:
	struct Node{
		T* data;
		Node* child[2];
	};

	Node* root;

public:
	

};

#endif
