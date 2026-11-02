/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 00:27:03 by pierre_lepe       #+#    #+#             */
/*   Updated: 2026/11/02 00:30:44 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include <unistd.h>
# include <stddef.h>
# include <sys/time.h>

long	get_time_ms(struct timeval tv);
long	get_current_time_ms(void);
void	precise_sleep(long duration);

#endif