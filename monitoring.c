/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:55:03 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/21 19:09:43 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meal(t_data *data)
{
	int	i;

	i = -1;
	if (data->nb_meals == -1)
		return (0);
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(&data->p[i].eating);
		if (data->p[i].m_count <= data->nb_meals)
		{
			pthread_mutex_unlock(&data->p[i].eating);
			return (0);
		}
		pthread_mutex_unlock(&data->p[i].eating);
	}
	pthread_mutex_lock(&data->stopit);
	data->stop = 1;
	pthread_mutex_unlock(&data->stopit);
	return (1);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	pthread_mutex_lock(&philo->data->stopit);
	if ((timestamp() - philo->data->start_time)
		- philo->last_eat >= philo->data->t_die)
	{
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->stopit);
		pthread_mutex_unlock(&philo->eating);
		printf("%d %d died\n", timestamp()
			- philo->data->start_time, philo->id);
		return (1);
	}
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->data->stopit);
	return (0);
}

int	check_stop(t_data *data)
{
	pthread_mutex_lock(&data->stopit);
	if (data->stop == 1)
	{
		pthread_mutex_unlock(&data->stopit);
		return (1);
	}
	pthread_mutex_unlock(&data->stopit);
	return (0);
}

void	*welfare_check(t_data *data)
{
	int	i;

	if (data->nb_philo == 1)
		return (NULL);
	pthread_mutex_lock(&data->start);
	data->start_time = timestamp();
	pthread_mutex_unlock(&data->start);
	while (1)
	{
		i = -1;
		while (++i < data->nb_philo)
			if (check_death(&data->p[i]) == 1 || check_meal(data) == 1)
				return (NULL);
	}
}
