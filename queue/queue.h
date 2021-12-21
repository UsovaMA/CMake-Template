#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "list.h"

class QueueOnList
{
private:
 List list;
public:
  // ������������
  QueueOnList();                            // List();
  QueueOnList(DataType* arr, int size);     // List(DataType* arr, int size);

  // ����������
  ~QueueOnList();                        // ~List();

  // �������� ������
  void pop();                               // void DeleteHead();
  void push(const DataType& val);           // void InsertToTail(const DataType& d);
  bool isEmpty();                           // bool isEmpty();

  // ���. ������
  // DataType front();
  // DataType back();
  // int getSize();

  // ����� �� �����
  void print();
};

#endif  // __QUEUE_H__
