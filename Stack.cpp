#include "Stack.h"

Stack::Stack() {}
Stack::Stack(DataType* arr, int size) : list(arr, size) { }

Stack::~Stack() {}

void Stack::Stackpush(const DataType& val) {
	list.InsertToTail(val);
}

bool Stack::StackEmpty() {
	return list.isEmpty();
}

DataType& Stack::StackGet()
{
	return list.DeleteLast();
}

void Stack::StackSee()
{
	list.seelast();
}

void Stack::StackClean()
{
	list.Clean();
}

int Stack::StackNum()
{
	return list.GetSize();
}

// вывод на экран
void StackOnList::print() {
	list.print("<-");
}