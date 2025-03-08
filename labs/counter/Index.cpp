#include "Index.h"

// Index Member Functions
Index::Index(){
	cap = 10000;
	table = new dirtyCheck[cap];
}

Index::Index(size_t capcity){
        cap = capcity;
        table = new dirtyCheck[cap];
}

Index::~Index(){
	delete [] table;
}

void Index::clear(){
	delete [] table;
}

void Index::insert(const std::string& key, Node* add){
	size_t index = stringHash(key);
	size_t probe = 0;

        while(table[(index+(probe * probe)) % cap].listNode != nullptr){
              probe++;
        }
	

	
	table[(index+(probe * probe)) % cap].listNode = add; 
	table[(index+(probe * probe)) % cap].key = key;
	table[(index+(probe * probe)) % cap].dirty = 1;
}

int Index::lookup(const std::string& key) const{
	size_t index = stringHash(key);
	size_t probe = 0;

	while(table[(index+(probe * probe)) % cap].dirty){
		if(table[(index+(probe * probe)) % cap].key == key){
			return (index+(probe * probe)) % cap;
		}
		else{
			probe++;
		}
	}
	return -1;
}

void Index::del(int index){
	table[index].listNode = nullptr;
	table[index].key = "";
}

void Index::setCap(size_t newCap){
	cap = newCap;
}
void Index::setTable(dirtyCheck* tab){
	table = tab;
}

dirtyCheck* Index::getTable(){
	return table;
}

Node* Index::getNode(int index) const{ 
	return table[index].listNode;
}

size_t Index::getCap(){
	return cap;
}
