/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:30:56 by jcallejo          #+#    #+#             */
/*   Updated: 2024/08/01 12:53:11 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR_PHILO 		1
# define ERROR_FORK 		2
# define ERROR_FORK_ARRAY	3
# define ERROR_WRITE 		4
# define ERROR_CHECK 		5

# define STATUS_TINK		1
# define STATUS_EEP			2
# define STATUS_TAKE_FORK	3
# define STATUS_NOM			4
# define STATUS_DIE			5

# define RED "\033[0;31m"
# define DEFAULT "\033[;0m"

typedef struct data
{
	pthread_mutex_t						*forks;
	struct s_philosophers				**philosophers;
	int									philo_n;
	int									must_nom;
	int									still_breathing;
	long								start_time;
	long								t_to_die;
	long								t_to_eep;
	long								t_to_nom;
	pthread_mutex_t						write;
	pthread_mutex_t						check;
}	t_data;

typedef struct s_philosophers
{
	t_data				*data;
	int					id;
	int					times_nomd;
	long				last_nom;
	pthread_t			thread;
	pthread_mutex_t		lock;
	pthread_mutex_t		*rfork;
	pthread_mutex_t		*lfork;
}	t_philo;

/**
 * @brief ATOI
 * 
 * @param str 
 * @return int 
 */
int		ft_atoi(const char *str);

/**
 * @brief Error check function
 * 
 * @param error_n 
 * @param data 
 * @return int 
 */
int		ft_errors(int error_n, t_data *data);

/**
 * @brief Initializes data, but not philosophers
 * 
 * @param data 
 * @param argv 
 */
void	ft_init_data(t_data	*data, char **argv);

/**
 * @brief Initializes philosopher
 * 
 * @param data 
 */
void	ft_create_philo(t_data *data);
/**
 * @brief Gets current time
 * 
 * @param data 
 * @return long 
 */
long	ft_current_time(t_data *data);

/**
 * @brief Gets time
 * 
 * @return long 
 */
long	ft_get_time(void);

/**
 * @brief Checks number of arguments and numbers are correct
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int		ft_check(int argc, char **argv);

/**
 * @brief Checks is_alive and comunicates it to main
 * 
 * @param data 
 * @return int 
 */
int		ft_are_still_breathing(t_data *data);

/**
 * @brief Function that call and manages the other routines
 * 
 * @param arg 
 */
void	ft_routine(void *arg);

/**
 * @brief Prints the status of each philosopher
 * 
 * @param philo 
 * @param status 
 */
void	ft_print_routine(t_philo *philo, int status);

/**
 * @brief Initializes each philosopher
 * 
 * @param data 
 */
void	ft_philo_initializer(t_data *data);

/**
 * @brief Checks if each philo is still alive
 * 
 * @param data 
 * @return int 
 */
int		ft_alive_check(t_philo *philo);

/**
 * @brief Cleans up everything
 * 
 * @param data 
 */
void	ft_clean(t_data *data);

#endif