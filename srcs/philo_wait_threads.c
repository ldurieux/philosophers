/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:35 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_wait_threads(t_data *data)
{
	size_t	idx;

	pthread_mutex_lock(&data->print_mutex);
	data->stop_print = 1;
	pthread_mutex_unlock(&data->print_mutex);
	idx = (size_t)-1;
	while (++idx < data->philo_count)
	{
		pthread_mutex_lock(&data->philos[idx].mutex);
		data->philos[idx].dead = 1;
		pthread_mutex_unlock(&data->philos[idx].mutex);
	}
	idx = (size_t)-1;
	while (++idx < data->philo_count)
		pthread_join(data->philos[idx].thread, NULL);
}
