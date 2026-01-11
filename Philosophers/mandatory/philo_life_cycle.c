/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:55:39 by souaouri          #+#    #+#             */
/*   Updated: 2024/09/21 11:59:12 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	single_philo(t_philo *philo)
{
	if (philo->table->num_of_philo == 1)
	{
		ft_usleep(philo->table, philo->table->time_to_die);
		return (0);
	}
	return (1);
}

void	unlock_forks(t_table *table, t_philo *philo)
{
	pthread_mutex_unlock(&table->forks[philo->id - 1]);
	pthread_mutex_unlock(&table->forks[philo->id % table->num_of_philo]);
}

int	ft_eating(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->forks[philo->id - 1]);
	ft_printf(philo->table, "is taken a fork", philo->id);
	if (!single_philo(philo))
		return (0);
	pthread_mutex_lock(&table->forks[philo->id % table->num_of_philo]);
	ft_printf(philo->table, "is taken a fork", philo->id);
	ft_printf(philo->table, "is eating", philo->id);
	philo->num_of_meals++;
	if (philo->num_of_meals == table->num_of_times_must_eat)
	{
		pthread_mutex_lock(&philo->lock_philo);
		philo->is_full = 1;
		pthread_mutex_unlock(&philo->lock_philo);
		unlock_forks(table, philo);
		return (1);
	}
	pthread_mutex_lock(&philo->lock_philo);
	philo->time_of_last_meals = my_gettime();
	pthread_mutex_unlock(&philo->lock_philo);
	ft_usleep(philo->table, philo->table->time_to_eat);
	unlock_forks(table, philo);
	return (0);
}

void	divide_philos(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock_philo);
	philo->time_of_last_meals = my_gettime();
	pthread_mutex_unlock(&philo->lock_philo);
	if (philo->id % 2 != 0)
	{
		ft_printf(philo->table, "is thinking", philo->id);
		ft_usleep(philo->table, philo->table->time_to_eat);
	}
}

void	*ft_life_cycle(void	*content)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)content;
	table = philo->table;
	divide_philos(philo);
	while (1)
	{
		if (ft_eating(philo))
			break ;
		ft_printf(philo->table, "is sleeping", philo->id);
		ft_usleep(philo->table, philo->table->time_to_sleep);
		ft_printf(philo->table, "is thinking", philo->id);
		pthread_mutex_lock(&table->table_lock);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->table_lock);
			break ;
		}
		pthread_mutex_unlock(&table->table_lock);
	}
	return (NULL);
}
