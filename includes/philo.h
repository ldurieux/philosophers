#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_mutex_t	mutex;
	size_t			id;
	pthread_t		thread;
	size_t			eaten;
	size_t			last_time_eaten;
	int				dead;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	print_mutex;
	size_t			philo_count;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			eat_goal;
	size_t			start_time;
	int				stop_print;
}	t_data;

int		philo_data_init(t_data *data, char **argv);
void	philo_data_destroy(t_data *data);
void	philo_init(t_philo *philo, t_data *data, size_t id);
int		philo_start(t_data *data);

void	philo_while_alive(t_data *data);
void	philo_wait_threads(t_data *data);

void	*philo_thread(t_philo *philo);

void	philo_print_msg(t_philo *philo, char *msg);

int		ft_strtoui(const char *str, char **end_ptr);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_usleep(size_t time);
size_t	get_time(void);

#endif // PHILO_H
