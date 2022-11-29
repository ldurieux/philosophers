/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:39 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:41 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->mutex);
	dead = philo->dead;
	pthread_mutex_unlock(&philo->mutex);
	return (dead);
}

static int	get_forks(t_philo *philo, pthread_mutex_t *forks[2])
{
	pthread_mutex_t	*swap;

	forks[0] = philo->data->forks + philo->id;
	forks[1] = philo->data->forks;
	if (philo->id != philo->data->philo_count - 1)
		forks[1] = philo->data->forks + philo->id + 1;
	swap = forks[0];
	forks[0] = forks[philo->id % 2];
	forks[philo->id % 2] = swap;
	pthread_mutex_lock(forks[0]);
	if (is_dead(philo))
		return (pthread_mutex_unlock(forks[0]), 0);
	philo_print_msg(philo, "has taken a fork");
	pthread_mutex_lock(forks[1]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(forks[0]);
		pthread_mutex_unlock(forks[1]);
		return (0);
	}
	return (1);
}

static void	update_eaten(t_philo *philo)
{
	size_t	time;

	time = get_time();
	pthread_mutex_lock(&philo->mutex);
	time -= philo->data->start_time;
	philo->last_time_eaten = time;
	philo->eaten++;
	pthread_mutex_unlock(&philo->mutex);
}

static int	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*forks[2];

	if (!get_forks(philo, forks))
		return (0);
	philo_print_msg(philo, "is eating");
	update_eaten(philo);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(forks[0]);
	pthread_mutex_unlock(forks[1]);
	return (!is_dead(philo));
}

void	*philo_thread(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		philo_print_msg(philo, "is thinking");
		philo_print_msg(philo, "has taken a fork");
		return (NULL);
	}
	while (!is_dead(philo))
	{
		philo_print_msg(philo, "is thinking");
		if (!philo_eat(philo))
			break ;
		philo_print_msg(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
	return (NULL);
}
