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
