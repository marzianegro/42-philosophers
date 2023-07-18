/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:26:34 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/18 14:29:05 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* HEADER FILES */
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

/* MACROS */

/* STRUCTURES */
typedef struct s_philo
{
	int				right_fork;
	int				left_fork;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	struct s_symp	*symp;
}			t_philo;

typedef struct s_symp
{
	pthread_mutex_t	symp_gate;
	int				n_philo; 
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_t		monitor;
	int				*n_eat;
	struct timeval	tv;
	time_t			start_time;
	time_t			current_time;
	time_t			*last_meal;
	unsigned int	time_die;
	int				philo_death;
}			t_symp;

/* PROTOTYPES */
/* initAll.c */
void	ft_alloc_symp(char **argv, t_symp *symp);
void	ft_init_symp(int argc, char **argv, t_symp *symp);
void	ft_init_philos(char **argv, t_symp *symp, t_philo *philo);
void	ft_init_mutex(t_symp *symp, t_philo *philo);
int		ft_init_threads(t_symp *symp, t_philo *philo);
/* libft.c */
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
/* lonePhilo.c */
void	ft_lone_symposium(t_philo *philo);
void	ft_lone_thread(t_symp *symp, t_philo *philo);
/* main.c */
void	ft_symposium(t_philo *philo);
/* monitorPhilos.c */
void	ft_monitoring(t_symp *symp);
void	ft_monitor_death(t_symp *symp, int *i);
void	ft_monitor_meals(t_symp *symp, int *j);
/* threadRoutine.c */
void	ft_take_fork(t_symp *symp, t_philo *philo);
void	ft_eat(t_symp *symp, t_philo *philo);
void	ft_sleep(t_symp *symp, t_philo *philo);
void	ft_think(t_symp *symp, t_philo *philo);
/* utils.c */
void	ft_error(char *str);
void	ft_get_time(t_symp *symp);
void	ft_set_last(t_philo *philo);
void	ft_end(t_symp *symp, t_philo *philo);

#endif
