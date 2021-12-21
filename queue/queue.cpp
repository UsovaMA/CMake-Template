#include "queue.h"

QueueOnList::QueueOnList() {}
QueueOnList::QueueOnList(DataType* arr, int size) : list(arr, size) { }

// деструктор
QueueOnList::~QueueOnList() {}

// основные методы
void QueueOnList::pop() {
  list.DeleteHead();
}

void QueueOnList::push(const DataType& val) {
  list.InsertToTail(val);
}

bool QueueOnList::isEmpty() {
  return list.isEmpty();
}

// вывод на экран
void QueueOnList::print() {
  list.print("<-");
}