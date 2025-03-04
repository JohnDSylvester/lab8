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
	void List::insert(const std::string& key, const int & value){
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
	}

	void List::remove(const std::string& key){
		Node* tracer = head;
                while(tracer != nullptr){
			if(tracer->key == key){
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
				return;
			}
			tracer = tracer->next;
	}
	}

	Node* List::find(const std::string& key) const{
		Node* tracer = head;
		while(tracer != nullptr){
			if(tracer->key == key){
				return tracer; 
			}
			tracer = tracer->next;
		}

		return nullptr;
	}

	Node* List::getHead() const{
		return head;
	}
