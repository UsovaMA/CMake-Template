#include "stack.h"

StackOnList::StackOnList() {};

StackOnList::StackOnList(DataType* arr, int size) : list(arr, size){};

StackOnList::~StackOnList() {};

void StackOnList::pop() {
	list.DeleteTail();
};

void StackOnList::push(const DataType& val) {
	list.InsertToHead(val);
};

bool StackOnList::isEmpty() {
	return list.isEmpty();
};

void StackOnList::print() {
	list.print("->");
};