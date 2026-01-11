/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:27:52 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/08 14:36:51 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int if_or_of)
{
	int	fd;

	if (if_or_of == 0)
		fd = open(file, O_RDONLY, 0777);
	if (if_or_of == 1)
		fd = open(file, O_CREAT | O_RDWR, 0777);
	return (fd);
}

void	free_double_ptr(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_find_path(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	return (env[i] + 5);
}
