#include "List.h" 

// List Member Functions
	List::List(){
		head = nullptr;
		tail = nullptr;
	}

	List::~List(){
		Node* tracer = head;
		Node* temp;
		while(tracer != nullptr){
			temp = tracer;
			tracer = tracer->next;
			delete temp; 
		}
	}	

	void List::clear(){
                Node* tracer = head;
                Node* temp;
                while(tracer != nullptr){
                        temp = tracer;
                        tracer = tracer->next;
                        delete temp;
        	}
		head = nullptr;
		tail = nullptr;
		}
	Node* List::insert(const std::string& key, const int & value){
		if(head == nullptr){
			head = new Node;
			head->prev = nullptr;
			head->key = key;
			head->value = value;
			head->next = nullptr;
			tail = head;
		}
		else{
			Node* temp = new Node;
			temp->key = key;
			temp->value = value;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
		return tail;
	}

	void List::remove(Node* toRemove){
		if(toRemove == nullptr){
			return;
		}

		Node* tracer = toRemove;
		if(tracer != head && tracer != tail){
			Node* last = tracer->prev;
			Node* ahead = tracer->next;
			last->next = tracer->next;
			ahead->prev = tracer->prev;
			}
		else if(tracer == head && tracer == tail){
			head = nullptr;
			tail = nullptr;
		}
		else if(tracer == head){
			head = tracer->next;
			head->prev = nullptr;
		}
		else{
			tail = tracer->prev;
			tail->next = nullptr;
		}
			delete tracer;
	}

	Node* List::getHead() const{
		return head;
	}
	Node* List::getTail() const{
		return tail;
	}
