/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:32 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:33 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_msg(t_philo *philo, char *msg)
{
	size_t	time;
	t_data	*data;

	time = (get_time() - philo->data->start_time) / 1000;
	data = philo->data;
	pthread_mutex_lock(&data->print_mutex);
	if (!data->stop_print)
		printf("%zu %zu %s\n", time, philo->id + 1, msg);
	pthread_mutex_unlock(&data->print_mutex);
}
