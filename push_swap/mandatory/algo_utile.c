/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:59:33 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:51:01 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack_a)
{
	int	max;

	if (!stack_a)
		ft_error();
	max = stack_a->content;
	while (stack_a)
	{
		if (max > stack_a->content)
			return (0);
		max = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}

int	find_biggest(t_list	*stack)
{
	int	num;

	if (!stack)
		ft_error();
	num = stack->content;
	while (stack)
	{
		if (stack->content > num)
			num = stack->content;
		stack = stack->next;
	}
	return (num);
}

int	find_smallest(t_list *stack)
{
	int	num;

	if (!stack)
		ft_error();
	num = stack->content;
	while (stack)
	{
		if (stack->content < num)
			num = stack->content;
		stack = stack->next;
	}
	return (num);
}

int	numbering(t_list *stack, int num)
{
	int				index;

	index = 0;
	while (stack)
	{
		if (stack->content == num)
			return (index);
		stack = stack->next;
		index++;
	}
	return (0);
}

int	find_second_bigest(t_list	*stack)
{
	int	num;
	int	i;

	if (!stack)
		ft_error();
	i = find_biggest(stack);
	num = stack->content;
	while (stack)
	{
		if (num == find_biggest(stack) && stack->next)
			num = stack->next->content;
		if (stack->content > num && stack->content != i)
			num = stack->content;
		stack = stack->next;
	}
	return (num);
}
