#include "RPN.hpp"

int	isoperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

float	matchingOperator(int op, float first, float second)
{
	if (op == '+')
		return (second + first);
	if (op == '-')
		return (second - first);
	if (op == '*')
		return (second * first);
	if (first == 0)
		throw std::runtime_error("division by zero error!");
	return (second / first);
}

void calculate(std::stack<float> *stack, char op)
{
	if (stack->size() < 2)
		throw OperatoeNeedTwoNum();

	float first = stack->top();
	stack->pop();
	float second = stack->top();
	stack->pop();
	float res = matchingOperator(op, first, second);
	if (isinf(res)) throw std::runtime_error("overflow occured!");
	stack->push(std::floor(res));
}

const char *OperatoeNeedTwoNum::what() const throw()
{
	return ("operator need two numbers");
}

const char *BadInput::what() const throw()
{
	return ("please enter just positive numbers less then 10 and operator (* / + -)");
}

const char *NumMoreThenOperators::what() const throw()
{
	return ("num more then operators");
}