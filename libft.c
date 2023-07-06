/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:46:43 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/06 10:09:29 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (res * sign < INT_MIN || res * sign > INT_MAX)
		return (1);
	return (res * sign);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*ret;

	i = 0;
	ret = (char *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	while (i < (nmemb * size))
		ret[i++] = 0;
	return ((void *)ret);
}
