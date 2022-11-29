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
