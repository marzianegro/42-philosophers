/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitorPhilos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:03:25 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/11 17:26:45 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_monitoring(t_symp *symp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	symp->philo_death = 0;
	pthread_mutex_lock(&symp->symp_gate);
	while (symp->philo_death == 0)
	{
		pthread_mutex_unlock(&symp->symp_gate);
		ft_monitor_meals(symp, &j);
		usleep(100);
		ft_monitor_death(symp, &i);
		pthread_mutex_lock(&symp->symp_gate);
	}
	pthread_mutex_unlock(&symp->symp_gate);
}

void	ft_monitor_death(t_symp *symp, int *i)
{
	pthread_mutex_lock(&symp->symp_gate);
	ft_get_time(symp);
	if (symp->current_time - symp->last_meal[*i] > symp->time_die)
	{
		symp->philo_death = 1;
		printf("%lu | Philosopher %d has died\n", symp->current_time - symp->start_time, *i + 1);
		pthread_mutex_unlock(&symp->symp_gate);
		return ;
	}
	pthread_mutex_unlock(&symp->symp_gate);
	*i += 1;
	if (*i == symp->n_philo)
		*i = 0;
}

void	ft_monitor_meals(t_symp *symp, int *j)
{
	pthread_mutex_lock(&symp->symp_gate);
	while (*j < symp->n_philo)
	{
		if (symp->n_eat[*j] == 0)
			*j += 1;
		else
		{	
			*j = 0;
			break ;
		}
	}
	pthread_mutex_unlock(&symp->symp_gate);
	pthread_mutex_lock(&symp->symp_gate);
	if (*j == symp->n_philo)
		symp->philo_death = 1;
	pthread_mutex_unlock(&symp->symp_gate);
}
