/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:24:17 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/01 12:06:47 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_info *info)
{
	int	philo;
	int	i;

	i = -1;
	philo = info->nb_philo;
	info->start_time = timestamp();
	while (philo && ++i < philo)
	{
		if (pthread_create(&(info->p[i].thread_id),
				NULL, (void *)routine, info) != 0)
			return (1);
		philo--;
	}
	philo = info->nb_philo;
	i = -1;
	while (philo && ++i < philo)
	{
		if (pthread_join(info->p[i].thread_id, NULL) != 0)
			return (1);
		philo--;
	}
}

void	mutex_init(t_info *info)
{
	pthread_mutex_init(&(info->fork_l), NULL);
	pthread_mutex_init(&(info->fork_r), NULL);
	pthread_mutex_init(&(info->mutex), NULL);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_params(t_info *info, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (is_int(argv[i]) == 1)
			return (1);
		if (ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	info->nb_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->nb_eat = ft_atoi(argv[5]);
	else
		info->nb_eat = -1;
	return (0);
}
