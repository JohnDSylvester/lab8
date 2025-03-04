#include "Counter.h"
#include "Iterator.cpp"

// Counter Member Functions
//

	Counter::Counter(){
		cou = 0;
	}
	Counter::~Counter(){
		inOrder.clear();
	}

  size_t Counter::count() const{
  	return cou;
  }

  int   Counter::total() const{
  	int result = 0;
	Node* tracer = inOrder.getHead();
	while(tracer != nullptr){
		result += tracer->value;
		tracer = tracer->next;
	}
	return result;
  }

  	void Counter::inc(const std::string& key, int by){
  		Node* temp = inOrder.find(key);
        	if(temp != nullptr){
			temp->value += by;
			return;
		}
		inOrder.insert(key, by);
		cou++;
  	}

	void Counter::dec(const std::string& key, int by){
        	Node* temp = inOrder.find(key);
                if(temp != nullptr){
                        temp->value -= by;
                        return;
                }
                inOrder.insert(key, -by);
		cou++;
  	}

  void Counter::del(const std::string& key){
  	inOrder.remove(key);
  }
  int  Counter::get(const std::string& key) const{
  	Node* temp = inOrder.find(key);
	if(temp != nullptr){
	return temp->value;
	}
	else{
	return 0;
	}
  }
  void Counter::set(const std::string& key, int count){
  	Node* temp = inOrder.find(key);
	if(temp != nullptr){
	temp->value = count;
	return;
	}
	inOrder.insert(key, count);
	cou++;
  }
	
	Counter::Iterator Counter::begin() const{
		return Counter::Iterator(inOrder.getHead());
	}

	Counter::Iterator Counter::end() const{
                return Counter::Iterator(nullptr);
        }
