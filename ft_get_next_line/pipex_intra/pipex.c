/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:06:45 by souaouri          #+#    #+#             */
/*   Updated: 2024/02/19 20:06:45 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**all_path;
	char	*one_path;
	char	*cmd_with_path;

	i = 0;
	all_path = ft_split(ft_find_path(env), ':');
	while (all_path[i])
	{
		one_path = ft_strjoin(all_path[i], "/");
		cmd_with_path = ft_strjoin(one_path, cmd);
		if (access(cmd_with_path, X_OK) == 0)
		{
			free_double_ptr(all_path);
			free (one_path);
			return (cmd_with_path);
		}
		free(cmd_with_path);
		free(one_path);
		i++;
	}
	free_double_ptr(all_path);
	return (cmd);
}

void	ft_exec(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**cmmd;

	i = 0;
	if (!ft_strncmp(cmd, "\0", 1))
	{
		perror("command not found");
		exit (EXIT_FAILURE);
	}
	cmmd = ft_split(cmd, ' ');
	cmd = cmmd[0];
	ft_check(cmd, env);
	path = ft_get_path(cmd, env);
	if (execve(path, cmmd, env) == -1)
	{
		perror("command not found");
		exit (EXIT_FAILURE);
		free (path);
		free_double_ptr(cmmd);
	}
	free (path);
	free_double_ptr(cmmd);
}

void	child(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(argv[1], 0);
	if (fd == -1)
		ft_error(p_fd);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(fd);
	close(p_fd[1]);
	close(p_fd[0]);
	ft_exec(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int	fd;
	int	pid;

	fd = open_file(argv[4], 1);
	if (fd == -1)
		ft_error(p_fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 1);
		dup2(p_fd[0], 0);
		close(fd);
		close(p_fd[0]);
		close(p_fd[1]);
		ft_exec(argv[3], env);
	}
	else if (pid > 0)
	{
		close(p_fd[0]);
		close(p_fd[1]);
	}
	else
		perror("piping error !!");
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	int		pid;

	if (argc != 5)
		(perror("piping error !!"), exit(1));
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		(perror("piping error !!"), close(p_fd[0]), close(p_fd[1]), exit(1));
	if (!pid)
		child(argv, p_fd, env);
	else
	{
		parent(argv, p_fd, env);
		close (p_fd[1]);
		close (p_fd[0]);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
