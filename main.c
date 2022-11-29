#include "philo.h"

static int	usage(void)
{
	printf("Usage: phisolophers count_philosophers time_to_die "
		"time_to_eat time_to_sleep {eat_goal}\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (usage());
	if (!philo_data_init(&data, argv + 1))
	{
		printf("Invalid argument\n");
		return (1);
	}
	philo_start(&data);
	philo_while_alive(&data);
	philo_wait_threads(&data);
	philo_data_destroy(&data);
	return (0);
}
