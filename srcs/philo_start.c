/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:28 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:29 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_start(t_data *data)
{
	size_t	idx;

	idx = (size_t)-1;
	data->start_time = get_time();
	while (++idx < data->philo_count)
		if (pthread_create(&data->philos[idx].thread, NULL,
				(void *)philo_thread, data->philos + idx) != 0)
			return (0);
	return (1);
}
