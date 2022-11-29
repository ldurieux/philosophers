/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_while_alive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:34 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:35 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock_philos(t_philo *philos, size_t	count)
{
	size_t	idx;

	idx = (size_t)-1;
	while (++idx < count)
		pthread_mutex_lock(&philos[idx].mutex);
}

static void	unlock_philos(t_philo *philos, size_t count)
{
	size_t	idx;

	idx = (size_t)-1;
	while (++idx < count)
		pthread_mutex_unlock(&philos[idx].mutex);
}

static int	check_dead(t_philo *philo, t_data *data)
{
	size_t	curr_time;
	size_t	dead_time;

	curr_time = get_time();
	dead_time = philo->last_time_eaten + data->time_to_die + data->start_time;
	return (curr_time >= dead_time);
}

void	philo_while_alive(t_data *data)
{
	size_t	idx;
	size_t	goal_not_reached;

	while (1)
	{
		idx = (size_t) - 1;
		goal_not_reached = data->eat_goal == 0;
		ft_usleep(500);
		lock_philos(data->philos, data->philo_count);
		while (++idx < data->philo_count)
		{
			if (check_dead(data->philos + idx, data))
			{
				philo_print_msg(data->philos + idx, "died");
				unlock_philos(data->philos, data->philo_count);
				return ;
			}
			if (data->philos[idx].eaten < data->eat_goal)
				goal_not_reached++;
		}
		unlock_philos(data->philos, data->philo_count);
		if (goal_not_reached == 0)
			return ;
	}
}
