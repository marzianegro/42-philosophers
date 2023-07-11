/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:09:38 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/11 17:26:57 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_error(char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	exit(1);
}

void	ft_get_time(t_symp *symp)
{
	gettimeofday(&symp->tv, NULL);
	symp->current_time = ((time_t)(symp->tv.tv_sec) * 1000)
		+ ((time_t)(symp->tv.tv_usec) / 1000);
}

void	ft_set_last(t_philo *philo)
{
	gettimeofday(&philo->symp->tv, NULL);
	philo->symp->last_meal[philo->right_fork] = ((time_t)(philo->symp->tv.tv_sec) * 1000)
	+ ((time_t)(philo->symp->tv.tv_usec) / 1000);
}

void	ft_end(int argc, t_symp *symp)
{
	free(symp->philos);
	free(symp->forks);
	free(symp->last_meal);
	if (argc == 6)
		free(symp->n_eat);
}
