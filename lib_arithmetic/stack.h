// объ€вление и реализаци€ шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, +
// - извлечение элемента, +
// - просмотр верхнего элемента (без удалени€)+
// - проверка на пустоту, +
// - получение количества элементов в стеке+
// - очистка стека+
// при вставке в полный стек должна перевыдел€тьс€ пам€ть

#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class T>
class Stack
{
private:
	T* stack; //указатель на стек
	int size; //количество элементов в стеке
	int index; // номер текущего элемента в стеке
public:
	Stack(int s = 10); 
	Stack(const Stack<T>& s);
	~Stack();

	void Push(const T val);     // вставка элемента в вершину стека
	T& Pop();                   // извлечение элемента из стека
	T& See(); // просмотр верхнего элемента(без удалени€)
	bool isEmpty(); // проверка на пустоту
	int Number(); //количество элементов в стеке
	void Clean(); //очистка стека
};

template<class T> 
Stack<T>::Stack(int s)
{
	if (s >= 0)
	{
		size = s;
		index = -1;
		stack = new T[size];
	}
	else
		throw std::exception("Error: array size cannot be negative");
}

template<class T>
Stack<T>::Stack(const Stack<T>& s)
{
	size = s.size;
	index = s.index;
	stack = new T[s.size];
	for (int i = 0; i < size; i++)
	{
		stack[i] = s.stack[i];
	}
}

template<class T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template<class T>
void Stack<T>::Push(const T val)
{
	if (index + 1 < size)
	{
		index++;
		stack[index] = val;
	}
	else
	{
		Stack<T> Copy(*this);
		delete[] stack;
		size = size * 2;
		stack = new T[size];
		for (int i = 0; i, size; i++)
			stack[i] = Copy.stack[i];
		index++;
		stack[index] = val;
	}
}

template<class T>
T& Stack<T>::Pop()
{
	if (isEmpty())
		throw std::exception("Error: stack is empty");
	return stack[index--];
}

template<class T>
T& Stack<T>::See()
{
	if (isEmpty())
		throw std::exception("Error: stack is empty");
	return stack[index];
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (index == -1)
		return true;
	else
		return false;
}

template<class T>
int Stack<T>::Number()
{
	return index + 1;
}

template<class T>
void Stack<T>::Clean()
{
	size = 0;
}
#endif