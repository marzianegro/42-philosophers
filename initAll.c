/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initAll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:03:30 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/06 11:26:09 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_symp(int argc, char **argv, t_symp *symp)
{
	int	i;

	i = 0;
	symp->n_philo = ft_atoi(argv[1]);
	if (symp->n_philo < 1)
		ft_error("invalid number of arguments");
	symp->philos = (pthread_t *)ft_calloc(symp->n_philo, sizeof(pthread_t));
	if (!symp->philos)
		ft_error("failed to allocate 'symp->philos'");
	symp->forks = (pthread_mutex_t *)ft_calloc(symp->n_philo,
			sizeof(pthread_mutex_t));
	if (!symp->forks)
		ft_error("failed to allocate 'symp->forks'");
	symp->time_die = ft_atoi(argv[2]);
	if (argc == 6)
	{
		symp->n_eat = (int *)ft_calloc(symp->n_philo, sizeof(int));
		while (i < symp->n_philo)
		{
			symp->n_eat[i] = ft_atoi(argv[5]);
			i++;
		}
	}
}

void	ft_init_philos(char **argv, t_symp *symp, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < symp->n_philo)
	{
		philo[i].right_fork = i;
		philo[i].left_fork = (i + 1) % symp->n_philo;
		philo[i].time_eat = ft_atoi(argv[3]);
		philo[i].time_sleep = ft_atoi(argv[4]);
		philo[i].symp = symp;
		i++;
	}
}

void	ft_init_mutex(t_symp *symp, t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&symp->symp_gate, NULL) != 0)
		ft_error("failed to initialize mutex");
	while (i < symp->n_philo)
	{
		if (pthread_mutex_init(&philo->symp->forks[i], NULL) != 0)
			ft_error("failed to initialize mutex");
		i++;
	}
}

int	ft_init_threads(t_symp *symp, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < symp->n_philo)
	{
		if (pthread_create(&symp->philos[i], NULL,
				(void *)ft_symposium, &philo[i]))
			ft_error("failed to create thread");
		i++;
	}
	i = 0;
	while (i < symp->n_philo)
	{
		if (pthread_join(symp->philos[i], NULL))
			ft_error("failed to join thread");
		i++;
	}
	return (0);
}
