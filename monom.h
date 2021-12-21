#ifndef __MONOM_H__
#define __MONOM_H__

class Monom
{
private:
  // char varName;
  int coefficient;
  int deg;
public:
  // конструкторы

  Monom() {};
  Monom(int coef, int deg) {};
  Monom(const Monom& m) {};

  // деструктор - не обязательно, динамически выделенной памяти нет, поля очистятся автоматически

  // сеттеры, геттеры

  /* ... */

  // перегрузка основных операторов сравнения

  bool operator==(const Monom& m)const;
  bool operator!=(const Monom& m)const;
  bool operator<=(const Monom& m)const;
  bool operator>=(const Monom& m)const;
  bool operator>(const Monom& m)const;
  bool operator<(const Monom& m)const;

  // перегрузка математических операторов (в нашей программе возможны только + -, без *)

  Monom operator+(const Monom& m)const;
  Monom operator-(const Monom& m)const;
  Monom& operator+=(const Monom& m);
  Monom& operator-=(const Monom& m);

  Monom operator-()const;

  int calculate(int x);

  // вывод на экран (или перегрузка оператора вывода <<)

  void print() {};
};

#endif  // __MONOM_H__
