/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:56:08 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:51:22 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_fork(t_philo *p)
{
	print_message(p, MSG_THINK);
	if (p->index % 2 == 1)
	{
		pthread_mutex_lock(p->right);
		print_message(p, MSG_FORK);
		pthread_mutex_lock(p->left);
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(p->left);
		print_message(p, MSG_FORK);
		if (p->arg->nums_philo == 1)
		{
			pthread_mutex_unlock(p->left);
			return (1);
		}
		usleep(100);
		pthread_mutex_lock(p->right);
	}
	print_message(p, MSG_FORK);
	return (0);
}

void	ph_wait(t_philo *p, long long time_wait)
{
	long long	start_time;
	long long	cur_time;

	start_time = get_now_time(p->arg);
	while (1)
	{
		cur_time = get_now_time(p->arg);
		if (cur_time - start_time >= time_wait)
			break ;
	}
}

void	ph_eat(t_philo *p)
{
	print_message(p, MSG_EAT);
	pthread_mutex_lock(&p->arg->ac_last_repa);
	p->last_repa = get_now_time(p->arg);
	pthread_mutex_unlock(&p->arg->ac_last_repa);
	ph_wait(p, p->arg->time_eat);
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
	p->count_repa++;
}

void	ph_sleep(t_philo *p)
{
	print_message(p, MSG_SLEEP);
	ph_wait(p, p->arg->time_sleep);
}

void	*ph_main(void *pointer)
{
	t_philo	*p;

	p = (t_philo *)pointer;
	while (is_finished(p))
	{
		if (ph_fork(p) == 1)
			break ;
		ph_eat(p);
		ph_sleep(p);
	}
	return (NULL);
}
