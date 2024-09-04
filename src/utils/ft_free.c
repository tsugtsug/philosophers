/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:13:04 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/20 22:20:28 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_free_philo(t_philo_l *ph)
{
	t_philo	*p;
	t_philo	*tmp;

	p = ph->top;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	ph->top = NULL;
}

void	init_free_mut(t_data *arg)
{
	t_mut	*p;
	t_mut	*tmp;

	p = arg->mut.top;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	arg->mut.top = NULL;
}

void	free_all(t_data *arg, t_philo_l *ph)
{
	init_free_philo(ph);
	init_free_mut(arg);
}
