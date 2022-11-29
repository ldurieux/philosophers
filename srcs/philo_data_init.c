#include "philo.h"

#define INT32_MAX_STR "2147483647"

static int	parse_args(t_data *data, char **argv)
{
	char	*tmp;

	data->philo_count = ft_strtoui(argv[0], &tmp);
	if (data->philo_count == 0 || (data->philo_count == INT_MAX
		&& ft_strcmp(argv[0], INT32_MAX_STR)))
		return (0);
	data->time_to_die = ft_strtoui(argv[1], &tmp);
	if (data->time_to_die == 0 || (data->time_to_die == INT_MAX
		&& ft_strcmp(argv[1], INT32_MAX_STR)))
		return (0);
	data->time_to_eat = ft_strtoui(argv[2], &tmp);
	if (data->time_to_eat == 0 || (data->time_to_eat == INT_MAX
		&& ft_strcmp(argv[2], INT32_MAX_STR)))
		return (0);
	data->time_to_sleep = ft_strtoui(argv[3], &tmp);
	if (data->time_to_sleep == 0 || (data->time_to_sleep == INT_MAX
		&& ft_strcmp(argv[3], INT32_MAX_STR)))
		return (0);
	data->eat_goal = 0;
	if (!argv[4])
		return (1);
	data->eat_goal = ft_strtoui(argv[4], NULL);
	if (data->eat_goal < 1 || (data->eat_goal == INT_MAX
		&& ft_strcmp(argv[4], INT32_MAX_STR)))
		return (0);
	return (1);
}

int		philo_data_init(t_data *data, char **argv)
{
	size_t	idx;

	if (!parse_args(data, argv))
		return (0);
	data->time_to_die *= 1000;
	data->time_to_eat *= 1000;
	data->time_to_sleep *= 1000;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->forks || !data->philos)
		return (free(data->forks), free(data->philos), 0);
	pthread_mutex_init(&data->print_mutex, NULL);
	data->stop_print = 0;
	idx = (size_t)-1;
	while (++idx < data->philo_count)
		philo_init(data->philos + idx, data, idx);
	return (1);
}
