// реализация пользовательского приложения
#include "arithmetic.h"
#include "locale.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Калькулятор" << endl;
	Arithmetic A;

		try {
			A.Input();
		}
		catch (...)
		{
			cerr << "Выражение не введено" << endl;
		}

		try {
			A.check_brackets();
		}
		catch (...)
		{
			cerr << "Скобки раставлены неверно" << endl;
		}

		try {
			A.Divide();
		}
		catch (...)
		{
			cerr << "Выражение не может быть разделено на лексемы" << endl;
		}

		try {
			A.Converting();
		}
		catch(...)
		{
			cerr << "Выражение не может быть преобразовано" << endl;
		}

		try {
			A.Variable_value();
		}
		catch(...)
		{
			cerr << "Значение переменной неверное" << endl;
		}

		try {
			A.Calculation();
		}
		catch (...)
		{
			cerr << "Выражение не может быть вычислено" << endl;
		}
		A.Launch();
	return 0;
}
