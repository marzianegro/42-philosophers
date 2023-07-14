/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonePhilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:56:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/14 16:09:25 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lone_routine(t_symp *symp, t_philo *philo)
{
	while (symp->philo_death != 1)
	{
		ft_get_time(philo->symp);
		printf("%ld | Philosopher %d has taken a fork\n",
			symp->current_time - symp->start_time, philo->right_fork + 1);
		printf("%ld | Philosopher %d has taken a fork\n",
			symp->current_time - symp->start_time, philo->right_fork + 1);
		ft_eat(philo->symp, philo);
		usleep(philo->time_eat * 1000);
		ft_sleep(philo->symp, philo);
		usleep(philo->time_sleep * 1000);
		ft_think(philo->symp, philo);
	}
}
