#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "list.h"

class QueueOnList
{
private:
 List list;
public:
  // конструкторы
  QueueOnList();                            // List();
  QueueOnList(DataType* arr, int size);     // List(DataType* arr, int size);

  // деструктор
  ~QueueOnList();                        // ~List();

  // основные методы
  void pop();                               // void DeleteHead();
  void push(const DataType& val);           // void InsertToTail(const DataType& d);
  bool isEmpty();                           // bool isEmpty();

  // доп. методы
  // DataType front();
  // DataType back();
  // int getSize();

  // вывод на экран
  void print();
};

#endif  // __QUEUE_H__
