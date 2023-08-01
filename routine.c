/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:58:19 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/01 12:07:06 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *info)
{
	t_info	*data;

	data = (t_info *)info;
	while (data->dead_philo == 0)
	{
		philo_takes_forks(data);
	}
	philo_eat(data);
}

//check death
//exec eating
//exec sleep
//destroy inits with free_all