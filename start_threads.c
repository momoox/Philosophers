/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:25:34 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/14 20:36:13 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arguments)
{
	t_philo		*philo;

	philo = (t_philo *)arguments;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 10);
	if (fork_check(philo) == 1)
		return (NULL);
	philo_takes_forks(philo);
	philo_eats(philo);
	philo_sleeps(philo);
	print_actions("is thinking", philo);
	return (NULL);
}

int	fork_check(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		print_actions("has taken a fork", philo);
		return (1);
	}
	return (0);
}

void	start_threads(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	i = -1;
	data->start_time = timestamp();
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
