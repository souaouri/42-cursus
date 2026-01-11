/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:43:54 by souaouri          #+#    #+#             */
/*   Updated: 2023/12/12 10:43:54 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_upper(int long n, int base)
{
	char	*s;
	int		hu_len;

	hu_len = 0;
	s = "0123456789ABCDEF";
	if (n < base)
	{
		return (print_character(s[n]));
	}
	else
	{
		hu_len += print_hex_upper((n / base), base);
		return (hu_len + print_hex_upper((n % base), base));
	}
}
