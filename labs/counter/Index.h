#ifndef INDEX_H
#define INDEX_H
#include "List.h"

// TODO...

struct dirtyCheck{
	std::string key;
	bool dirty;
	Node* listNode;
	dirtyCheck(){
		key = "";
		dirty = 0;
		listNode = nullptr;
	}
};

class Index{
		

	dirtyCheck* table;
	size_t cap;
	std::hash<std::string> stringHash;

	public:
	Index();
	Index(size_t capcity);
	~Index();

	void clear();
	void insert(const std::string& key, Node* add);
	int lookup(const std::string& key) const;
	void del(int index);
	void setCap(size_t newCap);
	void setTable(dirtyCheck* tab);
	dirtyCheck* getTable();
	Node* getNode(int index) const;
	size_t getCap();
	void reSize();
};
#endif
