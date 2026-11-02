/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:04:43 by plepercq          #+#    #+#             */
/*   Updated: 2026/11/02 01:32:04 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_utils.h"

long	get_time_ms(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	return (get_time_ms(tv));
}

void	precise_sleep(long duration)
{
	long	start;

	start = get_current_time_ms();
	while (get_current_time_ms() - start < duration)
		usleep(200);
}
