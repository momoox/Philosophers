/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:27:18 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/17 22:44:24 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_manage(int error)
{
	if (error == 1)
		printf("Malloc error.\n");
	else if (error == 2)
	{
		printf("Arguments error, please execute as followed:\n");
		printf("./philo [nb of philosphers] [time to die] [time to sleep]\n");
		printf("You can had [nb of time each philo must eat]\n");
	}
	else if (error == 3)
		printf("Init error.\n");
	else if (error == 4)
		printf("Creation threads error.\n");
	return (0);
}
