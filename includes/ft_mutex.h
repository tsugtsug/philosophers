/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:31:17 by yokamura          #+#    #+#             */
/*   Updated: 2023/06/20 23:54:12 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MUTEX_H
# define FT_MUTEX_H

# include "philo.h"

typedef struct s_mut
{
	pthread_mutex_t	fork;
	struct s_mut	*next;
	struct s_mut	*prev;
}				t_mut;

typedef struct s_mut_l
{
	int		size;
	t_mut	*top;
}				t_mut_l;

#endif
