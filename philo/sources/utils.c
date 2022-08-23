/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:12:31 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/08/23 14:37:37 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_useconds(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_usleep(useconds_t time)
{
	size_t	t;

	t = get_useconds();
	while (get_useconds() - t < time)
		usleep(1);
}

void	print_philo_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->info->mtx_end);
	pthread_mutex_unlock(&philo->info->mtx_end);
	printf("%zu %d %s\n", (get_useconds() - philo->info->start) / 1000, \
	philo->num, status);
}

int	ft_atoi(char *str)
{
	long		number;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number > 2147483647)
			return (-1);
		number = number * 10 + *str - '0';
		str++;
	}
	return (number);
}
