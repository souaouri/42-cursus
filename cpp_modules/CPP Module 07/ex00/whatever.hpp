#pragma once

#include <iostream>


template <typename A>

void	swap(A &num1, A &num2)
{
	A temp = num1;
	num1 = num2;
	num2 = temp;
}

template <typename B>

const B min(const B num1, const B num2)
{
	return (num1 < num2) ? num1 : num2;
}

template <typename C>

const C max(const C num1, const C num2)
{
	return (num1 > num2) ? num1 : num2;
}