#pragma once


#include <iostream>

template <typename X>
void	print(X &array)
{
	std::cout << "[ " << array << " ]" << std::endl;
}

template <typename X>

void	toUpper(X &array)
{
	if (array >= 'a' && array <= 'z')
		array -= 32;
}

template <typename X>

void	toUpper(const X &array)
{
	(void)array;
	std::cout << "array is const !" << std::endl;
}

template <typename X, typename B >


void	iter(X *array, B len, void	(*func)(X&))
{
	if (array == NULL || func == NULL)
		return;
	for (int i = 0; static_cast<B>(i) < len; i++)
		func(array[i]);
}