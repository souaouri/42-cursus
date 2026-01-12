/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:23:09 by souaouri          #+#    #+#             */
/*   Updated: 2025/01/17 09:31:24 by souaouri         ###   ########.fr       */
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
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
		std::ostream& operator<<(std::ostream& o, const Fixed& obj);