// реализация функций и классов для вычисления арифметических выражений

#include "arithmetic.h"
#include <clocale>
using namespace std;

Arithmetic::Arithmetic(string s)
{
	input = s;
	if (s.empty())
		status = -1;
	else
		status = 0;
}

Arithmetic::~Arithmetic(){}

void Arithmetic::Divide()
{
	for (size_t i = 0; i < input.length(); i++)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string number = ".0123456789";
		size_t a_alf = alf.find(input[i]);
		size_t a_number = number.find(input[i]);

		Lexema temp(input[i]);

		if (input[i] != ' ')
		{
			if (input[i] == '(' || input[i] == '[' || input[i] == '{')
				temp.type = 0;
			else if (input[i] == ')' || input[i] == ']' || input[i] == '}')
				temp.type = -1;
			else if (input[i] == '+')
				temp.type = 1;
			else if (input[i] == '*' || input[i] == '/')
				temp.type = 2;
			else if (input[i] == '^')
				temp.type = 3;
			else if (input[i] == '-')
			{
				if (lexInput.empty() || (lexInput.back().type > -1 && lexInput.back().type < 5))
				{
					temp.val = "--";
					temp.type = 4;
				}
				else
					temp.type = 1;
			}
			else if (a_alf != alf.npos)
			{
				if (input[i] == 's' && input[i + 1] == 'i' && input[i + 2] == 'n' && input[i + 3] == '(')
				{
					temp.type = 5;
					temp.val = "sin";
					i = i + 2;
				}
				else if (input[i] == 'c' && input[i + 1] == 'o' && input[i + 2] == 's' && input[i + 3] == '(')
				{
					temp.type = 5;
					temp.val = "cos";
					i = i + 2;
				}
				else if (input[i] == 'e' && input[i + 1] == 'x' && input[i + 2] == 'p' && input[i + 3] == '(')
				{
					temp.type = 5;
					temp.val = "exp";
					i = i + 2;
				}
				else if (input[i] == 'l' && input[i + 1] == 'n' && input[i + 2] == '(')
				{
					temp.type = 5;
					temp.val = "ln";
					i = i + 1;
				}
				else
				{
					temp.type = -2;
					for (size_t j = i + 1; j < input.length(); j++)
					{
						a_alf = alf.find(input[j]);
						if (a_alf != alf.npos)
						{
							temp.val.push_back(input[j]);
							i++;
						}
						else
							j = input.length();
					}
				}
			}
			else if (a_number != number.npos)
			{
				temp.type = -3;
				for (size_t j = i + 1; j < input.length(); j++)
				{
					a_number = number.find(input[j]);
					if (a_number != number.npos)
					{
						temp.val.push_back(input[j]);
						i++;
					}
					else
						j = input.length();
				}
			}
			lexInput.push_back(temp);
		}
	}

	status = 1;
}

void Arithmetic::Converting()
{
	Stack<Lexema> L;
	for (size_t i = 0; i < lexInput.size(); i++)
	{
		if (lexInput[i].type < -1)
			lexPolish.push_back(lexInput[i]);
		else if (lexInput[i].type == -1)
		{
			while (L.See().type != 0)
				lexPolish.push_back(L.Pop());
			L.Pop();
		}
		else if (lexInput[i].type == 0)
		{
			L.Push(lexInput[i]);
		}
		else
		{
			while (!L.isEmpty() && L.See().type >= lexInput[i].type)
				lexPolish.push_back(L.Pop());
			L.Push(lexInput[i]);
		}
	}
	while (!L.isEmpty())
	{
		lexPolish.push_back(L.Pop());
	}
	status = 2;
}

void Arithmetic::Variable_value()
{
	setlocale(LC_ALL, "Russian");
	for (size_t i = 0; i < lexPolish.size(); i++)
	{
		if (lexPolish[i].type == -3)
			lexPolish[i].x = stod(lexPolish[i].val);
		if (lexPolish[i].type == -2)
		{
			cout << "Введите значение переменной:" << lexPolish[i].val;
			cin >> lexPolish[i].x;
		}
	}
	status = 3;
}

void Arithmetic::Calculation()
{
	Stack<double> L;
	for(size_t i = 0; i < lexPolish.size(); i++)
	{
		if (lexPolish[i].type < -1)
			L.Push(lexPolish[i].x);
		else
		{
			double x = L.Pop();
			if (lexPolish[i].val == "sin")
				L.Push(sin(x));
			else if (lexPolish[i].val == "cos")
				L.Push(cos(x));
			else if (lexPolish[i].val == "exp")
				L.Push(exp(x));
			else if (lexPolish[i].val == "ln")
				L.Push(log(x));
			else if (lexPolish[i].val == "--")
				L.Push(-x);
			else
			{
				double y = L.Pop();
				if (lexPolish[i].val == "+")
					L.Push(x + y);
				else if (lexPolish[i].val == "-")
					L.Push(y - x);
				else if (lexPolish[i].val == "*")
					L.Push(x * y);
				else if (lexPolish[i].val == "/")
					L.Push(y / x);
				else if (lexPolish[i].val == "^")
					L.Push(pow(y, x));
			}
		}
	}
	res = L.Pop();
	status = 4;
}

void Arithmetic::Launch()
{
	if (status == -1)
		Input();
	if (status == 0)
		Divide();
	if (status == 1 && check_brackets())
		Converting();
	if (status == 2)
		Variable_value();
	if (status == 3)
		Calculation();
	if (status == 4)
		setlocale(LC_ALL, "Russian");
	cout << "Результат вычисления выражения:" << endl;
}

vector<Lexema> Arithmetic::Input_Lex()
{
	if (status == 1)
		return lexInput;
	else
		throw exception("Error: not divided");
}

vector<Lexema> Arithmetic::Input_Polish()
{
	if (status == 2)
		return lexPolish;
	else
		throw exception("Error: not converted");
}

double Arithmetic::Result()
{
	if (status == 4)
		return res;
	else
		throw exception("Error: not calculated");
}

void Arithmetic::Input()
{
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Введите арифметическое выражение" << endl;
		getline(cin, input);
	} while (input.empty());
	status = 0;
}

bool Arithmetic::check_brackets()
{
	Stack<char> L;
	for (size_t i = 0; i < lexInput.size(); i++)
	{
		if (lexInput[i].type == 0)
			L.Push('(');
		if (lexInput[i].type == -1)
		{
			if (L.isEmpty())
				return false;
			else L.Pop();
		}
	}
	return L.isEmpty();
}
