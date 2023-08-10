/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:22:54 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/10 18:06:01 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	free(data->fork_mutex);
	data->fork_mutex = NULL;
	free(data->p);
	data->p = NULL;
	pthread_mutex_destroy(&(data->mutex));
	pthread_mutex_destroy(&(data->death));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) == 1)
	{
		free_all(&data);
		error_manage(2);
		return (1);
	}
	if (init_all(&data, argv) != 0)
	{
		free_all(&data);
		error_manage(3);
		return (1);
	}
	welfare_check(&data);
	start_threads(&data);
	free_all(&data);
}
