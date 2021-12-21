#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "monom.h"
#include "list.h"
#include "parser.h"

/* + ��������??? */

class Polynom
{
private:
  // ������� - ��� ������ �������
  List<Monom> monoms;                         // ������� ���� ������ ��������� ������� ��� ������������ std::list<Monom> monoms;
  // PolinomIterator it;
public:
  // ������������

  Polynom();
  Polynom(const Monom* _monoms);  // ��� Polynom(const std::vector<Monom>& _monoms);
  Polynom(const Polynom& p);

  // ����������

  ~Polynom();       // ????

  // ���������� ����������

  /* ... */

  // ���������� �������� �������� !!!!!!!!!!!!!!!!!!!!!!!!!!!

  int calculate(int x);

  // ����� �� ����� (��� ���������� ��������� ������ <<)

  void print() {};
};

#endif  // __POLYNOM_H__
