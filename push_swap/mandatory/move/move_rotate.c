/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:21:18 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:54:30 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstadd_back2(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (!*lst || !lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	ra(t_list **stack_a, int w)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back2(stack_a, tmp);
	if (w == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int w)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back2(stack_b, tmp);
	if (w == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int w)
{
	if (!*stack_a || !*stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (w == 1)
		write(1, "rr\n", 3);
}
