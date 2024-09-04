/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:30:33 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/21 00:50:48 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*get_last_philo(t_philo_l *ph)
{
	t_philo	*last;
	t_philo	*tmp;

	tmp = ph->top;
	if (tmp == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

void	init_philo(t_data *arg, t_philo *new, int i)
{
	new->index = i;
	new->count_repa = 0;
	new->is_die = 0;
	new->last_repa = 0;
	new->next = NULL;
	new->thread = NULL;
	new->arg = arg;
}

t_philo	*new_philo(t_data *arg, t_philo_l *ph, int i)
{
	t_philo	*new;
	t_philo	*last;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	last = get_last_philo(ph);
	if (last == NULL)
	{
		ph->top = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
	}
	init_philo(arg, new, i);
	ph->size++;
	return (new);
}

int	init_set_philos(t_data *arg, t_philo_l *ph)
{
	int		i;
	t_philo	*new;

	i = 0;
	while (i < arg->nums_philo)
	{
		new = new_philo(arg, ph, i);
		if (new == NULL)
		{
			ft_putstr_fd(ERMSG_MALLOC, 2);
			init_free_philo(ph);
			return (1);
		}
		i++;
	}
	return (0);
}
