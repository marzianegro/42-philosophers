/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitorPhilos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:03:25 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/10 15:09:35 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_monitoring(t_symp *symp)
{
	int	i;

	i = 0;
	symp->philo_death = 0;
	ft_get_time(symp);
	if (symp->current_time - symp->last_meal[i] > symp->time_die)
	{
		symp->philo_death = 1;
		printf("%lu %d has died\n", symp->current_time, i);
	}
	i = 0;
	while (i < symp->n_philo)
	{
		if (symp->n_eat[i] == 0)
			i++;
		break ;
	}
}
