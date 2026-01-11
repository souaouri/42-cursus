/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:31:09 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/16 18:31:39 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n; 
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd ('-', fd);
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd (nbr / 10, fd);
		ft_putchar_fd (nbr % 10 + '0', fd);
	}
	else
		ft_putchar_fd (nbr % 10 + '0', fd);
}
//int main ()
//{
//	ft_putnbr_fd(-1337,1);
//}
