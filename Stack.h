#include "queue.h"
#include "list.h"
#include <iostream>
using namespace std;

class Stack
{
private:
	List list;
public:
	// ������������
	Stack();                            // List();
	Stack(DataType* arr, int size);     // List(DataType* arr, int size);

	// ����������
	~Stack();                        // ~List();

	// �������� ������
	void Stackpush(const DataType& val);
	bool StackEmpty();
	void StackClean();
	void StackSee();
	DataType& StackGet();
	int StackNum();

	// ���. ������
	// DataType front();
	// DataType back();
	// int getSize();

	// ����� �� �����
	void print();
};
