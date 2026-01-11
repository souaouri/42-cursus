/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 02:13:06 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/10 16:50:02 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_it_a_move(char *line)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "sa\n") || !ft_strncmp(line, "sb\n")
		|| !ft_strncmp(line, "ss\n"))
		i++;
	if (!ft_strncmp(line, "pa\n") || !ft_strncmp(line, "pb\n"))
		i++;
	if (!ft_strncmp(line, "ra\n") || !ft_strncmp(line, "rb\n")
		|| !ft_strncmp(line, "rr\n"))
		i++;
	if (!ft_strncmp(line, "rra\n") || !ft_strncmp(line, "rrb\n")
		|| !ft_strncmp(line, "rrr\n"))
		i++;
	return (i);
}

void	is_ok_or_ko(t_list	*stack, int stack_b_size)
{
	if (is_sorted(stack) && stack_b_size == 0)
		write(1, "OK\n", 3);
	else if (!is_sorted(stack))
		write(1, "KO\n", 3);
	else
		write(1, "KO\n", 3);
}

char	**ft_read(t_list *stack_a, t_list *stack_b)
{
	char	**lines;
	char	*line;
	int		i;

	i = 0;
	lines = (char **)malloc(sizeof(char *) * 5500);
	if (lines == NULL)
		return (NULL);
	line = get_next_line(0);
	while (line != NULL && i < 5500)
	{
		lines[i] = line;
		if (!is_it_a_move(lines[i]))
		{
			freee_list(&stack_b);
			ft_free_error(&stack_a);
		}
		i++;
		line = get_next_line(0);
	}
	lines[i] = NULL;
	return (lines);
}

void	tester(t_list	*stack_a)
{
	t_list	*stack_b;
	char	**lines;
	char	stack_b_size;
	int		i;

	i = 0;
	stack_b = NULL;
	if (ft_lstsize(stack_a) == 0)
		return ;
	lines = ft_read(stack_a, stack_b);
	while (lines[i])
	{
		check_swap(lines[i], &stack_a, &stack_b);
		check_push(lines[i], &stack_a, &stack_b);
		check_rotate(lines[i], &stack_a, &stack_b);
		check_reverse_rotate(lines[i], &stack_a, &stack_b);
		i++;
	}
	stack_b_size = ft_lstsize(stack_b);
	is_ok_or_ko(stack_a, stack_b_size);
	freee(lines);
	freee_list(&stack_a);
}
