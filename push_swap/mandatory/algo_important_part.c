/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_important_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:55:50 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:50:46 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_help(t_list *stack_a, t_right_hand *var)
{
	var->list_size = ft_lstsize(stack_a);
	if (var->list_size >= 200)
		var->devide = 9;
	else
		var->devide = 5;
	var->chunk = var->list_size / var->devide;
}

int	there_is_more(t_list *stack_a, int chunk)
{
	while (stack_a)
	{
		if (stack_a->position < chunk)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	move(t_list **stack_b, int max, int index)
{
	if (index < ft_lstsize(*stack_b) / 2)
	{
		while ((*stack_b)->content != max)
			rb(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->content != max)
			rrb(stack_b, 1);
	}
}

int	who_is_the_essy_one(t_list *stack, int max)
{
	int	abs;

	abs = (ft_lstsize(stack) / 2) - max;
	if (abs < 0)
		return (-abs);
	else
		return (abs);
}

void	who_is_first(t_list **stack_a, t_list **stack_b, \
				t_right_hand helpers, int se_big)
{
	if (who_is_the_essy_one(*stack_b, helpers.big_index)
		< who_is_the_essy_one(*stack_b, helpers.se_big_index))
	{
		move(stack_b, se_big, helpers.se_big_index);
		pa(stack_a, stack_b, 1);
		if (!stack_b)
			return ;
	}
}
