/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:57:45 by souaouri          #+#    #+#             */
/*   Updated: 2024/09/26 09:56:28 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	parsing_error(char *str)
{
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n"RESET, 2);
}

void	mutex_error(char *str, int i, t_table *table)
{
	int	j;

	if (i == 1)
	{
		pthread_mutex_destroy(&table->table_lock);
		pthread_mutex_destroy(&table->print);
	}
	if (i == 2)
	{
		j = -1;
		while (++j < table->num_of_philo)
			pthread_mutex_destroy(&table->forks[j]);
		pthread_mutex_destroy(&table->table_lock);
		pthread_mutex_destroy(&table->print);
	}
	if (i != 0)
	{
		free(table->forks);
		free(table->philos);
	}
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n"RESET, 2);
}

void	thread_error(char *str, t_table *table)
{
	int	j;

	j = -1;
	while (++j < table->num_of_philo)
		pthread_mutex_destroy(&table->forks[j]);
	pthread_mutex_destroy(&table->table_lock);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->philos->lock_philo);
	free(table->forks);
	free(table->philos);
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n"RESET, 2);
}
