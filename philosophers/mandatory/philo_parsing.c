/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:54:28 by souaouri          #+#    #+#             */
/*   Updated: 2024/09/26 10:47:41 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_out_of_range(long num)
{
	if ((num > INT_MAX))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_valid(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str && str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str && str[i] == '+' && str[i + 1])
		i++;
	if (str && str[i] == '-')
		return (parsing_error("please enter a positive parametre"), 1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (parsing_error("The parameter must contain num only"), 1);
		i++;
	}
	return (0);
}

long	ft_atoi_long(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (!str || !*str)
		return (parsing_error("null parametre !!"), -1337);
	if (is_valid(str))
		return (-1337);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (check_out_of_range(num))
			return (parsing_error("parametre is out of the range"), -1337);
		i++;
	}
	return (num);
}
