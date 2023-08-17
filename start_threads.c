/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:25:34 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/17 22:39:24 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arguments)
{
	t_philo		*philo;

	philo = (t_philo *)arguments;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 10, philo->data);
	if (fork_check(philo) == 1)
		return (NULL);
	while (check_stop(philo->data) == 0)
	{
		philo_takes_forks(philo);
		philo_eats(philo);
		philo_sleeps(philo);
		print_actions("is thinking", philo);
	}
	pthread_mutex_lock(&philo->data->finished);
	philo->data->finished_p++;
	pthread_mutex_unlock(&philo->data->finished);
	return (NULL);
}

int	fork_check(t_philo *philo)
{
	if (philo->data->nb_philo == 1)
	{
		print_actions("has taken a fork", philo);
		ft_usleep(philo->data->t_die, philo->data);
		print_actions("is dead", philo);
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
}
