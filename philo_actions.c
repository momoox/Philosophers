/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:08:56 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/14 19:21:12 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_actions("has taken a fork", philo);
	pthread_mutex_lock(philo->fork_r);
	print_actions("has taken a fork", philo);
}

void	philo_eats(t_philo *philo)
{
	print_actions("is eating", philo);
	pthread_mutex_lock(&philo->data->mutex);
	philo->last_eat = timestamp() - philo->data->start_time;
	philo->m_count++;
	pthread_mutex_unlock(&philo->data->mutex);
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	philo_sleeps(t_philo *philo)
{
	print_actions("is sleeping", philo);
	ft_usleep(philo->data->t_sleep);
}

void	philo_thinks(t_philo *philo)
{
	print_actions("is thinking", philo);
}
