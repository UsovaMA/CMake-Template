#pragma once
#ifndef __STACK_H__
#define __STACK_H__
#include "list.h"

class StackOnList
{
private:
	List list;
public:
	StackOnList();								// List();
	StackOnList(DataType* arr, int size);		// List(DataType* arr, int size);

	~StackOnList();								// ~List();

	void pop();									// void DeleteTail();
	void push(const DataType& val);				// void InsertToHead(const DataType& d);
	bool isEmpty();								// bool isEmpty();
	void StackClean();

	void print();
};
#endif  // __STACK_H__