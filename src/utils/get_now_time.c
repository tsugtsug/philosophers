/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_now_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:21:11 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/21 23:54:42 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_now_time(t_data *arg)
{
	struct timeval		time;
	long long			sec;
	long long			usec;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec - arg->start.tv_sec) * 1000;
	usec = (time.tv_usec - arg->start.tv_usec) / 1000;
	return (sec + usec);
}
