/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 20:33:50 by llepesqu          #+#    #+#             */
/*   Updated: 2026/10/19 20:34:00 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_error(char *str)
{
	ft_putstr_fd(STDERR_FILENO,"Error\n");
	ft_putstr_fd(STDERR_FILENO,str);
	return (FAILURE);
}