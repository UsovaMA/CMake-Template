#include "list.h"

Node::Node(DataType d, Node* n) : data(d), next(n) {
}

Node::Node(const Node& node2) {
  data = node2.data;
}

bool Node::operator==(const Node& node2) const {
  return (data == node2.data);
}

List::List() {
  head = nullptr;
}



List::~List() {
  Node* tmp, *tmp1; // указатель-ходилка
  tmp = head;
  tmp1 = tmp;
  while (tmp1 != nullptr)
  {
    tmp1 = tmp->next;
    delete tmp;
    tmp = tmp1;
  }
}


void List::InsertToHead(const DataType& d)
{
  if (isEmpty())
  {
    head = new Node(d, nullptr); // это первый и единственный
  }
  else
  {
    head = new Node(d, head);
  }
}

void List::InsertToTail(const DataType& d)
{
  if (isEmpty())
  {
    head = new Node(d, nullptr); // это первый и единственный
  }
  else
  {
    Node* p = new Node(d, nullptr);
    Node* tmp; // указатель-ходилка
    tmp = head;
    while (tmp->next != nullptr)
    {
      tmp = tmp->next;
    }
    // в итоге - tmp - последний
    tmp->next = p;
  }
}

void List::Clean()
{
  Node* tmp;
  if (isEmpty())
    return;

  while (head->next != nullptr)
  {
    tmp = head->next;
    head->next = tmp->next; // head->next->next;
    delete tmp;
  }
  delete head;
  head = nullptr;
}

void List::Delete(const DataType& d)
{
  // найти значение
  // найти того, кто перед ним
  Node* prev = head;
  Node* tmp;
  bool find = false;

  // данные в голове
  if (head->data == d)
  {
    head = head->next;
    delete prev; // сейчас это голова
    find = true;
  }

  while (!find && (prev->next != nullptr))
  {
    if (prev->next->data == d)
    {
      // prev->next - это звено
      tmp = prev->next;
      prev->next = prev->next->next; // tmp->next
      delete tmp;
      find = true;
    }
    else
      prev = prev->next;
  }
}


List::List(DataType* arr, int size) {
  if (arr != nullptr) {
    head = new Node(arr[0], nullptr);
    Node* tmp = head;                              // указатель на начало НИКОГДА не используем для движения по списку!!!!
    for (int i = 1; i < size; i++) {
      Node* elem = new Node(arr[i], nullptr);      // создаём звено
      tmp->next = elem;                            // цепляем его
      tmp = tmp->next;                             // сдвигаем временный указатель
    }
  } else {
    throw std::exception("Empty Input Data!");
  }
}

void List::DeleteHead() {
  if (!isEmpty()) {
    Node* tmp = head;
    head = head->next;
    delete tmp;
  }
}

void List::print(char* direction = "->") {    // найти другой способ фикса
  if (!isEmpty()) {
    Node* tmp = head;
    while (tmp->next != nullptr) {
      std::cout << "(" << tmp->data << ")" << direction;                   // (1)->(3)->(2)->
      tmp = tmp->next;                                                     // сдвигаем временный указатель
    } 
    std::cout << "(" << tmp->data << ")" << direction;
  }
  std::cout << "NULL" << std::endl;                                        // (1)->(3)->(2)->NULL
}
