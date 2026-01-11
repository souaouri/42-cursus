/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:39:53 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:51:09 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_list **stack_a)
{
	if (is_sorted(*stack_a) == 0)
	{
		if ((*stack_a)->content == find_biggest(*stack_a))
		{
			ra(stack_a, 1);
			if (!is_sorted(*stack_a))
				sa(stack_a, 1);
		}
		else if (ft_lstlast(*stack_a)->content == find_biggest(*stack_a))
			sa(&*stack_a, 1);
		else if (ft_lstlast(*stack_a)->content == find_smallest(*stack_a))
			rra(&*stack_a, 1);
		else if ((*stack_a)->content == find_smallest(*stack_a))
		{
			rra(stack_a, 1);
			sa(stack_a, 1);
		}
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 0)
	{
		while ((*stack_a)->content != find_smallest(*stack_a))
			ra(stack_a, 1);
		pb(stack_a, stack_b, 1);
		sort_3(stack_a);
		pa(stack_a, stack_b, 1);
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 0)
	{
		while ((*stack_a)->content != find_smallest(*stack_a))
			ra(stack_a, 1);
		pb(stack_a, stack_b, 1);
		sort_4(stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}

int	is_there(t_list *stack_a, int chunk)
{
	while (stack_a)
	{
		if (stack_a->position < chunk)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	where_is_big_location(t_list *stack, int big, int se_big)
{
	t_list	*tmp;
	int		size;

	tmp = stack;
	size = ft_lstsize(stack) / 2;
	while (size >= 0)
	{
		if (tmp->content == big || tmp->content == se_big)
			return (1);
		rb(&tmp, 0);
		size--;
	}
	return (0);
}
