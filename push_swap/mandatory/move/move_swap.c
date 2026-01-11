/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:11:43 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:54:38 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_list **stack_a, int w)
{
	t_list	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (w == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int w)
{
	t_list	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (w == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int w)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (w == 1)
		write(1, "ss\n", 3);
}
