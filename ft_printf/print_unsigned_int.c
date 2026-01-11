/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:44:00 by souaouri          #+#    #+#             */
/*   Updated: 2023/12/12 10:44:00 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_int_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_unsigned_int(long n)
{
	int	ui_l;

	if (n >= 0)
	{
		if (n >= 10)
			print_digit(n / 10);
		print_digit(n % 10);
		ui_l = u_int_len(n);
	}
	else
	{
		print_unsigned_int(n + 1 + 4294967295);
		ui_l = u_int_len(n + 1 + 4294967295);
	}
	return (ui_l);
}
