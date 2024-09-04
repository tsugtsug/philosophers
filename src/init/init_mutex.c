/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:29:59 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:54:57 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mut_arg(t_mut *new)
{
	new->next = NULL;
	if (pthread_mutex_init(&new->fork, NULL) != 0)
	{
		ft_putstr_fd(ERMSG_MUT_INIT, 2);
		return (1);
	}
	return (0);
}

t_mut	*get_last_mut(t_data *arg)
{
	t_mut	*last;
	t_mut	*tmp;

	tmp = arg->mut.top;
	if (tmp == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

t_mut	*new_mut(t_data *arg)
{
	t_mut	*new;
	t_mut	*last;

	new = (t_mut *)malloc(sizeof(t_mut));
	if (new == NULL)
		return (NULL);
	last = get_last_mut(arg);
	if (last == NULL)
	{
		arg->mut.top = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
	}
	if (init_mut_arg(new))
		return (NULL);
	arg->mut.size++;
	return (new);
}

int	init_die_mutex(t_data *arg, t_philo_l *ph)
{
	if (pthread_mutex_init(&arg->die, NULL) != 0)
	{
		ft_putstr_fd(ERMSG_MUT_INIT, 2);
		if (destroy_fork_mutex(arg, ph))
			return (1);
		free_all(arg, ph);
		return (1);
	}
	if (pthread_mutex_init(&arg->log, NULL) != 0)
	{
		ft_putstr_fd(ERMSG_MUT_INIT, 2);
		if (destroy_fork_mutex(arg, ph))
			return (1);
		free_all(arg, ph);
		return (1);
	}
	if (pthread_mutex_init(&arg->ac_last_repa, NULL) != 0)
	{
		ft_putstr_fd(ERMSG_MUT_INIT, 2);
		if (destroy_fork_mutex(arg, ph))
			return (1);
		free_all(arg, ph);
		return (1);
	}
	return (0);
}

int	init_mutex(t_data *arg, t_philo_l *ph)
{
	int		i;
	t_mut	*mut;

	i = 0;
	while (i < arg->nums_philo)
	{
		mut = new_mut(arg);
		if (mut == NULL)
		{
			ft_putstr_fd(ERMSG_MALLOC, 2);
			free_all(arg, ph);
			return (1);
		}
		i++;
	}
	if (init_die_mutex(arg, ph))
		return (0);
	set_hands_mutex(arg, ph);
	return (0);
}
