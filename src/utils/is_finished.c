/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finished.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:51:11 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:51:25 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_finished(t_philo *p)
{
	pthread_mutex_lock(&p->arg->die);
	if (p->arg->fini == 1)
	{
		pthread_mutex_unlock(&p->arg->die);
		return (0);
	}
	pthread_mutex_unlock(&p->arg->die);
	return (1);
}
