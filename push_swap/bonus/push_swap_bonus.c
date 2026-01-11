/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 01:59:17 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/10 16:53:18 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	change_arg_to_int(char *str)
{
	int	sign;
	int	res;
	int	i;
	int	handel;

	handel = 0;
	i = 0;
	sign = 1;
	res = 0;
	if (i == (int)ft_strlen(str))
		ft_error();
	if (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			sign *= -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		handel += 1;
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] || handel == 0)
		ft_error();
	if ((sign == 1 && (res * sign) < 0) || (sign == -1 && (res * sign) > 0))
		ft_error();
	return (res * sign);
}

void	is_frequent(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp1;

	while (stack_a)
	{
		tmp = stack_a->next;
		tmp1 = stack_a;
		while (tmp)
		{
			if (tmp1->content == tmp->content)
				ft_free_error(&stack_a);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

void	space_handler(char *str, t_list *stack_a)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if ((int)ft_strlen(str) == i)
		ft_free_error(&stack_a);
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*node;
	char		**spliter;
	t_utile_var	var;

	var.i = 0;
	while (++var.i <= argc - 1)
	{
		space_handler(argv[var.i], stack_a);
		spliter = ft_split(argv[var.i], ' ');
		if (!spliter)
			ft_free_error(&stack_a);
		var.j = 0;
		while (spliter[var.j])
		{
			var.num = change_arg_to_int(spliter[var.j]);
			node = ft_lstnew(var.num);
			ft_lstadd_back(&stack_a, node);
			var.j++;
		}
		freee(spliter);
	}
	is_frequent(stack_a);
	tester(stack_a);
}
