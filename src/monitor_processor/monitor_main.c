/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:56:29 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:47:21 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_all_eatcount(t_philo_l *ph)
{
	t_philo	*p;
	int		i;

	p = ph->top;
	i = 0;
	while (i < ph->size)
	{
		if (p->count_repa < p->arg->nums_eat)
			return (0);
		i++;
		p = p->next;
	}
	return (1);
}

int	is_someone_dead(t_philo_l *ph)
{
	t_philo	*p;

	p = ph->top;
	while (p != NULL)
	{
		pthread_mutex_lock(&p->arg->ac_last_repa);
		if (get_now_time(p->arg) - p->last_repa >= p->arg->time_die)
		{
			pthread_mutex_unlock(&p->arg->ac_last_repa);
			pthread_mutex_lock(&p->arg->die);
			p->arg->fini = 1;
			print_message_monitor(p, MSG_DIE);
			pthread_mutex_unlock(&p->arg->die);
			return (1);
		}
		pthread_mutex_unlock(&p->arg->ac_last_repa);
		p = p->next;
	}
	return (0);
}

void	*monitor_main(void *pointer)
{
	t_philo_l	*ph;

	ph = (t_philo_l *)pointer;
	pthread_mutex_lock(&ph->top->arg->log);
	gettimeofday(&ph->top->arg->start, NULL);
	pthread_mutex_unlock(&ph->top->arg->log);
	while (1)
	{
		usleep(100);
		if (is_someone_dead(ph))
			return (NULL);
		if (ph->top->arg->nums_eat != 0 && is_all_eatcount(ph))
		{
			pthread_mutex_lock(&ph->top->arg->die);
			ph->top->arg->fini = 1;
			pthread_mutex_unlock(&ph->top->arg->die);
		}
		pthread_mutex_lock(&ph->top->arg->die);
		if (ph->top->arg->fini == 1)
		{
			pthread_mutex_unlock(&ph->top->arg->die);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->top->arg->die);
	}
}
