/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:15 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/06 15:49:32 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Checks if the philosopher is hungry and if so,
//tries to pick up the forks to start eating.
int	ft_hungry(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_status(philo, "has taken a fork");
	if (philo->n_of_philo == 1)
	{
		ft_sleep(philo->time_to_die);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	ft_status(philo, "has taken a fork");
	ft_status(philo, "is eating");
	return (0);
}

// Makes the philosopher sleep if they have finished
//eating and are not hungry anymore.
int	ft_lullaby(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	philo->total_eaten++;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->death);
	ft_sleep(philo->time_to_eat);
	ft_status(philo, "is sleeping");
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	ft_sleep(philo->time_to_sleep);
	return (0);
}

//The main function that the philosopher threads run,
//repeatedly trying to pick up the forks, eat, and sleep.
void	*ft_feast(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (ft_hungry(philo))
			break ;
		if (ft_lullaby(philo))
			break ;
		if (ft_status(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
