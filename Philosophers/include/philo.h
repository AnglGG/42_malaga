/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:36:28 by anggalle          #+#    #+#             */
/*   Updated: 2025/07/14 15:53:11 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_count;
	int				eating;
	int				finished_eating;
	long			last_meal_time;
	pthread_mutex_t	meal_mutex;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	long			start_time;
	int				simulation_ended;
	int				all_threads_ready;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	ready_mutex;
	pthread_mutex_t	simulation_mutex;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor_thread;
}	t_table;

/* Parsing functions */
void	parse_arguments(int argc, char **argv, t_table *table);
int		is_valid_positive_number(char *str);
int		strict_atoi(char *str);
void	validate_argument(char *arg, int min_value, char *param_name);

/* Initialization functions */
int		init_table(t_table *table);
void	cleanup_table(t_table *table);
int		init_mutex_trio(t_table *table);

/* Print functions */
void	print_action(t_philo *philo, const char *action);

/* Simulation functions */
int		start_simulation(t_table *table);
void	join_threads(t_table *table);
void	*philosopher_routine(void *arg);
void	*monitor_routine(void *arg);

/* Simulation utils */
void	handle_single_philosopher(t_table *table);
void	initialize_start_times(t_table *table);
void	signal_threads_start(t_table *table);

/* Philosopher actions */
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	put_forks(t_philo *philo);
void	sleep_and_think(t_philo *philo);

/* Philosopher utils */
void	wait_for_start_signal(t_philo *philo);
void	philosopher_lifecycle(t_philo *philo);
long	get_initial_delay(t_philo *philo);
long	calculate_think_time(t_philo *philo);

/* Utils functions for simulation */
int		is_simulation_ended(t_table *table);
void	set_simulation_ended(t_table *table);
int		should_philosopher_die(t_philo *philo);
int		all_philosophers_fed(t_table *table);

/* Error handling */
void	error_exit(char *message);

/* Utils functions */
long	get_current_time(void);
long	get_current_time_usec(void);
long	get_current_time_usec_cached(void);
long	get_time_diff_usec(long start_time);
long	get_precise_time_diff(long start_time);
void	precision_usleep(long usec);
int		is_small_timing_case(t_table *table);
void	ft_usleep(long usec, t_table *table);

/* Test functions (for TDD) */
void	run_parsing_tests(void);

#endif
