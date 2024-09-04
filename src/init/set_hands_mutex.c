/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hands_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:54:47 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:55:01 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_hands_mutex(t_data *arg, t_philo_l *ph)
{
	t_philo	*p;
	t_mut	*t;
	int		i;

	i = 0;
	p = ph->top;
	t = arg->mut.top;
	while (i < ph->size)
	{
		if (p->next != NULL)
		{
			p->right = &(t->fork);
			p->left = &(t->next->fork);
		}
		else
		{
			p->right = &(t->fork);
			p->left = &(arg->mut.top->fork);
		}
		t = t->next;
		p = p->next;
		i++;
	}
}
