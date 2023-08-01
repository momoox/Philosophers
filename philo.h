/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:51:34 by mgeisler          #+#    #+#             */
/*   Updated: 2023/08/01 12:14:25 by mgeisler         ###   ########.fr       */
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
	int			id;
	int			ate;
	int			last_meal;
	int			death_time;
	pthread_t	thread_id;
}				t_philo;

typedef struct s_info
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int 			nb_eat;
	int				dead_philo;
	int				start_time;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	fork_r;
	pthread_mutex_t	mutex;
	t_philo			*p;
}					t_info;

int		main(int argc, char **argv);
//init_args
int		is_int(char *str);
int		check_params(t_info *info, int argc, char **argv);
void	mutex_init(t_info *info);
int		create_threads(t_info *info);
//routine
void	*routine(void *info);
//philo_actions
// int		philo_takes_forks(t_info *info);
// void	philo_eats(t_info *info);
// void	philo_sleeps(t_info *info);
// void	philo_thinks(t_info *info);
// int		philo_is_dead(t_info *info);
//utils
int		ft_atoi(char *str);
int		timestamp(void);
void	print_actions(char *str, t_info *info);
//errors
int		error_manage(t_info *info, int error);

#endif
