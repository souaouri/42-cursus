/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:15:24 by souaouri          #+#    #+#             */
/*   Updated: 2024/09/26 10:48:15 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

size_t	my_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_printf(t_table *table, char *str, int id)
{
	pthread_mutex_lock(&table->table_lock);
	if (!table->dead)
	{
		pthread_mutex_lock(&table->print);
		printf("%ld\t%d\t%s\n", my_gettime() - table->start, id, str);
		pthread_mutex_unlock(&table->print);
	}
	pthread_mutex_unlock(&table->table_lock);
}

void	ft_usleep(t_table *table, int time)
{
	size_t	start;

	start = my_gettime();
	while (1)
	{
		pthread_mutex_lock(&table->table_lock);
		if (my_gettime() - start >= (size_t)time || table->dead)
		{
			pthread_mutex_unlock(&table->table_lock);
			break ;
		}
		pthread_mutex_unlock(&table->table_lock);
		usleep(500);
	}
}

void	destroy_and_free(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_of_philo)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->table_lock);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->philos->lock_philo);
	free(table->forks);
	free(table->philos);
}
