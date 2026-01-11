/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:43:43 by souaouri          #+#    #+#             */
/*   Updated: 2023/12/12 10:43:43 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lower(unsigned long n, int base)
{
	char	*s;
	int		hl_len;

	hl_len = 0;
	s = "0123456789abcdef";
	if (n < 16)
		return (print_character(s[n]));
	else
	{
		hl_len += print_hex_lower ((n / base), base);
		return (hl_len + print_hex_lower ((n % base), base));
	}
}
