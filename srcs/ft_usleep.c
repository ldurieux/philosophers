/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:27:42 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/28 09:27:43 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(size_t time)
{
	size_t	curr_time;
	size_t	end_time;
	size_t	wait_time;

	curr_time = get_time();
	end_time = curr_time + time - 1;
	while (curr_time < end_time)
	{
		curr_time = get_time();
		wait_time = (end_time - curr_time) / 2;
		if (wait_time > time)
			break ;
		usleep((unsigned int)wait_time);
	}
}
