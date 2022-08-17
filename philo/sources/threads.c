/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:01:27 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/15 11:25:30 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = FALSE;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	while (i < main->input.num_philo)
	{
		main->n_thread = i;
		if (pthread_create(&main->philo[i].thread,
				NULL, &routine, (void *) main) != 0)
			return (FALSE);
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->orchestrator, NULL, &checker, (void *) main) != 0)
		return (FALSE);
	usleep(1000);
	if (join_threads(main) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_join(main->orchestrator, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	return (TRUE);
}
