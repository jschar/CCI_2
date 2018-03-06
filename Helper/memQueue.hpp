#ifndef MEM_QUEUE
#define MEM_QUEUE

#include <utility>

template <typename T>
class memQueue{
private:
	struct Node{
		T value;
		Node *next;

		Node(T &&v): value(std::move(v)), next(nullptr){

		}
	};

	
	Node *last;
	size_t queueSize;
public:
	Node *first;

	memQueue(): first(nullptr), last(nullptr), queueSize(0){
	}

	memQueue(memQueue && other): first(std::move(other.first)), last(std::move(other.last)), queueSize(std::move(other.queueSize)){
	}
	
	~memQueue(){
		while(!isEmpty()){
			remove();
		}
	}

	template <typename U>
	void add(U &&value){
		auto n = new Node(std::forward<U>(value));
		if(!first){
			first = n;
		} else {
			last->next = n;
		}
		last = n;
		queueSize++;
	}

	T& peek(){
		if(!first){
			throw QueueIsEmptyException();
		}
		return first->value;
	}
	
	T remove(){
		if(!first){
			throw QueueIsEmptyException();
		}
		auto value(std::move(first->value));
		auto n = first;
		first = n->next;
		if(!first){
			last= nullptr;
		}
		delete n;
		queueSize--;
		return value;
	}

	bool isEmpty() const{
		return !first;
	}


	size_t size() const{
		return queueSize;
	}


	class QueueIsEmptyException { };
};


#endif