/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:26:44 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/08 14:43:03 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_check(char *cmd, char **env)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	j = 0;
	if (ft_strchr(cmd, '/'))
	{
		path = ft_split (ft_find_path(env), ':');
		while (path[i])
		{
			if (!ft_strncmp(cmd, path[i], ft_strlen(path[i])))
				j += 1;
			i++;
		}
		if (!j)
		{
			perror("error !!");
			free_double_ptr(path);
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_error(int *p_fd)
{
	perror("bad file discreptor !!");
	close (p_fd[0]);
	close (p_fd[1]);
	exit(EXIT_FAILURE);
}
