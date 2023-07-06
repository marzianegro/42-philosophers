/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:09:38 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/06 11:26:08 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("\033[1;91mError\033[0;39m: %s!\n", str);
	exit(1);
}

void	ft_get_time(t_symp *symp)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	symp->current_time = ((time_t)(tv.tv_sec) * 1000)
		+ ((time_t)(tv.tv_usec) / 1000);
}
