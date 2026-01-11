/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:34:34 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 18:28:53 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_swap(char *line, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "sa\n"))
	{
		sa(stack_a, 0);
		i++;
	}
	else if (!ft_strncmp(line, "sb\n"))
	{
		sb(stack_b, 0);
		i++;
	}
	else if (!ft_strncmp(line, "ss\n"))
	{
		ss(stack_a, stack_b, 0);
		i++;
	}
	return (i);
}

int	check_push(char *line, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "pa\n"))
	{
		pa(stack_a, stack_b, 0);
		i++;
	}
	else if (!ft_strncmp(line, "pb\n"))
	{
		pb(stack_a, stack_b, 0);
		i++;
	}
	return (i);
}

int	check_rotate(char *line, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "ra\n"))
	{
		ra(stack_a, 0);
		i++;
	}
	else if (!ft_strncmp(line, "rb\n"))
	{
		rb(stack_b, 0);
		i++;
	}
	else if (!ft_strncmp(line, "rr\n"))
	{
		rr(stack_a, stack_b, 0);
		i++;
	}
	return (i);
}

int	check_reverse_rotate(char *line, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "rra\n"))
	{
		rra(stack_a, 0);
		i++;
	}
	else if (!ft_strncmp(line, "rrb\n"))
	{
		rrb(stack_b, 0);
		i++;
	}
	else if (!ft_strncmp(line, "rrr\n"))
	{
		rrr(stack_a, stack_b, 0);
		i++;
	}
	return (i);
}
