/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:43:38 by souaouri          #+#    #+#             */
/*   Updated: 2023/12/14 12:24:17 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char wisthelett, va_list ap)
{
	int	count;

	count = 0;
	if (wisthelett == 'c')
		count += print_character(va_arg(ap, int));
	else if (wisthelett == 's')
		count += print_string(va_arg(ap, char *));
	else if (wisthelett == 'd' || wisthelett == 'i')
		count = print_digit(va_arg(ap, int));
	else if (wisthelett == 'p')
	{
		count += print_string("0x");
		count += print_hex_lower(va_arg(ap, unsigned long), 16);
	}
	else if (wisthelett == 'x')
		count += print_hex_lower(va_arg(ap, unsigned int), 16);
	else if (wisthelett == 'X')
		count += print_hex_upper(va_arg(ap, unsigned int), 16);
	else if (wisthelett == 'u')
		count += print_unsigned_int(va_arg(ap, int));
	else
		count += print_character(wisthelett);
	return (count);
}
