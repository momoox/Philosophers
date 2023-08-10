/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:25:34 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/10 18:06:40 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arguments)
{
	t_philo		*philo;

	philo = (t_philo *)arguments;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 10);
	while (philo->data->dead_philo == 0)
	{
		if (philo->data->dead_philo != 0)
			return (NULL);
		philo_takes_forks(philo);
		if (philo->data->dead_philo != 0)
			return (NULL);
		philo_eats(philo);
		if (philo->data->dead_philo != 0)
			return (NULL);
		philo_sleeps(philo);
		if (philo->data->dead_philo != 0)
			return (NULL);
		print_actions("is thinking", philo);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	int		i;

	i = -1;
	ft_usleep(philo->data->t_die + 1);
	while (++i < philo->data->nb_philo)
	{
		if (timestamp() - philo->last_eat >= philo->data->t_die)
		{
			pthread_mutex_lock(&philo->data->death);
			philo->data->dead_philo = 1;
			pthread_mutex_unlock(&philo->data->death);
			printf("%d %d died\n", timestamp()
				- philo->data->start_time, philo->id);
			return (0);
		}
	}
	return (0);
}

void	welfare_check(void *args)  //monitoring
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = 0;
	while (data->start_time != 0)
		;
	while (data->dead_philo == 0)
	{
		if (check_death(&data->p[i]) != 0)
		{
			ft_usleep(100);
			return ;
		}
		if (data->p[i].m_count == data->nb_meals)
		{
			free_all(data);
			return ;
		}
		i++;
		if (i == data->nb_philo)
			i = 0;
	}
}

void	start_threads(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = -1;
	data->start_time = timestamp();
	welfare_check(data);
	while (++i < data->nb_philo)
	{
		if (pthread_create(&data->p[i].thread_id,
				NULL, routine, &data->p[i]) != 0)
			return ;
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->p[i].thread_id, NULL))
			return ;
	}
}
