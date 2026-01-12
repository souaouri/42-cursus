/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:27:15 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/18 19:22:54 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = integer * (1 << num_of_frac_bits);
}

Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = round(floating * (1 << this->num_of_frac_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->fixed_point / (1 << this->num_of_frac_bits));
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