#include "philo.h"

void	philo_init(t_philo *philo, t_data *data, size_t id)
{
	philo->data = data;
	pthread_mutex_init(&philo->mutex, NULL);
	philo->id = id;
	philo->eaten = 0;
	philo->dead = 0;
	philo->last_time_eaten = 0;
}
