/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:45:05 by souaouri          #+#    #+#             */
/*   Updated: 2024/09/26 10:27:26 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	sign_to_monitor_to_start(t_table *table)
{
	while (1)
	{
		usleep (5000);
		pthread_mutex_lock(&table->table_lock);
		if (table->start)
		{
			pthread_mutex_unlock(&table->table_lock);
			break ;
		}
		pthread_mutex_unlock(&table->table_lock);
	}
}

int	philo_is_dead(t_table *table, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->lock_philo);
	if (!(&philo[i])->is_full)
	{
		ft_printf(table, "is died", (&philo[i])->id);
		pthread_mutex_lock(&table->table_lock);
		table->dead = 1;
		pthread_mutex_unlock(&table->table_lock);
		pthread_mutex_unlock(&philo->lock_philo);
		return (0);
	}
	pthread_mutex_unlock(&philo->lock_philo);
	return (1);
}

int	is_full(t_table *table)
{
	pthread_mutex_lock(&table->table_lock);
	if (table->all_isfull)
	{
		pthread_mutex_unlock(&table->table_lock);
		return (0);
	}
	pthread_mutex_unlock(&table->table_lock);
	return (1);
}

void	*moni_routine(void *content)
{
	t_table	*table;
	t_philo	*philo;
	int		i;

	(1) && (table = (t_table *)content, philo = table->philos);
	sign_to_monitor_to_start(table);
	while (1)
	{
		i = -1;
		while (++i < table->num_of_philo)
		{
			pthread_mutex_lock(&philo[i].lock_philo);
			if (my_gettime() - (&philo[i])->time_of_last_meals \
				>= (size_t)table->time_to_die)
			{
				pthread_mutex_unlock(&philo[i].lock_philo);
				if (!philo_is_dead(table, philo, i))
					return (NULL);
			}
			pthread_mutex_unlock(&philo[i].lock_philo);
		}
		if (!is_full(table))
			break ;
	}
	return (NULL);
}

int	the_monitoring(t_table *table)
{
	pthread_t	trm;

	if (pthread_create(&trm, NULL, moni_routine, table))
		return (thread_error ("pthread_creat() failed !", table), 1);
	if (pthread_detach(trm))
		return (thread_error ("pthread_detach() failed !", table), 1);
	return (0);
}
