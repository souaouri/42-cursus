/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:27:15 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/18 23:01:31 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(Fixed const& obj)
{
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	this->fixed_point = obj.getRawBits();
	return *this;
}

//comparison operators

bool	Fixed::operator>(const Fixed& obj)
{
	return (this->fixed_point > obj.fixed_point);
}

bool	Fixed::operator<(const Fixed& obj)
{
	return (this->fixed_point < obj.fixed_point);
}

bool	Fixed::operator>=(const Fixed& obj)
{
	return (this->fixed_point >= obj.fixed_point);
}

bool	Fixed::operator<=(const Fixed& obj)
{
	return (this->fixed_point <= obj.fixed_point);
}

bool	Fixed::operator==(const Fixed& obj)
{
	return (this->fixed_point == obj.fixed_point);
}

bool	Fixed::operator!=(const Fixed& obj)
{
	return (this->fixed_point != obj.fixed_point);
}

//arithmetic operators

Fixed	Fixed::operator+(const Fixed& obj)
{
	float s = this->toFloat() + obj.toFloat();
	Fixed res(s);
	return (res);
}

Fixed	Fixed::operator-(const Fixed& obj)
{
	float s = this->toFloat() - obj.toFloat();
	Fixed res(s);
	return (res);
}

Fixed	Fixed::operator*(const Fixed& obj)
{
	float s = this->toFloat() * obj.toFloat();
	Fixed res(s);
	return (res);
}

Fixed	Fixed::operator/(const Fixed& obj)
{
	float s = this->toFloat() / obj.toFloat();
	Fixed res(s);
	return (res);
}

//

Fixed&	Fixed::operator++()
{
	this->fixed_point++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixed_point++;
	return temp;
}

Fixed&	Fixed::operator--()
{
	this->fixed_point--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixed_point--;
	return temp;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj2);
	else
		return (obj1);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	Fixed copy_obj1;
	Fixed copy_obj2;
	
	copy_obj1 = obj1;
	copy_obj2 = obj2;
	return (min(copy_obj1, copy_obj2));
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1 > obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	Fixed copy_obj1;
	Fixed copy_obj2;
	
	copy_obj1 = obj1;
	copy_obj2 = obj2;
	return (max(copy_obj1, copy_obj2));
}


Fixed::~Fixed()
{
}

Fixed::Fixed(const int integer)
{
	this->fixed_point = integer << num_of_frac_bits;
}

Fixed::Fixed(const float floating)
{
	this->fixed_point = round(floating * (1 << this->num_of_frac_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->fixed_point >> this->num_of_frac_bits);
}

float	Fixed::toFloat(void) const
{
	float res = this->fixed_point / (float)(1 << this->num_of_frac_bits);
	return (res);
}

std::ostream& operator<<(std::ostream& o, const Fixed& obj)
{
	o << obj.toFloat();
	return o;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

int	Fixed::getRawBits() const
{
	return (fixed_point);
}