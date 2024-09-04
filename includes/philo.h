/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 06:59:18 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:55:13 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "ft_mutex.h"

# define ERMSG_ARG	"[usage]: ./philo <philos> <die> <eat> <sleep> (<must>)"
# define ERMSG_ARG_NUM	"All arguments must be positive integers"
# define ERMSG_MALLOC "malloc() failed"
# define ERMSG_TH_CREATE "pthread_create() failed"
# define ERMSG_TH_JOIN "pthread_join() failed"
# define ERMSG_DESTROY "pthread_mutex_destroy() failed"
# define ERMSG_UNLOCK "pthread_mutex_unlock() failed"
# define ERMSG_MUT_INIT "pthread_mutex_init() failed"
# define ERMSG_NUM_PHILO "The number of philosophers must be from 1 to 200"
# define ERMSG_TIME "Each time argument must be more than 60 ms"
# define ERMSG_NUM_EAT "The number of meals, if set, must be positive"

# define MSG_FORK "has taken a fork"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIE "died"

typedef struct s_data
{
	long long		nums_philo;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	long long		nums_eat;
	int				is_someone_died;
	pthread_mutex_t	die;
	pthread_mutex_t	log;
	pthread_mutex_t	ac_last_repa;
	int				fini;
	struct timeval	start;
	pthread_t		monitor;
	t_mut_l			mut;
}				t_data;

typedef struct s_philo
{
	int					index;
	int					count_repa;
	int					is_die;
	long long			last_repa;
	struct s_philo		*next;
	struct s_philo		*prev;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	pthread_t			thread;
	t_data				*arg;
}				t_philo;

typedef struct s_philo_l
{
	int			size;
	t_philo		*top;
}				t_philo_l;

int			is_correct_argv(int argc, char **argv, t_data *arg);
void		ft_putstr_fd(char *s, int fd);

long long	get_now_time(t_data *arg);
int			is_finished(t_philo *p);

int			init_main(t_data *arg, t_philo_l *ph);
int			init_set_philos(t_data *arg, t_philo_l *ph);
int			init_mutex(t_data *arg, t_philo_l *ph);
void		set_hands_mutex(t_data *arg, t_philo_l *ph);

void		init_free_philo(t_philo_l *ph);
void		init_free_mut(t_data *arg);
void		free_all(t_data *arg, t_philo_l *ph);

int			destroy_all_mutex(t_data *arg, t_philo_l *ph);
int			destroy_fork_mutex(t_data *arg, t_philo_l *ph);
int			destory_die_mutex(t_data *arg, t_philo_l *ph);

void		*ph_main(void *p);
void		print_message(t_philo *p, char *msg);
void		print_message_monitor(t_philo *p, char *msg);

void		*monitor_main(void *p);
int			philos_thread_create(t_data *arg, t_philo_l *ph);
int			philos_thread_join(t_data *arg, t_philo_l *ph);

#endif
