/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:44 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:45 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_data_destroy(t_data *data)
{
	size_t	idx;

	idx = (size_t)-1;
	while (++idx < data->philo_count)
	{
		pthread_mutex_destroy(data->forks + idx);
		pthread_mutex_destroy(&data->philos[idx].mutex);
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(data->philos);
	free(data->forks);
}
