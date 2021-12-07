#include "queue.h"
#include "list.h"
#include <iostream>
using namespace std;

class Stack
{
private:
	List list;
public:
	// конструкторы
	Stack();                            // List();
	Stack(DataType* arr, int size);     // List(DataType* arr, int size);

	// деструктор
	~Stack();                        // ~List();

	// основные методы
	void Stackpush(const DataType& val);
	bool StackEmpty();
	void StackClean();
	void StackSee();
	DataType& StackGet();
	int StackNum();

	// доп. методы
	// DataType front();
	// DataType back();
	// int getSize();

	// вывод на экран
	void print();
};
