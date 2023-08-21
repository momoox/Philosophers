/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:34:30 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/17 23:08:32 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timestamp(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	print_actions(char *str, t_philo *philo)
{
	if (check_stop(philo->data) == 0)
		printf("%d %d %s\n", timestamp()
			- philo->data->start_time, philo->id, str);
}

void	ft_usleep(int i, t_data *data)
{
	long int	time;

	if (check_stop(data) == 1)
		return ;
	time = timestamp();
	while (timestamp() - time < i)
	{
		if (check_stop(data) == 1)
			return ;
		usleep(500);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result < 0 || result > 2147483647 || i > 10)
		return (-1);
	return (sign * result);
}
