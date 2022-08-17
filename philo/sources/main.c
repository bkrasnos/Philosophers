/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:01:21 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/17 10:50:55 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (error_handling(argc, argv, &main) == FALSE)
		return (1);
	if (create_philos(&main) == FALSE)
		return (1);
	if (create_forks(&main) == FALSE)
		return (1);
	if (main.input.num_philo == 1)
	{
		if (just_one_philo(&main) == FALSE)
			return (1);
		return (0);
	}
	if (create_threads(&main) == FALSE)
		return (1);
	if (destroy_threads(&main) == FALSE)
		return (1);
	philo_free(&main);
	return (0);
}

int	just_one_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	main->t0 = get_time();
	philo_print(main, 1, PURPLE, FORK);
	exec_action(main->input.time_to_die);
	philo_print(main, 1, RED, DIED);
	philo_free(main);
	return (TRUE);
}
