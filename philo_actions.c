/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:08:56 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/17 22:40:04 by mgeisler         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->eating);
	philo->last_eat = timestamp() - philo->data->start_time;
	philo->m_count++;
	pthread_mutex_unlock(&philo->eating);
	ft_usleep(philo->data->t_eat, philo->data);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	philo_sleeps(t_philo *philo)
{
	print_actions("is sleeping", philo);
	ft_usleep(philo->data->t_sleep, philo->data);
}

void	philo_thinks(t_philo *philo)
{
	print_actions("is thinking", philo);
}
