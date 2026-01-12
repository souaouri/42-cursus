/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:23:09 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/18 22:22:09 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
	private:
		int 				fixed_point;
		static const int	num_of_frac_bits = 8;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(Fixed const& obj);

		Fixed&	operator=(const Fixed& obj);
		bool	operator>(const Fixed& obj);
		bool	operator<(const Fixed& obj);
		bool	operator>=(const Fixed& obj);
		bool	operator<=(const Fixed& obj);
		bool	operator==(const Fixed& obj);
		bool	operator!=(const Fixed& obj);
		
		Fixed	operator+(const Fixed& obj);
		Fixed	operator-(const Fixed& obj);
		Fixed	operator*(const Fixed& obj);
		Fixed	operator/(const Fixed& obj);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static	Fixed& min(Fixed& obj1, Fixed&obj2);
		static	Fixed const& min(Fixed const& obj1, Fixed const& obj2);
	
		static	Fixed& max(Fixed& obj1, Fixed&obj2);
		static	Fixed const& max(Fixed const& obj1, Fixed const& obj2);
		
		~Fixed();
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
std::ostream& operator<<(std::ostream& o, const Fixed& obj);