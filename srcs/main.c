/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:21:25 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/04 18:19:00 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;

	if (ac != 5 && ac != 6)
		return (1);
	if (ft_check_args(ac, av) == 0)
		return (2);
	philo = malloc(sizeof(t_philo) * ft_atol(av[1]));
	if (!philo)
		return (3);
	forks = malloc(sizeof(pthread_mutex_t) * ft_atol(av[1]));
	death = malloc(sizeof(pthread_mutex_t));
	ft_init_philos(philo, ac, av);
	ft_init_mutex(philo, av, forks, death);
	ft_init_threads(philo, av);
	ft_free(philo, forks, death);
	return (0);
}
