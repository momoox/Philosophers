/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:22:54 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/21 19:47:30 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	int	i;

	while (1)
	{
		pthread_mutex_lock(&data->finished);
		if (data->finished_p == data->nb_philo || data->nb_philo == 1)
		{
			pthread_mutex_unlock(&data->finished);
			break ;
		}
		pthread_mutex_unlock(&data->finished);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(data->p[i].thread_id, NULL))
			return ;
		pthread_mutex_destroy(&data->p[i].eating);
	}
	free(data->fork_mutex);
	data->fork_mutex = NULL;
	free(data->p);
	data->p = NULL;
	free_next(data);
}

void	free_next(t_data *data)
{
	pthread_mutex_destroy(&data->stopit);
	pthread_mutex_destroy(&data->finished);
	pthread_mutex_destroy(&data->start);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == 1)
	{
		error_manage(2);
		return (1);
	}
	if (init_all(&data, argv) == 1)
	{
		error_manage(3);
		return (1);
	}
	start_threads(&data);
	welfare_check(&data);
	free_all(&data);
}
