#ifndef COUNTER_H
#define COUNTER_H

#include <cstddef>
#include <string>
#include "List.h"
#include "Index.h"
// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.

class Counter {
public:
  class Iterator {
    // Member Variables
	Node* current;
	std::string k;
	int v;


  public:
	Iterator(Node* c);
    const std::string& key() const;
    int value() const;

    void operator ++ ();
    bool operator == (const Iterator& other) const;
    bool operator != (const Iterator& other) const;
  };

private:
  // Member Variables
	List inOrder;
	Index hashTable;
	size_t cou;
private:
  // Helper Functions

public:
  Counter();
  ~Counter();

  size_t count() const;
  int    total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);
  void reSize();

  Iterator begin() const;
  Iterator end() const;
};

#endif
