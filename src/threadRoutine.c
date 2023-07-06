/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadRoutine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:18:35 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/06 22:04:09 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_take_fork(t_symp *symp, t_philo *philo)
{
	pthread_mutex_lock(&symp->symp_gate);
	if (symp->philo_death != 1)
	{
		ft_get_time(symp);
		printf("%ld %d has taken a fork\n",
			symp->current_time, philo->right_fork);
	}
	pthread_mutex_unlock(&symp->symp_gate);
}

void	ft_eat(t_symp *symp, t_philo *philo)
{
	pthread_mutex_lock(&symp->symp_gate);
	if (symp->philo_death != 1)
	{
		ft_get_time(symp);
		printf("%ld %d is eating\n", symp->current_time, philo->right_fork);
	}
	pthread_mutex_unlock(&symp->symp_gate);
}

void	ft_sleep(t_symp *symp, t_philo *philo)
{
	pthread_mutex_lock(&symp->symp_gate);
	if (symp->philo_death != 1)
	{
		ft_get_time(symp);
		printf("%ld %d is sleeping\n", symp->current_time, philo->right_fork);
	}
	pthread_mutex_unlock(&symp->symp_gate);
}

void	ft_think(t_symp *symp, t_philo *philo)
{
	pthread_mutex_lock(&symp->symp_gate);
	if (symp->philo_death != 1)
	{
		ft_get_time(symp);
		printf("%ld %d is sleeping\n", symp->current_time, philo->right_fork);
	}
	pthread_mutex_unlock(&symp->symp_gate);
}
