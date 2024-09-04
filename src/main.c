/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 06:59:05 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/22 23:57:36 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			arg;
	t_philo_l		ph;

	if (is_correct_argv(argc, argv, &arg))
		return (1);
	if (init_main(&arg, &ph))
		return (1);
	if (philos_thread_create(&arg, &ph))
		return (1);
	if (philos_thread_join(&arg, &ph))
		return (1);
	if (destroy_all_mutex(&arg, &ph))
		return (1);
	free_all(&arg, &ph);
	return (0);
}
