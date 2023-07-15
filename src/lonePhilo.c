/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonePhilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:56:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/15 12:06:19 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lone_symposium(t_philo *philo)
{
	printf("0 | Philosopher 1 has taken a fork\n");
	usleep(philo->symp->time_die * 1000);
	printf("%u | Philosopher 1 has died\n", philo->symp->time_die);
}

void	ft_lone_thread(t_symp *symp, t_philo *philo)
{
	if (pthread_create(&symp->philos[0], NULL,
			(void *)ft_lone_symposium, &philo[0]))
		ft_error("failed to create thread");
	if (pthread_join(symp->philos[0], NULL))
		ft_error("failed to join thread");
}
