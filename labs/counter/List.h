#ifndef LIST_H
#define LIST_H

// TODO...

#include <string>
#include <stdexcept>

struct Node{
	std::string key;
	int value;
	Node* next;
	Node* prev;

	Node(): key(""), value(0), next(nullptr), prev(nullptr){}
};


class List{
	private:
		Node* head;
		Node* tail;
	public:
		List();
		~List();
	
		Node* getHead() const;	
		Node* getTail() const;
		void clear();
		Node* insert(const std::string& key, const int & value);
		void remove(Node* toRemove);
};

#endif
