/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 20:20:01 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/01 12:14:34 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_manage(t_info *info, int error)
{
	if (error == 1)
		printf("Malloc error.\n");
	if (error == 2)
	{
		printf("Error with arguments.\n");
		printf("Should look like this:\n");
		printf("./philo [nb of philosphers] [time to die] [time to sleep]\n");
		printf("You can had [nb of time each philo must eat]\n");
		free(info->p);
		free(info);
	}
	return (0);
}
