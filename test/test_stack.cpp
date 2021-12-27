// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack)
{
	ASSERT_NO_THROW(Stack<double> stack(5));
}

TEST(Stack, can_create_copy)
{
	Stack<double> stack(5);
	ASSERT_NO_THROW(Stack<double> stack1(stack));
}

TEST(Stack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<double> stack(-1));
}

TEST(Stack, add_element_to_stack)
{
	Stack<double> stack(2);
	ASSERT_NO_THROW(stack.Push(3));
}

TEST(Stack, pop_an_element_off_the_stack)
{
	Stack<double> stack(2);
	stack.Push(3);
	ASSERT_EQ(3, stack.Pop());
}

TEST(Stack, view_top_element)
{
	Stack<double> stack(2);
	stack.Push(3);
	ASSERT_EQ(3, stack.See());
}

TEST(Stack, checking_for_emptiness)
{
	Stack<double> stack(2);
	stack.Push(3);
	stack.Pop();
	ASSERT_EQ(1, stack.isEmpty());
}

TEST(Stack, number_of_elements_on_the_stack)
{
	Stack<double> stack(2);
	stack.Push(3);
	stack.Push(4);
	ASSERT_EQ(2, stack.Number());
}

TEST(Stack, can_clean_stack)
{
	Stack<double> stack(2);
	stack.Push(3);
	stack.Clean();
	ASSERT_EQ(0, stack.isEmpty());
}