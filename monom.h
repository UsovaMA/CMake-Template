#ifndef __MONOM_H__
#define __MONOM_H__

class Monom
{
private:
  // char varName;
  int coefficient;
  int deg;
public:
  // ������������

  Monom() {};
  Monom(int coef, int deg) {};
  Monom(const Monom& m) {};

  // ���������� - �� �����������, ����������� ���������� ������ ���, ���� ��������� �������������

  // �������, �������

  /* ... */

  // ���������� �������� ���������� ���������

  bool operator==(const Monom& m)const;
  bool operator!=(const Monom& m)const;
  bool operator<=(const Monom& m)const;
  bool operator>=(const Monom& m)const;
  bool operator>(const Monom& m)const;
  bool operator<(const Monom& m)const;

  // ���������� �������������� ���������� (� ����� ��������� �������� ������ + -, ��� *)

  Monom operator+(const Monom& m)const;
  Monom operator-(const Monom& m)const;
  Monom& operator+=(const Monom& m);
  Monom& operator-=(const Monom& m);

  Monom operator-()const;

  int calculate(int x);

  // ����� �� ����� (��� ���������� ��������� ������ <<)

  void print() {};
};

#endif  // __MONOM_H__
