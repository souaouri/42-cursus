/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:10:06 by souaouri          #+#    #+#             */
/*   Updated: 2024/09/28 16:35:33 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	take_times(t_table *table, char **argv)
{
	table->num_of_philo = ft_atoi_long(argv[1]);
	table->time_to_die = ft_atoi_long(argv[2]);
	table->time_to_eat = ft_atoi_long(argv[3]);
	table->time_to_sleep = ft_atoi_long(argv[4]);
	if (argv[5])
		table->num_of_times_must_eat = ft_atoi_long(argv[5]);
	else
		table->num_of_times_must_eat = -1;
	if (table->num_of_philo == -1337 || table->time_to_die == -1337
		|| table->time_to_eat == -1337 || table->time_to_sleep == -1337
		|| table->num_of_times_must_eat == -1337)
		return (1);
	if (table->num_of_times_must_eat == 0)
		return (1);
	return (0);
}

int	philo_and_fork_data(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (mutex_error("pthread_mutex_init() failed", 1, table), 1);
		i++;
	}
	i = 0;
	while (i < table->num_of_philo)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].is_full = 0;
		table->philos[i].num_of_meals = 0;
		table->philos[i].time_of_last_meals = 0;
		if (pthread_mutex_init(&table->philos[i].lock_philo, NULL))
			return (mutex_error("pthread_mutex_init() failed !", 2, table), 1);
		i++;
	}
	return (0);
}

int	creat_thread(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->table_lock);
	table->start = my_gettime();
	pthread_mutex_unlock(&table->table_lock);
	while (i < table->num_of_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL, \
		ft_life_cycle, &table->philos[i]))
			return (thread_error ("pthread_create() failed !", table), 1);
		i++;
	}
	i = 0;
	while (i < table->num_of_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL))
			return (thread_error ("pthread_create() failed !", table), 1);
		i++;
	}
	pthread_mutex_lock(&table->table_lock);
	table->all_isfull = 1;
	pthread_mutex_unlock(&table->table_lock);
	destroy_and_free(table);
	return (0);
}

void	discover_the_table(t_table *table, char **argv)
{
	int	i;

	i = 0;
	if (take_times(table, argv))
		return ;
	if (pthread_mutex_init(&table->print, NULL) || \
		pthread_mutex_init(&table->table_lock, NULL))
		return (mutex_error("pthread_mutex_init() failed!", 0, table));
	table->start = 0;
	table->dead = 0;
	table->all_isfull = 0;
	table->cheker = 0;
	table->philos = malloc(sizeof(t_philo) * table->num_of_philo);
	if (!table->philos)
		return ;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_of_philo);
	if (!table->forks)
		return ;
	if (philo_and_fork_data(table))
		return ;
	if (the_monitoring(table))
		return ;
	if (creat_thread(table))
		return ;
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (parsing_error("Please enter the correct num of arguments"), 1);
	discover_the_table(&table, argv);
}
