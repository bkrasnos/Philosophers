/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:01:15 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/15 11:33:02 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, PURPLE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, PURPLE, FORK) == FALSE)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, CYAN, EAT) == FALSE)
		return (FALSE);
	main->philo[i].time_to_die = get_time();
	exec_action(main->input.time_to_eat);
	drop_forks(main, i);
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	exec_action(main->input.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, YELLOW, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->input.time_to_die)
	{
		philo_print(main, main->philo[*i].id, RED, DIED);
		main->philo_dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (FALSE);
	main->philo[i].num_of_times_ate++;
	return (TRUE);
}
