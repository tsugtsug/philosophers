/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:46:39 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:47:26 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->arg->log);
	if (p->arg->fini != 1)
	{
		printf("%lld ", get_now_time(p->arg));
		printf("%d ", p->index + 1);
		printf("%s\n", msg);
	}
	pthread_mutex_unlock(&p->arg->log);
}

void	print_message_monitor(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->arg->log);
	printf("%lld ", get_now_time(p->arg));
	printf("%d ", p->index + 1);
	printf("%s\n", msg);
	pthread_mutex_unlock(&p->arg->log);
}
