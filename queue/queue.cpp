#include "queue.h"

QueueOnList::QueueOnList() {}
QueueOnList::QueueOnList(DataType* arr, int size) : list(arr, size) { }

// ����������
QueueOnList::~QueueOnList() {}

// �������� ������
void QueueOnList::pop() {
  list.DeleteHead();
}

void QueueOnList::push(const DataType& val) {
  list.InsertToTail(val);
}

bool QueueOnList::isEmpty() {
  return list.isEmpty();
}

// ����� �� �����
void QueueOnList::print() {
  list.print("<-");
}