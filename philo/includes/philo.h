/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:01:51 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/15 11:44:07 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define TRUE 1
# define FALSE 0
# define RESET "\e[0m"
# define RED "\e\033[1;31m" 
# define GREEN "\033[1;32m" 
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define NUM_ARGS "ERROR: The number of arguments must be 4 or 5"
# define ARG1 "ERROR: There is a mistake in number of philosophers"
# define ARG2 "ERROR: There is a mistake in time to die"
# define ARG3 "ERROR: There is a mistake in time to eat"
# define ARG4 "ERROR: There is a mistake in time to sleep"
# define ARG5 "ERROR: There is a mistake in number of times \
each philosopher must eat"
# define HELP "The number of arguments must be 4 or 5:\n\
- arg1 number of philosophers\n\
- arg2 time to die\n\
- arg3 time to eat\n\
- arg4 time to sleep\n\
- arg5 number of times each philosopher must eat"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_input
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
}					t_input;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				num_of_times_ate;
	long long		time_to_die;
	t_fork			fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_input			input;
	t_philo			*philo;
	pthread_t		orchestrator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_main;

int			philo_eat(t_main *main, int i);
int			philo_sleep(t_main *main, int i);
int			philo_think(t_main *main, int i);
int			philo_is_dead(t_main *main, int *i);
int			drop_forks(t_main *main, int i);

int			error_handling(int argc, char **argv, t_main *main);
int			init_input_struct(int argc, char **argv, t_main *main);
void		print_args_errors(t_main *main, int argc);

int			create_forks(t_main *main);
void		unlock_forks(t_main *main);

int			create_philos(t_main *main);
void		fill_philo_struct(t_main *main, int i, int j);

int			create_threads(t_main *main);
int			join_threads(t_main *main);
int			destroy_threads(t_main *main);

long long	get_time(void);
long long	delta_time(long long time2);
void		exec_action(long long time);

int			main(int argc, char **argv);
int			just_one_philo(t_main *main);

int			philo_atoi(char *str);
int			philo_strncmp(const char *s1, const char *s2, size_t n);
int			philo_strlen(const char *str);
void		philo_free(t_main *main);

void		*routine(void *args);
int			routine_execute(t_main *main, int i);
void		*checker(void *args);
int			philo_print(t_main *main, int id, char *color, char *status);

#endif