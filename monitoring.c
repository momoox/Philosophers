/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:55:03 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/14 20:35:48 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meal(t_philo *philo)
{
	int	i;

	i = -1;
	while (i++ < philo->data->nb_philo)
	{
		if (philo->m_count < philo->data->nb_meals)
			return (0);
		else
			return (1);
	}
	return (0);
}

int	check_death(t_philo *philo)
{
	if (timestamp() - philo->last_eat >= philo->data->t_die)
	{
		pthread_mutex_lock(&philo->data->death);
		philo->data->dead_philo = 1;
		pthread_mutex_unlock(&philo->data->death);
		printf("%d %d died\n", timestamp()
			- philo->data->start_time, philo->id);
		return (1);
	}
	return (0);
}

void	welfare_check(t_data *data)
{
	int	i;

	i = -1;
	while (1)
	{
		while (i++ < data->nb_philo)
		{
			if (check_death(&data->p[i]) == 1)
				return ;
			if (check_meal(&data->p[i]) == 1)
				return ;
		}
		i = -1;
	}
}