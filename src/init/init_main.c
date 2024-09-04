/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:33:12 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/21 21:24:00 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_ph(t_philo_l *ph)
{
	ph->size = 0;
	ph->top = NULL;
}

int	init_main(t_data *arg, t_philo_l *ph)
{
	init_ph(ph);
	arg->fini = 0;
	arg->is_someone_died = 0;
	if (init_set_philos(arg, ph))
		return (1);
	if (init_mutex(arg, ph))
		return (1);
	return (0);
}
