/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:27:18 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/17 23:11:44 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_manage(int error)
{
	if (error == 1)
		printf("Malloc error.\n");
	else if (error == 2)
	{
		printf("\nArguments error, please execute as followed:\n");
		printf("\n./philo [nb of philosphers] [time to die] [time to sleep]\n");
		printf("\nYou can had [nb of time each philo must eat]\n");
	}
	else if (error == 3)
		printf("\nInit error.\n");
	else if (error == 4)
		printf("\nCreation threads error.\n");
	return (0);
}
