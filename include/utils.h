/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:13:20 by llepesqu          #+#    #+#             */
/*   Updated: 2026/11/05 20:16:26 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILIS_H
#define UTILIS_H

// Standard C Libraries
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_bzero(void *s, size_t n);
int		ft_error(char *str);
void	ft_puterror(int condition, char *msg);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(int fd, const char *s);
size_t	ft_strlen(const char *s);

#endif