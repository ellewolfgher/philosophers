/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:45:00 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/05/04 19:02:01 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long long	t_time;

typedef struct s_philo
{
	int				id;
	int				n_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_time_must_eat;
	int				total_eaten;
	int				*is_dead;
	t_time			last_meal;
	t_time			start_time;
	pthread_t		thread;
	pthread_mutex_t	*death;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

// init:
void	ft_init_philos(t_philo *philo, int ac, char *av[]);
void	ft_init_threads(t_philo *philo, char *av[]);
void	ft_init_mutex(t_philo *philo, char *av[], \
	pthread_mutex_t *forks, pthread_mutex_t *death);

// feast:
void	*ft_feast(void *args);

// status:
void	ft_check_pulse(t_philo *philo);
int		ft_die(t_philo *philo, int i, t_time time);
int		ft_done_eating(t_philo *philo, int *j, int *res);
int		ft_status(t_philo *philo, char *status);

// utils: 
long	ft_atol(const char *str);
int		ft_check_args(int ac, char *av[]);
void	ft_free(t_philo *philo, pthread_mutex_t *forks, pthread_mutex_t *death);
t_time	ft_get_time(void);
void	ft_sleep(int timeout);

#endif