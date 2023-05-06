/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:20:58 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/06 15:47:02 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Converts a string to a long integer.
long	ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

// Checks if the arguments are valid.
int	ft_check_args(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Gets the current time as the number of milliseconds
//since the Unix epoch. It does this using the `gettimeofday`
//system call, which gets the time of day with microsecond precision.
t_time	ft_get_time(void)
{
	struct timeval	tv;
	t_time			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

// Simply sleeps for a given number of milliseconds by
//repeatedly checking the current time until the desired
//amount of time has elapsed.
void	ft_sleep(int timeout)
{
	t_time	time;

	time = ft_get_time();
	while (ft_get_time() - time < (t_time)timeout)
		usleep(100);
}

// Cleans up the mutex locks and memory used by the program.
//It destroys each mutex lock.
void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death)
{
	int	i;

	i = 0;
	while (i < philo->n_of_philo)
	{
		pthread_mutex_destroy(philo[i].left_fork);
		pthread_mutex_destroy(philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(philo->death);
	free(forks);
	free(death);
	free(philo);
}
