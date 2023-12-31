/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:31:15 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/21 19:56:58 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < argc - 1)
	{
		if (is_int(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
