/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:43:32 by souaouri          #+#    #+#             */
/*   Updated: 2023/12/12 10:43:32 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nember_len(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i += 1;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	print_digit(int nb)
{
	long	nbr;
	int		nbr_len;

	nbr = nb;
	nbr_len = nember_len(nbr);
	if (nbr < 0)
	{
		print_character('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		print_digit(nbr / 10);
		print_digit(nbr % 10);
	}
	else
		print_character(nbr + '0');
	return (nbr_len);
}
