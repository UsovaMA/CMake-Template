#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "monom.h"
#include "list.h"
#include "parser.h"

/* + итератор??? */

class Polynom
{
private:
  // полином - это список мономов
  List<Monom> monoms;                         // сделать свой список шаблонным классом или использовать std::list<Monom> monoms;
  // PolinomIterator it;
public:
  // конструкторы

  Polynom();
  Polynom(const Monom* _monoms);  // или Polynom(const std::vector<Monom>& _monoms);
  Polynom(const Polynom& p);

  // деструктор

  ~Polynom();       // ????

  // перегрузка операторов

  /* ... */

  // вычисление значения полинома !!!!!!!!!!!!!!!!!!!!!!!!!!!

  int calculate(int x);

  // вывод на экран (или перегрузка оператора вывода <<)

  void print() {};
};

#endif  // __POLYNOM_H__
