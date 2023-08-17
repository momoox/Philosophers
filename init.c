/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:30:55 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/17 22:22:41 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_init(&(data->fork_mutex[i]), NULL);
	}
	pthread_mutex_init(&data->stopit, NULL);
	pthread_mutex_init(&data->finished, NULL);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->p = malloc(sizeof(t_philo) * data->nb_philo);
	data->fork_mutex = malloc(sizeof(t_data) * data->nb_philo);
	if (!data->p || !data->fork_mutex)
		return (1);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->p[i].eating, NULL);
		data->p[i].data = data;
		data->p[i].id = i + 1;
		data->p[i].last_eat = data->t_die;
		data->p[i].m_count = 0;
		data->p[i].fork_l = &data->fork_mutex[i];
		if (data->nb_philo != 1)
			data->p[i].fork_r = &data->fork_mutex[(i + 1) % data->nb_philo];
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_meals = ft_atoi(argv[5]);
	else
		data->nb_meals = -1;
	data->start_time = -1;
	data->stop = 0;
	data->finished_p = 0;
	return (0);
}

int	init_all(t_data *data, char **argv)
{
	if (init_data(data, argv) != 0)
		return (3);
	if (init_philo(data) != 0)
		return (3);
	if (init_mutex(data) != 0)
		return (3);
	return (0);
}
