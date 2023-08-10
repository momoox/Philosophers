/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:21:28 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/09 14:19:41 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <libc.h>

typedef struct s_philo
{
	int				id;
	int				last_eat;
	int				m_count;
	pthread_t		thread_id;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	int				dead_philo;
	int				start_time;
	pthread_t		*thread;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	mutex;
	pthread_mutex_t	death;
	t_philo			*p;
}					t_data;

//check_args
int		check_args(int argc, char **argv);
int		max_min(char *str);

//init
int		init_all(t_data *data, char **argv);
int		init_data(t_data *data, char **argv);
int		init_philo(t_data *data);
int		init_mutex(t_data *data);

//start_threads
void	start_threads(void *args);
void	welfare_check(void *args);
int		check_death(t_philo *philo);
void	*routine(void *arguments);

//philo_actions
void	philo_takes_forks(t_philo *philo);
void	philo_eats(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_thinks(t_philo *philo);

//utils
int		ft_atoi(char *str);
void	ft_usleep(int i);
void	print_actions(char *str, t_philo *philo);
int		timestamp(void);

//errors
int		error_manage(int error);

//main
void	free_all(t_data *data);

#endif
