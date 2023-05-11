/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:10 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/11 20:49:06 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// When a philo die, it sets the is_dead flag of the
//philosopher to 1, and prints a message to the console
//indicating that the philosopher has died.
int	ft_die(t_philo *philo, int i, t_time time)
{
	if ((int)time > philo[i].time_to_die)
	{
		printf("%s%llu %d %s\n", GRAY, time, philo->id + 1, "died");
		*philo->is_dead = 1;
		return (1);
	}
	return (0);
}

// Check if the philo have eaten enough times to satisfy the
//n_time_must_eat constraint. If the constraint is not set,
//the function always returns 0. If the constraint is set,
//the function returns 1 if the philo has eaten enough times, and 0 otherwise.
int	ft_done_eating(t_philo *philo, int *j, int *res)
{
	if (philo->n_time_must_eat != -1)
	{
		while (*j < philo->n_of_philo)
			*res = *res + philo[(*j)++].total_eaten;
		if (*res == philo->n_of_philo * philo->n_time_must_eat)
		{
			*philo->is_dead = 1;
			return (1);
		}
	}
	return (0);
}

// Checks if a philosopher has died by comparing 
//the current time to the time of their last meal.
void	ft_check_pulse(t_philo *philo)
{
	t_time	time;
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	while (i < philo->n_of_philo)
	{
		pthread_mutex_lock(philo->death);
		time = ft_get_time() - philo[i].last_meal;
		if (ft_die(philo, i, time) || ft_done_eating(philo, &j, &res))
			break ;
		i++;
		pthread_mutex_unlock(philo->death);
	}			
}

// Print the status of a philosopher, including the
//time elapsed since the program started.
//This function is protected by a mutex lock to ensure
//that only one philosopher can write to the console at a time.
int	ft_status(t_philo *philo, char *status, char *color)
{
	t_time	time;

	time = ft_get_time() - philo->start_time;
	pthread_mutex_lock(philo->death);
	if (*philo->is_dead == 0)
		printf("%s%llu %d %s\n", color, time, philo->id + 1, status);
	pthread_mutex_unlock(philo->death);
	return (0);
}
