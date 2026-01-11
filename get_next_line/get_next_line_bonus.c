/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:17:36 by souaouri          #+#    #+#             */
/*   Updated: 2024/02/12 23:17:24 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1 + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_next(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	line = malloc((ft_strlen(buffer) - i) + 1);
	if (!line)
		return (NULL);
	while (buffer[i] && (size_t)i <= ft_strlen(buffer))
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*read_file(char	*buffer, int fd)
{
	char	*buffer1;
	int		i;

	buffer1 = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer1)
		return (NULL);
	i = read(fd, buffer1, BUFFER_SIZE);
	while (i > 0)
	{
		buffer1[i] = '\0';
		buffer = ft_strjoin(buffer, buffer1);
		if (!buffer)
			return (free(buffer1), NULL);
		if (ft_strchr(buffer1, '\n'))
			break ;
		i = read(fd, buffer1, BUFFER_SIZE);
	}
	free(buffer1);
	if (i < 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd >= OPEN_MAX)
		return (NULL);
	buffer[fd] = read_file(buffer[fd], fd);
	if (!buffer[fd] || *buffer[fd] == '\0')
		return (free(buffer[fd]), NULL);
	if (ft_strchr(buffer[fd], '\n'))
	{
		line = ft_line(buffer[fd]);
		buffer[fd] = ft_next(buffer[fd]);
		if (!line)
			return (free(line), NULL);
		return (line);
	}
	else
	{
		line = ft_strjoin(line, buffer[fd]);
		return (free(buffer[fd]), buffer[fd] = NULL, line);
	}
	return (NULL);
}
