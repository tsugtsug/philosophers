/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:42:37 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:45:50 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_thread_create(t_data *arg, t_philo_l *ph)
{
	int	rtn;

	rtn = pthread_create(&arg->monitor, NULL, &monitor_main, ph);
	if (rtn != 0)
	{
		ft_putstr_fd(ERMSG_TH_CREATE, 2);
		free_all(arg, ph);
		return (1);
	}
	return (0);
}

int	philos_thread_create(t_data *arg, t_philo_l *ph)
{
	t_philo	*p;
	int		rtn;

	if (monitor_thread_create(arg, ph))
		return (1);
	p = ph->top;
	while (p != NULL)
	{
		rtn = pthread_create(&p->thread, NULL, &ph_main, p);
		if (rtn != 0)
		{
			ft_putstr_fd(ERMSG_TH_CREATE, 2);
			free_all(arg, ph);
			return (1);
		}
		p = p->next;
	}
	return (0);
}

int	monitor_thread_join(t_data *arg, t_philo_l *ph)
{
	int		rtn;

	rtn = pthread_join(arg->monitor, NULL);
	if (rtn != 0)
	{
		ft_putstr_fd(ERMSG_TH_JOIN, 2);
		free_all(arg, ph);
		return (1);
	}
	return (0);
}

int	philos_thread_join(t_data *arg, t_philo_l *ph)
{
	t_philo	*p;
	int		rtn;

	if (monitor_thread_join(arg, ph))
		return (1);
	p = ph->top;
	while (p != NULL)
	{
		rtn = pthread_join(p->thread, NULL);
		if (rtn != 0)
		{
			ft_putstr_fd(ERMSG_TH_JOIN, 2);
			free_all(arg, ph);
			return (1);
		}
		p = p->next;
	}
	return (0);
}
