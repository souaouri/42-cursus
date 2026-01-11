/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:21:05 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:54:26 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_list **stack_a, int w)
{
	t_list	*tmp;
	t_list	*prev;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (t_list *)ft_lstlast(*stack_a);
	prev = *stack_a;
	while (prev->next != tmp)
		prev = prev->next;
	prev->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (w == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list	**stack_b, int w)
{
	t_list	*tmp;
	t_list	*prev;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = (t_list *)ft_lstlast(*stack_b);
	prev = *stack_b;
	while (prev->next != tmp)
		prev = prev->next;
	prev ->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (w == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int w)
{
	if (!*stack_a || !*stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (w == 1)
		write(1, "rrr\n", 4);
}
