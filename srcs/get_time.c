/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:26:20 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/27 12:26:22 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;
	size_t			res;

	gettimeofday(&time, NULL);
	res = time.tv_sec;
	res *= 1000000;
	res += time.tv_usec;
	return (res);
}
