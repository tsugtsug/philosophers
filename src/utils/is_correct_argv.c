/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 06:59:11 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/21 00:55:48 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	is_all_num(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static long long	philo_atol(char *str)
{
	int	i;
	int	sum;
	int	is_negative;

	i = 0;
	sum = 0;
	is_negative = 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		sum = sum * 10 + (str[i++] - '0');
	return (sum * is_negative);
}

static int	is_minus(int argc, t_data *arg)
{
	if (arg->nums_philo < 1 || arg->nums_philo > 200)
	{
		ft_putstr_fd(ERMSG_NUM_PHILO, 2);
		return (1);
	}
	if (arg->time_die <= 60 || arg->time_eat <= 60
		|| arg->time_sleep <= 60)
	{
		ft_putstr_fd(ERMSG_TIME, 2);
		return (1);
	}
	if (argc == 6 && arg->nums_eat <= 0)
	{
		ft_putstr_fd(ERMSG_NUM_EAT, 2);
		return (1);
	}
	return (0);
}

int	is_correct_argv(int argc, char **argv, t_data *arg)
{
	if (argc == 5 || argc == 6)
	{
		if (is_all_num(argv))
		{
			ft_putstr_fd(ERMSG_ARG_NUM, 2);
			return (1);
		}
		arg->nums_philo = philo_atol(argv[1]);
		arg->time_die = philo_atol(argv[2]);
		arg->time_eat = philo_atol(argv[3]);
		arg->time_sleep = philo_atol(argv[4]);
		arg->nums_eat = 0;
		arg->mut.size = 0;
		arg->mut.top = NULL;
		if (argc == 6)
			arg->nums_eat = philo_atol(argv[5]);
		else
			arg->nums_eat = 0;
		if (is_minus(argc, arg))
			return (1);
		return (0);
	}
	else
		ft_putstr_fd(ERMSG_ARG, 2);
	return (1);
}
