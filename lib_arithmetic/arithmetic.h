// объявление функций и классов для вычисления арифметических выражений
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include "stack.h"
#include <string>
#include <vector>
using namespace std;

using namespace std;

struct Lexema
{
	string val; //значение лексемы
	int type;  //тип лексемы
	double x;  //значение числа или переменной

	Lexema()
	{
		val = "0";
		type = -1;
		x = 0.0;
	}

	Lexema(string v, int t = -1)
	{
		val = v;
		type = t;
		x = 0.0;
	}

	Lexema(char v, int t = -1)
	{
		val = v;
		type = t;
		x = 0.0;
	}

	int operator ==(const Lexema& l) const
	{
		return((val == l.val) && (type == l.type));
	}

	friend ostream& operator<<(ostream os, const Lexema& l)
	{
		os << l.val;
		return os;
	}

	~Lexema() {}
};

class Arithmetic
{
	string input;
	double res;
	int status; //статус обработки
	vector<Lexema> lexInput;//массив лексем
	vector<Lexema> lexPolish;// массив лексем в порядке ПЗ
public:
	 Arithmetic(string s = "");
	 ~Arithmetic();
	 void Divide();//разбить на лексемы
	 void Converting();//преобразовать в ПЗ
	 void Variable_value();//запросить значение переменной
	 void Calculation();//вычисление выражения
	 void Launch();//запуск
	 vector<Lexema> Input_Lex();
	 vector<Lexema> Input_Polish();
	 double Result();
	 void Input();
	 bool check_brackets();
};
#endif