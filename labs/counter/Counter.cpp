#include "Counter.h"
//#include "List.cpp"
//#include "Index.cpp"
//#include "Iterator.cpp"

// Counter Member Functions

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
  		int found = hashTable.lookup(key);
		if(found != -1){
			hashTable.getNode(found)->value += by;
			return;
		}
		Node* temp = inOrder.insert(key, by);
		hashTable.insert(key, temp);
		cou++;
		if(cou >= .5*hashTable.getCap()){
			reSize();
		}
  	}

	void Counter::dec(const std::string& key, int by){
        	int found = hashTable.lookup(key);
                if(found != -1){
                        hashTable.getNode(found)->value -= by;
                        return;
                }
                Node* temp = inOrder.insert(key, -by);
                hashTable.insert(key, temp);
                cou++;
		if(cou >= .5*hashTable.getCap()){
                        reSize();
                }
  	}

  void Counter::del(const std::string& key){
	int found = hashTable.lookup(key);
        if(found != -1){
		hashTable.del(found);
		inOrder.remove(hashTable.getNode(found));	
		cou--;
	}
  }
  int  Counter::get(const std::string& key) const{
  	int found = hashTable.lookup(key);
        if(found != -1){
	return hashTable.getNode(found)->value;
	}
	else{
	return 0;
	}
  }
  void Counter::set(const std::string& key, int count){
  	int found = hashTable.lookup(key);
	if(found != -1){
	hashTable.getNode(found)->value = count;
	return;
	}
	Node* temp = inOrder.insert(key, count);
        hashTable.insert(key, temp);
        cou++;
	if(cou >= .5*hashTable.getCap()){
                 reSize();
        }
  }
	
	Counter::Iterator Counter::begin() const{
		return Counter::Iterator(inOrder.getHead());
	}

	Counter::Iterator Counter::end() const{
                return Counter::Iterator(nullptr);
        }
void Counter::reSize(){
	size_t cap = hashTable.getCap();
        dirtyCheck* newTable = new dirtyCheck[cap*10];

	dirtyCheck* oldTable = hashTable.getTable();

	hashTable.setTable(newTable);
	hashTable.setCap(cap*10);

        for(size_t i = 0; i < cap; i++){
                if(oldTable[i].dirty){
                        hashTable.insert(oldTable[i].key, oldTable[i].listNode);
                }
        }
        delete [] oldTable;
}
