/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitorPhilos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:03:25 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/06 11:15:41 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_symp *symp, t_philo *philo)
{
	int	i;

	i = 0;
	symp->philo_death = 0;
	if (symp->philo_death == 1)
		printf("%lu %d died\n", symp->current_time, philo->right_fork);
}
