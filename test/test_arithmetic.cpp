// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"

TEST(Lexema, Can_create_lexem)
{
	ASSERT_NO_THROW(Lexema L);
}

TEST(Lexema, Can_create_copy_lexem)
{
	string val = "0";
	Lexema L(val);
	Lexema Lex(L);
	ASSERT_EQ(L.val, Lex.val);
}

TEST(Lexema, Equality)
{
	string val = "0";
	Lexema L(val);
	ASSERT_EQ(L.val, "0");
}

TEST(Lexema, Not_equality)
{
	string val = "0";
	Lexema L(val);
	ASSERT_NE(L.val, "1");
}

TEST(Arithmetic, Can_create_arithmetic)
{
	string val = "(1+1)";
	ASSERT_NO_THROW(Arithmetic A(val));
}

TEST(Arithmetic, Check_brackets_incorrect_1)
{
	Arithmetic A("{1-2*([3*4]}");
	A.Divide();
	EXPECT_FALSE(A.check_brackets());
}

TEST(Arithmetic, Check_brackets_incorrect_2)
{
	Arithmetic A("(5*cos[15]-[ln{3))");
	A.Divide();
	EXPECT_FALSE(A.check_brackets());
}

TEST(Arithmetic, Check_brackets_incorrect_3)
{
	Arithmetic A("(tg[11}*cos[7]+(-5*5}");
	A.Divide();
	EXPECT_FALSE(A.check_brackets());
}

TEST(Arithmetic, Check_brackets_1)
{
	Arithmetic A("{(5-3*[4-2])}");
	A.Divide();
	EXPECT_TRUE(A.check_brackets());
}

TEST(Arithmetic, Check_brackets_2)
{
	Arithmetic A("(ln(4)*2-[23-20]*sin{2})");
	A.Divide();
	EXPECT_TRUE(A.check_brackets());
}

TEST(Arithmetic, Check_brackets_3)
{
	Arithmetic A("{cos[5]*sin(3)-ln{2}*(-3)}");
	A.Divide();
	EXPECT_TRUE(A.check_brackets());
}

TEST(Arithmetic, Divide_correct)
{
	Arithmetic A("(3*3)^sin(1)*ln(10)");
	A.Divide();
	vector<Lexema> lex = A.Input_Lex();
	vector<Lexema> v;
	v.push_back(Lexema("(", 0));
	v.push_back(Lexema("3", -3));
	v.push_back(Lexema("*", 2));
	v.push_back(Lexema("3", -3));
	v.push_back(Lexema(")", -1));
	v.push_back(Lexema("^", 3));
	v.push_back(Lexema("sin", 5));
	v.push_back(Lexema("(", 0));
	v.push_back(Lexema("1", -3));
	v.push_back(Lexema(")", -1));
	v.push_back(Lexema("*", 2));
	v.push_back(Lexema("ln", 5));
	v.push_back(Lexema("(", 0));
	v.push_back(Lexema("10", -3));
	v.push_back(Lexema(")", -1));

	bool F = true;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(lex[i] == v[i]))
			F = false;
	}
	EXPECT_TRUE(F);
}

TEST(Arithmetic, Converting_correct)
{
	Arithmetic A("(3*3)^sin(1)*ln(10)");
	A.Divide();
	A.Converting();
	vector<Lexema> lex = A.Input_Polish();
	vector<Lexema> v;
	v.push_back(Lexema("3", -3));
	v.push_back(Lexema("3", -3));
	v.push_back(Lexema("*", 2));
	v.push_back(Lexema("1", -3));
	v.push_back(Lexema("sin", 5));
	v.push_back(Lexema("^", 3));
	v.push_back(Lexema("10", -3));
	v.push_back(Lexema("ln", 5));
	v.push_back(Lexema("*", 2));

	bool F = true;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (!(lex[i] == v[i]))
			F = false;
	}
	EXPECT_TRUE(F);
}

TEST(Arithmetic, Calculation_correct)
{
	Arithmetic A("{[(2+3)*5]+[ln(25)*sin(2)]}");
	A.Divide();
	A.Converting();
	A.Variable_value();
	A.Calculation();
	EXPECT_FLOAT_EQ(27.926916, A.Result());
}
