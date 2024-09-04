/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:48:29 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:49:35 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_fork_mutex(t_data *arg, t_philo_l *ph)
{
	int		i;
	int		rtn;
	t_mut	*t;
	t_mut	*tmp;

	i = 0;
	t = arg->mut.top;
	while (i < arg->mut.size)
	{
		tmp = t->next;
		rtn = pthread_mutex_destroy(&t->fork);
		if (rtn != 0)
		{
			ft_putstr_fd(ERMSG_DESTROY, 2);
			free_all(arg, ph);
			return (1);
		}
		t = tmp;
		i++;
	}
	return (0);
}

int	destory_die_mutex(t_data *arg, t_philo_l *ph)
{
	int	rtn;

	rtn = pthread_mutex_destroy(&arg->die);
	if (rtn != 0)
	{
		ft_putstr_fd(ERMSG_DESTROY, 2);
		free_all(arg, ph);
		return (1);
	}
	return (0);
}

int	destory_log_mutex(t_data *arg, t_philo_l *ph)
{
	int	rtn;

	rtn = pthread_mutex_destroy(&arg->log);
	if (rtn != 0)
	{
		ft_putstr_fd(ERMSG_DESTROY, 2);
		free_all(arg, ph);
		return (1);
	}
	return (0);
}

int	destory_last_repa_mutex(t_data *arg, t_philo_l *ph)
{
	int	rtn;

	rtn = pthread_mutex_destroy(&arg->ac_last_repa);
	if (rtn != 0)
	{
		ft_putstr_fd(ERMSG_DESTROY, 2);
		free_all(arg, ph);
		return (1);
	}
	return (0);
}

int	destroy_all_mutex(t_data *arg, t_philo_l *ph)
{
	if (destroy_fork_mutex(arg, ph))
		return (1);
	if (destory_die_mutex(arg, ph))
		return (1);
	if (destory_log_mutex(arg, ph))
		return (1);
	if (destory_last_repa_mutex(arg, ph))
		return (1);
	return (0);
}
