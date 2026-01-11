/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emergency.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:56:24 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:51:12 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_2(int argc, int size, t_list **stack_a)
{
	if (argc == 1)
		return ;
	if (size == 2)
	{
		if (is_sorted(*stack_a) == 0)
			sa(stack_a, 1);
	}
}

void	sort_other(t_list **stack_a, t_list **stack_b, t_right_hand var)
{
	while (*stack_a)
	{
		if ((*stack_a)->position < var.chunk)
		{
			pb(stack_a, stack_b, 1);
			if (!*stack_a)
				return ;
			if ((*stack_b)->position >= var.chunk - \
			(var.list_size / var.devide) / 2)
			{
				if (there_is_more(*stack_a, var.chunk) && \
				(*stack_a)->position >= var.chunk)
					rr(stack_a, stack_b, 1);
				else
					rb(stack_b, 1);
			}
		}
		else
			ra(stack_a, 1);
		if (!there_is_more(*stack_a, var.chunk))
			var.chunk += var.list_size / var.devide;
	}
}

void	push_to_stack_a(t_list**stack_a, t_list**stack_b)
{
	t_right_hand	helpers;
	int				big;
	int				se_big;

	while (*stack_b)
	{
		big = find_biggest(*stack_b);
		se_big = find_second_bigest(*stack_b);
		helpers.big_index = numbering(*stack_b, big);
		helpers.se_big_index = numbering(*stack_b, se_big);
		who_is_first(stack_a, stack_b, helpers, se_big);
		helpers.big_index = numbering(*stack_b, big);
		move(stack_b, big, helpers.big_index);
		pa(stack_a, stack_b, 1);
		if (!is_sorted(*stack_a))
			sa(stack_a, 1);
	}
}

void	shose_sort(int argc, t_list **stack_a, t_list **stack_b)
{
	t_right_hand	help;
	int				size;

	size = ft_lstsize(*stack_a);
	sort_2(argc, size, stack_a);
	if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else if (size > 5)
	{
		if (is_sorted(*stack_a) == 0)
		{
			ft_help(*stack_a, &help);
			sort_other(stack_a, stack_b, help);
			push_to_stack_a(stack_a, stack_b);
		}
	}
	freee_list(stack_a);
}
