/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:32:26 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/09 17:51:20 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strncmp(char *s1, char *s2)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	freee(char **spliter)
{
	int	i;

	i = 0;
	while (spliter[i])
	{
		free(spliter[i]);
		i++;
	}
	free(spliter);
}

void	freee_list(t_list	**stack)
{
	t_list	*tmp;
	t_list	*current;

	current = *stack;
	tmp = NULL;
	while (current)
	{
		tmp = current->next;
		current->content = 0;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_free_error(t_list	**stack)
{
	freee_list(stack);
	ft_error();
}
