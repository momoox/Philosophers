/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:51:25 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/01 12:10:43 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info			*info;

	info = NULL;
	info->p = malloc(sizeof(int) * info->nb_philo);
	if (!info->p)
		return (1);
	if (check_params(info, argc, argv) == 2)
		return (error_manage(info, 2));
	mutex_init(info);
	create_threads(info);
	return (0);
}
