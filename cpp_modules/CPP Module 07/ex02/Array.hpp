#pragma once

#include <iostream>

template <typename T>

class Array{
	private:
		T* array;
		unsigned int _size;
	public:
		Array() : _size(0){
			array = new T[_size];
		}
		Array(unsigned int n) : _size(n){
			array = new T[_size];
		}
		Array(const Array& other){
			_size = other.size();
			if (_size == 0)
			{
				array = NULL;
				return ;
			}
			array = new T[_size];
			for (unsigned int i = 0; i <= _size; i++)
				array[i] = other.array[i];
		}
		Array&	operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] array;
				_size = other.size();
				if (_size == 0)
				{
					array = 0;
					return *this;
				}
				array = new T[_size];
				for (unsigned int i = 0; i <= _size; i++)
					array[i] = other.array[i];
			}
			return *this;
		}
		T&	operator[](unsigned int index){
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return array[index];
		}
		const T&	operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of range");
			return array[index];
		}
		unsigned int	size() const{
			return _size;
		}
};