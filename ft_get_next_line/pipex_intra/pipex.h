/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:06:33 by souaouri          #+#    #+#             */
/*   Updated: 2024/03/08 14:31:37 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H	
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		open_file(char *file, int if_or_of);
void	free_double_ptr(char **ptr);
char	*ft_find_path(char **env);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char	*s, char c);
char	*ft_get_path(char *cmd, char **env);
void	ft_exec(char *cmd, char **env);
void	child(char **argv, int *p_fd, char **env);
void	parent(char **argv, int *p_fd, char **env);
void	ft_check(char *cmd, char **env);
void	ft_error(int *p_fd);

#endif
