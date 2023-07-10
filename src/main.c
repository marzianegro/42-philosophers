/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:40 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/10 16:41:58 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_symposium(t_philo *philo)
{
	if (philo->right_fork % 2)
		usleep(50000);
	pthread_mutex_lock(&philo->symp->symp_gate);
	while (philo->symp->philo_death != 1)
	{
		pthread_mutex_unlock(&philo->symp->symp_gate);
		pthread_mutex_lock(&philo->symp->forks[philo->right_fork]);
		ft_take_fork(philo->symp, philo);
		pthread_mutex_lock(&philo->symp->forks[philo->left_fork]);
		ft_take_fork(philo->symp, philo);
		ft_eat(philo->symp, philo);
		usleep(philo->time_eat * 1000);
		pthread_mutex_unlock(&philo->symp->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->symp->forks[philo->left_fork]);
		ft_sleep(philo->symp, philo);
		usleep(philo->time_sleep * 1000);
		ft_think(philo->symp, philo);
		pthread_mutex_lock(&philo->symp->symp_gate);
	}
	pthread_mutex_unlock(&philo->symp->symp_gate);
}

int	main(int argc, char **argv)
{
	t_symp	symp;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		ft_error("invalid number of arguments");
	ft_alloc_symp(argc, argv, &symp);
	ft_init_symp(argc, argv, &symp);
	philo = (t_philo *)ft_calloc(symp.n_philo, sizeof(t_philo));
	if (!philo)
		ft_error("failed to allocate 'philo'");
	ft_init_philos(argv, &symp, philo);
	ft_init_mutex(&symp, philo);
	ft_init_threads(&symp, philo);
	ft_end(argc, &symp);
	return (0);
}
