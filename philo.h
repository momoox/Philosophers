/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:21:28 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/21 19:55:22 by mgeisler         ###   ########.fr       */
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
	pthread_mutex_t	eating;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	int				start_time;
	int				finished_p;
	int				stop;
	pthread_t		*thread;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	stopit;
	pthread_mutex_t	meal;
	pthread_mutex_t	finished;
	pthread_mutex_t	start;
	t_philo			*p;
}					t_data;

/*check_args*/
int		check_args(int argc, char **argv);
int		max_min(char *str);

/*init*/
int		init_all(t_data *data, char **argv);
int		init_data(t_data *data, char **argv);
int		init_philo(t_data *data);
int		init_mutex(t_data *data);

/*start_threads*/
void	*routine(void *arguments);
int		fork_check(t_philo *philo);
void	start_threads(void *args);
int		check_start(t_data *data);

/*monitoring*/
int		check_meal(t_data *data);
int		check_death(t_philo *philo);
int		check_stop(t_data *data);
void	*welfare_check(t_data *data);

/*philo_actions*/
void	philo_takes_forks(t_philo *philo);
void	philo_eats(t_philo *philo);
void	philo_sleeps(t_philo *philo);
void	philo_thinks(t_philo *philo);

/*utils*/
int		ft_atoi(char *str);
void	ft_usleep(int i, t_data *data);
void	print_actions(char *str, t_philo *philo);
int		ft_strlen(char *str);
int		timestamp(void);

/*errors*/
int		error_manage(int error);

/*main*/
void	free_all(t_data *data);
void	free_next(t_data *data);

#endif
