/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitorPhilos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:03:25 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/10 17:17:25 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_monitoring(t_symp *symp)
{
	int	i;

	i = 0;
	symp->philo_death = 0;
	pthread_mutex_lock(&symp->symp_gate);
	while (symp->philo_death == 0)
	{
		pthread_mutex_unlock(&symp->symp_gate);
		usleep(100);
		pthread_mutex_lock(&symp->symp_gate);
		ft_get_time(symp);
		if (symp->current_time - symp->last_meal[i] > symp->time_die)
		{
			symp->philo_death = 1;
			printf("%lu %d has died\n", symp->current_time - symp->start_time, i + 1);
			pthread_mutex_unlock(&symp->symp_gate);
			return ;
		}
		pthread_mutex_unlock(&symp->symp_gate);
		i++;
		if (i == symp->n_philo)
			i = 0;
		pthread_mutex_lock(&symp->symp_gate);
	}
	pthread_mutex_unlock(&symp->symp_gate);
	// while (i < symp->n_philo)
	// {
	// 	if (symp->n_eat[i] == 0)
	// 		i++;
	// 	break ;
	// }
}
