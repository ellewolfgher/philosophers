/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:25:38 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/12 14:40:55 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Initializes the philo struct with the values from the arguments
void	ft_init_philos(t_philo *philo, int ac, char *av[])
{
	int	is_dead;
	int	i;

	i = 0;
	is_dead = 0;
	while (i < ft_atol(av[1]))
	{
		philo[i].id = i;
		philo[i].time_to_die = ft_atol(av[2]);
		philo[i].time_to_eat = ft_atol(av[3]);
		philo[i].time_to_sleep = ft_atol(av[4]);
		if (ac == 6)
			philo[i].n_time_must_eat = ft_atol(av[5]);
		else
			philo[i].n_time_must_eat = -1;
		philo[i].last_meal = ft_get_time();
		philo[i].start_time = ft_get_time();
		philo[i].total_eaten = 0;
		philo[i].n_of_philo = ft_atol(av[1]);
		philo[i].is_dead = &is_dead;
		i++;
	}
}

// Initializes the mutex locks for each philosopher's left
//and right forks, as well as the mutex lock for the death
//variable (which is used to track whether any philosopher has died).
void	ft_init_mutex(t_philo *philo, char *av[], \
	pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->n_of_philo)
	{
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % philo->n_of_philo];
		i++;
	}
	i = 0;
	while (i < ft_atol(av[1]))
	{
		pthread_mutex_init(philo[i].left_fork, NULL);
		pthread_mutex_init(philo[i].right_fork, NULL);
		philo[i].death = death;
		i++;
	}
	pthread_mutex_init(philo->death, NULL);
}

// Creates a thread for each philosopher, and then waits for all 
//philosophers to finish eating or for one of them to die
void	ft_init_threads(t_philo *philo, char *av[])
{
	int	i;

	i = 0;
	while (i < ft_atol(av[1]))
	{
		pthread_create(&philo[i].thread, NULL, &ft_feast, &philo[i]);
		i++;
		usleep(100);
	}
	while (*philo->is_dead != 1)
		ft_check_pulse(philo);
	i = 0;
	while (i < ft_atol(av[1]))
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
