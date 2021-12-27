#include "Stackonlist.h"

StackOnList::StackOnList(){}
StackOnList::StackOnList(DataType* arr, int size) : list(arr, size) { }
StackOnList::~StackOnList(){}

void StackOnList::pop()
{
	list.DeleteToTail();
}

void StackOnList::push(const DataType& val)
{
	list.InsertToTail(val);
}

bool StackOnList::isEmpty()
{
	return list.isEmpty();
}

void StackOnList::StackClean()
{
	list.Clean();
}

void StackOnList::print()
{
	list.print("<-");
}