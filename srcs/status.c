/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:10 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/04 19:10:21 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_die(t_philo *philo, int i, t_time time)
{
	if ((int)time > philo[i].time_to_die)
	{
		printf("%llu %d %s\n", time, philo->id + 1, "died");
		*philo->is_dead = 1;
		return (1);
	}
	return (0);
}

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

int	ft_status(t_philo *philo, char *status)
{
	t_time	time;

	time = ft_get_time() - philo->start_time;
	pthread_mutex_lock(philo->death);
	if (*philo->is_dead == 0)
		printf("%llu %d %s\n", time, philo->id + 1, status);
	pthread_mutex_unlock(philo->death);
	return (0);
}
